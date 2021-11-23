/**
 * @file translate.h
 * @author Ugur CORUH
 * @date 23 November 2021
 *
 * @brief <b> Functions for Translate Program </b>
 *
 * HW3 Translate Functions Header
 *
 * @see http://bilgisayar.mmf.erdogan.edu.tr/en/
 *
 * @see https://learnprogramo.com/50-interesting-programming-c-projects-download-with-source-code/#6_Departmental_Store_Management
 */

#pragma once

#include <stdio.h>
#include <stdbool.h> 

 /*this are definition to keep code clean*/
#define ENGLISH_L "en"
#define TURKISH_L "tr"

/*file names*/
#define EN_LANG_FILE "en.dat"
#define TR_LANG_FILE "tr.dat"
#define LANG_CONF_FILE "lang.conf"

/*application language definitions.*/
#define APP_LANG_EN 0
#define APP_LANG_TR 1

/*This will keep our global selected langauge information*/
int app_language = APP_LANG_EN;

/*This set our language config from lang.conf file.
"en" or "tr" for setTranslateLang function*/
char* langConfig[2 + 1] = { '\0' };

/**
*	  @name getId
*
*	  @brief Get Identity
*
*	  Gets ID(number) of message from line
*
*	  @param  [in] line [\b char*]  Translation line
*
*	  @retval [\b int] Index of translation line's id
**/
int getId(char* line);

/**
*	  @name getIdString
*
*	  @brief Get String of ID
*
*	  Gets ID String(text) of message from line
*
*	  @param  [in] line [\b char*]  Translation line's text
*
*	  @retval [\b int] Text of translation line
**/
char* getIdString(char* line);

/**
*	  @name fixFile
*
*	  @brief Fix the File
*
*	  Fix file if it is null. Fix lang.conf file for empty or corrupted issues
*
*	  @param  [in] fptr [\b FILE*] File pointer for getting file
*
*	  @param  [in] close [\b bool] For closing file
**/
void fixFile(FILE* fptr, bool close);

/**
*	  @name setTranslateLang
*
*	  @brief Set Translation Language
*
*	  set translation language "en" or "tr"
*     and keep this setting in lang.conf file with save parameter
*	  if boll save is true then it stores this configuration in the file
*
*	  @param  [in] str [\b char*] File pointer for getting file
*
*	  @param  [in] save [\b bool] For closing file
**/
void setTranslateLang(char* str, bool save);

/**
*	  @name getTranslateLang
*
*	  @brief Get Translate Language
*
*	  read the current language from conf.file if its not exist creates with default "en" value.
*	  if its corrupted or empty then fixes with default "en" value.
*
*	  @param  [in] lang [\b char*]  "tr" or "en" will copied inside it
**/
void getTranslateLang(char* lang);

/**
*	  @name printTranslateLang
*
*	  @brief Print Translated Text
*
*	  read translation files "en.dat" or "tr.dat" find id related
*	  message and print to screen with current language configuration.
*
*	  @param  [in] id [\b int]  Translated text id
**/
void printTranslateLang(int id);