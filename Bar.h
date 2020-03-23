#ifndef BAR_H
#define BAR_H
#include <Bill.h>
#include <GuestDetails.h>

int main();
void Reception();

class Bar:public Bill , GuestDetails
{
    public:
        int sumbar=0;
int sumbar1=0;

        void InterfaceBar();      //interface of the function bar
        void HardDrinks();       //function for hard drinks
        void SoftDrinks();       //function for hard drinks
};

#endif // BAR_H
