#include "Restaurant.h"
#include <iostream>
#include <iomanip>
#include <conio.h>
#include <stdlib.h>

void Reception();
using namespace std;

int c1=0;
int cn=0;

int main();

void Restaurant::Interface()
{
   // system("cls");
    int ch;
    cout<<"\t\t\t\t\t   RESTAURANT"<<endl;
    cout<<"\t\t\t\t\t~~~~~~~~~~~~~~~~"<<endl;
    cout<<"\n1. Food court"<<endl;
    cout<<"\n2. Snack lite"<<endl;
    cout<<"\n3. Bill"<<endl;
    cout<<"\n4. Back"<<endl;
    cout<<"\nEnter your choice: ";
    cin>>ch;

    switch(ch)
    {

        case 1:
                cout<<"\n\n";
                cout<<"    ~~~~~~~~~~~~~~~~~WELCOME~~~~~~~~~~~~~~~~"<<endl;
                display_items();  //function of same class to display items.
                break;

        case 2:
                cout<<"\n\n";
                cout<<"    ~~~~~~~~~~~~~~~~~WELCOME~~~~~~~~~~~~~~~~"<<endl;
                extras();   //function of same class to display snack items.
                break;

        case 3:
                RestaurantMoney(sum,sum1); /*This is for billing function, called from bill class with parameters (sum,sum1) = (total money from
                                                food court and snack lite */
                cout<<"\n\n\n\n\n\n\n";
                system("pause");
                system("cls");
                Interface();
                break;

        case 4:
                RestaurantMoneyFile(sum,sum1);  //writing data into the file function called from GuestDetails class
                system("cls");
                cout<<"\n\n\n\n\n\n";
                cout<<setw(60)<<"Thanks for your visit!!!\n"<<endl;
                cout<<setw(83)<<"Hope you like our services...\n\n\n\n\n\n\n\n\n\n\n\n\n\n"<<endl;
                system("pause");
                system("cls");
                Reception();
                break;

        default:
                system("cls");
                cout<<"\n\n\n\n\n\n\n";
                cout<<setw(70)<<"Invalid option!!!"<<endl;
                cout<<"\n\n\n\n\n\n\n\n\n\n\n";
                system("pause");
                Interface();  //calling the function of same class if default input by user.
                break;
    }

}

void Restaurant::display_items()//function for food court.
{
    system("cls");
    char choice;
    int o;
    unsigned long long int n;//such big range because may be user can give 19 digit number order.
    char ch;

    cout<<"\n    ITEM LIST    \t\t\tPRICE"<<endl;

    cout<<"\n1. Indian veg-Thali \t\t\t $20"<<endl;
    cout<<"\n2. Non-veg Thali    \t\t\t $45"<<endl;
    cout<<"\n3. South Indian     \t\t\t $30"<<endl;
    cout<<"\n4. Fast food combo  \t\t\t $35"<<endl;
    cout<<"\n5. Sea food combo   \t\t\t $20"<<endl;
    cout<<"\n6. Biryani(veg)     \t\t\t $15"<<endl;
    cout<<"\n7. Biryani(non-veg) \t\t\t $25"<<endl;
    cout<<"\n8. Curry(fish)      \t\t\t $30"<<endl;
    cout<<"\n9. Other veg curry   \t\t\t $35"<<endl;
    cout<<"\n10. Popular-street-food  \t\t $20"<<endl;
    cout<<"\n11. Speciality of hotel\t\t\t $50"<<endl;
    cout<<"\n12. food on-demand    \t\t\t $80"<<endl;
    cout<<"\n13. Back"<<endl;
    cout<<"\nWant to order something(y/n): ";
    cin>>choice;

    if(choice=='y'||choice=='Y')
    {
        cout<<"\nGrab an option from the list: ";
        cin>>o;

        if(o==13)
        {
            Interface(); //if choice is for back.
        }

    else if(o>12||o<=0)
    {
            system("cls");
            cout<<"\n\n\n\n\n\n\n";
            cout<<setw(70)<<"Invalid option!!!"<<endl;
            cout<<"\n\n\n\n\n\n\n\n\n\n\n";
            system("pause");
            display_items();// if any default is present.
    }

    else
    {
        cout<<"\nHow many orders, sir/ma'm?  ";
        cin>>n;

        switch(o)
        {
            case 1:
                    cn=n*20;
                    cout<<"\nThe charges are: "<<cn;
                    break;
            case 2:
                    cn=n*45;
                    cout<<"\nThe charges are: "<<cn;
                    break;
            case 3:
                    cn=n*30;
                    cout<<"\nThe charges are: "<<cn;
                    break;
            case 4:
                    cn=n*35;
                    cout<<"\nThe charges are: "<<cn;
                    break;
            case 5:
                    cn=n*20;
                    cout<<"\nThe charges are: "<<cn;
                    break;
            case 6:
                    cn=n*15;
                    cout<<"\nThe charges are: "<<cn;
                    break;
            case 7:
                    cn=n*25;
                    cout<<"\nThe charges are: "<<cn;
                    break;
            case 8:
                    cn=n*30;
                    cout<<"\nThe charges are: "<<cn;
                    break;
            case 9:
                    cn=n*35;
                    cout<<"\nThe charges are: "<<cn;
                    break;
            case 10:
                    cn=n*20;
                    cout<<"\nThe charges are: "<<cn;
                    break;
            case 11:
                    cn=n*50;
                    cout<<"\nThe charges are: "<<cn;
                    break;
            case 12:
                    cn=n*80;
                    cout<<"\nThe charges are: "<<cn;
                    break;
        }

        sum+=cn; //calculating total of charges.
        cout<<"\n\nDo you want to order anything else? (y/n): ";
        cin>>ch;

        if(ch=='y'||ch=='Y')
        {
            display_items();//for more orders calling the same function.
        }

        else
        {
            system("cls");
            cout<<"\n\n\n\n";
            cout<<setw(50)<<"Your orders placed!!!"<<endl;
            cout<<"\n\t\t  Please wait and enjoy until we serve you!!!\n\n\n\n"<<endl;
            system("pause");
            system("cls");
            Interface();//if no then serving the plates and going back to the interface of Restaurant.
        }
    }
  }
}

