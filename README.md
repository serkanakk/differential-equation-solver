# Differential Equation Solver

A web-based differential equation solver implemented in C++.

## Features

### User Management

* User Registration
* User Login Authentication
* SQLite Database Integration

### Differential Equation Solvers

* Euler Method
* Heun Method
* Runge-Kutta 4th Order Method
* Runtime Equation Parsing
* Impulsive Differential Systems

### Solution Management

* Save Solutions to Database
* View User Solution History
* CSV Export

### Frontend Interface

* Login Page
* Register Page
* Dashboard Page
* Solve Equation Page
* History Page
* Graph Visualization Page

### Data Visualization

* Plotly.js Integration
* Dynamic Solution Graph Display
* X(t), Y(t), and Z(t) Visualization

### Web Server

* HTTP Server Infrastructure using cpp-httplib
* Localhost API Support
* REST-style API Endpoints

## Technologies

* C++
* CMake
* SQLite
* ExprTk
* HTML
* CSS
* JavaScript
* Plotly.js
* cpp-httplib
* GitHub

## Project Architecture

Frontend (HTML/CSS/JS)
↓
HTTP API (cpp-httplib)
↓
C++ Backend
↓
SQLite Database

## Project Status

### Completed

* Numerical solving algorithms
* Euler Method implementation
* Heun Method implementation
* Runge-Kutta 4th Order implementation
* Impulsive differential system support
* User registration and login
* SQLite database integration
* Solution history management
* CSV export functionality
* Frontend user interface
* HTTP server infrastructure
* Frontend-backend communication
* REST API endpoints
* Dynamic graph visualization
* Plotly.js integration
* History page integration
* Solution persistence and retrieval

### Known Issues

* Registration page does not automatically redirect to login page after successful registration
* Solve page result output is not persistently displayed in the result box

### Planned Improvements

* Improved UI/UX design
* Interactive graph controls
* Per-solution graph storage and visualization
* Enhanced dashboard experience
* Better error handling and validation
* Responsive design improvements

## Latest Update

Implemented complete frontend-backend integration using cpp-httplib. Added solution history retrieval from SQLite, CSV-based result storage, REST API endpoints, and dynamic graph visualization with Plotly.js. Users can now solve differential equation systems, save results, review solution history, and visualize numerical solutions directly in the web interface.
