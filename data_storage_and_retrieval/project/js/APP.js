"use strict";


var APP = {};

// The PHP script that handles ajax requests.
APP.requests = '/requests.php';
APP.method = 'POST';

// Order by togglable.
APP.order = ['desc', 'asc'];

// The keys of each table.
APP.tableKeys = {
    'artist': 'NAME',
    'customers': 'NAME',
    'pieces': 'TITLE',
    'purchases': ['BUYER', 'PIECE', 'PAID']
};


/**
 * nodeListIndex
 * 
 * @param {type} childNode
 * @returns {Number|Number.nodeListIndex.i}
 */

APP.nodeListIndex = function (childNode) {
    var children = childNode.parentNode.childNodes;
    
    for (var i = 0; i < children.length; i++) { 
        if (children[i] === childNode) {
            return i;
        }
    }
    
    return -1;
};


/**
 * endOfNodeList
 * 
 * Given a node is in a node with children, return 0 if the node is not
 * at the end of it's containing nodeList, otherwise return the index
 * (Number) of the node at the end of the node list.
 * 
 * @param {type} node
 * @returns {false|Number.endOfNodeList.end}
 */

APP.endOfNodeList = function (node) {
    var end = node.parentNode.childNodes.length - 1;

    if (APP.nodeListIndex(node) === end) {
        return end;
    }
    else {
        return false;
    }
};


/**
 * firstTableRow
 * 
 * @param {type} node
 * @returns {Boolean}
 */

APP.firstTableRow = function (node) {
    var rowNumber = APP.nodeListIndex(node);
    
    if ((rowNumber - 4) === 0) {
        return true;
    }
    else {
        return false;
    }
};


/**
 * firstCell
 * 
 * @param {type} td
 * @returns {Boolean}
 */

APP.firstCell = function (td) {
    if (APP.nodeListIndex(td)) {
        return false;
    }
    else {
        return true;
    }
};


/**
 * tdTableName
 * 
 * Takes an DOM table row cell and returns the name of that table.
 * 
 * @param {Node} td An DOM table row cell.
 * @returns {String} The table name of the td Node.
 */

APP.tdTableName = function (td) {
    return td.parentNode.parentNode.parentNode.id.replace(/-\w+/, '');
};


/**
 * appToDbName
 * 
 * Translates the appName for a table header to the Database name.
 * 
 * @param {string} appName The table header HTML.
 * @param {string} table The table translating for.
 * @param {boolean} rev Flag to do translation in reverse order.
 * @returns {APP.appToDbName.aliases|aliases} The name of the table
 *                                  attribute in the database.
 */

APP.appToDbName = function (appName, table, rev) {
    var aliases = {
        'BIRTHDAY': 'DOB',
        'DECEASED': 'DOD',
        'ORIGIN': 'BIRTHPLACE',
        'AMOUNT': 'PAID'
    };
    
    
    if (Object.keys(aliases).indexOf(appName) !== -1) {
        return aliases[appName];
    }
    else if (appName === 'STYLE' && table === 'pieces') {
        return 'CATEGORY';
    }
    else {
        return appName;
    }        
};


/**
 * editor
 * 
 * Handles editing of table rows.
 * 
 * @param {event} event The event that the editor responds to.
 * @returns {undefined}
 */

