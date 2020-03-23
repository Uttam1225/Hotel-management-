#include "Check_Out.h"
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <conio.h>
#include <fstream>
#include <Interface.h>
#include <GuestDetails.h>
#include <CheckIn.h>
#include <graphics.h>

using namespace std;

Interface i;// creating object of Interface class.
GuestDetails gd;// creating object of GuestDetails class.
CheckIn ci;

 /* Global variables   */
struct node // declaration of global structure for creating a linked list, having 4 blocks as follows:
{
    char name[30];  //name field
    char password[30];  //password field
    ifstream file;  //creating a block of file type. This block is for reading data from the file.
    node* next;  //for linking to next node.
};

node* head=nullptr; //global node type pointers named head and setting value as NULL.
node* temp1=nullptr;//global node type pointers named temp1 and setting value as NULL.
node* ptr; //global node type pointers named ptr declaration.


void delayd(unsigned int ms)//this is a delay function.
{
    clock_t goal=ms+clock();/*I don't know (idk) what this line is doing. I just have knowledge that somehow
                              this function is working as delay.  */
    while(goal>clock());
}

int Check_Out::LinkedList(char username[],char c[])/*function to create LinkedList having parameters from guestDetails function
                                                      named Password. */
{
    ptr=new node;
    strcpy(ptr->name,username);
    strcpy(ptr->password,c);
    ptr->file.open(username);

    if(head==nullptr)
    {
        ptr->next=head;
        head=ptr;
        temp1=ptr;
    }
    else
    {
        ptr->next=nullptr;
        temp1->next=ptr;
        temp1=ptr;
    }
    return 0;
}

int Check_Out::CheckingPassword(char username[],char password[])/* checking for UserName and password is already present
                                                                   in LinkedList*/
{
    int c=0;
    ptr=head;
    cout<<"\n\n\n";
    cout<<setw(60)<<"Loading";

    for(int x=0;x<3;x++)
    {
        delayd(500);
        cout<<".";
        cout<<" ";
    }
    delayd(500);

    while(ptr!=nullptr)                 /*  called from Interface class function UserInterface */
                                        /*  or we can say if user inputs that he/she is already an
                                            user before of this hotel then this function will be in action */
    {
        if(strcmp(username,ptr->name)==0 && strcmp(password,ptr->password)==0)
        {
            c++;
            system("cls");
            i.Starting(username);
            return 0;
        }
        ptr=ptr->next;
    }

    if(c==0)  //if UserName and password does not matched.
    {
        cout<<"\n\n\n"<<setw(85)<<"Username and Password did not matched!!!\n"<<endl;
        cout<<setw(81)<<"Search is not successful!!!\n\n\n\n\n\n\n\n"<<endl;
        system("pause");
        system("cls");
        i.UserInterface(); //Calling function of Interface class
    }

    return 0;
}

/*For the first time there will be no Linked list hence not checking for
the first time weather the UserName is already present or not. */

/* This function is for checking weather UserName is already id taken
taken or not */

int Check_Out::CheckingUsername(char username[])  /* Checking for UserName is already present
                                                     in LinkedList */
{
    if(ptr)//checking weather linked list is created or not.
    {
        node* temp=head;
        int c=0;
        while(temp!=nullptr)
        {
            if(strcmp(username,temp->name)==0)
            {
                c++;
            }
            temp=temp->next;
        }
        if(c>0)
        {
            cout<<"\n\n"<<setw(70)<<"Username already taken!!!"<<endl;
            cout<<"\n"<<setw(70)<<"Try again!!!\n\n\n"<<endl;
            system("pause");
            system("cls");
            return c;               //If name is already taken then return value of c to Login  function again.
        }
        else
        {
            gd.Password(username);//if UserName is unique then calling password of GuestDetails class
        }
    }
    else
    {
        gd.Password(username);
    }
    return 0;        /*This function is called from GuestDetails class function name Login. */
}

void Check_Out::Display()
{
        fflush(stdin);
        char name[30],c[30];
        int i=0;
        cout<<"\n\n\n\n\n\n\n";
        cout<<setw(65)<<"Search"<<endl;
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
        }                           /* This function is to get UserName and password as input from user.  */
        cout<<"\n\n\n";
        cout<<setw(66)<<"Loading";
        for(int x=0;x<3;x++)
        {
            delayd(500);
            cout<<".";
            cout<<" ";
        }
        Search(c,name); /*Calling search function */
}

