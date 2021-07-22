# #!/bin/bash
# make file for class Date
Project_11:  Project_11.o  Project_11_main.o
	g++   Project_11.o Project_11_main.o -o Project_11

Project_11.o: Project_11.cpp P11.h
	g++   -c  Project_11.cpp

Project_11_main.o:  P11.h  Project_11_main.cpp
	g++   -c  Project_11_main.cpp
clean:
	rm *.o Project_11

