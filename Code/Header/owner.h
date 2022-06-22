#ifndef OWNER_H
#define OWNER_H
#include <bits/stdc++.h>
using namespace std;

class user;
class owner
{
    public:
        owner();
        void car_information();
        void edir_car();
        void new_car();
        void remove_car();
        friend void current_trip(owner,user);
        friend void past_trip(owner,user);

        int check_password(string);
        vector<int> price;
        vector<string> name;
    private:



        string pw="pass";


};

#endif // OWNER_H
