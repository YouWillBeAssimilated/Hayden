// File: project4.cpp
// Author: Written by Hayden Wagner
// Instructor: Dr. Williams
// Course: CSCI 2170
// Due Date: April 2, 2026
// Description: Takes product and ingredient count and cost and determines the most expensive items
// AI DISCLAIMER: THIS PROJECT WAS MADE WITHOUT THE USE OF AI




//THERE ARE TWO LISTED SIZES FOR THE CONSTANT VARIABLES IN THE INSTRUCTIONS
//I USED THE LARGER SIZE GIVEN TO AVOID SIZE CONFLICTS


#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;
const int kMaxProducts=24,kMaxIngredients=30;

ifstream getRecipeFile();

ifstream getProductFile();

void calculateProductPrice(int [][kMaxProducts],float [],float [], int, int);

int getMaxProductPrice(float [], int);

int main(){
ifstream recipeFile,productFile;
int numProduct,numIngredient,ingAmount[kMaxIngredients][kMaxProducts],maxProd;
float ingPrice[kMaxIngredients],prodPrice[kMaxProducts];
string prodNames[kMaxProducts];
    
recipeFile=getRecipeFile();
cout<<"File opened successfully"<<endl;
productFile=getProductFile();
cout<<"File opened successfully"<<endl<<endl;

recipeFile>>numProduct;
recipeFile>>numIngredient;
    
if(numProduct==0||numIngredient==0){
    cout<<"No products or ingredients entered. Please try a different file."<<endl;
    return 1;}


    for(int row=0;row<numIngredient;row++){
        for(int col=0;col<numProduct;col++){
            recipeFile>>ingAmount[row][col];
            getline(productFile,prodNames[col]);
            }
        recipeFile>>ingPrice[row];
    }
    
    

calculateProductPrice(ingAmount, ingPrice, prodPrice, numProduct, numIngredient);
maxProd=getMaxProductPrice(prodPrice, numProduct);

cout<<"Cost Of Bakery Products Table"<<endl;
cout<<setw(80)<<setfill('*')<<"*"<<endl;
    
cout<<setw(21)<<setfill(' ')<<left<<"Products";

    for(int ing=0;ing<numIngredient;ing++)
        cout<<setw(4)<<"Ing "<<setw(4)<<ing+1;
        
    cout<<setw(20)<<"Price"<<endl;
    
cout<<setw(80)<<setfill('-')<<"-"<<endl;
    
for(int row=0;row<numProduct;row++){
    cout<<setfill(' ')<<setw(3)<<row+1<<setw(18)<<prodNames[row];
    for(int col=0;col<numIngredient;col++)
        cout<<setw(7)<<ingAmount[col][row]<<" ";
    cout<<setw(1)<<"$"<<setw(19)<<fixed<<setprecision(2)<<prodPrice[row]<<endl;
}
cout<<setw(80)<<setfill('-')<<"-"<<endl<<endl;

cout<<"Product "<<maxProd+1<<": "<<prodNames[maxProd]<<" is the most expensive."<<endl;
    
return 0;
}


//Prompts the user to input the name of the recipe file
ifstream getRecipeFile(){
string fileName;
    
cout<<"What is the recipe filename? ";
cin>>fileName;

ifstream infile;
infile.open(fileName);

if(!infile){
    cout<<"Error opening file."<<endl;
    infile.close();
    getRecipeFile();}

return infile;
    }

//Prompts the user to input the name of the product file
ifstream getProductFile(){
string fileName;
    
cout<<"What is the product filename? ";
cin>>fileName;

ifstream infile;
infile.open(fileName);

if(!infile){
    cout<<"Error opening file."<<endl;
    infile.close();
    getProductFile();}

return infile;}



//Takes the number of products and ingredients and calculates the total price for each product
void calculateProductPrice(int ingAmount[][kMaxProducts], float ingPrice[],float prodPrice[],int numProduct, int numIngredient){
    for(int col=0;col<numProduct;col++){
        for(int row=0;row<numIngredient;row++)
            prodPrice[col]+=ingPrice[row]*ingAmount[row][col];
            }
return;
}


//Determines which product is the most expensive and returns that index to main
int getMaxProductPrice(float prodPrice[], int numProduct){
int max=-999, index;
    
    for(int num=0;num<numProduct;num++)
        if(prodPrice[num]>max){
            max=prodPrice[num];
            index=num;
                }
return index;
}