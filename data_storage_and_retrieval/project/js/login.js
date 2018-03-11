 (function () {
    /* global APP */
    
    
    document.getElementById('login-btn').addEventListener('click', login);
    //document.getElementById('register-btn').addEventListener('click', addConfirmation);
    document.getElementById('password').addEventListener('keypress', function (event) { submitOnEnter(event); });
    
    
    /**
     * addConfirmation
     * 
     * 
     * @returns {undefined}
     */
    
    function addConfirmation () {
        var login = document.getElementById('login');
        var confirm = document.createElement('input');
        var clone = this.cloneNode(true);
        
        confirm.setAttribute('type', 'password');
        confirm.setAttribute('id', 'confirmation');
        confirm.setAttribute('placeholder', 'confirm password');
        login.insertBefore(confirm, login.childNodes.item(5));
        
        login.replaceChild(clone, this);
        
        clone.style.width = '150px';
        clone.innerHTML = 'Submit Registration';
        clone.addEventListener('click', register);
    }
    
    /**
     * register
     * 
     * @returns {undefined}
     */
    
    function register() {
        var password = document.getElementById('password');
        var confirmation = document.getElementById('confirmation');
        
        if (password.value === confirmation.value) {
            console.log('confirmed');
        }
        else {
            console.log('confirmation failed');
        }
    }
    
    
    /**
     * login
     * 
     * @returns {undefined}
     */
    
    function login() {
        var username = document.getElementById('username');
        var password = document.getElementById('password');
        var creds = {
            username: username.value,
            password: password.value
        };

        $.ajax({
            url: APP.requests,
            method: APP.method,
            data: {'validateUser': JSON.stringify(creds)},
            success: function (data, textStatus, jqXHR) {
                if (data === '1') {
                    startSession(creds.username);
                }
                else {
                    console.log('not in dare');
                }
            }
        });
    }
    
    
    function startSession(user) {
        $.ajax({
            url: APP.requests,
            method: APP.method,
            data: {'sessionStart': user},
            success: function (data, textStatus, jqXHR) {
                console.log(data);
                window.location.assign(data);
            }
        });
    }
    
    
    function submitOnEnter(event) {
        if (event.key === 'Enter') {
            login();
        }
    }
    
})();
