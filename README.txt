/********************************************************************************
* Student Record System(Hostel)                                         *
*                                                                               *
* Copyright (C) 2016 Onkar Rajendra Patil                                  	*                                                      
* License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html> *
* This is free software: you are free to change and redistribute it.            *
* There is NO WARRANTY, to the extent permitted by law.                         *
*                                                                               *
*********************************************************************************/

PROJECT NAME: STUDENT RECORD SYSTEM (HOSTEL)
NAME : ONKAR RAJENDRA PATIL
MIS : 141603010

README FOR STUDENT RECORD SYSTEM (HOSTEL)
====================================

Features : 
===========
	
	Provides User Friendly Graphical User Interface to end Users with the help of GTK3.0. So it will be more easy to End Users to deal with data store in files in an efficient way.

Solutions : 
===========

	A very common and simple solution used is FILE HANDLING and dividing problems in to similar parts i.e files. Using files to store data row wise and using tab as delimiter to seperate columns. Accessing data row wise as a whole record and performing appropriate operations like delete, edit or search. 


Different files : (srs - Student Record System )
=================

"headerfile.h", "srs.c", "srsmain.c".

File "headerfile.h"   -- containd typedef of record , prototypes of methods, global variables like fp, ft, rec.

File "srs.c"	      -- contains implementation of prototype of header file. 

File "srsmain.c"      -- contains main() which intializes gtk window for the first.


Problems Solved :
================

		 Not permit to edit Existing MIS no. but permit to edit details regarding it.
		
		 Implementation of Quick search, Quick delete, Quick edit mode.

		 Not permit to add Existing Mis no. again in the system. 

