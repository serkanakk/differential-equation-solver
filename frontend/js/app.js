
document.addEventListener("DOMContentLoaded", () => {

    function loadLastResult() {

        const lastSolutionId =
            sessionStorage.getItem(
                "lastSolutionId");

        fetch(
            `http://localhost:8080/results?id=${lastSolutionId}`)
            .then(response => response.json())
            .then(graphData => {

                let html = `
<table class="results-table">

<tr>
    <th>Step</th>
    <th>Time</th>
    <th>X</th>
    <th>Y</th>
    <th>Z</th>
</tr>
`;

                graphData.forEach(point => {

                    html += `
<tr>
    <td>${point.step}</td>
    <td>${point.time}</td>
    <td>${point.x}</td>
    <td>${point.y}</td>
    <td>${point.z}</td>
</tr>
`;
                });

                html += "</table>";

                document.getElementById(
                    "resultBox").innerHTML = html;

                const time = [];
                const xValues = [];
                const yValues = [];
                const zValues = [];

                graphData.forEach(point => {

                    time.push(point.time);

                    xValues.push(point.x);

                    yValues.push(point.y);

                    zValues.push(point.z);
                });

                const traceX = {
                    x: time,
                    y: xValues,
                    mode: 'lines',
                    name: 'X(t)'
                };

                const traceY = {
                    x: time,
                    y: yValues,
                    mode: 'lines',
                    name: 'Y(t)'
                };

                const traceZ = {
                    x: time,
                    y: zValues,
                    mode: 'lines',
                    name: 'Z(t)'
                };

                Plotly.newPlot(
                    'graph',
                    [traceX, traceY, traceZ]);
            });
    }





    if (!sessionStorage.getItem("hasSolved")) {

        sessionStorage.setItem(
            "hasSolved",
            "0");
    }
    const showPassword =
        document.getElementById(
            "showPassword");

    if (showPassword) {

        showPassword.addEventListener(
            "change",
            () => {

                const passwordInput =
                    document.getElementById(
                        "password");

                passwordInput.type =
                    showPassword.checked
                        ? "text"
                        : "password";
            });
    }

    const loginButton = document.getElementById("loginBtn");

    if (loginButton) {
        loginButton.addEventListener("click", async (event) => {
            event.preventDefault();

            const username = document.getElementById("username").value;
            const password = document.getElementById("password").value;

            const response = await fetch("http://localhost:8080/login", {
                method: "POST",
                headers: {
                    "Content-Type": "application/x-www-form-urlencoded"
                },
                body: `username=${username}&password=${password}`
            });

            const result = await response.text();


            if (result === "Login successful") {
                window.location.href = "app.html";
            }
        });
    }

    const registerButton = document.getElementById("registerBtn");

    if (registerButton) {
        registerButton.addEventListener("click", async (event) => {
            event.preventDefault();

            const username = document.getElementById("registerUsername").value;
            const email = document.getElementById("registerEmail").value;
            const password = document.getElementById("registerPassword").value;

            const response = await fetch("http://localhost:8080/register", {
                method: "POST",
                headers: {
                    "Content-Type": "application/x-www-form-urlencoded"
                },
                body: `username=${username}&email=${email}&password=${password}`
            });

            const result = await response.text();

            alert(result);

            if (result === "Registration successful") {
                window.location.href = "login.html";
            }
        });
    }

    const solveButton = document.getElementById("solveBtn");

    if (solveButton) {
        solveButton.addEventListener("click", async (event) => {

            event.preventDefault();



            const equation1 = document.getElementById("equation1").value;
            const equation2 = document.getElementById("equation2").value;
            const equation3 = document.getElementById("equation3").value;
            const method = document.getElementById("method").value;

            const response = await fetch("http://localhost:8080/solve", {
                method: "POST",
                headers: {
                    "Content-Type": "application/x-www-form-urlencoded"
                },
                body: `equation1=${encodeURIComponent(equation1)}&equation2=${encodeURIComponent(equation2)}&equation3=${encodeURIComponent(equation3)}&method=${encodeURIComponent(method)}`
            });

            const result = await response.text();



            const solutionIdMatch =
                result.match(
                    /SOLUTION_ID:(\d+)/);



            if (!solutionIdMatch) {
                alert("NO SOLUTION ID");
                return;
            }

            const solutionId =
                solutionIdMatch[1];
            sessionStorage.setItem(
                "hasSolved",
                "1");

            sessionStorage.setItem(
                "lastSolutionId",
                solutionId);


            const resultBox =
                document.getElementById("resultBox");

            if (resultBox) {
                resultBox.innerText = result;
            }


        });
    }






    if (
        sessionStorage.getItem("hasSolved") === "1"
    ) {

        loadLastResult();
    }


    const logoutBtn =
        document.getElementById(
            "logoutBtn");

    if (logoutBtn) {

        logoutBtn.addEventListener(
            "click",
            () => {

                sessionStorage.setItem(
                    "hasSolved",
                    "0");

                sessionStorage.removeItem(
                    "lastSolutionId");

                window.location.href =
                    "login.html";
            });
    }
    const clearBtn =
        document.getElementById(
            "clearBtn");

    if (clearBtn) {

        clearBtn.addEventListener(
            "click",
            () => {

                sessionStorage.setItem(
                    "hasSolved",
                    "0");

                sessionStorage.removeItem(
                    "lastSolutionId");

                document.getElementById(
                    "resultBox").innerHTML =
                    "No solution calculated yet.";

                document.getElementById(
                    "graph").innerHTML =
                    "Graph will appear here.";
            });
    }
});