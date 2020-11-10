# Rapport-System
School rapport generator using a database

## What is this?
This is just a basic school rapport system I'm trying to make using C++ and MariaDB(MySQL).

## How to run
To run this you have to do make a few configurations, now let's start:

1. Create a local database (MySQL or MariaDB). The table and default data can be found in "db.sql"

2. Configure the "#include <mariadb/mysql.h>" in "main.cpp" and "Database.h" to work with your MySQL or MariaDB coniguration. This should become something as such: "<mysql.h>" or "<mysql/mysql.h>" or something close to it. In my case, I could find the mysql.h file here: "/usr/includes/mariadb/mysql.h". Yours should be somewhere near there.

3. Install cmake if you don't have it yet, or use g++ *.cpp *.h -o output -L/usr/include/mariadb/mysql -lmariadbclient

4. If you have cmake installed, configure the CMakeLists file if needed and just type "./run.sh" to compile and run the program.

## Note:
I used Parrot OS when creating it. Also, the project may not be finished yet.