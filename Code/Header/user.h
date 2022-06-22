#ifndef USER_H
#define USER_H
#include <iostream>
#include <string.h>
using namespace std;
class owner;
class user
{
    public:
        user();
        void get_details();
        void edit_detail();
        friend void trip(owner*,user*);
        void bill();
        void show();
        friend void payment(owner*,user*);
        int get_password(string);
        int remaning_payment;

    private:
        string name;
        string email_id;
        string password;
        string phone_number;
        string car_name;
        int customer_id;
        int trip_id;
        int car_number;
        string start_date;
        string end_date;
        int trip_days;

        int total_payment;
        int advance_payment;
        int total_days;
};

#endif // USER_H