int Check_Out::DeleteFromLinkedList(char username[])
{
        int c9=0;
        ptr=head;

        while(ptr!=nullptr)
        {

            if(strcmp(username,ptr->name)==0)
            {
                if(c9==0)
                {
                    head=ptr->next;
                    delete ptr;
                    break;
                }

                else
                {
                    temp1=head;
                    for(int i=0;i<c9-1;i++)
                    {
                        temp1=temp1->next;
                    }
                    temp1->next=ptr->next;
                    delete ptr;
                    while(temp1->next!=nullptr)
                    {
                        temp1=temp1->next;
                    }
                    break;
                }
            }
            c9++;
            ptr=ptr->next;
        }

        return 0;
}

void Check_Out::Search(char p[],char nameuser[])
{
    /*typedef _Ios_Seekdir seekdir;

    /// Request a seek relative to the beginning of the stream.
    static const seekdir beg =		_S_beg;

    /// Request a seek relative to the current position within the sequence.
    static const seekdir cur =		_S_cur;

    /// Request a seek relative to the current end of the sequence.
    static const seekdir end =		_S_end;*/

    string line;                     /* This function is for searching UserName and password in the linked list for  */
    char ch;
    int c=0;

    ptr=head;
    while(ptr!=nullptr)    //Remember that this function is searching and showing the same file in the field.
    {
        if((strcmp(p,ptr->password)==0) && (strcmp(nameuser,ptr->name)==0))
        {
            c++;
            system("cls");
            cout<<"\n\n";
            cout<<setw(50)<<"Search is successfully done!!!\n\n"<<endl;

            if(ptr->file.is_open())
            {
                //fseek(,cur,beg);
                //rewind(ptr->file);
                while(getline(ptr->file,line))
                {
                    cout<<line<<"\n";
                }
            }
        }
        ptr=ptr->next;
    }

    if(c==0) // if UserName and password does not matched.
    {
        cout<<"\n\n\n"<<setw(85)<<"Username and Password did not matched!!!\n"<<endl;
        cout<<setw(78)<<"Search is not successful!!!\n\n\n\n\n\n\n\n\n"<<endl;
        system("pause");
        system("cls");
        Display();
    }

    cout<<"\n\n\n"<<setw(76)<<"Do you wanna search again (y/n): ";
    cin>>ch;

    if(ch=='y'||ch=='Y')
    {
        system("cls");
        Display();      //Calling the function present just above this function.
    }

    else if(ch=='n'|| ch=='N')
    {
        system("cls");
        char ch1;                    //called from checkOut class function named search
        cout<<"\n\n\n\n\n\n\n"<<setw(75)<<"This is me Mr. Computer"<<endl;
        cout<<"\n"<<setw(80)<<"Should I delete details of this guest (y/n): ";
        cin>>ch1;

        if(ch1=='y'||ch1=='Y')
        {
           ci.Remove();
           DeleteFromLinkedList(nameuser);
           system("cls");
            cout<<"\n\n\n";
            cout<<setw(66)<<"Loading";
            for(int x=0;x<3;x++)
            {
                delayd(500);
                cout<<".";
                cout<<" ";
            }
            delayd(500);
            cout<<"\n\n"<<setw(68)<<"Deleted Successfully!!!"<<endl;
            cout<<"\n\n\n\n\n\n\n\n\n\n";
            system("pause");
            system("cls");
            main();
        }

        else if(ch1=='n'||ch1=='N')
        {
            system("cls");
            cout<<"\n\n\n\n\n\n\n"<<setw(80)<<"Details of the guest is not deleted yet!!!"<<endl;
            cout<<"\n\n\n\n\n\n\n\n\n\n\n";
            system("pause");
            system("cls");
            main();
        }
    }

    else
    {
        system("cls");
        cout<<"\n\n\n\n\n\n\n";
        cout<<setw(69)<<"Please choose between a character 'Y' or 'N'"<<endl;
        cout<<"\n\n\n\n\n\n\n\n\n\n";
        system("pause");
        system("cls");
        Search(p,nameuser); //If user is to smart and choose option other than 'y' or 'n' then this else will be in action.
    }

    ptr->file.close();//closing of linked list file.
}

