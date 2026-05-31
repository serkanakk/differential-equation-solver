#pragma once

#include "../../external/sqlite3.h"

#include <string>

class DatabaseManager
{
private:
    sqlite3 *db;

public:
    DatabaseManager();

    ~DatabaseManager();

    bool connect(const std::string &dbPath);

    void disconnect();

    bool registerUser(
        const std::string &username,
        const std::string &email,
        const std::string &password);

    bool loginUser(
        const std::string &username,
        const std::string &password);
};
