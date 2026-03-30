/*
Author: Hayden Wagner
Date: February 5 2025
Purpose: Traffic light control
*/

#include <iostream>
using namespace std;

//Initializing the function to determine if the traffic light will be green
bool trafficLightControl(bool carDetected,bool timerCondition, bool pedestrianCrossing)
    {
        bool greenLight;
        if(carDetected || timerCondition)
        {
            if(pedestrianCrossing)
                greenLight=0;
            else
                greenLight=1;
        }

        if(pedestrianCrossing)
        {
            greenLight=0;
        }



        
        return greenLight;
    }

int main()
{
    
    bool carDetected,timerCondition,pedestrianCrossing,greenLight,cont;

    //Getting all of the input from the user
    cout<<"Is a car detected? (1 for true, 0 for false): ";
    cin>>carDetected;
    cout<<endl<<"Is the timer condition allowing? (1 for true, 0 for false): ";
    cin>>timerCondition;
    cout<<endl<<"Is a pedestrian crossing? (1 for true, 0 for false): ";
    cin>>pedestrianCrossing;

    //Calling the function
    greenLight=trafficLightControl(carDetected, timerCondition, pedestrianCrossing);

    //Determines the outcome
    if(greenLight)
        cout<<endl<<"The light is green (cars may go)."<<endl;
    else
        cout<<"The light is red (cars must stop)"<<endl;


    cout<<"Do you want to continue?(1/0): ";
    cin>>cont;

    while(cont)
    {
    cout<<"Is a car detected? (1 for true, 0 for false): ";
    cin>>carDetected;
    cout<<endl<<"Is the timer condition allowing? (1 for true, 0 for false): ";
    cin>>timerCondition;
    cout<<endl<<"Is a pedestrian crossing? (1 for true, 0 for false): ";
    cin>>pedestrianCrossing;
    greenLight=trafficLightControl(carDetected, timerCondition, pedestrianCrossing);

    if(greenLight)
        cout<<endl<<"The light is green (cars may go)."<<endl;
    else
        cout<<"The light is red (cars must stop)"<<endl;

    cout<<"Do you want to continue?(1/0): ";
    cin>>cont;
    }



    return 0;
}

