#include <iostream>
#include <bits/stdc++.h>
#include "user.h"
#include "owner.h"
using namespace std;

int main()
{
    owner o;
    vector<user> u;
    cout<<"\n\n\n\n";
    cout<<"\t\t-------------------------------------"<<endl;
    cout << "\t\tWelcome to car rental shop" << endl;
    cout<<"\t\t-------------------------------------"<<endl;
    int choice1,choice2;
    user tmp;
    string pwd;
    //for password
    vector<user> lu;
    //lu, who complete their trip
    do
    {

        cout<<"\n\n";
        cout<<"\t\t1. owner"<<endl;
        cout<<"\t\t2. customer"<<endl;
        cout<<"\t\t3. exit"<<endl;
        cout<<"\n";
        cout<<"\t\tenter a number : ";
        cin>>choice1;

        switch(choice1)
        {
        case 1:
            cout<<"\n\n";
                cout<<"\t\tenter a password : ";
                cin>>pwd;
                system("cls");
                cout<<"\n\n\n\n";
                if(o.check_password(pwd))
                {
                    do
            {
                cout<<"\n\n\n";
                cout<<"\t\t1. view car information"<<endl;
                cout<<"\t\t2. edit car information"<<endl;
                cout<<"\t\t3. remove car"<<endl;
                cout<<"\t\t4. add new car"<<endl;
                cout<<"\t\t5. show current trip"<<endl;
                cout<<"\t\t6. show past trip"<<endl;
                cout<<"\t\t7. exit"<<endl;
                cout<<"\n\n";

                cout<<"\t\tenter your choice : ";
                cin>>choice2;

                switch(choice2)
                {
                case 1:
                    o.car_information();
                    break;
                case 2:
                    o.edir_car();
                    break;
                case 3:
                    o.remove_car();
                    break;
                case 4:
                    o.new_car();
                    break;
                case 5:
                    {
                        int i=0;
                        for(auto it=u.begin();it!=u.end();it++)
                        {
                            current_trip(o,u[i]);
                            i=i+1;
                        }
                        break;
                    }
                case 6:
                    {
                        int i=0;
                        for(auto it=lu.begin();it!=lu.end();it++)
                        {
                            past_trip(o,lu[i]);
                            i=i+1;
                        }
                        break;
                    }
                    break;
                }
            }while(choice2!=7);


                }
                break;


        case 2:
            int choice3;
            do
            {
                cout<<"\n\n\n";
                cout<<"\t\t1. new user"<<endl;
                cout<<"\t\t2. old user"<<endl;
                cout<<"\t\t3. exit"<<endl;
                cout<<"\n\n";
                cout<<"\t\tenter your choice : ";
                cin>>choice3;

                switch(choice3)
                {



                case 2:
                    {
                        system("cls");
                        cout<<"\n\n\n\n";
                        int x;
                        cout<<"\t\tenter your customer ID : ";
                        cin>>x;
                        string y;
                        cout<<"\t\tenter your pass word : ";
                        cin>>y;
                        if(u[x-1].get_password(y))
                        {
                            int choice4;
                            do
                            {


                                cout<<"\t\t1. edit details "<<endl;
                                cout<<"\t\t2. clear your remaning payment"<<endl;
                                cout<<"\t\t3. new trip"<<endl;
                                cout<<"\t\t4. exit"<<endl;
                                cout<<"\n\n";
                                cout<<"\t\tenter your choice : ";
                                cin>>choice4;
                                switch(choice4)
                                {
                                case 1:
                                    u[x-1].edit_detail();
                                    break;
                                case 2:
                                    payment(&o,&u[x-1]);
                                    lu.push_back(u[x-1]);
                                    break;
                                case 3:
                                    trip(&o,&u[x-1]);

                                    break;
                                }
                            }while(choice4!=4);
                        }
                        break;

                    }
                     case 1:
                    {

                        tmp.get_details();
                        cout<<"\t\t-------------------"<<endl;
                        trip(&o,&tmp);

                        u.push_back(tmp);
                        cout<<"\t\t------------------------"<<endl;
                        cout<<"\t\thapppy journey"<<endl;
                        cout<<"\t\t------------------------"<<endl;
                        break;
                    }
                }
            }while(choice3!=3);


            break;
        }
    }while(choice1!=3);
    cout<<"\n\n\t\tVISIT AGAIN"<<endl;
    cout<<"\n\t\tTHANK YOU"<<endl;
    return 0;
}
