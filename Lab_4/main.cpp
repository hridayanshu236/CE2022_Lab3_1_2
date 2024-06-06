#include<iostream>
#include <random> // for std::mt19937
#include"Insertion_Sort/Include/insertion.h"
#include"Quick_Sort/Include/quick.h"
int main()
{   //insertion sort 
    int array_size = 10;
    //Seed with real random value
    std::random_device rd;
    //Initialize Mersenne Twister pseudo-random number generator
    std::mt19937 gen(rd());
    //Defining the range for random numbers
    std::uniform_int_distribution<>dis(0,100);
    int random_numbers[array_size];
    //Generating random numbers
    for(int i=0;i<array_size; i++){
        random_numbers[i]=dis(gen);
    }
    //Generated random numbers
    std::cout << "Generated random numbers:\n ";
    printArray(random_numbers, array_size);
    //passing generated random numbers to insertion sort function
    insertionSort(random_numbers, array_size);
    cout<<"Sorted Array using insertion sort:\n";
    printArray(random_numbers,array_size);
    //Sorted array for quick sort
	int arr[] = {0,25,34,38,45,49,55,66,77,99 };
    cout<<"Array passed to quick sort function:\n";
    printArray(arr,array_size);
    //Passing the sorted array in quick sort function
	quickSort(arr, 0, array_size - 1);
    //sorted array
    cout<<"Sorted Array using quick sort:\n";
    printArray(arr,array_size);
}