/*
    Author: Hayden Wagner
    Date: 02/26/2026
    Lab Purpose: Virus Spread Simulation Using Recursion and Iteration
    A.I. Disclaimer: THIS CODE WAS WRITTEN ENTIRELY WITHOUT AI
*/
            
#include <iostream>
#include <iomanip>


using namespace std;

int totalInfectedRecursive(int numDay);
int newInfectionsRecursive(int numDay);
int totalInfectedIterative(int numDay);




int main(){
    string answer;
    cout<<endl<<"Virus Spread Simulation"<<endl;
    cout<<setw(70)<<setfill('-')<<'-'<<endl;
    do{
        
int numDay, totalInfectedRec, totalInfectedIt; //Initializing all needed variables


cout<<"How many days do you want to simulate? ";
cin>>numDay; //Getting number of days to simulate

totalInfectedRec=totalInfectedRecursive(numDay);
totalInfectedIt=totalInfectedIterative(numDay); //Calling both functions to get the number of infected individuals

cout<<endl<<"Recursive approach: Total infected individuals on Day "<<numDay<<": "<<totalInfectedRec;
cout<<endl<<"Iterative Approach: Total infected individuals on Day "<<numDay<<": "<<totalInfectedIt; //Outputting the total numbers

cout<<endl<<"Do you want to simulate again (y/n): "; //Prompting user to continue the simulation
cin>>answer;
cout<<endl;
}while(answer=="y");

    cout<<"Simulation ended. Stay Safe!"<<endl;
    cout<<setw(70)<<setfill('-')<<'-'<<endl;
    return 0;
}


int totalInfectedRecursive(int numDay){
    if (numDay == 1)
        return 1;  // Base case: Total infected on Day 1 is 1
    else if (numDay == 2)
        return 3;  // Base case: Total infected on Day 2 is 1 + 2 = 3
    else
        return totalInfectedRecursive(numDay - 1) + newInfectionsRecursive(numDay);

}

int newInfectionsRecursive(int numDay){
                if(numDay == 1)
                    return 1;  // Base case: Day 1 has 1 new infection
                else if (numDay == 2)
                    return 2;  // Base case: Day 2 has 2 new infections
                else
                    return newInfectionsRecursive(numDay - 1) + 2 * newInfectionsRecursive(numDay - 2);
                    // Apply recurrence relation for new infections
}

int totalInfectedIterative(int numDay){
    int currentNewInfections, prev2=2,prev1=1,total=3;
    if (numDay==1)
        return 1;
    else if (numDay==2)
        return 3;

    for(int i=3;i<=numDay;i++){
        currentNewInfections = prev2 + 2 * prev1;  // Apply recurrence relation for new infections
        total = total + currentNewInfections;  // Accumulate total infections
        prev1 = prev2;  // Update previous values
        prev2 = currentNewInfections;
            
        
        }
        return total;  // Return the total infected individuals up to day n
    
        return 0;
}