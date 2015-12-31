"use strict";
/* global APP */


(function() {
    
    var initElements = [
        {query:'select * from customers', callback:populateCustomers},
        {elmID: 'customer-state', query: 'select abbreviation from state', callback:APP.populateDropdown}
    ];


    APP.customerNameToggle = 0;
    APP.customerCityToggle = 0;
    APP.customerStateToggle = 0;
    APP.customerZipToggle = 0;
    APP.customerSpentToggle = 0;


    var headerElements = {
        headerInfo: [
            {id:'customer-name-th', toggle:'customerNameToggle', query:'select * from customers order by name '},
            {id:'customer-city-th', toggle:'customerCityToggle', query:'select * from customers order by city '},
            {id:'customer-state-th', toggle:'customerStateToggle', query:'select * from customers order by state '},
            {id:'customer-zip-th', toggle:'customerZipToggle', query:'select * from customers order by zip '},
            {id:'customer-spent-th', toggle:'customerSpentToggle', query:'select * from customers order by spent '}
        ],
        tableID: 'customers-table',
        populate: populateCustomers
    };


    initElements.forEach(function(elm) {
        APP.initElement(elm);
    });
    
    APP.initTableHeader(headerElements);
    
    document.getElementById("enter-customer").addEventListener("click",enterCustomer);


    /**
     * populateCustomers
     * 
     * Used for ajax responses that populate the customers-table.
     * 
     * @param {array} data Contains table rows as JSON objects.
     * 
     * @returns {void}
     */

    function populateCustomers(data) {
        APP.populateTable('customers-table', data);
        document.getElementById('customer-street-th').addEventListener('click', function () {
            alert('can not sort by street address');
        });
    }


    function enterCustomer() {
        var insertPacket = {};
        insertPacket.table = 'customers';
        
        insertPacket.values = {
            NAME: document.getElementById('customer-name').value,
            STREET: document.getElementById('customer-street').value,
            CITY: document.getElementById('customer-city').value,
            STATE: document.getElementById('customer-state').value,
            ZIP: document.getElementById('customer-zip').value
        };
        
        insertPacket.callback = function (data) {
            if (data === 'true') {
                APP.populateTable('customers-table', [insertPacket.values]);
            }
            else {
                console.log(data);
            }
        };
        
        APP.insertData(insertPacket);
    }
    
}());