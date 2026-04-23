#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

struct Movie{
string title, director;
int yearReleased, runTime;
};


void processFile(Movie* arrMovies);
int getRows();
void printData(Movie*, int);
void searchTitle(Movie*, int);
void searchDirector(Movie*, int);
void searchYear(Movie*, int);
void searchRunTime(Movie*, int);
void lessThanTime(Movie*, int);
void greaterThanTime(Movie*,int);

int main(){
    int rows=0;
    rows=getRows();
    Movie *arrMovies=new Movie[rows];
    int uInput;
    processFile(arrMovies);
    do{
    cout<<"Menu:"<<endl<<"1. Search by Title"<<endl<<"2. Search by Director"<<endl<<"3. Search by release year"<<endl<<"4. Search by run time"<<endl<<"5. Print all movies"<<endl<<"6. Less than release year"<<endl<<"7. Greater than release year"<<endl<<"8. Quit"<<endl<<"Input: ";
    cin>>uInput;
    switch(uInput){
        case 1:searchTitle(arrMovies, rows); break;
        case 2:searchDirector(arrMovies, rows); break;
        case 3:searchYear(arrMovies, rows); break;
        case 4:searchRunTime(arrMovies, rows); break;
        case 5:printData(arrMovies,rows); break;
        case 6:lessThanTime(arrMovies, rows); break;
        case 7:greaterThanTime(arrMovies, rows); break;
        case 8:break;}}while(uInput!=8);
    cout<<"Have a good day!"<<endl;
   
    
    
    
    

    
    return 0;
}

int getRows(){
    ifstream infile;
    infile.open("movies.txt");
    string line;
    int numRows=0;
    
    while(getline(infile,line,'\n')){
    numRows++;}
    
    infile.close();
return numRows;}

void processFile(Movie* arrMovies){
    
    int index;
    ifstream dataGet;
    dataGet.open("movies.txt");
    string line;
    while(getline(dataGet,line)){
        stringstream ss(line);
        string item;
        int count =0;
        while(getline(ss,item,',')){
            switch(count){
                case 0: 
                    arrMovies[index].title=item;
                    break;
                case 1:
                    arrMovies[index].director=item;
                    break;
                case 2:
                    arrMovies[index].yearReleased=stoi(item);
                    break;
                case 3:
                    arrMovies[index].runTime=stoi(item);
                    break;
                
            }
            count++;
        }
        index++;
    }
}

void printData(Movie* arrMovies, int rows){
for(int i=0;i<rows;i++){
    cout<<arrMovies[i].title<<endl;
    cout<<arrMovies[i].director<<endl;
    cout<<arrMovies[i].yearReleased<<endl;
    cout<<arrMovies[i].runTime<<endl;
    cout<<endl;
}
}

void searchTitle(Movie* arrMovies, int rows){
    string name;
    cout<<"Enter a movie name to search for: ";
    cin>>name;
    cout<<endl;
    
    int count=0;
    for(int i=0;i<rows;i++){
        if(arrMovies[i].title==name){
            cout<<arrMovies[i].title<<endl;
            cout<<arrMovies[i].director<<endl;
            cout<<arrMovies[i].yearReleased<<endl;
            cout<<arrMovies[i].runTime<<endl;
            cout<<endl;
            count++;}
        }
    if(count==0){cout<<"Movie not found!"<<endl;}
}

void searchDirector(Movie* arrMovies, int rows){
    string director;
    cin.ignore();
    cout<<"Enter a director to search for: ";
    getline(cin,director);
    cout<<endl;
    
    int count=0;
    for(int i=0;i<rows;i++){
        if(arrMovies[i].director==director){
            cout<<arrMovies[i].title<<endl;
            cout<<arrMovies[i].director<<endl;
            cout<<arrMovies[i].yearReleased<<endl;
            cout<<arrMovies[i].runTime<<endl;
            cout<<endl;
            count++;}
        }
    if(count==0){cout<<"Movie not found!"<<endl;}
}

void searchYear(Movie* arrMovies, int rows){
    int year;
    cout<<"Enter a year to search for: ";
    cin>>year;
    cout<<endl;
    
    int count=0;
    for(int i=0;i<rows;i++){
        if(arrMovies[i].yearReleased==year){
            cout<<arrMovies[i].title<<endl;
            cout<<arrMovies[i].director<<endl;
            cout<<arrMovies[i].yearReleased<<endl;
            cout<<arrMovies[i].runTime<<endl;
            cout<<endl;
            count++;}
        }
    if(count==0){cout<<"Movie not found!"<<endl;}
}

void searchRunTime(Movie* arrMovies, int rows){
    int runTime;
    cout<<"Enter a run time to search for: ";
    cin>>runTime;
    cout<<endl;
    
    int count=0;
    for(int i=0;i<rows;i++){
        if(arrMovies[i].runTime==runTime){
            cout<<arrMovies[i].title<<endl;
            cout<<arrMovies[i].director<<endl;
            cout<<arrMovies[i].yearReleased<<endl;
            cout<<arrMovies[i].runTime<<endl;
            cout<<endl;
            count++;}
        }
    if(count==0){cout<<"Movie not found!"<<endl;}
}


void lessThanTime(Movie* arrMovies, int rows){
    int lessThan;
    cout<<"Enter a release year to search less than for: ";
    cin>>lessThan;
    cout<<endl;
    
    int count=0;
    for(int i=0;i<rows;i++){
        if(arrMovies[i].yearReleased<lessThan){
            cout<<arrMovies[i].title<<endl;
            cout<<arrMovies[i].director<<endl;
            cout<<arrMovies[i].yearReleased<<endl;
            cout<<arrMovies[i].runTime<<endl;
            cout<<endl;
            count++;}
        }
    if(count==0){cout<<"Movie not found!"<<endl;}
}

void greaterThanTime(Movie* arrMovies, int rows){
    int greaterThan;
    cout<<"Enter a release year to search greater than for: ";
    cin>>greaterThan;
    cout<<endl;
    
    int count=0;
    for(int i=0;i<rows;i++){
        if(arrMovies[i].yearReleased>greaterThan){
            cout<<arrMovies[i].title<<endl;
            cout<<arrMovies[i].director<<endl;
            cout<<arrMovies[i].yearReleased<<endl;
            cout<<arrMovies[i].runTime<<endl;
            cout<<endl;
            count++;}
        }
    if(count==0){cout<<"Movie not found!"<<endl;}
}