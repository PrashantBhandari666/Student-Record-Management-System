//***************************************************
//*        ================================         *
//*        Student Record Management System         *
//*        ================================         *
//***************************************************
//*                     Author                      *
//*                     ------                      *
//*                Prashant Bhandari                *
//***************************************************

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
void clrscr();
//function to clear console screen.
void gotoxy(short x, short y);
//This function places cursor at a desired location on screen i.e., we can change cursor position using gotoxy function.
/*
                      5
                      |   [120]Columns
              *-------|-----------------------> (X-axis)     Example:-
              | *-----|-------------------*                          gotoxy(5,5);
              | |     |                   |                          printf("hello");
          5 --|-|-----*hello              |
         [30] | |     (5,5)               |                  Syntax:-
         Rows | |                         |                          gotoxy(x,y);
              | |     [output screen]     |
              | |                         |                  where,
              | |                         |                        x=x-coordinate
              | |                         |                        y=y-coordinate
              | |                         |
              | *-------------------------*
              |
              V 
    
          (Y-axis)
*/
void box_single_line(int x, int y, int l, int w);
//This function is used to print single line box in output screen.
/*
                   [120]Columns
                       x(5)  
                        |   
              *---------|---------------------> (X-axis)       Example:-    
              | *-------|-----------------*                             box_single_line(5,5,5,5);
              | |       | l(5)            |
              | |       |<----->          |
       y(5)---|-|-------┌──────┐          |                    Syntax:- 
              | |     ^ │      │          |                             box_single_line(x,y,l,w);
              | |     | │ box  │          |          
              | | w(5)| │      │          |
    [30]      | |     | │      │          |                    where,
    Rows      | |     V └──────┘          |                          x=x-coordinate
              | |    [output screen]      |                          y=y-coordinate
              | |                         |                          l=length
              | *-------------------------*                          w=width
              |
              V
           (Y-axis)
*/
void box_double_line(int x, int y, int l, int w);
//This function is same as above function but used to print double line box in output screen.
/*
                        [120]Columns
						    
              *-------------------------------> (X-axis)       Example:-    
              | *-------------------------*                             box_double_line(5,5,5,5);
              | |                         |
              | |                         |
              | |       ╔══════╗          |                    Syntax:- 
              | |       ║      ║          |                            box_double_line(x,y,l,w);
              | |       ║ box  ║          |
              | |       ║      ║          |                    where,
    [30]      | |       ║      ║          |                         x=x-coordinate
    Rows      | |       ╚══════╝          |                         y=y-coordinate
              | |     [output screen]     |                         l=length
              | |                         |                         w=width
              | *-------------------------*
              |
              V
           (Y-axis)
*/
int login();
void print_menu();
//This function prints Main Menu.
void print_delmenu();
//This function prints Delete Menu.
void rcreate();
//This function creates records.
void rdisplay();
//This function displays records.
void rsearch();
//This function searches records.
void rmodify();
//This function modify records.
void rdelete();
//This function deletes records.
void ralldelete();
//This function deletes all records.
void logout();
int user = 0;
struct student
{
    int roll;
    char name[30];
    struct dateofbirth
    {
        int yy;
        int mm;
        int dd;
    } dob;
    char add[15];
    char phone[13];
    char gender[8];
    int class;
    char sec;
} s;
int main()
{
    int c, a;
    if (user > 0)
    {
        goto a;
    }
login:
    a = login();
    if (a == 1)
    {
        user++;
        goto a;
    }
    else
    {
        clrscr();
        box_single_line(49, 9, 22, 2);
        gotoxy(50, 10);
        printf("Incorrect Credentials");
        getch();
        goto login;
    }
a:
    print_menu();
    scanf("%d", &c);
    switch (c)
    {
    case (1):
    {
        rcreate();
        break;
    }
    case (2):
    {
        rdisplay();
        break;
    }
    case (3):
    {
        rsearch();
        break;
    }
    case (4):
    {
        rmodify();
        break;
    }
    case (5):
    {
    b:
        print_delmenu();
        scanf("%d", &c);
        switch (c)
        {
        case (1):
        {
            rdelete();
            goto b;
            break;
        }
        case (2):
        {
            ralldelete();
            goto b;
            break;
        }
        case (3):
        {
            goto a;
            break;
        }
        case (4):
        {
            exit(0);
        }
        default:
        {
            clrscr();
            box_single_line(49, 9, 15, 2);
            gotoxy(50, 10);
            printf("Invalid Option");
            getch();
            fflush(stdin);
            goto b;
        }
        }
        break;
    }
    case (6):
    {
        logout();
    }
    case (7):
    {
        exit(0);
    }
    default:
    {
        clrscr();
        box_single_line(49, 9, 15, 2);
        gotoxy(50, 10);
        printf("Invalid Option");
        getch();
        fflush(stdin);
        goto a;
    }
    }
    getch();
    return (0);
}
void clrscr()
{
    system("cls");
}
void gotoxy(short x, short y)
{
    COORD pos = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void box_single_line(int x, int y, int l, int w)
{
    int h, i, j, k;
    gotoxy(x, y);
    printf("\xDA");
    gotoxy(l + x, y);
    printf("\xBF");
    gotoxy(l + x, w + y);
    printf("\xD9");
    gotoxy(x, y + w);
    printf("\xC0");
    for (h = x + 1; h < l + x; h++)
    {
        gotoxy(h, y);
        printf("\xC4");
    }
    for (i = y + 1; i < w + y; i++)
    {
        gotoxy(l + x, i);
        printf("\xB3");
    }
    for (j = x + 1; j < l + x; j++)
    {
        gotoxy(j, y + w);
        printf("\xC4");
    }
    for (k = y + 1; k < w + y; k++)
    {
        gotoxy(x, k);
        printf("\xB3");
    }
}
void box_double_line(int x, int y, int l, int w)
{
    int h, i, j, k;
    gotoxy(x, y);
    printf("\xC9");
    gotoxy(l + x, y);
    printf("\xBB");
    gotoxy(l + x, w + y);
    printf("\xBC");
    gotoxy(x, y + w);
    printf("\xC8");
    for (h = x + 1; h < l + x; h++)
    {
        gotoxy(h, y);
        printf("\xCD");
    }
    for (i = y + 1; i < w + y; i++)
    {
        gotoxy(l + x, i);
        printf("\xBA");
    }
    for (j = x + 1; j < l + x; j++)
    {
        gotoxy(j, y + w);
        printf("\xCD");
    }
    for (k = y + 1; k < w + y; k++)
    {
        gotoxy(x, k);
        printf("\xBA");
    }
}
int login()
{
    clrscr();
    int i = 0;
    char ch;
    char password[100], username[100];
    box_single_line(53, 1, 15, 2);
    gotoxy(55, 2);
    printf("LOGIN PANEL");
    box_double_line(42, 6, 37, 2);
    gotoxy(45, 7);
    printf("STUDENT RECORD MANAGEMENT SYSTEM");
    box_double_line(30, 10, 60, 10);
    gotoxy(45, 12);
    printf("Enter Username: ");
    box_single_line(61, 11, 15, 2);
    gets(username);
    gotoxy(45, 15);
    printf("Enter Password: ");
    box_single_line(61, 14, 15, 2);
    while (1)
    {
        ch = getch();
        if (ch == 13)
        {
            password[i] = '\0';
            break;
        }
        else
        {
            password[i] = ch;
            i++;
            printf("*");
        }
    }
    if ((strcmp(username, "user") == 0) && (strcmp(password, "user123") == 0))
    {
        return (1);
    }
    else
    {
        return (0);
    }
}
void print_menu()
{
    clrscr();
    box_single_line(53, 2, 12, 2);
    gotoxy(55, 3);
    printf("MAIN MENU");
    box_double_line(20, 5, 80, 20);
    gotoxy(45, 7);
    printf("1) Create Student Record");
    gotoxy(45, 9);
    printf("2) Display All Student Records");
    gotoxy(45, 11);
    printf("3) Search Student Records");
    gotoxy(45, 13);
    printf("4) Modify Student Records");
    gotoxy(45, 15);
    printf("5) Delete Student Records");
    gotoxy(45, 17);
    printf("6) Log Out");
    gotoxy(45, 19);
    printf("7) Exit");
    gotoxy(50, 22);
    printf("Your Choice:");
}
void print_delmenu()
{
    clrscr();
    box_single_line(53, 2, 14, 2);
    gotoxy(55, 3);
    printf("DELETE MENU");
    box_double_line(20, 5, 80, 20);
    gotoxy(45, 7);
    printf("1) Delete Individual Record ");
    gotoxy(45, 9);
    printf("2) Delete All Records");
    gotoxy(45, 11);
    printf("3) Go to Main Menu");
    gotoxy(45, 13);
    printf("4) Exit");
    gotoxy(50, 22);
    printf("Your Choice:");
}
void rcreate()
{
    clrscr();
    FILE *fpt;
    char another;
    char g;
    box_single_line(53, 2, 16, 2);
    gotoxy(55, 3);
    printf("CREATE RECORD");
    fpt = fopen("record.txt", "ab+");
    if (fpt == NULL)
    {
        clrscr();
        box_single_line(49, 14, 20, 2);
        gotoxy(50, 15);
        printf("Error opening file");
        main();
    }
    fflush(stdin);
    box_double_line(20, 5, 80, 20);
    gotoxy(10, 3);
    gotoxy(42, 6);
    printf("Please enter the new details of Student \n");
    gotoxy(25, 9);
    printf("Roll Number:");
    scanf("%d", &s.roll);
    fflush(stdin);
    gotoxy(25, 10);
    printf("Name:");
    gets(s.name);
    gotoxy(25, 11);
    printf("Address:");
    gets(s.add);
    gotoxy(25, 12);
    printf("Phone No:");
    gets(s.phone);
    fflush(stdin);
    gotoxy(25, 13);
    printf("Enter Date of Birth:");
    gotoxy(25, 14);
    printf("Year:");
    scanf("%d", &s.dob.yy);
    gotoxy(35, 14);
    printf("Month:");
    scanf("%d", &s.dob.mm);
    gotoxy(44, 14);
    printf("Day:");
    scanf("%d", &s.dob.dd);
    fflush(stdin);
    gotoxy(25, 15);
    printf("Gender[M/F]:");
    g = getchar();
    if ((g == 'M') || (g == 'm'))
    {
        strcpy(s.gender, "Male");
    }
    else if ((g == 'F') || (g == 'f'))
    {
        strcpy(s.gender, "Female");
    }
    else
    {
        strcpy(s.gender, "Other");
    }
    fflush(stdin);
    gotoxy(25, 16);
    printf("Class:");
    scanf("%d", &s.class);
    gotoxy(25, 17);
    printf("Section:");
    fflush(stdin);
    s.sec = getchar();
    fwrite(&s, sizeof(s), 1, fpt);
    gotoxy(42, 22);
    printf("Do you want to add another record? (Y/N):");
    fflush(stdin);
    another = getch();
    if ((another == 'Y') || (another == 'y'))
    {
        fflush(stdin);
        fclose(fpt);
        rcreate();
    }
    fflush(stdin);
    fclose(fpt);
    gotoxy(47, 28);
    printf("Press any key to continue.");
    getch();
    main();
}
void rdisplay()
{
    clrscr();
    FILE *fpt;
    int i = 0, j;
    box_single_line(53, 1, 15, 2);
    gotoxy(55, 2);
    printf("VIEW RECORD");
    fpt = fopen("record.txt", "rb+");
    if (fpt == NULL)
    {
        clrscr();
        box_single_line(49, 14, 20, 2);
        gotoxy(50, 15);
        printf("Error opening file");
        getch();
        main();
    }
    else
    {
        gotoxy(0, 5);
        printf("   +-----+--------+-----------------------------+--------------+-----------+--------------+--------+------+--------+\n");
        printf("   |S.No |Roll No |Student Name                 |Address       |Phone No   |Date of Birth |Gender  |Class |Section |\n");
        printf("   +-----+--------+-----------------------------+--------------+-----------+--------------+--------+------+--------+\n");
    }
    j = 8;
    while (fread(&s, sizeof(s), 1, fpt) == 1)
    {

        printf("   |%-5d|%-8d|%-29s|%-14s|%-11s|%-4d/%2d/%-6d|%-8s|%-6d|%-8c|\n", i + 1, s.roll, s.name, s.add, s.phone, s.dob.yy, s.dob.mm, s.dob.dd, s.gender, s.class, s.sec);
        i++;
        j++;
    }
    printf("   +-----+--------+-----------------------------+--------------+-----------+--------------+--------+------+--------+\n");
    if (i == 0)
    {
        box_single_line(52, 14, 16, 2);
        gotoxy(53, 15);
        printf("Record is Empty");
        gotoxy(47, 28);
        printf("Press any key to continue.");
        getch();
        main();
    }
    fclose(fpt);
    gotoxy(47, j + 3);
    printf("Press any key to continue.");
    getch();
    main();
}
void rsearch()
{
    clrscr();
    FILE *fpt;
    int i = 0;
    char stname[30];
    box_single_line(53, 1, 16, 2);
    gotoxy(55, 2);
    printf("SEAECH RECORD");
    gotoxy(5, 5);
    printf("Enter name of student : ");
    fflush(stdin);
    gets(stname);
    fpt = fopen("record.txt", "rb+");
    if (fpt == NULL)
    {
        clrscr();
        box_single_line(49, 14, 20, 2);
        gotoxy(50, 15);
        printf("Error opening file");
        getch();
        main();
    }
    while (fread(&s, sizeof(s), 1, fpt) == 1)
    {
        if (strcmp(stname, s.name) == 0)
        {
            i++;
            printf("\n");
            printf("                                                      Search Result(%d)               \n", i);
            printf("                                                     ===================               \n");
            printf("                                     +----------------+------------------------------+\n");
            printf("                                     | Roll no:       | %-29d|\n", s.roll);
            printf("                                     +----------------+------------------------------+\n");
            printf("                                     | Student Name:  | %-29s|\n", s.name);
            printf("                                     +----------------+------------------------------+\n");
            printf("                                     | Address:       | %-29s|\n", s.add);
            printf("                                     +----------------+------------------------------+\n");
            printf("                                     | Phone No:      | %-29s|\n", s.phone);
            printf("                                     +----------------+------------------------------+\n");
            printf("                                     | Date of Birth: | %-4d/%-2d/%-21d|\n", s.dob.yy, s.dob.mm, s.dob.dd);
            printf("                                     +----------------+------------------------------+\n");
            printf("                                     | Gender:        | %-29s|\n", s.gender);
            printf("                                     +----------------+------------------------------+\n");
            printf("                                     | Class:         | %-29d|\n", s.class);
            printf("                                     +----------------+------------------------------+\n");
            printf("                                     | Section:       | %-29c|\n", s.sec);
            printf("                                     +----------------+------------------------------+\n");
        }
    }
    fclose(fpt);
    if (i == 0)
    {
        box_single_line(53, 9, 16, 2);
        gotoxy(54, 10);
        printf("No Record Found");
        gotoxy(47, 28);
        printf("Press any key to continue.");
        getch();
        main();
    }
    printf("                                                Press any key to continue.");
    getch();
    main();
}
void rmodify()
{
    clrscr();
    FILE *fpt;
    char stname[30];
    char g;
    int i;
    box_single_line(53, 1, 16, 2);
    gotoxy(55, 2);
    printf("MODIFY RECORD");
    gotoxy(5, 5);
    printf("Enter name of student: ");
    fflush(stdin);
    gets(stname);
    fpt = fopen("record.txt", "rb+");
    if (fpt == NULL)
    {
        clrscr();
        box_single_line(49, 14, 20, 2);
        gotoxy(50, 15);
        printf("Error opening file");
        getch();
        main();
    }
    rewind(fpt);
    fflush(stdin);
    while (fread(&s, sizeof(s), 1, fpt) == 1)
    {
        if (strcmp(stname, s.name) == 0)
        {
            i++;
            printf("\n");
            printf("                                                       Previous Data                                            \n");
            printf("                                                      ===============                                           \n");
            printf("     +--------+-----------------------------+--------------+-----------+--------------+--------+------+--------+\n");
            printf("     |Roll No |Student Name                 |Address       |Phone No   |Date of Birth |Gender  |Class |Section |\n");
            printf("     +--------+-----------------------------+--------------+-----------+--------------+--------+------+--------+\n");
            printf("     |%-8d|%-29s|%-14s|%-11s|%-4d/%-2d/%-6d|%-8s|%-6d|%-8c|\n", s.roll, s.name, s.add, s.phone, s.dob.yy, s.dob.mm, s.dob.dd, s.gender, s.class, s.sec);
            printf("     +--------+-----------------------------+--------------+-----------+--------------+--------+------+--------+\n");
            printf("                                                         New Data                                               \n");
            printf("                                                        ==========                                              \n");
            box_double_line(4, 16, 108, 11);
            gotoxy(42, 17);
            printf("Please enter the new details of student \n");
            gotoxy(6, 18);
            printf("Roll Number:");
            scanf("%d", &s.roll);
            fflush(stdin);
            gotoxy(6, 19);
            printf("Name:");
            gets(s.name);
            gotoxy(6, 20);
            printf("Address:");
            gets(s.add);
            gotoxy(6, 21);
            printf("Phone No:");
            gets(s.phone);
            fflush(stdin);
            gotoxy(6, 22);
            printf("Enter Date of Birth:");
            gotoxy(6, 23);
            printf("Year:");
            scanf("%d", &s.dob.yy);
            gotoxy(16, 23);
            printf("Month:");
            scanf("%d", &s.dob.mm);
            gotoxy(25, 23);
            printf("Day:");
            scanf("%d", &s.dob.dd);
            fflush(stdin);
            gotoxy(6, 24);
            printf("Gender[M/F]:");
            g = getchar();
            if ((g == 'M') || (g == 'm'))
            {
                strcpy(s.gender, "Male");
            }
            else if ((g == 'F') || (g == 'f'))
            {
                strcpy(s.gender, "Female");
            }
            else
            {
                strcpy(s.gender, "Other");
            }
            fflush(stdin);
            gotoxy(6, 25);
            printf("Class:");
            scanf("%d", &s.class);
            gotoxy(6, 26);
            fflush(stdin);
            printf("Section:");
            s.sec = getchar();
            fseek(fpt, -sizeof(s), SEEK_CUR);
            fwrite(&s, sizeof(s), 1, fpt);
            break;
        }
    }
    fclose(fpt);
    if (i == 0)
    {
        box_single_line(53, 9, 16, 2);
        gotoxy(54, 10);
        printf("No Record Found");
    }
    gotoxy(47, 28);
    printf("Press any key to continue.");
    getch();
    main();
}
void rdelete()
{
    clrscr();
    char stname[20];
    int i = 0;
    FILE *fpt1, *fpt2;
    gotoxy(10, 3);
    box_single_line(53, 1, 16, 2);
    gotoxy(55, 2);
    printf("DELETE RECORD");
    gotoxy(5, 5);
    printf("Enter name of student: ");
    fflush(stdin);
    gets(stname);
    fpt1 = fopen("record.txt", "rb+");
    if (fpt1 == NULL)
    {
        clrscr();
        box_single_line(49, 14, 20, 2);
        gotoxy(50, 15);
        printf("Error opening file");
        goto end;
    }
    fpt2 = fopen("temp.txt", "wb+");
    if (fpt2 == NULL)
    {
        clrscr();
        box_single_line(49, 14, 20, 2);
        gotoxy(50, 15);
        printf("Error opening file");
        goto end;
    }
    while (fread(&s, sizeof(s), 1, fpt1) == 1)
    {
        if (strcmp(stname, s.name) != 0)
        {
            fwrite(&s, sizeof(s), 1, fpt2);
        }
        else
        {
            i++;
            gotoxy(0, 10);
            printf("                                                       Deleted Data                                             \n");
            printf("                                                     ================                                           \n");
            printf("     +--------+-----------------------------+--------------+-----------+--------------+--------+------+--------+\n");
            printf("     |Roll No |Student Name                 |Address       |Phone No   |Date of Birth |Gender  |Class |Section |\n");
            printf("     +--------+-----------------------------+--------------+-----------+--------------+--------+------+--------+\n");
            printf("     |%-8d|%-29s|%-14s|%-11s|%-4d/%-2d/%-6d|%-8s|%-6d|%-8c|\n", s.roll, s.name, s.add, s.phone, s.dob.yy, s.dob.mm, s.dob.dd, s.gender, s.class, s.sec);
            printf("     +--------+-----------------------------+--------------+-----------+--------------+--------+------+--------+\n");
            printf("                                            The record is deleated sucessfully.                                 \n");
        }
    }
    fclose(fpt1);
    fclose(fpt2);
    remove("record.txt");
    rename("temp.txt", "record.txt");
    if (i == 0)
    {
        box_single_line(53, 9, 16, 2);
        gotoxy(54, 10);
        printf("No Record Found");
    }
    gotoxy(47, 28);
    printf("Press any key to continue.");
end:
    getch();
}
void ralldelete()
{
    clrscr();
    FILE *fpt;
    remove("record.txt");
    fpt = fopen("record.txt", "wb+");
    if (fpt == NULL)
    {
        clrscr();
        box_single_line(49, 14, 20, 2);
        gotoxy(50, 15);
        printf("Error opening file");
        goto end;
    }
    fclose(fpt);
    box_single_line(53, 9, 15, 2);
    gotoxy(54, 10);
    printf("Record Deleted");
    gotoxy(47, 28);
    printf("Press any key to continue.");
end:
    getch();
}
void logout()
{
    fflush(stdin);
    user--;
    main();
}