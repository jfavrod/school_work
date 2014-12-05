SRCDIR := source
OBJDIR := builds
INCDIR := includes

B_SRC  := $(addprefix $(SRCDIR)/,B.c, find_max.c, strappend.c, header.h)
B_OBJS := B.o find_max.o strappend.o

C_SRC  := $(SRCDIR)/C.c
C_OBJS := C.o

all: B C

B : $(B_OBJS)
	gcc -o B $(B_OBJS)

C : $(C_OBJS)
	gcc -o C $(C_OBJS)

B.o : $(SRCDIR)/B.c $(INCDIR)/header.h
	gcc -Wall -ansi -c $(SRCDIR)/B.c $(INCDIR)/header.h

find_max.o : $(SRCDIR)/find_max.c
	gcc -Wall -ansi -c $(SRCDIR)/find_max.c

strappend.o : $(SRCDIR)/strappend.c
	gcc -Wall -ansi -c $(SRCDIR)/strappend.c

C.o : $(SRCDIR)/C.c
	gcc -Wall -ansi -c $(SRCDIR)/C.c

clean:
	mv $(B_OBJS) $(OBJDIR)
	mv $(C_OBJS) $(OBJDIR)

cleanB:
	mv $(B_OBJS) $(OBJDIR)

cleanC:
	mv $(C_OBJS) $(OBJDIR)
