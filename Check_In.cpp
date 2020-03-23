#include "Check_In.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <time.h>
#include <ctype.h>

using namespace std;

void Reception();

int a,b=0,c,d=0,e,f=0;
int amount4=0,n1=0;   /* Global Variables   */
int amount5=0,n2=0;
int amount6=0,n3=0;
int TotalCharge=0;

int Check_In::Time()
{
        time_t now = time(0);
    tm *ltm = localtime(&now);//detecting present time and date from current system.

    cout<<"\n\n\nDate of Check-In: "<<  ltm->tm_mday<<"/"<< 1 + ltm->tm_mon<<"/"<< 1900 + ltm->tm_year<<endl;
    cout<<"\nTime of Check-In: "<<ltm->tm_hour << ":";
    cout<<ltm->tm_min << ":";
    cout<<ltm->tm_sec <<"\n"<< endl;
    return 0;

}

void delay(unsigned int ms)//this is a delay function.
{
    clock_t goal=ms+clock();
    while(goal>clock());
}

