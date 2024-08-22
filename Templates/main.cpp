#include <iostream>
#include <vector>
#include "quickSort.h"
#include "Date.h"

using namespace std;
template <typename T>
void print(T[],int);

int main() {
    Date my_Dates[10]; 
    for (int i = 0; i< 10; i++) {
        my_Dates[i].setDay(rand()%29);
        my_Dates[i].setMonth(rand()%12);
        my_Dates[i].setYear(2000 + rand()%5);
    }  
    print(my_Dates,10);
    quickSort(my_Dates,0,10);  
    print(my_Dates,10);
}


template <typename T>
void print(T arr[],int n){
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}