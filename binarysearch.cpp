#include <iostream>
using namespace std;

int count = 0; // Counter for the number of comparisons

// Recursive binary search function
int binarysearch(int *arr, int key, int start, int end) {
    int mid = start + (end - start) / 2;

    // Base case: element not found
    if (start > end) {
        return 0;
    }

    // Check if the middle element is the key
    if (arr[mid] == key) {
        count++;
        return 1; // Element found
    }
    // If key is less than the middle element, search in the left half
    else if (key < arr[mid]) {
        count++;
        return binarysearch(arr, key, start, mid - 1);
    }
    // If key is greater than the middle element, search in the right half
    else {
        count++;
        return binarysearch(arr, key, mid + 1, end);
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

    int key;
    cout << "Enter element to be searched : ";
    cin >> key;

    cout << "Gandla Sai Shivani" << endl;
    cout << "22103054" << endl;

    // Perform binary search and display result
    if (binarysearch(arr, key, 0, n - 1)) {
        cout << "Element is present" << endl;
    } else {
        cout << "Element not found" << endl;
    }

    // Display the number of comparisons made
    cout << "Number of comparisons taken is " << count << endl;

    // Time complexity is O(logn)

    return 0;
}
