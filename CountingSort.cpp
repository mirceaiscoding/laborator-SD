#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;

ifstream fin("date.in");
ofstream fout("date.out");


void copyArray(int a[], int b[], int n){
    for (int i = 0; i < n; i++){
        a[i] = b[i];
    }
}


void countingSort(int v[], int n, int max_number){

    int f[max_number + 1];
    for (int i = 0; i <= max_number; i++){
        f[i] = 0;
    }

    for (int i = 0; i < n; i++){
        f[v[i]+1]++;
    }

    for (int i = 1; i <= max_number; i++){
        f[i] += f[i-1];
    }

    /// v[i] trebuie plasat in sol intre indicii f[v[i]] si f[v[i]+1]
    int sol[n];
    for (int i = 0; i < n; i++){
        sol[f[v[i]]] = v[i];
        f[v[i]]++;
    }

    copyArray(v, sol, n);

}


int main(){

    int n;
    fin >> n;
    int v[n];

    int maxim = -1;

    for (int i = 0; i < n; i++){
        fin >> v[i];
        maxim = max(maxim, v[i]);
    }

    countingSort(v, n, maxim);

    for (int i = 0; i < n; i++){
        fout << v[i] << " ";
    }

    return 0;
}