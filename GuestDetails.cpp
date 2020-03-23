#include "GuestDetails.h"
#include <iostream>
#include <iomanip>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <graphics.h>
#include <Check_Out.h>
//#include <DeleteDetailsOfGuest.h>

using namespace std;

unsigned long long int w=0;
//DeleteDetailsOfGuest ddog;

char username[30];

int GuestDetails::Password(char username[])//called from Login function of same class.
{
    if(w>0)//hmmmm..this is for if password didn't matched then UserName wont be gone from the console. I mean it will ask for
    {      //password and not for UserName once UserName is accepted.
        cout<<setw(60)<<"Username: ";
        puts(username);
    }
    int i=0,j=0,x;
    char c[30],d[30];
    cout<<"\n";
    cout<<setw(67)<<"Create Password: ";
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
    x=strlen(c);//checking length of the password.
    if(x<5)
    {
        cout<<"\n\n"<<endl;
        w++;
        cout<<setw(81)<<"Passowrd must have at least 5 characters!!!"<<endl;
        cout<<"\n\n\n\n\n\n\n\n\n"<<endl;
        system("pause");
        system("cls");
        cout<<"\n\n\n\n\n\n\n";
        cout<<setw(66)<<"Sign-in Screen\n"<<endl;
        Password(username);
        return 0;
    }
    cout<<"\n"<<endl;
    cout<<setw(68)<<"Confirm Password: ";
    while(4)
    {
        d[j]=getch();
        if(d[j]==13)
        {
            d[j]='\0';
            break;
        }
        else
        {
            cout<<"*";
            j++;
        }
    }
    cout<<"\n\n\n"<<endl;

    if(strcmp(c,d)!=0)//comparing passwords
    {
        w++;
        cout<<setw(76)<<"Password does not matched!!!\n"<<endl;
        cout<<setw(62)<<"Try again..."<<endl;
        cout<<"\n\n\n\n\n"<<endl;
        system("pause");
        system("cls");
        cout<<"\n\n\n\n\n\n\n";
        cout<<setw(66)<<"Sign-in Screen\n"<<endl;
        Password(username);
    }
    else
    {
        PasswordFile(username,c);//writing into the file.
        LinkedList(username,c);//creating a linked list.function is in checkout class
    }
    return 0;
}

int GuestDetails::Login()
{
    int c;
    cout<<"\n\n\n\n\n\n\n";
    cout<<setw(65)<<"Sign-in Screen"<<endl;
    cout<<"\n";
    cout<<setw(60)<<"Username: ";
    fflush(stdin);
    gets(username);

    Check_Out co;
    c=co.CheckingUsername(username);//checking weather UserName is taken or not.

    if(c>0)
    {
        Login();
    }

    else
    {
        system("cls");
        cout<<"\n";
        Starting(username);//function from class Interface for design.
    }

    return 0;
}

int GuestDetails::DetailsOfGuestFile()
{
        char name[30];
        char address[100];
        char email[30];
        char ph[12];

        fstream fout;
        fout.open(username,ios::app);
        system("cls");

        time_t now = time(0);
        tm *ltm = localtime(&now);

        fout<<"\n\nDate of Check-In: "<<  ltm->tm_mday<<" "<< 1 + ltm->tm_mon<<" "<< 1900 + ltm->tm_year<<endl;
        fout<<"Time of Check-In: "<<ltm->tm_hour << ":";//writing date and time in the file
        fout<<ltm->tm_min << ":";
        fout<<ltm->tm_sec << endl;

        cout<<"\n\n\n\n\n"<<setw(60)<<"Enter your name: ";
        fflush(stdin);
        gets(name);
        fout<<"\nName: "<<name<<endl;

        cout<<"\n"<<setw(63)<<"Enter your address: ";
        gets(address);
        fout<<"Address: "<<address<<endl;

        cout<<"\n"<<setw(64)<<"Enter your email-id: ";
        gets(email);
        fout<<"Email-Id: "<<email<<endl;

        cout<<"\n"<<setw(68)<<"Enter your phone number: ";
        gets(ph);
        fout<<"Contact: "<<ph<<endl;

        fout.close();

    return 0;
}

void GuestDetails::PasswordFile(char name[] , char c1[])
{
    int n=0,m=0;

    ofstream fout;
    fout.open(username);//file name is what, user input in userName, or file name is same as userName.

    fout<<setw(40)<<"GUEST DETAILS"<<endl;

    fout<<"\n\n";
    fout<<"Username: ";
    do{
        fout<<name[n];
        n++;
    }while(name[n]!='\0');

    fout<<"\n";
    fout<<"Password: ";
    do{
        fout<<c1[m];
        m++;
    }while(c1[m]!='\0');
    fout<<"\n\n";

    fout.close();
}

int GuestDetails::CheckInMoneyFile(int amount4,int amount5,int amount6,int n1,int n2,int n3,int TotalCharge)
{
        fstream fout;
        fout.open(username,ios::app);

        fout<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;

        int charge1=1000,charge2=2000,charge3=4000;
        fout<<"\n";
        fout<<"Bill from Rooms: "<<endl;
        fout<<"\n\n";
        fout<<"   Rooms"<<setw(17)<<"Charge"<<setw(20)<<"No. of rooms"<<setw(13)<<"Total"<<endl;
        fout<<"\nSingle Bed"<<setw(10)<<"$"<<charge1<<setw(15)<<n1<<setw(16)<<"$"<<amount4<<endl;
        fout<<"\nDouble Bed"<<setw(10)<<"$"<<charge2<<setw(15)<<n2<<setw(16)<<"$"<<amount5<<endl;
        fout<<"\nDeluxe Bed"<<setw(10)<<"$"<<charge3<<setw(15)<<n3<<setw(16)<<"$"<<amount6<<endl;
        fout<<"\n\n"<<setw(46)<<"Sub-Total: "<<setw(9)<<"$"<<TotalCharge<<endl;
        fout<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;

        fout.close();
        return 0;
}

int GuestDetails::RestaurantMoneyFile(int sum,int sum1)
{
        fstream fout;
        fout.open(username,ios::app);

        int sum3=0;
        sum3=sum+sum1;
        fout<<"\n";
        fout<<"Bill from Restaurant: "<<endl;
        fout<<"\n\n";
        fout<<setw(40)<<"\t   Shops"<<setw(21)<<"Total\n"<<endl;
        fout<<setw(40)<<"\t Food Court"<<setw(14)<<"$"<<sum<<"\n"<<endl;
        fout<<setw(40)<<"\t Snack Lite"<<setw(14)<<"$"<<sum1<<"\n\n"<<endl;
        fout<<setw(40)<<"\t Sub-Total: "<<setw(13)<<"$"<<sum3<<endl;
        fout<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;

        fout.close();
        return 0;
}

int GuestDetails::BarMoneyFile(int sumbar,int sumbar1)
{
        fstream fout;
        fout.open(username,ios::app);

        int sumbar2=0;
        sumbar2=sumbar+sumbar1;
        fout<<"\n";
        fout<<"Bill from Bar: "<<endl;
        fout<<"\n\n";
        fout<<setw(40)<<"\t   Shops"<<setw(21)<<"Total\n"<<endl;
        fout<<setw(40)<<"\t Hard drinks"<<setw(13)<<"$"<<sumbar1<<"\n"<<endl;
        fout<<setw(40)<<"\t Soft drinks"<<setw(13)<<"$"<<sumbar<<"\n\n"<<endl;
        fout<<setw(40)<<"\t Sub-Total: "<<setw(13)<<"$"<<sumbar2<<endl;
        fout<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;

        fout.close();
        return 0;
}

