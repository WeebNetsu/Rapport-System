// g++ connectdb.cpp -o output -L/usr/include/mariadb/mysql -lmariadbclient
#include <iostream>
#include <mariadb/mysql.h> 

#include "Database.h"


Database::Database(const char *server, const char *user, const char *password, const char *database)
{
    this->server = server;
    this->user = user;
    this->password = password;
    this->database = database;
}

Database::~Database()
{
}

MYSQL* Database::mysql_connection_setup(){
    MYSQL *connection = mysql_init(NULL); // mysql instance
    
    //connect database
    if(!mysql_real_connect(connection, this->server, this->user, this->password, this->database, 0, NULL, 0)){
        std::cout << "Connection Error: " << mysql_error(connection) << std::endl;
        exit(1); 
    }

    return connection;
}

// mysql_res = mysql result
MYSQL_RES* Database::mysql_perform_query(MYSQL *connection, const char *sql_query){
    //send query to db
    if(mysql_query(connection, sql_query)){
        std::cout << "MySQL Query Error: " << mysql_error(connection) << std::endl;
        exit(1);
    }

    return mysql_use_result(connection);
}