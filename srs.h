#ifndef __DEMO__H
#define __DEMO__H

typedef struct Window_grid{
	GtkWidget *window;
	GtkWidget *grid;
}Window_grid;

GtkWidget *init_window(GtkApplication *);  //this is the prototype for initialize function
void activate (GtkApplication *app, Window_grid *win_grid); // prototype for activate

#endif
