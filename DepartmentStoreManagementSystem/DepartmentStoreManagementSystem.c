#define _CRT_SECURE_NO_WARNINGS

//LEARNPROGRAMO-PROGRAMMING MADE SIMPLE
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<windows.h>
#include<stdarg.h>
#include<stdbool.h> 
#include"translate.h"
#include"message.h"
#include"departmentstore.h"

/*start of main*/
int main()
{
    //get current language setting from lang.conf file its "en" or "tr"
    getTranslateLang(langConfig);

    //set application language setting but setting is not set to file
    setTranslateLang(langConfig, false);
    d_mainmenu();
    return 0;
}

void d_mainmenu()
{
    system("cls");  // this is calling system function. cls(clear terminal)
    window(25, 51, 20, 32);
    gotoxy(33, 18);
    printTranslateLang(translation10);
    /*previous switch case printing login screen but unnecesarry
    because cursor and highlight functions also doing this
    for this reason it deleted*/
    cursor(8);
}

void d_search()
{
    // just draw shape then go into cursor(4) for printing text
    system("cls");
    window(25, 50, 20, 32);
    gotoxy(33, 18);
    printTranslateLang(translation11);
    cursor(4);
}

/*function for cursor movement*/
void cursor(int no)
{
    int count = 1;
    char ch = '0';
    gotoxy(30, 23);
    // loop forever if there is no exit 
    while (1)
    {
        switch (ch)
        {
        case 80:
            count++;
            if (count == no + 1) count = 1;
            break;
        case 72:
            count--;
            if (count == 0) count = no;
            break;
        }
        highlight(no, count);
        ch = _getch();
        // if pressed enter go into this
        if (ch == '\r')
        {
            if (no == 8)
            {
                if (count == 1) bill();
                else if (count == 2) add();
                else if (count == 3) edit();
                else if (count == 4) d_all();
                else if (count == 5) d_search();
                else if (count == 6) del();
                else if (count == 7) pickLanguage();
                else exit(0);
            }
            if (no == 4)
            {
                if (count == 1) d_code();
                else if (count == 2)d_rate();
                else if (count == 3) d_quan();
                else d_mainmenu();
            }
        }
    }
}

void highlight(int no, int count)
{
    // no == 4 codes for highlighting and printing d_search page
    if (no == 4)
    {
        gotoxy(30, 23);
        printTranslateLang(translation12);
        gotoxy(30, 24);
        printTranslateLang(translation13);
        gotoxy(30, 25);
        printTranslateLang(translation14);
        gotoxy(30, 26);
        printTranslateLang(translation15);
        switch (count)
        {
        case 1:
            gotoxy(30, 23);
            printTranslateLang(translation16);
            break;
        case 2:
            gotoxy(30, 24);
            printTranslateLang(translation17);
            break;
        case 3:
            gotoxy(30, 25);
            printTranslateLang(translation18);
            break;
        case 4:
            gotoxy(30, 26);
            printTranslateLang(translation19);
            break;
        }
    }

    // no == 8 codes for highlighting and printing main page
    if (no == 8)
    {
        gotoxy(30, 23);
        printTranslateLang(translation20);
        gotoxy(30, 24);
        printTranslateLang(translation21);
        gotoxy(30, 25);
        printTranslateLang(translation22);
        gotoxy(30, 26);
        printTranslateLang(translation23);
        gotoxy(30, 27);
        printTranslateLang(translation24);
        gotoxy(30, 28);
        printTranslateLang(translation25);
        gotoxy(30, 29);
        printTranslateLang(translation80);
        gotoxy(30, 30);
        printTranslateLang(translation26);
        switch (count)
        {
        case 1:
            gotoxy(30, 23);
            printTranslateLang(translation27);
            break;
        case 2:
            gotoxy(30, 24);
            printTranslateLang(translation28);
            break;
        case 3:
            gotoxy(30, 25);
            printTranslateLang(translation29);
            break;
        case 4:
            gotoxy(30, 26);
            printTranslateLang(translation30);
            break;
        case 5:
            gotoxy(30, 27);
            printTranslateLang(translation31);
            break;
        case 6:
            gotoxy(30, 28);
            printTranslateLang(translation32);
            break;
        case 7:
            gotoxy(30, 29);
            printTranslateLang(translation81);
            break;
        case 8:
            gotoxy(30, 30);
            printTranslateLang(translation33);
            break;
        }
    }
}

