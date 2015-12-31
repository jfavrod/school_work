<?php
namespace Epoque\ICSProject;
use Epoque\ODB\ODB;


class Model extends ODB
{   
    public static function fetch($query)
    {
        return json_encode(parent::select($query));
    }
    
    
    /**
     * insert
     * 
     * A generic insert function. Builds an insert query executed
     * by ODB::insert method.
     * 
     * @param $table string The table to perform the insert on.
     * 
     * @param array $values A reference to an associative array of
     * tuple attributes/value pairs for insertion.
     * 
     * @return Boolean The response from an ODB::insert query.
     */

    public static function insert($table, &$values)
    {
        $attribs    = '';
        $valString  = '';
        $statement  = "insert into $table (";

        foreach($values as $attrib => $value) {
            $attribs .= "$attrib, ";
            $valString .= "'$value', ";
        }    

        $statement .= rtrim($attribs, ', ') . ') values (' . 
            rtrim($valString, ', ') . ')';
        
        return parent::insert($statement);
    }

    
    /**
     * insertArtist
     *
     * Adds the date formatting for the insert into artist.
     * 
     * @param array $attribs An associative array containing the attributes
     * and values to an artist tuple.
     * 
     * @return string The 'true' string if successful, 'false' otherwise.
     */

    public static function insertArtist(&$attribs)
    {
        $statement = 'insert into artist (name, birthplace, dob, dod, age, style) '.
            'values('.
                '\''.$attribs['NAME'].'\', '.
                '\''.$attribs['BIRTHPLACE'].'\', '.
                "to_date('".$attribs['DOB']."', 'mm/dd/yyyy'), ".
                "to_date('".$attribs['DOD']."', 'mm/dd/yyyy'), ".
                '\''.$attribs['AGA'].'\', '.
                '\''.$attribs['STYLE'].
            '\')';

        return parent::insert($statement);
    }

    
    /**
     * update
     * 
     */
    
    public static function update($query)
    {
        return parent::insert($query);
    }
    

    /**
     * validateUser
     * 
     * Based on given credentials, check if username and password
     * have a matching tuple in the gallery_users table.
     * 
     * @param array $creds An associative array containing 'username'
     * and 'password'.
     * 
     * @return string '1' if creds are in the table, '0' otherwise.
     */

    public static function validateUser(&$creds)
    {
        $query = 'select count(*) ';
        $query .= 'from gallery_users ';
        $query .= "where username='" . $creds['username'] . "' ";
        $query .= "and password='" . $creds['password'] . "'";
        
        return parent::select($query)[0]['COUNT(*)'];
    }
}
