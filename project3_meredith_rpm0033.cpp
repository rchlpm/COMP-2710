/*
Rachel Meredith
rpm0033
project2_meredith_rpm0033.cpp

*/

#include <fstream>
#include <iostream>
#include <cstdlib>
#include <string>
#include <cassert>
using namespace std;

const int MAX_SIZE = 100;

//User defined methods

//create ofstream
void writeFile(int outputArray[], int outputArray_size, char* outputname);

//read input file
int readFile(int iArray[], ifstream& instream);

//merge the arrays
int mergeSort(int iArray1[], int iArray1_size, int iArray2[], int iArray2_size, int outputArray[]);

int main()
{
   char file[50];
   char file[50];
   
   int outputArray[2*MAX_SIZE];
   
   int iArray1[MAX_SIZE];
   int iArray2[MAX_SIZE];
   
   cout<<"*** Welcome to Rachel's sorting program ***"
        <<"\nEnter the first input file name: ";
   cin>>file1;
    
   ifstream currFile;
   currFile.open(file1);

//Error message
   if(currFile.fail())
   {
      cout << "Input file opening failed!" << endl;
      exit(1);
   }
    
   int input1_size = readFile(iArray1,currFile);
   currFile.close();

   cout<<"The list of "<<input1_size<<" numbers in file "<<file1<<" is: \n"; //Give the number on characters in file and display them.

   for(int i=0;i<input1_size;i++)
   {
      cout<<iArray1[i]<<endl;
   }
//second file
   cout<<"\nEnter the second input file name: ";
   cin>>file2;

   currFile.open(file2);
//second error message
   if(currFile.fail())
   {
      cout << "Input file opening failed!" << endl;
      exit(1);
   }

   int input2_size = readFile(iArray2,currFile);
   currFile.close();

   cout<<"The list of "<<input2_size<<" numbers in file "<<file2<<" is: \n"; //Give the number on characters in file and display them.

   for(int i=0;i<input2_size;i++)
   {
      cout<<iArray2[i]<<endl;
   }
    
    //creating array from two inputs
   int output_size = mergeSort(iArray1, input1_size, iArray2, input2_size, outputArray);

   cout<<"\nThe sorted list of 11 numbers is: ";

   for(int i=0;i<output_size;i++)
   {
      cout<<outputArray[i]<<" ";
   }
   cout<<std::endl;
    
    //output arrays
   cout<<"Enter the output file name: ";

   char outputname[50]; //Declare output
   cin>> outputname;
   writeFile(outputArray,output_size,outputname);
   cout<<"*** Please check the new file - "<<outputname<<" ***"
        <<"\n*** Goodbye. ***";

}
//hint page
void writeFile(int outputArray[], int outputArray_size, char* outputname)
{
   std::ofstream ofs(outputname);

   if(ofs.fail())
   {
      cout<< "Failed to open file for writing" <<endl;
      exit(1);
   }

   for(int i=0; i<outputArray_size; i++)
   {
      ofs << outputArray[i] << std::endl;
   }
}
//hint page
int readFile(int iArray[], ifstream& instream)
{
   int i = 0;
   instream >> iArray[i];
   while(!instream.eof())
   {
      i++;
      instream >> iArray[i];
   }
   return i;
}

int mergeSort(int iArray1[], int iArray1_size, int iArray2[], int iArray2_size, int outputArray[])
{
   int k=0;
   int i=0;
   int j=0;

   while(i<iArray1_size)
   {
      outputArray[k] = iArray1[i];
      i += 1;
      k += 1;
   }
   while(j<iArray2_size)
   {
      outputArray[k] = iArray2[j];
      j += 1;
      k += 1;
   }

//sorting
   sort(outputArray, outputArray + iArray1_size + iArray2_size);
   return iArray1_size + iArray2_size;
}