void bill()
{
    char x[4] = { 0 };
    int j = 29, q = 0, size = 0, i = 1;
    float total = 0, gtotal = 0;
    FILE* file;
    file = fopen("record.txt", "r+b");
    rewind(file);
    system("cls");
    dbill();
    gotoxy(26, 15);
    printTranslateLang(translation34);
    while (1)
    {
        gotoxy(25, 18);
        printf("                    ");
        gotoxy(25, 19);
        printf("                    ");
        gotoxy(25, 18);
        printTranslateLang(translation35);
        scanf("%s", x);
        if (strcmp(x, "end") == 0)
            break;
        gotoxy(25, 19);
        printTranslateLang(translation36);
        scanf("%d", &q);
        rewind(file);
        while (fread(&item, sizeof(item), 1, file))
        {
            if ((strcmp(item.code, x) == 0))
            {
                total = item.rate * q;
                gotoxy(11, j);
                printf("%4d", i);
                printf("%9s", item.name);
                printf("%13d", q);
                printf("%15.2f", item.rate);
                printf("%13.2f", total);
                gtotal = gtotal + total;
                size = sizeof(item);
                item.quantity = item.quantity - q;
                j += 2;
                i++;
                fseek(file, -size, SEEK_CUR);
                fwrite(&item, sizeof(item), 1, file);
                break;
            }
        }
    }
    if (gtotal != 0)
    {
        gotoxy(30, j + 5);
        printTranslateLang(translation74);
        printf(" = NRs. %6.2f", gtotal);
    }
    fclose(file);
    _getch();
    d_mainmenu();
}
/*function to display bill window*/
void dbill()
{
    int i;
    gotoxy(20, 10);
    //;
    for (i = 1; i <= 10; i++)
        printf("*");
    printTranslateLang(translation37);
    for (i = 1; i <= 10; i++)
        printf("*");
    printf("\n\n");
    gotoxy(30, 11);
    printTranslateLang(translation38);
    //textcolor(1);
    gotoxy(32, 25);
    printTranslateLang(translation39);
    //textcolor(8);
    gotoxy(13, 27);
    printTranslateLang(translation40);

}
/*function to add records*/
void add()
{
    FILE* file;
    char y[ACS], x[12];
    system("cls");
    //textbackground(11);
    //textcolor(0);
    gotoxy(25, 25);
    printTranslateLang(translation41);
    while (toupper(_getche()) == 'Y') // click y or e to proceed
    {
        system("cls");
        file = fopen("record.txt", "ab");
        c_code(y);
        strcpy(item.code, y);
        gotoxy(22, 28);
        printTranslateLang(translation42);
        scanf("%f", &item.rate);
        gotoxy(22, 30);
        printTranslateLang(translation43);
        scanf("%d", &item.quantity);
        gotoxy(22, 32);
        printTranslateLang(translation44);
        scanf("%s", item.name);
        fseek(file, 0, SEEK_END);
        fwrite(&item, sizeof(item), 1, file);
        fclose(file);
        gotoxy(22, 34);
        printTranslateLang(translation41);

    }
    d_mainmenu();
}

/*function to check availability of code*/
void c_code(char y[])
{
    int flag;
    FILE* file;
    file = fopen("record.txt", "rb");
    while (1)
    {
        system("cls");
        window(20, 58, 23, 36);
        gotoxy(32, 18);
        printTranslateLang(translation45);
        flag = 1;
        rewind(file);
        gotoxy(22, 25);
        printTranslateLang(translation46);
        scanf(" %[^\n]", y);
        while (fread(&item, sizeof(item), 1, file) == 1)
        {
            if (strcmp(y, item.code) == 0)
            {
                flag = 0;
                gotoxy(26, 30);
                printTranslateLang(translation47);
                gotoxy(29, 32);
                printTranslateLang(translation48);
                _getch();
                break;
            }
        }
        if (flag == 1)
            break;
    }
}

