// SOAL 1 - Analisis Kompleksitas Waktu Analisis Algoritma

//Analisis untuk Tmin dan Tmax secara manual:
//|==================================================|
//|        Pseudocodenya       | Cost | Tmin  | Tmax |
//|============================|======|=======|======|
//|procedure FindMin           |  C1  |   1   |   1  |
//|min <- A[0]                 |  C2  |   1   |   1  |
//|for i <- 1 to n-1           |  C3  |   n   |   n  |
//|if A[i] < min               |  C4  |  n-1  |  n-1 |
//|min <- A[i]                 |  C5  |   0   |  n-1 |
//|end if                      |  C6  |  n-1  |  n-1 |
//|end for                     |  C7  |   n   |   n  |
//|return min                  |  C8  |   1   |   1  |
//|end procedure               |  C9  |   1   |   1  |
//|==================================================|

// Best Case (Tmin):
// Arraynya urut naik jadi kondisi if nya itu selalu salah = C5 = 0
// Tmin = (C3+C4+C6+C7)*n + (C1+C2+C8+C9-C4-C6)
//      = (1+1+1+1)*n + (1+1+1+1-1-1)
//      = 4n + 4 => O(n)

// Worst Case (Tmax):
// Arraynya urut turun jadi kondisi if nya itu selalu benar = C5 = n-1
// Tmax = (C3+C4+C5+C6+C7)*n + (C1+C2+C8+C9-C4-C5-C6)
//      = (1+1+1+1+1)*n + (1+1+1+1-1-1-1)
//      = 5n + 3 => O(n)


#include <iostream>
using namespace std;

int findMin(int A[], int n, int &idxMin) {
    int min = A[0];
    idxMin = 0;

    for (int i = 1; i <= n - 1; i++) {
        if (A[i] < min) {
            min = A[i];
            idxMin = i;
        }
    }
    return min;
}

int main() {
    int fib[8] = {1, 1, 2, 3, 5, 8, 13, 21};
    int n = 8;

    cout << "Soal 1: Analisis Algoritma Kompleksitas Waktu FindMin" << endl;
    cout << "Isi array Fibonaccinya: ";
    for (int i = 0; i < n; i++) {
        cout << fib[i];
        if (i < n - 1) cout << ", ";
    }
    cout << endl;

    int idxMin;
    int nilaiMin = findMin(fib, n, idxMin);

    cout << "Nilai minimum : " << nilaiMin << endl;
    cout << "Indeks        : " << idxMin << endl;
    cout << "Best Case  : 4n + 4 => O(n)" << endl;
    cout << "Worst Case : 5n + 3 => O(n)" << endl;

    return 0;
}

