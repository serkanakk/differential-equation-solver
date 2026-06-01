console.log("APP JS LOADED");
document.addEventListener(
    "DOMContentLoaded",
    () => {
        const loginButton =
            document.getElementById(
                "loginBtn");

        if (!loginButton) {
            return;
        }

        loginButton.addEventListener(
            "click",
            async () => {
                const username =
                    document.getElementById(
                        "username").value;

                const password =
                    document.getElementById(
                        "password").value;

                const response =
                    await fetch(
                        "http://localhost:8080/login",
                        {
                            method: "POST",

                            headers:
                            {
                                "Content-Type":
                                    "application/x-www-form-urlencoded"
                            },

                            body:
                                `username=${username}&password=${password}`
                        });

                const result =
                    await response.text();

                alert(result);

                if (result === "Login successful") {
                    window.location.href =
                        "dashboard.html";
                }
            });
    });