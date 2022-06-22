#include "owner.h"
#include <bits/stdc++.h>
#include "user.h"
#include <user.h>
using namespace std;

owner::owner()
{
    pw="pass";

    name.push_back("BALENO       ");
    price.push_back(2000);
    name.push_back("CIAZ         ");
    price.push_back(2200);
    name.push_back("ERITGA       ");
    price.push_back(1800);
    name.push_back("VITARA BREZZA");
    price.push_back(2500);
    name.push_back("WAGON-R      ");
    price.push_back(1800);
    name.push_back("SWITT DZIRA  ");
    price.push_back(2000);
    name.push_back("EECO         ");
    price.push_back(1800);
    name.push_back("CRETA        ");
    price.push_back(3000);
    name.push_back("ELITE I20    ");
    price.push_back(2500);
    name.push_back("VERNA        ");
    price.push_back(2700);
    name.push_back("ELENTRA      ");
    price.push_back(2800);
    name.push_back("NEXON        ");
    price.push_back(2000);
    name.push_back("TIAGO        ");
    price.push_back(2200);
    name.push_back("ALTROZ       ");
    price.push_back(2400);
    name.push_back("FORTUNER     ");
    price.push_back(3500);
    name.push_back("INNOVA       ");
    price.push_back(4000);
    name.push_back("BOLENO       ");
    price.push_back(3500);
    name.push_back("SCORPIO      ");
    price.push_back(3800);
    name.push_back("AUDI A6      ");
    price.push_back(6000);
    name.push_back("AUDI A4      ");
    price.push_back(7000);
    name.push_back("BMW X1       ");
    price.push_back(7000);
    name.push_back("BMW X5       ");
    price.push_back(8000);


}
void owner::car_information()
{
    cout<<"\t\tavaible car in the shop"<<endl;
    int k=0;
    for(auto it=name.begin();it!=name.end();it++)
    {
        cout<<"\t\t\t\t"<<k+1<<".\t"<<*it<<"\t"<<price[k]<<endl;
        k++;
    }
}
void owner::edir_car()
{
    cout<<"\t\tyou can change the rent of the car "<<endl;
    car_information();
    int n;
    cout<<"\t\tenter a car number : ";
    cin>>n;
    int x;
    cout<<"\t\tenter a new rent : ";
    cin>>x;
    price[n-1]=x;
}
void owner::new_car()
{
    string a;
    //a = new car name
    int b;
    //b = new car rent
    cout<<"\t\tenter a new car name : ";
    cin>>a;
    cout<<"\t\tenter a new car rent : ";
    cin>>b;
    name.push_back(a);
    price.push_back(b);
}
void owner::remove_car()
{
    car_information();
    int x;
    //x = number of car which was remove by owner
    cout<<"\t\tenter a number of car : ";
    cin>>x;
    auto it1=name.begin()+x-1;
    auto it2=price.begin()+x-1;
    name.erase(it1);
    price.erase(it2);
}
void current_trip(owner a,user b)
{
    if(b.remaning_payment!=0)
        b.show();
}
void past_trip(owner a,user b)
{

        b.show();
}
int owner::check_password(string j)
{
    if(j==pw)
        return 1;
    else
        return 0;
}
