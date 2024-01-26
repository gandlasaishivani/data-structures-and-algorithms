#include<iostream>
using namespace std;

int s = 0; // Counter for swaps
int it = 0; // Counter for iterations

// Function to perform insertion sort on an array
void insertionsort(int *arr, int size) {
    for (int i = 1; i < size; i++) {
        it++; // Increment iteration counter
        int j = i - 1;
        int temp = arr[i]; // Current element to be inserted
        while (j >= 0) {
            if (arr[j] > temp) {
                arr[j + 1] = arr[j]; // Swap elements
                s++; // Increment swap counter
                j--;
            } else {
                break;
            }
        }
        arr[j + 1] = temp; // Insert the current element in its correct position
    }
}

// Function to display the elements of an array
void display(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[100];
    int n;

    // Input the size of the array
    cout << "Enter size of array: ";
    cin >> n;

    // Input elements into the array
    cout << "Enter elements in array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Print student details
    cout << "Gandla Sai Shivani" << endl;
    cout << "22103054" << endl;

    // Display the given array
    cout << "Given array is: ";
    display(arr, n);

    // Sort the array using insertion sort
    insertionsort(arr, n);

    // Display the sorted array
    cout << "Sorted array is: ";
    display(arr, n);

    // Display the number of iterations and swaps
    cout << "Number of iterations = " << it << endl;
    cout << "Number of swaps = " << s << endl;

    // Time complexity in best case is O(n)
    // Time complexity in worst case is O(n^2)
    // Algorithm is stable

    return 0;
}
