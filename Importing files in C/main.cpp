//
//  main.cpp
//  lab3
//
//  Created by Brandon Johns on 2/15/18.
//  Copyright © 2018 Brandon Johns. All rights reserved.
//
#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;
void number1();

void number1()
{
    //1
    
    ifstream ifs;
    
    char iarray[1000];
    ifs.open("LabInput3-1.txt");
    
    
    if (ifs.fail())
    {
        
        cout<< "that failed"<<endl;
        exit(1);
    }
    int count = 0;
    char *p= iarray;
    while (ifs >> iarray[count++])
    {
        *p=toupper(*p);
        p++;
    }
    
    cout<<"File content is written to LabOutput3-1.txt ."<<endl;
    cout<< iarray<<endl;
    ifs.close();
}
void swap(int *arr, int a, int b) {
    
    int temp = arr[a];
    
    arr[a] = arr[b];
    
    arr[b] = temp;
    
    
}
int indexSmallest(int *arr, int lower, int upper) {
    
    int indexMin = lower;
    
    for (int i = lower + 1; i <= upper; i++)
        
        if ((arr[i] < arr[indexMin]))
            
            indexMin = i;
    
    return indexMin;
    
}
void selectionSort(int *arr, int n) {
    
    for (int i = 0; i < n - 1; i++) {
        
        int j = indexSmallest(arr, i, n - 1);
        
        swap(arr, i, j);
        
    }
    
}
void printArray(int* number, int n) {
    for(int i = 0; i < n; ++i) {
        cout<< number[i]<<" ";
    }
    cout<<endl;
}



int main()
{
    
    //1
    
    number1();
    
    
    //2
    cout<<"-------------------------------------------------------------------------"<<endl;
    
    
     int size=50;
    int inputArray[size];
   
    int n = 0;
    int count;
    int i = 0;
    int j=0;
    int input;
    char userfile[50];
    
    ifstream myfile;
    cout<< "press 1 to enter numbers"<<endl;
    cout<<"press 2 to enter file"<< endl<<": ";
    cin >> input;
    if(input == 1){
        cout << "How many numbers? "<<endl;;
        cin >> n;
        
        cout << "Enter " << n << " integers:" <<endl;
        
        for(i = 0; i < n; i++)
        {
            cin >> inputArray[i];
        }
    }
    if(input == 2)
    {
        cout << "Enter a file name with directory: "<<endl;
        cin >> userfile;
        ifstream myFile(userfile);
        while(myFile >> inputArray[i])
        {
            n++;
            i++;
        }
    }
    for(i = 0; i < n; i++)
    {
        for(j = 0; j <= i; j++)
        {
            if(inputArray[i] > inputArray[j])
            {
                int temp = inputArray[i];
                inputArray[i] = inputArray[j];
                inputArray[j] = temp;
            }
        }
    }
    cout << "\nN\tCount\n";
    for(i = 0; i < n; i++){
        count = 1;
        while(inputArray[i] == inputArray[i + 1] && i < n){
            count++;
            i++;
        }
        cout << inputArray[i] << "\t" << count << endl;
    }
    
    
     cout<<"-------------------------------------------------------------------------"<<endl;
    
    
    
    //3
    
    
    int N;
    int I = 0;
    int arr[1000];
    
    ifstream inFile;
    ifstream inFile1;
    inFile.open("LabInput3-3.txt");
    if (!inFile)
    {
        cout << "can't find LabInput3-3.txt" << endl;
        return 0;
    }
    
    while (inFile >> N)
    {
        arr[I++] = N;
    }
    inFile1.open("LabInput3-4.txt");
    if (!inFile1)
    {
        cout << "can't find LabInput3-4.txt" << endl;
        return 0;
    }
    
    while (inFile1 >> N)
    {
        arr[I++] = N;
    }
    selectionSort(arr, I);
    cout<<"Sorted data is: "<<endl;
    printArray(arr, I);

    
    
    }

