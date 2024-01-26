#include <iostream>
using namespace std;

int s = 0;  // Counter for swaps
int it = 0; // Counter for iterations

// Function to perform selection sort on an array
void selectionsort(int *arr, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int minindex = i;
        for (int j = i + 1; j < size; j++)
        {
            it++; // Increment iteration counter
            if (arr[j] < arr[minindex])
            {
                minindex = j;
            }
        }
        if (minindex != i)
        {
            // Swap elements if necessary
            swap(arr[i], arr[minindex]);
            s++; // Increment swap counter
        }
    }
}

// Function to display the elements of an array
void display(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[100];
    int n;

    // Input the size of the array
    cout << "Enter size of array: ";
    cin >> n;

    // Input elements into the array
    cout << "Enter elements in array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // Print student details
    cout << "Gandla Sai Shivani" << endl;
    cout << "22103054" << endl;

    // Display the given array
    cout << "Given array is: ";
    display(arr, n);

    // Sort the array using selection sort
    selectionsort(arr, n);

    // Display the sorted array
    cout << "Sorted array is: ";
    display(arr, n);

    // Display the number of iterations and swaps
    cout << "Number of iterations = " << it << endl;
    cout << "Number of swaps = " << s << endl;

    // Time complexity in best case is O(n^2)
    // Time complexity in worst case is O(n^2)
    // Algorithm is not stable

    return 0;
}

