#include <iostream>
#include <fstream>
#include <array>
#include <sstream>
#include <iomanip>

using namespace std;
const int kMaxRows=5, kMaxCols=10;

int load_data(int [][kMaxCols]);
int max_num(int[][kMaxCols],int);
int min_num(int[][kMaxCols],int);
int sum_num(int[][kMaxCols],int);
float avg_num(int[][kMaxCols],int);
int menu();


int main(){
int numRows;
int uInput;

int nums[kMaxRows][kMaxCols];
numRows=load_data(nums);

cout<<"Menu: "<<endl<<endl<<"1. average"<<endl<<"2. sum"<<endl<<"3. max"<<endl<<"4. min"<<endl<<"5. quit"<<endl<<endl;
uInput=menu();
    
float avg;
int sum,max,min;
while(uInput!=5){
switch (uInput)
    {
        case 1: avg=avg_num(nums,numRows);
                cout<<"Average of numbers: "<<fixed<<setprecision(2)<<avg<<endl<<endl;
            break;
        case 2: sum=sum_num(nums,numRows);
            cout<<"Sum of numbers: "<<sum<<endl<<endl;
            break;
        case 3: max=max_num(nums,numRows);
            cout<<"Max of numbers: "<<max<<endl<<endl;
            break;
        case 4: min=min_num(nums,numRows);
            cout<<"Min of numbers: "<<min<<endl<<endl;
            break;
        
        default: cout<<"Invalid input, please review";
            break;

    }
    
uInput=menu();
}
cout<<"Exiting program..."<<endl;
return 0;
}


int menu(){
int uInput;

cout<<"Enter choice: ";
cin>>uInput;

return uInput;}



int load_data(int nums[][kMaxCols]){
    ifstream infile;
    string fileName, number,line;
    int col=0,row=0;
    cout<<"What is the name of the file? ";
    cin>>fileName;
    infile.open(fileName);
    
    while(getline(infile,line)){

    stringstream ss(line);
    string item;
    col=0;
        while(getline(ss,item,','))
            {
                int num=stoi(item);
                nums[row][col]=num;
                col++;
            } row++;}
return row;}


float avg_num(int nums[][kMaxCols],int numRows){
int numOfNums=0;
float avg,total=0;

for(int ROW=0;ROW<numRows;ROW++){
    for(int COL=0;COL<kMaxCols;COL++){
        total+=nums[ROW][COL];
        numOfNums++;}
}
    avg=total/numOfNums;
    return avg;
}


int sum_num(int nums[][kMaxCols],int numRows){
int total=0;

for(int ROW=0;ROW<numRows;ROW++){
    for(int COL=0;COL<kMaxCols;COL++){
        total+=nums[ROW][COL];}
}
    return total;

}



int max_num(int nums[][kMaxCols],int numRows){

int max=-999;

for(int ROW=0;ROW<numRows;ROW++){
    for(int COL=0;COL<kMaxCols;COL++){
        if(max<nums[ROW][COL])
            max=nums[ROW][COL];
}
}

    
    return max;
}


int min_num(int nums[][kMaxCols],int numRows){

int min=999;

for(int ROW=0;ROW<numRows;ROW++){
    for(int COL=0;COL<kMaxCols;COL++){
        if(min>nums[ROW][COL])
            min=nums[ROW][COL];
}
}

return min;
    }