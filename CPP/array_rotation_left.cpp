// Author @pranjal-aggarwal (Pranjal Aggarwal)

#include <iostream>

using namespace std;

void print_array(int *array, int size)
{
	// cout << "size = " << size << endl;
	for (int i=0; i<size; i++)
	{
		cout << *(array+i);
	}
	cout << endl;
}

void array_rotate(int arr[], int temp[], int n, int d)
{
	for (int i=0; i<n-d; i++)
	{
		arr[i] = arr[i+d];
	}
	for (int i=0; i<d; i++)
	{
		arr[n-d+i] = temp[i];
	}
	print_array(arr, n);
}

int main()
{
	int n, d;

	cout << "Size of array: ";
	cin >> n;
	cout << "No. of rotations(d): ";
	cin >> d;

	int arr[n], temp[d];

	for (int i=0; i<n; i++)
	{
		cin >> arr[i];
		if (i <= d)
		{
			temp[i] = arr[i];
		}
	}

	// print_array(arr, n);
	// print_array(temp, d);

	array_rotate(arr, temp, n, d);
}