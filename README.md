# Differential Equation Solver

A web-based differential equation solver implemented in C++ with a custom HTTP server, SQLite database integration, and dynamic frontend visualization.

## Features

### User Management

* User Registration
* User Login Authentication
* User Logout
* Session-Based User Access
* SQLite Database Integration

### Differential Equation Solvers

* Euler Method
* Heun Method
* Runge-Kutta 4th Order Method (RK4)
* Runtime Equation Parsing
* Impulsive Differential Systems

### Solution Management

* Save Solutions to Database
* User-Specific Solution History
* Delete Saved Solutions
* View Numerical Results
* CSV Export

### Frontend Interface

* Login Page
* Registration Page
* Main Solver Interface
* Solution History Page
* Results Visualization Page
* Graph Visualization Page

### Data Visualization

* Plotly.js Integration
* Dynamic Graph Generation
* X(t), Y(t), and Z(t) Visualization
* Persistent Solution Retrieval

### Web Server

* HTTP Server Infrastructure using cpp-httplib
* REST-style API Endpoints
* Localhost API Support
* Frontend-Backend Communication

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

Frontend (HTML/CSS/JavaScript)

↓

HTTP API (cpp-httplib)

↓

C++ Backend

↓

SQLite Database

## Project Status

### Completed

* Euler Method implementation
* Heun Method implementation
* Runge-Kutta 4th Order implementation
* Impulsive differential system support
* Runtime equation parsing
* User registration and login system
* User logout functionality
* SQLite database integration
* Solution persistence
* User-specific solution history
* Solution deletion
* CSV export functionality
* Frontend user interface
* HTTP server infrastructure
* REST API endpoints
* Frontend-backend communication
* Dynamic graph visualization
* Numerical result visualization
* Plotly.js integration

### Future Improvements

* Improved UI/UX design
* Interactive graph controls
* Enhanced error handling and validation
* Responsive design support
* Advanced equation templates
* Multi-user session improvements

## Latest Update

Implemented complete frontend-backend integration using cpp-httplib and SQLite. Added user-specific solution history, solution deletion, persistent result retrieval, Plotly-based graph visualization, session management, and automatic loading of saved numerical solutions. Users can solve differential equation systems, store solutions, review historical computations, visualize graphs, and inspect numerical results through a web interface.
