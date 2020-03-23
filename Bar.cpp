#include <iostream>
#include <iomanip>
#include <conio.h>
#include <stdlib.h>
#include "Bar.h"

using namespace std;

int main();

int cbar=0;
int cbar1=0;

void Bar::InterfaceBar()  //same comments as in restaurant class.
{
    system("cls");
    int ch;
    cout<<"\t\t\t\t\t\t       BAR"<<endl;
    cout<<"\t\t\t\t\t\t      ~~~~~"<<endl;
    cout<<"\n1. Hard drinks"<<endl;
    cout<<"\n2. Soft drinks"<<endl;
    cout<<"\n3. Bill"<<endl;
    cout<<"\n4. Back"<<endl;
    cout<<"\nEnter your choice: ";
    fflush(stdin);
    cin>>ch;

    switch(ch)
    {

        case 1:
                cout<<"\n\n";
                cout<<"    ~~~~~~~~~~~~~~~~~WELCOME~~~~~~~~~~~~~~~~"<<endl;
                HardDrinks();
                break;

        case 2:
                cout<<"\n\n";
                cout<<"    ~~~~~~~~~~~~~~~~~WELCOME~~~~~~~~~~~~~~~~"<<endl;
                SoftDrinks();
                break;

        case 3:
                BarMoney(sumbar,sumbar1);
                cout<<"\n\n\n\n\n\n\n";
                system("pause");
                InterfaceBar();
                break;

        case 4:
                BarMoneyFile(sumbar,sumbar1);
                system("cls");
                cout<<"\n\n\n\n\n\n\n";
                cout<<setw(60)<<"Thanks for your visit!!!\n"<<endl;
                cout<<setw(83)<<"Hope you like our services...\n\n\n\n\n\n\n\n\n\n\n\n\n\n"<<endl;
                system("pause");
                system("cls");
                Reception();
                break;

        default:
                system("cls");
                cout<<"\n\n\n\n\t\t\t\t\tOOPs...Invalid Choice!!!\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"<<endl;
                system("pause");
                InterfaceBar();
    }

}

void Bar::HardDrinks()
{
    system("cls");
    int o;
    unsigned long long int n;
    char ch;

    cout<<"\n     DRINKS    \t\t\tPRICE"<<endl;

    cout<<"\n1. Royal Stag    \t\t\t $20"<<endl;
    cout<<"\n2. Bacardi         \t\t\t $45"<<endl;
    cout<<"\n3. Brandy           \t\t\t $30"<<endl;
    cout<<"\n4. Whiskey           \t\t\t $35"<<endl;
    cout<<"\n5. Scotch           \t\t\t $20"<<endl;
    cout<<"\n6. Vodka shots       \t\t\t $15"<<endl;
    cout<<"\n7. Rum              \t\t\t $25"<<endl;
    cout<<"\n8. Tequila shots     \t\t\t $30"<<endl;
    cout<<"\n9. Cognac             \t\t\t $35"<<endl;
    cout<<"\n10. Gin                \t\t\t $20"<<endl;
    cout<<"\n11. Back"<<endl;

    cout<<"\nSelect options from the list: ";
    cin>>o;

    if(o==11)
    {
        InterfaceBar();
    }

    else if(o>10||o<=0)
    {
        system("cls");
        cout<<"\n\n\n\n\t\t\t\t\tOOPs...Invalid Choice!!!\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"<<endl;
        system("pause");
        HardDrinks();
    }

    else
    {
        cout<<"\nHow many orders, sir/ma'm?  ";
        cin>>n;

        switch(o)
        {
            case 1:
                    cbar1=n*20;
                    cout<<"\nThe charges are: $"<<cbar1;
                    break;
            case 2:
                    cbar1=n*45;
                    cout<<"\nThe charges are: $"<<cbar1;
                    break;
            case 3:
                    cbar1=n*30;
                    cout<<"\nThe charges are: $"<<cbar1;
                    break;
            case 4:
                    cbar1=n*35;
                    cout<<"\nThe charges are: $"<<cbar1;
                    break;
            case 5:
                    cbar1=n*20;
                    cout<<"\nThe charges are: $"<<cbar1;
                    break;
            case 6:
                    cbar1=n*15;
                    cout<<"\nThe charges are: $"<<cbar1;
                    break;
            case 7:
                    cbar1=n*25;
                    cout<<"\nThe charges are: $"<<cbar1;
                    break;
            case 8:
                    cbar1=n*30;
                    cout<<"\nThe charges are: $"<<cbar1;
                    break;
            case 9:
                    cbar1=n*35;
                    cout<<"\nThe charges are: $"<<cbar1;
                    break;
            case 10:
                    cbar1=n*20;
                    cout<<"\nThe charges are: $"<<cbar1;
                    break;
        }

        sumbar1+=cbar1;
        cout<<"\n\nDo you want to order anything else? (y/n): ";
        cin>>ch;

        if(ch=='y'||ch=='Y')
        {
            HardDrinks();
        }

        else
        {
            system("cls");
            cout<<"\n\n\n\n";
            cout<<setw(50)<<"\t\t  Here is your Drinks!!!"<<endl;
            cout<<"\n\t\t\t\t\t\tPlease enjoy...\n\n\n\n"<<endl;
            system("pause");
            system("cls");
            InterfaceBar();
        }
    }

}

