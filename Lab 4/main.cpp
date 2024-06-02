#include<iostream>

int main()
{

	int arr[] = {1,3,5,6,9,11 };
	int n = 6;

	quickSort(arr, 0, n - 1);

	for (int i = 0; i < n; i++)
     {
		cout << arr[i] << " ";
	}

	return 0;
}