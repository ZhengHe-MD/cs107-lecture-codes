CC = gcc
CFLAGS = -I.

LECTURE_2 = lecture_2
LECTURE_3 = lecture_3
LECTURE_4 = lecture_4
LECTURE_5 = lecture_5
LECTURE_6 = lecture_6
PROCS = $(LECTURE_2) $(LECTURE_3) $(LECTURE_4) $(LECTURE_5) $(LECTURE_6)
HDRS = printbinary.h stack.h generic_stack.h
SRCS = lecture_2.c lecture_3.c lecture_4.c lecture_5.c lecture_6.c printbinary.c stack.c generic_stack.c
OBJS = lecture_2.o lecture_3.o lecture_5.o lecture_5.o lecture_6.o printbinary.o stack.o generic_stack.o

$(LECTURE_2): lecture_2.o printbinary.o
	$(CC) -o lecture_2 lecture_2.o printbinary.o $(CFLAGS)

$(LECTURE_3): lecture_3.o printbinary.o
	$(CC) -o lecture_3 lecture_3.o printbinary.o $(CFLAGS)

$(LECTURE_4): lecture_4.o printbinary.o
	$(CC) -o lecture_4 lecture_4.o printbinary.o $(CFLAGS)

$(LECTURE_5): lecture_5.o stack.o
	$(CC) -o lecture_5 lecture_5.o stack.o $(CFLAGS)

$(LECTURE_6): lecture_6.o generic_stack.o
	$(CC) -o lecture_6 lecture_6.o generic_stack.o $(CFLAGS)

clean:
	rm -f *.o $(PROCS)

printbinary.o: printbinary.h
stack.o: stack.h
generic_stack.o: generic_stack.h
