#include "quickSort.h"

void quickSort(int arr[], int low, int high) {
    if (low >= high)
        return;
    int pi = partition(arr, low, high);
    quickSort(arr,low, pi - 1);
    quickSort(arr,pi+1,high);
}

int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low;
    int tmp;
    for (int j = low + 1; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            tmp = arr[j];
            arr[j] = arr[i];
            arr[i] = tmp;
        }
    }
    arr[low] = arr[i];
    arr[i] = pivot;
    return i;
}