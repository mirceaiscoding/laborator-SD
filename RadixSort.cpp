#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;

ifstream fin("date.in");
ofstream fout("date.out");


void afisare(int v[], int n){
    for (int i = 0; i < n; i++){
        cout << v[i] << " ";
    }
    cout << "\n";
}

void copyArray(int a[], int b[], int n){
    for (int i = 0; i < n; i++){
        a[i] = b[i];
    }
}

void radixSort(int currentPowerOfTwo, int powerOfTwo, int v[], int n){


    /// Initializez bucket-urile cu 0
    int bucket[(1 << powerOfTwo)];
    for (int i = 0; i < (1 << powerOfTwo); i++){
        bucket[i] = 0;
    }

    /// Impart numerele in buckets in functie de "cifra" curenta
    for (int i = 0; i < n; i++){
        int key = ( (v[i] >> currentPowerOfTwo ) & ( (1 << powerOfTwo) - 1 ) );
        bucket[key+1]++;
    }

    /// Fac sume partiale pe vector pentru a afla de la ce indice trebuie
    /// sa plasez elementele cu o anumita cifra, pastrand ordinea relativa
    for (int i = 1; i < (1 << powerOfTwo); i++){
        bucket[i] += bucket[i-1];
    }

    int sol[n];
    for (int i = 0; i < n; i++){
        int key = ( (v[i] >> currentPowerOfTwo ) & ( (1 << powerOfTwo) - 1 ) );
        sol[bucket[key]] = v[i];
        bucket[key]++;
    }

    copyArray(v, sol, n);

}


void applyRadixSort(int v[], int n, int maxim){
    int powerOfTwo = 1;
    while ((1 << powerOfTwo) <= maxim / 2){
        powerOfTwo++;
    }
    int currentPowerOfTwo = 0;
    while ((1 << currentPowerOfTwo) <= maxim){
        radixSort(currentPowerOfTwo, powerOfTwo, v, n);
        currentPowerOfTwo += powerOfTwo;
    }
}

int main(){


    int n;
    fin >> n;
    int v[n];
    int maxim = -1;

    for (int i = 0; i < n; i++){
        int x;
        fin >> x;
        maxim = max(maxim, x);
        v[i] = x;
    }

    applyRadixSort(v, n, maxim);

    for (int i = 0; i < n; i++){
        fout << v[i] << " ";
    }

    return 0;
}