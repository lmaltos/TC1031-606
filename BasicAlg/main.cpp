#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;

int randNmb(int M) {
    return rand() % M;
}

int main(int argc, char *argv[]) {
    int n = 100;
    int M = 1000;
    double m = 0.0;
    double m1 = 0.0;

    if (argc > 1) {
        n = atoi(argv[1]);
        if (argc > 2) {
            M = atoi(argv[2]);
        }
    }
    srand(time(0));
    for (int i = 0; i < n; i++) {
        double x = randNmb(M);
        cout << x << " ";
        m += x / n;
        m1 += x * x / n;
        if ((i+1) % 10 == 0) cout << endl;
    }

    cout << " Avg: " << m << endl;
    cout << "Std. Dev.:" << sqrt(m1 - m * m) << endl;
}