/*function for editing*/
void edit()
{
    int flag = 0, choice;
    char x[ACS], y[ACS];
    FILE* file = NULL;
    int size;
    system("cls");
    //textcolor(0);
    //textbackground(11);
    window(20, 63, 20, 46);
    gotoxy(35, 18);
    printTranslateLang(translation49);
    gotoxy(25, 23);
    printTranslateLang(translation50);
    scanf("%s", x);
    flag = check(x);
    if (flag == 0)
    {
        file = fopen("record.txt", "r+b");
        rewind(file);
        while (fread(&item, sizeof(item), 1, file))
        {
            if (strcmp(item.code, x) == 0)
            {
                //textcolor(0);
                gotoxy(25, 27);
                printTranslateLang(translation75);
                printf(" %s", item.name);
                gotoxy(25, 28);
                printTranslateLang(translation76);
                printf(" %s", item.code);
                gotoxy(25, 29);
                printTranslateLang(translation77);
                printf(" %g", item.rate);
                gotoxy(25, 30);
                printTranslateLang(translation78);
                printf(" %d", item.quantity);
                gotoxy(25, 32);;
                printTranslateLang(translation51);
                fflush(file);
                if (toupper(_getche()) == 'Y')
                {
                    //textcolor(0);
                    gotoxy(25, 34);
                    printTranslateLang(translation52);
                    gotoxy(25, 35);
                    printTranslateLang(translation53);
                    gotoxy(25, 36);
                    printTranslateLang(translation54);
                    gotoxy(25, 37);
                    printTranslateLang(translation55);
                    gotoxy(25, 39); ;
                    printTranslateLang(translation56);
                    scanf("%d", &choice);
                    switch (choice)
                    {
                    case 1:
                        system("cls");
                        window(23, 48, 20, 40);
                        gotoxy(35, 18);
                        printTranslateLang(translation49);
                        gotoxy(25, 24);
                        printTranslateLang(translation57);
                        scanf("%s", item.name);
                        size = sizeof(item);
                        fseek(file, -size, SEEK_CUR);
                        fwrite(&item, sizeof(item), 1, file);
                        break;
                    case 2:
                        system("cls");
                        window(23, 65, 20, 40);
                        gotoxy(35, 18);
                        printTranslateLang(translation49);
                        gotoxy(25, 24);
                        c_code(y);
                        strcpy(item.code, y);
                        size = sizeof(item);
                        fseek(file, -size, SEEK_CUR);
                        fwrite(&item, sizeof(item), 1, file);
                        break;
                    case 3:
                        system("cls");
                        window(23, 65, 20, 40);
                        gotoxy(35, 18);
                        printTranslateLang(translation49);
                        gotoxy(25, 24);
                        printTranslateLang(translation58);
                        scanf("%f", &item.rate);
                        size = sizeof(item);
                        fseek(file, -size, SEEK_CUR);
                        fwrite(&item, sizeof(item), 1, file);
                        break;
                    case 4:
                        system("cls");
                        window(23, 65, 20, 40);
                        gotoxy(35, 18);
                        printTranslateLang(translation49);
                        gotoxy(25, 24);
                        printTranslateLang(translation59);
                        scanf("%d", &item.quantity);
                        size = sizeof(item);
                        fseek(file, -size, 1);
                        fwrite(&item, sizeof(item), 1, file);
                        break;
                    }
                    gotoxy(27, 30);
                    printTranslateLang(translation60);
                    break;
                }
            }
        }
    }
    if (flag == 1)
    {
        gotoxy(32, 30);
        printTranslateLang(translation61);
        gotoxy(36, 32);
        printTranslateLang(translation62);
    }
    _getch();
    fclose(file);
    d_mainmenu();
}

