"use strict";
/* global APP */


(function () {
    
    APP.buyerToggle = 0;
    APP.purchaseToggle = 0;
    APP.paidToggle = 0;
    
    var initElements = [
        {elmID: 'buyer', query: 'select name from customers', callback: APP.populateDropdown},
        {elmID: 'piece', query: 'select title from pieces', callback: APP.populateDropdown},
        {query: 'select * from purchases', callback: populatePurchases}
    ];
    
    var headerElements = {
        headerInfo: [
            {id: 'buyer-th', toggle: 'buyerToggle', query: 'select * from purchases order by buyer '},
            {id: 'piece-th', toggle: 'purchaseToggle', query: 'select * from purchases order by piece '},
            {id: 'paid-th', toggle: 'paidToggle', query: 'select * from purchases order by paid '}
        ],
        tableID: 'purchases-table',
        populate: populatePurchases
    };
    
    initElements.forEach(function (elm) {
        APP.initElement(elm);
    });
    
    APP.initTableHeader(headerElements);


    document.getElementById('enter-purchase').addEventListener('click', purchase);
    document.getElementById('paid').addEventListener('keypress', purchase);


    function purchase(event) {
        if (event.type === 'click' || event.key === 'Enter') {
            var insertData = {
                values: {
                    'BUYER': document.getElementById('buyer').value,
                    'PIECE': document.getElementById('piece').value,
                    'PAID': document.getElementById('paid').value
                },
                table: 'purchases',
                callback: function () {
                    populatePurchases([this.values]);
                }
            };

            APP.insertData(insertData);
        }
    }
    
    
    function populatePurchases (data) {
        APP.populateTable('purchases-table', data);
    }
    
}());
