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

    int getUserId(
        const std::string &username);

    bool saveSolution(
        int userId,
        const std::string &equation1,
        const std::string &equation2,
        const std::string &equation3,
        const std::string &method);

    void showUserSolutions(
        int userId);
};
