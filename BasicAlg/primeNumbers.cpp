#include <iostream>
#include <cmath>

using namespace std;
static const int M = 1000000;
int shive[M];
bool isPrime(int);
void createShive();
void printPrimes();

int main(int argc, char *argv[]) {
    int n;
    createShive();
    if (argc > 1) {
        n = atoi(argv[1]);
    }
    if (isPrime(n)) {
        cout << n << " is prime number" << endl;
    }
    else {
        cout << n << " is not a prime number" << endl;
    }
    printPrimes();
    return 0;
}

// complexity O(n^1/2)
bool isPrime_old(int n) {
    int limit = sqrt(n);
    for (int i = 2; i <= limit; i ++) {
        if (n % i == 0) {
            return false; // not a prime number
        }
    }
    return true;
}

bool isPrime(int n) {
    if (n < M) {
        return shive[n] == 1;
    }
    return isPrime_old(n);
}

// complexity O(n sqrt(n)) = O(n^3/2)
void createShive() {
    for (int i = 0; i < M; i++) {
        shive[i] = 1;
    }
    for (int i = 2; i < sqrt(M); i++) {
        if (shive[i] == 1) {
            for (int j = i * 2; j < M; j+= i) {
                shive[j] = 0;
            }
        }
    }
}

void printPrimes() {
    int cont = 0;
    for(int i = 2; i < 1000; i++) {
        if (shive[i]) {
            cout << i << " ";
            cont++;
            if (cont > 9) {
                cont = 0;
                cout << endl;
            }
        }
    }
}