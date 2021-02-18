#include <fstream>
#include <vector>

using namespace std;

ifstream fin("date.in");
ofstream fout("date.out");


void radixSort(int nr, int base, int v[], int n){


    /// Initializez bucket-urile cu 0
    int bucket[base];
    for (int i = 0; i < base; i++){
        bucket[i] = 0;
    }

    /// Impart numerele in buckets in functie de "cifra" curenta
    for (int i = 0; i < n; i++){
        int key = (v[i] / nr) % base;
        bucket[key]++;
    }

    /// Fac sume partiale pe vector pentru a afla de la ce indice trebuie
    /// sa plasez elementele cu o anumita cifra, pastrand ordinea relativa
    for (int i = 1; i < base; i++){
        bucket[i] += bucket[i-1];
    }

    int sol[n];
    
    

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

    int base = 10;
    int nr = 1;

    while (nr <= maxim){
        radixSort(nr, base, v, n);
        nr *= base;
    }

    return 0;
}
