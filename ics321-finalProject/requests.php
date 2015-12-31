<?php
require_once('config.php');
use Epoque\ICSProject\Model;

// TO DO:

// * Sanitize input!


if (filter_input(INPUT_POST, 'fetch')) {
    echo 
        Model::fetch(filter_input(INPUT_POST, 'fetch'));
}

else if (filter_input(INPUT_POST, 'insert') && filter_input(INPUT_POST, 'table')) {
    $table   = filter_input(INPUT_POST, 'table');
    $values = json_decode(filter_input(INPUT_POST, 'insert'), true);
    
    echo
        Model::insert($table, $values);    
}

else if (filter_input(INPUT_POST, 'update')) {
    $query = filter_input(INPUT_POST, 'update');
    
    echo 
        Model::update($query);
}

else if (filter_input(INPUT_POST, 'insertArtist')) {
    $attribs = filter_input(INPUT_POST, 'insertArtist');
    
    echo
        Model::insertArtist( json_decode($attribs, true) );
}

else if (filter_input(INPUT_POST, 'validateUser')) {
    $creds = filter_input(INPUT_POST, 'validateUser');
    
    echo
        Model::validateUser(json_decode($creds, true));
}

else if (filter_input(INPUT_POST, 'sessionStart')) {
    $user = filter_input(INPUT_POST, 'sessionStart');
    $redirectUrl = 'http://icsproject.jasonfavrod.com/';
    
    $_SESSION['user'] = $user;

    if ($_SESSION['REDIRECT']) {
        $redirectUrl = $redirectUrl . $_SESSION['REDIRECT'];
    }
    
    echo $redirectUrl;
}

else {
    print_r($_POST);
    echo "doh!";
}
