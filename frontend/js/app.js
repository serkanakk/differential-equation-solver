console.log("APP JS LOADED");

document.addEventListener(
    "DOMContentLoaded",
    () => {
        const loginButton =
            document.getElementById(
                "loginBtn");

        if (loginButton) {
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
        }

        const registerButton =
            document.getElementById(
                "registerBtn");

        if (registerButton) {
            registerButton.addEventListener(
                "click",
                async () => {
                    const username =
                        document.getElementById(
                            "registerUsername").value;

                    const email =
                        document.getElementById(
                            "registerEmail").value;

                    const password =
                        document.getElementById(
                            "registerPassword").value;

                    const response =
                        await fetch(
                            "http://localhost:8080/register",
                            {
                                method: "POST",

                                headers:
                                {
                                    "Content-Type":
                                        "application/x-www-form-urlencoded"
                                },

                                body:
                                    `username=${username}&email=${email}&password=${password}`
                            });

                    const result =
                        await response.text();

                    alert(result);

                    if (result === "Registration successful") {
                        window.location.href =
                            "login.html";
                    }
                });
        }

        const solveButton =
            document.getElementById(
                "solveBtn");

        if (solveButton) {
            solveButton.addEventListener(
                "click",
                async () => {

                    console.log("SOLVE CLICKED");
                    const equation1 =
                        document.getElementById(
                            "equation1").value;

                    const equation2 =
                        document.getElementById(
                            "equation2").value;

                    const equation3 =
                        document.getElementById(
                            "equation3").value;

                    const method =
                        document.getElementById(
                            "method").value;

                    const response =
                        await fetch(
                            "http://localhost:8080/solve",
                            {
                                method: "POST",

                                headers:
                                {
                                    "Content-Type":
                                        "application/x-www-form-urlencoded"
                                },

                                body:
                                    `equation1=${equation1}&equation2=${equation2}&equation3=${equation3}&method=${method}`
                            });

                    const result =
                        await response.text();

                    alert(result);

                });
        }
    });