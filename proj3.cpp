#include <iostream>
#include <fstream>
#include <string>

using namespace std;




string getLineData(string line);
string getKeyData(string invLine,int digit);



int main()
{
    
    
    string invLine,passcode,line,strDigit, fileName;
    int digit=5;
    cout<<"Enter file to decode: ";
    cin>>fileName;
    ifstream infile;
    infile.open(fileName);
    if(infile){
    
    while(getline(infile,line)){
        invLine=getLineData(line);
        strDigit=getKeyData(invLine,digit);
        passcode+=strDigit;}
    cout<<endl<<"Password: "<<passcode<<endl;
    cout<<"You have cracked the Space Safe! Now get the documents and go back to headquarters!"<<endl;
    }
    else
        cout<<"File "<<fileName<<" could not be found."<<endl;
return 0;
}



//This function gets the input data from the given file and inverts it to be used.
string getLineData(string line){
    string invLine;
    int lenLine=0;
    
    lenLine=line.length();
    lenLine--;
    
    while(lenLine>=0){
        invLine+=line[lenLine];
        lenLine--;}

return invLine;
}

//This function takes the inversed instructions and determines the code.
string getKeyData(string invLine, int digit){
    int lenLine=0,index=0;
    char move;
    string strDigit, passcode;
    lenLine=invLine.length();
    lenLine--;
    while(index<=lenLine){
        
        move=invLine[index];
                if(move=='U'){
                    if(digit>0&&digit<=3)
                        digit=digit;
                    else
                        digit-=3;
                    index++;
                }
                
                else if(move=='R'){
                    if(digit==3||digit==6||digit==9)
                        digit=digit;
                    else
                        digit+=1;
                    index++;
                }
                    
                else if(move=='D'){
                    if(digit>=7&&digit<=9)
                        digit=digit;
                    else
                        digit+=3;
                    index++;
                }
                    
                else if(move=='L'){
                    if(digit==1||digit==4||digit==7)
                        digit=digit;
                    else
                        digit-=1;
                    index++;
                }
        
        
        }
    
    strDigit=to_string(digit);
    
    
    
    return strDigit;
}