#ifndef QUICKSORT_H
#define QUICKSORT_H

template <typename T>
void quickSort(T arr[], int low, int high);

template <typename T>
int partition(T arr[], int low, int high);

template <typename T>
void quickSort(T arr[], int low, int high) {
    if (low >= high)
        return;
    int pi = partition(arr, low, high);
    quickSort(arr,low, pi);
    quickSort(arr,pi+1,high);
}

template <typename T>
int partition(T arr[], int low, int high) {
    T pivot = arr[low];
    int i = low;
    T tmp;
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

#endif