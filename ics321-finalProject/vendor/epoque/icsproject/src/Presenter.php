<?php
namespace Epoque\ICSProject;


class Presenter
{
    /**
     * view
     * 
     * @return tail-call includeViewFromUri
     */
    
    public static function view()
    {
        return self::includeViewFromUri();
    }
    
    
    /**
     * includeViewFromUri
     * 
     * Grabs the request URI, parses it, then includes the view of any
     * requested view that is in the VIEWS_DIR.
     *
     * Required Constants: DEFAULT_VIEW, VIEWS_DIR;
     * 
     * @return void
     */

    private static function includeViewFromUri()
    {
        $URI = ltrim(filter_input(INPUT_SERVER, 'REQUEST_URI', FILTER_SANITIZE_URL), '/');

        if ($URI === '' && DEFAULT_VIEW){
            include(DEFAULT_VIEW);
        }
        else if (in_array("$URI.php", scandir(VIEWS_DIR))) {
            include(VIEWS_DIR."$URI.php");
        }
        else if ($URI === 'logout') {
            session_destroy();
            header('Location: http://icsproject.jasonfavrod.com');
        }
        else {
            include(VIEWS_DIR.'404.php');
        }
    }
    
    /**
     * navList
     * 
     * Prints the site's navigation list (<ul>) if there is a user
     * session.
     * 
     */
    
    public static function navList()
    {

        if (isset($_SESSION['user'])) {
            print '<ul class="nav nav-pills">
                <li role="presentation"><a href="/artists">Artists</a></li>
                <li role="presentation"><a href="/pieces">Pieces</a></li>
                <li role="presentation"><a href="/customers">Customers</a></li>
                <li role="presentation"><a href="/purchases">Purchases</a></li>
                <li role="presentation"><a href="/logout">Logout</a></li>
            </ul>';
        }
    }
}
