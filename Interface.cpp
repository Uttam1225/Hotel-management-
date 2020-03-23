#include "Interface.h"
#include <ctype.h>
#include <iomanip>
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <graphics.h>
#include <GuestDetails.h>
#include <Check_Out.h>

using namespace std;

void delayc(unsigned int ms)
{
    clock_t goal=ms+clock();
    while(goal>clock());
}

int Interface::UserInterface()
{
    GuestDetails gd;
    char ch;
    static int z=0;
    if(z==0)
    {
        Look();
        z++;
        delayc(100);
        cout<<"\n\n\n\n\n\n";
        cout<<setw(90)<<"Note: 1) Please read instructions carefully!!!\n\n"<<endl;
        cout<<setw(106)<<"2) Don't share your password with unknowns!!!\n\n\n\n\n\n\n\n\n\n\n\n\n"<<endl;
        system("pause");
    }
    system("cls");
    cout<<"\n\n\n\n\n\n\n\n";
    cout<<setw(70)<<"Already a customer of our hotel before (y/n): ";
    cin>>ch;
    if(ch=='y'||ch=='Y')
    {
        system("cls");
        fflush(stdin);
        char name[30],c[30];
        int i=0;
        cout<<"\n\n\n\n\n\n\n";
        cout<<setw(65)<<"Login Search"<<endl;
        cout<<"\n";
        cout<<setw(60)<<"Enter Username: ";
        gets(name);
        cout<<"\n";
        cout<<setw(60)<<"Enter Password: ";
        while(4)
        {
            c[i]=getch();
            if(c[i]==13)
            {
                c[i]='\0';
                break;
            }
            else
            {
                cout<<"*";
                i++;
            }
        }

        Check_Out co;
        co.CheckingPassword(name,c);
    }

    else if(ch=='n'||ch=='N')
    {
        system("cls");
        gd.Login();
    }
    else
    {
        system("cls");
        cout<<"\n\n\n\n\n\n\n";
        cout<<setw(69)<<"Please choose between a character 'Y' or 'N'"<<endl;
        cout<<"\n\n\n\n\n\n\n\n\n\n";
        system("pause");
        system("cls");
        UserInterface();
    }
    return 0;
}

void Interface::Look()
{
        //system("cls");
        cout<<"\n\n\n";
        cout<<setw(44)<<"W";
        delayc(200);
        cout<<"e";
        delayc(200);
        cout<<"l";
        delayc(200);
        cout<<"c";
        delayc(200);
        cout<<"o";
        delayc(200);
        cout<<"m";
        delayc(200);
        cout<<"e";
        delayc(200);
        delayc(50);

        cout<<"  t";
        delayc(200);
        cout<<"o";
        delayc(200);
        delayc(50);

        cout<<"  H";
        delayc(200);
        cout<<"o";
        delayc(200);
        cout<<"t";
        delayc(200);
        cout<<"e";
        delayc(200);
        cout<<"l";
        delayc(200);
        delayc(50);

        cout<<"  P";
        delayc(200);
        cout<<"r";
        delayc(200);
        cout<<"@";
        delayc(200);
        cout<<"t";
        delayc(200);
        cout<<"t";
        delayc(200);
        cout<<"u"<<endl;
        delayc(200);
        delayc(50);
        cout<<setw(43);
        for(int u=0;u<28;u++)
        {
            cout<<"~";
            delayc(50);
        }
        cout<<setw(45)<<endl;
        for(int v=0;v<5;v++)
        {
            cout<<"*";
            cout<<"     ";
            delayc(100);
        }
}


void Interface::Starting(char username[])
{
    cout<<"\n\n";
    cout<<setw(31)<<"A";
    delayc(70);

    cout<<"  V";
    delayc(70);
    cout<<"e";
    delayc(70);
    cout<<"r";
    delayc(70);
    cout<<"y";
    delayc(70);

    cout<<"  W";
    delayc(70);
    cout<<"a";
    delayc(70);
    cout<<"r";
    delayc(70);
    cout<<"m";
    delayc(70);

    cout<<"  G";
    delayc(70);
    cout<<"o";
    delayc(70);
    cout<<"o";
    delayc(70);
    cout<<"d";
    delayc(70);

    cout<<"m";
    delayc(70);
    cout<<"o";
    delayc(70);
    cout<<"r";
    delayc(70);
    cout<<"n";
    delayc(70);
    cout<<"i";
    delayc(70);
    cout<<"n";
    delayc(70);
    cout<<"g";
    delayc(70);
    cout<<"  M";
    delayc(70);
    cout<<"r";
    delayc(70);
    cout<<".";
    delayc(70);
    cout<<"/";
    delayc(70);
    cout<<"M";
    delayc(70);
    cout<<"r";
    delayc(70);
    cout<<"s";
    delayc(70);
    cout<<".";
    delayc(70);

    cout<<"  ";
    puts(username);
    delayc(500);
}
