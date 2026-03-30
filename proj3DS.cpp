/*
                Author: Hayden Wagner
                Date: 3/17/2026
                Lab Purpose: Gauss-Jordan Elimination for Solving Linear Equations
                A.I. Disclaimer: THIS CODE WAS WRITTEN WITHOUT THE USE OF AI
*/
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;
const int ROWS = 3;  // Number of equations (rows)
const int COLS = 4;  // Number of columns (3 variables + 1 augmented column)
bool readMatrixFromFile(const string &filename, double matrix[][COLS]);
void GaussJordanElim(double matrix[][COLS]);
void displayMatrix(double matrix[][COLS]);

//main function for calling all other functions and assigning variables
int main(){
    int x1,x2,x3;
    string filename;
    double matrix[ROWS][COLS];
    cout<<"Gauss-Jordan Elimination Solver"<<endl;
    cout<<setw(50)<<setfill('-')<<'-'<<endl;
    cout<<"What file do you want to read from? ";
    cin>>filename;
    readMatrixFromFile(filename, matrix);
    cout<<"Original augmented matrix: "<<endl;
    displayMatrix(matrix);

    GaussJordanElim(matrix);
    cout<<endl<<endl<<"RREF FORM: "<<endl;
    displayMatrix(matrix);
    
    x1=matrix[0][3];
    x2=matrix[1][3];
    x3=matrix[2][3];
    cout<<"x1: "<<x1<<endl<<"x2: "<<x2<<endl<<"x3: "<<x3<<endl;

    return 0;
}

//Opens the file and reads the matrix from said file
bool readMatrixFromFile(const string &filename, double matrix[ROWS][COLS]) {
            ifstream file; //create a file object
            file.open(filename); //open the file
            if (!file) {
                cerr << "Error: Unable to open file!" << endl;
                return false;
            }
        
            // Read matrix from file and store it in a 2D array
            for (int i = 0; i < ROWS; i++) {
                for (int j = 0; j < COLS; j++) {
                    file >> matrix[i][j];  // Read each value into the matrix
                }
            }
            

            
            
            file.close(); //Closes the file after reading its contents.
            return true;
        }

//Performs the Gauss-Jordan Elimination sequence
void GaussJordanElim(double matrix[ROWS][COLS]){
double divisor,multiplier;
for(int i=0; i<ROWS;i++){
    divisor = matrix[i][i];
    for(int j=0; j<COLS;j++)
        matrix[i][j] /= divisor;


    for(int k=0; k<ROWS;k++){
        if(k!=i){
        multiplier = -matrix[k][i];
        for(int l=0;l<COLS;l++)
            matrix[k][l] = matrix[k][l] + multiplier*matrix[i][l];}}
}
}

//Prints the matrix to the terminal
void displayMatrix(double matrix[][COLS]){

for (int i = 0; i < ROWS; i++) {
        cout<<endl;
        for (int j = 0; j < COLS; j++) 
            cout<<setw(4)<<setfill(' ')<<matrix[i][j]<<" ";}

cout<<endl;
}