#include "DatabaseManager.h"

#include <iostream>

DatabaseManager::DatabaseManager()
{
    db = nullptr;
}

DatabaseManager::~DatabaseManager()
{
    disconnect();
}

bool DatabaseManager::connect(
    const std::string &dbPath)
{
    int result =
        sqlite3_open(
            dbPath.c_str(),
            &db);

    if (result != SQLITE_OK)
    {
        std::cout
            << "Database connection failed!"
            << std::endl;

        return false;
    }

    std::cout
        << "Database connected successfully!"
        << std::endl;

    return true;
}

void DatabaseManager::disconnect()
{
    if (db != nullptr)
    {
        sqlite3_close(db);

        db = nullptr;
    }
}

bool DatabaseManager::registerUser(
    const std::string &username,
    const std::string &email,
    const std::string &password)
{
    std::string sql =
        "INSERT INTO Users(username,email,password) "
        "VALUES('" +
        username + "','" +
        email + "','" +
        password + "');";

    char *errorMessage = nullptr;

    int result =
        sqlite3_exec(
            db,
            sql.c_str(),
            nullptr,
            nullptr,
            &errorMessage);

    if (result != SQLITE_OK)
    {
        std::cout
            << "Registration failed: "
            << errorMessage
            << std::endl;

        sqlite3_free(errorMessage);

        return false;
    }

    std::cout
        << "User registered successfully!"
        << std::endl;

    return true;
}

bool DatabaseManager::loginUser(
    const std::string &username,
    const std::string &password)
{
    std::string sql =
        "SELECT * FROM Users "
        "WHERE username='" +
        username +
        "' AND password='" +
        password +
        "';";

    sqlite3_stmt *statement;

    int result =
        sqlite3_prepare_v2(
            db,
            sql.c_str(),
            -1,
            &statement,
            nullptr);

    if (result != SQLITE_OK)
    {
        return false;
    }

    result = sqlite3_step(statement);

    bool found =
        (result == SQLITE_ROW);

    sqlite3_finalize(statement);

    return found;
}