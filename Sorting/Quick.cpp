#include<iostream>
#include<cmath>
using namespace std;

int partitionArray(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low + 1; // to skip the pivot element and start iterating from the next element .
    int j = high;

    while (i <= j) {
        while (i <= high && arr[i] <= pivot) {
            i++;
        }
        while (j > low && arr[j] > pivot) {
            j--;
        }
        if (i < j) {
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[low], arr[j]);
    return j;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int partition = partitionArray(arr, low, high);
        quickSort(arr, low, partition - 1);
        quickSort(arr, partition + 1, high);
    }
}
int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    quickSort(arr, 0, n - 1); 
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    return 0;
}