/*function to display all records*/
void d_all()
{
    int i, j = 1;
    FILE* file;
    dis_con();
    file = fopen("record.txt", "rb");
    rewind(file);
    i = 26;
    fflush(file);
    while (fread(&item, sizeof(item), 1, file))
    {
        display(&item, i, j);
        i++;
        j++;
        if ((j % 20) == 0)
        {
            gotoxy(27, 47);/*textcolor(0)*/;
            printTranslateLang(translation63);
            _getch();
            system("cls");
            dis_con();
            i = 26;
            continue;
        }
    }
    _getch();
    if (i == 26)
    {
        gotoxy(24, 30);
        printTranslateLang(translation64);
    }
    _getch();
    fclose(file);
    d_mainmenu();
}

/*function to display by quantity*/
void d_quan()
{
    int i, j = 1;
    int a, b;
    FILE* file;
    dis_con();
    file = fopen("record.txt", "rb");
    rewind(file);
    i = 26;
    gotoxy(16, 20);;
    printTranslateLang(translation65);
    scanf("%d", &a);
    gotoxy(16, 21);
    printTranslateLang(translation66);
    scanf("%d", &b);
    fflush(file);
    while (fread(&item, sizeof(item), 1, file))
    {
        if ((item.quantity >= a) && (item.quantity <= b))
        {
            display(&item, i, j);
            i++;
            j++;
            if ((j % 20) == 0)
            {
                gotoxy(27, 47);
                printTranslateLang(translation67);
                _getch();
                system("cls");
                dis_con();
                i = 26;
                continue;
            }
        }
    }
    _getch();
    if (i == 26)
    {
        gotoxy(28, 30);
        printTranslateLang(translation68);
    }
    _getch();
    d_search();
    fclose(file);
}

/*function to display by rate*/
void d_rate()
{
    int i, j = 1;
    float a, b;
    FILE* file;
    dis_con();
    file = fopen("record.txt", "rb");
    rewind(file);
    i = 26;
    gotoxy(16, 20);;
    printTranslateLang(translation65);
    scanf("%f", &a);
    gotoxy(16, 21);
    printTranslateLang(translation66);
    scanf("%f", &b);
    fflush(file);
    while (fread(&item, sizeof(item), 1, file))
    {
        if ((item.rate >= a) && (item.rate <= b))
        {
            display(&item, i, j);
            i++;
            j++;
            if ((j % 20) == 0)
            {
                gotoxy(27, 47);
                printTranslateLang(translation67);
                _getch();
                system("cls");
                dis_con();
                i = 26;
                continue;
            }
        }
    }
    _getch();
    if (i == 26)
    {
        gotoxy(28, 30);
        printTranslateLang(translation68);
    }
    _getch();
    fclose(file);
    d_search();
}

/*function to display by code*/
void d_code()
{
    int i, j = 1;
    char x[4] = { 0 };
    FILE* file;
    dis_con();
    file = fopen("record.txt", "rb");
    rewind(file);
    i = 26;
    gotoxy(16, 20);;
    printTranslateLang(translation50);
    scanf("%s", x);
    fflush(file);
    while (fread(&item, sizeof(item), 1, file))
    {
        if ((strcmp(item.code, x) == 0))
        {
            display(&item, i, j);
            i++;
            j++;
            break;
        }
    }
    if (i == 26)
    {
        gotoxy(28, 30);
        printTranslateLang(translation68);
    }
    _getch();
    fclose(file);
    d_search();
}

/*function to display window for item display*/
void dis_con()
{
    int i;
    system("cls");
    gotoxy(20, 10);
    ;
    for (i = 1; i <= 10; i++)
        printf("*");
    printTranslateLang(translation37);
    for (i = 1; i <= 10; i++)
        printf("*");
    printf("\n\n");
    gotoxy(30, 11);
    printTranslateLang(translation38);
    //textcolor(1);
    gotoxy(32, 17);
    printTranslateLang(translation69);
    //textcolor(8);
    gotoxy(18, 23);
    printTranslateLang(translation70);
}

/*function to display in screen*/
void display(rec* item, int i, int j)
{
    gotoxy(16, i);//textcolor(13);
    printf("%4d", j);
    printf("%9s", item->name);
    printf("%12s", item->code);
    printf("%14.2f", item->rate);
    printf("%11d", item->quantity);
}

