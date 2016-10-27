
#include <gtk/gtk.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include "srs.h"

typedef struct Gc_master{
	GtkWidget *ent1;
	GtkWidget *ent2;
	GtkWidget *ent3;
	GtkWidget *ent4;
	GtkWidget *ent5;
}Gc_master;

int i=0;

typedef struct record {			
	char mis[400];		// student mis
	char name[200];		// student name
	char address[1000];	// Address of student
	char branch[200];	// Branch of student
        char blockno[200];	// Block of student	
}record;

// global declariations
record rec;

static void on_window_closed(GtkWidget *widget, gpointer data){
	gtk_main_quit();
}

void close_window(GtkWidget *widget, gpointer window)
{
	
    	gtk_widget_destroy(GTK_WIDGET(window));
}


void update_edited_record(GtkWidget *widget, Gc_master *user_data){
}




void delete_student(GtkWidget *widget, Gc_master *user_data){
	int i = atoi(gtk_entry_get_text(GTK_ENTRY(user_data->ent1)));
	FILE* ft = fopen("tmp.txt","a+");
	FILE* fp = fopen("studata.txt","a+");			
	while(1) {
		fscanf(fp, "%s %s %s %s %s", rec.mis,  rec.name, rec.address, rec.branch, rec.blockno);
		if(feof(fp))
				break;
		if(atoi(rec.mis) != i)
			fprintf(ft, "%s %s %s %s %s\n", rec.mis,  rec.name, rec.address, rec.branch, rec.blockno);
	}
	gtk_entry_set_text(GTK_ENTRY(user_data->ent1), "");
	gtk_entry_set_text(GTK_ENTRY(user_data->ent2), "");
	gtk_entry_set_text(GTK_ENTRY(user_data->ent3), "");
	gtk_entry_set_text(GTK_ENTRY(user_data->ent4), "");
	gtk_entry_set_text(GTK_ENTRY(user_data->ent5), "");
	fclose(ft);
	fclose(fp);
	remove("studata.txt");		// remove old file
	rename("tmp.txt", "studata.txt");
}





void cleartext(GtkWidget *widget, Gc_master *user_data){
	gtk_entry_set_text(GTK_ENTRY(user_data->ent1), "");
	gtk_entry_set_text(GTK_ENTRY(user_data->ent2), "");
	gtk_entry_set_text(GTK_ENTRY(user_data->ent3), "");
	gtk_entry_set_text(GTK_ENTRY(user_data->ent4), "");
	gtk_entry_set_text(GTK_ENTRY(user_data->ent5), "");
}



void viewinfilenext(GtkWidget *widget, Gc_master *user_data){
		
}




void viewinfileprev(GtkWidget *widget, Gc_master *user_data){

}





void searchinfile(GtkWidget *widget, Gc_master *user_data){
	int i = atoi(gtk_entry_get_text(GTK_ENTRY(user_data->ent1)));
	FILE *fp = fopen("studata.txt","r+");
	while(1){
		fscanf(fp, "%s%s%s%s%s", rec.mis,  rec.name, rec.address, rec.branch, rec.blockno);
			if(atoi(rec.mis) == i) {	
				gtk_entry_set_text(GTK_ENTRY(user_data->ent2), rec.name);
				gtk_entry_set_text(GTK_ENTRY(user_data->ent3), rec.address);
				gtk_entry_set_text(GTK_ENTRY(user_data->ent4), rec.branch);
				gtk_entry_set_text(GTK_ENTRY(user_data->ent5), rec.blockno);
			}
			if(feof(fp)){
					break;	
			}
	}
	fclose(fp);		
}


