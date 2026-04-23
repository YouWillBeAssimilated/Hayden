#include <iostream>
#include <array>
using namespace std;

const int ARRAY_SIZE=5;
bool GradesAreSame(const array<double, ARRAY_SIZE>, const array<double, ARRAY_SIZE>);
array<double,ARRAY_SIZE*2> GetGrades();

int main(){

double grade;
bool gradesSame;
array<double, ARRAY_SIZE> stu1_grades;
array<double, ARRAY_SIZE> stu2_grades;
array<double, ARRAY_SIZE*2> stu_grades;

stu_grades=GetGrades();
    for(int i=0;i<ARRAY_SIZE;i++){
    grade=stu_grades[i];
    stu1_grades[i]=grade;}


    
for(int i=5;i<ARRAY_SIZE*2;i++){
    grade=stu_grades[i];
    stu2_grades[i-5]=grade;}
    


gradesSame=GradesAreSame(stu1_grades,stu2_grades);
if(gradesSame==true)
    cout<<endl<<"The student's grades are the same!"<<endl;
else
    cout<<endl<<"The student's grades are different!"<<endl;

return 0;
}



bool GradesAreSame(const array<double, ARRAY_SIZE> stu1_grades, const array<double, ARRAY_SIZE> stu2_grades){
    bool gradesSame=true;
    for(int i =0;i<ARRAY_SIZE;i++){
        if(stu1_grades!=stu2_grades)
            gradesSame=false;

    }

    return gradesSame;
}

array<double,ARRAY_SIZE*2> GetGrades(){
    double grade;
array<double, ARRAY_SIZE*2> stu_grades;
cout<<"Please enter 5 grades for student 1: "<<endl;
    
for(int i=0;i<ARRAY_SIZE;i++){
    cout<<"Getting grade: ";
    cin>>grade;
    stu_grades[i]=grade;}

cout<<endl<<"Please enter 5 grades for student 2: "<<endl;
    
for(int i=0;i<ARRAY_SIZE;i++){
    cout<<"Getting grade: ";
    cin>>grade;
    stu_grades[i+5]=grade;}




return stu_grades;


}