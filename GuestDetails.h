#ifndef GUESTDETAILS_H
#define GUESTDETAILS_H
#include <Check_Out.h>
#include <Interface.h>

class GuestDetails : public Check_Out , Interface
{
    public:
        int Login();  //function for login or sign in
        int Password(char[]);//function for accepting Password and having parameters of UserName
        int CheckInMoneyFile(int,int,int,int,int,int,int);//function to write details of CheckIn class Details of guest
        int BarMoneyFile(int,int);    //function to write details of Bar class Details of guest
        void PasswordFile(char[],char[]);//function to write UserName and password int the file
        int RestaurantMoneyFile(int,int);//function to write details of Restaurant class Details of guest
        int DetailsOfGuestFile();//function to write details of guest in the file.
};

#endif // GUESTDETAILS_H
