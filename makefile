CC = gcc
CFLAGS = -I.

LECTURE_2 = lecture_2
LECTURE_3 = lecture_3
PROCS = $(LECTURE_2) $(LECTURE_3)
HDRS = printbinary.h
SRCS = lecture_2.c lecture_3.c printbinary.c
OBJS = lecture_2.o lecture_3.o printbinary.o

$(LECTURE_2): lecture_2.o printbinary.o
	$(CC) -o lecture_2 lecture_2.o printbinary.o $(CFLAGS)

$(LECTURE_3): lecture_3.o printbinary.o
	$(CC) -o lecture_3 lecture_3.o printbinary.o $(CFLAGS)

clean:
	rm -f *.o $(PROCS)

printbinary.o: printbinary.h