SRCDIR := src
OBJDIR := bld
INCDIR := inc
CC     := gcc -ansi -Wall

addrBookUI : addrBookUI.o helpers.o actions.o
	$(CC) -o addrBookUI helpers.o actions.o addrBookUI.o

addrBookUI.o : $(SRCDIR)/addrBookUI.c $(INCDIR)/addrBookUI.h $(INCDIR)/helpers.h $(INCDIR)/actions.h $(INCDIR)/record.h
	cp $(INCDIR)/addrBookUI.h $(SRCDIR)/
	cp $(INCDIR)/helpers.h $(SRCDIR)/
	cp $(INCDIR)/actions.h $(SRCDIR)/
	cp $(INCDIR)/record.h $(SRCDIR)/
	$(CC) -c $(SRCDIR)/addrBookUI.c

helpers.o : $(SRCDIR)/helpers.c
	cp $(INCDIR)/helpers.h $(SRCDIR)/
	$(CC) -c $(SRCDIR)/helpers.c

actions.o : $(SRCDIR)/actions.c $(INCDIR)/record.h
	cp $(INCDIR)/actions.h $(SRCDIR)/
	cp $(INCDIR)/record.h $(SRCDIR)/
	$(CC) -c $(SRCDIR)/actions.c

clean :
	mv addrBookUI.o $(OBJDIR)
	mv helpers.o $(OBJDIR)
	mv actions.o $(OBJDIR)
	mv $(SRCDIR)/addrBookUI.h $(INCDIR)
	mv $(SRCDIR)/helpers.h $(INCDIR)
	mv $(SRCDIR)/actions.h $(INCDIR)
	mv $(SRCDIR)/record.h $(INCDIR)
