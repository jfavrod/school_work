"use strict";
/* global APP */


(function() {

    // Initialize toggles.
    APP.artistNameToggle = 0;
    APP.artistCountryToggle = 0;
    APP.artistDobToggle = 0;
    APP.artistDodToggle = 0;
    APP.artistAgeToggle = 1;
    APP.artistStyleToggle = 1;

    // The spec needed by the APP.initTableHeader method.
    var initHeaderSpec = {
        headerInfo: [
            {id:'artist-name-th', toggle:'artistNameToggle', query:'select * from artist order by name '},
            {id:'artist-country-th', toggle:'artistCountryToggle', query:'select * from artist order by birthplace '},
            {id:'artist-dob-th', toggle:'artistDobToggle', query:'select * from artist order by dob '},
            {id:'artist-dod-th', toggle:'artistDodToggle', query:'select * from artist order by dod '},
            {id:'artist-age-th', toggle:'artistAgeToggle', query:'select * from artist order by age '},
            {id:'artist-style-th', toggle:'artistStyleToggle', query:'select * from artist order by style '}
        ],
        tableID: 'artist-table',
        populate: populateArtists
    };


    var initElements = [
        {elmID:'artist-country', query: 'select code from countries', callback:APP.populateDropdown},
        {elmID:'artist-style', query: 'select * from styles', callback:populateStyles},
        {query:'select * from artist', callback:populateArtists}
    ];


    initElements.forEach(
        function (elm) {
            APP.initElement(elm);
        }
    );

    APP.initTableHeader(initHeaderSpec);

    // Assign event handlers to insert buttons.
    document.getElementById("enter-artist").addEventListener("click",enterArtist);
    document.getElementById("artist-name").addEventListener("keypress", function (event) {
        if (event.key === 'Enter'){
            enterArtist();
        }
    });
    document.getElementById("add-style-button").addEventListener("click",APP.addStyle);


    /**
     * populateStyles
     * 
     * Using this function to call two populate methods on the same
     * (styles) data.
     * 
     * @param {string} elmID Eats an unneeded parameter.
     * @param {Object} dbData Contains JSON objects passed to populate methods.
     * @returns {void}
     */
    
    function populateStyles(elmID, dbData) {
        APP.populateDropdown('artist-style', dbData);
        APP.populatePanel('style-list', dbData);
    }


    /**
     * populateArtist
     * 
     * Adds data to the artist table.
     * 
     * @param {array} data Contains objects representing rows to add
     *                     to the artist-table.
     * 
     * @returns {void}
     */
    
    function populateArtists(data) {
        // data returned from db request.
        if (data) {
            data.forEach(function (JSONobj) {
                var artistTable = document.getElementById('artist-table');
                var row = artistTable.insertRow();
                
                Object.keys(JSONobj).forEach(function (key, index) {
                    var cell = row.insertCell(index);
                    cell.setAttribute('contentEditable', 'true');
                    cell.addEventListener('click', APP.editor);
                    cell.addEventListener('keypress', APP.editor);
                    cell.innerHTML = JSONobj[key];
                });
            });
            
            $( ".datepicker").datepicker('destroy');

            $(function() {
              $( ".datepicker").datepicker({
                  yearRange: "0:2015",
                  changeYear: true,
                  changeMonth: true
                });
            });
        }
    }


    /**
     * enterArtist
     * 
     * Sends request to insert artist into database. Populates artist
     * table if insert was successful.
     * 
     * @returns {void}
     */
    
    function enterArtist() {
        var info = {
            NAME: document.getElementById("artist-name").value,
            DOB: document.getElementById("artist-dob").value,
            DOD: document.getElementById("artist-dod").value,
            AGE: '',
            BIRTHPLACE: document.getElementById("artist-country").value,
            STYLE: document.getElementById("artist-style").value
        };

        $.ajax({
            url: APP.requests,
            method: 'POST',
            data: { 'insertArtist': JSON.stringify(info)},
            success: function (dbResponse) {
                if (dbResponse === 'true') {
                    populateArtists([info]);

                    // Reset artist name input box.
                    document.getElementById('artist-name').value = '';
                }
                else {
                    console.log(dbResponse);
                }
            }
        });
    }

}());
