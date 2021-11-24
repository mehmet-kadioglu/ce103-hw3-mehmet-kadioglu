/**
 * @file departmentstore.h
 * @author Mehmet Kadioglu
 * @date 23 November 2021
 *
 * @brief <b> Functions for Department Managment Store </b>
 *
 * HW3 Department Managment Store Functions Header
 */

 /*with this run below codes just once if there are many same headers*/
#pragma once

#include<stdio.h>
#include<windows.h>
#include<stdlib.h>

/*these are holding size of character array item  code.example : x[ans]*/
#define ANS 15
#define ACS 4

/*structure declaration*/
typedef struct { char name[ANS], code[ACS]; float rate; int quantity; } rec; rec item;

/*this is global variable for coordinates movements used in gotoxy*/
COORD coord = { 0,0 };

/**
*	  @name gotoxy
*
*	  @brief Go to selected coordinate
*
*	  This function goes written coordinate
*
*	  @param  [in] x [\b int]  X coordinate
*
*	  @param  [in] line [\b int]  Y coordinate
**/
void gotoxy(int x, int y);

/*declaration of checking functions*/
/**
*	  @name c_code
*
*	  @brief Find item code
*
*	  Finding item code if its exist for helping add function
*
*	  @param  [in] y [\b char*]  item code
**/
void c_code(char y[]);

/**
*	  @name check
*
*	  @brief Check Validity of Code
*
*	  Check code for if it is exist
*
*	  @param  [in] x [\b char*]  item code
*
*	  @retval [\b int] if exist returning 0
**/
int check(char x[ANS]);

/*declaration of display functions*/
/**
*	  @name cursor
*
*	  @brief Go into functions
*
*	  Get ascii value of given character for cursor movements with _getch()
*
*	  @param  [in] no [\b char*]  d_search or d_mainmenu
**/
void cursor(int no);

/**
*	  @name dbill
*
*	  @brief Print page
*
*	  Printing for calculate bill page
**/
void dbill();

/**
*	  @name d_mainmenu
*
*	  @brief Display Main Menu
*
*	  Just creating skeleton of main menu then goes into cursor function
*	  to print main menu
**/
void d_mainmenu();

/**
*	  @name display
*
*	  @brief Display all
*
*	  Display, in all goods in Display All section
*
*	  @param  [in] item [\b char*]  item
* 
*	  @param  [in] i [\b char*]  cursor movement y index
* 
*	  @param  [in] j [\b char*]  sequence line index
**/
void display(rec* item, int i, int j);

/**
*	  @name window
*
*	  @brief create window
*
*	  Creating windows for sections. first two decide left or right others up or down
**/
void window(int, int, int, int);

/**
*	  @name dis_con
*
*	  @brief
*
*	  Gets ID(number) of message from line
**/
void dis_con();

/**
*	  @name d_search
*
*	  @brief Display
*
*	  Create template for search section
**/
void d_search();

/**
*	  @name highlight
*
*	  @brief Highlight Text 
*
*	  Highlight text when moving cursor. This function responsible for printings
*
*	  @param  [in] no [\b int] go into d_search or d_mainmenu
* 
*	  @param  [in] count [\b int] index to choose which option will be cursored
**/
void highlight(int no, int count);

/*declaration of main menu functions*/
/**
*	  @name bill
*
*	  @brief Get and print bill
*
*	  Getting bill and printing some text
**/
void bill();

/**
*	  @name edit
*
*	  @brief
*
*	  Gets ID(number) of message from line
**/
void edit();

/**
*	  @name add
*
*	  @brief Add item
*
*	  Adding item and printing some text
**/
void add();

/**
*	  @name del
*
*	  @brief delete records
*
*	  Delete records in delete section
**/
void del();

/*declaration of display submenu functions*/
/**
*	  @name d_code
*
*	  @brief Display by code
*
*	  Display by code for Search section
**/
void d_code();

/**
*	  @name d_rate
*
*	  @brief Display by rate
*
*	  Display by rate for Search section
**/
void d_rate();

/**
*	  @name d_quan
*
*	  @brief Display by quantity
*
*	  Display by quantity for Search section
**/
void d_quan();

/**
*	  @name d_all
*
*	  @brief Display all 
*
*	  Display all records for display all section
**/
void d_all();