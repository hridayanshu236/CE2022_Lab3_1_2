#include<iostream>
#include <random> // for std::mt19937
// #include <ctime> // for clock(), clock_t, and CLOCKS_PER_SEC
#include <chrono> // for high_resolution_clock
#include"Insertion_Sort/Include/insertion.h"
#include"Quick_Sort/Include/quick.h"
int main()
{   //insertion sort 
    int array_size = 1000;
    //Seed with real random value
    std::random_device rd;
    //Initialize Mersenne Twister pseudo-random number generator
    std::mt19937 gen(rd());
    //Defining the range for random numbers
    std::uniform_int_distribution<>dis(0,1000);
    int random_numbers[array_size];
    //Generating random numbers
    for(int i=0;i<array_size; i++){
        random_numbers[i]=dis(gen);
    }
    //Generated random numbers
    std::cout << "Generated random numbers:\n ";
    printArray(random_numbers, array_size);
    
    // Measure time taken by insertion sort
    auto start = std::chrono::high_resolution_clock::now();
    //passing generated random numbers to insertion sort function
    insertionSort(random_numbers, array_size);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> insertion_sort_duration = end - start;
    cout<<"\nSorted Array using insertion sort:\n";
    printArray(random_numbers,array_size);
    std::cout << "Time taken by insertion sort: " << insertion_sort_duration.count() << " milliseconds\n";
   
    //passing the sorted array from insertion sort to quick sort and calculating time to sort
    start = std::chrono::high_resolution_clock::now();
    quickSort(random_numbers, 0, array_size - 1);
    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> quick_sort_duration = end - start;

    // Print sorted array using quick sort
    std::cout << "\n\nSorted array using quick sort:\n";
    printArray(random_numbers, array_size);
    std::cout << "Time taken by quick sort: " << quick_sort_duration.count() << " milliseconds\n";
}