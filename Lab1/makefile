#
#	Makefile for lab1
#
#	-> Set the three variables to what works for you:

CC = g++
EXENAME = lab1
DEST ~/tmp/

$(EXENAME): main.o getDate.o checkDate.o dateToString.o displayResult.o
	$(CC) main.o getDate.o checkDate.o dateToString.o displayResult.o -o $(DEST)$(EXENAME)

main.o: main.cpp date_type.h
	$(CC) -c main.cpp

getDate.o: getDate.cpp date_type.h
	$(CC) -c getDate.cpp

checkDate.o: checkDate.cpp date_type.h
	$(CC) -c checkDate.cpp

dateToString.o: dateToString.cpp date_type.h
	$(CC) -c dateToString.cpp

displayResult.o: displayResult.cpp date_type.h
	$(CC) -c displayResult.cpp

clean:
	rm -rf *.o


