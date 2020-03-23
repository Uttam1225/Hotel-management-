#include "Bill.h"
#include <iostream>
#include <iomanip>
#include <ctype.h>

using namespace std;

void delaya(unsigned int ms)//delay function
{
    clock_t goal=ms+clock();
    while(goal>clock());
}

int Bill::BarMoney(int sumbar,int sumbar1)  /* money from bar where (sumbar = total money from HardDrinks)
                                            and (sumbar1 = total money from SoftDrinks) */
{
        system("cls");
        cout<<"\n\n\n\n\n\n\n\n";
        cout<<setw(60)<<"Loading";
        for(int x=0;x<3;x++)
        {
            delaya(1000);
            cout<<".";
            cout<<" ";
        }
        delaya(1000);
        int sumbar2=0;
        system("cls");
        if(sumbar1>0||sumbar>0)
             sumbar2=sumbar1+sumbar;//calculating total of both HardDrinks and SoftDrinks.
        cout<<"\n\n";
        cout<<setw(21)<<"\t     BILL"<<endl;
        cout<<setw(21)<<"\t    ~~~~~~\n"<<endl;
        cout<<"\t   Shops"<<setw(21)<<"Total"<<endl;
        cout<<"\n\t Hard drinks"<<setw(14)<<"$"<<sumbar1<<endl;
        cout<<"\n\t Soft drinks"<<setw(14)<<"$"<<sumbar<<endl;
        cout<<"\n\n"<<"\t Sub-Total: "<<setw(14)<<"$"<<sumbar2<<endl;

        return 0;
}

int Bill::RestaurantMoney(int sum,int sum1) /* money from bar where (sum = total money from Food court)
                                            and (sum1 = total money from SnackLite) */
{
        system("cls");
        cout<<"\n\n\n\n\n\n\n\n";
        cout<<setw(60)<<"Loading";
        for(int x=0;x<3;x++)
        {
            delaya(1000);
            cout<<".";
            cout<<" ";
        }
        delaya(1000);
        system("cls");
        int sum3=0;
        if(sum>0||sum1>0)
            sum3=sum+sum1;
        cout<<"\n\n";
        cout<<setw(21)<<"\t     BILL"<<endl;
        cout<<setw(21)<<"\t    ~~~~~~\n"<<endl;
        cout<<"\t   Shops"<<setw(19)<<"Total"<<endl;
        cout<<"\n\t Food Court"<<setw(14)<<"$"<<sum<<endl;
        cout<<"\n\t Snack Lite"<<setw(14)<<"$"<<sum1<<endl;
        cout<<"\n\n"<<"\t Sub-Total: "<<setw(13)<<"$"<<sum3<<endl;

        return 0;
}

int Bill::CheckInMoney(int amount4,int amount5,int amount6,int n1,int n2,int n3,int TotalCharge)   /*Money from Check-in amount4=toatl money
                                                                    from single bed and so on...and n1=total number of rooms and so on...
                                                                    TotalCharge = Total from single,double,deluxe beds. */
{
        system("cls");
        cout<<"\n\n\n\n\n\n\n\n";
        cout<<setw(60)<<"Loading";
        for(int x=0;x<3;x++)
        {
            delaya(1000);
            cout<<".";
            cout<<" ";
        }
        delaya(1000);
        system("cls");
        int charge1=1000,charge2=2000,charge3=4000;
        cout<<"\n\n";
        cout<<setw(42)<<"BILL\n\n\n"<<endl;
        cout<<"   Rooms"<<setw(17)<<"Charge"<<setw(20)<<"No. of rooms"<<setw(13)<<"Total"<<endl;
        cout<<"\nSingle Bed"<<setw(10)<<"$"<<charge1<<setw(15)<<n1<<setw(16)<<"$"<<amount4<<endl;
        cout<<"\nDouble Bed"<<setw(10)<<"$"<<charge2<<setw(15)<<n2<<setw(16)<<"$"<<amount5<<endl;
        cout<<"\nDeluxe Bed"<<setw(10)<<"$"<<charge3<<setw(15)<<n3<<setw(16)<<"$"<<amount6<<endl;
        cout<<"\n\n"<<setw(46)<<"Sub-Total: "<<setw(9)<<"$"<<TotalCharge<<endl;

        return 0;
}