void on_button_click(GtkWidget *widget, Gc_master *user_data){
	FILE *fp = fopen("studata.txt","a+");
	fprintf(fp, "%s\t%s\t%s\t%s\t%s\n", gtk_entry_get_text(GTK_ENTRY(user_data->ent1)), gtk_entry_get_text(GTK_ENTRY(user_data->ent2)), gtk_entry_get_text(GTK_ENTRY(user_data->ent3)), gtk_entry_get_text(GTK_ENTRY(user_data->ent4)), gtk_entry_get_text(GTK_ENTRY(user_data->ent5)));
	g_print("Student Details Register Succesfully...!!");
	gtk_entry_set_text(GTK_ENTRY(user_data->ent1), "");
	gtk_entry_set_text(GTK_ENTRY(user_data->ent2), "");
	gtk_entry_set_text(GTK_ENTRY(user_data->ent3), "");
	gtk_entry_set_text(GTK_ENTRY(user_data->ent4), "");
	gtk_entry_set_text(GTK_ENTRY(user_data->ent5), "");
	fclose(fp);				
}




void viewstudent_details(GtkWidget *widget, Window_grid *win_grid){

	GtkWidget *addstu_grid,*btn1,*btn2,*btn3,*btn4,*grid,*ent1,*ent2,*ent3,*ent4,*ent5;
	GtkWidget *entry,*label1,*label2,*label3,*label4,*label5,*labelhead,*labelnull;
	addstu_grid = gtk_grid_new();

	gtk_container_remove(GTK_CONTAINER(win_grid->window), win_grid->grid);
	gtk_container_add(GTK_CONTAINER(win_grid->window), addstu_grid);
	win_grid->grid = addstu_grid;



	Gc_master *master;
	

	master = (Gc_master *)malloc(sizeof(Gc_master));
	master->ent1=gtk_entry_new();
	master->ent2=gtk_entry_new();
	master->ent3=gtk_entry_new();
	master->ent4=gtk_entry_new();
	master->ent5=gtk_entry_new();

	labelhead = gtk_label_new(NULL);
	gtk_label_set_markup(GTK_LABEL(labelhead), "<b><big>     VIEW STUDENT</big></b>\n");
	labelnull = gtk_label_new(" ");
	label1 = gtk_label_new("MIS");
	label2 = gtk_label_new("NAME");
	label3 = gtk_label_new("ADDRESS");
	label4= gtk_label_new("BRANCH");
	label5 = gtk_label_new("BLOCKNO");


	btn1 = gtk_button_new_with_label("PREV");
	btn2 = gtk_button_new_with_label("HOME");
	btn3 = gtk_button_new_with_label("NEXT");
	g_signal_connect(btn1, "clicked", G_CALLBACK(viewinfileprev), master);
	g_signal_connect(btn2, "clicked", G_CALLBACK(activate), win_grid);
	g_signal_connect(btn3, "clicked", G_CALLBACK(viewinfilenext), master);

	
	gtk_grid_attach(GTK_GRID(win_grid->grid), master->ent1, 2,2, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), master->ent2, 2,3, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), master->ent3, 2,4, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), master->ent4, 2,5, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), master->ent5, 2,6, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), labelhead, 1,0, 2 , 2);
	gtk_grid_attach(GTK_GRID(win_grid->grid), label1, 1,2, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), label2, 1,3, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), label3, 1,4, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), label4, 1,5, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), label5, 1,6, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), labelnull, 1,7, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), btn1, 3, 10, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), btn2, 0, 10, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), btn3, 3, 2, 1, 1);
	gtk_widget_show_all(win_grid->window);	
	return;
}





