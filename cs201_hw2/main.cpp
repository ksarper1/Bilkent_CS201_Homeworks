//Kemal Sarper Sahin
#include <iostream>
#include <cstdlib>
#include "findMedian.h"



int main() {
    int size;
    std::cout << "Enter the size of array: ";
    std::cin >> size;
    std::cout << "" << std::endl;

    int* randArray1 = new int[size];
    for (int i = 0; i < size; i++) {
        randArray1[i] = rand() % 1500; // Generate a number between 0 and 1499
        if (rand() % 2 == 0) randArray1[i] = randArray1[i] * (-1); // randomly assigning sign
    }
    int* randArray2 = new int[size];
    int* randArray3 = new int[size];

    for (int i = 0; i < size; i++){     //making 2 more identical arrays
        randArray2[i]=randArray1[i];
        randArray3[i]=randArray1[i];
    }

    clock_t startTime = clock();
    for(int i = 0; i<10;i++)FIND_MEDIAN_1(randArray1,size);
    double duration = (1000* double (clock()-startTime)/CLOCKS_PER_SEC)/10;
    std::cout << "Execution took " << duration << " milliseconds." << std::endl; //execution time of FIND_MEDIAN_1

    startTime = clock();
    for(int i = 0; i<10;i++)FIND_MEDIAN_2(randArray2,size);
    duration = (1000* double (clock()-startTime)/CLOCKS_PER_SEC)/10;
    std::cout << "Execution took " << duration << " milliseconds." << std::endl; //execution time of FIND_MEDIAN_2

    startTime = clock();
    for(int i = 0; i<10;i++)FIND_MEDIAN_3(randArray3,size);
    duration = (1000* double (clock()-startTime)/CLOCKS_PER_SEC)/10;
    std::cout << "Execution took " << duration << " milliseconds." << std::endl; //execution time of FIND_MEDIAN_3

    std::cout << "" << std::endl;
    return 0;
}
