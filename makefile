#------------------------------------------------------------------------------

SOURCE=main.cpp
MYPROGRAM=memorymanager
MYINCLUDES=/home/scale/g++Projects/gLib/

MYLIBRARIES=fltk
CC=g++
CFLAGS= -g -Wall -Wextra
#------------------------------------------------------------------------------



all: $(MYPROGRAM)



$(MYPROGRAM): $(SOURCE)

	$(CC) $(SOURCE) $(CFLAGS) -o$(MYPROGRAM)

clean:

	rm -f $(MYPROGRAM)





