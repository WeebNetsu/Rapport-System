/*
g++ -I/usr/include/python3.6/ *.cpp *.hpp -L/usr/lib/python3.6/config-3.6m-x86_64-linux-gnu -lpython3.6 -L/usr/include/mysql/mysql -lmysqlclient -o output && ./output 
*/

#include <iostream>
#include </usr/include/mysql/mysql.h>

#include "Database.hpp"
#include "PythonCode.hpp"

int main(int argc, char *argv[])
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
    
    //why use a pointer? because I want to.
    PythonCode* myCode = new PythonCode(argv);
    //default max lines is 100
    const char *pythonCommands[myCode->getMaxLines()] = {
        "from PIL import Image, ImageDraw, ImageFont", 
        "import datetime, textwrap", 
        "now = datetime.datetime.now()", 
        "imgRapport = Image.open('src/images/rapport.jpg')", 
        "draw = ImageDraw.Draw(imgRapport)", 
        "font_bold = ImageFont.truetype('src/fonts/roboto_medium.ttf', 60)", 
        "font_normal = ImageFont.truetype('src/fonts/roboto_regular.ttf', 35)", 
        "school_name = 'High School Van Rooisenveld'", 
        "student_name = 'Neil'", 
        "student_surname = 'Von Trador'", 
        "student_grade = 9", 
        "current_year = now.year", 
        "draw.text((110, 30), school_name, (0, 0, 0), font=font_bold)",
        "draw.text((350, 147), student_name, (0, 0, 0), font=font_normal)",
        "draw.text((350, 210), student_surname, (0, 0, 0), font=font_normal)",
        "draw.text((350, 270), str(student_grade), (0, 0, 0), font=font_normal)",
        "draw.text((350, 320), str(current_year), (0, 0, 0), font=font_normal)",
        "subject_font = ImageFont.truetype('src/fonts/roboto_regular.ttf', 32)",
        "subject_1 = 'Engineering and Graphics Design'",
        "top = 480",
        "draw.text((10, top), subject_1, (0, 0, 0), font=subject_font)",
        "draw.text((10, top + 52), subject_1, (0, 0, 0), font=subject_font)",
        "draw.text((10, top + 102), subject_1, (0, 0, 0), font=subject_font)",
        "draw.text((10, top + 152), subject_1, (0, 0, 0), font=subject_font)",
        "draw.text((10, top + 202), subject_1, (0, 0, 0), font=subject_font)",
        "draw.text((10, top + 252), subject_1, (0, 0, 0), font=subject_font)",
        "draw.text((10, top + 302), subject_1, (0, 0, 0), font=subject_font)",
        "mark_font = ImageFont.truetype('src/fonts/roboto_medium.ttf', 37)",
        "mark_1 = 55",
        "right = 580",
        "draw.text((right, top), str(mark_1), (0, 0, 0), font=mark_font)",
        "draw.text((right, top + 52), str(mark_1), (0, 0, 0), font=mark_font)",
        "draw.text((right, top + 102), str(mark_1), (0, 0, 0), font=mark_font)",
        "draw.text((right, top + 152), str(mark_1), (0, 0, 0), font=mark_font)",
        "draw.text((right, top + 202), str(mark_1), (0, 0, 0), font=mark_font)",
        "draw.text((right, top + 252), str(mark_1), (0, 0, 0), font=mark_font)",
        "draw.text((right, top + 302), str(mark_1), (0, 0, 0), font=mark_font)",
        "mark_1_avg = 60",
        "right = 750",
        "draw.text((right, top), str(mark_1_avg), (0, 0, 0), font=mark_font)",
        "draw.text((right, top + 52), str(mark_1_avg), (0, 0, 0), font=mark_font)",
        "draw.text((right, top + 102), str(mark_1_avg), (0, 0, 0), font=mark_font)",
        "draw.text((right, top + 152), str(mark_1_avg), (0, 0, 0), font=mark_font)",
        "draw.text((right, top + 202), str(mark_1_avg), (0, 0, 0), font=mark_font)",
        "draw.text((right, top + 252), str(mark_1_avg), (0, 0, 0), font=mark_font)",
        "draw.text((right, top + 302), str(mark_1_avg), (0, 0, 0), font=mark_font)",
        "message_font = ImageFont.truetype('src/fonts/roboto_medium.ttf', 30)",
        "my_wrap = textwrap.TextWrapper(width = 70)",
        "extra_notes = f'{student_name} {student_surname} has passed grade {student_grade} with average marks and is promoted to grade {student_grade + 1}. Good job, welcome to the grade {student_grade + 1} class of {current_year + 1}.'",
        "draw.text((10, 850), my_wrap.fill(text = extra_notes), (0, 0, 0), font=message_font)",
        "imgRapport.show()"
    };

    myCode->executePython(pythonCommands);

    myCode->~PythonCode();
   
    return 0;
}