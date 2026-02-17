#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string userFile;
    cout<<"What file would you like to decompress? ";
    cin>>userFile;
    ifstream file(userFile);

    if (!file) {
        cout <<"File "<<userFile<<" does not exist."<< endl;
        return 1;
    }

    int count,num1=0,num2=0,lineLength=0;
    string line,ch;
    
    getline(file,line);
    while(!line.empty())
        {
    lineLength=line.length();
    for(int i=0; i<lineLength;i++)
        {
            if(isdigit(line[i]))
            {
            num1=line[i];
            num1-='0';
            i++;
                if(isdigit(line[i]))
                    {
                    num2=line[i];
                    num2-='0';
                    count=(num1*10);
                    count+=num2;
                        i++;
                    }
                else
                    count=num1;

            }       
            
                
           else
                
            {
                if(line[i]==' '&&line[i+2]==' ')
                {
                    ch=line[i+1]; 
                    i+=3;
                }
                else if(line[i-1]==' '&&line[i+1]==' ')
                {
                    ch=line[i];
                    i+=1;
                }
                for(int g=1;g<=count;g++)
                   cout<<ch;
                
                
            }
        
        
       
        }
        cout<<endl;
        getline(file,line);
        
        }
    cout<<endl;
    return 0;
}
