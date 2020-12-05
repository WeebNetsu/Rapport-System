#include </usr/include/mysql/mysql.h>
#include <iostream>

#include "Student.hpp"
#include "Database.hpp"
#include "PythonCode.hpp"

Student::Student()
{
    //NB: THE ORDER IS THE SAME AS IN THE DATABASE, DO NOT MODIFY
    this->subjects_names[0] = "math";
    this->subjects_names[1] = "math_literacy";
    this->subjects_names[2] = "information_technology";
    this->subjects_names[3] = "physical_sciences";
    this->subjects_names[4] = "life_sciences";
    this->subjects_names[5] = "engineering_and_graphics_design";
    this->subjects_names[6] = "history";
    this->subjects_names[7] = "geography";
    this->subjects_names[8] = "art";
    this->subjects_names[9] = "music";
    this->subjects_names[10] = "business";
    this->subjects_names[11] = "computer_sciences";
    this->subjects_names[12] = "afrikaans";
    this->subjects_names[13] = "afrikaans_fal";
    this->subjects_names[14] = "english";
    this->subjects_names[15] = "english_fal";
    this->subjects_names[16] = "life_orientation";
    //  {"math", "math_literacy", "information_technology", "physical_sciences", "life_sciences", "engineering_and_graphics_design", "history", "geography", "art", "music", "business", "computer_sciences", "afrikaans", "afrikaans_fal", "english", "english_fal", "life_orientation"};
}

std::string Student::subjectsTaking(int id, Database user){
    return "";
}

void Student::createImage(int id, Database user, char *argv[])
{
    MYSQL *con;     // the connection
    MYSQL_RES *res; // the results
    MYSQL_ROW row;  // the results rows (array)

    // connect to the mysql database
    con = user.mysql_connection_setup();

    // get the results from executing commands
    res = user.mysql_perform_query(con, "select * from tblMarks where student_id = 1;");

    std::cout << ("Database Output:\n") << std::endl;

    while ((row = mysql_fetch_row(res)) != NULL)
    {
        // the below row[] parametes may change depending on the size of the table and your objective
        // std::cout << row[0] << std::endl;

        for (int i = 0; i < 17; i++)
        {
            this->subject_marks[i] = atoi(row[i + 1]);
            // std::cout << this->subjects_names[i] << ": " << this->subject_marks[i] << std::endl;
        }
    }

    // clean up the database result
    mysql_free_result(res);
    // close database connection
    mysql_close(con);

    PythonCode *myCode = new PythonCode(argv);
    //default max lines is 100
    // const char *pythonCommands[myCode->getMaxLines()];
    const char *pythonCommands[myCode->getMaxLines()] = {
        "import sys",
        "sys.argv = [24, 35, \"good\"]", //pass in arguments for the python file to use
        "exec(open('design_rapport.py').read())"};

    // myCode->executePython(pythonCommands);

    myCode->~PythonCode();
}

Student::~Student()
{
}