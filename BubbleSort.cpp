#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;

ifstream fin("date.in");
ofstream fout("date.out");


void bubbleSort(int v[], int n){
    int changes;
    for (int sortedNumbers = 0; sortedNumbers < n; sortedNumbers ++){
        changes = 0;
        for (int i = 0; i < n-1-sortedNumbers; i++){
            if (v[i] > v[i+1]){
                swap(v[i], v[i+1]);
                changes++;
            }
        }
        if (changes == 0){
            return;
        }
    }
}

int main(){

    int n;
    fin >> n;
    int v[n];

    for (int i = 0; i < n; i++){
        fin >> v[i];
    }

    bubbleSort(v, n);

    for (int i = 0; i < n; i++){
        fout << v[i] << " ";
    }

    return 0;
}