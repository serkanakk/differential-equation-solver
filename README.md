# Differential Equation Solver

A web-based differential equation solver implemented in C++.

## Features

### User Management
- User Registration
- User Login Authentication
- SQLite Database Integration

### Differential Equation Solvers
- Euler Method
- Heun Method
- Runge-Kutta 4th Order Method
- Runtime Equation Parsing
- Impulsive Differential Systems

### Solution Management
- Save Solutions to Database
- View User Solution History
- CSV Export

### Frontend Interface
- Login Page
- Register Page
- Dashboard Page
- Solve Equation Page
- History Page
- Graph Visualization Page

### Data Visualization
- Plotly.js Integration
- Solution Graph Display

### Web Server
- HTTP Server Infrastructure using cpp-httplib
- Localhost API Support

## Technologies

- C++
- CMake
- SQLite
- ExprTk
- HTML
- CSS
- JavaScript
- Plotly.js
- cpp-httplib
- GitHub

## Project Architecture

```text
Frontend (HTML/CSS/JS)
        ↓
HTTP API (cpp-httplib)
        ↓
C++ Backend
        ↓
SQLite Database
```

## Project Status

### Completed
- Numerical solving algorithms
- Database integration
- User authentication
- Solution history
- CSV export
- Frontend user interface
- HTTP server setup
- Graph visualization infrastructure

### In Progress
- Frontend and Backend Integration
- REST API Development
- Dynamic Data Visualization

### Planned
- Full Web-Based Authentication
- Real-Time Graph Generation
- Interactive Dashboard

## Latest Update

Implemented a web server using cpp-httplib and prepared the project architecture for frontend-backend communication through HTTP APIs.