APP.editor = function (event) {
    // Currently editing Row object.
    var workingRow;
    var workingNodeIndex;
    var currentRow = event.target.parentNode;
    currentRow.nodes = function () {
        return this.parentNode.childNodes;
    };

    /**
     * rowObject
     * 
     * Makes an object of the given row node.
     * 
     * @param {node} rowNode A DOM node for a table row.
     * @returns {APP.editor.rowObject.artist|Number.editor.rowObject.artist}
     */
    
    var rowObject = function(rowNode) {
        var tbody  = rowNode.parentNode.parentNode.childNodes.item(1);
        var thead  = tbody.firstChild;
        var thHTML = [];
        var rowObj = {};
        
        
        for (var i = 1, tmpStr; i < thead.childNodes.length; i = i+2) {
            tmpStr = thead.childNodes.item(i).innerHTML.toUpperCase();
            tmpStr = APP.appToDbName(tmpStr, APP.tdTableName(thead.childNodes.item(0)));
            thHTML.push(tmpStr);
        }
        
        thHTML.forEach(function (elm, index) {
            rowObj[elm] = null;
        });

        Object.keys(rowObj).forEach( function (elm, i) {
            rowObj[elm] = rowNode.childNodes.item(i).innerHTML;
        });

        return rowObj;
    };


    /**
     * highlightActiveRow
     * 
     * Based on the given td node, add highlight to it's row.
     * 
     * @param {node} td
     * @returns {undefined}
     */
    
    var highlightActiveRow = function (td) {;
        if (APP.activeRow && td.parentNode !== APP.activeRow) {
            APP.activeRow.removeAttribute('class');
        }

        APP.activeRow = td.parentNode;
        APP.activeRow.setAttribute('class', 'glowing-border');
    };


    /**
     * exitEditMode
     * 
     * @returns {undefined}
     */
    var exitEditMode = function() {
        APP.activeRow = null;
        event.target.parentNode.removeAttribute('class');
        event.target.blur();
    };
    
    
    /**
     * updatePacket
     * 
     * Given a td node (one that editor responds to), return an
     * updatePackt object (See APP.update).
     * 
     * @param {Node} td An event.target handled by editor.
     * @returns {Object} An updatePacket for the APP.update method.
     */
    
    var updatePacket = function (td) {
        console.log(td.innerHTML);
        var updatePacket = {};
        updatePacket.table = APP.tdTableName(td);
        updatePacket.key = APP.tableKeys[updatePacket.table];
        updatePacket.row_a = APP.editor.workingRow;
        updatePacket.row_b = rowObject(td.parentNode);
        updatePacket.node = td.parentNode;
        
        return updatePacket;
    };


    // Respond to events ...
    
    if (event.type === 'click') {
        highlightActiveRow(event.target);
        if (APP.editor.workingNodeIndex !== APP.nodeListIndex(event.target.parentNode)) {
            APP.editor.workingRow = rowObject(currentRow);
            APP.editor.workingNodeIndex = APP.nodeListIndex(event.target.parentNode);
        }
    }
    else if (event.type === 'keypress') {
        if (event.key === 'Enter') {
            // Assume user wants to submit row for update.
            event.target.innerHTML = event.target.innerHTML.replace('<br>', '');
            APP.editor.currentRow = rowObject(event.target.parentNode);
            APP.update(updatePacket(event.target));
            exitEditMode();
        }
        if (event.shiftKey && event.keyCode === 9) {
            // User is scrolling backwards through cells. If user
            // scrolls back from the first cell in a row, then
            // submit the update query; if that cell is not in the
            // first row, hightlight the previous row.
            if (APP.firstCell(event.target)) {
                console.log('shift+tab update');
            }

            if (!APP.firstTableRow(currentRow) && APP.firstCell(event.target)) {
                var rowBeforeIndex = APP.nodeListIndex(currentRow) - 1;

                highlightActiveRow(currentRow.nodes().item(rowBeforeIndex).lastChild);
                APP.update(updatePacket(event.target));
                APP.editor.workingRow = rowObject(currentRow.nodes().item
                    (APP.nodeListIndex(currentRow) - 1));
            }
        }
        else if (event.key === 'Tab') {
            // If not at the end of the row, assume the user
            // wants to go to the next td. Otherwise submit
            // the row for update.
            
            if (APP.endOfNodeList(event.target)) {
                // Highlight the next row.
                // Move the workingRow and currentRow pointers
                // to the next row.
                
                if (APP.nodeListIndex(currentRow) < currentRow.nodes().length) {
                    highlightActiveRow(currentRow.nodes().item
                        (APP.nodeListIndex(currentRow)+1).firstChild);
                }
                
                // Update and set workingRow to next (tabbed) row.
                APP.update(updatePacket(event.target));      
                APP.editor.workingRow = rowObject(currentRow.nodes().item
                    (APP.nodeListIndex(currentRow)+1));
            }
        }
        else if (event.keyCode === 27) {
            // If esc key pressed ...
            exitEditMode();
        }
    }
};


