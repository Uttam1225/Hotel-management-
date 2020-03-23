#ifndef CHECK_IN_H
#define CHECK_IN_H
#include <Bill.h>
#include <iostream>
#include <GuestDetails.h>

using namespace std;

int main();

class Check_In:public Bill , GuestDetails
{
private:
    int rooms[3][5]={101,102,103,104,105,201,202,203,204,205,301,302,303,304,305};//2-d array for room numbers
    int amount;
    char choice2;
    unsigned long long int n,i,sum,choice1;
    int charge1=1000,charge2=2000,charge3=4000;
    string roomname1="Single Bed",roomname2="Double Bed",roomname3="Deluxe Bed";

public:
    int SingleBed();
    int DoubleBed();
    int DeluxeBed();
    int RoomChoice();
    int Time();


};

#endif // CHECK_IN_H
