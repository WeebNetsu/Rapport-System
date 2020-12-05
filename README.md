# Rapport-System
School rapport generator using a <i>MySQL</i> database, C++ and Python.

## How to run
To run this you have to do make a few configurations, now let's start:

1. Create a local database (<b>MySQL</b> or <b>MariaDB</b>). The table and default data can be found in <i>"db.sql"</i>

2. Configure the <b>"#include </usr/include/mysql/mysql.h>"</b> in "main.cpp" (if necessary) and "Database.h" to work with your MySQL or MariaDB coniguration. This should become something as such: "<mysql.h>" or "<mysql/mysql.h>" or something close to it. In my case, I could find the mysql.h file here: "/usr/includes/mysql/mysql.h". Yours should be somewhere near there.

3. Modify the include inside <b>"PythonCode.hpp"</b> just like above, but for Python.h.

4. Run the code: g++ *.cpp -L/usr/lib/python3.6/config-3.6m-x86_64-linux-gnu -lpython3.6 -lmysqlclient -o output && ./output 

Just remember to modify the above g++ if needed

## Note:
This project is/was developed on Linux Mint