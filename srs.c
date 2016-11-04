/********************************************************************************
* Student Record System(Hostel)                                     *
*                                                                               *
* Copyright (C) 2016 Onkar Rajendra Patil                                       *                                                      
* License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html> *
* This is free software: you are free to change and redistribute it.            *
* There is NO WARRANTY, to the extent permitted by law.                         *
*                                                                               *
*********************************************************************************/
#include <gtk/gtk.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include "headerfile.h"
/*global declaration*/
int misno=0;
int j=0;
int i=0;
int p=0;
			/**********************************************************************global declaration of GtkWidget*/
GtkWidget *window, *push_button,*add,*delete,*edit,*search,*btn6,*labelnewdate;
GtkWidget *addstu_grid,*btn1,*btn2,*btn3,*btn4,*btn5,*btn11,*btn12,*btn13,*btn14,*grid,*ent1,*ent2,*ent3,*ent4,*ent5,*ent6,*ent7;
GtkWidget *btn15,*btn16,*btn17,*btn18,*btn19,*btn10,*btn111,*btn112,*btn113,*btn114,*btn115;
GtkWidget *entry,*labelhead,*labelnull,*btnnxt,*btnpre,*btnref;
GtkWidget *label1,*label2,*label3,*label4,*label5,*label6,*label7,*label8;
GtkWidget *label11,*label12,*label13,*label14,*label15,*label16,*label17,*label18, *label19;
GtkWidget *label21,*label22,*label23,*label24,*label25,*label26,*label27,*labe28;
GtkWidget *labeln21,*labeln22,*labeln23,*labeln24,*labeln25,*labeln26,*labeln27,*labeln28;
GtkWidget *label31,*label32,*label33,*label34,*label35,*label36,*label37,*label38;
GtkWidget *labeln31,*labeln32,*labeln33,*labeln34,*labeln35,*labeln36,*labeln37,*labeln38;
GtkWidget *label41,*label42,*label43,*label44,*label45,*label46,*label47,*label48;
GtkWidget *labeln41,*labeln42,*labeln43,*labeln44,*labeln45,*labeln46,*labeln47,*labeln48;
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

/***********************************************updation of edited student details***********/
void update_edited_record(GtkWidget *widget, Gc_label *user_data){
  	GtkResponseType result;
	GtkWidget *dialog;	
	char arr[5]="";
	if(atoi(gtk_entry_get_text(GTK_ENTRY(user_data->ent1)))==0 || strcmp(arr,gtk_entry_get_text(GTK_ENTRY(user_data->ent2)))==0 || strcmp(arr,gtk_entry_get_text(GTK_ENTRY(user_data->ent3)))==0 || strcmp(arr,gtk_entry_get_text(GTK_ENTRY(user_data->ent4)))==0 || strcmp(arr,gtk_entry_get_text(GTK_ENTRY(user_data->ent4)))==0 || strcmp(arr,gtk_entry_get_text(GTK_ENTRY(user_data->ent5)))==0 || strcmp(arr,gtk_entry_get_text(GTK_ENTRY(user_data->ent7)))==0 || atoi(gtk_entry_get_text(GTK_ENTRY(user_data->ent6)))==0){
		  			/*checks whether user enters valid details or not**/	
 	    	dialog = gtk_message_dialog_new(GTK_WINDOW(user_data->window),
            	GTK_DIALOG_DESTROY_WITH_PARENT,
            	GTK_MESSAGE_ERROR,
            	GTK_BUTTONS_OK,
            	"Enter Valid Details");
 		gtk_window_set_title(GTK_WINDOW(dialog), "Error");
		gtk_dialog_run(GTK_DIALOG(dialog));
		gtk_widget_destroy(dialog);
	}
	else{	
		int i = atoi(gtk_entry_get_text(GTK_ENTRY(user_data->ent1)));
		dialog = gtk_message_dialog_new(GTK_WINDOW(user_data->window),
  		          GTK_DIALOG_DESTROY_WITH_PARENT,
  	     		     GTK_MESSAGE_QUESTION,
 	        	   GTK_BUTTONS_YES_NO,
            			"confirm update...?");
  		gtk_window_set_title(GTK_WINDOW(dialog), "Question");
  		result=gtk_dialog_run(GTK_DIALOG(dialog));
		if(result == GTK_RESPONSE_YES){
		    gtk_widget_destroy(dialog);
		    FILE* fp=fopen("studata.txt","a+");
		    FILE* ft=fopen("tmp.txt", "a+");  
		    if(misno !=  i)
		    {				/*check whether user try to edit existing MIS*/
			dialog = gtk_message_dialog_new(GTK_WINDOW(user_data->window),
            		GTK_DIALOG_DESTROY_WITH_PARENT,
            		GTK_MESSAGE_ERROR,
            		GTK_BUTTONS_OK,
            		"You are not allowed to change MIS NO.");
 			gtk_window_set_title(GTK_WINDOW(dialog), "Error");
			gtk_dialog_run(GTK_DIALOG(dialog));
			gtk_widget_destroy(dialog);
							
		    }
		    while(1) {		
				fscanf(fp, "%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\n]\n", rec.mis,  rec.name, rec.address, rec.branch, rec.blockno, rec.mobileno, rec.emailid, rec.date);
		 	   if(atoi(rec.mis) == i )
				fprintf(ft, "%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n", gtk_entry_get_text(GTK_ENTRY(user_data->ent1)), gtk_entry_get_text(GTK_ENTRY(user_data->ent2)), gtk_entry_get_text(GTK_ENTRY(user_data->ent3)), gtk_entry_get_text(GTK_ENTRY(user_data->ent4)), gtk_entry_get_text(GTK_ENTRY(user_data->ent5)), gtk_entry_get_text(GTK_ENTRY(user_data->ent6)), gtk_entry_get_text(GTK_ENTRY(user_data->ent7)), rec.date);
			   if(atoi(rec.mis) != i )/*writing of edited data to file**/
				fprintf(ft, "%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n", rec.mis,  rec.name, rec.address, rec.branch, rec.blockno, rec.mobileno, rec.emailid, rec.date);
			   if(feof(fp))
			    	  break;			
			}
		   gtk_entry_set_text(GTK_ENTRY(user_data->ent1), "");
		   gtk_entry_set_text(GTK_ENTRY(user_data->entry), "");
		   gtk_entry_set_text(GTK_ENTRY(user_data->ent2), "");
	     	   gtk_entry_set_text(GTK_ENTRY(user_data->ent3), "");
		   gtk_entry_set_text(GTK_ENTRY(user_data->ent4), "");
		   gtk_entry_set_text(GTK_ENTRY(user_data->ent5), "");
		   gtk_entry_set_text(GTK_ENTRY(user_data->ent6), "");
		   gtk_entry_set_text(GTK_ENTRY(user_data->ent7), "");
	 	   fclose(ft);
		   fclose(fp);
		   remove("studata.txt");
		   rename("tmp.txt", "studata.txt");
		   p=0;
		   fp = fopen("studata.txt","r+");
		   while(1){
			fscanf(fp, "%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\n]\n", rec.mis,  rec.name, rec.address, rec.branch, rec.blockno, rec.mobileno, rec.emailid,rec.date);
			if(p == 0) {	
				gtk_label_set_text(GTK_LABEL(user_data->label21), rec.mis);
				gtk_label_set_text(GTK_LABEL(user_data->label22), rec.name);
				gtk_label_set_text(GTK_LABEL(user_data->label23), rec.address);
				gtk_label_set_text(GTK_LABEL(user_data->label24), rec.branch);
				gtk_label_set_text(GTK_LABEL(user_data->label25), rec.blockno);
				gtk_label_set_text(GTK_LABEL(user_data->label26), rec.mobileno);
				gtk_label_set_text(GTK_LABEL(user_data->label27), rec.emailid);
			}
			else if(p == 1) {	
				gtk_label_set_text(GTK_LABEL(user_data->label31), rec.mis);
				gtk_label_set_text(GTK_LABEL(user_data->label32), rec.name);
				gtk_label_set_text(GTK_LABEL(user_data->label33), rec.address);
				gtk_label_set_text(GTK_LABEL(user_data->label34), rec.branch);
				gtk_label_set_text(GTK_LABEL(user_data->label35), rec.blockno);
				gtk_label_set_text(GTK_LABEL(user_data->label36), rec.mobileno);
				gtk_label_set_text(GTK_LABEL(user_data->label37), rec.emailid);
			}
			else if(p == 2) {	
				gtk_label_set_text(GTK_LABEL(user_data->label41), rec.mis);
				gtk_label_set_text(GTK_LABEL(user_data->label42), rec.name);
				gtk_label_set_text(GTK_LABEL(user_data->label43), rec.address);
				gtk_label_set_text(GTK_LABEL(user_data->label44), rec.branch);
				gtk_label_set_text(GTK_LABEL(user_data->label45), rec.blockno);
				gtk_label_set_text(GTK_LABEL(user_data->label46), rec.mobileno);
				gtk_label_set_text(GTK_LABEL(user_data->label47), rec.emailid);
			}
			else if(p == 3) {	
				gtk_label_set_text(GTK_LABEL(user_data->label51), rec.mis);
				gtk_label_set_text(GTK_LABEL(user_data->label52), rec.name);
				gtk_label_set_text(GTK_LABEL(user_data->label53), rec.address);
				gtk_label_set_text(GTK_LABEL(user_data->label54), rec.branch);
				gtk_label_set_text(GTK_LABEL(user_data->label55), rec.blockno);
				gtk_label_set_text(GTK_LABEL(user_data->label56), rec.mobileno);
				gtk_label_set_text(GTK_LABEL(user_data->label57), rec.emailid);
			}
			else if(p == 4) {	
				gtk_label_set_text(GTK_LABEL(user_data->label61), rec.mis);
				gtk_label_set_text(GTK_LABEL(user_data->label62), rec.name);
				gtk_label_set_text(GTK_LABEL(user_data->label63), rec.address);
				gtk_label_set_text(GTK_LABEL(user_data->label64), rec.branch);
				gtk_label_set_text(GTK_LABEL(user_data->label65), rec.blockno);
				gtk_label_set_text(GTK_LABEL(user_data->label66), rec.mobileno);
				gtk_label_set_text(GTK_LABEL(user_data->label67), rec.emailid);
			}
			else if(p == 5) {	
				gtk_label_set_text(GTK_LABEL(user_data->label71), rec.mis);
				gtk_label_set_text(GTK_LABEL(user_data->label72), rec.name);
				gtk_label_set_text(GTK_LABEL(user_data->label73), rec.address);
				gtk_label_set_text(GTK_LABEL(user_data->label74), rec.branch);
				gtk_label_set_text(GTK_LABEL(user_data->label75), rec.blockno);
				gtk_label_set_text(GTK_LABEL(user_data->label76), rec.mobileno);
				gtk_label_set_text(GTK_LABEL(user_data->label77), rec.emailid);
			}
			else if(p == 6) {	
				gtk_label_set_text(GTK_LABEL(user_data->label81), rec.mis);
				gtk_label_set_text(GTK_LABEL(user_data->label82), rec.name);
				gtk_label_set_text(GTK_LABEL(user_data->label83), rec.address);
				gtk_label_set_text(GTK_LABEL(user_data->label84), rec.branch);
				gtk_label_set_text(GTK_LABEL(user_data->label85), rec.blockno);
				gtk_label_set_text(GTK_LABEL(user_data->label86), rec.mobileno);
				gtk_label_set_text(GTK_LABEL(user_data->label87), rec.emailid);
			}
			else if(p == 7) {	
				gtk_label_set_text(GTK_LABEL(user_data->label91), rec.mis);
				gtk_label_set_text(GTK_LABEL(user_data->label92), rec.name);
				gtk_label_set_text(GTK_LABEL(user_data->label93), rec.address);
				gtk_label_set_text(GTK_LABEL(user_data->label94), rec.branch);
				gtk_label_set_text(GTK_LABEL(user_data->label95), rec.blockno);
				gtk_label_set_text(GTK_LABEL(user_data->label96), rec.mobileno);
				gtk_label_set_text(GTK_LABEL(user_data->label97), rec.emailid);
			}
			else if(p == 8) {	
				gtk_label_set_text(GTK_LABEL(user_data->label101), rec.mis);
				gtk_label_set_text(GTK_LABEL(user_data->label102), rec.name);
				gtk_label_set_text(GTK_LABEL(user_data->label103), rec.address);
				gtk_label_set_text(GTK_LABEL(user_data->label104), rec.branch);
				gtk_label_set_text(GTK_LABEL(user_data->label105), rec.blockno);
				gtk_label_set_text(GTK_LABEL(user_data->label106), rec.mobileno);
				gtk_label_set_text(GTK_LABEL(user_data->label107), rec.emailid);
			}
			else if(p == 9) {	
				gtk_label_set_text(GTK_LABEL(user_data->label111), rec.mis);
				gtk_label_set_text(GTK_LABEL(user_data->label112), rec.name);
				gtk_label_set_text(GTK_LABEL(user_data->label113), rec.address);
				gtk_label_set_text(GTK_LABEL(user_data->label114), rec.branch);
				gtk_label_set_text(GTK_LABEL(user_data->label115), rec.blockno);
				gtk_label_set_text(GTK_LABEL(user_data->label116), rec.mobileno);
				gtk_label_set_text(GTK_LABEL(user_data->label117), rec.emailid);
			}
			else if(p == 10) {	
				gtk_label_set_text(GTK_LABEL(user_data->label121), rec.mis);
				gtk_label_set_text(GTK_LABEL(user_data->label122), rec.name);
				gtk_label_set_text(GTK_LABEL(user_data->label123), rec.address);
				gtk_label_set_text(GTK_LABEL(user_data->label124), rec.branch);
				gtk_label_set_text(GTK_LABEL(user_data->label125), rec.blockno);
				gtk_label_set_text(GTK_LABEL(user_data->label126), rec.mobileno);
				gtk_label_set_text(GTK_LABEL(user_data->label127), rec.emailid);
			}
			else if(p == 11) {	
				gtk_label_set_text(GTK_LABEL(user_data->label131), rec.mis);
				gtk_label_set_text(GTK_LABEL(user_data->label132), rec.name);
				gtk_label_set_text(GTK_LABEL(user_data->label133), rec.address);
				gtk_label_set_text(GTK_LABEL(user_data->label134), rec.branch);
				gtk_label_set_text(GTK_LABEL(user_data->label135), rec.blockno);
				gtk_label_set_text(GTK_LABEL(user_data->label136), rec.mobileno);
				gtk_label_set_text(GTK_LABEL(user_data->label137), rec.emailid);
			}
			else if(p == 12) {	
				gtk_label_set_text(GTK_LABEL(user_data->label141), rec.mis);
				gtk_label_set_text(GTK_LABEL(user_data->label142), rec.name);
				gtk_label_set_text(GTK_LABEL(user_data->label143), rec.address);
				gtk_label_set_text(GTK_LABEL(user_data->label144), rec.branch);
				gtk_label_set_text(GTK_LABEL(user_data->label145), rec.blockno);
				gtk_label_set_text(GTK_LABEL(user_data->label146), rec.mobileno);
				gtk_label_set_text(GTK_LABEL(user_data->label147), rec.emailid);
			}
			else if(p == 13) {	
				gtk_label_set_text(GTK_LABEL(user_data->label151), rec.mis);
				gtk_label_set_text(GTK_LABEL(user_data->label152), rec.name);
				gtk_label_set_text(GTK_LABEL(user_data->label153), rec.address);
				gtk_label_set_text(GTK_LABEL(user_data->label154), rec.branch);
				gtk_label_set_text(GTK_LABEL(user_data->label155), rec.blockno);
				gtk_label_set_text(GTK_LABEL(user_data->label156), rec.mobileno);
				gtk_label_set_text(GTK_LABEL(user_data->label157), rec.emailid);
			}
			else if(p == 14) {	
				gtk_label_set_text(GTK_LABEL(user_data->label161), rec.mis);
				gtk_label_set_text(GTK_LABEL(user_data->label162), rec.name);
				gtk_label_set_text(GTK_LABEL(user_data->label163), rec.address);
				gtk_label_set_text(GTK_LABEL(user_data->label164), rec.branch);
				gtk_label_set_text(GTK_LABEL(user_data->label165), rec.blockno);
				gtk_label_set_text(GTK_LABEL(user_data->label166), rec.mobileno);
				gtk_label_set_text(GTK_LABEL(user_data->label167), rec.emailid);
				p=0;
				break;
			}
			if(feof(fp)){
					break;	
			}
			p++;
		}
		fclose(fp);
	    }
	    else{
	        gtk_widget_destroy(dialog);
		gtk_entry_set_text(GTK_ENTRY(user_data->ent1), "");
		gtk_entry_set_text(GTK_ENTRY(user_data->entry), "");
		gtk_entry_set_text(GTK_ENTRY(user_data->ent2), "");
	        gtk_entry_set_text(GTK_ENTRY(user_data->ent3), "");
		gtk_entry_set_text(GTK_ENTRY(user_data->ent4), "");
		gtk_entry_set_text(GTK_ENTRY(user_data->ent5), "");
		gtk_entry_set_text(GTK_ENTRY(user_data->ent6), "");
		gtk_entry_set_text(GTK_ENTRY(user_data->ent7), "");
	}
      }
}



/**********************************************************************************delete student details from file*******/
void delete_student(GtkWidget *widget, Gc_label *user_data){
	GtkResponseType result;
	GtkWidget *dialog;	
	if(atoi(gtk_label_get_text(GTK_LABEL(user_data->ent1)))==0){ /**check whether student is selected for delete or not**/
		
 	    	dialog = gtk_message_dialog_new(GTK_WINDOW(user_data->window),
            	GTK_DIALOG_DESTROY_WITH_PARENT,
            	GTK_MESSAGE_ERROR,
            	GTK_BUTTONS_OK,
            	"Select STudent To be Deleted");
  		gtk_window_set_title(GTK_WINDOW(dialog), "Error");
  		gtk_dialog_run(GTK_DIALOG(dialog));
  		gtk_widget_destroy(dialog);
	}
	else{							/**check whether user had enter leaving date of student or not***/
		if(atoi(gtk_entry_get_text(GTK_ENTRY(user_data->newdate)))==0){		
 	    		dialog = gtk_message_dialog_new(GTK_WINDOW(user_data->window),
            		GTK_DIALOG_DESTROY_WITH_PARENT,
            		GTK_MESSAGE_ERROR,
            		GTK_BUTTONS_OK,
            		"Enter Date of leave...!!");
  			gtk_window_set_title(GTK_WINDOW(dialog), "Error");
  			gtk_dialog_run(GTK_DIALOG(dialog));
  			gtk_widget_destroy(dialog);}else{	
  			dialog = gtk_message_dialog_new(GTK_WINDOW(user_data->window),
  		          GTK_DIALOG_DESTROY_WITH_PARENT,
  	     		     GTK_MESSAGE_QUESTION,
 	        	   GTK_BUTTONS_YES_NO,
            			"Confirm delete...?");
  			gtk_window_set_title(GTK_WINDOW(dialog), "Question");
  			result=gtk_dialog_run(GTK_DIALOG(dialog));
			if(result == GTK_RESPONSE_YES){
  				int i = atoi(gtk_label_get_text(GTK_LABEL(user_data->ent1)));
				FILE* ft = fopen("tmp.txt","a+");
				FILE* fp = fopen("studata.txt","a+");	
				FILE* fd = fopen("studleave.txt","a+");		
				while(1) {
					fscanf(fp, "%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\n]\n", rec.mis,  rec.name, rec.address, rec.branch, rec.blockno, rec.mobileno, rec.emailid,rec.date);
					if(atoi(rec.mis) != i) /*data which is to be deleted is not written in new file**/
						fprintf(ft, "%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n", rec.mis,  rec.name, rec.address, rec.branch, rec.blockno, rec.mobileno, rec.emailid,rec.date);
					if(atoi(rec.mis) == i) /*data which is to be deleted is written in another file named studleave.txt**/
						fprintf(fd, "%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n", rec.mis,  rec.name, rec.address, rec.branch, rec.blockno, rec.mobileno, rec.emailid,rec.date,gtk_entry_get_text(GTK_ENTRY(user_data->newdate)));
					if(feof(fp))
						break;	
				}
			gtk_label_set_text(GTK_LABEL(user_data->ent1), "");
			gtk_label_set_text(GTK_LABEL(user_data->ent2), "");
			gtk_label_set_text(GTK_LABEL(user_data->ent3), "");
			gtk_label_set_text(GTK_LABEL(user_data->ent4), "");
			gtk_label_set_text(GTK_LABEL(user_data->ent5), "");
			gtk_label_set_text(GTK_LABEL(user_data->ent6), "");
			gtk_label_set_text(GTK_LABEL(user_data->ent7), "");
			gtk_entry_set_text(GTK_ENTRY(user_data->entry), "");
			gtk_entry_set_text(GTK_ENTRY(user_data->newdate), "");
			fclose(ft);
			fclose(fp);
			fclose(fd);
			remove("studata.txt");		/***removal of old file**/
			rename("tmp.txt", "studata.txt");	/**rename new file same as of old file**/
			gtk_widget_destroy(dialog);
			p = 0;
			FILE* fm = fopen("studata.txt","r+");
			while(1){
				fscanf(fm, "%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\n]\n", rec.mis,  rec.name, rec.address, rec.branch, rec.blockno, rec.mobileno, rec.emailid, rec.date);    /*displaying file content after deletion**/
				if(p == 0) {	
					gtk_label_set_text(GTK_LABEL(user_data->label21), rec.mis);
					gtk_label_set_text(GTK_LABEL(user_data->label22), rec.name);
					gtk_label_set_text(GTK_LABEL(user_data->label23), rec.address);
					gtk_label_set_text(GTK_LABEL(user_data->label24), rec.branch);
					gtk_label_set_text(GTK_LABEL(user_data->label25), rec.blockno);
					gtk_label_set_text(GTK_LABEL(user_data->label26), rec.mobileno);
					gtk_label_set_text(GTK_LABEL(user_data->label27), rec.emailid);
				}
				else if(p == 1) {	
					gtk_label_set_text(GTK_LABEL(user_data->label31), rec.mis);
					gtk_label_set_text(GTK_LABEL(user_data->label32), rec.name);
					gtk_label_set_text(GTK_LABEL(user_data->label33), rec.address);
					gtk_label_set_text(GTK_LABEL(user_data->label34), rec.branch);
					gtk_label_set_text(GTK_LABEL(user_data->label35), rec.blockno);
					gtk_label_set_text(GTK_LABEL(user_data->label36), rec.mobileno);
					gtk_label_set_text(GTK_LABEL(user_data->label37), rec.emailid);
				}
				else if(p == 2) {	
					gtk_label_set_text(GTK_LABEL(user_data->label41), rec.mis);
					gtk_label_set_text(GTK_LABEL(user_data->label42), rec.name);
					gtk_label_set_text(GTK_LABEL(user_data->label43), rec.address);
					gtk_label_set_text(GTK_LABEL(user_data->label44), rec.branch);
					gtk_label_set_text(GTK_LABEL(user_data->label45), rec.blockno);
					gtk_label_set_text(GTK_LABEL(user_data->label46), rec.mobileno);
					gtk_label_set_text(GTK_LABEL(user_data->label47), rec.emailid);
				}
				else if(p == 3) {	
					gtk_label_set_text(GTK_LABEL(user_data->label51), rec.mis);
					gtk_label_set_text(GTK_LABEL(user_data->label52), rec.name);
					gtk_label_set_text(GTK_LABEL(user_data->label53), rec.address);
					gtk_label_set_text(GTK_LABEL(user_data->label54), rec.branch);
					gtk_label_set_text(GTK_LABEL(user_data->label55), rec.blockno);
					gtk_label_set_text(GTK_LABEL(user_data->label56), rec.mobileno);
					gtk_label_set_text(GTK_LABEL(user_data->label57), rec.emailid);
				}
				else if(p == 4) {	
					gtk_label_set_text(GTK_LABEL(user_data->label61), rec.mis);
					gtk_label_set_text(GTK_LABEL(user_data->label62), rec.name);
					gtk_label_set_text(GTK_LABEL(user_data->label63), rec.address);
					gtk_label_set_text(GTK_LABEL(user_data->label64), rec.branch);
					gtk_label_set_text(GTK_LABEL(user_data->label65), rec.blockno);
					gtk_label_set_text(GTK_LABEL(user_data->label66), rec.mobileno);
					gtk_label_set_text(GTK_LABEL(user_data->label67), rec.emailid);
				}
				else if(p == 5) {	
					gtk_label_set_text(GTK_LABEL(user_data->label71), rec.mis);
					gtk_label_set_text(GTK_LABEL(user_data->label72), rec.name);
					gtk_label_set_text(GTK_LABEL(user_data->label73), rec.address);
					gtk_label_set_text(GTK_LABEL(user_data->label74), rec.branch);
					gtk_label_set_text(GTK_LABEL(user_data->label75), rec.blockno);
					gtk_label_set_text(GTK_LABEL(user_data->label76), rec.mobileno);
					gtk_label_set_text(GTK_LABEL(user_data->label77), rec.emailid);
				}
				else if(p == 6) {	
					gtk_label_set_text(GTK_LABEL(user_data->label81), rec.mis);
					gtk_label_set_text(GTK_LABEL(user_data->label82), rec.name);
					gtk_label_set_text(GTK_LABEL(user_data->label83), rec.address);
					gtk_label_set_text(GTK_LABEL(user_data->label84), rec.branch);
					gtk_label_set_text(GTK_LABEL(user_data->label85), rec.blockno);
					gtk_label_set_text(GTK_LABEL(user_data->label86), rec.mobileno);
					gtk_label_set_text(GTK_LABEL(user_data->label87), rec.emailid);
				}
				else if(p == 7) {	
					gtk_label_set_text(GTK_LABEL(user_data->label91), rec.mis);
					gtk_label_set_text(GTK_LABEL(user_data->label92), rec.name);
					gtk_label_set_text(GTK_LABEL(user_data->label93), rec.address);
					gtk_label_set_text(GTK_LABEL(user_data->label94), rec.branch);
					gtk_label_set_text(GTK_LABEL(user_data->label95), rec.blockno);
					gtk_label_set_text(GTK_LABEL(user_data->label96), rec.mobileno);
					gtk_label_set_text(GTK_LABEL(user_data->label97), rec.emailid);
				}
				else if(p == 8) {	
					gtk_label_set_text(GTK_LABEL(user_data->label101), rec.mis);
					gtk_label_set_text(GTK_LABEL(user_data->label102), rec.name);
					gtk_label_set_text(GTK_LABEL(user_data->label103), rec.address);
					gtk_label_set_text(GTK_LABEL(user_data->label104), rec.branch);
					gtk_label_set_text(GTK_LABEL(user_data->label105), rec.blockno);
					gtk_label_set_text(GTK_LABEL(user_data->label106), rec.mobileno);
					gtk_label_set_text(GTK_LABEL(user_data->label107), rec.emailid);
				}
				else if(p == 9) {	
					gtk_label_set_text(GTK_LABEL(user_data->label111), rec.mis);
					gtk_label_set_text(GTK_LABEL(user_data->label112), rec.name);
					gtk_label_set_text(GTK_LABEL(user_data->label113), rec.address);
					gtk_label_set_text(GTK_LABEL(user_data->label114), rec.branch);
					gtk_label_set_text(GTK_LABEL(user_data->label115), rec.blockno);
					gtk_label_set_text(GTK_LABEL(user_data->label116), rec.mobileno);
					gtk_label_set_text(GTK_LABEL(user_data->label117), rec.emailid);
				}
				else if(p == 10) {	
					gtk_label_set_text(GTK_LABEL(user_data->label121), rec.mis);
					gtk_label_set_text(GTK_LABEL(user_data->label122), rec.name);
					gtk_label_set_text(GTK_LABEL(user_data->label123), rec.address);
					gtk_label_set_text(GTK_LABEL(user_data->label124), rec.branch);
					gtk_label_set_text(GTK_LABEL(user_data->label125), rec.blockno);
					gtk_label_set_text(GTK_LABEL(user_data->label126), rec.mobileno);
					gtk_label_set_text(GTK_LABEL(user_data->label127), rec.emailid);
				}
				else if(p == 11) {	
					gtk_label_set_text(GTK_LABEL(user_data->label131), rec.mis);
					gtk_label_set_text(GTK_LABEL(user_data->label132), rec.name);
					gtk_label_set_text(GTK_LABEL(user_data->label133), rec.address);
					gtk_label_set_text(GTK_LABEL(user_data->label134), rec.branch);
					gtk_label_set_text(GTK_LABEL(user_data->label135), rec.blockno);
					gtk_label_set_text(GTK_LABEL(user_data->label136), rec.mobileno);
					gtk_label_set_text(GTK_LABEL(user_data->label137), rec.emailid);
				}
				else if(p == 12) {	
					gtk_label_set_text(GTK_LABEL(user_data->label141), rec.mis);
					gtk_label_set_text(GTK_LABEL(user_data->label142), rec.name);
					gtk_label_set_text(GTK_LABEL(user_data->label143), rec.address);
					gtk_label_set_text(GTK_LABEL(user_data->label144), rec.branch);
					gtk_label_set_text(GTK_LABEL(user_data->label145), rec.blockno);
					gtk_label_set_text(GTK_LABEL(user_data->label146), rec.mobileno);
					gtk_label_set_text(GTK_LABEL(user_data->label147), rec.emailid);
				}
				else if(p == 13) {	
					gtk_label_set_text(GTK_LABEL(user_data->label151), rec.mis);
					gtk_label_set_text(GTK_LABEL(user_data->label152), rec.name);
					gtk_label_set_text(GTK_LABEL(user_data->label153), rec.address);
					gtk_label_set_text(GTK_LABEL(user_data->label154), rec.branch);
					gtk_label_set_text(GTK_LABEL(user_data->label155), rec.blockno);
					gtk_label_set_text(GTK_LABEL(user_data->label156), rec.mobileno);
					gtk_label_set_text(GTK_LABEL(user_data->label157), rec.emailid);
				}
				else if(p == 14) {	
					gtk_label_set_text(GTK_LABEL(user_data->label161), rec.mis);
					gtk_label_set_text(GTK_LABEL(user_data->label162), rec.name);
					gtk_label_set_text(GTK_LABEL(user_data->label163), rec.address);
					gtk_label_set_text(GTK_LABEL(user_data->label164), rec.branch);
					gtk_label_set_text(GTK_LABEL(user_data->label165), rec.blockno);
					gtk_label_set_text(GTK_LABEL(user_data->label166), rec.mobileno);
					gtk_label_set_text(GTK_LABEL(user_data->label167), rec.emailid);
					p=0;
					break;
				}
				if(feof(fm)){
					break;	
				}
				p++;
			    }
		            fclose(fm);
			}
			else{
				gtk_widget_destroy(dialog);
				gtk_label_set_text(GTK_LABEL(user_data->ent1), "");
				gtk_entry_set_text(GTK_ENTRY(user_data->entry), "");
				gtk_label_set_text(GTK_LABEL(user_data->ent2), "");
				gtk_label_set_text(GTK_LABEL(user_data->ent3), "");
				gtk_label_set_text(GTK_LABEL(user_data->ent4), "");
				gtk_label_set_text(GTK_LABEL(user_data->ent5), "");
				gtk_label_set_text(GTK_LABEL(user_data->ent6), "");
				gtk_label_set_text(GTK_LABEL(user_data->ent7), "");
				gtk_entry_set_text(GTK_ENTRY(user_data->newdate), "");
			}
  		}	
	}
}



/****************************following code set all textfields and labels to null********/

void cleartext12(GtkWidget *widget, Gc_label *user_data){
	gtk_label_set_text(GTK_LABEL(user_data->ent1), "");
	gtk_entry_set_text(GTK_ENTRY(user_data->entry), "");
	gtk_label_set_text(GTK_LABEL(user_data->ent2), "");
	gtk_label_set_text(GTK_LABEL(user_data->ent3), "");
	gtk_label_set_text(GTK_LABEL(user_data->ent4), "");
	gtk_label_set_text(GTK_LABEL(user_data->ent5), "");
	gtk_label_set_text(GTK_LABEL(user_data->ent6), "");
	gtk_label_set_text(GTK_LABEL(user_data->ent7), "");
	gtk_entry_set_text(GTK_ENTRY(user_data->newdate), "");
}
void cleartext(GtkWidget *widget, Gc_label *user_data){
	gtk_entry_set_text(GTK_ENTRY(user_data->entry), "");
	gtk_entry_set_text(GTK_ENTRY(user_data->ent1), "");
	gtk_entry_set_text(GTK_ENTRY(user_data->ent2), "");
	gtk_entry_set_text(GTK_ENTRY(user_data->ent3), "");
	gtk_entry_set_text(GTK_ENTRY(user_data->ent4), "");
	gtk_entry_set_text(GTK_ENTRY(user_data->ent5), "");
	gtk_entry_set_text(GTK_ENTRY(user_data->ent6), "");
	gtk_entry_set_text(GTK_ENTRY(user_data->ent7), "");
}


void clearlabel1(GtkWidget *widget, Gc_label *user_data){
	gtk_entry_set_text(GTK_ENTRY(user_data->search), "");
	gtk_label_set_text(GTK_LABEL(user_data->label21), "");
	gtk_label_set_text(GTK_LABEL(user_data->label22), "");
	gtk_label_set_text(GTK_LABEL(user_data->label23), "");
	gtk_label_set_text(GTK_LABEL(user_data->label24), "");
	gtk_label_set_text(GTK_LABEL(user_data->label25), "");
	gtk_label_set_text(GTK_LABEL(user_data->label26), "");
	gtk_label_set_text(GTK_LABEL(user_data->label27), "");
}

void clearlabel(GtkWidget *widget, Gc_label *user_data){
	gtk_entry_set_text(GTK_ENTRY(user_data->search), "");
	gtk_label_set_text(GTK_LABEL(user_data->label41), "");
	gtk_label_set_text(GTK_LABEL(user_data->label42), "");
	gtk_label_set_text(GTK_LABEL(user_data->label43), "");
	gtk_label_set_text(GTK_LABEL(user_data->label44), "");
	gtk_label_set_text(GTK_LABEL(user_data->label45), "");
	gtk_label_set_text(GTK_LABEL(user_data->label46), "");
	gtk_label_set_text(GTK_LABEL(user_data->label47), "");
	gtk_label_set_text(GTK_LABEL(user_data->label51), "");
	gtk_label_set_text(GTK_LABEL(user_data->label52), "");
	gtk_label_set_text(GTK_LABEL(user_data->label53), "");
	gtk_label_set_text(GTK_LABEL(user_data->label54), "");
	gtk_label_set_text(GTK_LABEL(user_data->label55), "");
	gtk_label_set_text(GTK_LABEL(user_data->label56), "");
	gtk_label_set_text(GTK_LABEL(user_data->label57), "");
	gtk_label_set_text(GTK_LABEL(user_data->label61), "");
	gtk_label_set_text(GTK_LABEL(user_data->label62), "");
	gtk_label_set_text(GTK_LABEL(user_data->label63), "");
	gtk_label_set_text(GTK_LABEL(user_data->label64), "");
	gtk_label_set_text(GTK_LABEL(user_data->label65), "");
	gtk_label_set_text(GTK_LABEL(user_data->label66), "");
	gtk_label_set_text(GTK_LABEL(user_data->label67), "");
	gtk_label_set_text(GTK_LABEL(user_data->label71), "");
	gtk_label_set_text(GTK_LABEL(user_data->label72), "");
	gtk_label_set_text(GTK_LABEL(user_data->label73), "");
	gtk_label_set_text(GTK_LABEL(user_data->label74), "");
	gtk_label_set_text(GTK_LABEL(user_data->label75), "");
	gtk_label_set_text(GTK_LABEL(user_data->label76), "");
	gtk_label_set_text(GTK_LABEL(user_data->label77), "");
	gtk_label_set_text(GTK_LABEL(user_data->label81), "");
	gtk_label_set_text(GTK_LABEL(user_data->label82), "");
	gtk_label_set_text(GTK_LABEL(user_data->label83), "");
	gtk_label_set_text(GTK_LABEL(user_data->label84), "");
	gtk_label_set_text(GTK_LABEL(user_data->label85), "");
	gtk_label_set_text(GTK_LABEL(user_data->label86), "");
	gtk_label_set_text(GTK_LABEL(user_data->label87), "");
}

/******************************************************adds user input(student details) to file****************/
void on_button_click(GtkWidget *widget, Gc_label *structlabel){
	GtkResponseType result;
	GtkWidget *dialog;
	int e = 1;	
	char arr[5] = "";
	FILE* fk = fopen("studata.txt","a+");
	while(1){
		fscanf(fk, "%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\n]\n", rec.mis,  rec.name, rec.address, rec.branch, rec.blockno, rec.mobileno, rec.emailid, rec.date);
		if(atoi(gtk_entry_get_text(GTK_ENTRY(structlabel->ent1))) == atoi(rec.mis)){ /*checks whether the MIS exits or not*/
			dialog = gtk_message_dialog_new(GTK_WINDOW(structlabel->window),
            		GTK_DIALOG_DESTROY_WITH_PARENT,
            		GTK_MESSAGE_ERROR,
            		GTK_BUTTONS_OK,
            		"MIS Exits..!!");
 			gtk_window_set_title(GTK_WINDOW(dialog), "Error");
			gtk_dialog_run(GTK_DIALOG(dialog));
			gtk_widget_destroy(dialog);
			gtk_entry_set_text(GTK_ENTRY(structlabel->ent1), "");
		}
		if(feof(fk))
			break;
	}
	fclose(fk);
	if(atoi(gtk_entry_get_text(GTK_ENTRY(structlabel->ent1)))==0 || strcmp(arr,gtk_entry_get_text(GTK_ENTRY(structlabel->ent2))) == 0 || strcmp(arr,gtk_entry_get_text(GTK_ENTRY(structlabel->ent3))) == 0 || strcmp(arr,gtk_entry_get_text(GTK_ENTRY(structlabel->ent4))) == 0 || strcmp(arr,gtk_entry_get_text(GTK_ENTRY(structlabel->ent4))) == 0 || strcmp(arr,gtk_entry_get_text(GTK_ENTRY(structlabel->ent5))) == 0 || strcmp(arr,gtk_entry_get_text(GTK_ENTRY(structlabel->ent7))) == 0 || atoi(gtk_entry_get_text(GTK_ENTRY(structlabel->ent6))) == 0 || atoi(gtk_entry_get_text(GTK_ENTRY(structlabel->entry))) == 0){
									/***check whether all fields are filled by end user*/
 	    	dialog = gtk_message_dialog_new(GTK_WINDOW(structlabel->window),
            	GTK_DIALOG_DESTROY_WITH_PARENT,
            	GTK_MESSAGE_INFO,
            	GTK_BUTTONS_OK,
            	"Enter valid details..!!""All fields are manadatory to be filled..!!");
 		gtk_window_set_title(GTK_WINDOW(dialog), "Information");
		gtk_dialog_run(GTK_DIALOG(dialog));
		gtk_widget_destroy(dialog);
		gtk_entry_set_text(GTK_ENTRY(structlabel->ent1), "");
		gtk_entry_set_text(GTK_ENTRY(structlabel->ent2), "");
		gtk_entry_set_text(GTK_ENTRY(structlabel->ent3), "");
		gtk_entry_set_text(GTK_ENTRY(structlabel->ent4), "");
		gtk_entry_set_text(GTK_ENTRY(structlabel->ent5), "");
		gtk_entry_set_text(GTK_ENTRY(structlabel->ent6), "");
		gtk_entry_set_text(GTK_ENTRY(structlabel->ent7), "");
		gtk_entry_set_text(GTK_ENTRY(structlabel->entry), "");
	}
	else{	
		FILE *fp = fopen("studata.txt","a+");				 /**adding new data to file***/
		fprintf(fp, "%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n", gtk_entry_get_text(GTK_ENTRY(structlabel->ent1)), gtk_entry_get_text(GTK_ENTRY(structlabel->ent2)), gtk_entry_get_text(GTK_ENTRY(structlabel->ent3)), gtk_entry_get_text(GTK_ENTRY(structlabel->ent4)), gtk_entry_get_text(GTK_ENTRY(structlabel->ent5)), gtk_entry_get_text(GTK_ENTRY(structlabel->ent6)), gtk_entry_get_text(GTK_ENTRY(structlabel->ent7)), gtk_entry_get_text(GTK_ENTRY(structlabel->entry)));
		g_print("Student Details Register Succesfully...!!");
		gtk_entry_set_text(GTK_ENTRY(structlabel->ent1), "");
		gtk_entry_set_text(GTK_ENTRY(structlabel->ent2), "");
		gtk_entry_set_text(GTK_ENTRY(structlabel->ent3), "");
		gtk_entry_set_text(GTK_ENTRY(structlabel->ent4), "");
		gtk_entry_set_text(GTK_ENTRY(structlabel->ent5), "");
		gtk_entry_set_text(GTK_ENTRY(structlabel->ent6), "");
		gtk_entry_set_text(GTK_ENTRY(structlabel->ent7), "");
		gtk_entry_set_text(GTK_ENTRY(structlabel->entry), "");
		fclose(fp);
	}

	p = 0;
	FILE *fp = fopen("studata.txt","r+");
	while(1){
		fscanf(fp, "%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\n]\n", rec.mis,  rec.name, rec.address, rec.branch, rec.blockno, rec.mobileno, rec.emailid, rec.date);		/*displaying file content with newly added data***/
		if(p == 0) {	
			gtk_label_set_text(GTK_LABEL(structlabel->label21), rec.mis);
			gtk_label_set_text(GTK_LABEL(structlabel->label22), rec.name);
			gtk_label_set_text(GTK_LABEL(structlabel->label23), rec.address);
			gtk_label_set_text(GTK_LABEL(structlabel->label24), rec.branch);
			gtk_label_set_text(GTK_LABEL(structlabel->label25), rec.blockno);
			gtk_label_set_text(GTK_LABEL(structlabel->label26), rec.mobileno);
			gtk_label_set_text(GTK_LABEL(structlabel->label27), rec.emailid);
			gtk_label_set_text(GTK_LABEL(structlabel->label28), rec.date);
		}
		else if(p == 1) {	
			gtk_label_set_text(GTK_LABEL(structlabel->label31), rec.mis);
			gtk_label_set_text(GTK_LABEL(structlabel->label32), rec.name);
			gtk_label_set_text(GTK_LABEL(structlabel->label33), rec.address);
			gtk_label_set_text(GTK_LABEL(structlabel->label34), rec.branch);
			gtk_label_set_text(GTK_LABEL(structlabel->label35), rec.blockno);
			gtk_label_set_text(GTK_LABEL(structlabel->label36), rec.mobileno);
			gtk_label_set_text(GTK_LABEL(structlabel->label37), rec.emailid);
			gtk_label_set_text(GTK_LABEL(structlabel->label38), rec.date);
		}
		else if(p == 2) {	
			gtk_label_set_text(GTK_LABEL(structlabel->label41), rec.mis);
			gtk_label_set_text(GTK_LABEL(structlabel->label42), rec.name);
			gtk_label_set_text(GTK_LABEL(structlabel->label43), rec.address);
			gtk_label_set_text(GTK_LABEL(structlabel->label44), rec.branch);
			gtk_label_set_text(GTK_LABEL(structlabel->label45), rec.blockno);
			gtk_label_set_text(GTK_LABEL(structlabel->label46), rec.mobileno);
			gtk_label_set_text(GTK_LABEL(structlabel->label47), rec.emailid);
			gtk_label_set_text(GTK_LABEL(structlabel->label48), rec.date);
		}
		else if(p == 3) {	
			gtk_label_set_text(GTK_LABEL(structlabel->label51), rec.mis);
			gtk_label_set_text(GTK_LABEL(structlabel->label52), rec.name);
			gtk_label_set_text(GTK_LABEL(structlabel->label53), rec.address);
			gtk_label_set_text(GTK_LABEL(structlabel->label54), rec.branch);
			gtk_label_set_text(GTK_LABEL(structlabel->label55), rec.blockno);
			gtk_label_set_text(GTK_LABEL(structlabel->label56), rec.mobileno);
			gtk_label_set_text(GTK_LABEL(structlabel->label57), rec.emailid);
			gtk_label_set_text(GTK_LABEL(structlabel->label58), rec.date);
		}
		else if(p == 4) {	
			gtk_label_set_text(GTK_LABEL(structlabel->label61), rec.mis);
			gtk_label_set_text(GTK_LABEL(structlabel->label62), rec.name);
			gtk_label_set_text(GTK_LABEL(structlabel->label63), rec.address);
			gtk_label_set_text(GTK_LABEL(structlabel->label64), rec.branch);
			gtk_label_set_text(GTK_LABEL(structlabel->label65), rec.blockno);
			gtk_label_set_text(GTK_LABEL(structlabel->label66), rec.mobileno);
			gtk_label_set_text(GTK_LABEL(structlabel->label67), rec.emailid);
			gtk_label_set_text(GTK_LABEL(structlabel->label68), rec.date);
		}
		else if(p == 5) {	
			gtk_label_set_text(GTK_LABEL(structlabel->label71), rec.mis);
			gtk_label_set_text(GTK_LABEL(structlabel->label72), rec.name);
			gtk_label_set_text(GTK_LABEL(structlabel->label73), rec.address);
			gtk_label_set_text(GTK_LABEL(structlabel->label74), rec.branch);
			gtk_label_set_text(GTK_LABEL(structlabel->label75), rec.blockno);
			gtk_label_set_text(GTK_LABEL(structlabel->label76), rec.mobileno);
			gtk_label_set_text(GTK_LABEL(structlabel->label77), rec.emailid);
			gtk_label_set_text(GTK_LABEL(structlabel->label78), rec.date);
		}
		else if(p == 6) {	
			gtk_label_set_text(GTK_LABEL(structlabel->label81), rec.mis);
			gtk_label_set_text(GTK_LABEL(structlabel->label82), rec.name);
			gtk_label_set_text(GTK_LABEL(structlabel->label83), rec.address);
			gtk_label_set_text(GTK_LABEL(structlabel->label84), rec.branch);
			gtk_label_set_text(GTK_LABEL(structlabel->label85), rec.blockno);
			gtk_label_set_text(GTK_LABEL(structlabel->label86), rec.mobileno);
			gtk_label_set_text(GTK_LABEL(structlabel->label87), rec.emailid);
			gtk_label_set_text(GTK_LABEL(structlabel->label88), rec.date);
		}
		else if(p == 7) {	
			gtk_label_set_text(GTK_LABEL(structlabel->label91), rec.mis);
			gtk_label_set_text(GTK_LABEL(structlabel->label92), rec.name);
			gtk_label_set_text(GTK_LABEL(structlabel->label93), rec.address);
			gtk_label_set_text(GTK_LABEL(structlabel->label94), rec.branch);
			gtk_label_set_text(GTK_LABEL(structlabel->label95), rec.blockno);
			gtk_label_set_text(GTK_LABEL(structlabel->label96), rec.mobileno);
			gtk_label_set_text(GTK_LABEL(structlabel->label97), rec.emailid);
			gtk_label_set_text(GTK_LABEL(structlabel->label98), rec.date);
		}
		else if(p == 8) {	
			gtk_label_set_text(GTK_LABEL(structlabel->label101), rec.mis);
			gtk_label_set_text(GTK_LABEL(structlabel->label102), rec.name);
			gtk_label_set_text(GTK_LABEL(structlabel->label103), rec.address);
			gtk_label_set_text(GTK_LABEL(structlabel->label104), rec.branch);
			gtk_label_set_text(GTK_LABEL(structlabel->label105), rec.blockno);
			gtk_label_set_text(GTK_LABEL(structlabel->label106), rec.mobileno);
			gtk_label_set_text(GTK_LABEL(structlabel->label107), rec.emailid);
			gtk_label_set_text(GTK_LABEL(structlabel->label108), rec.date);
		}
		else if(p == 9) {	
			gtk_label_set_text(GTK_LABEL(structlabel->label111), rec.mis);
			gtk_label_set_text(GTK_LABEL(structlabel->label112), rec.name);
			gtk_label_set_text(GTK_LABEL(structlabel->label113), rec.address);
			gtk_label_set_text(GTK_LABEL(structlabel->label114), rec.branch);
			gtk_label_set_text(GTK_LABEL(structlabel->label115), rec.blockno);
			gtk_label_set_text(GTK_LABEL(structlabel->label116), rec.mobileno);
			gtk_label_set_text(GTK_LABEL(structlabel->label117), rec.emailid);
			gtk_label_set_text(GTK_LABEL(structlabel->label118), rec.date);
		}
		else if(p == 10) {	
			gtk_label_set_text(GTK_LABEL(structlabel->label121), rec.mis);
			gtk_label_set_text(GTK_LABEL(structlabel->label122), rec.name);
			gtk_label_set_text(GTK_LABEL(structlabel->label123), rec.address);
			gtk_label_set_text(GTK_LABEL(structlabel->label124), rec.branch);
			gtk_label_set_text(GTK_LABEL(structlabel->label125), rec.blockno);
			gtk_label_set_text(GTK_LABEL(structlabel->label126), rec.mobileno);
			gtk_label_set_text(GTK_LABEL(structlabel->label127), rec.emailid);
			gtk_label_set_text(GTK_LABEL(structlabel->label128), rec.date);
		}
		else if(p == 11) {	
			gtk_label_set_text(GTK_LABEL(structlabel->label131), rec.mis);
			gtk_label_set_text(GTK_LABEL(structlabel->label132), rec.name);
			gtk_label_set_text(GTK_LABEL(structlabel->label133), rec.address);
			gtk_label_set_text(GTK_LABEL(structlabel->label134), rec.branch);
			gtk_label_set_text(GTK_LABEL(structlabel->label135), rec.blockno);
			gtk_label_set_text(GTK_LABEL(structlabel->label136), rec.mobileno);
			gtk_label_set_text(GTK_LABEL(structlabel->label137), rec.emailid);
			gtk_label_set_text(GTK_LABEL(structlabel->label138), rec.date);
		}
		else if(p == 12) {	
			gtk_label_set_text(GTK_LABEL(structlabel->label141), rec.mis);
			gtk_label_set_text(GTK_LABEL(structlabel->label142), rec.name);
			gtk_label_set_text(GTK_LABEL(structlabel->label143), rec.address);
			gtk_label_set_text(GTK_LABEL(structlabel->label144), rec.branch);
			gtk_label_set_text(GTK_LABEL(structlabel->label145), rec.blockno);
			gtk_label_set_text(GTK_LABEL(structlabel->label146), rec.mobileno);
			gtk_label_set_text(GTK_LABEL(structlabel->label147), rec.emailid);
			gtk_label_set_text(GTK_LABEL(structlabel->label148), rec.date);
		}
		else if(p == 13) {	
			gtk_label_set_text(GTK_LABEL(structlabel->label151), rec.mis);
			gtk_label_set_text(GTK_LABEL(structlabel->label152), rec.name);
			gtk_label_set_text(GTK_LABEL(structlabel->label153), rec.address);
			gtk_label_set_text(GTK_LABEL(structlabel->label154), rec.branch);
			gtk_label_set_text(GTK_LABEL(structlabel->label155), rec.blockno);
			gtk_label_set_text(GTK_LABEL(structlabel->label156), rec.mobileno);
			gtk_label_set_text(GTK_LABEL(structlabel->label157), rec.emailid);
			gtk_label_set_text(GTK_LABEL(structlabel->label158), rec.date);
		}
		else if(p == 14) {	
			gtk_label_set_text(GTK_LABEL(structlabel->label161), rec.mis);
			gtk_label_set_text(GTK_LABEL(structlabel->label162), rec.name);
			gtk_label_set_text(GTK_LABEL(structlabel->label163), rec.address);
			gtk_label_set_text(GTK_LABEL(structlabel->label164), rec.branch);
			gtk_label_set_text(GTK_LABEL(structlabel->label165), rec.blockno);
			gtk_label_set_text(GTK_LABEL(structlabel->label166), rec.mobileno);
			gtk_label_set_text(GTK_LABEL(structlabel->label167), rec.emailid);
			gtk_label_set_text(GTK_LABEL(structlabel->label168), rec.date);
			p=0;
			break;
		}
		if(feof(fp)){
			break;	
		}
		p++;
	}
	fclose(fp);	
}




/*******************************************************************************************refreshing list containing student details*/
static void refresh(GtkWidget *widget,  Gc_label *user_data){
	p=0;
	FILE *fp = fopen("studata.txt","r+");
	while(1){
		fscanf(fp, "%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\n]\n", rec.mis,  rec.name, rec.address, rec.branch, rec.blockno, rec.mobileno, rec.emailid, rec.date);			/*reading of file and displaying it*/
		if(p == 0) {	
			gtk_label_set_text(GTK_LABEL(user_data->label21), rec.mis);
			gtk_label_set_text(GTK_LABEL(user_data->label22), rec.name);
			gtk_label_set_text(GTK_LABEL(user_data->label23), rec.address);
			gtk_label_set_text(GTK_LABEL(user_data->label24), rec.branch);
			gtk_label_set_text(GTK_LABEL(user_data->label25), rec.blockno);
			gtk_label_set_text(GTK_LABEL(user_data->label26), rec.mobileno);
			gtk_label_set_text(GTK_LABEL(user_data->label27), rec.emailid);
		}
		else if(p == 1) {	
			gtk_label_set_text(GTK_LABEL(user_data->label31), rec.mis);
			gtk_label_set_text(GTK_LABEL(user_data->label32), rec.name);
			gtk_label_set_text(GTK_LABEL(user_data->label33), rec.address);
			gtk_label_set_text(GTK_LABEL(user_data->label34), rec.branch);
			gtk_label_set_text(GTK_LABEL(user_data->label35), rec.blockno);
			gtk_label_set_text(GTK_LABEL(user_data->label36), rec.mobileno);
			gtk_label_set_text(GTK_LABEL(user_data->label37), rec.emailid);
		}
		else if(p == 2) {	
			gtk_label_set_text(GTK_LABEL(user_data->label41), rec.mis);
			gtk_label_set_text(GTK_LABEL(user_data->label42), rec.name);
			gtk_label_set_text(GTK_LABEL(user_data->label43), rec.address);
			gtk_label_set_text(GTK_LABEL(user_data->label44), rec.branch);
			gtk_label_set_text(GTK_LABEL(user_data->label45), rec.blockno);
			gtk_label_set_text(GTK_LABEL(user_data->label46), rec.mobileno);
			gtk_label_set_text(GTK_LABEL(user_data->label47), rec.emailid);
		}
		else if(p == 3) {	
			gtk_label_set_text(GTK_LABEL(user_data->label51), rec.mis);
			gtk_label_set_text(GTK_LABEL(user_data->label52), rec.name);
			gtk_label_set_text(GTK_LABEL(user_data->label53), rec.address);
			gtk_label_set_text(GTK_LABEL(user_data->label54), rec.branch);
			gtk_label_set_text(GTK_LABEL(user_data->label55), rec.blockno);
			gtk_label_set_text(GTK_LABEL(user_data->label56), rec.mobileno);
			gtk_label_set_text(GTK_LABEL(user_data->label57), rec.emailid);
		}
		else if(p == 4) {	
			gtk_label_set_text(GTK_LABEL(user_data->label61), rec.mis);
			gtk_label_set_text(GTK_LABEL(user_data->label62), rec.name);
			gtk_label_set_text(GTK_LABEL(user_data->label63), rec.address);
			gtk_label_set_text(GTK_LABEL(user_data->label64), rec.branch);
			gtk_label_set_text(GTK_LABEL(user_data->label65), rec.blockno);
			gtk_label_set_text(GTK_LABEL(user_data->label66), rec.mobileno);
			gtk_label_set_text(GTK_LABEL(user_data->label67), rec.emailid);
		}
		else if(p == 5) {	
			gtk_label_set_text(GTK_LABEL(user_data->label71), rec.mis);
			gtk_label_set_text(GTK_LABEL(user_data->label72), rec.name);
			gtk_label_set_text(GTK_LABEL(user_data->label73), rec.address);
			gtk_label_set_text(GTK_LABEL(user_data->label74), rec.branch);
			gtk_label_set_text(GTK_LABEL(user_data->label75), rec.blockno);
			gtk_label_set_text(GTK_LABEL(user_data->label76), rec.mobileno);
			gtk_label_set_text(GTK_LABEL(user_data->label77), rec.emailid);
		}
		else if(p == 6) {	
			gtk_label_set_text(GTK_LABEL(user_data->label81), rec.mis);
			gtk_label_set_text(GTK_LABEL(user_data->label82), rec.name);
			gtk_label_set_text(GTK_LABEL(user_data->label83), rec.address);
			gtk_label_set_text(GTK_LABEL(user_data->label84), rec.branch);
			gtk_label_set_text(GTK_LABEL(user_data->label85), rec.blockno);
			gtk_label_set_text(GTK_LABEL(user_data->label86), rec.mobileno);
			gtk_label_set_text(GTK_LABEL(user_data->label87), rec.emailid);
		}
		else if(p == 7) {	
			gtk_label_set_text(GTK_LABEL(user_data->label91), rec.mis);
			gtk_label_set_text(GTK_LABEL(user_data->label92), rec.name);
			gtk_label_set_text(GTK_LABEL(user_data->label93), rec.address);
			gtk_label_set_text(GTK_LABEL(user_data->label94), rec.branch);
			gtk_label_set_text(GTK_LABEL(user_data->label95), rec.blockno);
			gtk_label_set_text(GTK_LABEL(user_data->label96), rec.mobileno);
			gtk_label_set_text(GTK_LABEL(user_data->label97), rec.emailid);
		}
		else if(p == 8) {	
			gtk_label_set_text(GTK_LABEL(user_data->label101), rec.mis);
			gtk_label_set_text(GTK_LABEL(user_data->label102), rec.name);
			gtk_label_set_text(GTK_LABEL(user_data->label103), rec.address);
			gtk_label_set_text(GTK_LABEL(user_data->label104), rec.branch);
			gtk_label_set_text(GTK_LABEL(user_data->label105), rec.blockno);
			gtk_label_set_text(GTK_LABEL(user_data->label106), rec.mobileno);
			gtk_label_set_text(GTK_LABEL(user_data->label107), rec.emailid);
		}
		else if(p == 9) {	
			gtk_label_set_text(GTK_LABEL(user_data->label111), rec.mis);
			gtk_label_set_text(GTK_LABEL(user_data->label112), rec.name);
			gtk_label_set_text(GTK_LABEL(user_data->label113), rec.address);
			gtk_label_set_text(GTK_LABEL(user_data->label114), rec.branch);
			gtk_label_set_text(GTK_LABEL(user_data->label115), rec.blockno);
			gtk_label_set_text(GTK_LABEL(user_data->label116), rec.mobileno);
			gtk_label_set_text(GTK_LABEL(user_data->label117), rec.emailid);
		}
		else if(p == 10) {	
			gtk_label_set_text(GTK_LABEL(user_data->label121), rec.mis);
			gtk_label_set_text(GTK_LABEL(user_data->label122), rec.name);
			gtk_label_set_text(GTK_LABEL(user_data->label123), rec.address);
			gtk_label_set_text(GTK_LABEL(user_data->label124), rec.branch);
			gtk_label_set_text(GTK_LABEL(user_data->label125), rec.blockno);
			gtk_label_set_text(GTK_LABEL(user_data->label126), rec.mobileno);
			gtk_label_set_text(GTK_LABEL(user_data->label127), rec.emailid);
		}
		else if(p == 11) {	
			gtk_label_set_text(GTK_LABEL(user_data->label131), rec.mis);
			gtk_label_set_text(GTK_LABEL(user_data->label132), rec.name);
			gtk_label_set_text(GTK_LABEL(user_data->label133), rec.address);
			gtk_label_set_text(GTK_LABEL(user_data->label134), rec.branch);
			gtk_label_set_text(GTK_LABEL(user_data->label135), rec.blockno);
			gtk_label_set_text(GTK_LABEL(user_data->label136), rec.mobileno);
			gtk_label_set_text(GTK_LABEL(user_data->label137), rec.emailid);
		}
		else if(p == 12) {	
			gtk_label_set_text(GTK_LABEL(user_data->label141), rec.mis);
			gtk_label_set_text(GTK_LABEL(user_data->label142), rec.name);
			gtk_label_set_text(GTK_LABEL(user_data->label143), rec.address);
			gtk_label_set_text(GTK_LABEL(user_data->label144), rec.branch);
			gtk_label_set_text(GTK_LABEL(user_data->label145), rec.blockno);
			gtk_label_set_text(GTK_LABEL(user_data->label146), rec.mobileno);
			gtk_label_set_text(GTK_LABEL(user_data->label147), rec.emailid);
		}
		else if(p == 13) {	
			gtk_label_set_text(GTK_LABEL(user_data->label151), rec.mis);
			gtk_label_set_text(GTK_LABEL(user_data->label152), rec.name);
			gtk_label_set_text(GTK_LABEL(user_data->label153), rec.address);
			gtk_label_set_text(GTK_LABEL(user_data->label154), rec.branch);
			gtk_label_set_text(GTK_LABEL(user_data->label155), rec.blockno);
			gtk_label_set_text(GTK_LABEL(user_data->label156), rec.mobileno);
			gtk_label_set_text(GTK_LABEL(user_data->label157), rec.emailid);
		}
		else if(p == 14) {	
			gtk_label_set_text(GTK_LABEL(user_data->label161), rec.mis);
			gtk_label_set_text(GTK_LABEL(user_data->label162), rec.name);
			gtk_label_set_text(GTK_LABEL(user_data->label163), rec.address);
			gtk_label_set_text(GTK_LABEL(user_data->label164), rec.branch);
			gtk_label_set_text(GTK_LABEL(user_data->label165), rec.blockno);
			gtk_label_set_text(GTK_LABEL(user_data->label166), rec.mobileno);
			gtk_label_set_text(GTK_LABEL(user_data->label167), rec.emailid);
			p=0;
			break;
		}
		if(feof(fp)){
			break;	
		}
		p++;
	}
	fclose(fp);
}


/***********************************************************************************************displays more & more contents of file*/
static void next(GtkWidget *widget,  Gc_label *user_data){
	FILE *fp = fopen("studata.txt","r+");
	int u=0;
	int y=0;
	p = p + 15;
	while(1){
		fscanf(fp, "%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\n]\n", rec.mis,  rec.name, rec.address, rec.branch, rec.blockno, rec.mobileno, rec.emailid, rec.date);                            /*reading of file and displaying it*/
		u++;
		if(p+1 == u){
			u--;
			if(y == 0) {	
				gtk_label_set_text(GTK_LABEL(user_data->label21), rec.mis);
				gtk_label_set_text(GTK_LABEL(user_data->label22), rec.name);
				gtk_label_set_text(GTK_LABEL(user_data->label23), rec.address);
				gtk_label_set_text(GTK_LABEL(user_data->label24), rec.branch);
				gtk_label_set_text(GTK_LABEL(user_data->label25), rec.blockno);
				gtk_label_set_text(GTK_LABEL(user_data->label26), rec.mobileno);
				gtk_label_set_text(GTK_LABEL(user_data->label27), rec.emailid);
			}
			else if(y == 1) {	
				gtk_label_set_text(GTK_LABEL(user_data->label31), rec.mis);
				gtk_label_set_text(GTK_LABEL(user_data->label32), rec.name);
				gtk_label_set_text(GTK_LABEL(user_data->label33), rec.address);
				gtk_label_set_text(GTK_LABEL(user_data->label34), rec.branch);
				gtk_label_set_text(GTK_LABEL(user_data->label35), rec.blockno);
				gtk_label_set_text(GTK_LABEL(user_data->label36), rec.mobileno);
				gtk_label_set_text(GTK_LABEL(user_data->label37), rec.emailid);
			}
			else if(y == 2) {	
				gtk_label_set_text(GTK_LABEL(user_data->label41), rec.mis);
				gtk_label_set_text(GTK_LABEL(user_data->label42), rec.name);
				gtk_label_set_text(GTK_LABEL(user_data->label43), rec.address);
				gtk_label_set_text(GTK_LABEL(user_data->label44), rec.branch);
				gtk_label_set_text(GTK_LABEL(user_data->label45), rec.blockno);
				gtk_label_set_text(GTK_LABEL(user_data->label46), rec.mobileno);
				gtk_label_set_text(GTK_LABEL(user_data->label47), rec.emailid);
			}
			else if(y == 3) {	
				gtk_label_set_text(GTK_LABEL(user_data->label51), rec.mis);
				gtk_label_set_text(GTK_LABEL(user_data->label52), rec.name);
				gtk_label_set_text(GTK_LABEL(user_data->label53), rec.address);
				gtk_label_set_text(GTK_LABEL(user_data->label54), rec.branch);
				gtk_label_set_text(GTK_LABEL(user_data->label55), rec.blockno);
				gtk_label_set_text(GTK_LABEL(user_data->label56), rec.mobileno);
				gtk_label_set_text(GTK_LABEL(user_data->label57), rec.emailid);
			}
			else if(y == 4) {	
				gtk_label_set_text(GTK_LABEL(user_data->label61), rec.mis);
				gtk_label_set_text(GTK_LABEL(user_data->label62), rec.name);
				gtk_label_set_text(GTK_LABEL(user_data->label63), rec.address);
				gtk_label_set_text(GTK_LABEL(user_data->label64), rec.branch);
				gtk_label_set_text(GTK_LABEL(user_data->label65), rec.blockno);
				gtk_label_set_text(GTK_LABEL(user_data->label66), rec.mobileno);
				gtk_label_set_text(GTK_LABEL(user_data->label67), rec.emailid);
			}
			else if(y == 5) {	
				gtk_label_set_text(GTK_LABEL(user_data->label71), rec.mis);
				gtk_label_set_text(GTK_LABEL(user_data->label72), rec.name);
				gtk_label_set_text(GTK_LABEL(user_data->label73), rec.address);
				gtk_label_set_text(GTK_LABEL(user_data->label74), rec.branch);
				gtk_label_set_text(GTK_LABEL(user_data->label75), rec.blockno);
				gtk_label_set_text(GTK_LABEL(user_data->label76), rec.mobileno);
				gtk_label_set_text(GTK_LABEL(user_data->label77), rec.emailid);
			}
			else if(y == 6) {	
				gtk_label_set_text(GTK_LABEL(user_data->label81), rec.mis);
				gtk_label_set_text(GTK_LABEL(user_data->label82), rec.name);
				gtk_label_set_text(GTK_LABEL(user_data->label83), rec.address);
				gtk_label_set_text(GTK_LABEL(user_data->label84), rec.branch);
				gtk_label_set_text(GTK_LABEL(user_data->label85), rec.blockno);
				gtk_label_set_text(GTK_LABEL(user_data->label86), rec.mobileno);
				gtk_label_set_text(GTK_LABEL(user_data->label87), rec.emailid);
			}
			else if(y == 7) {	
				gtk_label_set_text(GTK_LABEL(user_data->label91), rec.mis);
				gtk_label_set_text(GTK_LABEL(user_data->label92), rec.name);
				gtk_label_set_text(GTK_LABEL(user_data->label93), rec.address);
				gtk_label_set_text(GTK_LABEL(user_data->label94), rec.branch);
				gtk_label_set_text(GTK_LABEL(user_data->label95), rec.blockno);
				gtk_label_set_text(GTK_LABEL(user_data->label96), rec.mobileno);
				gtk_label_set_text(GTK_LABEL(user_data->label97), rec.emailid);
			}
			else if(y == 8) {	
				gtk_label_set_text(GTK_LABEL(user_data->label101), rec.mis);
				gtk_label_set_text(GTK_LABEL(user_data->label102), rec.name);
				gtk_label_set_text(GTK_LABEL(user_data->label103), rec.address);
				gtk_label_set_text(GTK_LABEL(user_data->label104), rec.branch);
				gtk_label_set_text(GTK_LABEL(user_data->label105), rec.blockno);
				gtk_label_set_text(GTK_LABEL(user_data->label106), rec.mobileno);
				gtk_label_set_text(GTK_LABEL(user_data->label107), rec.emailid);
			}
			else if(y == 9) {	
				gtk_label_set_text(GTK_LABEL(user_data->label111), rec.mis);
				gtk_label_set_text(GTK_LABEL(user_data->label112), rec.name);
				gtk_label_set_text(GTK_LABEL(user_data->label113), rec.address);
				gtk_label_set_text(GTK_LABEL(user_data->label114), rec.branch);
				gtk_label_set_text(GTK_LABEL(user_data->label115), rec.blockno);
				gtk_label_set_text(GTK_LABEL(user_data->label116), rec.mobileno);
				gtk_label_set_text(GTK_LABEL(user_data->label117), rec.emailid);
			}
			else if(y == 10) {	
				gtk_label_set_text(GTK_LABEL(user_data->label121), rec.mis);
				gtk_label_set_text(GTK_LABEL(user_data->label122), rec.name);
				gtk_label_set_text(GTK_LABEL(user_data->label123), rec.address);
				gtk_label_set_text(GTK_LABEL(user_data->label124), rec.branch);
				gtk_label_set_text(GTK_LABEL(user_data->label125), rec.blockno);
				gtk_label_set_text(GTK_LABEL(user_data->label126), rec.mobileno);
				gtk_label_set_text(GTK_LABEL(user_data->label127), rec.emailid);
			}
			else if(y == 11) {	
				gtk_label_set_text(GTK_LABEL(user_data->label131), rec.mis);
				gtk_label_set_text(GTK_LABEL(user_data->label132), rec.name);
				gtk_label_set_text(GTK_LABEL(user_data->label133), rec.address);
				gtk_label_set_text(GTK_LABEL(user_data->label134), rec.branch);
				gtk_label_set_text(GTK_LABEL(user_data->label135), rec.blockno);
				gtk_label_set_text(GTK_LABEL(user_data->label136), rec.mobileno);
				gtk_label_set_text(GTK_LABEL(user_data->label137), rec.emailid);
			}
			else if(y == 12) {	
				gtk_label_set_text(GTK_LABEL(user_data->label141), rec.mis);
				gtk_label_set_text(GTK_LABEL(user_data->label142), rec.name);
				gtk_label_set_text(GTK_LABEL(user_data->label143), rec.address);
				gtk_label_set_text(GTK_LABEL(user_data->label144), rec.branch);
				gtk_label_set_text(GTK_LABEL(user_data->label145), rec.blockno);
				gtk_label_set_text(GTK_LABEL(user_data->label146), rec.mobileno);
				gtk_label_set_text(GTK_LABEL(user_data->label147), rec.emailid);
			}
			else if(y == 13) {	
				gtk_label_set_text(GTK_LABEL(user_data->label151), rec.mis);
				gtk_label_set_text(GTK_LABEL(user_data->label152), rec.name);
				gtk_label_set_text(GTK_LABEL(user_data->label153), rec.address);
				gtk_label_set_text(GTK_LABEL(user_data->label154), rec.branch);
				gtk_label_set_text(GTK_LABEL(user_data->label155), rec.blockno);
				gtk_label_set_text(GTK_LABEL(user_data->label156), rec.mobileno);
				gtk_label_set_text(GTK_LABEL(user_data->label157), rec.emailid);
			}
			else if(y == 14) {	
				gtk_label_set_text(GTK_LABEL(user_data->label161), rec.mis);
				gtk_label_set_text(GTK_LABEL(user_data->label162), rec.name);
				gtk_label_set_text(GTK_LABEL(user_data->label163), rec.address);
				gtk_label_set_text(GTK_LABEL(user_data->label164), rec.branch);
				gtk_label_set_text(GTK_LABEL(user_data->label165), rec.blockno);
				gtk_label_set_text(GTK_LABEL(user_data->label166), rec.mobileno);
				gtk_label_set_text(GTK_LABEL(user_data->label167), rec.emailid);
			}
			y++;
			if(feof(fp)){
				if(y == 0) {	
					gtk_label_set_text(GTK_LABEL(user_data->label21), "");
					gtk_label_set_text(GTK_LABEL(user_data->label22), "");
					gtk_label_set_text(GTK_LABEL(user_data->label23), "");
					gtk_label_set_text(GTK_LABEL(user_data->label24), "");
					gtk_label_set_text(GTK_LABEL(user_data->label25), "");
					gtk_label_set_text(GTK_LABEL(user_data->label26), "");
					gtk_label_set_text(GTK_LABEL(user_data->label27), "");
					y++;
				}
				if(y == 1) {	
					gtk_label_set_text(GTK_LABEL(user_data->label31), "");
					gtk_label_set_text(GTK_LABEL(user_data->label32), "");
					gtk_label_set_text(GTK_LABEL(user_data->label33), "");
					gtk_label_set_text(GTK_LABEL(user_data->label34), "");
					gtk_label_set_text(GTK_LABEL(user_data->label35), "");
					gtk_label_set_text(GTK_LABEL(user_data->label36), "");
					gtk_label_set_text(GTK_LABEL(user_data->label37), "");
					y++;				
				}
				if(y == 2) {	
					gtk_label_set_text(GTK_LABEL(user_data->label41), "");
					gtk_label_set_text(GTK_LABEL(user_data->label42), "");
					gtk_label_set_text(GTK_LABEL(user_data->label43), "");
					gtk_label_set_text(GTK_LABEL(user_data->label44), "");
					gtk_label_set_text(GTK_LABEL(user_data->label45), "");
					gtk_label_set_text(GTK_LABEL(user_data->label46), "");
					gtk_label_set_text(GTK_LABEL(user_data->label47), "");
					y++;
				}
				if(y == 3) {	
					gtk_label_set_text(GTK_LABEL(user_data->label51), "");
					gtk_label_set_text(GTK_LABEL(user_data->label52), "");
					gtk_label_set_text(GTK_LABEL(user_data->label53), "");
					gtk_label_set_text(GTK_LABEL(user_data->label54), "");
					gtk_label_set_text(GTK_LABEL(user_data->label55), "");
					gtk_label_set_text(GTK_LABEL(user_data->label56), "");
					gtk_label_set_text(GTK_LABEL(user_data->label57), "");
					y++;
				}
				if(y == 4) {	
					gtk_label_set_text(GTK_LABEL(user_data->label61), "");
					gtk_label_set_text(GTK_LABEL(user_data->label62), "");
					gtk_label_set_text(GTK_LABEL(user_data->label63), "");
					gtk_label_set_text(GTK_LABEL(user_data->label64), "");
					gtk_label_set_text(GTK_LABEL(user_data->label65), "");
					gtk_label_set_text(GTK_LABEL(user_data->label66), "");
					gtk_label_set_text(GTK_LABEL(user_data->label67), "");
					y++;
				}
				if(y == 5) {	
					gtk_label_set_text(GTK_LABEL(user_data->label71), "");
					gtk_label_set_text(GTK_LABEL(user_data->label72), "");
					gtk_label_set_text(GTK_LABEL(user_data->label73), "");
					gtk_label_set_text(GTK_LABEL(user_data->label74), "");
					gtk_label_set_text(GTK_LABEL(user_data->label75), "");
					gtk_label_set_text(GTK_LABEL(user_data->label76), "");
					gtk_label_set_text(GTK_LABEL(user_data->label77), "");
					y++;
				}
				if(y == 6) {	
					gtk_label_set_text(GTK_LABEL(user_data->label81), "");
					gtk_label_set_text(GTK_LABEL(user_data->label82), "");
					gtk_label_set_text(GTK_LABEL(user_data->label83), "");
					gtk_label_set_text(GTK_LABEL(user_data->label84), "");
					gtk_label_set_text(GTK_LABEL(user_data->label85), "");
					gtk_label_set_text(GTK_LABEL(user_data->label86), "");
					gtk_label_set_text(GTK_LABEL(user_data->label87), "");
					y++;
				}
				if(y == 7) {	
					gtk_label_set_text(GTK_LABEL(user_data->label91), "");
					gtk_label_set_text(GTK_LABEL(user_data->label92), "");
					gtk_label_set_text(GTK_LABEL(user_data->label93), "");
					gtk_label_set_text(GTK_LABEL(user_data->label94), "");
					gtk_label_set_text(GTK_LABEL(user_data->label95), "");
					gtk_label_set_text(GTK_LABEL(user_data->label96), "");
					gtk_label_set_text(GTK_LABEL(user_data->label97), "");
					y++;
				}
				if(y == 8) {	
					gtk_label_set_text(GTK_LABEL(user_data->label101), "");
					gtk_label_set_text(GTK_LABEL(user_data->label102), "");
					gtk_label_set_text(GTK_LABEL(user_data->label103), "");
					gtk_label_set_text(GTK_LABEL(user_data->label104), "");
					gtk_label_set_text(GTK_LABEL(user_data->label105), "");
					gtk_label_set_text(GTK_LABEL(user_data->label106), "");
					gtk_label_set_text(GTK_LABEL(user_data->label107), "");
					y++;
				}
				if(y == 9) {	
					gtk_label_set_text(GTK_LABEL(user_data->label111), "");
					gtk_label_set_text(GTK_LABEL(user_data->label112), "");
					gtk_label_set_text(GTK_LABEL(user_data->label113), "");
					gtk_label_set_text(GTK_LABEL(user_data->label114), "");
					gtk_label_set_text(GTK_LABEL(user_data->label115), "");
					gtk_label_set_text(GTK_LABEL(user_data->label116), "");
					gtk_label_set_text(GTK_LABEL(user_data->label117), "");
					y++;
				}
				if(y == 10) {	
					gtk_label_set_text(GTK_LABEL(user_data->label121), "");
					gtk_label_set_text(GTK_LABEL(user_data->label122), "");
					gtk_label_set_text(GTK_LABEL(user_data->label123), "");
					gtk_label_set_text(GTK_LABEL(user_data->label124), "");
					gtk_label_set_text(GTK_LABEL(user_data->label125), "");
					gtk_label_set_text(GTK_LABEL(user_data->label126), "");
					gtk_label_set_text(GTK_LABEL(user_data->label127), "");
					y++;
				}
				if(y == 11) {	
					gtk_label_set_text(GTK_LABEL(user_data->label131), "");
					gtk_label_set_text(GTK_LABEL(user_data->label132), "");
					gtk_label_set_text(GTK_LABEL(user_data->label133), "");
					gtk_label_set_text(GTK_LABEL(user_data->label134), "");
					gtk_label_set_text(GTK_LABEL(user_data->label135), "");
					gtk_label_set_text(GTK_LABEL(user_data->label136), "");
					gtk_label_set_text(GTK_LABEL(user_data->label137), "");
					y++;
				}
				if(y == 12) {	
					gtk_label_set_text(GTK_LABEL(user_data->label141), "");
					gtk_label_set_text(GTK_LABEL(user_data->label142), "");
					gtk_label_set_text(GTK_LABEL(user_data->label143), "");
					gtk_label_set_text(GTK_LABEL(user_data->label144), "");
					gtk_label_set_text(GTK_LABEL(user_data->label145), "");
					gtk_label_set_text(GTK_LABEL(user_data->label146), "");
					gtk_label_set_text(GTK_LABEL(user_data->label147), "");
					y++;
				}
				if(y == 13) {	
					gtk_label_set_text(GTK_LABEL(user_data->label151), "");
					gtk_label_set_text(GTK_LABEL(user_data->label152), "");
					gtk_label_set_text(GTK_LABEL(user_data->label153), "");
					gtk_label_set_text(GTK_LABEL(user_data->label154), "");
					gtk_label_set_text(GTK_LABEL(user_data->label155), "");
					gtk_label_set_text(GTK_LABEL(user_data->label156), "");
					gtk_label_set_text(GTK_LABEL(user_data->label157), "");
					y++;
				}
				if(y == 14) {	
					gtk_label_set_text(GTK_LABEL(user_data->label161), "");
					gtk_label_set_text(GTK_LABEL(user_data->label162), "");
					gtk_label_set_text(GTK_LABEL(user_data->label163), "");
					gtk_label_set_text(GTK_LABEL(user_data->label164), "");
					gtk_label_set_text(GTK_LABEL(user_data->label165), "");
					gtk_label_set_text(GTK_LABEL(user_data->label166), "");
					gtk_label_set_text(GTK_LABEL(user_data->label167), "");
					y++;
					break;
				}
				break;	
			}
		}
		else if(feof(fp)){
			p = p - 15;
			break;
		}			
	}
	fclose(fp);
}

/**********************************************************************************************displays more and more contents of file*/
static void nextnext(GtkWidget *widget,  Gc_label *structlabel){
	FILE *fp = fopen("studata.txt","r+");
	int u=0;
	int y=0;
	p = p + 15;
	while(1){                                                  
		fscanf(fp, "%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\n]\n", rec.mis,  rec.name, rec.address, rec.branch, rec.blockno, rec.mobileno, rec.emailid, rec.date);                                /*reading of file and displaying it*/
		u++;
		if(p+1 == u){
			u--;
			if(y == 0) {	
				gtk_label_set_text(GTK_LABEL(structlabel->label21), rec.mis);
				gtk_label_set_text(GTK_LABEL(structlabel->label22), rec.name);
				gtk_label_set_text(GTK_LABEL(structlabel->label23), rec.address);
				gtk_label_set_text(GTK_LABEL(structlabel->label24), rec.branch);
				gtk_label_set_text(GTK_LABEL(structlabel->label25), rec.blockno);
				gtk_label_set_text(GTK_LABEL(structlabel->label26), rec.mobileno);
				gtk_label_set_text(GTK_LABEL(structlabel->label27), rec.emailid);
				gtk_label_set_text(GTK_LABEL(structlabel->label28), rec.date);				
			}
			else if(y == 1) {	
				gtk_label_set_text(GTK_LABEL(structlabel->label31), rec.mis);
				gtk_label_set_text(GTK_LABEL(structlabel->label32), rec.name);
				gtk_label_set_text(GTK_LABEL(structlabel->label33), rec.address);
				gtk_label_set_text(GTK_LABEL(structlabel->label34), rec.branch);
				gtk_label_set_text(GTK_LABEL(structlabel->label35), rec.blockno);
				gtk_label_set_text(GTK_LABEL(structlabel->label36), rec.mobileno);
				gtk_label_set_text(GTK_LABEL(structlabel->label37), rec.emailid);
				gtk_label_set_text(GTK_LABEL(structlabel->label38), rec.date);
			}
			else if(y == 2) {	
				gtk_label_set_text(GTK_LABEL(structlabel->label41), rec.mis);
				gtk_label_set_text(GTK_LABEL(structlabel->label42), rec.name);
				gtk_label_set_text(GTK_LABEL(structlabel->label43), rec.address);
				gtk_label_set_text(GTK_LABEL(structlabel->label44), rec.branch);
				gtk_label_set_text(GTK_LABEL(structlabel->label45), rec.blockno);
				gtk_label_set_text(GTK_LABEL(structlabel->label46), rec.mobileno);
				gtk_label_set_text(GTK_LABEL(structlabel->label47), rec.emailid);
				gtk_label_set_text(GTK_LABEL(structlabel->label48), rec.date);
			}
			else if(y == 3) {	
				gtk_label_set_text(GTK_LABEL(structlabel->label51), rec.mis);
				gtk_label_set_text(GTK_LABEL(structlabel->label52), rec.name);
				gtk_label_set_text(GTK_LABEL(structlabel->label53), rec.address);
				gtk_label_set_text(GTK_LABEL(structlabel->label54), rec.branch);
				gtk_label_set_text(GTK_LABEL(structlabel->label55), rec.blockno);
				gtk_label_set_text(GTK_LABEL(structlabel->label56), rec.mobileno);
				gtk_label_set_text(GTK_LABEL(structlabel->label57), rec.emailid);
				gtk_label_set_text(GTK_LABEL(structlabel->label58), rec.date);
			}
			else if(y == 4) {	
				gtk_label_set_text(GTK_LABEL(structlabel->label61), rec.mis);
				gtk_label_set_text(GTK_LABEL(structlabel->label62), rec.name);
				gtk_label_set_text(GTK_LABEL(structlabel->label63), rec.address);
				gtk_label_set_text(GTK_LABEL(structlabel->label64), rec.branch);
				gtk_label_set_text(GTK_LABEL(structlabel->label65), rec.blockno);
				gtk_label_set_text(GTK_LABEL(structlabel->label66), rec.mobileno);
				gtk_label_set_text(GTK_LABEL(structlabel->label67), rec.emailid);
				gtk_label_set_text(GTK_LABEL(structlabel->label68), rec.date);
			}
			else if(y == 5) {	
				gtk_label_set_text(GTK_LABEL(structlabel->label71), rec.mis);
				gtk_label_set_text(GTK_LABEL(structlabel->label72), rec.name);
				gtk_label_set_text(GTK_LABEL(structlabel->label73), rec.address);
				gtk_label_set_text(GTK_LABEL(structlabel->label74), rec.branch);
				gtk_label_set_text(GTK_LABEL(structlabel->label75), rec.blockno);
				gtk_label_set_text(GTK_LABEL(structlabel->label76), rec.mobileno);
				gtk_label_set_text(GTK_LABEL(structlabel->label77), rec.emailid);
				gtk_label_set_text(GTK_LABEL(structlabel->label78), rec.date);		
			}
			else if(y == 6) {	
				gtk_label_set_text(GTK_LABEL(structlabel->label81), rec.mis);
				gtk_label_set_text(GTK_LABEL(structlabel->label82), rec.name);
				gtk_label_set_text(GTK_LABEL(structlabel->label83), rec.address);
				gtk_label_set_text(GTK_LABEL(structlabel->label84), rec.branch);
				gtk_label_set_text(GTK_LABEL(structlabel->label85), rec.blockno);
				gtk_label_set_text(GTK_LABEL(structlabel->label86), rec.mobileno);
				gtk_label_set_text(GTK_LABEL(structlabel->label87), rec.emailid);
				gtk_label_set_text(GTK_LABEL(structlabel->label88), rec.date);
			}
			else if(y == 7) {	
				gtk_label_set_text(GTK_LABEL(structlabel->label91), rec.mis);
				gtk_label_set_text(GTK_LABEL(structlabel->label92), rec.name);
				gtk_label_set_text(GTK_LABEL(structlabel->label93), rec.address);
				gtk_label_set_text(GTK_LABEL(structlabel->label94), rec.branch);
				gtk_label_set_text(GTK_LABEL(structlabel->label95), rec.blockno);
				gtk_label_set_text(GTK_LABEL(structlabel->label96), rec.mobileno);
				gtk_label_set_text(GTK_LABEL(structlabel->label97), rec.emailid);
				gtk_label_set_text(GTK_LABEL(structlabel->label98), rec.date);
			}
			else if(y == 8) {	
				gtk_label_set_text(GTK_LABEL(structlabel->label101), rec.mis);
				gtk_label_set_text(GTK_LABEL(structlabel->label102), rec.name);
				gtk_label_set_text(GTK_LABEL(structlabel->label103), rec.address);
				gtk_label_set_text(GTK_LABEL(structlabel->label104), rec.branch);
				gtk_label_set_text(GTK_LABEL(structlabel->label105), rec.blockno);
				gtk_label_set_text(GTK_LABEL(structlabel->label106), rec.mobileno);
				gtk_label_set_text(GTK_LABEL(structlabel->label107), rec.emailid);
				gtk_label_set_text(GTK_LABEL(structlabel->label108), rec.date);
			}
			else if(y == 9) {	
				gtk_label_set_text(GTK_LABEL(structlabel->label111), rec.mis);
				gtk_label_set_text(GTK_LABEL(structlabel->label112), rec.name);
				gtk_label_set_text(GTK_LABEL(structlabel->label113), rec.address);
				gtk_label_set_text(GTK_LABEL(structlabel->label114), rec.branch);
				gtk_label_set_text(GTK_LABEL(structlabel->label115), rec.blockno);
				gtk_label_set_text(GTK_LABEL(structlabel->label116), rec.mobileno);
				gtk_label_set_text(GTK_LABEL(structlabel->label117), rec.emailid);
				gtk_label_set_text(GTK_LABEL(structlabel->label118), rec.date);
			}
			else if(y == 10) {	
				gtk_label_set_text(GTK_LABEL(structlabel->label121), rec.mis);
				gtk_label_set_text(GTK_LABEL(structlabel->label122), rec.name);
				gtk_label_set_text(GTK_LABEL(structlabel->label123), rec.address);
				gtk_label_set_text(GTK_LABEL(structlabel->label124), rec.branch);
				gtk_label_set_text(GTK_LABEL(structlabel->label125), rec.blockno);
				gtk_label_set_text(GTK_LABEL(structlabel->label126), rec.mobileno);
				gtk_label_set_text(GTK_LABEL(structlabel->label127), rec.emailid);
				gtk_label_set_text(GTK_LABEL(structlabel->label128), rec.date);
			}
			else if(y == 11) {	
				gtk_label_set_text(GTK_LABEL(structlabel->label131), rec.mis);
				gtk_label_set_text(GTK_LABEL(structlabel->label132), rec.name);
				gtk_label_set_text(GTK_LABEL(structlabel->label133), rec.address);
				gtk_label_set_text(GTK_LABEL(structlabel->label134), rec.branch);
				gtk_label_set_text(GTK_LABEL(structlabel->label135), rec.blockno);
				gtk_label_set_text(GTK_LABEL(structlabel->label136), rec.mobileno);
				gtk_label_set_text(GTK_LABEL(structlabel->label137), rec.emailid);
				gtk_label_set_text(GTK_LABEL(structlabel->label138), rec.date);
			}
			else if(y == 12) {	
				gtk_label_set_text(GTK_LABEL(structlabel->label141), rec.mis);
				gtk_label_set_text(GTK_LABEL(structlabel->label142), rec.name);
				gtk_label_set_text(GTK_LABEL(structlabel->label143), rec.address);
				gtk_label_set_text(GTK_LABEL(structlabel->label144), rec.branch);
				gtk_label_set_text(GTK_LABEL(structlabel->label145), rec.blockno);
				gtk_label_set_text(GTK_LABEL(structlabel->label146), rec.mobileno);
				gtk_label_set_text(GTK_LABEL(structlabel->label147), rec.emailid);
				gtk_label_set_text(GTK_LABEL(structlabel->label148), rec.date);
			}
			else if(y == 13) {	
				gtk_label_set_text(GTK_LABEL(structlabel->label151), rec.mis);
				gtk_label_set_text(GTK_LABEL(structlabel->label152), rec.name);
				gtk_label_set_text(GTK_LABEL(structlabel->label153), rec.address);
				gtk_label_set_text(GTK_LABEL(structlabel->label154), rec.branch);
				gtk_label_set_text(GTK_LABEL(structlabel->label155), rec.blockno);
				gtk_label_set_text(GTK_LABEL(structlabel->label156), rec.mobileno);
				gtk_label_set_text(GTK_LABEL(structlabel->label157), rec.emailid);
				gtk_label_set_text(GTK_LABEL(structlabel->label158), rec.date);
			}
			else if(y == 14) {	
				gtk_label_set_text(GTK_LABEL(structlabel->label161), rec.mis);
				gtk_label_set_text(GTK_LABEL(structlabel->label162), rec.name);
				gtk_label_set_text(GTK_LABEL(structlabel->label163), rec.address);
				gtk_label_set_text(GTK_LABEL(structlabel->label164), rec.branch);
				gtk_label_set_text(GTK_LABEL(structlabel->label165), rec.blockno);
				gtk_label_set_text(GTK_LABEL(structlabel->label166), rec.mobileno);
				gtk_label_set_text(GTK_LABEL(structlabel->label167), rec.emailid);
				gtk_label_set_text(GTK_LABEL(structlabel->label168), rec.date);
			}
			y++;
			if(feof(fp)){
				if(y == 0) {	
					gtk_label_set_text(GTK_LABEL(structlabel->label21), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label22), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label23), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label24), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label25), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label26), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label27), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label28),"");
					y++;
				}
				if(y == 1) {	
					gtk_label_set_text(GTK_LABEL(structlabel->label31), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label32), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label33), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label34), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label35), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label36), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label37), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label38),"");
					y++;				
				}
				if(y == 2) {	
					gtk_label_set_text(GTK_LABEL(structlabel->label41), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label42), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label43), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label44), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label45), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label46), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label47), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label48),"");
					y++;
				}
				if(y == 3) {	
					gtk_label_set_text(GTK_LABEL(structlabel->label51), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label52), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label53), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label54), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label55), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label56), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label57), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label58),"");
					y++;
				}
				if(y == 4) {	
					gtk_label_set_text(GTK_LABEL(structlabel->label61), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label62), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label63), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label64), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label65), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label66), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label67), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label68),"");
					y++;
				}
				if(y == 5) {	
					gtk_label_set_text(GTK_LABEL(structlabel->label71), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label72), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label73), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label74), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label75), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label76), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label77), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label78),"");
					y++;
				}
				if(y == 6) {	
					gtk_label_set_text(GTK_LABEL(structlabel->label81), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label82), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label83), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label84), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label85), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label86), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label87), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label88),"");
					y++;
				}
				if(y == 7) {	
					gtk_label_set_text(GTK_LABEL(structlabel->label91), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label92), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label93), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label94), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label95), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label96), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label97), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label98),"");
					y++;
				}
				if(y == 8) {	
					gtk_label_set_text(GTK_LABEL(structlabel->label101), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label102), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label103), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label104), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label105), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label106), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label107), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label108),"");
					y++;
				}
				if(y == 9) {	
					gtk_label_set_text(GTK_LABEL(structlabel->label111), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label112), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label113), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label114), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label115), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label116), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label117), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label118),"");
					y++;
				}
				if(y == 10) {	
					gtk_label_set_text(GTK_LABEL(structlabel->label121), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label122), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label123), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label124), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label125), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label126), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label127), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label128),"");
					y++;
				}
				if(y == 11) {	
					gtk_label_set_text(GTK_LABEL(structlabel->label131), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label132), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label133), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label134), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label135), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label136), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label137), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label138),"");
					y++;
				}
				if(y == 12) {	
					gtk_label_set_text(GTK_LABEL(structlabel->label141), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label142), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label143), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label144), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label145), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label146), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label147), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label148),"");
					y++;
				}
				if(y == 13) {	
					gtk_label_set_text(GTK_LABEL(structlabel->label151), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label152), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label153), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label154), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label155), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label156), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label157), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label158),"");
					y++;
				}
				if(y == 14) {	
					gtk_label_set_text(GTK_LABEL(structlabel->label161), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label162), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label163), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label164), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label165), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label166), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label167), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label168),"");
					y++;
					break;
				}
				break;	
			}
		}
		else if(feof(fp)){
				p = p - 15;
				break;
		}
	}
	fclose(fp);
}

/********************************************displays more & more contents of file containing details of students who had left hostel*/
static void nextleave(GtkWidget *widget,  Gc_label *structlabel){
	FILE *fp = fopen("studleave.txt","r+");
	int u=0;
	int y=0;
	p = p + 15;
	while(1){
		fscanf(fp, "%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\n]\n", rec.mis,  rec.name, rec.address, rec.branch, rec.blockno, rec.mobileno, rec.emailid, rec.date, rec.leave);                 /*reading of file and displaying it*/
		u++;
		if(p+1 == u){
			u--;
			if(y == 0) {	
				gtk_label_set_text(GTK_LABEL(structlabel->label21), rec.mis);
				gtk_label_set_text(GTK_LABEL(structlabel->label22), rec.name);
				gtk_label_set_text(GTK_LABEL(structlabel->label23), rec.address);
				gtk_label_set_text(GTK_LABEL(structlabel->label24), rec.branch);
				gtk_label_set_text(GTK_LABEL(structlabel->label25), rec.blockno);
				gtk_label_set_text(GTK_LABEL(structlabel->label26), rec.mobileno);
				gtk_label_set_text(GTK_LABEL(structlabel->label27), rec.emailid);
				gtk_label_set_text(GTK_LABEL(structlabel->label28), rec.date);
				gtk_label_set_text(GTK_LABEL(structlabel->label29), rec.leave);					
			}
			else if(y == 1) {	
				gtk_label_set_text(GTK_LABEL(structlabel->label31), rec.mis);
				gtk_label_set_text(GTK_LABEL(structlabel->label32), rec.name);
				gtk_label_set_text(GTK_LABEL(structlabel->label33), rec.address);
				gtk_label_set_text(GTK_LABEL(structlabel->label34), rec.branch);
				gtk_label_set_text(GTK_LABEL(structlabel->label35), rec.blockno);
				gtk_label_set_text(GTK_LABEL(structlabel->label36), rec.mobileno);
				gtk_label_set_text(GTK_LABEL(structlabel->label37), rec.emailid);
				gtk_label_set_text(GTK_LABEL(structlabel->label38), rec.date);
				gtk_label_set_text(GTK_LABEL(structlabel->label39), rec.leave);
			}
			else if(y == 2) {	
				gtk_label_set_text(GTK_LABEL(structlabel->label41), rec.mis);
				gtk_label_set_text(GTK_LABEL(structlabel->label42), rec.name);
				gtk_label_set_text(GTK_LABEL(structlabel->label43), rec.address);
				gtk_label_set_text(GTK_LABEL(structlabel->label44), rec.branch);
				gtk_label_set_text(GTK_LABEL(structlabel->label45), rec.blockno);
				gtk_label_set_text(GTK_LABEL(structlabel->label46), rec.mobileno);
				gtk_label_set_text(GTK_LABEL(structlabel->label47), rec.emailid);
				gtk_label_set_text(GTK_LABEL(structlabel->label48), rec.date);
				gtk_label_set_text(GTK_LABEL(structlabel->label49), rec.leave);
			}
			else if(y == 3) {	
				gtk_label_set_text(GTK_LABEL(structlabel->label51), rec.mis);
				gtk_label_set_text(GTK_LABEL(structlabel->label52), rec.name);
				gtk_label_set_text(GTK_LABEL(structlabel->label53), rec.address);
				gtk_label_set_text(GTK_LABEL(structlabel->label54), rec.branch);
				gtk_label_set_text(GTK_LABEL(structlabel->label55), rec.blockno);
				gtk_label_set_text(GTK_LABEL(structlabel->label56), rec.mobileno);
				gtk_label_set_text(GTK_LABEL(structlabel->label57), rec.emailid);
				gtk_label_set_text(GTK_LABEL(structlabel->label58), rec.date);
				gtk_label_set_text(GTK_LABEL(structlabel->label59), rec.leave);
			}
			else if(y == 4) {	
				gtk_label_set_text(GTK_LABEL(structlabel->label61), rec.mis);
				gtk_label_set_text(GTK_LABEL(structlabel->label62), rec.name);
				gtk_label_set_text(GTK_LABEL(structlabel->label63), rec.address);
				gtk_label_set_text(GTK_LABEL(structlabel->label64), rec.branch);
				gtk_label_set_text(GTK_LABEL(structlabel->label65), rec.blockno);
				gtk_label_set_text(GTK_LABEL(structlabel->label66), rec.mobileno);
				gtk_label_set_text(GTK_LABEL(structlabel->label67), rec.emailid);
				gtk_label_set_text(GTK_LABEL(structlabel->label68), rec.date);
				gtk_label_set_text(GTK_LABEL(structlabel->label69), rec.leave);
			}
			else if(y == 5) {	
				gtk_label_set_text(GTK_LABEL(structlabel->label71), rec.mis);
				gtk_label_set_text(GTK_LABEL(structlabel->label72), rec.name);
				gtk_label_set_text(GTK_LABEL(structlabel->label73), rec.address);
				gtk_label_set_text(GTK_LABEL(structlabel->label74), rec.branch);
				gtk_label_set_text(GTK_LABEL(structlabel->label75), rec.blockno);
				gtk_label_set_text(GTK_LABEL(structlabel->label76), rec.mobileno);
				gtk_label_set_text(GTK_LABEL(structlabel->label77), rec.emailid);
				gtk_label_set_text(GTK_LABEL(structlabel->label78), rec.date);
				gtk_label_set_text(GTK_LABEL(structlabel->label79), rec.leave);
			}
			else if(y == 6) {	
				gtk_label_set_text(GTK_LABEL(structlabel->label81), rec.mis);
				gtk_label_set_text(GTK_LABEL(structlabel->label82), rec.name);
				gtk_label_set_text(GTK_LABEL(structlabel->label83), rec.address);
				gtk_label_set_text(GTK_LABEL(structlabel->label84), rec.branch);
				gtk_label_set_text(GTK_LABEL(structlabel->label85), rec.blockno);
				gtk_label_set_text(GTK_LABEL(structlabel->label86), rec.mobileno);
				gtk_label_set_text(GTK_LABEL(structlabel->label87), rec.emailid);
				gtk_label_set_text(GTK_LABEL(structlabel->label88), rec.date);
				gtk_label_set_text(GTK_LABEL(structlabel->label89), rec.leave);
			}
			else if(y == 7) {	
				gtk_label_set_text(GTK_LABEL(structlabel->label91), rec.mis);
				gtk_label_set_text(GTK_LABEL(structlabel->label92), rec.name);
				gtk_label_set_text(GTK_LABEL(structlabel->label93), rec.address);
				gtk_label_set_text(GTK_LABEL(structlabel->label94), rec.branch);
				gtk_label_set_text(GTK_LABEL(structlabel->label95), rec.blockno);
				gtk_label_set_text(GTK_LABEL(structlabel->label96), rec.mobileno);
				gtk_label_set_text(GTK_LABEL(structlabel->label97), rec.emailid);
				gtk_label_set_text(GTK_LABEL(structlabel->label98), rec.date);
				gtk_label_set_text(GTK_LABEL(structlabel->label99), rec.leave);
			}
			else if(y == 8) {	
				gtk_label_set_text(GTK_LABEL(structlabel->label101), rec.mis);
				gtk_label_set_text(GTK_LABEL(structlabel->label102), rec.name);
				gtk_label_set_text(GTK_LABEL(structlabel->label103), rec.address);
				gtk_label_set_text(GTK_LABEL(structlabel->label104), rec.branch);
				gtk_label_set_text(GTK_LABEL(structlabel->label105), rec.blockno);
				gtk_label_set_text(GTK_LABEL(structlabel->label106), rec.mobileno);
				gtk_label_set_text(GTK_LABEL(structlabel->label107), rec.emailid);
				gtk_label_set_text(GTK_LABEL(structlabel->label108), rec.date);
				gtk_label_set_text(GTK_LABEL(structlabel->label109), rec.leave);
			}
			else if(y == 9) {	
				gtk_label_set_text(GTK_LABEL(structlabel->label111), rec.mis);
				gtk_label_set_text(GTK_LABEL(structlabel->label112), rec.name);
				gtk_label_set_text(GTK_LABEL(structlabel->label113), rec.address);
				gtk_label_set_text(GTK_LABEL(structlabel->label114), rec.branch);
				gtk_label_set_text(GTK_LABEL(structlabel->label115), rec.blockno);
				gtk_label_set_text(GTK_LABEL(structlabel->label116), rec.mobileno);
				gtk_label_set_text(GTK_LABEL(structlabel->label117), rec.emailid);
				gtk_label_set_text(GTK_LABEL(structlabel->label118), rec.date);
				gtk_label_set_text(GTK_LABEL(structlabel->label119), rec.leave);
			}
			else if(y == 10) {	
				gtk_label_set_text(GTK_LABEL(structlabel->label121), rec.mis);
				gtk_label_set_text(GTK_LABEL(structlabel->label122), rec.name);
				gtk_label_set_text(GTK_LABEL(structlabel->label123), rec.address);
				gtk_label_set_text(GTK_LABEL(structlabel->label124), rec.branch);
				gtk_label_set_text(GTK_LABEL(structlabel->label125), rec.blockno);
				gtk_label_set_text(GTK_LABEL(structlabel->label126), rec.mobileno);
				gtk_label_set_text(GTK_LABEL(structlabel->label127), rec.emailid);
				gtk_label_set_text(GTK_LABEL(structlabel->label128), rec.date);
				gtk_label_set_text(GTK_LABEL(structlabel->label129), rec.leave);
			}
			else if(y == 11) {	
				gtk_label_set_text(GTK_LABEL(structlabel->label131), rec.mis);
				gtk_label_set_text(GTK_LABEL(structlabel->label132), rec.name);
				gtk_label_set_text(GTK_LABEL(structlabel->label133), rec.address);
				gtk_label_set_text(GTK_LABEL(structlabel->label134), rec.branch);
				gtk_label_set_text(GTK_LABEL(structlabel->label135), rec.blockno);
				gtk_label_set_text(GTK_LABEL(structlabel->label136), rec.mobileno);
				gtk_label_set_text(GTK_LABEL(structlabel->label137), rec.emailid);
				gtk_label_set_text(GTK_LABEL(structlabel->label138), rec.date);
				gtk_label_set_text(GTK_LABEL(structlabel->label139), rec.leave);
			}
			else if(y == 12) {	
				gtk_label_set_text(GTK_LABEL(structlabel->label141), rec.mis);
				gtk_label_set_text(GTK_LABEL(structlabel->label142), rec.name);
				gtk_label_set_text(GTK_LABEL(structlabel->label143), rec.address);
				gtk_label_set_text(GTK_LABEL(structlabel->label144), rec.branch);
				gtk_label_set_text(GTK_LABEL(structlabel->label145), rec.blockno);
				gtk_label_set_text(GTK_LABEL(structlabel->label146), rec.mobileno);
				gtk_label_set_text(GTK_LABEL(structlabel->label147), rec.emailid);
				gtk_label_set_text(GTK_LABEL(structlabel->label148), rec.date);
				gtk_label_set_text(GTK_LABEL(structlabel->label149), rec.leave);
			}
			else if(y == 13) {	
				gtk_label_set_text(GTK_LABEL(structlabel->label151), rec.mis);
				gtk_label_set_text(GTK_LABEL(structlabel->label152), rec.name);
				gtk_label_set_text(GTK_LABEL(structlabel->label153), rec.address);
				gtk_label_set_text(GTK_LABEL(structlabel->label154), rec.branch);
				gtk_label_set_text(GTK_LABEL(structlabel->label155), rec.blockno);
				gtk_label_set_text(GTK_LABEL(structlabel->label156), rec.mobileno);
				gtk_label_set_text(GTK_LABEL(structlabel->label157), rec.emailid);
				gtk_label_set_text(GTK_LABEL(structlabel->label158), rec.date);
				gtk_label_set_text(GTK_LABEL(structlabel->label159), rec.leave);
			}
			else if(y == 14) {	
				gtk_label_set_text(GTK_LABEL(structlabel->label161), rec.mis);
				gtk_label_set_text(GTK_LABEL(structlabel->label162), rec.name);
				gtk_label_set_text(GTK_LABEL(structlabel->label163), rec.address);
				gtk_label_set_text(GTK_LABEL(structlabel->label164), rec.branch);
				gtk_label_set_text(GTK_LABEL(structlabel->label165), rec.blockno);
				gtk_label_set_text(GTK_LABEL(structlabel->label166), rec.mobileno);
				gtk_label_set_text(GTK_LABEL(structlabel->label167), rec.emailid);
				gtk_label_set_text(GTK_LABEL(structlabel->label168), rec.date);
				gtk_label_set_text(GTK_LABEL(structlabel->label169), rec.leave);
			}
			y++;
			if(feof(fp)){                     /*if end of file founds then set all labels to null*/
				if(y == 0) {	
					gtk_label_set_text(GTK_LABEL(structlabel->label21), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label22), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label23), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label24), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label25), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label26), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label27), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label28),"");
					gtk_label_set_text(GTK_LABEL(structlabel->label29),"");
					y++;
				}
				if(y == 1) {	
					gtk_label_set_text(GTK_LABEL(structlabel->label31), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label32), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label33), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label34), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label35), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label36), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label37), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label38),"");
					gtk_label_set_text(GTK_LABEL(structlabel->label39),"");
					y++;				
				}
				if(y == 2) {	
					gtk_label_set_text(GTK_LABEL(structlabel->label41), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label42), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label43), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label44), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label45), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label46), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label47), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label48),"");
					gtk_label_set_text(GTK_LABEL(structlabel->label49),"");
					y++;
				}
				if(y == 3) {	
					gtk_label_set_text(GTK_LABEL(structlabel->label51), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label52), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label53), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label54), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label55), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label56), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label57), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label58),"");
					gtk_label_set_text(GTK_LABEL(structlabel->label59),"");
					y++;
				}
				if(y == 4) {	
					gtk_label_set_text(GTK_LABEL(structlabel->label61), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label62), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label63), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label64), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label65), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label66), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label67), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label68),"");
					gtk_label_set_text(GTK_LABEL(structlabel->label69),"");
					y++;
				}
				if(y == 5) {	
					gtk_label_set_text(GTK_LABEL(structlabel->label71), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label72), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label73), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label74), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label75), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label76), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label77), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label78),"");
					gtk_label_set_text(GTK_LABEL(structlabel->label79),"");
					y++;
				}
				if(y == 6) {	
					gtk_label_set_text(GTK_LABEL(structlabel->label81), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label82), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label83), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label84), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label85), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label86), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label87), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label88),"");
					gtk_label_set_text(GTK_LABEL(structlabel->label89),"");
					y++;
				}
				if(y == 7) {	
					gtk_label_set_text(GTK_LABEL(structlabel->label91), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label92), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label93), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label94), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label95), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label96), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label97), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label98),"");
					gtk_label_set_text(GTK_LABEL(structlabel->label99),"");
					y++;
				}
				if(y == 8) {	
					gtk_label_set_text(GTK_LABEL(structlabel->label101), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label102), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label103), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label104), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label105), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label106), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label107), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label108),"");
					gtk_label_set_text(GTK_LABEL(structlabel->label109),"");
					y++;
				}
				if(y == 9) {	
					gtk_label_set_text(GTK_LABEL(structlabel->label111), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label112), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label113), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label114), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label115), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label116), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label117), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label118),"");
					gtk_label_set_text(GTK_LABEL(structlabel->label119),"");
					y++;
				}
				if(y == 10) {	
					gtk_label_set_text(GTK_LABEL(structlabel->label121), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label122), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label123), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label124), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label125), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label126), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label127), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label128),"");
					gtk_label_set_text(GTK_LABEL(structlabel->label129),"");					
					y++;
				}
				if(y == 11) {	
					gtk_label_set_text(GTK_LABEL(structlabel->label131), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label132), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label133), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label134), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label135), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label136), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label137), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label138),"");
					gtk_label_set_text(GTK_LABEL(structlabel->label139),"");
					y++;
				}
				if(y == 12) {	
					gtk_label_set_text(GTK_LABEL(structlabel->label141), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label142), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label143), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label144), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label145), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label146), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label147), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label148),"");
					gtk_label_set_text(GTK_LABEL(structlabel->label149),"");
					y++;
				}
				if(y == 13) {	
					gtk_label_set_text(GTK_LABEL(structlabel->label151), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label152), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label153), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label154), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label155), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label156), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label157), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label158),"");
					gtk_label_set_text(GTK_LABEL(structlabel->label159),"");
					y++;
				}
				if(y == 14) {	
					gtk_label_set_text(GTK_LABEL(structlabel->label161), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label162), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label163), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label164), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label165), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label166), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label167), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label168),"");
					gtk_label_set_text(GTK_LABEL(structlabel->label169),"");
					y++;
					break;
				}
				break;	
			}
		}
		else if(feof(fp)){
			p = p - 15;
			break;
		}		
	}
	fclose(fp);
}


/*************************************************displays  contents of file containing details of students who had left hostel*/
static void prevleft(GtkWidget *widget,  Gc_label *structlabel){
	FILE *fp = fopen("studleave.txt","r+");
	int u=-1;
	int y=0;
	p = p - 15;
	while(1){
		fscanf(fp, "%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\n]\n", rec.mis,  rec.name, rec.address, rec.branch, rec.blockno, rec.mobileno, rec.emailid, rec.date, rec.leave);			/*reading of file and displaying it*/
		u++;
		if(p == u){
				u--;
			if(y == 0) {	
				gtk_label_set_text(GTK_LABEL(structlabel->label21), rec.mis);
				gtk_label_set_text(GTK_LABEL(structlabel->label22), rec.name);
				gtk_label_set_text(GTK_LABEL(structlabel->label23), rec.address);
				gtk_label_set_text(GTK_LABEL(structlabel->label24), rec.branch);
				gtk_label_set_text(GTK_LABEL(structlabel->label25), rec.blockno);
				gtk_label_set_text(GTK_LABEL(structlabel->label26), rec.mobileno);
				gtk_label_set_text(GTK_LABEL(structlabel->label27), rec.emailid);
				gtk_label_set_text(GTK_LABEL(structlabel->label28), rec.date);
				gtk_label_set_text(GTK_LABEL(structlabel->label29), rec.leave);					
			}
			else if(y == 1) {	
				gtk_label_set_text(GTK_LABEL(structlabel->label31), rec.mis);
				gtk_label_set_text(GTK_LABEL(structlabel->label32), rec.name);
				gtk_label_set_text(GTK_LABEL(structlabel->label33), rec.address);
				gtk_label_set_text(GTK_LABEL(structlabel->label34), rec.branch);
				gtk_label_set_text(GTK_LABEL(structlabel->label35), rec.blockno);
				gtk_label_set_text(GTK_LABEL(structlabel->label36), rec.mobileno);
				gtk_label_set_text(GTK_LABEL(structlabel->label37), rec.emailid);
				gtk_label_set_text(GTK_LABEL(structlabel->label38), rec.date);
				gtk_label_set_text(GTK_LABEL(structlabel->label39), rec.leave);
			}
			else if(y == 2) {	
				gtk_label_set_text(GTK_LABEL(structlabel->label41), rec.mis);
				gtk_label_set_text(GTK_LABEL(structlabel->label42), rec.name);
				gtk_label_set_text(GTK_LABEL(structlabel->label43), rec.address);
				gtk_label_set_text(GTK_LABEL(structlabel->label44), rec.branch);
				gtk_label_set_text(GTK_LABEL(structlabel->label45), rec.blockno);
				gtk_label_set_text(GTK_LABEL(structlabel->label46), rec.mobileno);
				gtk_label_set_text(GTK_LABEL(structlabel->label47), rec.emailid);
				gtk_label_set_text(GTK_LABEL(structlabel->label48), rec.date);
				gtk_label_set_text(GTK_LABEL(structlabel->label49), rec.leave);
			}
			else if(y == 3) {	
				gtk_label_set_text(GTK_LABEL(structlabel->label51), rec.mis);
				gtk_label_set_text(GTK_LABEL(structlabel->label52), rec.name);
				gtk_label_set_text(GTK_LABEL(structlabel->label53), rec.address);
				gtk_label_set_text(GTK_LABEL(structlabel->label54), rec.branch);
				gtk_label_set_text(GTK_LABEL(structlabel->label55), rec.blockno);
				gtk_label_set_text(GTK_LABEL(structlabel->label56), rec.mobileno);
				gtk_label_set_text(GTK_LABEL(structlabel->label57), rec.emailid);
				gtk_label_set_text(GTK_LABEL(structlabel->label58), rec.date);
				gtk_label_set_text(GTK_LABEL(structlabel->label59), rec.leave);
			}
			else if(y == 4) {	
				gtk_label_set_text(GTK_LABEL(structlabel->label61), rec.mis);
				gtk_label_set_text(GTK_LABEL(structlabel->label62), rec.name);
				gtk_label_set_text(GTK_LABEL(structlabel->label63), rec.address);
				gtk_label_set_text(GTK_LABEL(structlabel->label64), rec.branch);
				gtk_label_set_text(GTK_LABEL(structlabel->label65), rec.blockno);
				gtk_label_set_text(GTK_LABEL(structlabel->label66), rec.mobileno);
				gtk_label_set_text(GTK_LABEL(structlabel->label67), rec.emailid);
				gtk_label_set_text(GTK_LABEL(structlabel->label68), rec.date);
				gtk_label_set_text(GTK_LABEL(structlabel->label69), rec.leave);
			}
			else if(y == 5) {	
				gtk_label_set_text(GTK_LABEL(structlabel->label71), rec.mis);
				gtk_label_set_text(GTK_LABEL(structlabel->label72), rec.name);
				gtk_label_set_text(GTK_LABEL(structlabel->label73), rec.address);
				gtk_label_set_text(GTK_LABEL(structlabel->label74), rec.branch);
				gtk_label_set_text(GTK_LABEL(structlabel->label75), rec.blockno);
				gtk_label_set_text(GTK_LABEL(structlabel->label76), rec.mobileno);
				gtk_label_set_text(GTK_LABEL(structlabel->label77), rec.emailid);
				gtk_label_set_text(GTK_LABEL(structlabel->label78), rec.date);
				gtk_label_set_text(GTK_LABEL(structlabel->label79), rec.leave);
			}
			else if(y == 6) {	
				gtk_label_set_text(GTK_LABEL(structlabel->label81), rec.mis);
				gtk_label_set_text(GTK_LABEL(structlabel->label82), rec.name);
				gtk_label_set_text(GTK_LABEL(structlabel->label83), rec.address);
				gtk_label_set_text(GTK_LABEL(structlabel->label84), rec.branch);
				gtk_label_set_text(GTK_LABEL(structlabel->label85), rec.blockno);
				gtk_label_set_text(GTK_LABEL(structlabel->label86), rec.mobileno);
				gtk_label_set_text(GTK_LABEL(structlabel->label87), rec.emailid);
				gtk_label_set_text(GTK_LABEL(structlabel->label88), rec.date);
				gtk_label_set_text(GTK_LABEL(structlabel->label89), rec.leave);
			}
			else if(y == 7) {	
				gtk_label_set_text(GTK_LABEL(structlabel->label91), rec.mis);
				gtk_label_set_text(GTK_LABEL(structlabel->label92), rec.name);
				gtk_label_set_text(GTK_LABEL(structlabel->label93), rec.address);
				gtk_label_set_text(GTK_LABEL(structlabel->label94), rec.branch);
				gtk_label_set_text(GTK_LABEL(structlabel->label95), rec.blockno);
				gtk_label_set_text(GTK_LABEL(structlabel->label96), rec.mobileno);
				gtk_label_set_text(GTK_LABEL(structlabel->label97), rec.emailid);
				gtk_label_set_text(GTK_LABEL(structlabel->label98), rec.date);
				gtk_label_set_text(GTK_LABEL(structlabel->label99), rec.leave);
			}
			else if(y == 8) {	
				gtk_label_set_text(GTK_LABEL(structlabel->label101), rec.mis);
				gtk_label_set_text(GTK_LABEL(structlabel->label102), rec.name);
				gtk_label_set_text(GTK_LABEL(structlabel->label103), rec.address);
				gtk_label_set_text(GTK_LABEL(structlabel->label104), rec.branch);
				gtk_label_set_text(GTK_LABEL(structlabel->label105), rec.blockno);
				gtk_label_set_text(GTK_LABEL(structlabel->label106), rec.mobileno);
				gtk_label_set_text(GTK_LABEL(structlabel->label107), rec.emailid);
				gtk_label_set_text(GTK_LABEL(structlabel->label108), rec.date);
				gtk_label_set_text(GTK_LABEL(structlabel->label109), rec.leave);
			}
			else if(y == 9) {	
				gtk_label_set_text(GTK_LABEL(structlabel->label111), rec.mis);
				gtk_label_set_text(GTK_LABEL(structlabel->label112), rec.name);
				gtk_label_set_text(GTK_LABEL(structlabel->label113), rec.address);
				gtk_label_set_text(GTK_LABEL(structlabel->label114), rec.branch);
				gtk_label_set_text(GTK_LABEL(structlabel->label115), rec.blockno);
				gtk_label_set_text(GTK_LABEL(structlabel->label116), rec.mobileno);
				gtk_label_set_text(GTK_LABEL(structlabel->label117), rec.emailid);
				gtk_label_set_text(GTK_LABEL(structlabel->label118), rec.date);
				gtk_label_set_text(GTK_LABEL(structlabel->label119), rec.leave);
			}
			else if(y == 10) {	
				gtk_label_set_text(GTK_LABEL(structlabel->label121), rec.mis);
				gtk_label_set_text(GTK_LABEL(structlabel->label122), rec.name);
				gtk_label_set_text(GTK_LABEL(structlabel->label123), rec.address);
				gtk_label_set_text(GTK_LABEL(structlabel->label124), rec.branch);
				gtk_label_set_text(GTK_LABEL(structlabel->label125), rec.blockno);
				gtk_label_set_text(GTK_LABEL(structlabel->label126), rec.mobileno);
				gtk_label_set_text(GTK_LABEL(structlabel->label127), rec.emailid);
				gtk_label_set_text(GTK_LABEL(structlabel->label128), rec.date);
				gtk_label_set_text(GTK_LABEL(structlabel->label129), rec.leave);
			}
			else if(y == 11) {	
				gtk_label_set_text(GTK_LABEL(structlabel->label131), rec.mis);
				gtk_label_set_text(GTK_LABEL(structlabel->label132), rec.name);
				gtk_label_set_text(GTK_LABEL(structlabel->label133), rec.address);
				gtk_label_set_text(GTK_LABEL(structlabel->label134), rec.branch);
				gtk_label_set_text(GTK_LABEL(structlabel->label135), rec.blockno);
				gtk_label_set_text(GTK_LABEL(structlabel->label136), rec.mobileno);
				gtk_label_set_text(GTK_LABEL(structlabel->label137), rec.emailid);
				gtk_label_set_text(GTK_LABEL(structlabel->label138), rec.date);
				gtk_label_set_text(GTK_LABEL(structlabel->label139), rec.leave);
			}
			else if(y == 12) {	
				gtk_label_set_text(GTK_LABEL(structlabel->label141), rec.mis);
				gtk_label_set_text(GTK_LABEL(structlabel->label142), rec.name);
				gtk_label_set_text(GTK_LABEL(structlabel->label143), rec.address);
				gtk_label_set_text(GTK_LABEL(structlabel->label144), rec.branch);
				gtk_label_set_text(GTK_LABEL(structlabel->label145), rec.blockno);
				gtk_label_set_text(GTK_LABEL(structlabel->label146), rec.mobileno);
				gtk_label_set_text(GTK_LABEL(structlabel->label147), rec.emailid);
				gtk_label_set_text(GTK_LABEL(structlabel->label148), rec.date);
				gtk_label_set_text(GTK_LABEL(structlabel->label149), rec.leave);
			}
			else if(y == 13) {	
				gtk_label_set_text(GTK_LABEL(structlabel->label151), rec.mis);
				gtk_label_set_text(GTK_LABEL(structlabel->label152), rec.name);
				gtk_label_set_text(GTK_LABEL(structlabel->label153), rec.address);
				gtk_label_set_text(GTK_LABEL(structlabel->label154), rec.branch);
				gtk_label_set_text(GTK_LABEL(structlabel->label155), rec.blockno);
				gtk_label_set_text(GTK_LABEL(structlabel->label156), rec.mobileno);
				gtk_label_set_text(GTK_LABEL(structlabel->label157), rec.emailid);
				gtk_label_set_text(GTK_LABEL(structlabel->label158), rec.date);
				gtk_label_set_text(GTK_LABEL(structlabel->label159), rec.leave);
			}
			else if(y == 14) {	
				gtk_label_set_text(GTK_LABEL(structlabel->label161), rec.mis);
				gtk_label_set_text(GTK_LABEL(structlabel->label162), rec.name);
				gtk_label_set_text(GTK_LABEL(structlabel->label163), rec.address);
				gtk_label_set_text(GTK_LABEL(structlabel->label164), rec.branch);
				gtk_label_set_text(GTK_LABEL(structlabel->label165), rec.blockno);
				gtk_label_set_text(GTK_LABEL(structlabel->label166), rec.mobileno);
				gtk_label_set_text(GTK_LABEL(structlabel->label167), rec.emailid);
				gtk_label_set_text(GTK_LABEL(structlabel->label168), rec.date);
				gtk_label_set_text(GTK_LABEL(structlabel->label169), rec.leave);
			}
			y++;
			if(feof(fp)){			/*if end of file founds then set all labels to null*/
				if(y == 0) {	
					gtk_label_set_text(GTK_LABEL(structlabel->label21), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label22), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label23), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label24), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label25), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label26), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label27), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label28),"");
					gtk_label_set_text(GTK_LABEL(structlabel->label29),"");
					y++;
				}
				if(y == 1) {	
					gtk_label_set_text(GTK_LABEL(structlabel->label31), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label32), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label33), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label34), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label35), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label36), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label37), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label38),"");
					gtk_label_set_text(GTK_LABEL(structlabel->label39),"");
					y++;				
				}
				if(y == 2) {	
					gtk_label_set_text(GTK_LABEL(structlabel->label41), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label42), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label43), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label44), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label45), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label46), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label47), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label48),"");
					gtk_label_set_text(GTK_LABEL(structlabel->label49),"");
					y++;
				}
				if(y == 3) {	
					gtk_label_set_text(GTK_LABEL(structlabel->label51), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label52), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label53), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label54), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label55), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label56), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label57), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label58),"");
					gtk_label_set_text(GTK_LABEL(structlabel->label59),"");
					y++;
				}
				if(y == 4) {	
					gtk_label_set_text(GTK_LABEL(structlabel->label61), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label62), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label63), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label64), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label65), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label66), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label67), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label68),"");
					gtk_label_set_text(GTK_LABEL(structlabel->label69),"");
					y++;
				}
				if(y == 5) {	
					gtk_label_set_text(GTK_LABEL(structlabel->label71), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label72), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label73), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label74), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label75), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label76), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label77), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label78),"");
					gtk_label_set_text(GTK_LABEL(structlabel->label79),"");
					y++;
				}
				if(y == 6) {	
					gtk_label_set_text(GTK_LABEL(structlabel->label81), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label82), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label83), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label84), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label85), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label86), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label87), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label88),"");
					gtk_label_set_text(GTK_LABEL(structlabel->label89),"");
					y++;
				}
				if(y == 7) {	
					gtk_label_set_text(GTK_LABEL(structlabel->label91), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label92), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label93), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label94), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label95), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label96), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label97), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label98),"");
					gtk_label_set_text(GTK_LABEL(structlabel->label99),"");
					y++;
				}
				if(y == 8) {	
					gtk_label_set_text(GTK_LABEL(structlabel->label101), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label102), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label103), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label104), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label105), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label106), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label107), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label108),"");
					gtk_label_set_text(GTK_LABEL(structlabel->label109),"");
					y++;
				}
				if(y == 9) {	
					gtk_label_set_text(GTK_LABEL(structlabel->label111), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label112), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label113), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label114), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label115), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label116), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label117), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label118),"");
					gtk_label_set_text(GTK_LABEL(structlabel->label119),"");
					y++;
				}
				if(y == 10) {	
					gtk_label_set_text(GTK_LABEL(structlabel->label121), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label122), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label123), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label124), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label125), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label126), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label127), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label128),"");
					gtk_label_set_text(GTK_LABEL(structlabel->label129),"");					
					y++;
				}
				if(y == 11) {	
					gtk_label_set_text(GTK_LABEL(structlabel->label131), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label132), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label133), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label134), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label135), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label136), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label137), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label138),"");
					gtk_label_set_text(GTK_LABEL(structlabel->label139),"");
					y++;
				}
				if(y == 12) {	
					gtk_label_set_text(GTK_LABEL(structlabel->label141), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label142), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label143), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label144), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label145), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label146), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label147), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label148),"");
					gtk_label_set_text(GTK_LABEL(structlabel->label149),"");
					y++;
				}
				if(y == 13) {	
					gtk_label_set_text(GTK_LABEL(structlabel->label151), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label152), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label153), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label154), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label155), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label156), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label157), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label158),"");
					gtk_label_set_text(GTK_LABEL(structlabel->label159),"");
					y++;
				}
				if(y == 14) {	
					gtk_label_set_text(GTK_LABEL(structlabel->label161), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label162), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label163), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label164), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label165), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label166), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label167), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label168),"");
					gtk_label_set_text(GTK_LABEL(structlabel->label169),"");
					y++;
					break;
				}
				break;	
			}
		}
		else if(feof(fp)){
			p = p + 15;
			break;
		}		
	}
	fclose(fp);
}


/**********************************************************displays contents of file containing details of students living in hostel*/
static void prev(GtkWidget *widget,  Gc_label *user_data){
	FILE *fp = fopen("studata.txt","r+");
	int u=-1;
	int y=0;
	p = p - 15;
	while(1){                                                             
		fscanf(fp, "%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\n]\n", rec.mis,  rec.name, rec.address, rec.branch, rec.blockno, rec.mobileno, rec.emailid, rec.date);                          /*reading of file and displaying contents on frame/window*/
		u++;
		if(p == u){
			u--;
			if(y == 0) {	
				gtk_label_set_text(GTK_LABEL(user_data->label21), rec.mis);
				gtk_label_set_text(GTK_LABEL(user_data->label22), rec.name);
				gtk_label_set_text(GTK_LABEL(user_data->label23), rec.address);
				gtk_label_set_text(GTK_LABEL(user_data->label24), rec.branch);
				gtk_label_set_text(GTK_LABEL(user_data->label25), rec.blockno);
				gtk_label_set_text(GTK_LABEL(user_data->label26), rec.mobileno);
				gtk_label_set_text(GTK_LABEL(user_data->label27), rec.emailid);
			}
			else if(y == 1) {	
				gtk_label_set_text(GTK_LABEL(user_data->label31), rec.mis);
				gtk_label_set_text(GTK_LABEL(user_data->label32), rec.name);
				gtk_label_set_text(GTK_LABEL(user_data->label33), rec.address);
				gtk_label_set_text(GTK_LABEL(user_data->label34), rec.branch);
				gtk_label_set_text(GTK_LABEL(user_data->label35), rec.blockno);
				gtk_label_set_text(GTK_LABEL(user_data->label36), rec.mobileno);
				gtk_label_set_text(GTK_LABEL(user_data->label37), rec.emailid);
			}
			else if(y == 2) {	
				gtk_label_set_text(GTK_LABEL(user_data->label41), rec.mis);
				gtk_label_set_text(GTK_LABEL(user_data->label42), rec.name);
				gtk_label_set_text(GTK_LABEL(user_data->label43), rec.address);
				gtk_label_set_text(GTK_LABEL(user_data->label44), rec.branch);
				gtk_label_set_text(GTK_LABEL(user_data->label45), rec.blockno);
				gtk_label_set_text(GTK_LABEL(user_data->label46), rec.mobileno);
				gtk_label_set_text(GTK_LABEL(user_data->label47), rec.emailid);
			}
			else if(y == 3) {	
				gtk_label_set_text(GTK_LABEL(user_data->label51), rec.mis);
				gtk_label_set_text(GTK_LABEL(user_data->label52), rec.name);
				gtk_label_set_text(GTK_LABEL(user_data->label53), rec.address);
				gtk_label_set_text(GTK_LABEL(user_data->label54), rec.branch);
				gtk_label_set_text(GTK_LABEL(user_data->label55), rec.blockno);
				gtk_label_set_text(GTK_LABEL(user_data->label56), rec.mobileno);
				gtk_label_set_text(GTK_LABEL(user_data->label57), rec.emailid);
			}
			else if(y == 4) {	
				gtk_label_set_text(GTK_LABEL(user_data->label61), rec.mis);
				gtk_label_set_text(GTK_LABEL(user_data->label62), rec.name);
				gtk_label_set_text(GTK_LABEL(user_data->label63), rec.address);
				gtk_label_set_text(GTK_LABEL(user_data->label64), rec.branch);
				gtk_label_set_text(GTK_LABEL(user_data->label65), rec.blockno);
				gtk_label_set_text(GTK_LABEL(user_data->label66), rec.mobileno);
				gtk_label_set_text(GTK_LABEL(user_data->label67), rec.emailid);
			}
			else if(y == 5) {	
				gtk_label_set_text(GTK_LABEL(user_data->label71), rec.mis);
				gtk_label_set_text(GTK_LABEL(user_data->label72), rec.name);
				gtk_label_set_text(GTK_LABEL(user_data->label73), rec.address);
				gtk_label_set_text(GTK_LABEL(user_data->label74), rec.branch);
				gtk_label_set_text(GTK_LABEL(user_data->label75), rec.blockno);
				gtk_label_set_text(GTK_LABEL(user_data->label76), rec.mobileno);
				gtk_label_set_text(GTK_LABEL(user_data->label77), rec.emailid);
			}
			else if(y == 6) {	
				gtk_label_set_text(GTK_LABEL(user_data->label81), rec.mis);
				gtk_label_set_text(GTK_LABEL(user_data->label82), rec.name);
				gtk_label_set_text(GTK_LABEL(user_data->label83), rec.address);
				gtk_label_set_text(GTK_LABEL(user_data->label84), rec.branch);
				gtk_label_set_text(GTK_LABEL(user_data->label85), rec.blockno);
				gtk_label_set_text(GTK_LABEL(user_data->label86), rec.mobileno);
				gtk_label_set_text(GTK_LABEL(user_data->label87), rec.emailid);
			}
			else if(y == 7) {	
				gtk_label_set_text(GTK_LABEL(user_data->label91), rec.mis);
				gtk_label_set_text(GTK_LABEL(user_data->label92), rec.name);
				gtk_label_set_text(GTK_LABEL(user_data->label93), rec.address);
				gtk_label_set_text(GTK_LABEL(user_data->label94), rec.branch);
				gtk_label_set_text(GTK_LABEL(user_data->label95), rec.blockno);
				gtk_label_set_text(GTK_LABEL(user_data->label96), rec.mobileno);
				gtk_label_set_text(GTK_LABEL(user_data->label97), rec.emailid);
			}
			else if(y == 8) {	
				gtk_label_set_text(GTK_LABEL(user_data->label101), rec.mis);
				gtk_label_set_text(GTK_LABEL(user_data->label102), rec.name);
				gtk_label_set_text(GTK_LABEL(user_data->label103), rec.address);
				gtk_label_set_text(GTK_LABEL(user_data->label104), rec.branch);
				gtk_label_set_text(GTK_LABEL(user_data->label105), rec.blockno);
				gtk_label_set_text(GTK_LABEL(user_data->label106), rec.mobileno);
				gtk_label_set_text(GTK_LABEL(user_data->label107), rec.emailid);
			}
			else if(y == 9) {	
				gtk_label_set_text(GTK_LABEL(user_data->label111), rec.mis);
				gtk_label_set_text(GTK_LABEL(user_data->label112), rec.name);
				gtk_label_set_text(GTK_LABEL(user_data->label113), rec.address);
				gtk_label_set_text(GTK_LABEL(user_data->label114), rec.branch);
				gtk_label_set_text(GTK_LABEL(user_data->label115), rec.blockno);
				gtk_label_set_text(GTK_LABEL(user_data->label116), rec.mobileno);
				gtk_label_set_text(GTK_LABEL(user_data->label117), rec.emailid);
			}
			else if(y == 10) {	
				gtk_label_set_text(GTK_LABEL(user_data->label121), rec.mis);
				gtk_label_set_text(GTK_LABEL(user_data->label122), rec.name);
				gtk_label_set_text(GTK_LABEL(user_data->label123), rec.address);
				gtk_label_set_text(GTK_LABEL(user_data->label124), rec.branch);
				gtk_label_set_text(GTK_LABEL(user_data->label125), rec.blockno);
				gtk_label_set_text(GTK_LABEL(user_data->label126), rec.mobileno);
				gtk_label_set_text(GTK_LABEL(user_data->label127), rec.emailid);
			}
			else if(y == 11) {	
				gtk_label_set_text(GTK_LABEL(user_data->label131), rec.mis);
				gtk_label_set_text(GTK_LABEL(user_data->label132), rec.name);
				gtk_label_set_text(GTK_LABEL(user_data->label133), rec.address);
				gtk_label_set_text(GTK_LABEL(user_data->label134), rec.branch);
				gtk_label_set_text(GTK_LABEL(user_data->label135), rec.blockno);
				gtk_label_set_text(GTK_LABEL(user_data->label136), rec.mobileno);
				gtk_label_set_text(GTK_LABEL(user_data->label137), rec.emailid);
			}
			else if(y == 12) {	
				gtk_label_set_text(GTK_LABEL(user_data->label141), rec.mis);
				gtk_label_set_text(GTK_LABEL(user_data->label142), rec.name);
				gtk_label_set_text(GTK_LABEL(user_data->label143), rec.address);
				gtk_label_set_text(GTK_LABEL(user_data->label144), rec.branch);
				gtk_label_set_text(GTK_LABEL(user_data->label145), rec.blockno);
				gtk_label_set_text(GTK_LABEL(user_data->label146), rec.mobileno);
				gtk_label_set_text(GTK_LABEL(user_data->label147), rec.emailid);
			}
			else if(y == 13) {	
				gtk_label_set_text(GTK_LABEL(user_data->label151), rec.mis);
				gtk_label_set_text(GTK_LABEL(user_data->label152), rec.name);
				gtk_label_set_text(GTK_LABEL(user_data->label153), rec.address);
				gtk_label_set_text(GTK_LABEL(user_data->label154), rec.branch);
				gtk_label_set_text(GTK_LABEL(user_data->label155), rec.blockno);
				gtk_label_set_text(GTK_LABEL(user_data->label156), rec.mobileno);
				gtk_label_set_text(GTK_LABEL(user_data->label157), rec.emailid);
			}
			else if(y == 14) {	
				gtk_label_set_text(GTK_LABEL(user_data->label161), rec.mis);
				gtk_label_set_text(GTK_LABEL(user_data->label162), rec.name);
				gtk_label_set_text(GTK_LABEL(user_data->label163), rec.address);
				gtk_label_set_text(GTK_LABEL(user_data->label164), rec.branch);
				gtk_label_set_text(GTK_LABEL(user_data->label165), rec.blockno);
				gtk_label_set_text(GTK_LABEL(user_data->label166), rec.mobileno);
				gtk_label_set_text(GTK_LABEL(user_data->label167), rec.emailid);
			}
			y++;
			if(feof(fp)){					/*if ends of file founds then set all labels to null*/
				if(y == 0) {	
					gtk_label_set_text(GTK_LABEL(user_data->label21), "");
					gtk_label_set_text(GTK_LABEL(user_data->label22), "");
					gtk_label_set_text(GTK_LABEL(user_data->label23), "");
					gtk_label_set_text(GTK_LABEL(user_data->label24), "");
					gtk_label_set_text(GTK_LABEL(user_data->label25), "");
					gtk_label_set_text(GTK_LABEL(user_data->label26), "");
					gtk_label_set_text(GTK_LABEL(user_data->label27), "");
					y++;
				}
				if(y == 1) {	
					gtk_label_set_text(GTK_LABEL(user_data->label31), "");
					gtk_label_set_text(GTK_LABEL(user_data->label32), "");
					gtk_label_set_text(GTK_LABEL(user_data->label33), "");
					gtk_label_set_text(GTK_LABEL(user_data->label34), "");
					gtk_label_set_text(GTK_LABEL(user_data->label35), "");
					gtk_label_set_text(GTK_LABEL(user_data->label36), "");
					gtk_label_set_text(GTK_LABEL(user_data->label37), "");
					y++;				
				}
				if(y == 2) {	
					gtk_label_set_text(GTK_LABEL(user_data->label41), "");
					gtk_label_set_text(GTK_LABEL(user_data->label42), "");
					gtk_label_set_text(GTK_LABEL(user_data->label43), "");
					gtk_label_set_text(GTK_LABEL(user_data->label44), "");
					gtk_label_set_text(GTK_LABEL(user_data->label45), "");
					gtk_label_set_text(GTK_LABEL(user_data->label46), "");
					gtk_label_set_text(GTK_LABEL(user_data->label47), "");
					y++;
				}
				if(y == 3) {	
					gtk_label_set_text(GTK_LABEL(user_data->label51), "");
					gtk_label_set_text(GTK_LABEL(user_data->label52), "");
					gtk_label_set_text(GTK_LABEL(user_data->label53), "");
					gtk_label_set_text(GTK_LABEL(user_data->label54), "");
					gtk_label_set_text(GTK_LABEL(user_data->label55), "");
					gtk_label_set_text(GTK_LABEL(user_data->label56), "");
					gtk_label_set_text(GTK_LABEL(user_data->label57), "");
					y++;
				}
				if(y == 4) {	
					gtk_label_set_text(GTK_LABEL(user_data->label61), "");
					gtk_label_set_text(GTK_LABEL(user_data->label62), "");
					gtk_label_set_text(GTK_LABEL(user_data->label63), "");
					gtk_label_set_text(GTK_LABEL(user_data->label64), "");
					gtk_label_set_text(GTK_LABEL(user_data->label65), "");
					gtk_label_set_text(GTK_LABEL(user_data->label66), "");
					gtk_label_set_text(GTK_LABEL(user_data->label67), "");
					y++;
				}
				if(y == 5) {	
					gtk_label_set_text(GTK_LABEL(user_data->label71), "");
					gtk_label_set_text(GTK_LABEL(user_data->label72), "");
					gtk_label_set_text(GTK_LABEL(user_data->label73), "");
					gtk_label_set_text(GTK_LABEL(user_data->label74), "");
					gtk_label_set_text(GTK_LABEL(user_data->label75), "");
					gtk_label_set_text(GTK_LABEL(user_data->label76), "");
					gtk_label_set_text(GTK_LABEL(user_data->label77), "");
					y++;
				}
				if(y == 6) {	
					gtk_label_set_text(GTK_LABEL(user_data->label81), "");
					gtk_label_set_text(GTK_LABEL(user_data->label82), "");
					gtk_label_set_text(GTK_LABEL(user_data->label83), "");
					gtk_label_set_text(GTK_LABEL(user_data->label84), "");
					gtk_label_set_text(GTK_LABEL(user_data->label85), "");
					gtk_label_set_text(GTK_LABEL(user_data->label86), "");
					gtk_label_set_text(GTK_LABEL(user_data->label87), "");
					y++;
				}
				if(y == 7) {	
					gtk_label_set_text(GTK_LABEL(user_data->label91), "");
					gtk_label_set_text(GTK_LABEL(user_data->label92), "");
					gtk_label_set_text(GTK_LABEL(user_data->label93), "");
					gtk_label_set_text(GTK_LABEL(user_data->label94), "");
					gtk_label_set_text(GTK_LABEL(user_data->label95), "");
					gtk_label_set_text(GTK_LABEL(user_data->label96), "");
					gtk_label_set_text(GTK_LABEL(user_data->label97), "");
					y++;
				}
				if(y == 8) {	
					gtk_label_set_text(GTK_LABEL(user_data->label101), "");
					gtk_label_set_text(GTK_LABEL(user_data->label102), "");
					gtk_label_set_text(GTK_LABEL(user_data->label103), "");
					gtk_label_set_text(GTK_LABEL(user_data->label104), "");
					gtk_label_set_text(GTK_LABEL(user_data->label105), "");
					gtk_label_set_text(GTK_LABEL(user_data->label106), "");
					gtk_label_set_text(GTK_LABEL(user_data->label107), "");
					y++;
				}
				if(y == 9) {	
					gtk_label_set_text(GTK_LABEL(user_data->label111), "");
					gtk_label_set_text(GTK_LABEL(user_data->label112), "");
					gtk_label_set_text(GTK_LABEL(user_data->label113), "");
					gtk_label_set_text(GTK_LABEL(user_data->label114), "");
					gtk_label_set_text(GTK_LABEL(user_data->label115), "");
					gtk_label_set_text(GTK_LABEL(user_data->label116), "");
					gtk_label_set_text(GTK_LABEL(user_data->label117), "");
					y++;
				}
				if(y == 10) {	
					gtk_label_set_text(GTK_LABEL(user_data->label121), "");
					gtk_label_set_text(GTK_LABEL(user_data->label122), "");
					gtk_label_set_text(GTK_LABEL(user_data->label123), "");
					gtk_label_set_text(GTK_LABEL(user_data->label124), "");
					gtk_label_set_text(GTK_LABEL(user_data->label125), "");
					gtk_label_set_text(GTK_LABEL(user_data->label126), "");
					gtk_label_set_text(GTK_LABEL(user_data->label127), "");
					y++;
				}
				if(y == 11) {	
					gtk_label_set_text(GTK_LABEL(user_data->label131), "");
					gtk_label_set_text(GTK_LABEL(user_data->label132), "");
					gtk_label_set_text(GTK_LABEL(user_data->label133), "");
					gtk_label_set_text(GTK_LABEL(user_data->label134), "");
					gtk_label_set_text(GTK_LABEL(user_data->label135), "");
					gtk_label_set_text(GTK_LABEL(user_data->label136), "");
					gtk_label_set_text(GTK_LABEL(user_data->label137), "");
					y++;
				}
				if(y == 12) {	
					gtk_label_set_text(GTK_LABEL(user_data->label141), "");
					gtk_label_set_text(GTK_LABEL(user_data->label142), "");
					gtk_label_set_text(GTK_LABEL(user_data->label143), "");
					gtk_label_set_text(GTK_LABEL(user_data->label144), "");
					gtk_label_set_text(GTK_LABEL(user_data->label145), "");
					gtk_label_set_text(GTK_LABEL(user_data->label146), "");
					gtk_label_set_text(GTK_LABEL(user_data->label147), "");
					y++;
				}
				if(y == 13) {	
					gtk_label_set_text(GTK_LABEL(user_data->label151), "");
					gtk_label_set_text(GTK_LABEL(user_data->label152), "");
					gtk_label_set_text(GTK_LABEL(user_data->label153), "");
					gtk_label_set_text(GTK_LABEL(user_data->label154), "");
					gtk_label_set_text(GTK_LABEL(user_data->label155), "");
					gtk_label_set_text(GTK_LABEL(user_data->label156), "");
					gtk_label_set_text(GTK_LABEL(user_data->label157), "");
					y++;
				}
				if(y == 14) {	
					gtk_label_set_text(GTK_LABEL(user_data->label161), "");
					gtk_label_set_text(GTK_LABEL(user_data->label162), "");
					gtk_label_set_text(GTK_LABEL(user_data->label163), "");
					gtk_label_set_text(GTK_LABEL(user_data->label164), "");
					gtk_label_set_text(GTK_LABEL(user_data->label165), "");
					gtk_label_set_text(GTK_LABEL(user_data->label166), "");
					gtk_label_set_text(GTK_LABEL(user_data->label167), "");
					y++;
					break;
				}
				break;	
			}
		}
		else if(feof(fp)){
			p = p + 15;
			break;
		}		
	}
	fclose(fp);
}

/***********************************************************displays contents of file containing details of students living in hostel*/
static void previous(GtkWidget *widget,  Gc_label *structlabel){
	FILE *fp = fopen("studata.txt","r+");
	int u=-1;
	int y=0;
	p = p - 15;
	while(1){
		fscanf(fp, "%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\n]\n", rec.mis,  rec.name, rec.address, rec.branch, rec.blockno, rec.mobileno, rec.emailid, rec.date);			/*reading of file and displaying it*/
		u++;
		if(p == u){
			u--;
			if(y == 0) {	
				gtk_label_set_text(GTK_LABEL(structlabel->label21), rec.mis);
				gtk_label_set_text(GTK_LABEL(structlabel->label22), rec.name);
				gtk_label_set_text(GTK_LABEL(structlabel->label23), rec.address);
				gtk_label_set_text(GTK_LABEL(structlabel->label24), rec.branch);
				gtk_label_set_text(GTK_LABEL(structlabel->label25), rec.blockno);
				gtk_label_set_text(GTK_LABEL(structlabel->label26), rec.mobileno);
				gtk_label_set_text(GTK_LABEL(structlabel->label27), rec.emailid);
				gtk_label_set_text(GTK_LABEL(structlabel->label28), rec.date);				
			}
			else if(y == 1) {	
				gtk_label_set_text(GTK_LABEL(structlabel->label31), rec.mis);
				gtk_label_set_text(GTK_LABEL(structlabel->label32), rec.name);
				gtk_label_set_text(GTK_LABEL(structlabel->label33), rec.address);
				gtk_label_set_text(GTK_LABEL(structlabel->label34), rec.branch);
				gtk_label_set_text(GTK_LABEL(structlabel->label35), rec.blockno);
				gtk_label_set_text(GTK_LABEL(structlabel->label36), rec.mobileno);
				gtk_label_set_text(GTK_LABEL(structlabel->label37), rec.emailid);
				gtk_label_set_text(GTK_LABEL(structlabel->label38), rec.date);
			}
			else if(y == 2) {	
				gtk_label_set_text(GTK_LABEL(structlabel->label41), rec.mis);
				gtk_label_set_text(GTK_LABEL(structlabel->label42), rec.name);
				gtk_label_set_text(GTK_LABEL(structlabel->label43), rec.address);
				gtk_label_set_text(GTK_LABEL(structlabel->label44), rec.branch);
				gtk_label_set_text(GTK_LABEL(structlabel->label45), rec.blockno);
				gtk_label_set_text(GTK_LABEL(structlabel->label46), rec.mobileno);
				gtk_label_set_text(GTK_LABEL(structlabel->label47), rec.emailid);
				gtk_label_set_text(GTK_LABEL(structlabel->label48), rec.date);
			}
			else if(y == 3) {	
				gtk_label_set_text(GTK_LABEL(structlabel->label51), rec.mis);
				gtk_label_set_text(GTK_LABEL(structlabel->label52), rec.name);
				gtk_label_set_text(GTK_LABEL(structlabel->label53), rec.address);
				gtk_label_set_text(GTK_LABEL(structlabel->label54), rec.branch);
				gtk_label_set_text(GTK_LABEL(structlabel->label55), rec.blockno);
				gtk_label_set_text(GTK_LABEL(structlabel->label56), rec.mobileno);
				gtk_label_set_text(GTK_LABEL(structlabel->label57), rec.emailid);
				gtk_label_set_text(GTK_LABEL(structlabel->label58), rec.date);
			}
			else if(y == 4) {	
				gtk_label_set_text(GTK_LABEL(structlabel->label61), rec.mis);
				gtk_label_set_text(GTK_LABEL(structlabel->label62), rec.name);
				gtk_label_set_text(GTK_LABEL(structlabel->label63), rec.address);
				gtk_label_set_text(GTK_LABEL(structlabel->label64), rec.branch);
				gtk_label_set_text(GTK_LABEL(structlabel->label65), rec.blockno);
				gtk_label_set_text(GTK_LABEL(structlabel->label66), rec.mobileno);
				gtk_label_set_text(GTK_LABEL(structlabel->label67), rec.emailid);
				gtk_label_set_text(GTK_LABEL(structlabel->label68), rec.date);
			}
			else if(y == 5) {	
				gtk_label_set_text(GTK_LABEL(structlabel->label71), rec.mis);
				gtk_label_set_text(GTK_LABEL(structlabel->label72), rec.name);
				gtk_label_set_text(GTK_LABEL(structlabel->label73), rec.address);
				gtk_label_set_text(GTK_LABEL(structlabel->label74), rec.branch);
				gtk_label_set_text(GTK_LABEL(structlabel->label75), rec.blockno);
				gtk_label_set_text(GTK_LABEL(structlabel->label76), rec.mobileno);
				gtk_label_set_text(GTK_LABEL(structlabel->label77), rec.emailid);
				gtk_label_set_text(GTK_LABEL(structlabel->label78), rec.date);		
			}
			else if(y == 6) {	
				gtk_label_set_text(GTK_LABEL(structlabel->label81), rec.mis);
				gtk_label_set_text(GTK_LABEL(structlabel->label82), rec.name);
				gtk_label_set_text(GTK_LABEL(structlabel->label83), rec.address);
				gtk_label_set_text(GTK_LABEL(structlabel->label84), rec.branch);
				gtk_label_set_text(GTK_LABEL(structlabel->label85), rec.blockno);
				gtk_label_set_text(GTK_LABEL(structlabel->label86), rec.mobileno);
				gtk_label_set_text(GTK_LABEL(structlabel->label87), rec.emailid);
				gtk_label_set_text(GTK_LABEL(structlabel->label88), rec.date);
			}
			else if(y == 7) {	
				gtk_label_set_text(GTK_LABEL(structlabel->label91), rec.mis);
				gtk_label_set_text(GTK_LABEL(structlabel->label92), rec.name);
				gtk_label_set_text(GTK_LABEL(structlabel->label93), rec.address);
				gtk_label_set_text(GTK_LABEL(structlabel->label94), rec.branch);
				gtk_label_set_text(GTK_LABEL(structlabel->label95), rec.blockno);
				gtk_label_set_text(GTK_LABEL(structlabel->label96), rec.mobileno);
				gtk_label_set_text(GTK_LABEL(structlabel->label97), rec.emailid);
				gtk_label_set_text(GTK_LABEL(structlabel->label98), rec.date);
			}
			else if(y == 8) {	
				gtk_label_set_text(GTK_LABEL(structlabel->label101), rec.mis);
				gtk_label_set_text(GTK_LABEL(structlabel->label102), rec.name);
				gtk_label_set_text(GTK_LABEL(structlabel->label103), rec.address);
				gtk_label_set_text(GTK_LABEL(structlabel->label104), rec.branch);
				gtk_label_set_text(GTK_LABEL(structlabel->label105), rec.blockno);
				gtk_label_set_text(GTK_LABEL(structlabel->label106), rec.mobileno);
				gtk_label_set_text(GTK_LABEL(structlabel->label107), rec.emailid);
				gtk_label_set_text(GTK_LABEL(structlabel->label108), rec.date);
			}
			else if(y == 9) {	
				gtk_label_set_text(GTK_LABEL(structlabel->label111), rec.mis);
				gtk_label_set_text(GTK_LABEL(structlabel->label112), rec.name);
				gtk_label_set_text(GTK_LABEL(structlabel->label113), rec.address);
				gtk_label_set_text(GTK_LABEL(structlabel->label114), rec.branch);
				gtk_label_set_text(GTK_LABEL(structlabel->label115), rec.blockno);
				gtk_label_set_text(GTK_LABEL(structlabel->label116), rec.mobileno);
				gtk_label_set_text(GTK_LABEL(structlabel->label117), rec.emailid);
				gtk_label_set_text(GTK_LABEL(structlabel->label118), rec.date);
			}
			else if(y == 10) {	
				gtk_label_set_text(GTK_LABEL(structlabel->label121), rec.mis);
				gtk_label_set_text(GTK_LABEL(structlabel->label122), rec.name);
				gtk_label_set_text(GTK_LABEL(structlabel->label123), rec.address);
				gtk_label_set_text(GTK_LABEL(structlabel->label124), rec.branch);
				gtk_label_set_text(GTK_LABEL(structlabel->label125), rec.blockno);
				gtk_label_set_text(GTK_LABEL(structlabel->label126), rec.mobileno);
				gtk_label_set_text(GTK_LABEL(structlabel->label127), rec.emailid);
				gtk_label_set_text(GTK_LABEL(structlabel->label128), rec.date);
			}
			else if(y == 11) {	
				gtk_label_set_text(GTK_LABEL(structlabel->label131), rec.mis);
				gtk_label_set_text(GTK_LABEL(structlabel->label132), rec.name);
				gtk_label_set_text(GTK_LABEL(structlabel->label133), rec.address);
				gtk_label_set_text(GTK_LABEL(structlabel->label134), rec.branch);
				gtk_label_set_text(GTK_LABEL(structlabel->label135), rec.blockno);
				gtk_label_set_text(GTK_LABEL(structlabel->label136), rec.mobileno);
				gtk_label_set_text(GTK_LABEL(structlabel->label137), rec.emailid);
				gtk_label_set_text(GTK_LABEL(structlabel->label138), rec.date);
			}
			else if(y == 12) {	
				gtk_label_set_text(GTK_LABEL(structlabel->label141), rec.mis);
				gtk_label_set_text(GTK_LABEL(structlabel->label142), rec.name);
				gtk_label_set_text(GTK_LABEL(structlabel->label143), rec.address);
				gtk_label_set_text(GTK_LABEL(structlabel->label144), rec.branch);
				gtk_label_set_text(GTK_LABEL(structlabel->label145), rec.blockno);
				gtk_label_set_text(GTK_LABEL(structlabel->label146), rec.mobileno);
				gtk_label_set_text(GTK_LABEL(structlabel->label147), rec.emailid);
				gtk_label_set_text(GTK_LABEL(structlabel->label148), rec.date);
			}
			else if(y == 13) {	
				gtk_label_set_text(GTK_LABEL(structlabel->label151), rec.mis);
				gtk_label_set_text(GTK_LABEL(structlabel->label152), rec.name);
				gtk_label_set_text(GTK_LABEL(structlabel->label153), rec.address);
				gtk_label_set_text(GTK_LABEL(structlabel->label154), rec.branch);
				gtk_label_set_text(GTK_LABEL(structlabel->label155), rec.blockno);
				gtk_label_set_text(GTK_LABEL(structlabel->label156), rec.mobileno);
				gtk_label_set_text(GTK_LABEL(structlabel->label157), rec.emailid);
				gtk_label_set_text(GTK_LABEL(structlabel->label158), rec.date);
			}
			else if(y == 14) {	
				gtk_label_set_text(GTK_LABEL(structlabel->label161), rec.mis);
				gtk_label_set_text(GTK_LABEL(structlabel->label162), rec.name);
				gtk_label_set_text(GTK_LABEL(structlabel->label163), rec.address);
				gtk_label_set_text(GTK_LABEL(structlabel->label164), rec.branch);
				gtk_label_set_text(GTK_LABEL(structlabel->label165), rec.blockno);
				gtk_label_set_text(GTK_LABEL(structlabel->label166), rec.mobileno);
				gtk_label_set_text(GTK_LABEL(structlabel->label167), rec.emailid);
				gtk_label_set_text(GTK_LABEL(structlabel->label168), rec.date);
			}
			y++;
			if(feof(fp)){					/*if file ends then set all labels to null*/
				if(y == 0) {	
					gtk_label_set_text(GTK_LABEL(structlabel->label21), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label22), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label23), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label24), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label25), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label26), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label27), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label28),"");
					y++;
				}
				if(y == 1) {	
					gtk_label_set_text(GTK_LABEL(structlabel->label31), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label32), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label33), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label34), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label35), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label36), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label37), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label38),"");
					y++;				
				}
				if(y == 2) {	
					gtk_label_set_text(GTK_LABEL(structlabel->label41), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label42), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label43), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label44), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label45), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label46), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label47), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label48),"");
					y++;
				}
				if(y == 3) {	
					gtk_label_set_text(GTK_LABEL(structlabel->label51), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label52), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label53), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label54), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label55), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label56), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label57), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label58),"");
					y++;
				}
				if(y == 4) {	
					gtk_label_set_text(GTK_LABEL(structlabel->label61), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label62), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label63), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label64), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label65), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label66), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label67), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label68),"");
					y++;
				}
				if(y == 5) {	
					gtk_label_set_text(GTK_LABEL(structlabel->label71), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label72), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label73), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label74), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label75), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label76), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label77), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label78),"");
					y++;
				}
				if(y == 6) {	
					gtk_label_set_text(GTK_LABEL(structlabel->label81), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label82), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label83), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label84), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label85), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label86), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label87), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label88),"");
					y++;
				}
				if(y == 7) {	
					gtk_label_set_text(GTK_LABEL(structlabel->label91), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label92), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label93), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label94), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label95), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label96), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label97), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label98),"");
					y++;
				}
				if(y == 8) {	
					gtk_label_set_text(GTK_LABEL(structlabel->label101), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label102), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label103), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label104), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label105), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label106), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label107), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label108),"");
					y++;
				}
				if(y == 9) {	
					gtk_label_set_text(GTK_LABEL(structlabel->label111), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label112), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label113), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label114), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label115), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label116), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label117), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label118),"");
					y++;
				}
				if(y == 10) {	
					gtk_label_set_text(GTK_LABEL(structlabel->label121), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label122), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label123), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label124), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label125), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label126), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label127), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label128),"");
					y++;
				}
				if(y == 11) {	
					gtk_label_set_text(GTK_LABEL(structlabel->label131), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label132), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label133), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label134), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label135), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label136), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label137), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label138),"");
					y++;
				}
				if(y == 12) {	
					gtk_label_set_text(GTK_LABEL(structlabel->label141), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label142), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label143), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label144), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label145), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label146), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label147), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label148),"");
					y++;
				}
				if(y == 13) {	
					gtk_label_set_text(GTK_LABEL(structlabel->label151), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label152), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label153), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label154), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label155), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label156), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label157), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label158),"");
					y++;
				}
				if(y == 14) {	
					gtk_label_set_text(GTK_LABEL(structlabel->label161), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label162), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label163), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label164), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label165), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label166), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label167), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label168),"");
					y++;
					break;
				}
				break;	
			}
		}
		else if(feof(fp)){
			p = p + 15;
			break;
		}	
	}
	fclose(fp);
}


/************************************following methods and functions are used during quick deletion and updation of student details by enduser*/
static void dynamic_edit2(GtkWidget *widget,  Gc_label *user_data1){
	misno = atoi(gtk_label_get_text(GTK_LABEL(user_data1->label21)));
	gtk_entry_set_text(GTK_ENTRY(user_data1->ent1), gtk_label_get_text(GTK_LABEL(user_data1->label21)));
	gtk_entry_set_text(GTK_ENTRY(user_data1->ent2), gtk_label_get_text(GTK_LABEL(user_data1->label22)));
	gtk_entry_set_text(GTK_ENTRY(user_data1->ent3), gtk_label_get_text(GTK_LABEL(user_data1->label23)));
	gtk_entry_set_text(GTK_ENTRY(user_data1->ent4), gtk_label_get_text(GTK_LABEL(user_data1->label24)));
	gtk_entry_set_text(GTK_ENTRY(user_data1->ent5), gtk_label_get_text(GTK_LABEL(user_data1->label25)));
	gtk_entry_set_text(GTK_ENTRY(user_data1->ent6), gtk_label_get_text(GTK_LABEL(user_data1->label26)));
	gtk_entry_set_text(GTK_ENTRY(user_data1->ent7), gtk_label_get_text(GTK_LABEL(user_data1->label27)));	
}
static void dynamic_edit3(GtkWidget *widget,  Gc_label *user_data1){
	misno = atoi(gtk_label_get_text(GTK_LABEL(user_data1->label31)));
	gtk_entry_set_text(GTK_ENTRY(user_data1->ent1), gtk_label_get_text(GTK_LABEL(user_data1->label31)));
	gtk_entry_set_text(GTK_ENTRY(user_data1->ent2), gtk_label_get_text(GTK_LABEL(user_data1->label32)));
	gtk_entry_set_text(GTK_ENTRY(user_data1->ent3), gtk_label_get_text(GTK_LABEL(user_data1->label33)));
	gtk_entry_set_text(GTK_ENTRY(user_data1->ent4), gtk_label_get_text(GTK_LABEL(user_data1->label34)));
	gtk_entry_set_text(GTK_ENTRY(user_data1->ent5), gtk_label_get_text(GTK_LABEL(user_data1->label35)));
	gtk_entry_set_text(GTK_ENTRY(user_data1->ent6), gtk_label_get_text(GTK_LABEL(user_data1->label36)));
	gtk_entry_set_text(GTK_ENTRY(user_data1->ent7), gtk_label_get_text(GTK_LABEL(user_data1->label37)));	
}
static void dynamic_edit4(GtkWidget *widget,  Gc_label *user_data1){
	misno = atoi(gtk_label_get_text(GTK_LABEL(user_data1->label41)));
	gtk_entry_set_text(GTK_ENTRY(user_data1->ent1), gtk_label_get_text(GTK_LABEL(user_data1->label41)));
	gtk_entry_set_text(GTK_ENTRY(user_data1->ent2), gtk_label_get_text(GTK_LABEL(user_data1->label42)));
	gtk_entry_set_text(GTK_ENTRY(user_data1->ent3), gtk_label_get_text(GTK_LABEL(user_data1->label43)));
	gtk_entry_set_text(GTK_ENTRY(user_data1->ent4), gtk_label_get_text(GTK_LABEL(user_data1->label44)));
	gtk_entry_set_text(GTK_ENTRY(user_data1->ent5), gtk_label_get_text(GTK_LABEL(user_data1->label45)));
	gtk_entry_set_text(GTK_ENTRY(user_data1->ent6), gtk_label_get_text(GTK_LABEL(user_data1->label46)));
	gtk_entry_set_text(GTK_ENTRY(user_data1->ent7), gtk_label_get_text(GTK_LABEL(user_data1->label47)));	
}
static void dynamic_edit5(GtkWidget *widget,  Gc_label *user_data1){
	misno = atoi(gtk_label_get_text(GTK_LABEL(user_data1->label51)));
	gtk_entry_set_text(GTK_ENTRY(user_data1->ent1), gtk_label_get_text(GTK_LABEL(user_data1->label51)));
	gtk_entry_set_text(GTK_ENTRY(user_data1->ent2), gtk_label_get_text(GTK_LABEL(user_data1->label52)));
	gtk_entry_set_text(GTK_ENTRY(user_data1->ent3), gtk_label_get_text(GTK_LABEL(user_data1->label53)));
	gtk_entry_set_text(GTK_ENTRY(user_data1->ent4), gtk_label_get_text(GTK_LABEL(user_data1->label54)));
	gtk_entry_set_text(GTK_ENTRY(user_data1->ent5), gtk_label_get_text(GTK_LABEL(user_data1->label55)));
	gtk_entry_set_text(GTK_ENTRY(user_data1->ent6), gtk_label_get_text(GTK_LABEL(user_data1->label56)));
	gtk_entry_set_text(GTK_ENTRY(user_data1->ent7), gtk_label_get_text(GTK_LABEL(user_data1->label57)));	
}
static void dynamic_edit6(GtkWidget *widget,  Gc_label *user_data1){
	misno = atoi(gtk_label_get_text(GTK_LABEL(user_data1->label61)));
	gtk_entry_set_text(GTK_ENTRY(user_data1->ent1), gtk_label_get_text(GTK_LABEL(user_data1->label61)));
	gtk_entry_set_text(GTK_ENTRY(user_data1->ent2), gtk_label_get_text(GTK_LABEL(user_data1->label62)));
	gtk_entry_set_text(GTK_ENTRY(user_data1->ent3), gtk_label_get_text(GTK_LABEL(user_data1->label63)));
	gtk_entry_set_text(GTK_ENTRY(user_data1->ent4), gtk_label_get_text(GTK_LABEL(user_data1->label64)));
	gtk_entry_set_text(GTK_ENTRY(user_data1->ent5), gtk_label_get_text(GTK_LABEL(user_data1->label65)));
	gtk_entry_set_text(GTK_ENTRY(user_data1->ent6), gtk_label_get_text(GTK_LABEL(user_data1->label66)));
	gtk_entry_set_text(GTK_ENTRY(user_data1->ent7), gtk_label_get_text(GTK_LABEL(user_data1->label67)));	
}
static void dynamic_edit7(GtkWidget *widget,  Gc_label *user_data1){
	misno = atoi(gtk_label_get_text(GTK_LABEL(user_data1->label71)));
	gtk_entry_set_text(GTK_ENTRY(user_data1->ent1), gtk_label_get_text(GTK_LABEL(user_data1->label71)));
	gtk_entry_set_text(GTK_ENTRY(user_data1->ent2), gtk_label_get_text(GTK_LABEL(user_data1->label72)));
	gtk_entry_set_text(GTK_ENTRY(user_data1->ent3), gtk_label_get_text(GTK_LABEL(user_data1->label73)));
	gtk_entry_set_text(GTK_ENTRY(user_data1->ent4), gtk_label_get_text(GTK_LABEL(user_data1->label74)));
	gtk_entry_set_text(GTK_ENTRY(user_data1->ent5), gtk_label_get_text(GTK_LABEL(user_data1->label75)));
	gtk_entry_set_text(GTK_ENTRY(user_data1->ent6), gtk_label_get_text(GTK_LABEL(user_data1->label76)));
	gtk_entry_set_text(GTK_ENTRY(user_data1->ent7), gtk_label_get_text(GTK_LABEL(user_data1->label77)));	
}
static void dynamic_edit8(GtkWidget *widget,  Gc_label *user_data1){
	misno = atoi(gtk_label_get_text(GTK_LABEL(user_data1->label81)));
	gtk_entry_set_text(GTK_ENTRY(user_data1->ent1), gtk_label_get_text(GTK_LABEL(user_data1->label81)));
	gtk_entry_set_text(GTK_ENTRY(user_data1->ent2), gtk_label_get_text(GTK_LABEL(user_data1->label82)));
	gtk_entry_set_text(GTK_ENTRY(user_data1->ent3), gtk_label_get_text(GTK_LABEL(user_data1->label83)));
	gtk_entry_set_text(GTK_ENTRY(user_data1->ent4), gtk_label_get_text(GTK_LABEL(user_data1->label84)));
	gtk_entry_set_text(GTK_ENTRY(user_data1->ent5), gtk_label_get_text(GTK_LABEL(user_data1->label85)));
	gtk_entry_set_text(GTK_ENTRY(user_data1->ent6), gtk_label_get_text(GTK_LABEL(user_data1->label86)));
	gtk_entry_set_text(GTK_ENTRY(user_data1->ent7), gtk_label_get_text(GTK_LABEL(user_data1->label87)));	
}
static void dynamic_edit9(GtkWidget *widget,  Gc_label *user_data1){
	misno = atoi(gtk_label_get_text(GTK_LABEL(user_data1->label91)));
	gtk_entry_set_text(GTK_ENTRY(user_data1->ent1), gtk_label_get_text(GTK_LABEL(user_data1->label91)));
	gtk_entry_set_text(GTK_ENTRY(user_data1->ent2), gtk_label_get_text(GTK_LABEL(user_data1->label92)));
	gtk_entry_set_text(GTK_ENTRY(user_data1->ent3), gtk_label_get_text(GTK_LABEL(user_data1->label93)));
	gtk_entry_set_text(GTK_ENTRY(user_data1->ent4), gtk_label_get_text(GTK_LABEL(user_data1->label94)));
	gtk_entry_set_text(GTK_ENTRY(user_data1->ent5), gtk_label_get_text(GTK_LABEL(user_data1->label95)));
	gtk_entry_set_text(GTK_ENTRY(user_data1->ent6), gtk_label_get_text(GTK_LABEL(user_data1->label96)));
	gtk_entry_set_text(GTK_ENTRY(user_data1->ent7), gtk_label_get_text(GTK_LABEL(user_data1->label97)));	
}
static void dynamic_edit10(GtkWidget *widget,  Gc_label *user_data1){
	misno = atoi(gtk_label_get_text(GTK_LABEL(user_data1->label101)));
	gtk_entry_set_text(GTK_ENTRY(user_data1->ent1), gtk_label_get_text(GTK_LABEL(user_data1->label101)));
	gtk_entry_set_text(GTK_ENTRY(user_data1->ent2), gtk_label_get_text(GTK_LABEL(user_data1->label102)));
	gtk_entry_set_text(GTK_ENTRY(user_data1->ent3), gtk_label_get_text(GTK_LABEL(user_data1->label103)));
	gtk_entry_set_text(GTK_ENTRY(user_data1->ent4), gtk_label_get_text(GTK_LABEL(user_data1->label104)));
	gtk_entry_set_text(GTK_ENTRY(user_data1->ent5), gtk_label_get_text(GTK_LABEL(user_data1->label105)));
	gtk_entry_set_text(GTK_ENTRY(user_data1->ent6), gtk_label_get_text(GTK_LABEL(user_data1->label106)));
	gtk_entry_set_text(GTK_ENTRY(user_data1->ent7), gtk_label_get_text(GTK_LABEL(user_data1->label107)));	
}
static void dynamic_edit11(GtkWidget *widget,  Gc_label *user_data1){
	misno = atoi(gtk_label_get_text(GTK_LABEL(user_data1->label111)));
	gtk_entry_set_text(GTK_ENTRY(user_data1->ent1), gtk_label_get_text(GTK_LABEL(user_data1->label111)));
	gtk_entry_set_text(GTK_ENTRY(user_data1->ent2), gtk_label_get_text(GTK_LABEL(user_data1->label112)));
	gtk_entry_set_text(GTK_ENTRY(user_data1->ent3), gtk_label_get_text(GTK_LABEL(user_data1->label113)));
	gtk_entry_set_text(GTK_ENTRY(user_data1->ent4), gtk_label_get_text(GTK_LABEL(user_data1->label114)));
	gtk_entry_set_text(GTK_ENTRY(user_data1->ent5), gtk_label_get_text(GTK_LABEL(user_data1->label115)));
	gtk_entry_set_text(GTK_ENTRY(user_data1->ent6), gtk_label_get_text(GTK_LABEL(user_data1->label116)));
	gtk_entry_set_text(GTK_ENTRY(user_data1->ent7), gtk_label_get_text(GTK_LABEL(user_data1->label117)));	
}
static void dynamic_edit12(GtkWidget *widget,  Gc_label *user_data1){
	misno = atoi(gtk_label_get_text(GTK_LABEL(user_data1->label121)));
	gtk_entry_set_text(GTK_ENTRY(user_data1->ent1), gtk_label_get_text(GTK_LABEL(user_data1->label121)));
	gtk_entry_set_text(GTK_ENTRY(user_data1->ent2), gtk_label_get_text(GTK_LABEL(user_data1->label122)));
	gtk_entry_set_text(GTK_ENTRY(user_data1->ent3), gtk_label_get_text(GTK_LABEL(user_data1->label123)));
	gtk_entry_set_text(GTK_ENTRY(user_data1->ent4), gtk_label_get_text(GTK_LABEL(user_data1->label124)));
	gtk_entry_set_text(GTK_ENTRY(user_data1->ent5), gtk_label_get_text(GTK_LABEL(user_data1->label125)));
	gtk_entry_set_text(GTK_ENTRY(user_data1->ent6), gtk_label_get_text(GTK_LABEL(user_data1->label126)));
	gtk_entry_set_text(GTK_ENTRY(user_data1->ent7), gtk_label_get_text(GTK_LABEL(user_data1->label127)));	
}
static void dynamic_edit13(GtkWidget *widget,  Gc_label *user_data1){
	misno = atoi(gtk_label_get_text(GTK_LABEL(user_data1->label131)));
	gtk_entry_set_text(GTK_ENTRY(user_data1->ent1), gtk_label_get_text(GTK_LABEL(user_data1->label131)));
	gtk_entry_set_text(GTK_ENTRY(user_data1->ent2), gtk_label_get_text(GTK_LABEL(user_data1->label132)));
	gtk_entry_set_text(GTK_ENTRY(user_data1->ent3), gtk_label_get_text(GTK_LABEL(user_data1->label133)));
	gtk_entry_set_text(GTK_ENTRY(user_data1->ent4), gtk_label_get_text(GTK_LABEL(user_data1->label134)));
	gtk_entry_set_text(GTK_ENTRY(user_data1->ent5), gtk_label_get_text(GTK_LABEL(user_data1->label135)));
	gtk_entry_set_text(GTK_ENTRY(user_data1->ent6), gtk_label_get_text(GTK_LABEL(user_data1->label136)));
	gtk_entry_set_text(GTK_ENTRY(user_data1->ent7), gtk_label_get_text(GTK_LABEL(user_data1->label137)));	
}
static void dynamic_edit14(GtkWidget *widget,  Gc_label *user_data1){
	misno = atoi(gtk_label_get_text(GTK_LABEL(user_data1->label141)));
	gtk_entry_set_text(GTK_ENTRY(user_data1->ent1), gtk_label_get_text(GTK_LABEL(user_data1->label141)));
	gtk_entry_set_text(GTK_ENTRY(user_data1->ent2), gtk_label_get_text(GTK_LABEL(user_data1->label142)));
	gtk_entry_set_text(GTK_ENTRY(user_data1->ent3), gtk_label_get_text(GTK_LABEL(user_data1->label143)));
	gtk_entry_set_text(GTK_ENTRY(user_data1->ent4), gtk_label_get_text(GTK_LABEL(user_data1->label144)));
	gtk_entry_set_text(GTK_ENTRY(user_data1->ent5), gtk_label_get_text(GTK_LABEL(user_data1->label145)));
	gtk_entry_set_text(GTK_ENTRY(user_data1->ent6), gtk_label_get_text(GTK_LABEL(user_data1->label146)));
	gtk_entry_set_text(GTK_ENTRY(user_data1->ent7), gtk_label_get_text(GTK_LABEL(user_data1->label147)));	
}
static void dynamic_edit15(GtkWidget *widget,  Gc_label *user_data1){
	misno = atoi(gtk_label_get_text(GTK_LABEL(user_data1->label151)));
	gtk_entry_set_text(GTK_ENTRY(user_data1->ent1), gtk_label_get_text(GTK_LABEL(user_data1->label151)));
	gtk_entry_set_text(GTK_ENTRY(user_data1->ent2), gtk_label_get_text(GTK_LABEL(user_data1->label152)));
	gtk_entry_set_text(GTK_ENTRY(user_data1->ent3), gtk_label_get_text(GTK_LABEL(user_data1->label153)));
	gtk_entry_set_text(GTK_ENTRY(user_data1->ent4), gtk_label_get_text(GTK_LABEL(user_data1->label154)));
	gtk_entry_set_text(GTK_ENTRY(user_data1->ent5), gtk_label_get_text(GTK_LABEL(user_data1->label155)));
	gtk_entry_set_text(GTK_ENTRY(user_data1->ent6), gtk_label_get_text(GTK_LABEL(user_data1->label156)));
	gtk_entry_set_text(GTK_ENTRY(user_data1->ent7), gtk_label_get_text(GTK_LABEL(user_data1->label157)));	
}
static void dynamic_edit16(GtkWidget *widget,  Gc_label *user_data1){
	misno = atoi(gtk_label_get_text(GTK_LABEL(user_data1->label161)));
	gtk_entry_set_text(GTK_ENTRY(user_data1->ent1), gtk_label_get_text(GTK_LABEL(user_data1->label161)));
	gtk_entry_set_text(GTK_ENTRY(user_data1->ent2), gtk_label_get_text(GTK_LABEL(user_data1->label162)));
	gtk_entry_set_text(GTK_ENTRY(user_data1->ent3), gtk_label_get_text(GTK_LABEL(user_data1->label163)));
	gtk_entry_set_text(GTK_ENTRY(user_data1->ent4), gtk_label_get_text(GTK_LABEL(user_data1->label164)));
	gtk_entry_set_text(GTK_ENTRY(user_data1->ent5), gtk_label_get_text(GTK_LABEL(user_data1->label165)));
	gtk_entry_set_text(GTK_ENTRY(user_data1->ent6), gtk_label_get_text(GTK_LABEL(user_data1->label166)));
	gtk_entry_set_text(GTK_ENTRY(user_data1->ent7), gtk_label_get_text(GTK_LABEL(user_data1->label167)));	
}



static void dynamic_delete2(GtkWidget *widget,  Gc_label *user_data1){
	gtk_label_set_text(GTK_LABEL(user_data1->ent1), gtk_label_get_text(GTK_LABEL(user_data1->label21)));
	gtk_label_set_text(GTK_LABEL(user_data1->ent2), gtk_label_get_text(GTK_LABEL(user_data1->label22)));
	gtk_label_set_text(GTK_LABEL(user_data1->ent3), gtk_label_get_text(GTK_LABEL(user_data1->label23)));
	gtk_label_set_text(GTK_LABEL(user_data1->ent4), gtk_label_get_text(GTK_LABEL(user_data1->label24)));
	gtk_label_set_text(GTK_LABEL(user_data1->ent5), gtk_label_get_text(GTK_LABEL(user_data1->label25)));
	gtk_label_set_text(GTK_LABEL(user_data1->ent6), gtk_label_get_text(GTK_LABEL(user_data1->label26)));
	gtk_label_set_text(GTK_LABEL(user_data1->ent7), gtk_label_get_text(GTK_LABEL(user_data1->label27)));	
}
static void dynamic_delete3(GtkWidget *widget,  Gc_label *user_data1){
	gtk_label_set_text(GTK_LABEL(user_data1->ent1), gtk_label_get_text(GTK_LABEL(user_data1->label31)));
	gtk_label_set_text(GTK_LABEL(user_data1->ent2), gtk_label_get_text(GTK_LABEL(user_data1->label32)));
	gtk_label_set_text(GTK_LABEL(user_data1->ent3), gtk_label_get_text(GTK_LABEL(user_data1->label33)));
	gtk_label_set_text(GTK_LABEL(user_data1->ent4), gtk_label_get_text(GTK_LABEL(user_data1->label34)));
	gtk_label_set_text(GTK_LABEL(user_data1->ent5), gtk_label_get_text(GTK_LABEL(user_data1->label35)));
	gtk_label_set_text(GTK_LABEL(user_data1->ent6), gtk_label_get_text(GTK_LABEL(user_data1->label36)));
	gtk_label_set_text(GTK_LABEL(user_data1->ent7), gtk_label_get_text(GTK_LABEL(user_data1->label37)));	
}
static void dynamic_delete4(GtkWidget *widget,  Gc_label *user_data1){
	gtk_label_set_text(GTK_LABEL(user_data1->ent1), gtk_label_get_text(GTK_LABEL(user_data1->label41)));
	gtk_label_set_text(GTK_LABEL(user_data1->ent2), gtk_label_get_text(GTK_LABEL(user_data1->label42)));
	gtk_label_set_text(GTK_LABEL(user_data1->ent3), gtk_label_get_text(GTK_LABEL(user_data1->label43)));
	gtk_label_set_text(GTK_LABEL(user_data1->ent4), gtk_label_get_text(GTK_LABEL(user_data1->label44)));
	gtk_label_set_text(GTK_LABEL(user_data1->ent5), gtk_label_get_text(GTK_LABEL(user_data1->label45)));
	gtk_label_set_text(GTK_LABEL(user_data1->ent6), gtk_label_get_text(GTK_LABEL(user_data1->label46)));
	gtk_label_set_text(GTK_LABEL(user_data1->ent7), gtk_label_get_text(GTK_LABEL(user_data1->label47)));	
}
static void dynamic_delete5(GtkWidget *widget,  Gc_label *user_data1){
	gtk_label_set_text(GTK_LABEL(user_data1->ent1), gtk_label_get_text(GTK_LABEL(user_data1->label51)));
	gtk_label_set_text(GTK_LABEL(user_data1->ent2), gtk_label_get_text(GTK_LABEL(user_data1->label52)));
	gtk_label_set_text(GTK_LABEL(user_data1->ent3), gtk_label_get_text(GTK_LABEL(user_data1->label53)));
	gtk_label_set_text(GTK_LABEL(user_data1->ent4), gtk_label_get_text(GTK_LABEL(user_data1->label54)));
	gtk_label_set_text(GTK_LABEL(user_data1->ent5), gtk_label_get_text(GTK_LABEL(user_data1->label55)));
	gtk_label_set_text(GTK_LABEL(user_data1->ent6), gtk_label_get_text(GTK_LABEL(user_data1->label56)));
	gtk_label_set_text(GTK_LABEL(user_data1->ent7), gtk_label_get_text(GTK_LABEL(user_data1->label57)));	
}
static void dynamic_delete6(GtkWidget *widget,  Gc_label *user_data1){
	gtk_label_set_text(GTK_LABEL(user_data1->ent1), gtk_label_get_text(GTK_LABEL(user_data1->label61)));
	gtk_label_set_text(GTK_LABEL(user_data1->ent2), gtk_label_get_text(GTK_LABEL(user_data1->label62)));
	gtk_label_set_text(GTK_LABEL(user_data1->ent3), gtk_label_get_text(GTK_LABEL(user_data1->label63)));
	gtk_label_set_text(GTK_LABEL(user_data1->ent4), gtk_label_get_text(GTK_LABEL(user_data1->label64)));
	gtk_label_set_text(GTK_LABEL(user_data1->ent5), gtk_label_get_text(GTK_LABEL(user_data1->label65)));
	gtk_label_set_text(GTK_LABEL(user_data1->ent6), gtk_label_get_text(GTK_LABEL(user_data1->label66)));
	gtk_label_set_text(GTK_LABEL(user_data1->ent7), gtk_label_get_text(GTK_LABEL(user_data1->label67)));	
}
static void dynamic_delete7(GtkWidget *widget,  Gc_label *user_data1){
	gtk_label_set_text(GTK_LABEL(user_data1->ent1), gtk_label_get_text(GTK_LABEL(user_data1->label71)));
	gtk_label_set_text(GTK_LABEL(user_data1->ent2), gtk_label_get_text(GTK_LABEL(user_data1->label72)));
	gtk_label_set_text(GTK_LABEL(user_data1->ent3), gtk_label_get_text(GTK_LABEL(user_data1->label73)));
	gtk_label_set_text(GTK_LABEL(user_data1->ent4), gtk_label_get_text(GTK_LABEL(user_data1->label74)));
	gtk_label_set_text(GTK_LABEL(user_data1->ent5), gtk_label_get_text(GTK_LABEL(user_data1->label75)));
	gtk_label_set_text(GTK_LABEL(user_data1->ent6), gtk_label_get_text(GTK_LABEL(user_data1->label76)));
	gtk_label_set_text(GTK_LABEL(user_data1->ent7), gtk_label_get_text(GTK_LABEL(user_data1->label77)));	
}
static void dynamic_delete8(GtkWidget *widget,  Gc_label *user_data1){
	gtk_label_set_text(GTK_LABEL(user_data1->ent1), gtk_label_get_text(GTK_LABEL(user_data1->label81)));
	gtk_label_set_text(GTK_LABEL(user_data1->ent2), gtk_label_get_text(GTK_LABEL(user_data1->label82)));
	gtk_label_set_text(GTK_LABEL(user_data1->ent3), gtk_label_get_text(GTK_LABEL(user_data1->label83)));
	gtk_label_set_text(GTK_LABEL(user_data1->ent4), gtk_label_get_text(GTK_LABEL(user_data1->label84)));
	gtk_label_set_text(GTK_LABEL(user_data1->ent5), gtk_label_get_text(GTK_LABEL(user_data1->label85)));
	gtk_label_set_text(GTK_LABEL(user_data1->ent6), gtk_label_get_text(GTK_LABEL(user_data1->label86)));
	gtk_label_set_text(GTK_LABEL(user_data1->ent7), gtk_label_get_text(GTK_LABEL(user_data1->label87)));	
}
static void dynamic_delete9(GtkWidget *widget,  Gc_label *user_data1){
	gtk_label_set_text(GTK_LABEL(user_data1->ent1), gtk_label_get_text(GTK_LABEL(user_data1->label91)));
	gtk_label_set_text(GTK_LABEL(user_data1->ent2), gtk_label_get_text(GTK_LABEL(user_data1->label92)));
	gtk_label_set_text(GTK_LABEL(user_data1->ent3), gtk_label_get_text(GTK_LABEL(user_data1->label93)));
	gtk_label_set_text(GTK_LABEL(user_data1->ent4), gtk_label_get_text(GTK_LABEL(user_data1->label94)));
	gtk_label_set_text(GTK_LABEL(user_data1->ent5), gtk_label_get_text(GTK_LABEL(user_data1->label95)));
	gtk_label_set_text(GTK_LABEL(user_data1->ent6), gtk_label_get_text(GTK_LABEL(user_data1->label96)));
	gtk_label_set_text(GTK_LABEL(user_data1->ent7), gtk_label_get_text(GTK_LABEL(user_data1->label97)));	
}
static void dynamic_delete10(GtkWidget *widget,  Gc_label *user_data1){
	gtk_label_set_text(GTK_LABEL(user_data1->ent1), gtk_label_get_text(GTK_LABEL(user_data1->label101)));
	gtk_label_set_text(GTK_LABEL(user_data1->ent2), gtk_label_get_text(GTK_LABEL(user_data1->label102)));
	gtk_label_set_text(GTK_LABEL(user_data1->ent3), gtk_label_get_text(GTK_LABEL(user_data1->label103)));
	gtk_label_set_text(GTK_LABEL(user_data1->ent4), gtk_label_get_text(GTK_LABEL(user_data1->label104)));
	gtk_label_set_text(GTK_LABEL(user_data1->ent5), gtk_label_get_text(GTK_LABEL(user_data1->label105)));
	gtk_label_set_text(GTK_LABEL(user_data1->ent6), gtk_label_get_text(GTK_LABEL(user_data1->label106)));
	gtk_label_set_text(GTK_LABEL(user_data1->ent7), gtk_label_get_text(GTK_LABEL(user_data1->label107)));
}
static void dynamic_delete11(GtkWidget *widget,  Gc_label *user_data1){
	gtk_label_set_text(GTK_LABEL(user_data1->ent1), gtk_label_get_text(GTK_LABEL(user_data1->label111)));
	gtk_label_set_text(GTK_LABEL(user_data1->ent2), gtk_label_get_text(GTK_LABEL(user_data1->label112)));
	gtk_label_set_text(GTK_LABEL(user_data1->ent3), gtk_label_get_text(GTK_LABEL(user_data1->label113)));
	gtk_label_set_text(GTK_LABEL(user_data1->ent4), gtk_label_get_text(GTK_LABEL(user_data1->label114)));
	gtk_label_set_text(GTK_LABEL(user_data1->ent5), gtk_label_get_text(GTK_LABEL(user_data1->label115)));
	gtk_label_set_text(GTK_LABEL(user_data1->ent6), gtk_label_get_text(GTK_LABEL(user_data1->label116)));
	gtk_label_set_text(GTK_LABEL(user_data1->ent7), gtk_label_get_text(GTK_LABEL(user_data1->label117)));	
}
static void dynamic_delete12(GtkWidget *widget,  Gc_label *user_data1){
	gtk_label_set_text(GTK_LABEL(user_data1->ent1), gtk_label_get_text(GTK_LABEL(user_data1->label121)));
	gtk_label_set_text(GTK_LABEL(user_data1->ent2), gtk_label_get_text(GTK_LABEL(user_data1->label122)));
	gtk_label_set_text(GTK_LABEL(user_data1->ent3), gtk_label_get_text(GTK_LABEL(user_data1->label123)));
	gtk_label_set_text(GTK_LABEL(user_data1->ent4), gtk_label_get_text(GTK_LABEL(user_data1->label124)));
	gtk_label_set_text(GTK_LABEL(user_data1->ent5), gtk_label_get_text(GTK_LABEL(user_data1->label125)));
	gtk_label_set_text(GTK_LABEL(user_data1->ent6), gtk_label_get_text(GTK_LABEL(user_data1->label126)));
	gtk_label_set_text(GTK_LABEL(user_data1->ent7), gtk_label_get_text(GTK_LABEL(user_data1->label127)));	
}
static void dynamic_delete13(GtkWidget *widget,  Gc_label *user_data1){
	gtk_label_set_text(GTK_LABEL(user_data1->ent1), gtk_label_get_text(GTK_LABEL(user_data1->label131)));
	gtk_label_set_text(GTK_LABEL(user_data1->ent2), gtk_label_get_text(GTK_LABEL(user_data1->label132)));
	gtk_label_set_text(GTK_LABEL(user_data1->ent3), gtk_label_get_text(GTK_LABEL(user_data1->label133)));
	gtk_label_set_text(GTK_LABEL(user_data1->ent4), gtk_label_get_text(GTK_LABEL(user_data1->label134)));
	gtk_label_set_text(GTK_LABEL(user_data1->ent5), gtk_label_get_text(GTK_LABEL(user_data1->label135)));
	gtk_label_set_text(GTK_LABEL(user_data1->ent6), gtk_label_get_text(GTK_LABEL(user_data1->label136)));
	gtk_label_set_text(GTK_LABEL(user_data1->ent7), gtk_label_get_text(GTK_LABEL(user_data1->label137)));	
}
static void dynamic_delete14(GtkWidget *widget,  Gc_label *user_data1){
	gtk_label_set_text(GTK_LABEL(user_data1->ent1), gtk_label_get_text(GTK_LABEL(user_data1->label141)));
	gtk_label_set_text(GTK_LABEL(user_data1->ent2), gtk_label_get_text(GTK_LABEL(user_data1->label142)));
	gtk_label_set_text(GTK_LABEL(user_data1->ent3), gtk_label_get_text(GTK_LABEL(user_data1->label143)));
	gtk_label_set_text(GTK_LABEL(user_data1->ent4), gtk_label_get_text(GTK_LABEL(user_data1->label144)));
	gtk_label_set_text(GTK_LABEL(user_data1->ent5), gtk_label_get_text(GTK_LABEL(user_data1->label145)));
	gtk_label_set_text(GTK_LABEL(user_data1->ent6), gtk_label_get_text(GTK_LABEL(user_data1->label146)));
	gtk_label_set_text(GTK_LABEL(user_data1->ent7), gtk_label_get_text(GTK_LABEL(user_data1->label147)));	
}
static void dynamic_delete15(GtkWidget *widget,  Gc_label *user_data1){
	gtk_label_set_text(GTK_LABEL(user_data1->ent1), gtk_label_get_text(GTK_LABEL(user_data1->label151)));
	gtk_label_set_text(GTK_LABEL(user_data1->ent2), gtk_label_get_text(GTK_LABEL(user_data1->label152)));
	gtk_label_set_text(GTK_LABEL(user_data1->ent3), gtk_label_get_text(GTK_LABEL(user_data1->label153)));
	gtk_label_set_text(GTK_LABEL(user_data1->ent4), gtk_label_get_text(GTK_LABEL(user_data1->label154)));
	gtk_label_set_text(GTK_LABEL(user_data1->ent5), gtk_label_get_text(GTK_LABEL(user_data1->label155)));
	gtk_label_set_text(GTK_LABEL(user_data1->ent6), gtk_label_get_text(GTK_LABEL(user_data1->label156)));
	gtk_label_set_text(GTK_LABEL(user_data1->ent7), gtk_label_get_text(GTK_LABEL(user_data1->label157)));	
}
static void dynamic_delete16(GtkWidget *widget,  Gc_label *user_data1){
	gtk_label_set_text(GTK_LABEL(user_data1->ent1), gtk_label_get_text(GTK_LABEL(user_data1->label161)));
	gtk_label_set_text(GTK_LABEL(user_data1->ent2), gtk_label_get_text(GTK_LABEL(user_data1->label162)));
	gtk_label_set_text(GTK_LABEL(user_data1->ent3), gtk_label_get_text(GTK_LABEL(user_data1->label163)));
	gtk_label_set_text(GTK_LABEL(user_data1->ent4), gtk_label_get_text(GTK_LABEL(user_data1->label164)));
	gtk_label_set_text(GTK_LABEL(user_data1->ent5), gtk_label_get_text(GTK_LABEL(user_data1->label165)));
	gtk_label_set_text(GTK_LABEL(user_data1->ent6), gtk_label_get_text(GTK_LABEL(user_data1->label166)));
	gtk_label_set_text(GTK_LABEL(user_data1->ent7), gtk_label_get_text(GTK_LABEL(user_data1->label167)));	
}
/*****************************************************************************************************end**********************/



static void on_window_closed(GtkWidget *widget, Gc_label *user_data){
	gtk_main_quit();
}

void close_window(GtkWidget *widget, gpointer window){		/****************************closes active window of application*/
	GtkResponseType result;
	GtkWidget *dialog;
  	dialog = gtk_message_dialog_new(GTK_WINDOW(window),
            GTK_DIALOG_DESTROY_WITH_PARENT,
            GTK_MESSAGE_QUESTION,
            GTK_BUTTONS_YES_NO,
            "Are you sure to quit?");
  	gtk_window_set_title(GTK_WINDOW(dialog), "Question");
  	result=gtk_dialog_run(GTK_DIALOG(dialog));
	if(result == GTK_RESPONSE_YES){
  			gtk_widget_destroy(dialog);
			gtk_widget_destroy(GTK_WIDGET(window));
	}
	else{
		gtk_widget_destroy(dialog);
	}
}


/*********************************************following functions and methods are used for searching student details in file*/
void searchinfile1(GtkWidget *widget, Gc_label *user_data){
	GtkResponseType result;
	GtkWidget *dialog;	
	if(atoi(gtk_entry_get_text(GTK_ENTRY(user_data->entry)))==0){		/*checks whether user had entered MIS or not*/	
 	    	dialog = gtk_message_dialog_new(GTK_WINDOW(user_data->window),
            	GTK_DIALOG_DESTROY_WITH_PARENT,
            	GTK_MESSAGE_ERROR,
            	GTK_BUTTONS_OK,
            	"Enter MIS OF STudent To be Search..");
  		gtk_window_set_title(GTK_WINDOW(dialog), "Error");
  		gtk_dialog_run(GTK_DIALOG(dialog));
  		gtk_widget_destroy(dialog);
	}
	else{	
		int i = atoi(gtk_entry_get_text(GTK_ENTRY(user_data->entry)));
		FILE *fp = fopen("studata.txt","r+"); /**opening file for searching**/
		while(1){
			fscanf(fp, "%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\n]\n", rec.mis,  rec.name, rec.address, rec.branch, rec.blockno, rec.mobileno, rec.emailid, rec.date);
			if(atoi(rec.mis) == i) {
				gtk_label_set_text(GTK_LABEL(user_data->ent1), rec.mis);
				gtk_label_set_text(GTK_LABEL(user_data->ent2), rec.name);
				gtk_label_set_text(GTK_LABEL(user_data->ent3), rec.address);
				gtk_label_set_text(GTK_LABEL(user_data->ent4), rec.branch);
				gtk_label_set_text(GTK_LABEL(user_data->ent5), rec.blockno);
				gtk_label_set_text(GTK_LABEL(user_data->ent6), rec.mobileno);
				gtk_label_set_text(GTK_LABEL(user_data->ent7), rec.emailid);
			}
			if(feof(fp)){
					break;	
			}
		}
		fclose(fp);		
	}
}

void search_student_by_all(GtkWidget *widget, Gc_label *structlabel){
	GtkResponseType result;
	GtkWidget *dialog;
	char arr[5]="";		
	if(strcmp(arr, gtk_entry_get_text(GTK_ENTRY(structlabel->ent1)))==0){	/*checks whether user had entered MIS or not*/
 	    	dialog = gtk_message_dialog_new(GTK_WINDOW(structlabel->window),
            	GTK_DIALOG_DESTROY_WITH_PARENT,
            	GTK_MESSAGE_ERROR,
            	GTK_BUTTONS_OK,
            	"Enter MIS OF STudent To be Search..");
  		gtk_window_set_title(GTK_WINDOW(dialog), "Error");
  		gtk_dialog_run(GTK_DIALOG(dialog));
  		gtk_widget_destroy(dialog);
	}
	else{	
		p=0;
		FILE *fp = fopen("studata.txt","r+"); /*opening file for searching**/
		while(1){
			fscanf(fp, "%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\n]\n", rec.mis,  rec.name, rec.address, rec.branch, rec.blockno, rec.mobileno, rec.emailid, rec.date);
			if(atoi(rec.mis) == atoi(gtk_entry_get_text(GTK_ENTRY(structlabel->ent1))) || strcmp(rec.name, gtk_entry_get_text(GTK_ENTRY(structlabel->ent1)))==0 || strcmp(rec.branch, gtk_entry_get_text(GTK_ENTRY(structlabel->ent1)))==0 || strcmp(rec.blockno, gtk_entry_get_text(GTK_ENTRY(structlabel->ent1)))==0 || strcmp(rec.emailid, gtk_entry_get_text(GTK_ENTRY(structlabel->ent1)))==0 || atoi(rec.mobileno) == atoi(gtk_entry_get_text(GTK_ENTRY(structlabel->ent1))) ||  strcmp(rec.date, gtk_entry_get_text(GTK_ENTRY(structlabel->ent1)))==0) {					/*if match founds then display that appropiate data*/
				if(p == 0) {	
					gtk_label_set_text(GTK_LABEL(structlabel->label21), rec.mis);
					gtk_label_set_text(GTK_LABEL(structlabel->label22), rec.name);
					gtk_label_set_text(GTK_LABEL(structlabel->label23), rec.address);
					gtk_label_set_text(GTK_LABEL(structlabel->label24), rec.branch);
					gtk_label_set_text(GTK_LABEL(structlabel->label25), rec.blockno);
					gtk_label_set_text(GTK_LABEL(structlabel->label26), rec.mobileno);
					gtk_label_set_text(GTK_LABEL(structlabel->label27), rec.emailid);
					gtk_label_set_text(GTK_LABEL(structlabel->label28), rec.date);
				}
				else if(p == 1) {	
					gtk_label_set_text(GTK_LABEL(structlabel->label31), rec.mis);
					gtk_label_set_text(GTK_LABEL(structlabel->label32), rec.name);
					gtk_label_set_text(GTK_LABEL(structlabel->label33), rec.address);
					gtk_label_set_text(GTK_LABEL(structlabel->label34), rec.branch);
					gtk_label_set_text(GTK_LABEL(structlabel->label35), rec.blockno);
					gtk_label_set_text(GTK_LABEL(structlabel->label36), rec.mobileno);
					gtk_label_set_text(GTK_LABEL(structlabel->label37), rec.emailid);
					gtk_label_set_text(GTK_LABEL(structlabel->label38), rec.date);
				}
				else if(p == 2) {	
					gtk_label_set_text(GTK_LABEL(structlabel->label41), rec.mis);
					gtk_label_set_text(GTK_LABEL(structlabel->label42), rec.name);
					gtk_label_set_text(GTK_LABEL(structlabel->label43), rec.address);
					gtk_label_set_text(GTK_LABEL(structlabel->label44), rec.branch);
					gtk_label_set_text(GTK_LABEL(structlabel->label45), rec.blockno);
					gtk_label_set_text(GTK_LABEL(structlabel->label46), rec.mobileno);
					gtk_label_set_text(GTK_LABEL(structlabel->label47), rec.emailid);
					gtk_label_set_text(GTK_LABEL(structlabel->label48), rec.date);
				}
				else if(p == 3) {	
					gtk_label_set_text(GTK_LABEL(structlabel->label51), rec.mis);
					gtk_label_set_text(GTK_LABEL(structlabel->label52), rec.name);
					gtk_label_set_text(GTK_LABEL(structlabel->label53), rec.address);
					gtk_label_set_text(GTK_LABEL(structlabel->label54), rec.branch);
					gtk_label_set_text(GTK_LABEL(structlabel->label55), rec.blockno);
					gtk_label_set_text(GTK_LABEL(structlabel->label56), rec.mobileno);
					gtk_label_set_text(GTK_LABEL(structlabel->label57), rec.emailid);
					gtk_label_set_text(GTK_LABEL(structlabel->label58), rec.date);
				}
				else if(p == 4) {	
					gtk_label_set_text(GTK_LABEL(structlabel->label61), rec.mis);
					gtk_label_set_text(GTK_LABEL(structlabel->label62), rec.name);
					gtk_label_set_text(GTK_LABEL(structlabel->label63), rec.address);
					gtk_label_set_text(GTK_LABEL(structlabel->label64), rec.branch);
					gtk_label_set_text(GTK_LABEL(structlabel->label65), rec.blockno);
					gtk_label_set_text(GTK_LABEL(structlabel->label66), rec.mobileno);
					gtk_label_set_text(GTK_LABEL(structlabel->label67), rec.emailid);
					gtk_label_set_text(GTK_LABEL(structlabel->label68), rec.date);
				}
				else if(p == 5) {	
					gtk_label_set_text(GTK_LABEL(structlabel->label71), rec.mis);
					gtk_label_set_text(GTK_LABEL(structlabel->label72), rec.name);
					gtk_label_set_text(GTK_LABEL(structlabel->label73), rec.address);
					gtk_label_set_text(GTK_LABEL(structlabel->label74), rec.branch);
					gtk_label_set_text(GTK_LABEL(structlabel->label75), rec.blockno);
					gtk_label_set_text(GTK_LABEL(structlabel->label76), rec.mobileno);
					gtk_label_set_text(GTK_LABEL(structlabel->label77), rec.emailid);
					gtk_label_set_text(GTK_LABEL(structlabel->label78), rec.date);
				}
				else if(p == 6) {	
					gtk_label_set_text(GTK_LABEL(structlabel->label81), rec.mis);
					gtk_label_set_text(GTK_LABEL(structlabel->label82), rec.name);
					gtk_label_set_text(GTK_LABEL(structlabel->label83), rec.address);
					gtk_label_set_text(GTK_LABEL(structlabel->label84), rec.branch);
					gtk_label_set_text(GTK_LABEL(structlabel->label85), rec.blockno);
					gtk_label_set_text(GTK_LABEL(structlabel->label86), rec.mobileno);
					gtk_label_set_text(GTK_LABEL(structlabel->label87), rec.emailid);
					gtk_label_set_text(GTK_LABEL(structlabel->label88), rec.date);
				}
				else if(p == 7) {	
					gtk_label_set_text(GTK_LABEL(structlabel->label91), rec.mis);
					gtk_label_set_text(GTK_LABEL(structlabel->label92), rec.name);
					gtk_label_set_text(GTK_LABEL(structlabel->label93), rec.address);
					gtk_label_set_text(GTK_LABEL(structlabel->label94), rec.branch);
					gtk_label_set_text(GTK_LABEL(structlabel->label95), rec.blockno);
					gtk_label_set_text(GTK_LABEL(structlabel->label96), rec.mobileno);
					gtk_label_set_text(GTK_LABEL(structlabel->label97), rec.emailid);
					gtk_label_set_text(GTK_LABEL(structlabel->label98), rec.date);
				}
				else if(p == 8) {	
					gtk_label_set_text(GTK_LABEL(structlabel->label101), rec.mis);
					gtk_label_set_text(GTK_LABEL(structlabel->label102), rec.name);
					gtk_label_set_text(GTK_LABEL(structlabel->label103), rec.address);
					gtk_label_set_text(GTK_LABEL(structlabel->label104), rec.branch);
					gtk_label_set_text(GTK_LABEL(structlabel->label105), rec.blockno);
					gtk_label_set_text(GTK_LABEL(structlabel->label106), rec.mobileno);
					gtk_label_set_text(GTK_LABEL(structlabel->label107), rec.emailid);
					gtk_label_set_text(GTK_LABEL(structlabel->label108), rec.date);
				}
				else if(p == 9) {	
					gtk_label_set_text(GTK_LABEL(structlabel->label111), rec.mis);
					gtk_label_set_text(GTK_LABEL(structlabel->label112), rec.name);
					gtk_label_set_text(GTK_LABEL(structlabel->label113), rec.address);
					gtk_label_set_text(GTK_LABEL(structlabel->label114), rec.branch);
					gtk_label_set_text(GTK_LABEL(structlabel->label115), rec.blockno);
					gtk_label_set_text(GTK_LABEL(structlabel->label116), rec.mobileno);
					gtk_label_set_text(GTK_LABEL(structlabel->label117), rec.emailid);
					gtk_label_set_text(GTK_LABEL(structlabel->label118), rec.date);
				}
				else if(p == 10) {	
					gtk_label_set_text(GTK_LABEL(structlabel->label121), rec.mis);
					gtk_label_set_text(GTK_LABEL(structlabel->label122), rec.name);
					gtk_label_set_text(GTK_LABEL(structlabel->label123), rec.address);
					gtk_label_set_text(GTK_LABEL(structlabel->label124), rec.branch);
					gtk_label_set_text(GTK_LABEL(structlabel->label125), rec.blockno);
					gtk_label_set_text(GTK_LABEL(structlabel->label126), rec.mobileno);
					gtk_label_set_text(GTK_LABEL(structlabel->label127), rec.emailid);
					gtk_label_set_text(GTK_LABEL(structlabel->label128), rec.date);
				}
				else if(p == 11) {	
					gtk_label_set_text(GTK_LABEL(structlabel->label131), rec.mis);
					gtk_label_set_text(GTK_LABEL(structlabel->label132), rec.name);
					gtk_label_set_text(GTK_LABEL(structlabel->label133), rec.address);
					gtk_label_set_text(GTK_LABEL(structlabel->label134), rec.branch);
					gtk_label_set_text(GTK_LABEL(structlabel->label135), rec.blockno);
					gtk_label_set_text(GTK_LABEL(structlabel->label136), rec.mobileno);
					gtk_label_set_text(GTK_LABEL(structlabel->label137), rec.emailid);
					gtk_label_set_text(GTK_LABEL(structlabel->label138), rec.date);
				}
				else if(p == 12) {	
					gtk_label_set_text(GTK_LABEL(structlabel->label141), rec.mis);
					gtk_label_set_text(GTK_LABEL(structlabel->label142), rec.name);
					gtk_label_set_text(GTK_LABEL(structlabel->label143), rec.address);
					gtk_label_set_text(GTK_LABEL(structlabel->label144), rec.branch);
					gtk_label_set_text(GTK_LABEL(structlabel->label145), rec.blockno);
					gtk_label_set_text(GTK_LABEL(structlabel->label146), rec.mobileno);
					gtk_label_set_text(GTK_LABEL(structlabel->label147), rec.emailid);
					gtk_label_set_text(GTK_LABEL(structlabel->label148), rec.date);
				}
				else if(p == 13) {	
					gtk_label_set_text(GTK_LABEL(structlabel->label151), rec.mis);
					gtk_label_set_text(GTK_LABEL(structlabel->label152), rec.name);
					gtk_label_set_text(GTK_LABEL(structlabel->label153), rec.address);
					gtk_label_set_text(GTK_LABEL(structlabel->label154), rec.branch);
					gtk_label_set_text(GTK_LABEL(structlabel->label155), rec.blockno);
					gtk_label_set_text(GTK_LABEL(structlabel->label156), rec.mobileno);
					gtk_label_set_text(GTK_LABEL(structlabel->label157), rec.emailid);
					gtk_label_set_text(GTK_LABEL(structlabel->label158), rec.date);
				}
				else if(p == 14) {	
					gtk_label_set_text(GTK_LABEL(structlabel->label161), rec.mis);
					gtk_label_set_text(GTK_LABEL(structlabel->label162), rec.name);
					gtk_label_set_text(GTK_LABEL(structlabel->label163), rec.address);
					gtk_label_set_text(GTK_LABEL(structlabel->label164), rec.branch);
					gtk_label_set_text(GTK_LABEL(structlabel->label165), rec.blockno);
					gtk_label_set_text(GTK_LABEL(structlabel->label166), rec.mobileno);
					gtk_label_set_text(GTK_LABEL(structlabel->label167), rec.emailid);
					gtk_label_set_text(GTK_LABEL(structlabel->label168), rec.date);
					
				}
				p++;
			}
			if(feof(fp)){
				if(p == 0) {	
					gtk_label_set_text(GTK_LABEL(structlabel->label21), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label22), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label23), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label24), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label25), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label26), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label27), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label28),"");
					p++;
				}
				if(p == 1) {	
					gtk_label_set_text(GTK_LABEL(structlabel->label31), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label32), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label33), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label34), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label35), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label36), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label37), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label38),"");
					p++;				
				}
				if(p == 2) {	
					gtk_label_set_text(GTK_LABEL(structlabel->label41), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label42), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label43), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label44), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label45), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label46), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label47), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label48),"");
					p++;
				}
				if(p == 3) {	
					gtk_label_set_text(GTK_LABEL(structlabel->label51), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label52), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label53), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label54), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label55), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label56), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label57), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label58),"");
					p++;
				}
				if(p == 4) {	
					gtk_label_set_text(GTK_LABEL(structlabel->label61), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label62), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label63), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label64), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label65), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label66), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label67), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label68),"");
					p++;
				}
				if(p == 5) {	
					gtk_label_set_text(GTK_LABEL(structlabel->label71), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label72), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label73), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label74), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label75), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label76), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label77), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label78),"");
					p++;
				}
				if(p == 6) {	
					gtk_label_set_text(GTK_LABEL(structlabel->label81), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label82), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label83), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label84), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label85), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label86), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label87), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label88),"");
					p++;
				}
				if(p == 7) {	
					gtk_label_set_text(GTK_LABEL(structlabel->label91), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label92), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label93), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label94), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label95), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label96), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label97), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label98),"");
					p++;
				}
				if(p == 8) {	
					gtk_label_set_text(GTK_LABEL(structlabel->label101), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label102), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label103), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label104), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label105), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label106), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label107), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label108),"");
					p++;
				}
				if(p == 9) {	
					gtk_label_set_text(GTK_LABEL(structlabel->label111), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label112), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label113), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label114), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label115), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label116), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label117), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label118),"");
					p++;
				}
				if(p == 10) {	
					gtk_label_set_text(GTK_LABEL(structlabel->label121), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label122), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label123), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label124), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label125), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label126), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label127), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label128),"");
					p++;
				}
				if(p == 11) {	
					gtk_label_set_text(GTK_LABEL(structlabel->label131), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label132), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label133), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label134), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label135), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label136), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label137), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label138),"");
					p++;
				}
				if(p == 12) {	
					gtk_label_set_text(GTK_LABEL(structlabel->label141), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label142), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label143), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label144), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label145), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label146), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label147), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label148),"");
					p++;
				}
				if(p == 13) {	
					gtk_label_set_text(GTK_LABEL(structlabel->label151), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label152), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label153), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label154), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label155), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label156), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label157), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label158),"");
					p++;
				}
				if(p == 14) {	
					gtk_label_set_text(GTK_LABEL(structlabel->label161), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label162), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label163), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label164), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label165), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label166), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label167), "");
					gtk_label_set_text(GTK_LABEL(structlabel->label168),"");
					p++;
					break;
				}
				break;
			}
		}
		fclose(fp);		
	}
}

void searchinfile12(GtkWidget *widget, Gc_label *user_data){
	GtkResponseType result;
	GtkWidget *dialog;
	misno = atoi(gtk_entry_get_text(GTK_ENTRY(user_data->entry)));	
	if(atoi(gtk_entry_get_text(GTK_ENTRY(user_data->entry)))==0){		/*checks whether user had entered MIS or not*/	
 	    	dialog = gtk_message_dialog_new(GTK_WINDOW(user_data->window),
            	GTK_DIALOG_DESTROY_WITH_PARENT,
            	GTK_MESSAGE_INFO,
            	GTK_BUTTONS_OK,
            	"Enter MIS OF STudent To be Search..");
  		gtk_window_set_title(GTK_WINDOW(dialog), "Information");
  		gtk_dialog_run(GTK_DIALOG(dialog));
  		gtk_widget_destroy(dialog);
	}
	else{	
		int i = atoi(gtk_entry_get_text(GTK_ENTRY(user_data->entry)));
		FILE *fp = fopen("studata.txt","r+");
		while(1){
			fscanf(fp, "%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\n]\n", rec.mis,  rec.name, rec.address, rec.branch, rec.blockno, rec.mobileno, rec.emailid, rec.date);
			if(atoi(rec.mis) == i) {
				gtk_entry_set_text(GTK_ENTRY(user_data->ent1), rec.mis);
				gtk_entry_set_text(GTK_ENTRY(user_data->ent2), rec.name);
				gtk_entry_set_text(GTK_ENTRY(user_data->ent3), rec.address);
				gtk_entry_set_text(GTK_ENTRY(user_data->ent4), rec.branch);
				gtk_entry_set_text(GTK_ENTRY(user_data->ent5), rec.blockno);
				gtk_entry_set_text(GTK_ENTRY(user_data->ent6), rec.mobileno);
				gtk_entry_set_text(GTK_ENTRY(user_data->ent7), rec.emailid);
			}
			if(feof(fp)){
					break;	
			}
		}
		fclose(fp);		
	}
}

void searchinfile(GtkWidget *widget, Gc_label *user_data){
	GtkResponseType result;
	GtkWidget *dialog;	
	if(atoi(gtk_entry_get_text(GTK_ENTRY(user_data->search)))==0){	/*checks whether user had entered MIS or not*/
 	    	dialog = gtk_message_dialog_new(GTK_WINDOW(user_data->window),
            	GTK_DIALOG_DESTROY_WITH_PARENT,
            	GTK_MESSAGE_INFO,
            	GTK_BUTTONS_OK,
            	"Enter MIS OF STudent To be Search..");
  		gtk_window_set_title(GTK_WINDOW(dialog), "Information");
  		gtk_dialog_run(GTK_DIALOG(dialog));
  		gtk_widget_destroy(dialog);
	}
	else{	
		int o = atoi(gtk_entry_get_text(GTK_ENTRY(user_data->search)));
		FILE *fp = fopen("studata.txt","r+");
		while(1){
			fscanf(fp, "%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\n]\n", rec.mis,  rec.name, rec.address, rec.branch, rec.blockno, rec.mobileno, rec.emailid);
			if(atoi(rec.mis) == o) {
				gtk_label_set_text(GTK_LABEL(user_data->label22), rec.name);
				gtk_label_set_text(GTK_LABEL(user_data->label23), rec.address);
				gtk_label_set_text(GTK_LABEL(user_data->label24), rec.branch);
				gtk_label_set_text(GTK_LABEL(user_data->label25), rec.blockno);
				gtk_label_set_text(GTK_LABEL(user_data->label26), rec.mobileno);
				gtk_label_set_text(GTK_LABEL(user_data->label27), rec.emailid);
			}
			if(feof(fp)){
					break;	
			}
		}
		fclose(fp);		
	}
}

void searchinfiledynamic(GtkWidget *widget, Gc_master *user_data){
	GtkResponseType result;
	GtkWidget *dialog;	
	if(atoi(gtk_entry_get_text(GTK_ENTRY(user_data->ent1)))==0 && j == 0){
			/*checks whether user had entered MIS or not*/
 	    	dialog = gtk_message_dialog_new(GTK_WINDOW(user_data->window),
            	GTK_DIALOG_DESTROY_WITH_PARENT,
            	GTK_MESSAGE_ERROR,
            	GTK_BUTTONS_OK,
            	"Enter MIS OF STudent To be Search..");
  		gtk_window_set_title(GTK_WINDOW(dialog), "Error");
  		gtk_dialog_run(GTK_DIALOG(dialog));
  		gtk_widget_destroy(dialog);
	}
	else{	
		int i = atoi(gtk_entry_get_text(GTK_ENTRY(user_data->ent1)));
		FILE *fp = fopen("studata.txt","r+");   /*opening file for searching**/
		while(1){
			fscanf(fp, "%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\n]\n", rec.mis,  rec.name, rec.address, rec.branch, rec.blockno, rec.mobileno, rec.emailid);
			if(atoi(rec.mis) == i){	
				gtk_entry_set_text(GTK_ENTRY(user_data->ent1), rec.mis);
				gtk_entry_set_text(GTK_ENTRY(user_data->ent2), rec.name);
				gtk_entry_set_text(GTK_ENTRY(user_data->ent3), rec.address);
				gtk_entry_set_text(GTK_ENTRY(user_data->ent4), rec.branch);
				gtk_entry_set_text(GTK_ENTRY(user_data->ent5), rec.blockno);
				gtk_entry_set_text(GTK_ENTRY(user_data->ent6), rec.mobileno);
				gtk_entry_set_text(GTK_ENTRY(user_data->ent7), rec.emailid);
			}
			else if(atoi(rec.mis) == j){	
				gtk_entry_set_text(GTK_ENTRY(user_data->ent1), rec.mis);
				gtk_entry_set_text(GTK_ENTRY(user_data->ent2), rec.name);
				gtk_entry_set_text(GTK_ENTRY(user_data->ent3), rec.address);
				gtk_entry_set_text(GTK_ENTRY(user_data->ent4), rec.branch);
				gtk_entry_set_text(GTK_ENTRY(user_data->ent5), rec.blockno);
				gtk_entry_set_text(GTK_ENTRY(user_data->ent6), rec.mobileno);
				gtk_entry_set_text(GTK_ENTRY(user_data->ent7), rec.emailid);
				break;
			}
			if(feof(fp)){
					break;	
			}
		}
		fclose(fp);		
	}
}
											/*end of search functions*/

/********************************GTK CODE BEGINS FROM HERE****************/

/***************************************************************************frame that displays students who had left hostel*/
void view_student_left(GtkWidget *widget, Window_grid *win_grid){
	GtkWidget *close;
	addstu_grid = gtk_grid_new();					/*initializing new grid**/
	gtk_container_remove(GTK_CONTAINER(win_grid->window), win_grid->grid);/**removing previous grid***/
	gtk_container_add(GTK_CONTAINER(win_grid->window), addstu_grid);/***attaching or adding new grid to current window**/
	win_grid->grid = addstu_grid;
	Gc_label *structlabel;
	structlabel = (Gc_label *)malloc(sizeof(Gc_label));		/**allocating memory to structure of widgets and buttons used***/
	structlabel->window = win_grid->window;
							/****defining buttons and labels****/
	labelhead = gtk_label_new(NULL);
	gtk_label_set_markup(GTK_LABEL(labelhead), "<b><big>       STUDENT LEFT HOSTEL</big></b>\n");
	labelnull = gtk_label_new(" ");
	label1 = gtk_label_new("");
	label2 = gtk_label_new("");
	label3 = gtk_label_new("");
	label4= gtk_label_new("");
	label5 = gtk_label_new("");
	label6= gtk_label_new("");
	label7 = gtk_label_new("");
	label11 = gtk_label_new("         MIS      ");
	label12 = gtk_label_new("        NAME        ");
	label13 = gtk_label_new("        ADDRESS     ");
	label14= gtk_label_new("         BRANCH      ");
	label15 = gtk_label_new("      ROOMNO     ");
	label16= gtk_label_new("         MOBILE-NO      ");
	label17 = gtk_label_new("                 EMAIL-ID               ");
	label18 = gtk_label_new("	DATE OF JOIN	");
	label19 = gtk_label_new("	DATE OF LEAVE	");
	structlabel->label28 = gtk_label_new("");
	structlabel->label29 = gtk_label_new("");
	structlabel->label38 = gtk_label_new("");
	structlabel->label48 = gtk_label_new("");
	structlabel->label58 = gtk_label_new("");
	structlabel->label68 = gtk_label_new("");
	structlabel->label78 = gtk_label_new("");
	structlabel->label88 = gtk_label_new("");
	structlabel->label98 = gtk_label_new("");
	structlabel->label108 = gtk_label_new("");
	structlabel->label118 = gtk_label_new("");
	structlabel->label128 = gtk_label_new("");
	structlabel->label138 = gtk_label_new("");
	structlabel->label148 = gtk_label_new("");
	structlabel->label158 = gtk_label_new("");
	structlabel->label168 = gtk_label_new("");
	structlabel->label39 = gtk_label_new("");
	structlabel->label49 = gtk_label_new("");
	structlabel->label59 = gtk_label_new("");
	structlabel->label69 = gtk_label_new("");
	structlabel->label79 = gtk_label_new("");
	structlabel->label89 = gtk_label_new("");
	structlabel->label99 = gtk_label_new("");
	structlabel->label109 = gtk_label_new("");
	structlabel->label119 = gtk_label_new("");
	structlabel->label129 = gtk_label_new("");
	structlabel->label139 = gtk_label_new("");
	structlabel->label149 = gtk_label_new("");
	structlabel->label159 = gtk_label_new("");
	structlabel->label169 = gtk_label_new("");
	labeln21 = gtk_label_new("");
	labeln22 = gtk_label_new("");
	labeln23 = gtk_label_new("");
	labeln24= gtk_label_new("");
	labeln25 = gtk_label_new("");
	labeln26= gtk_label_new("");
	labeln27 = gtk_label_new("");
	add = gtk_button_new_with_label("Add Student Details");
	search = gtk_button_new_with_label(" Search student Details ");
	edit = gtk_button_new_with_label("Edit student Details");
	delete = gtk_button_new_with_label("Delete student Details");
	btn6 = gtk_button_new_with_label("View student Details");
	close = gtk_button_new_with_label("Close Application");
	structlabel->label21 = gtk_label_new("");
	structlabel->label22 = gtk_label_new("");
	structlabel->label23 = gtk_label_new("");
	structlabel->label24= gtk_label_new("");
	structlabel->label25 = gtk_label_new("");
	structlabel->label26= gtk_label_new("");
	structlabel->label27 = gtk_label_new("");
	structlabel->label31 = gtk_label_new("");
	structlabel->label32 = gtk_label_new("");
	structlabel->label33 = gtk_label_new("");
	structlabel->label34= gtk_label_new("");
	structlabel->label35 = gtk_label_new("");
	structlabel->label36= gtk_label_new("");
	structlabel->label37 = gtk_label_new("");
	labeln31 = gtk_label_new("");
	labeln32 = gtk_label_new("");
	labeln33 = gtk_label_new("");
	labeln34= gtk_label_new("");
	labeln35 = gtk_label_new("");
	labeln36= gtk_label_new("");
	labeln37 = gtk_label_new("");
	labeln41 = gtk_label_new("");
	labeln42 = gtk_label_new("");
	labeln43 = gtk_label_new("");
	labeln44= gtk_label_new("");
	labeln45 = gtk_label_new("");
	labeln46= gtk_label_new("");
	labeln47 = gtk_label_new("");
	structlabel->label41 = gtk_label_new("");
	structlabel->label42 = gtk_label_new("");
	structlabel->label43 = gtk_label_new("");
	structlabel->label44= gtk_label_new("");
	structlabel->label45 = gtk_label_new("");
	structlabel->label46= gtk_label_new("");
	structlabel->label47 = gtk_label_new("");
	structlabel->label51 = gtk_label_new("");
	structlabel->label52 = gtk_label_new("");
	structlabel->label53 = gtk_label_new("");
	structlabel->label54= gtk_label_new("");
	structlabel->label55 = gtk_label_new("");
	structlabel->label56= gtk_label_new("");
	structlabel->label57 = gtk_label_new("");
	structlabel->label61 = gtk_label_new("");
	structlabel->label62 = gtk_label_new("");
	structlabel->label63 = gtk_label_new("");
	structlabel->label64= gtk_label_new("");
	structlabel->label65 = gtk_label_new("");
	structlabel->label66= gtk_label_new("");
	structlabel->label67 = gtk_label_new("");
	structlabel->label71 = gtk_label_new("");
	structlabel->label72 = gtk_label_new("");
	structlabel->label73 = gtk_label_new("");
	structlabel->label74= gtk_label_new("");
	structlabel->label75 = gtk_label_new("");
	structlabel->label76= gtk_label_new("");
	structlabel->label77 = gtk_label_new("");
	structlabel->label81 = gtk_label_new("");
	structlabel->label82 = gtk_label_new("");
	structlabel->label83 = gtk_label_new("");
	structlabel->label84= gtk_label_new("");
	structlabel->label85 = gtk_label_new("");
	structlabel->label86= gtk_label_new("");
	structlabel->label87 = gtk_label_new("");
	structlabel->label91 = gtk_label_new("");
	structlabel->label92 = gtk_label_new("");
	structlabel->label93 = gtk_label_new("");
	structlabel->label94= gtk_label_new("");
	structlabel->label95 = gtk_label_new("");
	structlabel->label96= gtk_label_new("");
	structlabel->label97 = gtk_label_new("");
	structlabel->label101 = gtk_label_new("");
	structlabel->label102 = gtk_label_new("");
	structlabel->label103 = gtk_label_new("");
	structlabel->label104= gtk_label_new("");
	structlabel->label105 = gtk_label_new("");
	structlabel->label106= gtk_label_new("");
	structlabel->label107 = gtk_label_new("");
	structlabel->label111 = gtk_label_new("");
	structlabel->label112 = gtk_label_new("");
	structlabel->label113 = gtk_label_new("");
	structlabel->label114= gtk_label_new("");
	structlabel->label115 = gtk_label_new("");
	structlabel->label116= gtk_label_new("");
	structlabel->label117 = gtk_label_new("");
	structlabel->label121 = gtk_label_new("");
	structlabel->label122 = gtk_label_new("");
	structlabel->label123 = gtk_label_new("");
	structlabel->label124= gtk_label_new("");
	structlabel->label125 = gtk_label_new("");
	structlabel->label126= gtk_label_new("");
	structlabel->label127 = gtk_label_new("");
	structlabel->label131 = gtk_label_new("");
	structlabel->label132 = gtk_label_new("");
	structlabel->label133 = gtk_label_new("");
	structlabel->label134= gtk_label_new("");
	structlabel->label135 = gtk_label_new("");
	structlabel->label136= gtk_label_new("");
	structlabel->label137 = gtk_label_new("");
	structlabel->label141 = gtk_label_new("");
	structlabel->label142 = gtk_label_new("");
	structlabel->label143 = gtk_label_new("");
	structlabel->label144= gtk_label_new("");
	structlabel->label145 = gtk_label_new("");
	structlabel->label146= gtk_label_new("");
	structlabel->label147 = gtk_label_new("");
	structlabel->label151 = gtk_label_new("");
	structlabel->label152 = gtk_label_new("");
	structlabel->label153 = gtk_label_new("");
	structlabel->label154= gtk_label_new("");
	structlabel->label155 = gtk_label_new("");
	structlabel->label156= gtk_label_new("");
	structlabel->label157 = gtk_label_new("");
	structlabel->label161 = gtk_label_new("");
	structlabel->label162 = gtk_label_new("");
	structlabel->label163 = gtk_label_new("");
	structlabel->label164= gtk_label_new("");
	structlabel->label165 = gtk_label_new("");
	structlabel->label166= gtk_label_new("");
	structlabel->label167 = gtk_label_new("");
	btn1 = gtk_button_new_with_label("DELETE");
	btn2 = gtk_button_new_with_label("HOME");
	btn3 = gtk_button_new_with_label("PASTE");
	btn4 = gtk_button_new_with_label("CLEAR");
	btn5 = gtk_button_new_with_label("DELETE by MIS");
	btnnxt = gtk_button_new_with_label("NEXT");
	btnpre = gtk_button_new_with_label("PREVIOUS");
	btnref = gtk_button_new_with_label("LIST OF STUDENT");
						/*****Signals(events) occurs when end users responds to GtkWidgets***/
	g_signal_connect(btn1, "clicked", G_CALLBACK(delete_student), structlabel);
	g_signal_connect(btn5, "clicked", G_CALLBACK(searchinfile1), structlabel);
	g_signal_connect(btn4, "clicked", G_CALLBACK(cleartext), structlabel);
	g_signal_connect(btn2, "clicked", G_CALLBACK(activate), win_grid);
	g_signal_connect(btn3, "clicked", G_CALLBACK(searchinfiledynamic), structlabel);
	g_signal_connect(btnnxt, "clicked", G_CALLBACK(nextleave), structlabel);
	g_signal_connect(btnpre, "clicked", G_CALLBACK(prevleft), structlabel);
	g_signal_connect(btnref, "clicked", G_CALLBACK(view_student), win_grid);
	g_signal_connect(add, "clicked", G_CALLBACK(addstudent_details), win_grid);
	g_signal_connect(search, "clicked", G_CALLBACK(search_student_details), win_grid);
	g_signal_connect(edit, "clicked", G_CALLBACK(editstudent_details), win_grid);
	g_signal_connect(delete, "clicked", G_CALLBACK(deletestudent_details), win_grid);
	g_signal_connect(btn6, "clicked", G_CALLBACK(view_student), win_grid);
	g_signal_connect(close, "clicked", G_CALLBACK(close_window), win_grid->window);
	p = 0;
	FILE *fp = fopen("studleave.txt","r+");
	while(1){			/***displaying file contents on frame****/
		fscanf(fp, "%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\n]\n", rec.mis,  rec.name, rec.address, rec.branch, rec.blockno, rec.mobileno, rec.emailid, rec.date, rec.leave);
		if(p == 0) {	
			gtk_label_set_text(GTK_LABEL(structlabel->label21), rec.mis);
			gtk_label_set_text(GTK_LABEL(structlabel->label22), rec.name);
			gtk_label_set_text(GTK_LABEL(structlabel->label23), rec.address);
			gtk_label_set_text(GTK_LABEL(structlabel->label24), rec.branch);
			gtk_label_set_text(GTK_LABEL(structlabel->label25), rec.blockno);
			gtk_label_set_text(GTK_LABEL(structlabel->label26), rec.mobileno);
			gtk_label_set_text(GTK_LABEL(structlabel->label27), rec.emailid);
			gtk_label_set_text(GTK_LABEL(structlabel->label28), rec.date);
			gtk_label_set_text(GTK_LABEL(structlabel->label29), rec.leave);
		}
		else if(p == 1) {	
			gtk_label_set_text(GTK_LABEL(structlabel->label31), rec.mis);
			gtk_label_set_text(GTK_LABEL(structlabel->label32), rec.name);
			gtk_label_set_text(GTK_LABEL(structlabel->label33), rec.address);
			gtk_label_set_text(GTK_LABEL(structlabel->label34), rec.branch);
			gtk_label_set_text(GTK_LABEL(structlabel->label35), rec.blockno);
			gtk_label_set_text(GTK_LABEL(structlabel->label36), rec.mobileno);
			gtk_label_set_text(GTK_LABEL(structlabel->label37), rec.emailid);
			gtk_label_set_text(GTK_LABEL(structlabel->label38), rec.date);
			gtk_label_set_text(GTK_LABEL(structlabel->label39), rec.leave);
		}
		else if(p == 2) {	
			gtk_label_set_text(GTK_LABEL(structlabel->label41), rec.mis);
			gtk_label_set_text(GTK_LABEL(structlabel->label42), rec.name);
			gtk_label_set_text(GTK_LABEL(structlabel->label43), rec.address);
			gtk_label_set_text(GTK_LABEL(structlabel->label44), rec.branch);
			gtk_label_set_text(GTK_LABEL(structlabel->label45), rec.blockno);
			gtk_label_set_text(GTK_LABEL(structlabel->label46), rec.mobileno);
			gtk_label_set_text(GTK_LABEL(structlabel->label47), rec.emailid);
			gtk_label_set_text(GTK_LABEL(structlabel->label48), rec.date);
			gtk_label_set_text(GTK_LABEL(structlabel->label49), rec.leave);
		}
		else if(p == 3) {	
			gtk_label_set_text(GTK_LABEL(structlabel->label51), rec.mis);
			gtk_label_set_text(GTK_LABEL(structlabel->label52), rec.name);
			gtk_label_set_text(GTK_LABEL(structlabel->label53), rec.address);
			gtk_label_set_text(GTK_LABEL(structlabel->label54), rec.branch);
			gtk_label_set_text(GTK_LABEL(structlabel->label55), rec.blockno);
			gtk_label_set_text(GTK_LABEL(structlabel->label56), rec.mobileno);
			gtk_label_set_text(GTK_LABEL(structlabel->label57), rec.emailid);
			gtk_label_set_text(GTK_LABEL(structlabel->label58), rec.date);
			gtk_label_set_text(GTK_LABEL(structlabel->label59), rec.leave);
		}
		else if(p == 4) {	
			gtk_label_set_text(GTK_LABEL(structlabel->label61), rec.mis);
			gtk_label_set_text(GTK_LABEL(structlabel->label62), rec.name);
			gtk_label_set_text(GTK_LABEL(structlabel->label63), rec.address);
			gtk_label_set_text(GTK_LABEL(structlabel->label64), rec.branch);
			gtk_label_set_text(GTK_LABEL(structlabel->label65), rec.blockno);
			gtk_label_set_text(GTK_LABEL(structlabel->label66), rec.mobileno);
			gtk_label_set_text(GTK_LABEL(structlabel->label67), rec.emailid);
			gtk_label_set_text(GTK_LABEL(structlabel->label68), rec.date);
			gtk_label_set_text(GTK_LABEL(structlabel->label69), rec.leave);
		}
		else if(p == 5) {	
			gtk_label_set_text(GTK_LABEL(structlabel->label71), rec.mis);
			gtk_label_set_text(GTK_LABEL(structlabel->label72), rec.name);
			gtk_label_set_text(GTK_LABEL(structlabel->label73), rec.address);
			gtk_label_set_text(GTK_LABEL(structlabel->label74), rec.branch);
			gtk_label_set_text(GTK_LABEL(structlabel->label75), rec.blockno);
			gtk_label_set_text(GTK_LABEL(structlabel->label76), rec.mobileno);
			gtk_label_set_text(GTK_LABEL(structlabel->label77), rec.emailid);
			gtk_label_set_text(GTK_LABEL(structlabel->label78), rec.date);
			gtk_label_set_text(GTK_LABEL(structlabel->label79), rec.leave);
		}
		else if(p == 6) {	
			gtk_label_set_text(GTK_LABEL(structlabel->label81), rec.mis);
			gtk_label_set_text(GTK_LABEL(structlabel->label82), rec.name);
			gtk_label_set_text(GTK_LABEL(structlabel->label83), rec.address);
			gtk_label_set_text(GTK_LABEL(structlabel->label84), rec.branch);
			gtk_label_set_text(GTK_LABEL(structlabel->label85), rec.blockno);
			gtk_label_set_text(GTK_LABEL(structlabel->label86), rec.mobileno);
			gtk_label_set_text(GTK_LABEL(structlabel->label87), rec.emailid);
			gtk_label_set_text(GTK_LABEL(structlabel->label88), rec.date);
			gtk_label_set_text(GTK_LABEL(structlabel->label89), rec.leave);
		}
		else if(p == 7) {	
			gtk_label_set_text(GTK_LABEL(structlabel->label91), rec.mis);
			gtk_label_set_text(GTK_LABEL(structlabel->label92), rec.name);
			gtk_label_set_text(GTK_LABEL(structlabel->label93), rec.address);
			gtk_label_set_text(GTK_LABEL(structlabel->label94), rec.branch);
			gtk_label_set_text(GTK_LABEL(structlabel->label95), rec.blockno);
			gtk_label_set_text(GTK_LABEL(structlabel->label96), rec.mobileno);
			gtk_label_set_text(GTK_LABEL(structlabel->label97), rec.emailid);
			gtk_label_set_text(GTK_LABEL(structlabel->label98), rec.date);
			gtk_label_set_text(GTK_LABEL(structlabel->label99), rec.leave);
		}
		else if(p == 8) {	
			gtk_label_set_text(GTK_LABEL(structlabel->label101), rec.mis);
			gtk_label_set_text(GTK_LABEL(structlabel->label102), rec.name);
			gtk_label_set_text(GTK_LABEL(structlabel->label103), rec.address);
			gtk_label_set_text(GTK_LABEL(structlabel->label104), rec.branch);
			gtk_label_set_text(GTK_LABEL(structlabel->label105), rec.blockno);
			gtk_label_set_text(GTK_LABEL(structlabel->label106), rec.mobileno);
			gtk_label_set_text(GTK_LABEL(structlabel->label107), rec.emailid);
			gtk_label_set_text(GTK_LABEL(structlabel->label108), rec.date);
			gtk_label_set_text(GTK_LABEL(structlabel->label109), rec.leave);
		}
		else if(p == 9) {	
			gtk_label_set_text(GTK_LABEL(structlabel->label111), rec.mis);
			gtk_label_set_text(GTK_LABEL(structlabel->label112), rec.name);
			gtk_label_set_text(GTK_LABEL(structlabel->label113), rec.address);
			gtk_label_set_text(GTK_LABEL(structlabel->label114), rec.branch);
			gtk_label_set_text(GTK_LABEL(structlabel->label115), rec.blockno);
			gtk_label_set_text(GTK_LABEL(structlabel->label116), rec.mobileno);
			gtk_label_set_text(GTK_LABEL(structlabel->label117), rec.emailid);
			gtk_label_set_text(GTK_LABEL(structlabel->label118), rec.date);
			gtk_label_set_text(GTK_LABEL(structlabel->label119), rec.leave);
		}
		else if(p == 10) {	
			gtk_label_set_text(GTK_LABEL(structlabel->label121), rec.mis);
			gtk_label_set_text(GTK_LABEL(structlabel->label122), rec.name);
			gtk_label_set_text(GTK_LABEL(structlabel->label123), rec.address);
			gtk_label_set_text(GTK_LABEL(structlabel->label124), rec.branch);
			gtk_label_set_text(GTK_LABEL(structlabel->label125), rec.blockno);
			gtk_label_set_text(GTK_LABEL(structlabel->label126), rec.mobileno);
			gtk_label_set_text(GTK_LABEL(structlabel->label127), rec.emailid);
			gtk_label_set_text(GTK_LABEL(structlabel->label128), rec.date);
			gtk_label_set_text(GTK_LABEL(structlabel->label129), rec.leave);
		}
		else if(p == 11) {	
			gtk_label_set_text(GTK_LABEL(structlabel->label131), rec.mis);
			gtk_label_set_text(GTK_LABEL(structlabel->label132), rec.name);
			gtk_label_set_text(GTK_LABEL(structlabel->label133), rec.address);
			gtk_label_set_text(GTK_LABEL(structlabel->label134), rec.branch);
			gtk_label_set_text(GTK_LABEL(structlabel->label135), rec.blockno);
			gtk_label_set_text(GTK_LABEL(structlabel->label136), rec.mobileno);
			gtk_label_set_text(GTK_LABEL(structlabel->label137), rec.emailid);
			gtk_label_set_text(GTK_LABEL(structlabel->label138), rec.date);
			gtk_label_set_text(GTK_LABEL(structlabel->label139), rec.leave);
		}
		else if(p == 12) {	
			gtk_label_set_text(GTK_LABEL(structlabel->label141), rec.mis);
			gtk_label_set_text(GTK_LABEL(structlabel->label142), rec.name);
			gtk_label_set_text(GTK_LABEL(structlabel->label143), rec.address);
			gtk_label_set_text(GTK_LABEL(structlabel->label144), rec.branch);
			gtk_label_set_text(GTK_LABEL(structlabel->label145), rec.blockno);
			gtk_label_set_text(GTK_LABEL(structlabel->label146), rec.mobileno);
			gtk_label_set_text(GTK_LABEL(structlabel->label147), rec.emailid);
			gtk_label_set_text(GTK_LABEL(structlabel->label148), rec.date);
			gtk_label_set_text(GTK_LABEL(structlabel->label149), rec.leave);
		}
		else if(p == 13) {	
			gtk_label_set_text(GTK_LABEL(structlabel->label151), rec.mis);
			gtk_label_set_text(GTK_LABEL(structlabel->label152), rec.name);
			gtk_label_set_text(GTK_LABEL(structlabel->label153), rec.address);
			gtk_label_set_text(GTK_LABEL(structlabel->label154), rec.branch);
			gtk_label_set_text(GTK_LABEL(structlabel->label155), rec.blockno);
			gtk_label_set_text(GTK_LABEL(structlabel->label156), rec.mobileno);
			gtk_label_set_text(GTK_LABEL(structlabel->label157), rec.emailid);
			gtk_label_set_text(GTK_LABEL(structlabel->label158), rec.date);
			gtk_label_set_text(GTK_LABEL(structlabel->label159), rec.leave);
		}
		else if(p == 14) {	
			gtk_label_set_text(GTK_LABEL(structlabel->label161), rec.mis);
			gtk_label_set_text(GTK_LABEL(structlabel->label162), rec.name);
			gtk_label_set_text(GTK_LABEL(structlabel->label163), rec.address);
			gtk_label_set_text(GTK_LABEL(structlabel->label164), rec.branch);
			gtk_label_set_text(GTK_LABEL(structlabel->label165), rec.blockno);
			gtk_label_set_text(GTK_LABEL(structlabel->label166), rec.mobileno);
			gtk_label_set_text(GTK_LABEL(structlabel->label167), rec.emailid);
			gtk_label_set_text(GTK_LABEL(structlabel->label168), rec.date);
			gtk_label_set_text(GTK_LABEL(structlabel->label169), rec.leave);
			p=0;
			break;
		}
		if(feof(fp)){
			break;	
		}
		p++;
	}
	fclose(fp);							 /*adding Widgets to frame*/
	gtk_grid_attach(GTK_GRID(win_grid->grid), label1, 0, 5, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), label2, 0, 6, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), label3, 0, 7, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), label4, 0, 8, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), label5, 0, 9, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), label6, 0, 10, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), label7, 0, 11, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), labelhead, 2, 2, 8 , 2);
	gtk_grid_attach(GTK_GRID(win_grid->grid), label11, 2, 5, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), label12, 3, 5, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), label13, 4, 5, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), label14, 5, 5, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), label15, 6, 5, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), label16, 7, 5, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), label17, 8 , 5, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), label18, 9 , 5, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), label19, 10, 5, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), labeln21, 2, 6, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), labeln22, 3, 6, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), labeln23, 4, 6, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), labeln24, 5, 6, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), labeln25, 6, 6, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), labeln26, 7,6, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), labeln27, 8, 6, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), labeln31, 2, 1, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), labeln32, 3, 1, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), labeln33, 4, 1, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), labeln34, 5, 1, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), labeln35, 6, 1, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), labeln36, 7,1, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), labeln37, 8,1, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), labeln41, 2, 4, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), labeln42, 3, 4, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), labeln43, 4, 4, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), labeln44, 5, 4, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), labeln45, 6, 4, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), labeln46, 7,4, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), labeln47, 8,4, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label21, 2, 7, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label22, 3, 7, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label23, 4, 7, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label24, 5, 7, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label25, 6, 7, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label26, 7,7, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label27, 8, 7, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label31, 2, 8, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label32, 3, 8, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label33, 4, 8, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label34, 5, 8, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label35, 6, 8, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label36, 7,8, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label37, 8, 8, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label41, 2, 9, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label42, 3, 9, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label43, 4, 9, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label44, 5, 9, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label45, 6, 9, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label46, 7,9, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label47, 8, 9, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label51, 2, 10, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label52, 3, 10, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label53, 4, 10, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label54, 5, 10, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label55, 6, 10, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label56, 7,10, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label57, 8,10, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label61, 2, 11, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label62, 3, 11, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label63, 4, 11, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label64, 5, 11, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label65, 6, 11, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label66, 7,11, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label67, 8,11, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label71, 2, 12, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label72, 3, 12, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label73, 4, 12, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label74, 5, 12, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label75, 6, 12, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label76, 7,12, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label77, 8,12, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label81, 2, 13, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label82, 3, 13, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label83, 4, 13, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label84, 5, 13, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label85, 6, 13, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label86, 7,13, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label87, 8,13, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label91, 2, 14, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label92, 3, 14, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label93, 4, 14, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label94, 5, 14, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label95, 6, 14, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label96, 7,14, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label97, 8,14, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label101, 2, 15, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label102, 3, 15, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label103, 4, 15, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label104, 5, 15, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label105, 6, 15, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label106, 7,15, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label107, 8,15, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label111, 2, 16, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label112, 3, 16, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label113, 4, 16, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label114, 5, 16, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label115, 6, 16, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label116, 7,16, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label117, 8,16, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label121, 2, 17, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label122, 3, 17, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label123, 4, 17, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label124, 5, 17, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label125, 6, 17, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label126, 7,17, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label127, 8,17, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label131, 2, 18, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label132, 3, 18, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label133, 4, 18, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label134, 5, 18, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label135, 6, 18, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label136, 7,18, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label137, 8,18, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label141, 2, 19,1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label142, 3, 19, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label143, 4, 19, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label144, 5, 19, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label145, 6, 19, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label146, 7,19, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label147, 8,19, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label151, 2, 20, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label152, 3, 20, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label153,4, 20, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label154, 5, 20, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label155, 6, 20, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label156, 7,20, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label157, 8,20, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label161, 2, 21, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label162, 3, 21, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label163, 4, 21, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label164, 5, 21, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label165, 6, 21, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label166, 7,21, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label167, 8,21, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label28, 9,7, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label38, 9,8, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label48, 9,9, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label58, 9,10, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label68, 9,11, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label78, 9,12, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label88, 9,13, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label98, 9,14, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label108, 9,15, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label118, 9,16, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label128, 9,17, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label138, 9,18, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label148, 9,19, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label158, 9,20, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label168, 9,21, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label29, 10,7, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label39, 10,8, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label49, 10,9, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label59, 10,10, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label69, 10,11, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label79, 10,12, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label89, 10,13, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label99, 10,14, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label109,10,15, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label119,10,16, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label129,10,17, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label139,10,18, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label149,10,19, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label159,10,20, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label169,10,21, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), btnnxt, 9,23, 2, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), btnpre, 2,23, 2, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), btnref, 6,23, 2, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), labelnull,6, 22, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), add, 0, 0, 2, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), search, 2, 0, 2, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), edit, 4, 0, 2, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), delete, 6, 0, 2, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), btn6, 8, 0, 2, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), close, 10, 0, 2, 1);
	gtk_widget_show_all(win_grid->window);
	return;
}

/**********************************************************************************frame that displays students living in hostel*/
void view_student(GtkWidget *widget, Window_grid *win_grid){
	GtkWidget *close;
	addstu_grid = gtk_grid_new();
	gtk_container_remove(GTK_CONTAINER(win_grid->window), win_grid->grid);
	gtk_container_add(GTK_CONTAINER(win_grid->window), addstu_grid);
	win_grid->grid = addstu_grid;
	Gc_label *structlabel;
	structlabel = (Gc_label *)malloc(sizeof(Gc_label));
	structlabel->window = win_grid->window;
	labelhead = gtk_label_new(NULL);
	gtk_label_set_markup(GTK_LABEL(labelhead), "<b><big>LIST OF STUDENT</big></b>\n");
	labelnull = gtk_label_new(" ");
	label1 = gtk_label_new("MIS");
	label7 = gtk_label_new("Total Students :");
	label11 = gtk_label_new("         MIS        ");
	label12 = gtk_label_new("        NAME        ");
	label13 = gtk_label_new("        ADDRESS     ");
	label14= gtk_label_new("         BRANCH      ");
	label15 = gtk_label_new("   ROOMNO   ");
	label16= gtk_label_new("         MOBILE-NO      ");
	label17 = gtk_label_new("                 EMAIL-ID               ");
	label18 = gtk_label_new("	DATE OF JOIN	");
	structlabel->label28 = gtk_label_new("");
	structlabel->label38 = gtk_label_new("");
	structlabel->label48 = gtk_label_new("");
	structlabel->label58 = gtk_label_new("");
	structlabel->label68 = gtk_label_new("");
	structlabel->label78 = gtk_label_new("");
	structlabel->label88 = gtk_label_new("");
	structlabel->label98 = gtk_label_new("");
	structlabel->label108 = gtk_label_new("");
	structlabel->label118 = gtk_label_new("");
	structlabel->label128 = gtk_label_new("");
	structlabel->label138 = gtk_label_new("");
	structlabel->label148 = gtk_label_new("");
	structlabel->label158 = gtk_label_new("");
	structlabel->label168 = gtk_label_new("");
	labeln21 = gtk_label_new("");
	labeln22 = gtk_label_new("");
	labeln23 = gtk_label_new("");
	labeln24= gtk_label_new("");
	labeln25 = gtk_label_new("");
	labeln26= gtk_label_new("");
	labeln27 = gtk_label_new("");
	add = gtk_button_new_with_label("Add Student Details");
	search = gtk_button_new_with_label("Search student Details");
	edit = gtk_button_new_with_label("Edit student Details");
	delete = gtk_button_new_with_label("Delete student Details");
	btn6 = gtk_button_new_with_label("View student Details");
	close = gtk_button_new_with_label("Close Application");
	structlabel->label21 = gtk_label_new("");
	structlabel->label22 = gtk_label_new("");
	structlabel->label23 = gtk_label_new("");
	structlabel->label24= gtk_label_new("");
	structlabel->label25 = gtk_label_new("");
	structlabel->label26= gtk_label_new("");
	structlabel->label27 = gtk_label_new("");
	structlabel->label31 = gtk_label_new("");
	structlabel->label32 = gtk_label_new("");
	structlabel->label33 = gtk_label_new("");
	structlabel->label34= gtk_label_new("");
	structlabel->label35 = gtk_label_new("");
	structlabel->label36= gtk_label_new("");
	structlabel->label37 = gtk_label_new("");
	labeln31 = gtk_label_new("");
	labeln32 = gtk_label_new("");
	labeln33 = gtk_label_new("");
	labeln34= gtk_label_new("");
	labeln35 = gtk_label_new("");
	labeln36= gtk_label_new("");
	labeln37 = gtk_label_new("");
	labeln41 = gtk_label_new("");
	labeln42 = gtk_label_new("");
	labeln43 = gtk_label_new("");
	labeln44= gtk_label_new("");
	labeln45 = gtk_label_new("");
	labeln46= gtk_label_new("");
	labeln47 = gtk_label_new("");
	structlabel->label41 = gtk_label_new("");
	structlabel->label42 = gtk_label_new("");
	structlabel->label43 = gtk_label_new("");
	structlabel->label44= gtk_label_new("");
	structlabel->label45 = gtk_label_new("");
	structlabel->label46= gtk_label_new("");
	structlabel->label47 = gtk_label_new("");
	structlabel->label51 = gtk_label_new("");
	structlabel->label52 = gtk_label_new("");
	structlabel->label53 = gtk_label_new("");
	structlabel->label54= gtk_label_new("");
	structlabel->label55 = gtk_label_new("");
	structlabel->label56= gtk_label_new("");
	structlabel->label57 = gtk_label_new("");
	structlabel->label61 = gtk_label_new("");
	structlabel->label62 = gtk_label_new("");
	structlabel->label63 = gtk_label_new("");
	structlabel->label64= gtk_label_new("");
	structlabel->label65 = gtk_label_new("");
	structlabel->label66= gtk_label_new("");
	structlabel->label67 = gtk_label_new("");
	structlabel->label71 = gtk_label_new("");
	structlabel->label72 = gtk_label_new("");
	structlabel->label73 = gtk_label_new("");
	structlabel->label74= gtk_label_new("");
	structlabel->label75 = gtk_label_new("");
	structlabel->label76= gtk_label_new("");
	structlabel->label77 = gtk_label_new("");
	structlabel->label81 = gtk_label_new("");
	structlabel->label82 = gtk_label_new("");
	structlabel->label83 = gtk_label_new("");
	structlabel->label84= gtk_label_new("");
	structlabel->label85 = gtk_label_new("");
	structlabel->label86= gtk_label_new("");
	structlabel->label87 = gtk_label_new("");
	structlabel->label91 = gtk_label_new("");
	structlabel->label92 = gtk_label_new("");
	structlabel->label93 = gtk_label_new("");
	structlabel->label94= gtk_label_new("");
	structlabel->label95 = gtk_label_new("");
	structlabel->label96= gtk_label_new("");
	structlabel->label97 = gtk_label_new("");
	structlabel->label101 = gtk_label_new("");
	structlabel->label102 = gtk_label_new("");
	structlabel->label103 = gtk_label_new("");
	structlabel->label104= gtk_label_new("");
	structlabel->label105 = gtk_label_new("");
	structlabel->label106= gtk_label_new("");
	structlabel->label107 = gtk_label_new("");
	structlabel->label111 = gtk_label_new("");
	structlabel->label112 = gtk_label_new("");
	structlabel->label113 = gtk_label_new("");
	structlabel->label114= gtk_label_new("");
	structlabel->label115 = gtk_label_new("");
	structlabel->label116= gtk_label_new("");
	structlabel->label117 = gtk_label_new("");
	structlabel->label121 = gtk_label_new("");
	structlabel->label122 = gtk_label_new("");
	structlabel->label123 = gtk_label_new("");
	structlabel->label124= gtk_label_new("");
	structlabel->label125 = gtk_label_new("");
	structlabel->label126= gtk_label_new("");
	structlabel->label127 = gtk_label_new("");
	structlabel->label131 = gtk_label_new("");
	structlabel->label132 = gtk_label_new("");
	structlabel->label133 = gtk_label_new("");
	structlabel->label134= gtk_label_new("");
	structlabel->label135 = gtk_label_new("");
	structlabel->label136= gtk_label_new("");
	structlabel->label137 = gtk_label_new("");
	structlabel->label141 = gtk_label_new("");
	structlabel->label142 = gtk_label_new("");
	structlabel->label143 = gtk_label_new("");
	structlabel->label144= gtk_label_new("");
	structlabel->label145 = gtk_label_new("");
	structlabel->label146= gtk_label_new("");
	structlabel->label147 = gtk_label_new("");
	structlabel->label151 = gtk_label_new("");
	structlabel->label152 = gtk_label_new("");
	structlabel->label153 = gtk_label_new("");
	structlabel->label154= gtk_label_new("");
	structlabel->label155 = gtk_label_new("");
	structlabel->label156= gtk_label_new("");
	structlabel->label157 = gtk_label_new("");
	structlabel->label161 = gtk_label_new("");
	structlabel->label162 = gtk_label_new("");
	structlabel->label163 = gtk_label_new("");
	structlabel->label164= gtk_label_new("");
	structlabel->label165 = gtk_label_new("");
	structlabel->label166= gtk_label_new("");
	structlabel->label167 = gtk_label_new("");
	btn1 = gtk_button_new_with_label("DELETE");
	btn2 = gtk_button_new_with_label("HOME");
	btn3 = gtk_button_new_with_label("PASTE");
	btn4 = gtk_button_new_with_label("CLEAR");
	btn5 = gtk_button_new_with_label("DELETE by MIS");
	btnnxt = gtk_button_new_with_label("NEXT");
	btnpre = gtk_button_new_with_label("PREVIOUS");
	btnref = gtk_button_new_with_label("LIST OF STUDENT LEFT");
	g_signal_connect(btn1, "clicked", G_CALLBACK(delete_student), structlabel);
	g_signal_connect(btn5, "clicked", G_CALLBACK(searchinfile1), structlabel);
	g_signal_connect(btn4, "clicked", G_CALLBACK(cleartext), structlabel);
	g_signal_connect(btn2, "clicked", G_CALLBACK(activate), win_grid);
	g_signal_connect(btn3, "clicked", G_CALLBACK(searchinfiledynamic), structlabel);
	g_signal_connect(btnnxt, "clicked", G_CALLBACK(nextnext), structlabel);
	g_signal_connect(btnpre, "clicked", G_CALLBACK(previous), structlabel);
	g_signal_connect(btnref, "clicked", G_CALLBACK(view_student_left), win_grid);
	g_signal_connect(add, "clicked", G_CALLBACK(addstudent_details), win_grid);
	g_signal_connect(search, "clicked", G_CALLBACK(search_student_details), win_grid);
	g_signal_connect(edit, "clicked", G_CALLBACK(editstudent_details), win_grid);
	g_signal_connect(delete, "clicked", G_CALLBACK(deletestudent_details), win_grid);
	g_signal_connect(btn6, "clicked", G_CALLBACK(view_student), win_grid);
	g_signal_connect(close, "clicked", G_CALLBACK(close_window), win_grid->window);
	p = 0;
	FILE *fp = fopen("studata.txt","r+");
	while(1){
		fscanf(fp, "%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\n]\n", rec.mis,  rec.name, rec.address, rec.branch, rec.blockno, rec.mobileno, rec.emailid, rec.date);
		if(p == 0) {	
			gtk_label_set_text(GTK_LABEL(structlabel->label21), rec.mis);
			gtk_label_set_text(GTK_LABEL(structlabel->label22), rec.name);
			gtk_label_set_text(GTK_LABEL(structlabel->label23), rec.address);
			gtk_label_set_text(GTK_LABEL(structlabel->label24), rec.branch);
			gtk_label_set_text(GTK_LABEL(structlabel->label25), rec.blockno);
			gtk_label_set_text(GTK_LABEL(structlabel->label26), rec.mobileno);
			gtk_label_set_text(GTK_LABEL(structlabel->label27), rec.emailid);
			gtk_label_set_text(GTK_LABEL(structlabel->label28), rec.date);
		}
		else if(p == 1) {	
			gtk_label_set_text(GTK_LABEL(structlabel->label31), rec.mis);
			gtk_label_set_text(GTK_LABEL(structlabel->label32), rec.name);
			gtk_label_set_text(GTK_LABEL(structlabel->label33), rec.address);
			gtk_label_set_text(GTK_LABEL(structlabel->label34), rec.branch);
			gtk_label_set_text(GTK_LABEL(structlabel->label35), rec.blockno);
			gtk_label_set_text(GTK_LABEL(structlabel->label36), rec.mobileno);
			gtk_label_set_text(GTK_LABEL(structlabel->label37), rec.emailid);
			gtk_label_set_text(GTK_LABEL(structlabel->label38), rec.date);
		}
		else if(p == 2) {	
			gtk_label_set_text(GTK_LABEL(structlabel->label41), rec.mis);
			gtk_label_set_text(GTK_LABEL(structlabel->label42), rec.name);
			gtk_label_set_text(GTK_LABEL(structlabel->label43), rec.address);
			gtk_label_set_text(GTK_LABEL(structlabel->label44), rec.branch);
			gtk_label_set_text(GTK_LABEL(structlabel->label45), rec.blockno);
			gtk_label_set_text(GTK_LABEL(structlabel->label46), rec.mobileno);
			gtk_label_set_text(GTK_LABEL(structlabel->label47), rec.emailid);
			gtk_label_set_text(GTK_LABEL(structlabel->label48), rec.date);
		}
		else if(p == 3) {	
			gtk_label_set_text(GTK_LABEL(structlabel->label51), rec.mis);
			gtk_label_set_text(GTK_LABEL(structlabel->label52), rec.name);
			gtk_label_set_text(GTK_LABEL(structlabel->label53), rec.address);
			gtk_label_set_text(GTK_LABEL(structlabel->label54), rec.branch);
			gtk_label_set_text(GTK_LABEL(structlabel->label55), rec.blockno);
			gtk_label_set_text(GTK_LABEL(structlabel->label56), rec.mobileno);
			gtk_label_set_text(GTK_LABEL(structlabel->label57), rec.emailid);
			gtk_label_set_text(GTK_LABEL(structlabel->label58), rec.date);
		}
		else if(p == 4) {	
			gtk_label_set_text(GTK_LABEL(structlabel->label61), rec.mis);
			gtk_label_set_text(GTK_LABEL(structlabel->label62), rec.name);
			gtk_label_set_text(GTK_LABEL(structlabel->label63), rec.address);
			gtk_label_set_text(GTK_LABEL(structlabel->label64), rec.branch);
			gtk_label_set_text(GTK_LABEL(structlabel->label65), rec.blockno);
			gtk_label_set_text(GTK_LABEL(structlabel->label66), rec.mobileno);
			gtk_label_set_text(GTK_LABEL(structlabel->label67), rec.emailid);
			gtk_label_set_text(GTK_LABEL(structlabel->label68), rec.date);
		}
		else if(p == 5) {	
			gtk_label_set_text(GTK_LABEL(structlabel->label71), rec.mis);
			gtk_label_set_text(GTK_LABEL(structlabel->label72), rec.name);
			gtk_label_set_text(GTK_LABEL(structlabel->label73), rec.address);
			gtk_label_set_text(GTK_LABEL(structlabel->label74), rec.branch);
			gtk_label_set_text(GTK_LABEL(structlabel->label75), rec.blockno);
			gtk_label_set_text(GTK_LABEL(structlabel->label76), rec.mobileno);
			gtk_label_set_text(GTK_LABEL(structlabel->label77), rec.emailid);
			gtk_label_set_text(GTK_LABEL(structlabel->label78), rec.date);
		}
		else if(p == 6) {	
			gtk_label_set_text(GTK_LABEL(structlabel->label81), rec.mis);
			gtk_label_set_text(GTK_LABEL(structlabel->label82), rec.name);
			gtk_label_set_text(GTK_LABEL(structlabel->label83), rec.address);
			gtk_label_set_text(GTK_LABEL(structlabel->label84), rec.branch);
			gtk_label_set_text(GTK_LABEL(structlabel->label85), rec.blockno);
			gtk_label_set_text(GTK_LABEL(structlabel->label86), rec.mobileno);
			gtk_label_set_text(GTK_LABEL(structlabel->label87), rec.emailid);
			gtk_label_set_text(GTK_LABEL(structlabel->label88), rec.date);
		}
		else if(p == 7) {	
			gtk_label_set_text(GTK_LABEL(structlabel->label91), rec.mis);
			gtk_label_set_text(GTK_LABEL(structlabel->label92), rec.name);
			gtk_label_set_text(GTK_LABEL(structlabel->label93), rec.address);
			gtk_label_set_text(GTK_LABEL(structlabel->label94), rec.branch);
			gtk_label_set_text(GTK_LABEL(structlabel->label95), rec.blockno);
			gtk_label_set_text(GTK_LABEL(structlabel->label96), rec.mobileno);
			gtk_label_set_text(GTK_LABEL(structlabel->label97), rec.emailid);
			gtk_label_set_text(GTK_LABEL(structlabel->label98), rec.date);
		}
		else if(p == 8) {	
			gtk_label_set_text(GTK_LABEL(structlabel->label101), rec.mis);
			gtk_label_set_text(GTK_LABEL(structlabel->label102), rec.name);
			gtk_label_set_text(GTK_LABEL(structlabel->label103), rec.address);
			gtk_label_set_text(GTK_LABEL(structlabel->label104), rec.branch);
			gtk_label_set_text(GTK_LABEL(structlabel->label105), rec.blockno);
			gtk_label_set_text(GTK_LABEL(structlabel->label106), rec.mobileno);
			gtk_label_set_text(GTK_LABEL(structlabel->label107), rec.emailid);
			gtk_label_set_text(GTK_LABEL(structlabel->label108), rec.date);
		}
		else if(p == 9) {	
			gtk_label_set_text(GTK_LABEL(structlabel->label111), rec.mis);
			gtk_label_set_text(GTK_LABEL(structlabel->label112), rec.name);
			gtk_label_set_text(GTK_LABEL(structlabel->label113), rec.address);
			gtk_label_set_text(GTK_LABEL(structlabel->label114), rec.branch);
			gtk_label_set_text(GTK_LABEL(structlabel->label115), rec.blockno);
			gtk_label_set_text(GTK_LABEL(structlabel->label116), rec.mobileno);
			gtk_label_set_text(GTK_LABEL(structlabel->label117), rec.emailid);
			gtk_label_set_text(GTK_LABEL(structlabel->label118), rec.date);
		}
		else if(p == 10) {	
			gtk_label_set_text(GTK_LABEL(structlabel->label121), rec.mis);
			gtk_label_set_text(GTK_LABEL(structlabel->label122), rec.name);
			gtk_label_set_text(GTK_LABEL(structlabel->label123), rec.address);
			gtk_label_set_text(GTK_LABEL(structlabel->label124), rec.branch);
			gtk_label_set_text(GTK_LABEL(structlabel->label125), rec.blockno);
			gtk_label_set_text(GTK_LABEL(structlabel->label126), rec.mobileno);
			gtk_label_set_text(GTK_LABEL(structlabel->label127), rec.emailid);
			gtk_label_set_text(GTK_LABEL(structlabel->label128), rec.date);
		}
		else if(p == 11) {	
			gtk_label_set_text(GTK_LABEL(structlabel->label131), rec.mis);
			gtk_label_set_text(GTK_LABEL(structlabel->label132), rec.name);
			gtk_label_set_text(GTK_LABEL(structlabel->label133), rec.address);
			gtk_label_set_text(GTK_LABEL(structlabel->label134), rec.branch);
			gtk_label_set_text(GTK_LABEL(structlabel->label135), rec.blockno);
			gtk_label_set_text(GTK_LABEL(structlabel->label136), rec.mobileno);
			gtk_label_set_text(GTK_LABEL(structlabel->label137), rec.emailid);
			gtk_label_set_text(GTK_LABEL(structlabel->label138), rec.date);
		}
		else if(p == 12) {	
			gtk_label_set_text(GTK_LABEL(structlabel->label141), rec.mis);
			gtk_label_set_text(GTK_LABEL(structlabel->label142), rec.name);
			gtk_label_set_text(GTK_LABEL(structlabel->label143), rec.address);
			gtk_label_set_text(GTK_LABEL(structlabel->label144), rec.branch);
			gtk_label_set_text(GTK_LABEL(structlabel->label145), rec.blockno);
			gtk_label_set_text(GTK_LABEL(structlabel->label146), rec.mobileno);
			gtk_label_set_text(GTK_LABEL(structlabel->label147), rec.emailid);
			gtk_label_set_text(GTK_LABEL(structlabel->label148), rec.date);
		}
		else if(p == 13) {	
			gtk_label_set_text(GTK_LABEL(structlabel->label151), rec.mis);
			gtk_label_set_text(GTK_LABEL(structlabel->label152), rec.name);
			gtk_label_set_text(GTK_LABEL(structlabel->label153), rec.address);
			gtk_label_set_text(GTK_LABEL(structlabel->label154), rec.branch);
			gtk_label_set_text(GTK_LABEL(structlabel->label155), rec.blockno);
			gtk_label_set_text(GTK_LABEL(structlabel->label156), rec.mobileno);
			gtk_label_set_text(GTK_LABEL(structlabel->label157), rec.emailid);
			gtk_label_set_text(GTK_LABEL(structlabel->label158), rec.date);
		}
		else if(p == 14) {	
			gtk_label_set_text(GTK_LABEL(structlabel->label161), rec.mis);
			gtk_label_set_text(GTK_LABEL(structlabel->label162), rec.name);
			gtk_label_set_text(GTK_LABEL(structlabel->label163), rec.address);
			gtk_label_set_text(GTK_LABEL(structlabel->label164), rec.branch);
			gtk_label_set_text(GTK_LABEL(structlabel->label165), rec.blockno);
			gtk_label_set_text(GTK_LABEL(structlabel->label166), rec.mobileno);
			gtk_label_set_text(GTK_LABEL(structlabel->label167), rec.emailid);
			gtk_label_set_text(GTK_LABEL(structlabel->label168), rec.date);
			p=0;
			break;
		}
		if(feof(fp)){
			break;	
		}
		p++;
	}
	fclose(fp);
	int b=0;
	FILE *fm = fopen("studata.txt","r+");
	while(1){				/**************************counts number of students***************/
		fscanf(fm, "%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\n]\n", rec.mis,  rec.name, rec.address, rec.branch, rec.blockno, rec.mobileno, rec.emailid, rec.date);
		b++;
		if(feof(fm)){
			break;
		}
	}
	fclose(fm);					
	char str[10];				/****code that converts integer to string and displays it on label*/
	int i, rem, len = 0, n;
	int num = b;
	n = num;
	while (n != 0){
        	len++;
		n /= 10;
	}
	for (i = 0; i < len; i++){

        	rem = num % 10;

        	num = num / 10;

        	str[len - (i + 1)] = rem + '0';
	
	}
	str[len] = '\0';
	gtk_label_set_text(GTK_LABEL(label1),str);
										 /*adding components to frame*/
	gtk_grid_attach(GTK_GRID(win_grid->grid), labelhead, 2, 2, 8 , 2);
	gtk_grid_attach(GTK_GRID(win_grid->grid), label11, 2, 5, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), label12, 3, 5, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), label13, 4, 5, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), label14, 5, 5, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), label15, 6, 5, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), label16, 7, 5, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), label17, 8 , 5, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), label18, 9 , 5, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), labeln21, 2, 6, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), labeln22, 3, 6, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), labeln23, 4, 6, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), labeln24, 5, 6, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), labeln25, 6, 6, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), labeln26, 7,6, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), labeln27, 8, 6, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), labeln31, 2, 1, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), labeln32, 3, 1, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), labeln33, 4, 1, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), labeln34, 5, 1, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), labeln35, 6, 1, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), labeln36, 7,1, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), labeln37, 8,1, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), labeln41, 2, 4, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), labeln42, 3, 4, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), labeln43, 4, 4, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), labeln44, 5, 4, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), labeln45, 6, 4, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), labeln46, 7,4, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), labeln47, 8,4, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label21, 2, 7, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label22, 3, 7, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label23, 4, 7, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label24, 5, 7, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label25, 6, 7, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label26, 7,7, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label27, 8, 7, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label31, 2, 8, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label32, 3, 8, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label33, 4, 8, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label34, 5, 8, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label35, 6, 8, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label36, 7,8, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label37, 8, 8, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label41, 2, 9, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label42, 3, 9, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label43, 4, 9, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label44, 5, 9, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label45, 6, 9, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label46, 7,9, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label47, 8, 9, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label51, 2, 10, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label52, 3, 10, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label53, 4, 10, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label54, 5, 10, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label55, 6, 10, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label56, 7,10, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label57, 8,10, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label61, 2, 11, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label62, 3, 11, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label63, 4, 11, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label64, 5, 11, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label65, 6, 11, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label66, 7,11, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label67, 8,11, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label71, 2, 12, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label72, 3, 12, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label73, 4, 12, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label74, 5, 12, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label75, 6, 12, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label76, 7,12, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label77, 8,12, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label81, 2, 13, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label82, 3, 13, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label83, 4, 13, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label84, 5, 13, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label85, 6, 13, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label86, 7,13, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label87, 8,13, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label91, 2, 14, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label92, 3, 14, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label93, 4, 14, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label94, 5, 14, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label95, 6, 14, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label96, 7,14, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label97, 8,14, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label101, 2, 15, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label102, 3, 15, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label103, 4, 15, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label104, 5, 15, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label105, 6, 15, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label106, 7,15, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label107, 8,15, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label111, 2, 16, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label112, 3, 16, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label113, 4, 16, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label114, 5, 16, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label115, 6, 16, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label116, 7,16, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label117, 8,16, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label121, 2, 17, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label122, 3, 17, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label123, 4, 17, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label124, 5, 17, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label125, 6, 17, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label126, 7,17, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label127, 8,17, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label131, 2, 18, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label132, 3, 18, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label133, 4, 18, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label134, 5, 18, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label135, 6, 18, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label136, 7,18, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label137, 8,18, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label141, 2, 19,1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label142, 3, 19, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label143, 4, 19, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label144, 5, 19, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label145, 6, 19, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label146, 7,19, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label147, 8,19, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label151, 2, 20, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label152, 3, 20, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label153,4, 20, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label154, 5, 20, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label155, 6, 20, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label156, 7,20, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label157, 8,20, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label161, 2, 21, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label162, 3, 21, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label163, 4, 21, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label164, 5, 21, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label165, 6, 21, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label166, 7,21, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label167, 8,21, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label28, 9,7, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label38, 9,8, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label48, 9,9, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label58, 9,10, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label68, 9,11, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label78, 9,12, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label88, 9,13, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label98, 9,14, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label108, 9,15, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label118, 9,16, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label128, 9,17, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label138, 9,18, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label148, 9,19, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label158, 9,20, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label168, 9,21, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), btnnxt, 8,23, 2, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), btnpre, 2,23, 2, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), btnref, 5,23, 2, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), label1, 6,24, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), label7, 5, 24, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), labelnull,6, 22, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), add, 0, 0, 2, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), search, 2, 0, 2, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), edit, 4, 0, 2, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), delete, 6, 0, 2, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), btn6, 8, 0, 2, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), close, 10, 0, 2, 1);
	gtk_widget_show_all(win_grid->window);
	return;
}
/********************************************************************************************frame : search student details*/
void search_student_details(GtkWidget *widget, Window_grid *win_grid){
	GtkWidget *close;
	addstu_grid = gtk_grid_new();
	gtk_container_remove(GTK_CONTAINER(win_grid->window), win_grid->grid);
	gtk_container_add(GTK_CONTAINER(win_grid->window), addstu_grid);
	win_grid->grid = addstu_grid;
	Gc_label *structlabel;
	structlabel = (Gc_label *)malloc(sizeof(Gc_label));
	structlabel->ent1=gtk_entry_new();
	structlabel->window = win_grid->window;
	labelhead = gtk_label_new(NULL);
	gtk_label_set_markup(GTK_LABEL(labelhead), "<b><big>       SEARCH STUDENT BY MIS NAME BRANCH ROOMNO MOBILENO EMAILID DATE</big></b>\n");
	labelnull = gtk_label_new(" ");
	label11 = gtk_label_new("         MIS      ");
	label12 = gtk_label_new("        NAME        ");
	label13 = gtk_label_new("        ADDRESS     ");
	label14= gtk_label_new("         BRANCH      ");
	label15 = gtk_label_new("      ROOMNO     ");
	label16= gtk_label_new("         MOBILE-NO      ");
	label17 = gtk_label_new("                 EMAIL-ID               ");
	label18 = gtk_label_new("	DATE OF JOIN	");
	structlabel->label28 = gtk_label_new("");
	structlabel->label38 = gtk_label_new("");
	structlabel->label48 = gtk_label_new("");
	structlabel->label58 = gtk_label_new("");
	structlabel->label68 = gtk_label_new("");
	structlabel->label78 = gtk_label_new("");
	structlabel->label88 = gtk_label_new("");
	structlabel->label98 = gtk_label_new("");
	structlabel->label108 = gtk_label_new("");
	structlabel->label118 = gtk_label_new("");
	structlabel->label128 = gtk_label_new("");
	structlabel->label138 = gtk_label_new("");
	structlabel->label148 = gtk_label_new("");
	structlabel->label158 = gtk_label_new("");
	structlabel->label168 = gtk_label_new("");
	labeln21 = gtk_label_new("");
	labeln22 = gtk_label_new("");
	labeln23 = gtk_label_new("");
	labeln24= gtk_label_new("");
	labeln25 = gtk_label_new("");
	labeln26= gtk_label_new("");
	labeln27 = gtk_label_new("");
	add = gtk_button_new_with_label("Add Student Details");
	search = gtk_button_new_with_label("Search student Details");
	edit = gtk_button_new_with_label("Edit student Details");
	delete = gtk_button_new_with_label("Delete student Details");
	btn6 = gtk_button_new_with_label("View student Details");
	close = gtk_button_new_with_label("Close Application");
	structlabel->label21 = gtk_label_new("");
	structlabel->label22 = gtk_label_new("");
	structlabel->label23 = gtk_label_new("");
	structlabel->label24= gtk_label_new("");
	structlabel->label25 = gtk_label_new("");
	structlabel->label26= gtk_label_new("");
	structlabel->label27 = gtk_label_new("");
	structlabel->label31 = gtk_label_new("");
	structlabel->label32 = gtk_label_new("");
	structlabel->label33 = gtk_label_new("");
	structlabel->label34= gtk_label_new("");
	structlabel->label35 = gtk_label_new("");
	structlabel->label36= gtk_label_new("");
	structlabel->label37 = gtk_label_new("");
	labeln31 = gtk_label_new("");
	labeln32 = gtk_label_new("");
	labeln33 = gtk_label_new("");
	labeln34= gtk_label_new("");
	labeln35 = gtk_label_new("");
	labeln36= gtk_label_new("");
	labeln37 = gtk_label_new("");
	labeln41 = gtk_label_new("");
	labeln42 = gtk_label_new("");
	labeln43 = gtk_label_new("");
	labeln44= gtk_label_new("");
	labeln45 = gtk_label_new("");
	labeln46= gtk_label_new("");
	labeln47 = gtk_label_new("");
	structlabel->label41 = gtk_label_new("");
	structlabel->label42 = gtk_label_new("");
	structlabel->label43 = gtk_label_new("");
	structlabel->label44= gtk_label_new("");
	structlabel->label45 = gtk_label_new("");
	structlabel->label46= gtk_label_new("");
	structlabel->label47 = gtk_label_new("");
	structlabel->label51 = gtk_label_new("");
	structlabel->label52 = gtk_label_new("");
	structlabel->label53 = gtk_label_new("");
	structlabel->label54= gtk_label_new("");
	structlabel->label55 = gtk_label_new("");
	structlabel->label56= gtk_label_new("");
	structlabel->label57 = gtk_label_new("");
	structlabel->label61 = gtk_label_new("");
	structlabel->label62 = gtk_label_new("");
	structlabel->label63 = gtk_label_new("");
	structlabel->label64= gtk_label_new("");
	structlabel->label65 = gtk_label_new("");
	structlabel->label66= gtk_label_new("");
	structlabel->label67 = gtk_label_new("");
	structlabel->label71 = gtk_label_new("");
	structlabel->label72 = gtk_label_new("");
	structlabel->label73 = gtk_label_new("");
	structlabel->label74= gtk_label_new("");
	structlabel->label75 = gtk_label_new("");
	structlabel->label76= gtk_label_new("");
	structlabel->label77 = gtk_label_new("");
	structlabel->label81 = gtk_label_new("");
	structlabel->label82 = gtk_label_new("");
	structlabel->label83 = gtk_label_new("");
	structlabel->label84= gtk_label_new("");
	structlabel->label85 = gtk_label_new("");
	structlabel->label86= gtk_label_new("");
	structlabel->label87 = gtk_label_new("");
	structlabel->label91 = gtk_label_new("");
	structlabel->label92 = gtk_label_new("");
	structlabel->label93 = gtk_label_new("");
	structlabel->label94= gtk_label_new("");
	structlabel->label95 = gtk_label_new("");
	structlabel->label96= gtk_label_new("");
	structlabel->label97 = gtk_label_new("");
	structlabel->label101 = gtk_label_new("");
	structlabel->label102 = gtk_label_new("");
	structlabel->label103 = gtk_label_new("");
	structlabel->label104= gtk_label_new("");
	structlabel->label105 = gtk_label_new("");
	structlabel->label106= gtk_label_new("");
	structlabel->label107 = gtk_label_new("");
	structlabel->label111 = gtk_label_new("");
	structlabel->label112 = gtk_label_new("");
	structlabel->label113 = gtk_label_new("");
	structlabel->label114= gtk_label_new("");
	structlabel->label115 = gtk_label_new("");
	structlabel->label116= gtk_label_new("");
	structlabel->label117 = gtk_label_new("");
	structlabel->label121 = gtk_label_new("");
	structlabel->label122 = gtk_label_new("");
	structlabel->label123 = gtk_label_new("");
	structlabel->label124= gtk_label_new("");
	structlabel->label125 = gtk_label_new("");
	structlabel->label126= gtk_label_new("");
	structlabel->label127 = gtk_label_new("");
	structlabel->label131 = gtk_label_new("");
	structlabel->label132 = gtk_label_new("");
	structlabel->label133 = gtk_label_new("");
	structlabel->label134= gtk_label_new("");
	structlabel->label135 = gtk_label_new("");
	structlabel->label136= gtk_label_new("");
	structlabel->label137 = gtk_label_new("");
	structlabel->label141 = gtk_label_new("");
	structlabel->label142 = gtk_label_new("");
	structlabel->label143 = gtk_label_new("");
	structlabel->label144= gtk_label_new("");
	structlabel->label145 = gtk_label_new("");
	structlabel->label146= gtk_label_new("");
	structlabel->label147 = gtk_label_new("");
	structlabel->label151 = gtk_label_new("");
	structlabel->label152 = gtk_label_new("");
	structlabel->label153 = gtk_label_new("");
	structlabel->label154= gtk_label_new("");
	structlabel->label155 = gtk_label_new("");
	structlabel->label156= gtk_label_new("");
	structlabel->label157 = gtk_label_new("");
	structlabel->label161 = gtk_label_new("");
	structlabel->label162 = gtk_label_new("");
	structlabel->label163 = gtk_label_new("");
	structlabel->label164= gtk_label_new("");
	structlabel->label165 = gtk_label_new("");
	structlabel->label166= gtk_label_new("");
	structlabel->label167 = gtk_label_new("");
	btn1 = gtk_button_new_with_label("SEARCH");
	btn2 = gtk_button_new_with_label("HOME");
	btn3 = gtk_button_new_with_label("PASTE");
	btn4 = gtk_button_new_with_label("CLEAR");
	btn5 = gtk_button_new_with_label("DELETE by MIS");
	btnnxt = gtk_button_new_with_label("NEXT");
	btnpre = gtk_button_new_with_label("PREVIOUS");
	btnref = gtk_button_new_with_label("LIST OF STUDENT LEFT");
	g_signal_connect(btn1, "clicked", G_CALLBACK(search_student_by_all), structlabel);
	g_signal_connect(structlabel->ent1, "activate", G_CALLBACK(search_student_by_all), structlabel);
	g_signal_connect(btn5, "clicked", G_CALLBACK(searchinfile1), structlabel);
	g_signal_connect(btn4, "clicked", G_CALLBACK(cleartext), structlabel);
	g_signal_connect(btn2, "clicked", G_CALLBACK(activate), win_grid);
	g_signal_connect(btn3, "clicked", G_CALLBACK(searchinfiledynamic), structlabel);
	g_signal_connect(btnnxt, "clicked", G_CALLBACK(nextnext), structlabel);
	g_signal_connect(btnpre, "clicked", G_CALLBACK(previous), structlabel);
	g_signal_connect(btnref, "clicked", G_CALLBACK(view_student_left), win_grid);
	g_signal_connect(add, "clicked", G_CALLBACK(addstudent_details), win_grid);
	g_signal_connect(search, "clicked", G_CALLBACK(search_student_details), win_grid);
	g_signal_connect(edit, "clicked", G_CALLBACK(editstudent_details), win_grid);
	g_signal_connect(delete, "clicked", G_CALLBACK(deletestudent_details), win_grid);
	g_signal_connect(btn6, "clicked", G_CALLBACK(view_student), win_grid);
	g_signal_connect(close, "clicked", G_CALLBACK(close_window), win_grid->window);	
										 /*adding components to frame*/
	gtk_grid_attach(GTK_GRID(win_grid->grid), labelhead, 2, 2, 8 , 2);
	gtk_grid_attach(GTK_GRID(win_grid->grid), label11, 2, 7, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), label12, 3, 7, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), label13, 4, 7, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), label14, 5, 7, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), label15, 6, 7, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), label16, 7, 7, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), label17, 8 , 7, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), label18, 9 , 7, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), labeln21, 2, 6, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), labeln22, 3, 6, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), labeln23, 4, 6, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), labeln24, 5, 6, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), labeln25, 6, 6, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), labeln26, 7,6, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), labeln27, 8, 6, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), labeln31, 2, 8, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), labeln32, 3, 8, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), labeln33, 4, 8, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), labeln34, 5, 8, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), labeln35, 6, 8, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), labeln36, 7,8, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), labeln37, 8,8, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), labeln41, 2, 1, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), labeln42, 3, 1, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), labeln43, 4, 1, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), labeln44, 5, 1, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), labeln45, 6, 1, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), labeln46, 7,1, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), labeln47, 8,1, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label21, 2, 9, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label22, 3, 9, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label23, 4, 9, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label24, 5, 9, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label25, 6, 9, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label26, 7,9, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label27, 8, 9, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label31, 2, 10, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label32, 3, 10, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label33, 4, 10, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label34, 5, 10, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label35, 6, 10, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label36, 7,10, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label37, 8, 10, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label41, 2, 11, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label42, 3, 11, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label43, 4, 11, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label44, 5, 11, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label45, 6, 11, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label46, 7,11, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label47, 8, 11, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label51, 2, 12, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label52, 3, 12, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label53, 4, 12, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label54, 5, 12, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label55, 6, 12, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label56, 7,12, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label57, 8,12, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label61, 2, 13, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label62, 3, 13, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label63, 4, 13, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label64, 5, 13, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label65, 6, 13, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label66, 7,13, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label67, 8,13, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label71, 2, 14, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label72, 3, 14, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label73, 4, 14, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label74, 5, 14, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label75, 6, 14, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label76, 7,14, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label77, 8,14, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label81, 2, 15, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label82, 3, 15, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label83, 4, 15, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label84, 5, 15, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label85, 6, 15, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label86, 7,15, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label87, 8,15, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label91, 2, 16, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label92, 3, 16, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label93, 4, 16, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label94, 5, 16, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label95, 6, 16, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label96, 7,16, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label97, 8,16, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label101, 2, 17, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label102, 3, 17, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label103, 4, 17, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label104, 5, 17, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label105, 6, 17, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label106, 7,17, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label107, 8,17, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label111, 2, 18, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label112, 3, 18, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label113, 4, 18, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label114, 5, 18, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label115, 6, 18, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label116, 7,18, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label117, 8,18, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label121, 2, 19, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label122, 3, 19, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label123, 4, 19, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label124, 5, 19, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label125, 6, 19, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label126, 7,19, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label127, 8,19, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label131, 2, 20, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label132, 3, 20, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label133, 4, 20, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label134, 5, 20, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label135, 6, 20, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label136, 7,20, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label137, 8,20, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label141, 2, 21,1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label142, 3, 21, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label143, 4, 21, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label144, 5, 21, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label145, 6, 21, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label146, 7,21, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label147, 8,21, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label151, 2, 22, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label152, 3, 22, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label153,4, 22, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label154, 5, 22, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label155, 6, 22, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label156, 7,22, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label157, 8,22, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label161, 2, 23, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label162, 3, 23, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label163, 4, 23, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label164, 5, 23, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label165, 6, 23, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label166, 7,23, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label167, 8,23, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label28, 9,9, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label38, 9,10, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label48, 9,11, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label58, 9,12, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label68, 9,13, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label78, 9,14, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label88, 9,15, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label98, 9,16, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label108, 9,17, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label118, 9,18, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label128, 9,19, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label138, 9,20, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label148, 9,21, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label158, 9,22, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label168, 9,23, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), btnnxt, 10,25, 2, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), btnpre, 1,25, 2, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), labelnull,6, 24, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), btn1, 7, 5, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->ent1, 5,5, 2, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), add, 0, 0, 2, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), search, 2, 0, 2, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), edit, 4, 0, 2, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), delete, 6, 0, 2, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), btn6, 8, 0, 2, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), close, 10, 0, 2, 1);
	gtk_widget_show_all(win_grid->window);
	return;
}
/*******************************************************************************frame : delete students*/
void deletestudent_details(GtkWidget *widget, Window_grid *win_grid){
	GtkWidget *close;
	addstu_grid = gtk_grid_new();
	gtk_container_remove(GTK_CONTAINER(win_grid->window), win_grid->grid);
	gtk_container_add(GTK_CONTAINER(win_grid->window), addstu_grid);
	win_grid->grid = addstu_grid;
	Gc_label *structlabel;
	structlabel = (Gc_label *)malloc(sizeof(Gc_label));
	structlabel->ent1=gtk_label_new("");
	structlabel->ent2=gtk_label_new("");
	structlabel->ent3=gtk_label_new("");
	structlabel->ent4=gtk_label_new("");
	structlabel->ent5=gtk_label_new("");
	structlabel->ent6=gtk_label_new("");
	structlabel->ent7=gtk_label_new("");
	structlabel->entry=gtk_entry_new();
	structlabel->newdate=gtk_entry_new();
	structlabel->window = win_grid->window;
	labelhead = gtk_label_new(NULL);
	gtk_label_set_markup(GTK_LABEL(labelhead), "<b><big>       DELETE STUDENT</big></b>\n");
	labelnull = gtk_label_new(" ");
	label1 = gtk_label_new("MIS");
	label2 = gtk_label_new("NAME");
	label3 = gtk_label_new("ADDRESS");
	label4= gtk_label_new("BRANCH");
	label5 = gtk_label_new("ROOMNO");
	label6= gtk_label_new("MOBILE-NO");
	label7 = gtk_label_new("EMAIL-ID");
	label11 = gtk_label_new("         MIS      ");
	label12 = gtk_label_new("        NAME        ");
	label13 = gtk_label_new("        ADDRESS     ");
	label14= gtk_label_new("         BRANCH      ");
	label15 = gtk_label_new("      ROOMNO     ");
	label16= gtk_label_new("         MOBILE-NO      ");
	label17 = gtk_label_new("                 EMAIL-ID               ");
	label18= gtk_label_new("                 DATE OF JOIN               ");
	labelnewdate =gtk_label_new("                DATE OF LEAVE               ");
	labeln21 = gtk_label_new("");
	labeln22 = gtk_label_new("");
	labeln23 = gtk_label_new("");
	labeln24= gtk_label_new("");
	labeln25 = gtk_label_new("");
	labeln26= gtk_label_new("");
	labeln27 = gtk_label_new("");
	add = gtk_button_new_with_label("Add Student Details");
	search = gtk_button_new_with_label("Search student Details");
	edit = gtk_button_new_with_label("Edit student Details");
	delete = gtk_button_new_with_label("Delete student Details");
	btn6 = gtk_button_new_with_label("View student Details");
	close = gtk_button_new_with_label("Close Application");
	structlabel->label21 = gtk_label_new("");
	structlabel->label22 = gtk_label_new("");
	structlabel->label23 = gtk_label_new("");
	structlabel->label24= gtk_label_new("");
	structlabel->label25 = gtk_label_new("");
	structlabel->label26= gtk_label_new("");
	structlabel->label27 = gtk_label_new("");
	structlabel->label31 = gtk_label_new("");
	structlabel->label32 = gtk_label_new("");
	structlabel->label33 = gtk_label_new("");
	structlabel->label34= gtk_label_new("");
	structlabel->label35 = gtk_label_new("");
	structlabel->label36= gtk_label_new("");
	structlabel->label37 = gtk_label_new("");
	labeln31 = gtk_label_new("");
	labeln32 = gtk_label_new("");
	labeln33 = gtk_label_new("");
	labeln34= gtk_label_new("");
	labeln35 = gtk_label_new("");
	labeln36= gtk_label_new("");
	labeln37 = gtk_label_new("");
	labeln41 = gtk_label_new("");
	labeln42 = gtk_label_new("");
	labeln43 = gtk_label_new("");
	labeln44= gtk_label_new("");
	labeln45 = gtk_label_new("");
	labeln46= gtk_label_new("");
	labeln47 = gtk_label_new("");
	structlabel->label41 = gtk_label_new("");
	structlabel->label42 = gtk_label_new("");
	structlabel->label43 = gtk_label_new("");
	structlabel->label44= gtk_label_new("");
	structlabel->label45 = gtk_label_new("");
	structlabel->label46= gtk_label_new("");
	structlabel->label47 = gtk_label_new("");
	structlabel->label51 = gtk_label_new("");
	structlabel->label52 = gtk_label_new("");
	structlabel->label53 = gtk_label_new("");
	structlabel->label54= gtk_label_new("");
	structlabel->label55 = gtk_label_new("");
	structlabel->label56= gtk_label_new("");
	structlabel->label57 = gtk_label_new("");
	structlabel->label61 = gtk_label_new("");
	structlabel->label62 = gtk_label_new("");
	structlabel->label63 = gtk_label_new("");
	structlabel->label64= gtk_label_new("");
	structlabel->label65 = gtk_label_new("");
	structlabel->label66= gtk_label_new("");
	structlabel->label67 = gtk_label_new("");
	structlabel->label71 = gtk_label_new("");
	structlabel->label72 = gtk_label_new("");
	structlabel->label73 = gtk_label_new("");
	structlabel->label74= gtk_label_new("");
	structlabel->label75 = gtk_label_new("");
	structlabel->label76= gtk_label_new("");
	structlabel->label77 = gtk_label_new("");
	structlabel->label81 = gtk_label_new("");
	structlabel->label82 = gtk_label_new("");
	structlabel->label83 = gtk_label_new("");
	structlabel->label84= gtk_label_new("");
	structlabel->label85 = gtk_label_new("");
	structlabel->label86= gtk_label_new("");
	structlabel->label87 = gtk_label_new("");
	structlabel->label91 = gtk_label_new("");
	structlabel->label92 = gtk_label_new("");
	structlabel->label93 = gtk_label_new("");
	structlabel->label94= gtk_label_new("");
	structlabel->label95 = gtk_label_new("");
	structlabel->label96= gtk_label_new("");
	structlabel->label97 = gtk_label_new("");
	structlabel->label101 = gtk_label_new("");
	structlabel->label102 = gtk_label_new("");
	structlabel->label103 = gtk_label_new("");
	structlabel->label104= gtk_label_new("");
	structlabel->label105 = gtk_label_new("");
	structlabel->label106= gtk_label_new("");
	structlabel->label107 = gtk_label_new("");
	structlabel->label111 = gtk_label_new("");
	structlabel->label112 = gtk_label_new("");
	structlabel->label113 = gtk_label_new("");
	structlabel->label114= gtk_label_new("");
	structlabel->label115 = gtk_label_new("");
	structlabel->label116= gtk_label_new("");
	structlabel->label117 = gtk_label_new("");
	structlabel->label121 = gtk_label_new("");
	structlabel->label122 = gtk_label_new("");
	structlabel->label123 = gtk_label_new("");
	structlabel->label124= gtk_label_new("");
	structlabel->label125 = gtk_label_new("");
	structlabel->label126= gtk_label_new("");
	structlabel->label127 = gtk_label_new("");
	structlabel->label131 = gtk_label_new("");
	structlabel->label132 = gtk_label_new("");
	structlabel->label133 = gtk_label_new("");
	structlabel->label134= gtk_label_new("");
	structlabel->label135 = gtk_label_new("");
	structlabel->label136= gtk_label_new("");
	structlabel->label137 = gtk_label_new("");
	structlabel->label141 = gtk_label_new("");
	structlabel->label142 = gtk_label_new("");
	structlabel->label143 = gtk_label_new("");
	structlabel->label144= gtk_label_new("");
	structlabel->label145 = gtk_label_new("");
	structlabel->label146= gtk_label_new("");
	structlabel->label147 = gtk_label_new("");
	structlabel->label151 = gtk_label_new("");
	structlabel->label152 = gtk_label_new("");
	structlabel->label153 = gtk_label_new("");
	structlabel->label154= gtk_label_new("");
	structlabel->label155 = gtk_label_new("");
	structlabel->label156= gtk_label_new("");
	structlabel->label157 = gtk_label_new("");
	structlabel->label161 = gtk_label_new("");
	structlabel->label162 = gtk_label_new("");
	structlabel->label163 = gtk_label_new("");
	structlabel->label164= gtk_label_new("");
	structlabel->label165 = gtk_label_new("");
	structlabel->label166= gtk_label_new("");
	structlabel->label167 = gtk_label_new("");
	btn1 = gtk_button_new_with_label("DELETE");
	btn2 = gtk_button_new_with_label("HOME");
	btn3 = gtk_button_new_with_label("PASTE");
	btn4 = gtk_button_new_with_label("CLEAR");
	btn5 = gtk_button_new_with_label("DELETE by MIS");
	btnnxt = gtk_button_new_with_label("NEXT");
	btnpre = gtk_button_new_with_label("PREVIOUS");
	btnref = gtk_button_new_with_label("REFRESH");
	btn11 = gtk_button_new_with_label("DELETE");
	btn12 = gtk_button_new_with_label("DELETE");
	btn13 = gtk_button_new_with_label("DELETE");
	btn14 = gtk_button_new_with_label("DELETE");
	btn15 = gtk_button_new_with_label("DELETE");
	btn16 = gtk_button_new_with_label("DELETE");
	btn17 = gtk_button_new_with_label("DELETE");
	btn18 = gtk_button_new_with_label("DELETE");
	btn19 = gtk_button_new_with_label("DELETE");
	btn10 = gtk_button_new_with_label("DELETE");
	btn111 = gtk_button_new_with_label("DELETE");
	btn112 = gtk_button_new_with_label("DELETE");
	btn113 = gtk_button_new_with_label("DELETE");
	btn114 = gtk_button_new_with_label("DELETE");
	btn115 = gtk_button_new_with_label("DELETE");
	g_signal_connect(structlabel->newdate, "activate", G_CALLBACK(delete_student), structlabel);
	g_signal_connect(btn1, "clicked", G_CALLBACK(delete_student), structlabel);
	g_signal_connect(btn11, "clicked", G_CALLBACK(dynamic_delete2), structlabel);
	g_signal_connect(btn12, "clicked", G_CALLBACK(dynamic_delete3), structlabel);
	g_signal_connect(btn13, "clicked", G_CALLBACK(dynamic_delete4), structlabel);
	g_signal_connect(btn14, "clicked", G_CALLBACK(dynamic_delete5), structlabel);
	g_signal_connect(btn15, "clicked", G_CALLBACK(dynamic_delete6), structlabel);
	g_signal_connect(btn16, "clicked", G_CALLBACK(dynamic_delete7), structlabel);
	g_signal_connect(btn17, "clicked", G_CALLBACK(dynamic_delete8), structlabel);
	g_signal_connect(btn18, "clicked", G_CALLBACK(dynamic_delete9), structlabel);
	g_signal_connect(btn19, "clicked", G_CALLBACK(dynamic_delete10), structlabel);
	g_signal_connect(btn10, "clicked", G_CALLBACK(dynamic_delete11), structlabel);
	g_signal_connect(btn111, "clicked", G_CALLBACK(dynamic_delete12), structlabel);
	g_signal_connect(btn112, "clicked", G_CALLBACK(dynamic_delete13), structlabel);
	g_signal_connect(btn113, "clicked", G_CALLBACK(dynamic_delete14), structlabel);
	g_signal_connect(btn114, "clicked", G_CALLBACK(dynamic_delete15), structlabel);
	g_signal_connect(btn115, "clicked", G_CALLBACK(dynamic_delete16), structlabel);
	g_signal_connect(btn5, "clicked", G_CALLBACK(searchinfile1), structlabel);
	g_signal_connect(structlabel->entry, "activate", G_CALLBACK(searchinfile1), structlabel);
	g_signal_connect(btn4, "clicked", G_CALLBACK(cleartext12), structlabel);
	g_signal_connect(btn2, "clicked", G_CALLBACK(activate), win_grid);
	g_signal_connect(btn3, "clicked", G_CALLBACK(searchinfiledynamic), structlabel);
	g_signal_connect(btnnxt, "clicked", G_CALLBACK(next), structlabel);
	g_signal_connect(btnpre, "clicked", G_CALLBACK(prev), structlabel);
	g_signal_connect(btnref, "clicked", G_CALLBACK(refresh), structlabel);
	g_signal_connect(add, "clicked", G_CALLBACK(addstudent_details), win_grid);
	g_signal_connect(search, "clicked", G_CALLBACK(search_student_details), win_grid);
	g_signal_connect(edit, "clicked", G_CALLBACK(editstudent_details), win_grid);
	g_signal_connect(delete, "clicked", G_CALLBACK(deletestudent_details), win_grid);
	g_signal_connect(btn6, "clicked", G_CALLBACK(view_student), win_grid);
	g_signal_connect(close, "clicked", G_CALLBACK(close_window), win_grid->window);
	p = 0;
	FILE *fp = fopen("studata.txt","r+");
	while(1){
		fscanf(fp, "%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\n]\n", rec.mis,  rec.name, rec.address, rec.branch, rec.blockno, rec.mobileno, rec.emailid,rec.date);
		if(p == 0) {	
			gtk_label_set_text(GTK_LABEL(structlabel->label21), rec.mis);
			gtk_label_set_text(GTK_LABEL(structlabel->label22), rec.name);
			gtk_label_set_text(GTK_LABEL(structlabel->label23), rec.address);
			gtk_label_set_text(GTK_LABEL(structlabel->label24), rec.branch);
			gtk_label_set_text(GTK_LABEL(structlabel->label25), rec.blockno);
			gtk_label_set_text(GTK_LABEL(structlabel->label26), rec.mobileno);
			gtk_label_set_text(GTK_LABEL(structlabel->label27), rec.emailid);
		}
		else if(p == 1) {	
			gtk_label_set_text(GTK_LABEL(structlabel->label31), rec.mis);
			gtk_label_set_text(GTK_LABEL(structlabel->label32), rec.name);
			gtk_label_set_text(GTK_LABEL(structlabel->label33), rec.address);
			gtk_label_set_text(GTK_LABEL(structlabel->label34), rec.branch);
			gtk_label_set_text(GTK_LABEL(structlabel->label35), rec.blockno);
			gtk_label_set_text(GTK_LABEL(structlabel->label36), rec.mobileno);
			gtk_label_set_text(GTK_LABEL(structlabel->label37), rec.emailid);
		}
		else if(p == 2) {	
			gtk_label_set_text(GTK_LABEL(structlabel->label41), rec.mis);
			gtk_label_set_text(GTK_LABEL(structlabel->label42), rec.name);
			gtk_label_set_text(GTK_LABEL(structlabel->label43), rec.address);
			gtk_label_set_text(GTK_LABEL(structlabel->label44), rec.branch);
			gtk_label_set_text(GTK_LABEL(structlabel->label45), rec.blockno);
			gtk_label_set_text(GTK_LABEL(structlabel->label46), rec.mobileno);
			gtk_label_set_text(GTK_LABEL(structlabel->label47), rec.emailid);
		}
		else if(p == 3) {	
			gtk_label_set_text(GTK_LABEL(structlabel->label51), rec.mis);
			gtk_label_set_text(GTK_LABEL(structlabel->label52), rec.name);
			gtk_label_set_text(GTK_LABEL(structlabel->label53), rec.address);
			gtk_label_set_text(GTK_LABEL(structlabel->label54), rec.branch);
			gtk_label_set_text(GTK_LABEL(structlabel->label55), rec.blockno);
			gtk_label_set_text(GTK_LABEL(structlabel->label56), rec.mobileno);
			gtk_label_set_text(GTK_LABEL(structlabel->label57), rec.emailid);
		}
		else if(p == 4) {	
			gtk_label_set_text(GTK_LABEL(structlabel->label61), rec.mis);
			gtk_label_set_text(GTK_LABEL(structlabel->label62), rec.name);
			gtk_label_set_text(GTK_LABEL(structlabel->label63), rec.address);
			gtk_label_set_text(GTK_LABEL(structlabel->label64), rec.branch);
			gtk_label_set_text(GTK_LABEL(structlabel->label65), rec.blockno);
			gtk_label_set_text(GTK_LABEL(structlabel->label66), rec.mobileno);
			gtk_label_set_text(GTK_LABEL(structlabel->label67), rec.emailid);
		}
		else if(p == 5) {	
			gtk_label_set_text(GTK_LABEL(structlabel->label71), rec.mis);
			gtk_label_set_text(GTK_LABEL(structlabel->label72), rec.name);
			gtk_label_set_text(GTK_LABEL(structlabel->label73), rec.address);
			gtk_label_set_text(GTK_LABEL(structlabel->label74), rec.branch);
			gtk_label_set_text(GTK_LABEL(structlabel->label75), rec.blockno);
			gtk_label_set_text(GTK_LABEL(structlabel->label76), rec.mobileno);
			gtk_label_set_text(GTK_LABEL(structlabel->label77), rec.emailid);
		}
		else if(p == 6) {	
			gtk_label_set_text(GTK_LABEL(structlabel->label81), rec.mis);
			gtk_label_set_text(GTK_LABEL(structlabel->label82), rec.name);
			gtk_label_set_text(GTK_LABEL(structlabel->label83), rec.address);
			gtk_label_set_text(GTK_LABEL(structlabel->label84), rec.branch);
			gtk_label_set_text(GTK_LABEL(structlabel->label85), rec.blockno);
			gtk_label_set_text(GTK_LABEL(structlabel->label86), rec.mobileno);
			gtk_label_set_text(GTK_LABEL(structlabel->label87), rec.emailid);
		}
		else if(p == 7) {	
			gtk_label_set_text(GTK_LABEL(structlabel->label91), rec.mis);
			gtk_label_set_text(GTK_LABEL(structlabel->label92), rec.name);
			gtk_label_set_text(GTK_LABEL(structlabel->label93), rec.address);
			gtk_label_set_text(GTK_LABEL(structlabel->label94), rec.branch);
			gtk_label_set_text(GTK_LABEL(structlabel->label95), rec.blockno);
			gtk_label_set_text(GTK_LABEL(structlabel->label96), rec.mobileno);
			gtk_label_set_text(GTK_LABEL(structlabel->label97), rec.emailid);
		}
		else if(p == 8) {	
			gtk_label_set_text(GTK_LABEL(structlabel->label101), rec.mis);
			gtk_label_set_text(GTK_LABEL(structlabel->label102), rec.name);
			gtk_label_set_text(GTK_LABEL(structlabel->label103), rec.address);
			gtk_label_set_text(GTK_LABEL(structlabel->label104), rec.branch);
			gtk_label_set_text(GTK_LABEL(structlabel->label105), rec.blockno);
			gtk_label_set_text(GTK_LABEL(structlabel->label106), rec.mobileno);
			gtk_label_set_text(GTK_LABEL(structlabel->label107), rec.emailid);
		}
		else if(p == 9) {	
			gtk_label_set_text(GTK_LABEL(structlabel->label111), rec.mis);
			gtk_label_set_text(GTK_LABEL(structlabel->label112), rec.name);
			gtk_label_set_text(GTK_LABEL(structlabel->label113), rec.address);
			gtk_label_set_text(GTK_LABEL(structlabel->label114), rec.branch);
			gtk_label_set_text(GTK_LABEL(structlabel->label115), rec.blockno);
			gtk_label_set_text(GTK_LABEL(structlabel->label116), rec.mobileno);
			gtk_label_set_text(GTK_LABEL(structlabel->label117), rec.emailid);
		}
		else if(p == 10) {	
			gtk_label_set_text(GTK_LABEL(structlabel->label121), rec.mis);
			gtk_label_set_text(GTK_LABEL(structlabel->label122), rec.name);
			gtk_label_set_text(GTK_LABEL(structlabel->label123), rec.address);
			gtk_label_set_text(GTK_LABEL(structlabel->label124), rec.branch);
			gtk_label_set_text(GTK_LABEL(structlabel->label125), rec.blockno);
			gtk_label_set_text(GTK_LABEL(structlabel->label126), rec.mobileno);
			gtk_label_set_text(GTK_LABEL(structlabel->label127), rec.emailid);
		}
		else if(p == 11) {	
			gtk_label_set_text(GTK_LABEL(structlabel->label131), rec.mis);
			gtk_label_set_text(GTK_LABEL(structlabel->label132), rec.name);
			gtk_label_set_text(GTK_LABEL(structlabel->label133), rec.address);
			gtk_label_set_text(GTK_LABEL(structlabel->label134), rec.branch);
			gtk_label_set_text(GTK_LABEL(structlabel->label135), rec.blockno);
			gtk_label_set_text(GTK_LABEL(structlabel->label136), rec.mobileno);
			gtk_label_set_text(GTK_LABEL(structlabel->label137), rec.emailid);
		}
		else if(p == 12) {	
			gtk_label_set_text(GTK_LABEL(structlabel->label141), rec.mis);
			gtk_label_set_text(GTK_LABEL(structlabel->label142), rec.name);
			gtk_label_set_text(GTK_LABEL(structlabel->label143), rec.address);
			gtk_label_set_text(GTK_LABEL(structlabel->label144), rec.branch);
			gtk_label_set_text(GTK_LABEL(structlabel->label145), rec.blockno);
			gtk_label_set_text(GTK_LABEL(structlabel->label146), rec.mobileno);
			gtk_label_set_text(GTK_LABEL(structlabel->label147), rec.emailid);
		}
		else if(p == 13) {	
			gtk_label_set_text(GTK_LABEL(structlabel->label151), rec.mis);
			gtk_label_set_text(GTK_LABEL(structlabel->label152), rec.name);
			gtk_label_set_text(GTK_LABEL(structlabel->label153), rec.address);
			gtk_label_set_text(GTK_LABEL(structlabel->label154), rec.branch);
			gtk_label_set_text(GTK_LABEL(structlabel->label155), rec.blockno);
			gtk_label_set_text(GTK_LABEL(structlabel->label156), rec.mobileno);
			gtk_label_set_text(GTK_LABEL(structlabel->label157), rec.emailid);
		}
		else if(p == 14) {	
			gtk_label_set_text(GTK_LABEL(structlabel->label161), rec.mis);
			gtk_label_set_text(GTK_LABEL(structlabel->label162), rec.name);
			gtk_label_set_text(GTK_LABEL(structlabel->label163), rec.address);
			gtk_label_set_text(GTK_LABEL(structlabel->label164), rec.branch);
			gtk_label_set_text(GTK_LABEL(structlabel->label165), rec.blockno);
			gtk_label_set_text(GTK_LABEL(structlabel->label166), rec.mobileno);
			gtk_label_set_text(GTK_LABEL(structlabel->label167), rec.emailid);
			p=0;
			break;
		}
		if(feof(fp)){
			break;	
		}
		p++;
	}
	fclose(fp);		
										 /*adding components to frame*/
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->entry, 2,4, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->ent1, 2,5, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->ent2, 2,6, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->ent3, 2,7, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->ent4, 2,8, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->ent5, 2,9, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->ent6, 2,10, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->ent7, 2,11, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->newdate, 2,12, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), labelhead, 1, 2, 2 , 2);
	gtk_grid_attach(GTK_GRID(win_grid->grid), label1, 1, 5, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), label2, 1, 6, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), label3, 1, 7, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), label4, 1, 8, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), label5, 1, 9, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), label6, 1, 10, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), label7, 1, 11, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), label11, 4, 2, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), label12, 5, 2, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), label13, 6, 2, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), label14, 7, 2, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), label15, 8, 2, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), label16, 9, 2, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), label17, 10 , 2, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), labelnewdate, 1 , 12, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), labeln21, 5, 3, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), labeln22, 6, 3, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), labeln23, 7, 3, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), labeln24, 8, 3, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), labeln25, 9, 3, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), labeln26, 10,3, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), labeln27, 11, 3, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label21, 4, 4, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label22, 5, 4, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label23, 6, 4, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label24, 7, 4, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label25, 8, 4, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label26, 9,4, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label27, 10, 4, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label31, 4, 5, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label32, 5, 5, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label33, 6, 5, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label34, 7, 5, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label35, 8, 5, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label36, 9,5, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label37, 10, 5, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), labeln31, 0, 1, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), labeln32, 2, 1, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), labeln33, 3, 1, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), labeln34, 4, 1, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), labeln35, 5, 1, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), labeln36, 8,1, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), labeln37, 9,1, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), labeln41, 0, 19, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), labeln42, 2, 19, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), labeln43, 3, 19, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), labeln44, 4, 19, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), labeln45, 5, 19, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), labeln46, 8,19, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), labeln47, 9,19, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label41, 4, 6, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label42, 5, 6, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label43, 6, 6, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label44, 7, 6, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label45, 8, 6, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label46, 9,6, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label47, 10, 6, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label51, 4, 7, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label52, 5, 7, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label53, 6, 7, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label54, 7, 7, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label55, 8, 7, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label56, 9,7, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label57, 10,7, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label61, 4, 8, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label62, 5, 8, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label63, 6, 8, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label64, 7, 8, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label65, 8, 8, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label66, 9,8, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label67, 10,8, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label71, 4, 9, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label72, 5, 9, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label73, 6, 9, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label74, 7, 9, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label75, 8, 9, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label76, 9,9, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label77, 10,9, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label81, 4, 10, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label82, 5, 10, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label83, 6, 10, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label84, 7, 10, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label85, 8, 10, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label86, 9,10, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label87, 10,10, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label91, 4, 11, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label92, 5, 11, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label93, 6, 11, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label94, 7, 11, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label95, 8, 11, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label96, 9,11, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label97, 10,11, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label101, 4, 12, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label102, 5, 12, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label103, 6, 12, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label104, 7, 12, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label105, 8, 12, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label106, 9,12, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label107, 10,12, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label111, 4, 13, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label112, 5, 13, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label113, 6, 13, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label114, 7, 13, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label115, 8, 13, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label116, 9,13, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label117, 10,13, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label121, 4, 14, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label122, 5, 14, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label123, 6, 14, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label124, 7, 14, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label125, 8, 14, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label126, 9,14, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label127, 10,14, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label131, 4, 15, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label132, 5, 15, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label133, 6, 15, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label134, 7, 15, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label135, 8, 15, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label136, 9,15, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label137, 10,15, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label141, 4, 16,1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label142, 5, 16, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label143, 6, 16, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label144, 7, 16, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label145, 8, 16, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label146, 9,16, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label147, 10,16, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label151, 4, 17, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label152, 5, 17, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label153, 6, 17, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label154, 7, 17, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label155, 8, 17, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label156, 9,17, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label157, 10,17, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label161, 4, 18, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label162, 5, 18, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label163, 6, 18, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label164, 7, 18, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label165, 8, 18, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label166, 9,18, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label167, 10,18, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), btnnxt, 10, 20, 2, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), btnpre, 4,20, 2, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), labelnull,1, 11, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), btn1, 2, 13, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), btn4, 1, 13, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), btn5, 0, 4, 2, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), btn11, 12, 4, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), btn12, 12, 5, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), btn13, 12, 6, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), btn14, 12, 7, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), btn15, 12, 8, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), btn16, 12, 9, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), btn17, 12, 10, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), btn18, 12, 11, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), btn19, 12, 12, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), btn10, 12, 13, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), btn111, 12, 14, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), btn112, 12, 15, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), btn113, 12, 16, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), btn114, 12, 17, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), btn115, 12, 18, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), add, 0, 0, 2, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), search, 2, 0, 2, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), edit, 4, 0, 2, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), delete, 6, 0, 2, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), btn6, 8, 0, 2, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), close, 10, 0, 2, 1);
	gtk_widget_show_all(win_grid->window);	
	return;
}
/***********************************************************************************frame : edit students details*/
void editstudent_details(GtkWidget *widget, Window_grid *win_grid){
	GtkWidget *close;
	addstu_grid = gtk_grid_new();
	gtk_container_remove(GTK_CONTAINER(win_grid->window), win_grid->grid);
	gtk_container_add(GTK_CONTAINER(win_grid->window), addstu_grid);
	win_grid->grid = addstu_grid;
	Gc_master *master;
	int max=10;
	Gc_label *structlabel;
	structlabel = (Gc_label *)malloc(sizeof(Gc_label));
	master = (Gc_master *)malloc(sizeof(Gc_master));
	structlabel->ent1=gtk_entry_new();
	structlabel->ent2=gtk_entry_new();
	structlabel->ent3=gtk_entry_new();
	structlabel->ent4=gtk_entry_new();
	structlabel->ent5=gtk_entry_new();
	structlabel->ent6=gtk_entry_new();
	gtk_entry_set_max_length(GTK_ENTRY(structlabel->ent6), max);
	structlabel->ent7=gtk_entry_new();
	structlabel->entry=gtk_entry_new();
	structlabel->window = win_grid->window;
	labelhead = gtk_label_new(NULL);
	gtk_label_set_markup(GTK_LABEL(labelhead), "<b><big>       EDIT STUDENT</big></b>\n");
	labelnull = gtk_label_new(" ");
	label1 = gtk_label_new("MIS");
	label2 = gtk_label_new("NAME");
	label3 = gtk_label_new("ADDRESS");
	label4= gtk_label_new("BRANCH");
	label5 = gtk_label_new("ROOMNO");
	label6= gtk_label_new("MOBILE-NO");
	label7 = gtk_label_new("EMAIL-ID");
	label11 = gtk_label_new("         MIS      ");
	label12 = gtk_label_new("        NAME        ");
	label13 = gtk_label_new("        ADDRESS     ");
	label14= gtk_label_new("         BRANCH      ");
	label15 = gtk_label_new("      ROOMNO     ");
	label16= gtk_label_new("         MOBILE-NO      ");
	label17 = gtk_label_new("                 EMAIL-ID               ");
	labeln21 = gtk_label_new("");
	labeln22 = gtk_label_new("");
	labeln23 = gtk_label_new("");
	labeln24= gtk_label_new("");
	labeln25 = gtk_label_new("");
	labeln26= gtk_label_new("");
	labeln27 = gtk_label_new("");
	add = gtk_button_new_with_label("Add Student Details");
	search = gtk_button_new_with_label("Search student Details");
	edit = gtk_button_new_with_label("Edit student Details");
	delete = gtk_button_new_with_label("Delete student Details");
	btn6 = gtk_button_new_with_label("View student Details");
	close = gtk_button_new_with_label("Close Application");
	structlabel->label21 = gtk_label_new("");
	structlabel->label22 = gtk_label_new("");
	structlabel->label23 = gtk_label_new("");
	structlabel->label24= gtk_label_new("");
	structlabel->label25 = gtk_label_new("");
	structlabel->label26= gtk_label_new("");
	structlabel->label27 = gtk_label_new("");
	structlabel->label31 = gtk_label_new("");
	structlabel->label32 = gtk_label_new("");
	structlabel->label33 = gtk_label_new("");
	structlabel->label34= gtk_label_new("");
	structlabel->label35 = gtk_label_new("");
	structlabel->label36= gtk_label_new("");
	structlabel->label37 = gtk_label_new("");
	labeln31 = gtk_label_new("");
	labeln32 = gtk_label_new("");
	labeln33 = gtk_label_new("");
	labeln34= gtk_label_new("");
	labeln35 = gtk_label_new("");
	labeln36= gtk_label_new("");
	labeln37 = gtk_label_new("");
	labeln41 = gtk_label_new("");
	labeln42 = gtk_label_new("");
	labeln43 = gtk_label_new("");
	labeln44= gtk_label_new("");
	labeln45 = gtk_label_new("");
	labeln46= gtk_label_new("");
	labeln47 = gtk_label_new("");
	structlabel->label41 = gtk_label_new("");
	structlabel->label42 = gtk_label_new("");
	structlabel->label43 = gtk_label_new("");
	structlabel->label44= gtk_label_new("");
	structlabel->label45 = gtk_label_new("");
	structlabel->label46= gtk_label_new("");
	structlabel->label47 = gtk_label_new("");
	structlabel->label51 = gtk_label_new("");
	structlabel->label52 = gtk_label_new("");
	structlabel->label53 = gtk_label_new("");
	structlabel->label54= gtk_label_new("");
	structlabel->label55 = gtk_label_new("");
	structlabel->label56= gtk_label_new("");
	structlabel->label57 = gtk_label_new("");
	structlabel->label61 = gtk_label_new("");
	structlabel->label62 = gtk_label_new("");
	structlabel->label63 = gtk_label_new("");
	structlabel->label64= gtk_label_new("");
	structlabel->label65 = gtk_label_new("");
	structlabel->label66= gtk_label_new("");
	structlabel->label67 = gtk_label_new("");
	structlabel->label71 = gtk_label_new("");
	structlabel->label72 = gtk_label_new("");
	structlabel->label73 = gtk_label_new("");
	structlabel->label74= gtk_label_new("");
	structlabel->label75 = gtk_label_new("");
	structlabel->label76= gtk_label_new("");
	structlabel->label77 = gtk_label_new("");
	structlabel->label81 = gtk_label_new("");
	structlabel->label82 = gtk_label_new("");
	structlabel->label83 = gtk_label_new("");
	structlabel->label84= gtk_label_new("");
	structlabel->label85 = gtk_label_new("");
	structlabel->label86= gtk_label_new("");
	structlabel->label87 = gtk_label_new("");
	structlabel->label91 = gtk_label_new("");
	structlabel->label92 = gtk_label_new("");
	structlabel->label93 = gtk_label_new("");
	structlabel->label94= gtk_label_new("");
	structlabel->label95 = gtk_label_new("");
	structlabel->label96= gtk_label_new("");
	structlabel->label97 = gtk_label_new("");
	structlabel->label101 = gtk_label_new("");
	structlabel->label102 = gtk_label_new("");
	structlabel->label103 = gtk_label_new("");
	structlabel->label104= gtk_label_new("");
	structlabel->label105 = gtk_label_new("");
	structlabel->label106= gtk_label_new("");
	structlabel->label107 = gtk_label_new("");
	structlabel->label111 = gtk_label_new("");
	structlabel->label112 = gtk_label_new("");
	structlabel->label113 = gtk_label_new("");
	structlabel->label114= gtk_label_new("");
	structlabel->label115 = gtk_label_new("");
	structlabel->label116= gtk_label_new("");
	structlabel->label117 = gtk_label_new("");
	structlabel->label121 = gtk_label_new("");
	structlabel->label122 = gtk_label_new("");
	structlabel->label123 = gtk_label_new("");
	structlabel->label124= gtk_label_new("");
	structlabel->label125 = gtk_label_new("");
	structlabel->label126= gtk_label_new("");
	structlabel->label127 = gtk_label_new("");
	structlabel->label131 = gtk_label_new("");
	structlabel->label132 = gtk_label_new("");
	structlabel->label133 = gtk_label_new("");
	structlabel->label134= gtk_label_new("");
	structlabel->label135 = gtk_label_new("");
	structlabel->label136= gtk_label_new("");
	structlabel->label137 = gtk_label_new("");
	structlabel->label141 = gtk_label_new("");
	structlabel->label142 = gtk_label_new("");
	structlabel->label143 = gtk_label_new("");
	structlabel->label144= gtk_label_new("");
	structlabel->label145 = gtk_label_new("");
	structlabel->label146= gtk_label_new("");
	structlabel->label147 = gtk_label_new("");
	structlabel->label151 = gtk_label_new("");
	structlabel->label152 = gtk_label_new("");
	structlabel->label153 = gtk_label_new("");
	structlabel->label154= gtk_label_new("");
	structlabel->label155 = gtk_label_new("");
	structlabel->label156= gtk_label_new("");
	structlabel->label157 = gtk_label_new("");
	structlabel->label161 = gtk_label_new("");
	structlabel->label162 = gtk_label_new("");
	structlabel->label163 = gtk_label_new("");
	structlabel->label164= gtk_label_new("");
	structlabel->label165 = gtk_label_new("");
	structlabel->label166= gtk_label_new("");
	structlabel->label167 = gtk_label_new("");
	btn1 = gtk_button_new_with_label("UPDATE");
	btn2 = gtk_button_new_with_label("HOME");
	btn3 = gtk_button_new_with_label("PASTE");
	btn4 = gtk_button_new_with_label("CLEAR");
	btn5 = gtk_button_new_with_label("EDIT by MIS");
	btnnxt = gtk_button_new_with_label("NEXT");
	btnpre = gtk_button_new_with_label("PREVIOUS");
	btnref = gtk_button_new_with_label("REFRESH");
	btn11 = gtk_button_new_with_label("EDIT");
	btn12 = gtk_button_new_with_label("EDIT");
	btn13 = gtk_button_new_with_label("EDIT");
	btn14 = gtk_button_new_with_label("EDIT");
	btn15 = gtk_button_new_with_label("EDIT");
	btn16 = gtk_button_new_with_label("EDIT");
	btn17 = gtk_button_new_with_label("EDIT");
	btn18 = gtk_button_new_with_label("EDIT");
	btn19 = gtk_button_new_with_label("EDIT");
	btn10 = gtk_button_new_with_label("EDIT");
	btn111 = gtk_button_new_with_label("EDIT");
	btn112 = gtk_button_new_with_label("EDIT");
	btn113 = gtk_button_new_with_label("EDIT");
	btn114 = gtk_button_new_with_label("EDIT");
	btn115 = gtk_button_new_with_label("EDIT");
	g_signal_connect(btn1, "clicked", G_CALLBACK(update_edited_record), structlabel);
	g_signal_connect(structlabel->entry, "activate", G_CALLBACK(searchinfile12), structlabel);
	g_signal_connect(btn11, "clicked", G_CALLBACK(dynamic_edit2), structlabel);
	g_signal_connect(btn12, "clicked", G_CALLBACK(dynamic_edit3), structlabel);
	g_signal_connect(btn13, "clicked", G_CALLBACK(dynamic_edit4), structlabel);
	g_signal_connect(btn14, "clicked", G_CALLBACK(dynamic_edit5), structlabel);
	g_signal_connect(btn15, "clicked", G_CALLBACK(dynamic_edit6), structlabel);
	g_signal_connect(btn16, "clicked", G_CALLBACK(dynamic_edit7), structlabel);
	g_signal_connect(btn17, "clicked", G_CALLBACK(dynamic_edit8), structlabel);
	g_signal_connect(btn18, "clicked", G_CALLBACK(dynamic_edit9), structlabel);
	g_signal_connect(btn19, "clicked", G_CALLBACK(dynamic_edit10), structlabel);
	g_signal_connect(btn10, "clicked", G_CALLBACK(dynamic_edit11), structlabel);
	g_signal_connect(btn111, "clicked", G_CALLBACK(dynamic_edit12), structlabel);
	g_signal_connect(btn112, "clicked", G_CALLBACK(dynamic_edit13), structlabel);
	g_signal_connect(btn113, "clicked", G_CALLBACK(dynamic_edit14), structlabel);
	g_signal_connect(btn114, "clicked", G_CALLBACK(dynamic_edit15), structlabel);
	g_signal_connect(btn115, "clicked", G_CALLBACK(dynamic_edit16), structlabel);
	g_signal_connect(btn5, "clicked", G_CALLBACK(searchinfile12), structlabel);
	g_signal_connect(btn4, "clicked", G_CALLBACK(cleartext), structlabel);
	g_signal_connect(btn2, "clicked", G_CALLBACK(activate), win_grid);
	g_signal_connect(btn3, "clicked", G_CALLBACK(searchinfiledynamic), structlabel);
	g_signal_connect(btnnxt, "clicked", G_CALLBACK(next), structlabel);
	g_signal_connect(btnpre, "clicked", G_CALLBACK(prev), structlabel);
	g_signal_connect(btnref, "clicked", G_CALLBACK(refresh), structlabel);
	g_signal_connect(add, "clicked", G_CALLBACK(addstudent_details), win_grid);
	g_signal_connect(search, "clicked", G_CALLBACK(search_student_details), win_grid);
	g_signal_connect(edit, "clicked", G_CALLBACK(editstudent_details), win_grid);
	g_signal_connect(delete, "clicked", G_CALLBACK(deletestudent_details), win_grid);
	g_signal_connect(btn6, "clicked", G_CALLBACK(view_student), win_grid);
	g_signal_connect(close, "clicked", G_CALLBACK(close_window), win_grid->window);
	p = 0;
	FILE *fp = fopen("studata.txt","r+");
		while(1){
			fscanf(fp, "%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\n]\n", rec.mis,  rec.name, rec.address, rec.branch, rec.blockno, rec.mobileno, rec.emailid, rec.date);
				if(p == 0) {	
			gtk_label_set_text(GTK_LABEL(structlabel->label21), rec.mis);
			gtk_label_set_text(GTK_LABEL(structlabel->label22), rec.name);
			gtk_label_set_text(GTK_LABEL(structlabel->label23), rec.address);
			gtk_label_set_text(GTK_LABEL(structlabel->label24), rec.branch);
			gtk_label_set_text(GTK_LABEL(structlabel->label25), rec.blockno);
			gtk_label_set_text(GTK_LABEL(structlabel->label26), rec.mobileno);
			gtk_label_set_text(GTK_LABEL(structlabel->label27), rec.emailid);
		}
		else if(p == 1) {	
			gtk_label_set_text(GTK_LABEL(structlabel->label31), rec.mis);
			gtk_label_set_text(GTK_LABEL(structlabel->label32), rec.name);
			gtk_label_set_text(GTK_LABEL(structlabel->label33), rec.address);
			gtk_label_set_text(GTK_LABEL(structlabel->label34), rec.branch);
			gtk_label_set_text(GTK_LABEL(structlabel->label35), rec.blockno);
			gtk_label_set_text(GTK_LABEL(structlabel->label36), rec.mobileno);
			gtk_label_set_text(GTK_LABEL(structlabel->label37), rec.emailid);
		}
		else if(p == 2) {	
			gtk_label_set_text(GTK_LABEL(structlabel->label41), rec.mis);
			gtk_label_set_text(GTK_LABEL(structlabel->label42), rec.name);
			gtk_label_set_text(GTK_LABEL(structlabel->label43), rec.address);
			gtk_label_set_text(GTK_LABEL(structlabel->label44), rec.branch);
			gtk_label_set_text(GTK_LABEL(structlabel->label45), rec.blockno);
			gtk_label_set_text(GTK_LABEL(structlabel->label46), rec.mobileno);
			gtk_label_set_text(GTK_LABEL(structlabel->label47), rec.emailid);
		}
		else if(p == 3) {	
			gtk_label_set_text(GTK_LABEL(structlabel->label51), rec.mis);
			gtk_label_set_text(GTK_LABEL(structlabel->label52), rec.name);
			gtk_label_set_text(GTK_LABEL(structlabel->label53), rec.address);
			gtk_label_set_text(GTK_LABEL(structlabel->label54), rec.branch);
			gtk_label_set_text(GTK_LABEL(structlabel->label55), rec.blockno);
			gtk_label_set_text(GTK_LABEL(structlabel->label56), rec.mobileno);
			gtk_label_set_text(GTK_LABEL(structlabel->label57), rec.emailid);
		}
		else if(p == 4) {	
			gtk_label_set_text(GTK_LABEL(structlabel->label61), rec.mis);
			gtk_label_set_text(GTK_LABEL(structlabel->label62), rec.name);
			gtk_label_set_text(GTK_LABEL(structlabel->label63), rec.address);
			gtk_label_set_text(GTK_LABEL(structlabel->label64), rec.branch);
			gtk_label_set_text(GTK_LABEL(structlabel->label65), rec.blockno);
			gtk_label_set_text(GTK_LABEL(structlabel->label66), rec.mobileno);
			gtk_label_set_text(GTK_LABEL(structlabel->label67), rec.emailid);
		}
		else if(p == 5) {	
			gtk_label_set_text(GTK_LABEL(structlabel->label71), rec.mis);
			gtk_label_set_text(GTK_LABEL(structlabel->label72), rec.name);
			gtk_label_set_text(GTK_LABEL(structlabel->label73), rec.address);
			gtk_label_set_text(GTK_LABEL(structlabel->label74), rec.branch);
			gtk_label_set_text(GTK_LABEL(structlabel->label75), rec.blockno);
			gtk_label_set_text(GTK_LABEL(structlabel->label76), rec.mobileno);
			gtk_label_set_text(GTK_LABEL(structlabel->label77), rec.emailid);
		}
		else if(p == 6) {	
			gtk_label_set_text(GTK_LABEL(structlabel->label81), rec.mis);
			gtk_label_set_text(GTK_LABEL(structlabel->label82), rec.name);
			gtk_label_set_text(GTK_LABEL(structlabel->label83), rec.address);
			gtk_label_set_text(GTK_LABEL(structlabel->label84), rec.branch);
			gtk_label_set_text(GTK_LABEL(structlabel->label85), rec.blockno);
			gtk_label_set_text(GTK_LABEL(structlabel->label86), rec.mobileno);
			gtk_label_set_text(GTK_LABEL(structlabel->label87), rec.emailid);
		}
		else if(p == 7) {	
			gtk_label_set_text(GTK_LABEL(structlabel->label91), rec.mis);
			gtk_label_set_text(GTK_LABEL(structlabel->label92), rec.name);
			gtk_label_set_text(GTK_LABEL(structlabel->label93), rec.address);
			gtk_label_set_text(GTK_LABEL(structlabel->label94), rec.branch);
			gtk_label_set_text(GTK_LABEL(structlabel->label95), rec.blockno);
			gtk_label_set_text(GTK_LABEL(structlabel->label96), rec.mobileno);
			gtk_label_set_text(GTK_LABEL(structlabel->label97), rec.emailid);
		}
		else if(p == 8) {	
			gtk_label_set_text(GTK_LABEL(structlabel->label101), rec.mis);
			gtk_label_set_text(GTK_LABEL(structlabel->label102), rec.name);
			gtk_label_set_text(GTK_LABEL(structlabel->label103), rec.address);
			gtk_label_set_text(GTK_LABEL(structlabel->label104), rec.branch);
			gtk_label_set_text(GTK_LABEL(structlabel->label105), rec.blockno);
			gtk_label_set_text(GTK_LABEL(structlabel->label106), rec.mobileno);
			gtk_label_set_text(GTK_LABEL(structlabel->label107), rec.emailid);
		}
		else if(p == 9) {	
			gtk_label_set_text(GTK_LABEL(structlabel->label111), rec.mis);
			gtk_label_set_text(GTK_LABEL(structlabel->label112), rec.name);
			gtk_label_set_text(GTK_LABEL(structlabel->label113), rec.address);
			gtk_label_set_text(GTK_LABEL(structlabel->label114), rec.branch);
			gtk_label_set_text(GTK_LABEL(structlabel->label115), rec.blockno);
			gtk_label_set_text(GTK_LABEL(structlabel->label116), rec.mobileno);
			gtk_label_set_text(GTK_LABEL(structlabel->label117), rec.emailid);
		}
		else if(p == 10) {	
			gtk_label_set_text(GTK_LABEL(structlabel->label121), rec.mis);
			gtk_label_set_text(GTK_LABEL(structlabel->label122), rec.name);
			gtk_label_set_text(GTK_LABEL(structlabel->label123), rec.address);
			gtk_label_set_text(GTK_LABEL(structlabel->label124), rec.branch);
			gtk_label_set_text(GTK_LABEL(structlabel->label125), rec.blockno);
			gtk_label_set_text(GTK_LABEL(structlabel->label126), rec.mobileno);
			gtk_label_set_text(GTK_LABEL(structlabel->label127), rec.emailid);
		}
		else if(p == 11) {	
			gtk_label_set_text(GTK_LABEL(structlabel->label131), rec.mis);
			gtk_label_set_text(GTK_LABEL(structlabel->label132), rec.name);
			gtk_label_set_text(GTK_LABEL(structlabel->label133), rec.address);
			gtk_label_set_text(GTK_LABEL(structlabel->label134), rec.branch);
			gtk_label_set_text(GTK_LABEL(structlabel->label135), rec.blockno);
			gtk_label_set_text(GTK_LABEL(structlabel->label136), rec.mobileno);
			gtk_label_set_text(GTK_LABEL(structlabel->label137), rec.emailid);
		}
		else if(p == 12) {	
			gtk_label_set_text(GTK_LABEL(structlabel->label141), rec.mis);
			gtk_label_set_text(GTK_LABEL(structlabel->label142), rec.name);
			gtk_label_set_text(GTK_LABEL(structlabel->label143), rec.address);
			gtk_label_set_text(GTK_LABEL(structlabel->label144), rec.branch);
			gtk_label_set_text(GTK_LABEL(structlabel->label145), rec.blockno);
			gtk_label_set_text(GTK_LABEL(structlabel->label146), rec.mobileno);
			gtk_label_set_text(GTK_LABEL(structlabel->label147), rec.emailid);
		}
		else if(p == 13) {	
			gtk_label_set_text(GTK_LABEL(structlabel->label151), rec.mis);
			gtk_label_set_text(GTK_LABEL(structlabel->label152), rec.name);
			gtk_label_set_text(GTK_LABEL(structlabel->label153), rec.address);
			gtk_label_set_text(GTK_LABEL(structlabel->label154), rec.branch);
			gtk_label_set_text(GTK_LABEL(structlabel->label155), rec.blockno);
			gtk_label_set_text(GTK_LABEL(structlabel->label156), rec.mobileno);
			gtk_label_set_text(GTK_LABEL(structlabel->label157), rec.emailid);
		}
		else if(p == 14) {	
			gtk_label_set_text(GTK_LABEL(structlabel->label161), rec.mis);
			gtk_label_set_text(GTK_LABEL(structlabel->label162), rec.name);
			gtk_label_set_text(GTK_LABEL(structlabel->label163), rec.address);
			gtk_label_set_text(GTK_LABEL(structlabel->label164), rec.branch);
			gtk_label_set_text(GTK_LABEL(structlabel->label165), rec.blockno);
			gtk_label_set_text(GTK_LABEL(structlabel->label166), rec.mobileno);
			gtk_label_set_text(GTK_LABEL(structlabel->label167), rec.emailid);
			p=0;
			break;
		}
		if(feof(fp)){
			break;	
		}
		p++;
	}
	fclose(fp);												 /*adding components to frame*/
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->entry, 2,4, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->ent1, 2,5, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->ent2, 2,6, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->ent3, 2,7, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->ent4, 2,8, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->ent5, 2,9, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->ent6, 2,10, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->ent7, 2,11, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), labelhead, 1, 2, 2 , 2);
	gtk_grid_attach(GTK_GRID(win_grid->grid), label1, 1, 5, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), label2, 1, 6, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), label3, 1, 7, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), label4, 1, 8, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), label5, 1, 9, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), label6, 1, 10, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), label7, 1, 11, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), label11, 4, 2, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), label12, 5, 2, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), label13, 6, 2, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), label14, 7, 2, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), label15, 8, 2, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), label16, 9, 2, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), label17, 10 , 2, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), labeln21, 5, 3, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), labeln22, 6, 3, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), labeln23, 7, 3, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), labeln24, 8, 3, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), labeln25, 9, 3, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), labeln26, 10,3, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), labeln27, 11, 3, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label21, 4, 4, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label22, 5, 4, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label23, 6, 4, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label24, 7, 4, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label25, 8, 4, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label26, 9,4, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label27, 10, 4, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label31, 4, 5, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label32, 5, 5, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label33, 6, 5, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label34, 7, 5, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label35, 8, 5, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label36, 9,5, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label37, 10, 5, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), labeln31, 0, 1, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), labeln32, 2, 1, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), labeln33, 3, 1, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), labeln34, 4, 1, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), labeln35, 5, 1, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), labeln36, 8,1, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), labeln37, 9,1, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), labeln41, 0, 19, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), labeln42, 2, 19, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), labeln43, 3, 19, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), labeln44, 4, 19, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), labeln45, 5, 19, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), labeln46, 8,19, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), labeln47, 9,19, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label41, 4, 6, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label42, 5, 6, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label43, 6, 6, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label44, 7, 6, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label45, 8, 6, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label46, 9,6, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label47, 10, 6, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label51, 4, 7, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label52, 5, 7, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label53, 6, 7, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label54, 7, 7, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label55, 8, 7, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label56, 9,7, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label57, 10,7, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label61, 4, 8, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label62, 5, 8, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label63, 6, 8, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label64, 7, 8, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label65, 8, 8, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label66, 9,8, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label67, 10,8, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label71, 4, 9, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label72, 5, 9, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label73, 6, 9, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label74, 7, 9, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label75, 8, 9, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label76, 9,9, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label77, 10,9, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label81, 4, 10, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label82, 5, 10, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label83, 6, 10, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label84, 7, 10, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label85, 8, 10, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label86, 9,10, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label87, 10,10, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label91, 4, 11, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label92, 5, 11, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label93, 6, 11, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label94, 7, 11, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label95, 8, 11, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label96, 9,11, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label97, 10,11, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label101, 4, 12, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label102, 5, 12, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label103, 6, 12, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label104, 7, 12, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label105, 8, 12, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label106, 9,12, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label107, 10,12, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label111, 4, 13, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label112, 5, 13, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label113, 6, 13, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label114, 7, 13, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label115, 8, 13, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label116, 9,13, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label117, 10,13, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label121, 4, 14, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label122, 5, 14, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label123, 6, 14, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label124, 7, 14, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label125, 8, 14, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label126, 9,14, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label127, 10,14, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label131, 4, 15, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label132, 5, 15, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label133, 6, 15, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label134, 7, 15, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label135, 8, 15, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label136, 9,15, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label137, 10,15, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label141, 4, 16,1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label142, 5, 16, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label143, 6, 16, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label144, 7, 16, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label145, 8, 16, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label146, 9,16, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label147, 10,16, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label151, 4, 17, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label152, 5, 17, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label153, 6, 17, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label154, 7, 17, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label155, 8, 17, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label156, 9,17, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label157, 10,17, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label161, 4, 18, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label162, 5, 18, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label163, 6, 18, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label164, 7, 18, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label165, 8, 18, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label166, 9,18, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label167, 10,18, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), btnnxt, 10, 20, 2, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), btnpre, 4,20, 2, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), labelnull,1, 11, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), btn1, 2, 13, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), btn4, 1, 13, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), btn5, 0, 4, 2, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), btn11, 12, 4, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), btn12, 12, 5, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), btn13, 12, 6, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), btn14, 12, 7, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), btn15, 12, 8, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), btn16, 12, 9, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), btn17, 12, 10, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), btn18, 12, 11, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), btn19, 12, 12, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), btn10, 12, 13, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), btn111, 12, 14, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), btn112, 12, 15, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), btn113, 12, 16, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), btn114, 12, 17, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), btn115, 12, 18, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), add, 0, 0, 2, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), search, 2, 0, 2, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), edit, 4, 0, 2, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), delete, 6, 0, 2, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), btn6, 8, 0, 2, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), close, 10, 0, 2, 1);
	gtk_widget_show_all(win_grid->window);	
	return;
}
/***********************************************************************************frame : add student details*/
void addstudent_details(GtkWidget *widget, Window_grid *win_grid){
	GtkWidget *close;
	addstu_grid = gtk_grid_new();
	gtk_container_remove(GTK_CONTAINER(win_grid->window), win_grid->grid);
	gtk_container_add(GTK_CONTAINER(win_grid->window), addstu_grid);
	win_grid->grid = addstu_grid;
	Gc_label *structlabel;
	int max=10;
	structlabel = (Gc_label *)malloc(sizeof(Gc_label));
	structlabel->window=win_grid->window;
	structlabel->ent1=gtk_entry_new();
	structlabel->ent2=gtk_entry_new();
	structlabel->ent3=gtk_entry_new();
	structlabel->ent4=gtk_entry_new();
	structlabel->ent5=gtk_entry_new();
	structlabel->ent6=gtk_entry_new();
	gtk_entry_set_max_length(GTK_ENTRY(structlabel->ent6), max);
	structlabel->ent7=gtk_entry_new();
	structlabel->entry=gtk_entry_new();
	labelhead = gtk_label_new(NULL);
	gtk_label_set_markup(GTK_LABEL(labelhead), "<b><big>       ADD STUDENT</big></b>\n");
	labelnull = gtk_label_new(" ");
	label1 = gtk_label_new("MIS");
	label2 = gtk_label_new("NAME");
	label3 = gtk_label_new("ADDRESS");
	label4= gtk_label_new("BRANCH");
	label5 = gtk_label_new("ROOMNO");
	label6= gtk_label_new("MOBILE-NO");
	label7 = gtk_label_new("EMAIL-ID");
	label8 = gtk_label_new("DATE OF JOIN");
	label11 = gtk_label_new("         MIS      ");
	label12 = gtk_label_new("        NAME        ");
	label13 = gtk_label_new("        ADDRESS     ");
	label14= gtk_label_new("         BRANCH      ");
	label15 = gtk_label_new("      ROOMNO     ");
	label16= gtk_label_new("         MOBILE-NO      ");
	label17 = gtk_label_new("                 EMAIL-ID               ");
	label18 = gtk_label_new("	DATE OF JOIN	");
	structlabel->label28 = gtk_label_new("");
	structlabel->label38 = gtk_label_new("");
	structlabel->label48 = gtk_label_new("");
	structlabel->label58 = gtk_label_new("");
	structlabel->label68 = gtk_label_new("");
	structlabel->label78 = gtk_label_new("");
	structlabel->label88 = gtk_label_new("");
	structlabel->label98 = gtk_label_new("");
	structlabel->label108 = gtk_label_new("");
	structlabel->label118 = gtk_label_new("");
	structlabel->label128 = gtk_label_new("");
	structlabel->label138 = gtk_label_new("");
	structlabel->label148 = gtk_label_new("");
	structlabel->label158 = gtk_label_new("");
	structlabel->label168 = gtk_label_new("");
	labeln21 = gtk_label_new("");
	labeln22 = gtk_label_new("");
	labeln23 = gtk_label_new("");
	labeln24= gtk_label_new("");
	labeln25 = gtk_label_new("");
	labeln26= gtk_label_new("");
	labeln27 = gtk_label_new("");
	add = gtk_button_new_with_label("Add Student Details");
	search = gtk_button_new_with_label("Search student Details");
	edit = gtk_button_new_with_label("Edit student Details");
	delete = gtk_button_new_with_label("Delete student Details");
	btn6 = gtk_button_new_with_label("View student Details");
	close = gtk_button_new_with_label("Close Application");
	structlabel->label21 = gtk_label_new("");
	structlabel->label22 = gtk_label_new("");
	structlabel->label23 = gtk_label_new("");
	structlabel->label24= gtk_label_new("");
	structlabel->label25 = gtk_label_new("");
	structlabel->label26= gtk_label_new("");
	structlabel->label27 = gtk_label_new("");
	structlabel->label31 = gtk_label_new("");
	structlabel->label32 = gtk_label_new("");
	structlabel->label33 = gtk_label_new("");
	structlabel->label34= gtk_label_new("");
	structlabel->label35 = gtk_label_new("");
	structlabel->label36= gtk_label_new("");
	structlabel->label37 = gtk_label_new("");
	labeln31 = gtk_label_new("");
	labeln32 = gtk_label_new("");
	labeln33 = gtk_label_new("");
	labeln34= gtk_label_new("");
	labeln35 = gtk_label_new("");
	labeln36= gtk_label_new("");
	labeln37 = gtk_label_new("");
	labeln41 = gtk_label_new("");
	labeln42 = gtk_label_new("");
	labeln43 = gtk_label_new("");
	labeln44= gtk_label_new("");
	labeln45 = gtk_label_new("");
	labeln46= gtk_label_new("");
	labeln47 = gtk_label_new("");
	structlabel->label41 = gtk_label_new("");
	structlabel->label42 = gtk_label_new("");
	structlabel->label43 = gtk_label_new("");
	structlabel->label44= gtk_label_new("");
	structlabel->label45 = gtk_label_new("");
	structlabel->label46= gtk_label_new("");
	structlabel->label47 = gtk_label_new("");
	structlabel->label51 = gtk_label_new("");
	structlabel->label52 = gtk_label_new("");
	structlabel->label53 = gtk_label_new("");
	structlabel->label54= gtk_label_new("");
	structlabel->label55 = gtk_label_new("");
	structlabel->label56= gtk_label_new("");
	structlabel->label57 = gtk_label_new("");
	structlabel->label61 = gtk_label_new("");
	structlabel->label62 = gtk_label_new("");
	structlabel->label63 = gtk_label_new("");
	structlabel->label64= gtk_label_new("");
	structlabel->label65 = gtk_label_new("");
	structlabel->label66= gtk_label_new("");
	structlabel->label67 = gtk_label_new("");
	structlabel->label71 = gtk_label_new("");
	structlabel->label72 = gtk_label_new("");
	structlabel->label73 = gtk_label_new("");
	structlabel->label74= gtk_label_new("");
	structlabel->label75 = gtk_label_new("");
	structlabel->label76= gtk_label_new("");
	structlabel->label77 = gtk_label_new("");
	structlabel->label81 = gtk_label_new("");
	structlabel->label82 = gtk_label_new("");
	structlabel->label83 = gtk_label_new("");
	structlabel->label84= gtk_label_new("");
	structlabel->label85 = gtk_label_new("");
	structlabel->label86= gtk_label_new("");
	structlabel->label87 = gtk_label_new("");
	structlabel->label91 = gtk_label_new("");
	structlabel->label92 = gtk_label_new("");
	structlabel->label93 = gtk_label_new("");
	structlabel->label94= gtk_label_new("");
	structlabel->label95 = gtk_label_new("");
	structlabel->label96= gtk_label_new("");
	structlabel->label97 = gtk_label_new("");
	structlabel->label101 = gtk_label_new("");
	structlabel->label102 = gtk_label_new("");
	structlabel->label103 = gtk_label_new("");
	structlabel->label104= gtk_label_new("");
	structlabel->label105 = gtk_label_new("");
	structlabel->label106= gtk_label_new("");
	structlabel->label107 = gtk_label_new("");
	structlabel->label111 = gtk_label_new("");
	structlabel->label112 = gtk_label_new("");
	structlabel->label113 = gtk_label_new("");
	structlabel->label114= gtk_label_new("");
	structlabel->label115 = gtk_label_new("");
	structlabel->label116= gtk_label_new("");
	structlabel->label117 = gtk_label_new("");
	structlabel->label121 = gtk_label_new("");
	structlabel->label122 = gtk_label_new("");
	structlabel->label123 = gtk_label_new("");
	structlabel->label124= gtk_label_new("");
	structlabel->label125 = gtk_label_new("");
	structlabel->label126= gtk_label_new("");
	structlabel->label127 = gtk_label_new("");
	structlabel->label131 = gtk_label_new("");
	structlabel->label132 = gtk_label_new("");
	structlabel->label133 = gtk_label_new("");
	structlabel->label134= gtk_label_new("");
	structlabel->label135 = gtk_label_new("");
	structlabel->label136= gtk_label_new("");
	structlabel->label137 = gtk_label_new("");
	structlabel->label141 = gtk_label_new("");
	structlabel->label142 = gtk_label_new("");
	structlabel->label143 = gtk_label_new("");
	structlabel->label144= gtk_label_new("");
	structlabel->label145 = gtk_label_new("");
	structlabel->label146= gtk_label_new("");
	structlabel->label147 = gtk_label_new("");
	structlabel->label151 = gtk_label_new("");
	structlabel->label152 = gtk_label_new("");
	structlabel->label153 = gtk_label_new("");
	structlabel->label154= gtk_label_new("");
	structlabel->label155 = gtk_label_new("");
	structlabel->label156= gtk_label_new("");
	structlabel->label157 = gtk_label_new("");
	structlabel->label161 = gtk_label_new("");
	structlabel->label162 = gtk_label_new("");
	structlabel->label163 = gtk_label_new("");
	structlabel->label164= gtk_label_new("");
	structlabel->label165 = gtk_label_new("");
	structlabel->label166= gtk_label_new("");
	structlabel->label167 = gtk_label_new("");
	btn1 = gtk_button_new_with_label("SUBMIT");
	btnnxt = gtk_button_new_with_label("NEXT");
	btnpre = gtk_button_new_with_label("PREVIOUS");
	btnref = gtk_button_new_with_label("REFRESH");
	g_signal_connect(btn1, "clicked", G_CALLBACK(on_button_click), structlabel);
	g_signal_connect(btnnxt, "clicked", G_CALLBACK(nextnext), structlabel);
	g_signal_connect(btnpre, "clicked", G_CALLBACK(previous), structlabel);
	g_signal_connect(add, "clicked", G_CALLBACK(addstudent_details), win_grid);
	g_signal_connect(search, "clicked", G_CALLBACK(search_student_details), win_grid);
	g_signal_connect(edit, "clicked", G_CALLBACK(editstudent_details), win_grid);
	g_signal_connect(btn6, "clicked", G_CALLBACK(view_student), win_grid);
	g_signal_connect(delete, "clicked", G_CALLBACK(deletestudent_details), win_grid);
	gtk_grid_attach(GTK_GRID(win_grid->grid), btn6, 8, 0, 2, 1);
	g_signal_connect(close, "clicked", G_CALLBACK(close_window), win_grid->window);
	p = 0;
	FILE *fp = fopen("studata.txt","r+");
	while(1){
		fscanf(fp, "%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\n]\n", rec.mis,  rec.name, rec.address, rec.branch, rec.blockno, rec.mobileno, rec.emailid, rec.date);
		if(p == 0) {	
			gtk_label_set_text(GTK_LABEL(structlabel->label21), rec.mis);
			gtk_label_set_text(GTK_LABEL(structlabel->label22), rec.name);
			gtk_label_set_text(GTK_LABEL(structlabel->label23), rec.address);
			gtk_label_set_text(GTK_LABEL(structlabel->label24), rec.branch);
			gtk_label_set_text(GTK_LABEL(structlabel->label25), rec.blockno);
			gtk_label_set_text(GTK_LABEL(structlabel->label26), rec.mobileno);
			gtk_label_set_text(GTK_LABEL(structlabel->label27), rec.emailid);
			gtk_label_set_text(GTK_LABEL(structlabel->label28), rec.date);
		}
		else if(p == 1) {	
			gtk_label_set_text(GTK_LABEL(structlabel->label31), rec.mis);
			gtk_label_set_text(GTK_LABEL(structlabel->label32), rec.name);
			gtk_label_set_text(GTK_LABEL(structlabel->label33), rec.address);
			gtk_label_set_text(GTK_LABEL(structlabel->label34), rec.branch);
			gtk_label_set_text(GTK_LABEL(structlabel->label35), rec.blockno);
			gtk_label_set_text(GTK_LABEL(structlabel->label36), rec.mobileno);
			gtk_label_set_text(GTK_LABEL(structlabel->label37), rec.emailid);
			gtk_label_set_text(GTK_LABEL(structlabel->label38), rec.date);
		}
		else if(p == 2) {	
			gtk_label_set_text(GTK_LABEL(structlabel->label41), rec.mis);
			gtk_label_set_text(GTK_LABEL(structlabel->label42), rec.name);
			gtk_label_set_text(GTK_LABEL(structlabel->label43), rec.address);
			gtk_label_set_text(GTK_LABEL(structlabel->label44), rec.branch);
			gtk_label_set_text(GTK_LABEL(structlabel->label45), rec.blockno);
			gtk_label_set_text(GTK_LABEL(structlabel->label46), rec.mobileno);
			gtk_label_set_text(GTK_LABEL(structlabel->label47), rec.emailid);
			gtk_label_set_text(GTK_LABEL(structlabel->label48), rec.date);
		}
		else if(p == 3) {	
			gtk_label_set_text(GTK_LABEL(structlabel->label51), rec.mis);
			gtk_label_set_text(GTK_LABEL(structlabel->label52), rec.name);
			gtk_label_set_text(GTK_LABEL(structlabel->label53), rec.address);
			gtk_label_set_text(GTK_LABEL(structlabel->label54), rec.branch);
			gtk_label_set_text(GTK_LABEL(structlabel->label55), rec.blockno);
			gtk_label_set_text(GTK_LABEL(structlabel->label56), rec.mobileno);
			gtk_label_set_text(GTK_LABEL(structlabel->label57), rec.emailid);
			gtk_label_set_text(GTK_LABEL(structlabel->label58), rec.date);
		}
		else if(p == 4) {	
			gtk_label_set_text(GTK_LABEL(structlabel->label61), rec.mis);
			gtk_label_set_text(GTK_LABEL(structlabel->label62), rec.name);
			gtk_label_set_text(GTK_LABEL(structlabel->label63), rec.address);
			gtk_label_set_text(GTK_LABEL(structlabel->label64), rec.branch);
			gtk_label_set_text(GTK_LABEL(structlabel->label65), rec.blockno);
			gtk_label_set_text(GTK_LABEL(structlabel->label66), rec.mobileno);
			gtk_label_set_text(GTK_LABEL(structlabel->label67), rec.emailid);
			gtk_label_set_text(GTK_LABEL(structlabel->label68), rec.date);
		}
		else if(p == 5) {	
			gtk_label_set_text(GTK_LABEL(structlabel->label71), rec.mis);
			gtk_label_set_text(GTK_LABEL(structlabel->label72), rec.name);
			gtk_label_set_text(GTK_LABEL(structlabel->label73), rec.address);
			gtk_label_set_text(GTK_LABEL(structlabel->label74), rec.branch);
			gtk_label_set_text(GTK_LABEL(structlabel->label75), rec.blockno);
			gtk_label_set_text(GTK_LABEL(structlabel->label76), rec.mobileno);
			gtk_label_set_text(GTK_LABEL(structlabel->label77), rec.emailid);
			gtk_label_set_text(GTK_LABEL(structlabel->label78), rec.date);
		}
		else if(p == 6) {	
			gtk_label_set_text(GTK_LABEL(structlabel->label81), rec.mis);
			gtk_label_set_text(GTK_LABEL(structlabel->label82), rec.name);
			gtk_label_set_text(GTK_LABEL(structlabel->label83), rec.address);
			gtk_label_set_text(GTK_LABEL(structlabel->label84), rec.branch);
			gtk_label_set_text(GTK_LABEL(structlabel->label85), rec.blockno);
			gtk_label_set_text(GTK_LABEL(structlabel->label86), rec.mobileno);
			gtk_label_set_text(GTK_LABEL(structlabel->label87), rec.emailid);
			gtk_label_set_text(GTK_LABEL(structlabel->label88), rec.date);
		}
		else if(p == 7) {	
			gtk_label_set_text(GTK_LABEL(structlabel->label91), rec.mis);
			gtk_label_set_text(GTK_LABEL(structlabel->label92), rec.name);
			gtk_label_set_text(GTK_LABEL(structlabel->label93), rec.address);
			gtk_label_set_text(GTK_LABEL(structlabel->label94), rec.branch);
			gtk_label_set_text(GTK_LABEL(structlabel->label95), rec.blockno);
			gtk_label_set_text(GTK_LABEL(structlabel->label96), rec.mobileno);
			gtk_label_set_text(GTK_LABEL(structlabel->label97), rec.emailid);
			gtk_label_set_text(GTK_LABEL(structlabel->label98), rec.date);
		}
		else if(p == 8) {	
			gtk_label_set_text(GTK_LABEL(structlabel->label101), rec.mis);
			gtk_label_set_text(GTK_LABEL(structlabel->label102), rec.name);
			gtk_label_set_text(GTK_LABEL(structlabel->label103), rec.address);
			gtk_label_set_text(GTK_LABEL(structlabel->label104), rec.branch);
			gtk_label_set_text(GTK_LABEL(structlabel->label105), rec.blockno);
			gtk_label_set_text(GTK_LABEL(structlabel->label106), rec.mobileno);
			gtk_label_set_text(GTK_LABEL(structlabel->label107), rec.emailid);
			gtk_label_set_text(GTK_LABEL(structlabel->label108), rec.date);
		}
		else if(p == 9) {	
			gtk_label_set_text(GTK_LABEL(structlabel->label111), rec.mis);
			gtk_label_set_text(GTK_LABEL(structlabel->label112), rec.name);
			gtk_label_set_text(GTK_LABEL(structlabel->label113), rec.address);
			gtk_label_set_text(GTK_LABEL(structlabel->label114), rec.branch);
			gtk_label_set_text(GTK_LABEL(structlabel->label115), rec.blockno);
			gtk_label_set_text(GTK_LABEL(structlabel->label116), rec.mobileno);
			gtk_label_set_text(GTK_LABEL(structlabel->label117), rec.emailid);
			gtk_label_set_text(GTK_LABEL(structlabel->label118), rec.date);
		}
		else if(p == 10) {	
			gtk_label_set_text(GTK_LABEL(structlabel->label121), rec.mis);
			gtk_label_set_text(GTK_LABEL(structlabel->label122), rec.name);
			gtk_label_set_text(GTK_LABEL(structlabel->label123), rec.address);
			gtk_label_set_text(GTK_LABEL(structlabel->label124), rec.branch);
			gtk_label_set_text(GTK_LABEL(structlabel->label125), rec.blockno);
			gtk_label_set_text(GTK_LABEL(structlabel->label126), rec.mobileno);
			gtk_label_set_text(GTK_LABEL(structlabel->label127), rec.emailid);
			gtk_label_set_text(GTK_LABEL(structlabel->label128), rec.date);
		}
		else if(p == 11) {	
			gtk_label_set_text(GTK_LABEL(structlabel->label131), rec.mis);
			gtk_label_set_text(GTK_LABEL(structlabel->label132), rec.name);
			gtk_label_set_text(GTK_LABEL(structlabel->label133), rec.address);
			gtk_label_set_text(GTK_LABEL(structlabel->label134), rec.branch);
			gtk_label_set_text(GTK_LABEL(structlabel->label135), rec.blockno);
			gtk_label_set_text(GTK_LABEL(structlabel->label136), rec.mobileno);
			gtk_label_set_text(GTK_LABEL(structlabel->label137), rec.emailid);
			gtk_label_set_text(GTK_LABEL(structlabel->label138), rec.date);
		}
		else if(p == 12) {	
			gtk_label_set_text(GTK_LABEL(structlabel->label141), rec.mis);
			gtk_label_set_text(GTK_LABEL(structlabel->label142), rec.name);
			gtk_label_set_text(GTK_LABEL(structlabel->label143), rec.address);
			gtk_label_set_text(GTK_LABEL(structlabel->label144), rec.branch);
			gtk_label_set_text(GTK_LABEL(structlabel->label145), rec.blockno);
			gtk_label_set_text(GTK_LABEL(structlabel->label146), rec.mobileno);
			gtk_label_set_text(GTK_LABEL(structlabel->label147), rec.emailid);
			gtk_label_set_text(GTK_LABEL(structlabel->label148), rec.date);
		}
		else if(p == 13) {	
			gtk_label_set_text(GTK_LABEL(structlabel->label151), rec.mis);
			gtk_label_set_text(GTK_LABEL(structlabel->label152), rec.name);
			gtk_label_set_text(GTK_LABEL(structlabel->label153), rec.address);
			gtk_label_set_text(GTK_LABEL(structlabel->label154), rec.branch);
			gtk_label_set_text(GTK_LABEL(structlabel->label155), rec.blockno);
			gtk_label_set_text(GTK_LABEL(structlabel->label156), rec.mobileno);
			gtk_label_set_text(GTK_LABEL(structlabel->label157), rec.emailid);
			gtk_label_set_text(GTK_LABEL(structlabel->label158), rec.date);
		}
		else if(p == 14) {	
			gtk_label_set_text(GTK_LABEL(structlabel->label161), rec.mis);
			gtk_label_set_text(GTK_LABEL(structlabel->label162), rec.name);
			gtk_label_set_text(GTK_LABEL(structlabel->label163), rec.address);
			gtk_label_set_text(GTK_LABEL(structlabel->label164), rec.branch);
			gtk_label_set_text(GTK_LABEL(structlabel->label165), rec.blockno);
			gtk_label_set_text(GTK_LABEL(structlabel->label166), rec.mobileno);
			gtk_label_set_text(GTK_LABEL(structlabel->label167), rec.emailid);
			gtk_label_set_text(GTK_LABEL(structlabel->label168), rec.date);
			p=0;
			break;
		}
		if(feof(fp)){
			break;	
		}
		p++;
	}
	fclose(fp);		  						 /*adding components to frame*/
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->entry, 2,12, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->ent1, 2,5, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->ent2, 2,6, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->ent3, 2,7, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->ent4, 2,8, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->ent5, 2,9, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->ent6, 2,10, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->ent7, 2,11, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), labelhead, 1, 2, 2 , 2);
	gtk_grid_attach(GTK_GRID(win_grid->grid), label1, 1, 5, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), label2, 1, 6, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), label3, 1, 7, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), label4, 1, 8, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), label5, 1, 9, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), label6, 1, 10, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), label7, 1, 11, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), label8, 1, 12, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), label11, 4, 2, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), label12, 5, 2, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), label13, 6, 2, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), label14, 7, 2, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), label15, 8, 2, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), label16, 9, 2, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), label17, 10 , 2, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), labeln21, 5, 3, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), labeln22, 6, 3, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), labeln23, 7, 3, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), labeln24, 8, 3, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), labeln25, 9, 3, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), labeln26, 10,3, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), labeln27, 11, 3, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label21, 4, 4, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label22, 5, 4, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label23, 6, 4, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label24, 7, 4, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label25, 8, 4, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label26, 9,4, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label27, 10, 4, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label31, 4, 5, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label32, 5, 5, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label33, 6, 5, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label34, 7, 5, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label35, 8, 5, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label36, 9,5, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label37, 10, 5, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), labeln31, 0, 1, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), labeln32, 2, 1, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), labeln33, 3, 1, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), labeln34, 4, 1, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), labeln35, 5, 1, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), labeln36, 8,1, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), labeln37, 9,1, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), labeln41, 0, 19, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), labeln42, 2, 19, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), labeln43, 3, 19, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), labeln44, 4, 19, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), labeln45, 5, 19, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), labeln46, 8,19, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), labeln47, 9,19, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label41, 4, 6, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label42, 5, 6, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label43, 6, 6, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label44, 7, 6, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label45, 8, 6, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label46, 9,6, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label47, 10, 6, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label51, 4, 7, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label52, 5, 7, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label53, 6, 7, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label54, 7, 7, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label55, 8, 7, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label56, 9,7, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label57, 10,7, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label61, 4, 8, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label62, 5, 8, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label63, 6, 8, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label64, 7, 8, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label65, 8, 8, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label66, 9,8, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label67, 10,8, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label71, 4, 9, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label72, 5, 9, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label73, 6, 9, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label74, 7, 9, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label75, 8, 9, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label76, 9,9, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label77, 10,9, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label81, 4, 10, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label82, 5, 10, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label83, 6, 10, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label84, 7, 10, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label85, 8, 10, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label86, 9,10, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label87, 10,10, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label91, 4, 11, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label92, 5, 11, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label93, 6, 11, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label94, 7, 11, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label95, 8, 11, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label96, 9,11, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label97, 10,11, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label101, 4, 12, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label102, 5, 12, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label103, 6, 12, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label104, 7, 12, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label105, 8, 12, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label106, 9,12, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label107, 10,12, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label111, 4, 13, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label112, 5, 13, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label113, 6, 13, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label114, 7, 13, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label115, 8, 13, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label116, 9,13, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label117, 10,13, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label121, 4, 14, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label122, 5, 14, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label123, 6, 14, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label124, 7, 14, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label125, 8, 14, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label126, 9,14, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label127, 10,14, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label131, 4, 15, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label132, 5, 15, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label133, 6, 15, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label134, 7, 15, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label135, 8, 15, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label136, 9,15, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label137, 10,15, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label141, 4, 16,1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label142, 5, 16, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label143, 6, 16, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label144, 7, 16, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label145, 8, 16, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label146, 9,16, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label147, 10,16, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label151, 4, 17, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label152, 5, 17, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label153, 6, 17, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label154, 7, 17, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label155, 8, 17, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label156, 9,17, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label157, 10,17, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label161, 4, 18, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label162, 5, 18, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label163, 6, 18, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label164, 7, 18, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label165, 8, 18, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label166, 9,18, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label167, 10,18, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), label18, 11,2, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label28, 11,4, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label38, 11,5, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label48, 11,6, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label58, 11,7, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label68, 11,8, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label78, 11,9, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label88, 11,10, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label98, 11,11, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label108, 11,12, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label118, 11,13, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label128, 11,14, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label138, 11,15, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label148, 11,16, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label158, 11,17, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), structlabel->label168, 11,18, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), btnnxt, 10, 20, 2, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), btnpre, 4,20, 2, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), labelnull,1, 11, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), btn1, 2, 13, 1, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), add, 0, 0, 2, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), search, 2, 0, 2, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), edit, 4, 0, 2, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), delete, 6, 0, 2, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), btn6, 8, 0, 2, 1);
	gtk_grid_attach(GTK_GRID(win_grid->grid), close, 10, 0, 2, 1);
	gtk_widget_show_all(win_grid->window);
	return;
}


/****************************************************Intiation of main window**********************************************/
void activate(GtkApplication *app, Window_grid *win_grid){
        GtkWidget *close;	
	Window_grid *main;
	main = (Window_grid *)malloc(sizeof(Window_grid));
	if(!win_grid){
		main->window = gtk_application_window_new(app);
		gtk_container_set_border_width(GTK_CONTAINER(main->window), 10);
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
	gtk_label_set_markup(GTK_LABEL(labelhead), "<b><big>             WElCOME TO STUDENT RECORD SYSTEM.(HOSTEL)</big></b>\n");
	labelnull = gtk_label_new(" ");
	labeln21 = gtk_label_new("");
	labeln22 = gtk_label_new("");
	labeln23 = gtk_label_new("");
	labeln24= gtk_label_new("");
	labeln25 = gtk_label_new("");
	labeln26= gtk_label_new("");
	labeln27 = gtk_label_new("");
	labeln31 = gtk_label_new("");
	labeln32 = gtk_label_new("");
	labeln33 = gtk_label_new("");
	labeln34= gtk_label_new("");
	labeln35 = gtk_label_new("");
	labeln36= gtk_label_new("");
	labeln37 = gtk_label_new("");
	labeln41 = gtk_label_new("");
	labeln42 = gtk_label_new("");
	labeln43 = gtk_label_new("");
	labeln44= gtk_label_new("");
	labeln45 = gtk_label_new("");
	labeln46= gtk_label_new("");
	labeln47 = gtk_label_new("");
	add = gtk_button_new_with_label("Add Student Details");
	search = gtk_button_new_with_label("Search student Details");
	edit = gtk_button_new_with_label("Edit student Details");
	delete = gtk_button_new_with_label("Delete student Details");
	btn6 = gtk_button_new_with_label("View student Details");
	close = gtk_button_new_with_label("Close Application");
							            /*Signals(event) generated when components are responed by end user*/
	g_signal_connect(add, "clicked", G_CALLBACK(addstudent_details), main);
	g_signal_connect(search, "clicked", G_CALLBACK(search_student_details), main);
	g_signal_connect(edit, "clicked", G_CALLBACK(editstudent_details), main);
	g_signal_connect(delete, "clicked", G_CALLBACK(deletestudent_details), main);
	g_signal_connect(btn6, "clicked", G_CALLBACK(view_student), main);
	g_signal_connect(close, "clicked", G_CALLBACK(close_window), main->window);
	
	                                                                          /*adding components to frame*/
	gtk_grid_attach(GTK_GRID(main->grid), labeln31, 2, 4, 1, 1);
	gtk_grid_attach(GTK_GRID(main->grid), labeln32, 1, 5, 1, 1);
	gtk_grid_attach(GTK_GRID(main->grid), labeln33, 1, 6, 1, 1);
	gtk_grid_attach(GTK_GRID(main->grid), labeln34, 1, 7, 1, 1);
	gtk_grid_attach(GTK_GRID(main->grid), labeln35, 1, 8, 1, 1);
	gtk_grid_attach(GTK_GRID(main->grid), labeln36, 1, 9, 1, 1);
	gtk_grid_attach(GTK_GRID(main->grid), labeln37, 1, 10, 1, 1);
	gtk_grid_attach(GTK_GRID(main->grid), labeln41, 1, 11, 1, 1);
	gtk_grid_attach(GTK_GRID(main->grid), labeln42, 1, 14, 1, 1);
	gtk_grid_attach(GTK_GRID(main->grid), labeln43, 1, 15, 1, 1);
	gtk_grid_attach(GTK_GRID(main->grid), labeln44, 1, 18, 1, 1);
	gtk_grid_attach(GTK_GRID(main->grid), labeln45, 1, 19, 1, 1);
	gtk_grid_attach(GTK_GRID(main->grid), labeln46, 1, 20, 1, 1);
	gtk_grid_attach(GTK_GRID(main->grid), labeln47, 1, 21, 1, 1);
	gtk_grid_attach(GTK_GRID(main->grid), labeln21, 1, 22, 1, 1);
	gtk_grid_attach(GTK_GRID(main->grid), labeln22, 1, 23, 1, 1);
	gtk_grid_attach(GTK_GRID(main->grid), labeln23, 1, 24, 1, 1);
	gtk_grid_attach(GTK_GRID(main->grid), labeln24, 1, 25, 1, 1);
	gtk_grid_attach(GTK_GRID(main->grid), labeln25, 1, 26, 1, 1);
	gtk_grid_attach(GTK_GRID(main->grid), labeln26, 1, 27, 1, 1);
	gtk_grid_attach(GTK_GRID(main->grid), labeln27, 1, 28, 1, 1);
	gtk_grid_attach(GTK_GRID(main->grid), labelhead,2, 16, 6, 2);
	gtk_grid_attach(GTK_GRID(main->grid), labelnull,1, 1, 1, 1);
	gtk_grid_attach(GTK_GRID(main->grid), add, 0, 0, 2, 1);
	gtk_grid_attach(GTK_GRID(main->grid), search, 2, 0, 2, 1);
	gtk_grid_attach(GTK_GRID(main->grid), edit, 4, 0, 2, 1);
	gtk_grid_attach(GTK_GRID(main->grid), delete, 6, 0, 2, 1);
	gtk_grid_attach(GTK_GRID(main->grid), btn6, 8, 0, 2, 1);
	gtk_grid_attach(GTK_GRID(main->grid), close, 10, 0, 2, 1);	
	gtk_widget_show_all(main->window);
	
}
