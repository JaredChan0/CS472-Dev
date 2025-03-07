
HEADERS = udp_proto.h
CFLAGS = -g -Wall -Wno-unused-function
CC = gcc

all: du-ftp

du-proto.o: du-proto.c du-proto.h
	$(CC) $(CFLAGS) -c du-proto.c -o du-proto.o

du-ftp.o: du-ftp.c du-ftp.h
	$(CC) $(CFLAGS) -c du-ftp.c -o du-ftp.o

du-ftp: du-ftp.o du-proto.o
	$(CC) $(CFLAGS) du-proto.o du-ftp.o -o du-ftp

run:
	./du-ftp

clean:
	rm ./objs/* ./du-ftp
