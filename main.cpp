#include <iostream>
#include <mariadb/mysql.h>

#include "Database.h"

int main(int argc, char const *argv[])
{
    MYSQL *con;	// the connection
    MYSQL_RES *res;	// the results
    MYSQL_ROW row;	// the results rows (array)

    Database user("localhost", "netsu", "root", "school");

    // connect to the mysql database
    con = user.mysql_connection_setup();

    // get the results from executing commands
    res = user.mysql_perform_query(con, "show tables;");

    std::cout << ("Database Output:\n") << std::endl;

    while ((row = mysql_fetch_row(res)) != NULL){
        // the below row[] parametes may change depending on the size of the table and your objective
        std::cout << row[0] << std::endl;
    }

    // clean up the database result
    mysql_free_result(res);
    // close database connection
    mysql_close(con);

    return 0;
}