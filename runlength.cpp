/*
Name: Hayden Wagner
Date: Feb 10 2026
Class: CSCI 2170-004
This Lab was made without using an AI 
*/
#include <iostream>
#include <string>

using namespace std;
int main()
{
    string sentence;
    int count=1;
    
    cout<<"Enter a sentence you want to be shortened: "<<endl;
    getline(cin,sentence);
    int len=sentence.length();
   
    for(int i=1;i<=len;i++)
        {
        
        if(sentence[i-1] == sentence[i])
            count++;
        else{
            cout<<count<<sentence[i-1];
            count=1;}
        
        }
        
    
    
    cout<<endl;
    
    return 0;
}