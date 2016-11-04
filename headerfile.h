/********************************************************************************
* Student Record System(Hostel)                                         *
*                                                                               *
* Copyright (C) 2016 Onkar Rajendra Patil                                   	*                                                      
* License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html> *
* This is free software: you are free to change and redistribute it.            *
* There is NO WARRANTY, to the extent permitted by law.                         *
*                                                                               *
*********************************************************************************/
#ifndef __DEMO__H
#define __DEMO__H

typedef struct record {			
	char mis[20];		// student mis
	char name[50];		// student name
	char address[500];	// Address of student
	char branch[50];	// Branch of student
        char blockno[20];	// Roomno of student	
	char mobileno[12];	//mobileno of student
	char emailid[50];	//mailid of student
	char date[20];		//date of joining hostel
	char leave[20];	//date of leaving hostel
}record;
record rec;


typedef struct Window_grid{
	GtkWidget *window;
	GtkWidget *grid;
}Window_grid;


typedef struct Gc_master{
	GtkWidget *ent1,*entry;
	GtkWidget *ent2;
	GtkWidget *ent3;
	GtkWidget *ent4;
	GtkWidget *ent5;
	GtkWidget *ent6;
	GtkWidget *ent7;
	GtkWidget *window;
}Gc_master;

typedef struct Gc_label{
	
	GtkWidget *label11,*label12,*label13,*label14,*label15,*label16,*label17,*label18,*newdate;
	GtkWidget *label21,*label22,*label23,*label24,*label25,*label26,*label27,*label28,*search;
	GtkWidget *label31,*label32,*label33,*label34,*label35,*label36,*label37,*label38;
	GtkWidget *label41,*label42,*label43,*label44,*label45,*label46,*label47,*label48;
	GtkWidget *label51,*label52,*label53,*label54,*label55,*label56,*label57,*label58;
	GtkWidget *label61,*label62,*label63,*label64,*label65,*label66,*label67,*label68;
	GtkWidget *label71,*label72,*label73,*label74,*label75,*label76,*label77,*label78;
	GtkWidget *label81,*label82,*label83,*label84,*label85,*label86,*label87,*label88;
	GtkWidget *label91,*label92,*label93,*label94,*label95,*label96,*label97,*label98;
	GtkWidget *label101,*label102,*label103,*label104,*label105,*label106,*label107,*label108;
	GtkWidget *label111,*label112,*label113,*label114,*label115,*label116,*label117,*label118;
	GtkWidget *label121,*label122,*label123,*label124,*label125,*label126,*label127,*label128;
	GtkWidget *label131,*label132,*label133,*label134,*label135,*label136,*label137,*label138;
	GtkWidget *label141,*label142,*label143,*label144,*label145,*label146,*label147,*label148;
	GtkWidget *label151,*label152,*label153,*label154,*label155,*label156,*label157,*label158;
	GtkWidget *label161,*label162,*label163,*label164,*label165,*label166,*label167,*label168;
	GtkWidget *label29,*label39,*label49,*label59,*label69,*label79,*label89,*label99,*label109,*label119,*label129,*label139,*label149;
	GtkWidget *label159, *label169;
	GtkWidget *ent1,*entry;
	GtkWidget *ent2;
	GtkWidget *ent3;
	GtkWidget *ent4;
	GtkWidget *ent5;
	GtkWidget *ent6;
	GtkWidget *ent7;
	GtkWidget *window;
}Gc_label;


GtkWidget *init_window(GtkApplication *);  				 //this is the prototype for initialize function
void activate (GtkApplication *app, Window_grid *win_grid);    		 // prototype for activate
void addstudent_details(GtkWidget *widget, Window_grid *win_grid);     	 //prototype for add student details
void search_student_details(GtkWidget *widget, Window_grid *win_grid); 	 //prototype for search student details
void editstudent_details(GtkWidget *widget, Window_grid *win_grid);	 //prototype for edit student details
void view_student(GtkWidget *widget, Window_grid *win_grid);		 //prototype for view student details
void view_student_left(GtkWidget *widget, Window_grid *win_grid);	 //prototype for view student details of those who had left hostel
void deletestudent_details(GtkWidget *widget, Window_grid *win_grid);	 //prototype for delete student details
void close_window(GtkWidget *widget, gpointer window); 			 //prototype for close window


#endif
