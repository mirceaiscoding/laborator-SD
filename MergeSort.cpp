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

void mergeSort(int st, int dr, int v[]){

    if (st < dr){

        int mid = (st + dr) / 2;
        mergeSort(st, mid, v);
        mergeSort(mid+1, dr, v);

        /// Interclasez v[st:mij] si v[mij+1:dr]
        int sol[dr-st+1];
        int i = st;
        int j = mid+1;
        int indice = 0;
        while (i <= mid && j <= dr){
            if (v[i] < v[j]){
                sol[indice] = v[i];
                indice++;
                i++;
            }else{
                sol[indice] = v[j];
                indice++;
                j++;
            }
        }
        while (i <= mid){
            sol[indice] = v[i];
            indice++;
            i++;
        }
        while (j <= dr){
            sol[indice] = v[j];
            indice++;
            j++;
        }
        copyArray(v+st, sol, dr-st+1);
    }
}


int main(){

    int n;
    fin >> n;
    int v[n];

    for (int i = 0; i < n; i++){
        fin >> v[i];
    }

    mergeSort(0, n-1, v);

    for (int i = 0; i < n; i++){
        fout << v[i] << " ";
    }

    return 0;
}