void Restaurant::extras()
{
    system("cls");
    int e,n;
    char ch,ch1;
    cout<<"\n    ITEM LIST     \t\t\tPRICE"<<endl;
    cout<<"\n1. Ice-creams          \t\t\t$10"<<endl;
    cout<<"\n2. Puddings                  \t\t$8"<<endl;
    cout<<"\n3. Cold coffee               \t\t$8"<<endl;
    cout<<"\n4. Hot coffee                \t\t$7"<<endl;
    cout<<"\n5. Tea(green/black)          \t\t$8"<<endl;
    cout<<"\n6. Hot chocolate             \t\t$7"<<endl;
    cout<<"\n7. Mix veg-soup              \t\t$7"<<endl;
    cout<<"\n8. Back"<<endl;
    cout<<"\nWant to order something (y/n): ";
    cin>>ch1;
    if(ch1=='y'||ch1=='Y')
    {
        cout<<"\nGrab an option from the list: ";
        cin>>e;

        if(e==8)
        {
            Interface();
        }

        else if(e>7||e<=0)
        {
                system("cls");
                cout<<"\n\n\n\n\n\n\n";
                cout<<setw(70)<<"Invalid option!!!"<<endl;
                cout<<"\n\n\n\n\n\n\n\n\n\n\n";
                system("pause");
                extras();
        }

        else
        {
            cout<<"\nHow many orders,sir/ma'm?  ";
            cin>>n;

            switch(e)
            {
                case 1:
                    c1=n*10;
                    cout<<"\nThe charges are: "<<c1;
                    break;
                case 2:
                    c1=n*8;
                    cout<<"\nThe charges are: "<<c1;
                    break;
                case 3:
                    c1=n*8;
                    cout<<"\nThe charges are: "<<c1;
                    break;
                case 4:
                    c1=n*7;
                    cout<<"\nThe charges are: "<<c1;
                    break;
                case 5:
                    c1=n*8;
                    cout<<"\nThe charges are: "<<c1;
                    break;
                case 6:
                    c1=n*7;
                    cout<<"\nThe charges are: "<<c1;
                    break;
                case 7:
                    c1=n*7;
                    cout<<"\nThe charges are: "<<c1;
                    break;
            }

            sum1+=c1;
            cout<<"\n\nDo you want to order anything else? (y/n): ";
            cin>>ch;

            if(ch=='y'||ch=='Y')
            {
                extras();
            }

            else
            {
                system("cls");
                cout<<"\n\n\n\n";
                cout<<setw(50)<<"Your orders placed!!!"<<endl;
                cout<<"\n\t\t  Please wait and enjoy until we serve you!!!\n\n\n\n"<<endl;
                system("pause");
                system("cls");
                Interface();
            }
        }
    }
}