void deletestudent_details(GtkWidget *widget, Window_grid *win_grid){

	GtkWidget *addstu_grid,*btn1,*btn2,*btn3,*btn4,*grid,*ent1,*ent2,*ent3,*ent4,*ent5;
	GtkWidget *entry,*label1,*label2,*label3,*label4,*label5,*labelhead,*labelnull;
	addstu_grid = gtk_grid_new();

	gtk_container_remove(GTK_CONTAINER(win_grid->window), win_grid->grid);
	gtk_container_add(GTK_CONTAINER(win_grid->window), addstu_grid);
	win_grid->grid = addstu_grid;



	Gc_master *master;
	

	master = (Gc_master *)malloc(sizeof(Gc_master));
	master->ent1=gtk_entry_new();
	master->ent2=gtk_entry_new();
	master->ent3=gtk_entry_new();
	master->ent4=gtk_entry_new();
	master->ent5=gtk_entry_new();

	labelhead = gtk_label_new(NULL);
	gtk_label_set_markup(GTK_LABEL(labelhead), "<b><big>     DELETE STUDENT</big></b>\n");
	labelnull = gtk_label_new(" ");
	label1 = gtk_label_new("MIS");
	label2 = gtk_label_new("NAME");
	label3 = gtk_label_new("ADDRESS");
	label4= gtk_label_new("BRANCH");
	label5 = gtk_label_new("BLOCKNO");


	btn1 = gtk_button_new_with_label("CONFIRM-DELETE");
	btn2 = gtk_button_new_with_label("HOME");
	btn3 = gtk_button_new_with_label("DELETE");
	g_signal_connect(btn1, "clicked", G_CALLBACK(delete_student), master);
	g_signal_connect(btn2, "clicked", G_CALLBACK(activate), win_grid);
	g_signal_connect(btn3, "clicked", G_CALLBACK(searchinfile), master);

	
	gtk_grid_attach(GTK_GRID(win_grid->grid), master->ent1, 2,2, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), master->ent2, 2,3, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), master->ent3, 2,4, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), master->ent4, 2,5, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), master->ent5, 2,6, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), labelhead, 1,0, 2 , 2);
	gtk_grid_attach(GTK_GRID(win_grid->grid), label1, 1,2, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), label2, 1,3, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), label3, 1,4, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), label4, 1,5, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), label5, 1,6, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), labelnull, 1,7, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), btn1, 3, 10, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), btn2, 0, 10, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), btn3, 3, 2, 1, 1);
	gtk_widget_show_all(win_grid->window);	
	return;
}






void editstudent_details(GtkWidget *widget, Window_grid *win_grid){
	

	GtkWidget *addstu_grid,*btn1,*btn2,*btn3,*btn4,*grid,*ent1,*ent2,*ent3,*ent4,*ent5;
	GtkWidget *entry,*label1,*label2,*label3,*label4,*label5,*labelhead,*labelnull;
	addstu_grid = gtk_grid_new();

	gtk_container_remove(GTK_CONTAINER(win_grid->window), win_grid->grid);
	gtk_container_add(GTK_CONTAINER(win_grid->window), addstu_grid);
	win_grid->grid = addstu_grid;



	Gc_master *master;
	

	master = (Gc_master *)malloc(sizeof(Gc_master));
	master->ent1=gtk_entry_new();
	master->ent2=gtk_entry_new();
	master->ent3=gtk_entry_new();
	master->ent4=gtk_entry_new();
	master->ent5=gtk_entry_new();

	labelhead = gtk_label_new(NULL);
	gtk_label_set_markup(GTK_LABEL(labelhead), "<b><big>       EDIT STUDENT</big></b>\n");
	labelnull = gtk_label_new(" ");
	label1 = gtk_label_new("MIS");
	label2 = gtk_label_new("NAME");
	label3 = gtk_label_new("ADDRESS");
	label4= gtk_label_new("BRANCH");
	label5 = gtk_label_new("BLOCKNO");


	btn1 = gtk_button_new_with_label("UPDATE");
	btn2 = gtk_button_new_with_label("HOME");
	btn3 = gtk_button_new_with_label("EDIT");
	g_signal_connect(btn1, "clicked", G_CALLBACK(update_edited_record), master);
	g_signal_connect(btn2, "clicked", G_CALLBACK(activate), win_grid);
	g_signal_connect(btn3, "clicked", G_CALLBACK(searchinfile), master);

	
	gtk_grid_attach(GTK_GRID(win_grid->grid), master->ent1, 2,2, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), master->ent2, 2,3, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), master->ent3, 2,4, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), master->ent4, 2,5, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), master->ent5, 2,6, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), labelhead, 1,0, 2 , 2);
	gtk_grid_attach(GTK_GRID(win_grid->grid), label1, 1,2, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), label2, 1,3, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), label3, 1,4, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), label4, 1,5, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), label5, 1,6, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), labelnull, 1,7, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), btn1, 3, 10, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), btn2, 0, 10, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), btn3, 3, 2, 1, 1);
	gtk_widget_show_all(win_grid->window);	
	return;
}




