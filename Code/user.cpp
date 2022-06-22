#include "user.h"
#include <iostream>
#include <bits/stdc++.h>

#include "owner.h"
using namespace std;
static int user_no=0;  //for customer id
static int trip_no=0;  //for trip id
user::user()
{
    remaning_payment=0;
    advance_payment=0;
    total_payment=0;
}
void user::get_details()
{
    cout<<"\t\tEnter your name : ";
    cin>>name;
    cout<<"\t\tEnter your ID password : ";
    cin>>password;
    cout<<"\t\tEnter your phone number : ";
    cin>>phone_number;
    cout<<"\t\tEnter your email id : ";
    cin>>email_id;
    customer_id=user_no+1;
}
void user::edit_detail()
{
    cout<<"\t\t1. ID password"<<endl;
    cout<<"\t\t2. phone number"<<endl;
    cout<<"\t\t3. email id"<<endl;
    cout<<"\t\t4. exit"<<endl;
    int x;
    string a;
    do
    {
        cout<<"\t\tEnter a choice : ";
        cin>>x;
        switch(x)
        {
        case 1:
            cout<<"\t\tEnter a old password : ";
            cin>>a;
            if(a==password)
            {
                cout<<"\t\tEnter a new password : ";
                cin>>password;
            }
            else
            {
                cout<<"\t\tyour old password is wrong contact the owner of the systeam."<<endl;
            }
            break;
        case 2:
            cout<<"\t\tEnter a new phone number : ";
            cin>>phone_number;
            break;
        case 3:
            cout<<"\t\tEnter a new mail id : ";
            cin>>email_id;
            break;
        }
    }while(x!=4);
}
void trip(owner *a,user *b)
{

    if(b->remaning_payment==0)
    {
        cout<<"\t\tHere are the car of our shop."<<endl;
    cout<<"\n";
    a->car_information();
    cout<<"\n";
    cout<<"\t\tEnter a car number : ";
    cin>>b->car_number;
    int x=b->car_number-1;
    b->car_name=a->name[x];

    cout<<"\t\tEnter a start date of your trip (dd/mm/yyyy): ";
    cin>>b->start_date;
    cout<<"\t\tEnter a end date of your trip (dd/mm/yyyy): ";
    cin>>b->end_date;
    cout<<"\t\tEnter a total days of your trip : ";
    cin>>b->total_days;

    b->total_payment=b->total_days*a->price[x];

    a->price[x]=0;
    b->trip_id=trip_no+1;

    cout<<"\t\tYour trip is confirmed."<<endl;
    cout<<"\n\n";
    b->bill();
    }
    else
    {
        cout<<"\t\tclear your previous payment."<<endl;
    }

}
void user::bill()
{
    char x;

    cout<<"\t\tName :                "<<name<<endl;
    cout<<"\t\tContact Number:       "<<phone_number<<endl;
    cout<<"\t\tEmail ID :            "<<email_id<<endl;
    cout<<"\t\tCustomer ID :         "<<customer_id<<endl;
    cout<<"\t\tTrip ID :             "<<trip_id<<endl;
    cout<<"\t\tTrip start date :     "<<start_date<<endl;
    cout<<"\t\tTrip end date :       "<<end_date<<endl;
    cout<<"\t\tTotal trip days :     "<<total_days<<endl;
    cout<<"\t\tyour car :            "<<car_name<<endl;
    cout<<"\t\tTotal Payment :       "<<total_payment<<endl;
    cout<<"\n";
    cout<<"\t\tDo want to pay any advance payment (Y/N): ";
    cin>>x;
    if(x=='Y'||x=='y')
    {
        cout<<"\t\tEnter your advance payment : ";
        cin>>advance_payment;
    }
    remaning_payment=total_payment-advance_payment;
    cout<<endl;
    cout<<"\t\tAdvance Payment :    "<<advance_payment<<endl;
    cout<<"\t\tRemaining Payment :  "<<remaning_payment<<endl;
    cout<<"\t\tTotal Payment :      "<<total_payment<<endl;
    cout<<"\n";
}
void user::show()
{
    cout<<"\t\tName :            "<<name<<endl;
    cout<<"\t\tContact Number:   "<<phone_number<<endl;
    cout<<"\t\tEmail ID :        "<<email_id<<endl;
    cout<<"\t\tCustomer ID :     "<<customer_id<<endl;
    cout<<"\t\tTrip ID :         "<<trip_id<<endl;
    cout<<"\t\tTrip start date : "<<start_date<<endl;
    cout<<"\t\tTrip end date :   "<<end_date<<endl;

    cout<<"\t\tyour car :        "<<car_name<<endl;

}
int user::get_password(string z)
{
    if(password==z)
        return 1;
    else
        return 0;
}
void payment(owner* a,user* b)
{
    cout<<"\t\tName :                      "<<b->name<<endl;
    cout<<"\t\tContact Number:             "<<b->phone_number<<endl;
    cout<<"\t\tEmail ID :                  "<<b->email_id<<endl;
    cout<<"\t\tCustomer ID :               "<<b->customer_id<<endl;
    cout<<"\t\tTrip ID :                   "<<b->trip_id<<endl;
    cout<<"\t\tTrip start date :           "<<b->start_date<<endl;
    cout<<"\t\tTrip end date :             "<<b->end_date<<endl;
    cout<<"\t\tTotal trip days :           "<<b->total_days<<endl;
    cout<<"\t\tTotal Payment :             "<<b->total_payment<<endl;
    cout<<"\t\tyour remaining payment :    "<<b->remaning_payment<<endl;
    cout<<"\t\tclear your remaning payment"<<endl;
    cout<<"\n";
    cout<<"\t\tThank you "<<endl;
    cout<<"\n";
    a->price[b->car_number-1]=b->total_payment/b->total_days;
    b->total_days=0;
    b->total_payment=0;
    b->advance_payment=0;
    b->remaning_payment=0;
}
