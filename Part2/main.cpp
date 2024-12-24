#include <iostream>
#include <fstream>
#include <cstdio>
#include <array>
#include <algorithm>

void getDataFromFile(std::ifstream& infile, int array1[], int array2[]);

int main() {
    std::ifstream infile;

    //Both arrays initialized to 0
    std::array<int, 1000> array1 = {};
    std::array<int, 1000> array2 = {};

    getDataFromFile(infile, array1.data(), array2.data());

    int similarityScore = 0;
    for (int element : array1) {
        similarityScore += element * std::count(array2.begin(), array2.end(), element);
    }
    
    printf("Similarity Score: %d\n", similarityScore);

    return 0;
}

void getDataFromFile(std::ifstream& infile, int array1[], int array2[]) {
    infile.open("input.txt");
    if (infile.fail()) {
        std::cout << "Input file opening failed." << std::endl;
        exit(1);
    }

    for (int i = 0; i < 1000; i++) {
        infile >> array1[i] >> array2[i];
    }

    infile.close();
}

