#ifndef RESTAURANT_H
#define RESTAURANT_H
#include <Bill.h>
#include <GuestDetails.h>

int main();

class Restaurant:public Bill , GuestDetails
{
 public:
     int sum=0;
     int sum1=0;
    void Interface();    //Interface for Restaurant.
    void display_items();      //displaying food items with price
    void extras();           //extra new or special dishes or puddings display list
};

#endif // RESTAURANT_H
