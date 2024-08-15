#include <iostream>
using namespace std;

void insertionSort(int arr[], int n);

int main() {
    int my_array[10] = {9,8,7,6,5,4,3,2,1,0};
    for (int i = 0; i < 10; i++) {
        my_array[i] = rand() % 100;
    }
    insertionSort(my_array,10);
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