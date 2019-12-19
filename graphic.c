#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<windows.h>
#include<time.h>
COORD coord={0,0};
void gotoxy(int x,int y)
{
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
void delay(int number_of_seconds)
{

    int milli_seconds = 20* number_of_seconds;

        clock_t start_time = clock();

    while (clock() < start_time + milli_seconds)
        ;
}

void drawbox(int x1, int y1, int x2, int y2, int d)
{
    gotoxy(x1,y1);
    printf("+");
    delay(d);
    gotoxy(x2,y2);
    printf("+");
    delay(d);
    for(int i=1;i<x2-x1;i++)
    {   gotoxy(x1+i,y1);
        printf("-");
        printf("\a");
        delay(d);
        gotoxy(x2-i,y2);
        printf("-");
        delay(d);
    }
    gotoxy(x1,y2);
    printf("+");
    gotoxy(x2,y1);
    printf("+");
    for(int j=1;j<y2-y1;j++)
        {
            gotoxy(x2,y1+j);
            printf("|");
            delay(d);
            gotoxy(x1,y2-j);
            printf("|");
            delay(d);
        }
}
void credits()
{
    gotoxy(50,6);
    printf("PRESENTED TO YOU BY:-");
    delay(100);
    gotoxy(54,8);

    printf("* SANKALP SINGH BISHT 18103147");
    delay(100);
    gotoxy(54,9);

    printf("* PUNIT JAIN 18103142");
    delay(100);
    gotoxy(54,10);

    printf("* KSHITIJ AGGARWAL 18103134");
    delay(100);
    gotoxy(54,11);

    printf("* AVINASH JHA 18103126");
    delay(100);
    system("color 0C");
    delay(30);
    system("color 0A");
    delay(30);

}

int main()
{
	drawbox(1,1,195,50,1);
	credits();
	delay(50);
	system("CLS");

}
