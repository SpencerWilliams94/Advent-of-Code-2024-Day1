#include <iostream>
#include <fstream>
#include <cstdio>
using namespace std;

void getDataFromFile(ifstream &infile, int array1[], int array2[]);

int getSmallestNumber(int array[]);


int main(){
    ifstream infile;


    //Both arrays initialized to 0
    int array1[1000] = {};
    int array2[1000] = {};

    getDataFromFile(infile, array1, array2);

    int num1, num2, difference;
    int total = 0;
    for(int i = 0; i < 1000; i++){
        num1 = getSmallestNumber(array1);
        num2 = getSmallestNumber(array2);

        difference = abs(num1 - num2);
        cout << difference << endl;
        total += difference;
    }

    printf("Total: %d\n", total);
    return 0;
}

void getDataFromFile(ifstream &infile, int array1[], int array2[]){
    infile.open("input.txt");
    if (infile.fail()){
        cout << "Input file opening failed." << endl;
        exit(1);
    }

    for(int i = 0; i < 1000; i++){
        infile >> array1[i] >> array2[i];
    }

    infile.close();
}

int getSmallestNumber(int array[]){
    int smallestNumber = 100000; //None of the input numbers are above 100,000 so it works, should probably make a
                                 // permanent solution later
    int smallestNumberIndex = 0;

    for(int i = 0; i < 1000; i++){
        if(array[i] > 0 && array[i] < smallestNumber){
            smallestNumber = array[i];
            smallestNumberIndex = i;
        }
    }

    array[smallestNumberIndex] = 0;
    return smallestNumber;
}