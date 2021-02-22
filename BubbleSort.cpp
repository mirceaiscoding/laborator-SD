#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;

ifstream fin("date.in");
ofstream fout("date.out");


void bubbleSort(int v[], int n){

    int changes;
    do {
        changes = 0;
        for (int i = 0; i < n-1; i++){
            if (v[i] > v[i+1]){
                swap(v[i], v[i+1]);
                changes++;
            }
        }
    } while (changes != 0);

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