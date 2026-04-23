#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

class Employee{
private:
string name, department, position;
int idNumber;


public:
Employee(string a, int b, string c, string d){
    name=a;
    department=c;
    position=d;
    idNumber=b;
    }

Employee(string a, int b)
{name=a;idNumber=b;}
Employee();

void setName(string a)
    {name=a;};

void setDepart(string a)
    {department=a;};

void setPosition(string a)
    {position=a;};

void setID(int a)
    {idNumber=a;};





const string getName() const
{return name;};

string getDepart() const
{return department;};

string getPosition() const
{return position;};

int getID() const
{return idNumber;};



};

void DisplayEmployees(const vector<Employee> employees);


int main(){
Employee emp1("Susan Meyers", 47899, "Accounting","Vice President");
Employee emp2("Mark Jones",39119, "IT", "Programmer");
Employee emp3("Joy Rogers", 81774, "Manufacturing","Engineer");
    
vector<Employee> employees = {emp1, emp2, emp3};
DisplayEmployees(employees);
    
return 0;
}



void DisplayEmployees(const vector<Employee> employees){
for(unsigned int i=0;i<employees.size();i++){
    cout<<"Employee "<<i+1<<endl;
    cout<<"Name: "<<employees[i].getName()<<endl;
    cout<<"ID Number: "<<employees[i].getID()<<endl;
    cout<<"Department: "<<employees[i].getDepart()<<endl;
    cout<<"Position: "<<employees[i].getPosition()<<endl;
    cout<<endl;}
    



}