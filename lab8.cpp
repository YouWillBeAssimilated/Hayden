/*
  Name: Hayden Wagner
  Date: 2 19 2026
  Class: CSCI 21770-004
  This is a program that makes a scalable division table
  THIS PROGRAM WAS MADE ENTIRELY WITHOUT THE USE OF AI
*/

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

int main()
{
    ofstream outfile;
    outfile.open("results.dat");
    
    int divTableLength;
    float value;
    cout<<"Enter division table size: ";
    cin>>divTableLength;

    if(divTableLength<0)
        {cout<<"Table Length can't be negative."<<endl;
        outfile<<"-- Your Custom Division Table --"<<endl;}
    else if(divTableLength==0)
        outfile<<"-- Your Custom Division Table --"<<endl;
    else
    {
    outfile<<"-- Your Custom Division Table --"<<endl;
    outfile<<"  |";

    int i=1;
    while(i<=divTableLength)
        {outfile<<setw(5)<<right<<i;
        i++;}
    i=1;
    outfile<<endl<<"---";
    
    while(i<=divTableLength)
        {
         outfile<<"-----";
        i++;}
    
    
    outfile<<endl;
    for(float row=1; row<=divTableLength;row++)
        {
        
        outfile<<fixed<<setprecision(0)<<setw(2)<<right<<row<<"|";
            for(float col=1; col<=divTableLength;col++)
                {
                    value=row/col;
                    
                    outfile<<setw(5)<<right<<fixed<<setprecision(2)<<value;
                    
                }
        
        outfile<<endl;
        }
    }
outfile.close();
cout<<"The contents of the table were output in the file results.dat"<<endl;
return 0;
}