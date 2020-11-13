# Rapport-System
School rapport generator using a MySQL database, C++ and Python.

## What is this?
This is just a basic school rapport system I'm trying to make using C++ and MySQL.

## How to run
To run this you have to do make a few configurations, now let's start:

1. Create a local database (MySQL or MariaDB). The table and default data can be found in "db.sql"

2. Configure the "#include </usr/include/mysql/mysql.h>" in "main.cpp" and "Database.h" to work with your MySQL or MariaDB coniguration. This should become something as such: "<mysql.h>" or "<mysql/mysql.h>" or something close to it. In my case, I could find the mysql.h file here: "/usr/includes/mysql/mysql.h". Yours should be somewhere near there.

3. Modify the include inside "PythonCode.hpp" just like above, but for Python.h.

4. Run the code: g++ -I/usr/include/python3.6/ *.cpp *.hpp -L/usr/lib/python3.6/config-3.6m-x86_64-linux-gnu -lpython3.6 -L/usr/include/mysql/mysql -lmysqlclient -o output && ./output 

Just remember to modify the above g++

## Note:
This project is/was developed on Linux Mint

## Lost
All these blow may still be valid, but I no longer use them and may add help on them later.

3. Install cmake if you don't have it yet, or use g++ *.cpp *.hpp -o output -L/usr/include/mariadb/mysql -lmariadbclient

3.5 NOTE: On *first* run remember to compile with g++ *.cpp *.hpp -o output -L/usr/include/mariadb/mysql -lmariadbclient ... You need to do this, if you use cmake or not.

4. If you have cmake installed, configure the CMakeLists file if needed and just type "./run.sh" to compile and run the program.