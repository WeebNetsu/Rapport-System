/*
g++ -I/usr/include/python3.6/ *.cpp *.hpp -L/usr/lib/python3.6/config-3.6m-x86_64-linux-gnu -lpython3.6 -L/usr/include/mysql/mysql -lmysqlclient -o output && ./output 
*/

#include <iostream>

#include "Database.hpp"
#include "Student.hpp"

int main(int argc, char *argv[])
{
    // MYSQL *con;	// the connection
    // MYSQL_RES *res;	// the results
    // MYSQL_ROW row;	// the results rows (array)

    Database user("localhost", "netsu", "root", "school");
    Student student;
    student.createImage(1, user, argv);
    // connect to the mysql database
    // con = user.mysql_connection_setup();

    // // get the results from executing commands
    // res = user.mysql_perform_query(con, "show tables;");

    // std::cout << ("Database Output:\n") << std::endl;

    // while ((row = mysql_fetch_row(res)) != NULL){
    //     // the below row[] parametes may change depending on the size of the table and your objective
    //     std::cout << row[0] << std::endl;
    // }

    // // clean up the database result
    // mysql_free_result(res);
    // // close database connection
    // mysql_close(con);
    
    // PythonCode* myCode = new PythonCode(argv);
    // //default max lines is 100
    // // const char *pythonCommands[myCode->getMaxLines()];
    // const char *pythonCommands[myCode->getMaxLines()] = {
    //     "import sys",
    //     "sys.argv = [24, 35, \"good\"]", //pass in arguments for the python file to use
    //     "exec(open('design_rapport.py').read())"
    // };

    // myCode->executePython(pythonCommands);

    // myCode->~PythonCode();
   
    return 0;
}