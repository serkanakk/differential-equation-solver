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

int DatabaseManager::getUserId(
    const std::string &username)
{
    std::string sql =
        "SELECT id FROM Users WHERE username='" +
        username +
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
        return -1;
    }

    result = sqlite3_step(statement);

    int userId = -1;

    if (result == SQLITE_ROW)
    {
        userId =
            sqlite3_column_int(
                statement,
                0);
    }

    sqlite3_finalize(statement);

    return userId;
}

bool DatabaseManager::saveSolution(
    int userId,
    const std::string &equation1,
    const std::string &equation2,
    const std::string &equation3,
    const std::string &method)
{
    std::string sql =
        "INSERT INTO Solutions("
        "userId,equation1,equation2,equation3,method,resultFile)"
        " VALUES(" +
        std::to_string(userId) +
        ",'" +
        equation1 +
        "','" +
        equation2 +
        "','" +
        equation3 +
        "','" +
        method +
        "','results.csv');";

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
            << "Solution save failed!"
            << std::endl;

        sqlite3_free(errorMessage);

        return false;
    }

    std::cout
        << "Solution saved successfully!"
        << std::endl;

    return true;
}

void DatabaseManager::showUserSolutions(
    int userId)
{
    std::string sql =
        "SELECT id,equation1,equation2,equation3,method,createdAt "
        "FROM Solutions WHERE userId=" +
        std::to_string(userId) +
        ";";

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
        std::cout
            << "Failed to load history!"
            << std::endl;

        return;
    }

    std::cout
        << "\n===== MY HISTORY =====\n"
        << std::endl;

    while (sqlite3_step(statement) == SQLITE_ROW)
    {
        std::cout
            << "Solution ID: "
            << sqlite3_column_int(statement, 0)
            << std::endl;

        std::cout
            << "Equation 1: "
            << reinterpret_cast<const char *>(
                   sqlite3_column_text(statement, 1))
            << std::endl;

        std::cout
            << "Equation 2: "
            << reinterpret_cast<const char *>(
                   sqlite3_column_text(statement, 2))
            << std::endl;

        std::cout
            << "Equation 3: "
            << reinterpret_cast<const char *>(
                   sqlite3_column_text(statement, 3))
            << std::endl;

        std::cout
            << "Method: "
            << reinterpret_cast<const char *>(
                   sqlite3_column_text(statement, 4))
            << std::endl;

        std::cout
            << "Date: "
            << reinterpret_cast<const char *>(
                   sqlite3_column_text(statement, 5))
            << std::endl;

        std::cout
            << "------------------------"
            << std::endl;
    }

    sqlite3_finalize(statement);
}