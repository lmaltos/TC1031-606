#include <iostream>
using namespace std;

void insertionSort(int arr[], int n);
void mergeSort(int arr[], int left, int right);

int main() {
    int my_array[10] = {9,8,7,6,5,4,3,2,1,0};
    for (int i = 0; i < 10; i++) {
        my_array[i] = rand() % 100;
    }
    //insertionSort(my_array,10);
    mergeSort(my_array,0,9);
    for (int i = 0; i < 10; i++) {
        cout << my_array[i] << " ";
    }
    cout << endl;
}

void insertionSort(int arr[], int n) {
    for(int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

void merge(int arr[], int left, int mid, int right) {
    int i,j,k;
    int *aux = new int[right - left + 1];
    i = left;
    j = mid + 1;
    k = 0;
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            aux[k++] = arr[i++];
        }
        else {
            aux[k++] = arr[j++];
        }
    }
    // copy the remain values of the left array
    while (i <= mid) {
        aux[k++] = arr[i++];
    }
    // copy the remain values of the right array
    while (j <= right) {
        aux[k++] = arr[j++];
    }
    // copy form aux to arr
    for (k = 0; k < right - left + 1; k++) {
        arr[left + k] = aux[k];
    }
    delete[] aux; // release dynamic memory 
}

void mergeSort(int arr[], int left, int right) {
    if (left >= right)
        return;
    int mid = (left + right) / 2;
    mergeSort(arr,left,mid);
    mergeSort(arr,mid+1,right);
    merge(arr,left,mid,right);
}