void searchstudent_details(GtkWidget *widget, Window_grid *win_grid){
	

	GtkWidget *addstu_grid,*btn1,*btn2,*btn3,*btn4,*grid,*ent1,*ent2,*ent3,*ent4,*ent5;
	GtkWidget *entry,*label1,*label2,*label3,*label4,*label5,*labelhead,*labelnull;
	addstu_grid = gtk_grid_new();

	gtk_container_remove(GTK_CONTAINER(win_grid->window), win_grid->grid);
	gtk_container_add(GTK_CONTAINER(win_grid->window), addstu_grid);
	win_grid->grid = addstu_grid;



	Gc_master *master;
	

	master = (Gc_master *)malloc(sizeof(Gc_master));
	master->ent1=gtk_entry_new();
	master->ent2=gtk_entry_new();
	master->ent3=gtk_entry_new();
	master->ent4=gtk_entry_new();
	master->ent5=gtk_entry_new();

	labelhead = gtk_label_new(NULL);
	gtk_label_set_markup(GTK_LABEL(labelhead), "<b><big>       SEARCH STUDENT</big></b>\n");
	labelnull = gtk_label_new(" ");
	label1 = gtk_label_new("MIS");
	label2 = gtk_label_new("NAME");
	label3 = gtk_label_new("ADDRESS");
	label4= gtk_label_new("BRANCH");
	label5 = gtk_label_new("BLOCKNO");


	btn1 = gtk_button_new_with_label("CLEAR");
	btn2 = gtk_button_new_with_label("HOME");
	btn3 = gtk_button_new_with_label("SEARCH");
	g_signal_connect(btn1, "clicked", G_CALLBACK(cleartext), master);
	g_signal_connect(btn2, "clicked", G_CALLBACK(activate), win_grid);
	g_signal_connect(btn3, "clicked", G_CALLBACK(searchinfile), master);

	
	gtk_grid_attach(GTK_GRID(win_grid->grid), master->ent1, 2,2, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), master->ent2, 2,3, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), master->ent3, 2,4, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), master->ent4, 2,5, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), master->ent5, 2,6, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), labelhead, 1,0, 2 , 2);
	gtk_grid_attach(GTK_GRID(win_grid->grid), label1, 1,2, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), label2, 1,3, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), label3, 1,4, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), label4, 1,5, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), label5, 1,6, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), labelnull, 1,7, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), btn1, 3, 10, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), btn2, 0, 10, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), btn3, 3, 2, 1, 1);
	gtk_widget_show_all(win_grid->window);	
	return;
}






void addstudent_details(GtkWidget *widget, Window_grid *win_grid){
	

	GtkWidget *addstu_grid,*btn1,*btn2,*btn3,*btn4,*grid,*ent1,*ent2,*ent3,*ent4,*ent5;
	GtkWidget *entry,*label1,*label2,*label3,*label4,*label5,*labelhead,*labelnull;
	addstu_grid = gtk_grid_new();

	gtk_container_remove(GTK_CONTAINER(win_grid->window), win_grid->grid);
	gtk_container_add(GTK_CONTAINER(win_grid->window), addstu_grid);
	win_grid->grid = addstu_grid;



	Gc_master *master;
	

	master = (Gc_master *)malloc(sizeof(Gc_master));
	master->ent1=gtk_entry_new();
	master->ent2=gtk_entry_new();
	master->ent3=gtk_entry_new();
	master->ent4=gtk_entry_new();
	master->ent5=gtk_entry_new();
	
	labelhead = gtk_label_new(NULL);
	gtk_label_set_markup(GTK_LABEL(labelhead), "<b><big>       ADD STUDENT DETAILS</big></b>\n");
	labelnull = gtk_label_new(" ");
	label1 = gtk_label_new("MIS");
	label2 = gtk_label_new("NAME");
	label3 = gtk_label_new("ADDRESS");
	label4= gtk_label_new("BRANCH");
	label5 = gtk_label_new("BLOCKNO");


	btn1 = gtk_button_new_with_label("SUBMIT");
	btn2 = gtk_button_new_with_label("HOME");
	g_signal_connect(btn1, "clicked", G_CALLBACK(on_button_click), master);
	g_signal_connect(btn2, "clicked", G_CALLBACK(activate), win_grid);


	
	gtk_grid_attach(GTK_GRID(win_grid->grid), master->ent1, 2,2, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), master->ent2, 2,3, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), master->ent3, 2,4, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), master->ent4, 2,5, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), master->ent5, 2,6, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), labelhead, 1,0, 2 , 2);
	gtk_grid_attach(GTK_GRID(win_grid->grid), label1, 1,2, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), label2, 1,3, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), label3, 1,4, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), label4, 1,5, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), label5, 1,6, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), labelnull, 1,7, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), btn1, 3, 10, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), btn2, 0, 10, 1, 1);
	
	gtk_widget_show_all(win_grid->window);	
	return;
}



