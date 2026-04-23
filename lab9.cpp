/*
name:Hayden Wagner
date:Feb 26 2026
class: CSCI 2170-004
THIS LAB WAS MADE WITHOUT AI
*/
#include <iostream>
#include <cstdlib>


using namespace std;

//The & symbol tells the function that the variable is a reference parameter (will be updated for calling function but not used in function)
void getDiceParam(int &x,int &y){
cout<<"Enter amount and number of sides (seperated by a space): ";
cin>>x;
cin>>y;

if(x<0||y<0){
    cout<<"All values must be at least 0."<<endl; 
    exit(1);}
}

int diceValue(int numDice, int numSides){
    int diceVal, totalVal=0;
    for(int i = 0; i<numDice;i++){
        diceVal=(rand() % numSides) + 1;
        cout<<diceVal<<endl;
        totalVal+=diceVal;}
    return totalVal;


}

int main()
{
    srand(100);
    int numDice=0, numSides=0, totalVal;
    cout<<"++++ Super Awesome Dice Roller++++"<<endl;
    getDiceParam(numDice,numSides);
    cout<<endl<<endl<<"Rolling "<<numDice<<"d"<<numSides<<endl;
    totalVal=diceValue(numDice,numSides);
    cout<<"Total: "<<totalVal<<endl;
return 0;
}