/*function to delete records*/
void del()
{
    int flag;
    char x[ANS];
    FILE* file = NULL, * file1 = NULL;
    system("cls");
    //textbackground(11);
    //textcolor(0);
    window(23, 51, 25, 34);
    gotoxy(29, 18);
    printTranslateLang(translation71);
    gotoxy(27, 27);
    printTranslateLang(translation50);
    scanf("%s", x);
    flag = check(x);
    if (flag == 0)
    {
        file1 = fopen("record1.txt", "ab");
        file = fopen("record.txt", "rb");
        rewind(file);
        while (fread(&item, sizeof(item), 1, file))
        {
            if (strcmp(item.code, x) != 0)
                fwrite(&item, sizeof(item), 1, file1);
        }
        gotoxy(27, 29);
        printTranslateLang(translation72);
        remove("record.txt");
        rename("record1.txt", "record.txt");
    }
    if (flag == 1)
    {
        gotoxy(25, 29);
        printTranslateLang(translation73);
        gotoxy(30, 31);
        printTranslateLang(translation62);
    }
    fclose(file1);
    fclose(file);
    _getch();
    d_mainmenu();
}

/*function to check validity of code while editing and deleting*/
int check(char x[ANS])
{
    FILE* file;
    int flag = 1;
    file = fopen("record.txt", "rb");
    rewind(file);
    while (fread(&item, sizeof(item), 1, file))
    {
        if (strcmp(item.code, x) == 0)
        {
            flag = 0;
            break;
        }
    }
    fclose(file);
    return flag;
}

/*function to display box*/
void window(int a, int b, int c, int d)
{
    int i;
    system("cls");
    gotoxy(20, 10);
    //textcolor(1);
    for (i = 1; i <= 10; i++)
        printf("*");
    printTranslateLang(translation37);
    for (i = 1; i <= 10; i++)
        printf("*");
    printf("\n\n");
    gotoxy(30, 11);
    printTranslateLang(translation38);
    //textcolor(4);
    for (i = a; i <= b; i++)
    {
        gotoxy(i, 17);
        printf("\xcd");
        gotoxy(i, 19);
        printf("\xcd");
        gotoxy(i, c);
        printf("\xcd");
        gotoxy(i, d);
        printf("\xcd");
    }

    gotoxy(a, 17);
    printf("\xc9");
    gotoxy(a, 18);
    printf("\xba");
    gotoxy(a, 19);
    printf("\xc8");
    gotoxy(b, 17);
    printf("\xbb");
    gotoxy(b, 18);
    printf("\xba");
    gotoxy(b, 19);
    printf("\xbc");
    //textcolor(4);
    for (i = c; i <= d; i++)
    {
        gotoxy(a, i);
        printf("\xba");
        gotoxy(b, i);
        printf("\xba");
    }
    gotoxy(a, c);
    printf("\xc9");
    gotoxy(a, d);
    printf("\xc8");
    gotoxy(b, c);
    printf("\xbb");
    gotoxy(b, d);
    printf("\xbc");
}

//This function set global language configuration
void setTranslateLang(char* str, bool save)
{
    FILE* fptr;

    //check and set language variables
    if (strcmp(str, (char*)ENGLISH_L) == 0) {
        app_language = APP_LANG_EN;
    }
    else if (strcmp(str, TURKISH_L) == 0) {
        app_language = APP_LANG_TR;
    }
    else {
        app_language = APP_LANG_EN;
    }

    if (save)
    {
        //if save enabled then create file and save current language setting "en" or "tr"
        fptr = fopen(LANG_CONF_FILE, "w");
        fprintf(fptr, "%s", str);
        fclose(fptr);
    }

}

void fixFile(FILE* fptr, bool close)
{
    //if file is open this should call to close file
    if (close)
        fclose(fptr);

    //open and write default "en" string in the file for missing or corrupted files.
    fptr = fopen(LANG_CONF_FILE, "w");
    fprintf(fptr, "%s", ENGLISH_L);
    fclose(fptr);
}

