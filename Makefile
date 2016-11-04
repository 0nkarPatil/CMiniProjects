project: srs.c srsmain.c headerfile.h
	gcc srsmain.c srs.c -o project `pkg-config --cflags --libs gtk+-3.0`
