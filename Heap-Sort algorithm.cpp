#include <iostream>
#include <vector>

using namespace std;

// Function to heapify a subtree rooted at index i, assuming that the subtrees are already heaps
void Heapify(vector<int> &arr, int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
    {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest])
    {
        largest = right;
    }

    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        Heapify(arr, n, largest);
    }
}

// Function to build a max-heap from the given array
void BuildMaxHeap(vector<int> &arr)
{
    int n = arr.size();

    for (int i = n / 2 - 1; i >= 0; --i)
    {
        Heapify(arr, n, i);
    }
}

// HeapSort function to sort an array using heap-sort algorithm
void HeapSort(vector<int> &arr)
{
    int n = arr.size();

    BuildMaxHeap(arr);

    for (int i = n - 1; i > 0; --i)
    {

        swap(arr[0], arr[i]);

        Heapify(arr, i, 0);
    }
}

// Function to print the array
void PrintArray(const vector<int> &arr)
{
    for (int num : arr)
    {
        cout << num << " ";
    }
    cout << endl;
}

int main()
{
    // Example
    vector<int> arr = {12, 11, 13, 5, 6, 7};

    cout << "Original array: ";
    PrintArray(arr);

    // Perform HeapSort
    HeapSort(arr);

    cout << "Sorted array: ";
    PrintArray(arr);

    return 0;
}
