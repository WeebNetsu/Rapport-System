#!/bin/bash

# make && echo "" && echo "----- Now Running -----" && echo "" && ./output
echo "" && g++ *.cpp -L/usr/lib/python3.6/config-3.6m-x86_64-linux-gnu -lpython3.6 -lmysqlclient -o output && ./output 

#g++ -I/usr/include/python3.6/ *.cpp *.hpp -L/usr/lib/python3.6/config-3.6m-x86_64-linux-gnu -lpython3.6 -L/usr/include/mysql/mysql -lmysqlclient -o output && ./output 

# echo "" && g++ *.cpp *.hpp -I/usr/include/python3.6/ -L/usr/lib/python3.6/config-3.6m-x86_64-linux-gnu -lpython3.6 -L/usr/include/mysql/mysql -lmysqlclient -o output && ./output 
