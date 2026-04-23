/*
Name: Hayden Wagner
Date: 3/17/2026
Class:CSCI 2170-004
This lab was made without the use of AI
*/

#include <iostream>
#include <fstream>
#include <iomanip>





using namespace std;

int processFile(ifstream &infile,int &totalNumGrades,int &pointsEarned);
double calculateFinalGrade(int totalPossiblePoints, int pointsEarned);
char calculateLetter(int finalGrade);




int main(){
int totalNumGrades=0,pointsEarned=0,totalPossiblePoints=0;
double finalGrade;
char letterGrade;
string fileName;
cout<<"What is the name of the file? ";
cin>>fileName;
cout<<endl;
    
ifstream infile;
infile.open(fileName);
if(infile){
    totalPossiblePoints=processFile(infile, totalNumGrades, pointsEarned);
    finalGrade=calculateFinalGrade(totalPossiblePoints,pointsEarned);
    letterGrade=calculateLetter(finalGrade);

    cout<<setw(25)<<left<<"Number of grades: "<<right<<totalNumGrades<<endl;
    cout<<setw(25)<<left<<"Total points earned: "<<right<<pointsEarned<<endl;
    cout<<setw(25)<<left<<"Max possible points: "<<right<<totalPossiblePoints<<endl<<endl;
    cout<<left<<"Final Grade: "<<"     "<<letterGrade<<"    "<<fixed<<setprecision(1)<<finalGrade<<"%"<<endl;
}


else
    cout<<"Error opening file."<<endl;
    


return 0;
}

int processFile(ifstream &infile,int &totalNumGrades,int &pointsEarned){
int totalPossiblePoints,num;
while(infile>>num){
    
    totalNumGrades++;
    pointsEarned+=num;
}
    totalPossiblePoints=totalNumGrades*100;
    return totalPossiblePoints;
}



double calculateFinalGrade(int totalPossiblePoints, int pointsEarned){
double finalGrade=0,temp;
    if(totalPossiblePoints==0||pointsEarned==0)
        finalGrade=0;
    else{temp=pointsEarned;
        finalGrade=(temp/totalPossiblePoints)*100;}
    return finalGrade;

}

char calculateLetter(int finalGrade){
    char letterGrade='F';
    if(finalGrade>=90.0)
        letterGrade='A';
    else if(finalGrade>=80.0)
        letterGrade='B';
    else if(finalGrade>=70.0)
        letterGrade='C';
    else if(finalGrade>=60.0)
        letterGrade='D';

return letterGrade;
}