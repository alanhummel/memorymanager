#------------------------------------------------------------------------------

SOURCE=main.cpp
MYPROGRAM=memorymanager
MYINCLUDES=/home/scale/g++Projects/gLib/

MYLIBRARIES=fltk
CC=g++

#------------------------------------------------------------------------------



all: $(MYPROGRAM)



$(MYPROGRAM): $(SOURCE)

	$(CC) $(SOURCE) -o$(MYPROGRAM)

clean:

	rm -f $(MYPROGRAM)