/**
 * populateDropdown
 * 
 * Adds values to a given HTML dropdown.
 * 
 * @param {string} htmlID The HTML id of the dropdown.
 * @param {array} data Collection of JSON objects containing the values
 *                     to be added to the dropdown.
 * 
 * @returns {void}
 */

APP.populateDropdown = function (htmlID, data) {
    var dropdown = document.getElementById(htmlID);

    if (data) {
        data.forEach(function (JSONobj) {
            Object.keys(JSONobj).forEach(function (key) {
                dropdown.innerHTML += '<option>' + JSONobj[key] + '</option>';
            });
        });
    }
};


/**
 * populatePanel
 * 
 * Adds data to a given HTML (Bootstrap styled) panel.
 * 
 * @param {String} htmlID the panel's HTML id.
 * @param {array} data Contains JSON objects representing data desired
 *                     to add to the panel.
 * 
 * @returns void
 */

APP.populatePanel = function (htmlID, data) {
    if (data) {
        var panel = document.getElementById(htmlID);

        data.forEach(function (JSONobj) {
            Object.keys(JSONobj).forEach(function (key) {
                panel.innerHTML += '<li class="list-group-item">' + JSONobj[key] + '</li>';
            });
        });
    }
};


/**
 * populateTable
 * 
 * Adds data to a given HTML table.
 * 
 * @param {String} htmlID The table's id.
 * @param {array} data Contains JSON objects representing data desired
 *                     to add to the panel.
 * @param {function} editor A function to use to edit the given table.
 * 
 * @problem: this fails if attribute values have ','
 * 
 * @returns void
 */

APP.populateTable = function (htmlID, data, editor) {
    if (data) {
        var table = document.getElementById(htmlID);

        data.forEach(function (JSONobj) {
            var row = table.insertRow();
            
            Object.keys(JSONobj).forEach(function (key, index) {
                var cell = row.insertCell(index);
                cell.setAttribute('contentEditable', 'true');
                cell.addEventListener('click', APP.editor);
                cell.addEventListener('keypress', APP.editor);
                cell.innerHTML = JSONobj[key];
            });
        });
    }
};


/**
 * initElements
 * 
 * Used to initialize page elements with requested dbData.
 * 
 * @param {object} spec Provides the details for initializing page
 *                      elements
 *                          { query: 'select code from countries'
 *                            callback: APP.populateDropdown
 *                            elmID: 'artist-country' }
 * @returns {void}
 */

APP.initElement = function(spec) {
    $.ajax({
        url:APP.requests,
        method: APP.method,
        data: {'fetch': spec.query},
        success: function (dbData) {
            dbData = JSON.parse(dbData);
            spec.elmID ? spec.callback(spec.elmID, dbData) : spec.callback(dbData);
        }
    });
};


/**
 * initTableHeader
 * 
 * Assigns methods to <thead> elements that requests the table rows
 * be sorted. The result of the request is used to update the table
 * contents.
 * 
 * @param {Object} spec Contains the details necessary to initialize a
 * table's header.
 * 
 * spec object: {
 *     headerInfo: {array} Contains objects that contain the needed header info {
 *                          id: {string} The <thead>'s element's id.
 *                          toggle: {string} The toggle's (stored as APP.{toggle}) name.
 *                          query: {string} The query to be requested from the server.
 *                               example query: 'select * from artist order by style '
 *                          }
 *     tableID: {string} The given table,
 *     populate: {function} The function that will be used to populate
 *                          the given table.
 * }
 * 
 * @returns {void}
 */

APP.initTableHeader = function (spec) {
    spec.headerInfo.forEach(function (elm) {
        document.getElementById(elm.id).addEventListener('click', function () {
            $.ajax({
                url: APP.requests,
                method: 'POST',
                data: {'fetch': elm.query + APP.order[APP[elm.toggle]]},
                success: function (data) {
                    // This function runs when the user clicks a header
                    // item which then correspondingly queries the db, and
                    // the db query is successful.
                    
                    var table = document.getElementById(spec.tableID);

                    // Toggle to switch asc, desc in queries.
                    APP[elm.toggle] ?
                        APP[elm.toggle] = 0 :
                        APP[elm.toggle] = 1;

                    // Remove current table contents, before repopulate.
                    for (var rowsToDelete = (table.rows.length - 2); rowsToDelete; rowsToDelete--) {
                        table.deleteRow(table.rows.length - 1);
                    }
                    
                    spec.populate(JSON.parse(data));

                }
            });
        });
    });
};


