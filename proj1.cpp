#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
    //Initializing all of the variables to be used
    int mushSold, lemSold, cramSold, saltSold, rabSold,honSold, wellSold;
    float totalReceived, totalIncome, totalProfits, taxedIncome,festiveTax;
    float mushPrice, lemPrice, cramPrice, saltPrice, rabPrice,honPrice,wellPrice;
    float mushTotal, lemTotal, cramTotal, saltTotal, rabTotal, honTotal, wellTotal;
    festiveTax=0.0675;
    mushPrice=0.80;
    lemPrice=3.00;
    cramPrice=2.00;
    saltPrice=2.25;
    rabPrice=3.25;
    honPrice=2.00;
    wellPrice=1.25;


   
    //Prompting the user for all of the items sold 

    cout<<"How many Mushrooms were sold? ";
    cin>>mushSold;

    cout<<"How many Lembas were sold? ";
    cin>>lemSold;

    cout<<"How many Cram Breads were sold? ";
    cin>>cramSold;

    cout<<"How many Salted Porks were sold? ";
    cin>>saltSold;

    cout<<"How many Rabbit Stews were sold? ";
    cin>>rabSold;

    cout<<"How many Honey Cakes were sold? ";
    cin>>honSold;

    cout<<"How many Well Waters were sold? ";
    cin>>wellSold;
    cin.ignore();
    

    //Calculating all of the totals for the products sold
    mushTotal=mushSold*mushPrice;
    lemTotal=lemSold*lemPrice;
    cramTotal=cramSold*cramPrice;
    saltTotal=saltSold*saltPrice;
    rabTotal=rabSold*rabPrice;
    honTotal=honSold*honPrice;
    wellTotal=wellSold*wellPrice;

    //Calculating total money received, how much is being taken for taxes, and the total after taxes
    totalReceived=mushTotal+lemTotal+cramTotal+saltTotal+rabTotal+honTotal+wellTotal;
    taxedIncome=totalReceived*festiveTax;
    totalIncome=totalReceived-taxedIncome;
    totalProfits=totalReceived/2;
    


    cout<<endl<<left<<setw(42)<<setfill('-')<<"---"<<endl;
    cout<<"----Tomburan Longriver\'s Savory Dishes----"<<endl;
    cout<<left<<setw(42)<<setfill('-')<<"---"<<endl;
    cout<<" QTY   DISH NAME UNIT PRICE TOTAL RECEIVED"<<endl;
    cout<<"---- ----------- ---------- --------------"<<endl;
    cout<<setfill(' ')<<setw(4)<<right<<mushSold<<" "<<setw(11)<<left<<"Mushrooms"<<" "<<setw(1)<<"   $"<<fixed<<setprecision(2)<<mushPrice<<" "<<setw(9)<<right<<"$"<<mushTotal<<endl;
    cout<<setfill(' ')<<setw(4)<<right<<lemSold<<" "<<setw(11)<<left<<"Lembas"<<" "<<setw(1)<<"   $"<<fixed<<setprecision(2)<<lemPrice<<" "<<setw(9)<<right<<"$"<<lemTotal<<endl;
    cout<<setfill(' ')<<setw(4)<<right<<cramSold<<" "<<setw(11)<<left<<"Cram Bread"<<" "<<setw(1)<<"   $"<<fixed<<setprecision(2)<<cramPrice<<" "<<setw(9)<<right<<"$"<<cramTotal<<endl;
    cout<<setfill(' ')<<setw(4)<<right<<saltSold<<" "<<setw(11)<<left<<"Salted Pork"<<" "<<setw(1)<<"   $"<<fixed<<setprecision(2)<<saltPrice<<" "<<setw(9)<<right<<"$"<<saltTotal<<endl;
    cout<<setfill(' ')<<setw(4)<<right<<rabSold<<" "<<setw(11)<<left<<"Rabbit Stew"<<" "<<setw(1)<<"   $"<<fixed<<setprecision(2)<<rabPrice<<" "<<setw(9)<<right<<"$"<<rabTotal<<endl;
    cout<<setfill(' ')<<setw(4)<<right<<honSold<<" "<<setw(11)<<left<<"Honey Cake"<<" "<<setw(1)<<"   $"<<fixed<<setprecision(2)<<honPrice<<" "<<setw(9)<<right<<"$"<<honTotal<<endl;
    cout<<setfill(' ')<<setw(4)<<right<<wellSold<<" "<<setw(11)<<left<<"Well Water"<<" "<<setw(1)<<"   $"<<fixed<<setprecision(2)<<wellPrice<<" "<<setw(9)<<right<<"$"<<wellTotal<<endl;
    cout<<setw(42)<<right<<"--------------"<<endl;
    cout<<setw(28)<<right<<"TOTAL RECEIVED"<<setw(7)<<right<<"$"<<fixed<<setprecision(2)<<totalReceived<<endl;
    cout<<setw(28)<<right<<"CUT TAKEN"<<setw(7)<<right<<"$"<<fixed<<setprecision(2)<<taxedIncome<<endl;
    cout<<setw(28)<<right<<"TOTAL MINUS CUT"<<setw(7)<<right<<"$"<<fixed<<setprecision(2)<<totalIncome<<endl;
    cout<<"TOTAL PROFIT PRE-CUT: $"<<totalProfits<<endl;

    

    return 0;
}