CC = gcc
CFLAGS = -I.

LECTURE_2 = lecture_2
LECTURE_3 = lecture_3
LECTURE_4 = lecture_4
LECTURE_5 = lecture_5
LECTURE_6 = lecture_6
LECTURE_7 = lecture_7
PROCS = $(LECTURE_2) $(LECTURE_3) $(LECTURE_4) $(LECTURE_5) $(LECTURE_6) $(LECTURE_7)
HDRS = printbinary.h stack1.h stack2.h
SRCS = lecture_2.c lecture_3.c lecture_4.c lecture_5.c lecture_6.c lecture_7.c printbinary.c stack1.c stack2.c
OBJS = lecture_2.o lecture_3.o lecture_5.o lecture_5.o lecture_6.o lecture_7.c printbinary.o stack1.o stack2.o

$(LECTURE_2): lecture_2.o printbinary.o
	$(CC) -o lecture_2 lecture_2.o printbinary.o $(CFLAGS)

$(LECTURE_3): lecture_3.o printbinary.o
	$(CC) -o lecture_3 lecture_3.o printbinary.o $(CFLAGS)

$(LECTURE_4): lecture_4.o printbinary.o
	$(CC) -o lecture_4 lecture_4.o printbinary.o $(CFLAGS)

$(LECTURE_5): lecture_5.o stack1.o
	$(CC) -o lecture_5 lecture_5.o stack1.o $(CFLAGS)

$(LECTURE_6): lecture_6.o stack2.o
	$(CC) -o lecture_6 lecture_6.o stack2.o $(CFLAGS)

$(LECTURE_7): lecture_7.o stack2.o
	$(CC) -o lecture_7 lecture_7.o stack2.o $(CFLAGS)

clean:
	rm -f *.o $(PROCS)

printbinary.o: printbinary.h
stack1.o: stack1.h
stack2.o: stack2.h