void Bar::SoftDrinks()
{
    system("cls");
    int e,n;
    char ch;
    cout<<"\n   DRINKS     \t\t\tPRICE"<<endl;
    cout<<"\n1. Tuborg          \t\t\t$10"<<endl;
    cout<<"\n2. Kingfisher  \t\t\t\t$8"<<endl;
    cout<<"\n3. Heineken               \t\t$8"<<endl;
    cout<<"\n4. Cocktail                \t\t$7"<<endl;
    cout<<"\n5. Mocktail          \t\t\t$8"<<endl;
    cout<<"\n6. Coca-cola            \t\t$7"<<endl;
    cout<<"\n7. Mountain              \t\t$7"<<endl;
    cout<<"\n8. Back"<<endl;

        cout<<"\nSelect options from the list: ";
        cin>>e;

        if(e==8)
        {
            InterfaceBar();
        }

        else if(e>7||e<=0)
        {
            system("cls");
            cout<<"\n\n\n\n\t\t\t\t\tOOPs...Invalid Choice!!!\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"<<endl;
            system("pause");
            SoftDrinks();
        }

        else
        {
            cout<<"\nHow many orders,sir/ma'm?  ";
            cin>>n;

            switch(e)
            {
                case 1:
                    cbar=n*10;
                    cout<<"\nThe charges are: $"<<cbar;
                    break;
                case 2:
                    cbar=n*8;
                    cout<<"\nThe charges are: $"<<cbar;
                    break;
                case 3:
                    cbar=n*8;
                    cout<<"\nThe charges are: $"<<cbar;
                    break;
                case 4:
                    cbar=n*7;
                    cout<<"\nThe charges are: $"<<cbar;
                    break;
                case 5:
                    cbar=n*8;
                    cout<<"\nThe charges are: $"<<cbar;
                    break;
                case 6:
                    cbar=n*7;
                    cout<<"\nThe charges are: $"<<cbar;
                    break;
                case 7:
                    cbar=n*7;
                    cout<<"\nThe charges are: $"<<cbar;
                    break;
            }

            sumbar+=cbar;
            cout<<"\n\nDo you want to order anything else? (y/n): ";
            cin>>ch;

            if(ch=='y'||ch=='Y')
            {
                SoftDrinks();
            }

            else
            {
                system("cls");
                cout<<"\n\n\n\n";
                cout<<setw(50)<<"\t\t  Here is your Drinks!!!"<<endl;
                cout<<"\n\t\t\t\t\t\tPlease enjoy...\n\n\n\n"<<endl;
                system("pause");
                system("cls");
                InterfaceBar();
            }
        }
}