/**
 * insertData
 * 
 * An ajax request to insert data into a database table.
 * 
 * @param {JSON} insertPacket Contains 'table' to be inserted into
 * 'values' to be inserted, and 'callback' to be called upon success.
 * 
 * Values must contain key value pairs for attribute values.
 * 
 * @returns void
 */

APP.insertData = function (insertPacket) {
    $.ajax({
        url: APP.requests,
        method: 'POST',
        data: {
            'table': insertPacket.table,
            'insert':JSON.stringify(insertPacket.values)
        },
        success: function (data, textStatus, jqXHR) {
            if (data === 'true') {
                insertPacket.callback(data);
            }
            else {
                console.log('APP.insertData failed on:');
                console.log(insertPacket.values);
            }
        }
    });
};


/**
 * update
 * 
 * Compares two rows of a given table. The changes in row-a
 * exhibited by row-b will be updated in the db.
 * 
 * @param {object} updatePacket Contains the data needed to do the update.
 *                              row_a: A given database row.
 *                              row_b: The changes in the row.
 *                              key: The primary key of the table.
 *                              table: The db table to update.
 * 
 * @returns {undefined}
 */

APP.update = function(updatePacket) {
    
    console.log(updatePacket.row_a);
    console.log(updatePacket.row_b);
    console.log(updatePacket.table);
    console.log(updatePacket.key);
    
    var changed = false;
    var updateQuery = 'update ' + updatePacket.table +' set ';
    
    Object.keys(updatePacket.row_a).forEach(function (elm, index) {
        if (updatePacket.row_a[elm] !== updatePacket.row_b[elm]) {
            changed || (changed = true);
            updateQuery += elm + "='" + updatePacket.row_b[elm].replace(/<br>/, '') + "', ";
        }
    });
    
    updateQuery = updateQuery.replace(/, $/, ' ');
    
    if (changed) {
        if (typeof updatePacket.key === 'string') {
            updateQuery += 'where ' + updatePacket.key + "='" +
                updatePacket.row_a[updatePacket.key] + "'";
        }
        else if (typeof updatePacket.key === 'object') {
            updateQuery += 'where ';

            updatePacket.key.forEach(function (elm, index) {
                updateQuery += elm + "='" + updatePacket.row_a[elm] + "' AND ";
            });
        }
        
        updateQuery = updateQuery.replace(/ AND $/, '');
        
        // Send update query.
        // If query is successful highlight tr green.
        // Else, highlight tr red.

        $.ajax({
            url: APP.requests,
            method: APP.method,
            data: {'update' : updateQuery},
            success: function (data) {
                if (data === 'true') {
                    updatePacket.node.setAttribute('class', 'border-success');
                }
                else {
                    updatePacket.node.setAttribute('class', 'border-failure');
                    Object.keys(updatePacket.row_a).forEach(function (elm, index) {
                        updatePacket.node.childNodes.item(index).innerHTML =
                                updatePacket.row_a[elm];
                    });
                }
                setTimeout(function () {
                    updatePacket.node.removeAttribute('class');
                }, 1000);
            }
        });
    }
};


/**
 * addStyle
 * 
 * Attempts to insert a style into the database.
 * 
 * @returns {undefined}
 */

APP.addStyle = function () {
    var styleInput = document.getElementById('add-style-in');
    var newStyle = {'STYLE':styleInput.value};

    $.ajax({
        url: APP.requests,
        method: "POST",
        data: {
            'insert': JSON.stringify(newStyle),
            'table':'styles'
        },
        success: function(data) {
            if (data === 'true') {
                APP.populatePanel('style-list', [newStyle]);
                styleInput.value = '';
            }
            else {
                console.log(data);
            }
        }
    });
};

