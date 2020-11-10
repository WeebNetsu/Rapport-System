#ifndef DATABASE_H
#define DATABASE_H 

#include <mariadb/mysql.h> // /usr/includes/mariadb/mysql.h

class Database
{
private:
    const char *server, *user, *password, *database;
public:
    Database(const char *server, const char *user, const char *password, const char *database);

    MYSQL* mysql_connection_setup();
    MYSQL_RES* mysql_perform_query(MYSQL *connection, const char *sql_query);

    const char getServer();
    const char getUser();
    const char getPassword();
    const char getDatabase();

    ~Database();
};

#endif
