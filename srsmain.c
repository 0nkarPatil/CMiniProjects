/********************************************************************************
* Student Record System(Hostel)                                         *
*                                                                               *
* Copyright (C) 2016 Onkar Rajendra Patil                                  	*                                                      
* License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html> *
* This is free software: you are free to change and redistribute it.            *
* There is NO WARRANTY, to the extent permitted by law.                         *
*                                                                               *
*********************************************************************************/
#include <gtk/gtk.h>
#include "headerfile.h"
#include <string.h>
int main(int argc, char *argv[]){
	char ch;
	if(argc > 2) {						/*for -h option*/
		perror("usage:- ./project -h  ");
		return 0;	
	}
	if(argc == 2) {				
		if(!strcmp(argv[1], "-h")){
			FILE* fp = fopen("./usage/usage.txt", "a+");
			if(fp == NULL) {
				perror("fopen can't open file\n You can read it manually from usage folder");
				return 0;
			}
			while(!feof(fp)){
				fscanf(fp, "%c", &ch);
				printf("%c", ch);
			}
			fclose(fp);
		}
		else
			perror("usage:-  ./project -h  ");
		return 0;
	}
	
	GtkApplication *app;
	int status;
	
	app = gtk_application_new("org.gtk.example", G_APPLICATION_FLAGS_NONE);
	g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
	
	status = g_application_run(G_APPLICATION(app), argc, argv);
	g_object_unref(app);
	
	g_signal_connect(app, "destroy", G_CALLBACK(gtk_main_quit), NULL);
	return status;
}
