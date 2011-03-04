#
#	Makefile for lab2
#
#	-> Set the three variables to what works for you:

CC = g++
EXENAME = lab2
DEST = ~/Documents/School/CISP400/Code/Homework/Lab2

$(EXENAME): main.o account_read.o account_write.o
	$(CC) main.o account_read.o account_write.o -o $(DEST)$(EXENAME)

main.o: main.cpp account.h
	$(CC) -c main.cpp

account_read.o: account_readwrite.cpp account.h
	$(CC) -c account_readwrite.cpp

clean:
	rm -rf *.o


