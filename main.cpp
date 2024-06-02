#include<iostream>
#include <random> // for std::mt19937
#include"../Include/quick.h"
// #include"Insertion Sort/Include/insertion.h"
int main()
{   //insertion sort using MT number generator
    int n = 6;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<>dis(0,999);
    std::cout<<"Using MT: \n";

    for(int i=0; i<n; i++){

    }
	int arr[] = {1,12,5,6,9,11 };
	

	quickSort(arr, 0, n - 1);

	for (int j = 0; j < n; j++)
     {
		cout << arr[j] << " ";
	}

	return 0;
}