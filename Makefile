project: srs.c mainprog.c srs.h
	gcc mainprog.c srs.c -o project `pkg-config --cflags --libs gtk+-3.0`
