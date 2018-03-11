"use strict";
/* global APP */


(function () {
    
    APP.pieceTitleToggle = 0;
    APP.pieceArtistToggle = 0;
    APP.pieceStyleToggle = 0;
    APP.pieceSubcategoryToggle = 0;
    APP.categoryToggle = 0;
    
    // The spec needed by the APP.initTableHeader method.
    var initHeaderSpec = {
        headerInfo: [
            {id:'pieces-title-th', toggle:'pieceTitleToggle', query:'select * from pieces order by title '},
            {id:'pieces-artist-th', toggle:'pieceArtistToggle', query:'select * from pieces order by artist '},
            {id:'pieces-style-th', toggle:'pieceStyleToggle', query:'select * from pieces order by category '},
            {id:'pieces-subcategory-th', toggle:'pieceSubcategoryToggle', query:'select * from pieces order by subcategory '}
        ],
        tableID: 'pieces-table',
        populate: populatePieces
    };
    
    
    // Page elements to be initialized.
    var initElements = [
        {elmID:'piece-subcategory', query: 'select * from subcategories', callback:APP.populateDropdown},
        {elmID:'piece-style', query: 'select * from styles', callback:APP.populateDropdown},
        {elmID:'piece-artist', query: 'select name from artist', callback:APP.populateDropdown},
        {elmID:'subcat-list', query: 'select * from subcategories', callback:APP.populatePanel},
        {query: 'select * from pieces', callback:populatePieces}
    ];


    // Initialize the page elements.
    initElements.forEach(function (elm) {
        APP.initElement(elm);
    });
    
    APP.initTableHeader(initHeaderSpec);

    // Add Event listeners to buttons.
    document.getElementById("enter-piece").addEventListener("click", enterPiece);
    document.getElementById("piece-title").addEventListener("keypress", function (event) {
        if (event.key === 'Enter') {
            enterPiece();
        }
    });
    
    document.getElementById("add-subcat").addEventListener("click", addSubcat);
    
    document.getElementById('style-heading-span').addEventListener('click', function () {
        var x = document.getElementById('styles');
        var y = ['select subcategory from subcategories', 'select style from styles'];
        
        APP.categoryToggle ? APP.categoryToggle = 0 : APP.categoryToggle = 1;
        
        x.innerHTML  = '';
        this.innerHTML = '';

        if (APP.categoryToggle === 1) {
            this.innerHTML += '(click to add new subcategory)';
            x.innerHTML += '<button id="add-style-button">Add Style</button>';
            x.innerHTML += '<input id="add-style-in" type="text">';
            x.innerHTML += '<ul id="style-list" class="list-group"></ul>';
            document.getElementById("add-style-button").addEventListener("click",APP.addStyle);
            APP.initElement({elmID:'style-list', query: y[APP.categoryToggle], callback:APP.populatePanel});
        }
        else {
            this.innerHTML += '(click to add new style)';
            x.innerHTML += '<button id="add-subcat">Add Subcategory</button>';
            x.innerHTML += '<input id="add-subcat-in" type="text">';
            x.innerHTML += '<ul id="subcat-list" class="list-group"></ul>';
            document.getElementById("add-subcat").addEventListener("click",addSubcat);
            APP.initElement({elmID:'subcat-list', query: y[APP.categoryToggle], callback:APP.populatePanel});
        }
        
        
    });


    /**
     * populatePieces
     * 
     * Used for ajax responses that populate the pieces-table.
     * 
     * @param {array} data Contains table rows as JSON objects.
     * 
     * @returns {void}
     */
    
    function populatePieces(data) {
        APP.populateTable('pieces-table', data);
    }


    /**
     * enterPiece
     * 
     * Collects piece info from the DOM and initiates a request
     * to insert the info into the pieces table.
     * 
     * @return {void}
     */
    
    function enterPiece () {
        var insertPacket = {};
        var info = {
            TITLE: document.getElementById('piece-title').value,
            ARTIST: document.getElementById('piece-artist').value,
            CATEGORY: document.getElementById('piece-style').value,
            SUBCATEGORY: document.getElementById('piece-subcategory').value
        };
        
        insertPacket.table = 'pieces';
        insertPacket.values = info;        
        insertPacket.callback = function (dbResponse) {
            if (dbResponse === 'true') {
                APP.populateTable('pieces-table', [info]);

                // Reset piece title input box.
                document.getElementById('piece-title').value = '';
            }
            else {
                console.log(dbResponse);
            }
        };
        
        APP.insertData(insertPacket);
    }


    /**
     * addSubcat
     * 
     * Inserts a subcategory into the database via ajax request.
     * If successful re-populates the subcategories panel.
     * 
     * @returns {void}
     */
    
    function addSubcat() {
        var subcat = document.getElementById('add-subcat-in').value;
        var insertPacket = {};
        
        insertPacket.table = 'subcategories';
        insertPacket.values = { SUBCATEGORY: subcat };
        
        insertPacket.callback = function (insertResponse) {
            if (insertResponse === 'true') {
                APP.populatePanel('subcat-list', [insertPacket.values]);
            
                // Reset piece subcategory input box.
                document.getElementById('add-subcat-in').value = '';
            }
        };
        
        APP.insertData(insertPacket);
    }
    
}());