void activate(GtkApplication *app, Window_grid *win_grid){
	
	GtkWidget *window, *push_button,*btn1,*btn2,*btn3,*btn4,*btn5,*btn6,*grid,*ent1,*ent2,*ent3,*ent4,*ent5;
	GtkWidget *entry,*label1,*label2,*label3,*label4,*label5,*labelhead,*labelnull;
	

	Window_grid *main;
	
	main = (Window_grid *)malloc(sizeof(Window_grid));

	if(!win_grid){
		main->window = gtk_application_window_new(app);
		gtk_container_set_border_width(GTK_CONTAINER(main->window), 50);
		gtk_window_set_title(GTK_WINDOW(main->window), "Student Record Sys (HOSTEL)");
		g_signal_connect(main->window, "destroy", G_CALLBACK(on_window_closed), NULL);
		main->grid = gtk_grid_new();
		gtk_container_add(GTK_CONTAINER(main->window), main->grid);
	}
	else{
		gtk_container_remove(GTK_CONTAINER(win_grid->window), win_grid->grid);
		grid = gtk_grid_new();
		gtk_container_add(GTK_CONTAINER(win_grid->window), grid);
		main->grid = grid;
		main->window = win_grid->window;
	}
	
	labelhead = gtk_label_new(NULL);
	gtk_label_set_markup(GTK_LABEL(labelhead), "<b><big>       STUDENT RECORD SYSTEM-HOSTEL</big></b>\n");
	labelnull = gtk_label_new(" ");


	btn1 = gtk_button_new_with_label("Add Student Details");
	btn2 = gtk_button_new_with_label("Search student Details");
	btn3 = gtk_button_new_with_label("Edit student Details");
	btn4 = gtk_button_new_with_label("Delete student Details");
	btn5 = gtk_button_new_with_label("View student Details");
	btn6 = gtk_button_new_with_label("Close Application");
	g_signal_connect(btn1, "clicked", G_CALLBACK(addstudent_details), main);
	g_signal_connect(btn2, "clicked", G_CALLBACK(searchstudent_details), main);
	g_signal_connect(btn3, "clicked", G_CALLBACK(editstudent_details), main);
	g_signal_connect(btn4, "clicked", G_CALLBACK(deletestudent_details), main);
	g_signal_connect(btn5, "clicked", G_CALLBACK(viewstudent_details), main);
	g_signal_connect(btn6, "clicked", G_CALLBACK(close_window), main->window);


	
	
	gtk_grid_attach(GTK_GRID(main->grid), labelhead, 1,0, 1 , 2);
	gtk_grid_attach(GTK_GRID(main->grid), labelnull, 1,2, 1, 1);
	gtk_grid_attach(GTK_GRID(main->grid), labelnull, 0.5,1, 2, 1);
	gtk_grid_attach(GTK_GRID(main->grid), btn1, 1, 3, 1, 1);
	gtk_grid_attach(GTK_GRID(main->grid), btn2, 1, 4, 1, 1);
	gtk_grid_attach(GTK_GRID(main->grid), btn3, 1, 5, 1, 1);
	gtk_grid_attach(GTK_GRID(main->grid), btn4, 1, 6, 1, 1);
	gtk_grid_attach(GTK_GRID(main->grid), btn5, 1, 7, 1, 1);
	gtk_grid_attach(GTK_GRID(main->grid), btn6, 1, 8, 1, 1);
	
	gtk_widget_show_all(main->window);
	
}

	