void getTranslateLang(char* lang)
{
    FILE* fptr;
    char line[100] = { 0 };

    if ((fptr = fopen(LANG_CONF_FILE, "r")) == NULL) {
        //if file not exist create default file with "en" configured
        fixFile(fptr, false);
        sprintf(lang, "%s", ENGLISH_L);
    }
    else {

        if (fscanf(fptr, "%[^\n]", line) != '\0')
        {
            //read line
            fgetc(fptr);

            if (strcmp(line, "") == 0) {
                //if file exist but has empty line then fix file with default "en" configuration
                fixFile(fptr, true);
                sprintf(lang, "%s", ENGLISH_L);
            }
            else {
                //if file exist and has a configuration copy to output. We don't check "en" or "tr" entered here.
                strcpy(lang, line);
            }

        }
        else {

            //if file has no data fix file with default "en" configuration.
            fixFile(fptr, true);
            sprintf(lang, "%s", ENGLISH_L);
        }
    }

}

// This function getting which filename to proceed(en.dat or tr.dat)
// then 
void printTranslateLang(int id)
{
    char line[1000] = { 0 };
    char fileName[100] = { 0 };
    FILE* fptr;

    //get translation file name by language setting.
    if (app_language == APP_LANG_TR) {
        strcpy(fileName, TR_LANG_FILE);
    }
    else if (app_language == APP_LANG_EN) {
        strcpy(fileName, EN_LANG_FILE);
    }
    else {
        strcpy(fileName, EN_LANG_FILE);
    }

    //open translation language file if not exit then close application
    //you should create "tr.dat" and "en.dat" manually.
    if ((fptr = fopen(fileName, "r")) == NULL) {
        printf("Error! opening file please create lang file first");
        // Program exits if file pointer returns NULL.
        exit(1);
    }

    //read each line untill end of file
    while (fscanf(fptr, "%[^\n]", line) != EOF) {

        fgetc(fptr);

        //if line empty skip
        if (strcmp(line, "") == 0)
            continue;

        // reads text until newline is encountered
        //printf("Data from the file:\n [%s] \n", line);
        //printf("Line ID [%d] \n",getId(line));
        //printf("Line Message [%s] \n",getIdString(line));

        //get ID and compare with input id parameter if match then get ID string and print to screen.
        if (getId(line) == id) {
            printf("%s", getIdString(line));
            break;
        }
    }

    //close the file.
    fclose(fptr);
}

// This function gets, translated part's id described in .dat files
int getId(char* line)
{
    char* pch;
    int index;
    char idStr[50] = { 0 };
    int idInt = 0;
    //find comma to extract id
    pch = strchr(line, ',');
    //calculate commad index
    index = pch - line;
    //copy ID as string
    memcpy(idStr, line, index);
    //convert ID string to integer    
    idInt = atoi(idStr);
    //return ID 
    return idInt;
}

char* getIdString(char* line)
{
    char* str = line;
    int length = strlen(line); //calculate length of line.
    char* pch;
    int index;
    //set end character to null this was "
    *(str + length - 1) = 0;
    //find " character
    pch = strchr(str, '\"');
    //calculate index of " character
    index = pch - line;
    //move pointer to this location
    str += index;
    //skip " character
    str += 1;
    //return only ID message.
    return str;
}

int pickLanguage()
{
    // language choice from console 0=en 1=tr
    int  languageChoice = 0;
    system("cls");

    window(16, 61, 20, 32);
    gotoxy(23, 18);
    printTranslateLang(translation79);
    gotoxy(18, 24);
    printf("----> for english press \"0\".");
    gotoxy(18, 25);
    printf("----> turkce icin \"1\"e basin.");
    gotoxy(18, 27);
    printTranslateLang(translation82);
    scanf("%d", &languageChoice);

    // change language
    if (languageChoice == APP_LANG_TR)
    {
        //if TR selected then set application language to Turkish 
        setTranslateLang(TURKISH_L, true);
    }
    else {
        //other cases set language to English 
        setTranslateLang(ENGLISH_L, true);
    }

    d_mainmenu();
    return 0;
}

void gotoxy(int x, int y)
{
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}