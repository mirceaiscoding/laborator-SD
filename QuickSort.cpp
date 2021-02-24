#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <cstdlib>


using namespace std;

ifstream fin("date.in");
ofstream fout("date.out");


void copyArray(int a[], int b[], int n){
    for (int i = 0; i < n; i++){
        a[i] = b[i];
    }
}


void printVector(vector <int> &aux){
    for (int i = 0; i < aux.size(); i++){
        fout << aux[i] << " ";
    }
    fout << "\n";
}



void quickSort(vector <int> &aux){

    if (aux.size() > 1){

        /// Aleg 3 elemente random din aux si selectez mediana lor

        srand((unsigned) time(0));
        int pivot1 = aux[rand() % aux.size()];
        int pivot2 = aux[rand() % aux.size()];
        int pivot3 = aux[rand() % aux.size()];

        if (pivot1 > pivot2){
            swap(pivot1, pivot2);
        }
        if (pivot2 > pivot3){
            swap(pivot2, pivot3);
        }
        if (pivot1 > pivot2){
            swap(pivot1, pivot2);
        }

        int pivot = pivot2;

        vector <int> low;
        vector <int> eq;
        vector <int> high;

        for (int i = 0; i < aux.size(); i++){
            if (aux[i] < pivot){
                low.push_back(aux[i]);
            }
            if (aux[i] == pivot){
                eq.push_back(aux[i]);
            }
            if (aux[i] > pivot){
                high.push_back(aux[i]);
            }
        }


        /// Aplic algoritmul pentru low si high (deoarece eq este sortat deja)
        quickSort(low);
        quickSort(high);

        aux.clear();

        /// Concatenez cele 3 liste
        for (int i = 0; i < low.size(); i++){
            aux.push_back(low[i]);
        }
        for (int i = 0; i < eq.size(); i++){
            aux.push_back(eq[i]);
        }
        for (int i = 0; i < high.size(); i++){
            aux.push_back(high[i]);
        }

    }
}


int main(){

    int n;
    fin >> n;
    vector <int> v;

    int maxim = -1;

    for (int i = 0; i < n; i++){
        int x;
        fin >> x;
        maxim = max(maxim, x);
        v.push_back(x);
    }

    quickSort(v);

    for (int i = 0; i < n; i++){
        fout << v[i] << " ";
    }

    return 0;
}