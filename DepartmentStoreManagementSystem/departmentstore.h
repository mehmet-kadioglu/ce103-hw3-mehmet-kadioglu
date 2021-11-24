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
*	  @brief
*
*	  Gets ID(number) of message from line
*
*	  @param  [in]  [\b char*]  Translation line
**/
void c_code(char[]);

/**
*	  @name check
*
*	  @brief Get Identity
*
*	  Gets ID(number) of message from line
*
*	  @param  [in] line [\b char*]  Translation line
*
*	  @retval [\b int] Index of translation line's id
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
*	  @brief
*
*	  Gets ID(number) of message from line
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
*	  @brief
*
*	  Gets ID(number) of message from line
*
*	  @param  [in] line [\b char*]  Translation line
**/
void display(rec*, int, int);

/**
*	  @name window
*
*	  @brief
*
*	  Gets ID(number) of message from line
*
*	  @param  [in] line [\b char*]  Translation line
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
*	  @brief
*
*	  Getting and printing find a
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
*	  @brief
*
*	  Gets ID(number) of message from line
**/
void add();

/**
*	  @name del
*
*	  @brief
*
*	  Gets ID(number) of message from line
**/
void del();

/*declaration of display submenu functions*/
/**
*	  @name d_code
*
*	  @brief
*
*	  Gets ID(number) of message from line
**/
void d_code();

/**
*	  @name d_rate
*
*	  @brief
*
*	  Gets ID(number) of message from line
**/
void d_rate();

/**
*	  @name d_quan
*
*	  @brief
*
*	  Gets ID(number) of message from line
**/
void d_quan();

/**
*	  @name d_all
*
*	  @brief
*
*	  Gets ID(number) of message from line
**/
void d_all();