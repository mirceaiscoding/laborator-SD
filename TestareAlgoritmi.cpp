#include <fstream>
#include <stdlib.h>
#include <vector>
#include <cstdlib>
#include <time.h>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono; 

ofstream fout("statistici.out");

void copyArray(int a[], int b[], int n){
    for (int i = 0; i < n; i++){
        a[i] = b[i];
    }
}


void afisare(int v[], int n){
    for (int i = 0; i < n; i++){
        fout << v[i] << " ";
    }
    fout << "\n";
}

void copyVector(vector<int> &v, int b[], int n){
    v.clear();
    for (int i = 0; i < n; i++){
        v.push_back(b[i]);
    }
}


bool checkIfCorrectArray(int a[], int sol[], int n){
    for (int i = 0; i < n; i++){
        if (a[i] != sol[i]){
            return false;
        }
    }
    return true;
}


bool checkIfCorrectVector(vector<int> &v, int sol[], int n){
    for (int i = 0; i < n; i++){
        if (v[i] != sol[i]){
            return false;
        }
    }
    return true;
}

bool checkIfCorrect(int a[], int sol[], int n){
    for (int i = 0; i < n; i++){
        if (a[i] != sol[i]){
            return false;
        }
    }
    return true;
}


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


void countingSort(int v[], int n, int max_number, int min_number){

    int f[max_number - min_number + 1];

    for (int i = 0; i <= max_number - min_number; i++){
        f[i] = 0;
    }

    for (int i = 0; i < n; i++){
        f[v[i] - min_number + 1]++;
    }

    for (int i = 1; i <= max_number - min_number; i++){
        f[i] += f[i-1];
    }

    /// v[i] trebuie plasat in sol intre indicii f[v[i] - min_numbber] si f[v[i] -min_number + 1]
    int sol[n];
    for (int i = 0; i < n; i++){
        sol[f[v[i] - min_number]] = v[i];
        f[v[i] - min_number]++;
    }

    copyArray(v, sol, n);

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


void radixSort(int nr, int base, int v[], int n){


    /// Initializez bucket-urile cu 0
    int bucket[base];
    for (int i = 0; i < base; i++){
        bucket[i] = 0;
    }

    /// Impart numerele in buckets in functie de "cifra" curenta
    for (int i = 0; i < n; i++){
        int key = (v[i] / nr) % base;
        bucket[key+1]++;
    }

    /// Fac sume partiale pe vector pentru a afla de la ce indice trebuie
    /// sa plasez elementele cu o anumita cifra, pastrand ordinea relativa
    for (int i = 1; i < base; i++){
        bucket[i] += bucket[i-1];
    }

    int sol[n];
    for (int i = 0; i < n; i++){
        int key = (v[i] / nr) % base;
        sol[bucket[key]] = v[i];
        bucket[key]++;
    }

    copyArray(v, sol, n);

}


void applyRadixSort(int v[], int n, int maxim){
    int base = 10;
    int nr = 1;
    while (nr <= maxim){
        radixSort(nr, base, v, n);
        nr *= base;
    }
}


int main(){

    int numberOfTests = 9;
    int testSize[] = {10, 100, 1000, 1000, 10000, 10000, 100000, 100000, 100000};
    int testMaxNumber[] = {1000000, 100, 10, 10000, 1000, 100000, 1000, 100000, 1000000};

    srand((unsigned) time(0));

    for (int indiceTest = 0; indiceTest < numberOfTests; indiceTest++){

        int size = testSize[indiceTest];
        int maxNumber = testMaxNumber[indiceTest];
        int a[size];
        int maxim = INT32_MIN;
        int minim = INT32_MAX;
        for (int i = 0; i < size; i++){
            int nrCrt = rand() % maxNumber;
            a[i] = nrCrt;
            minim = min(minim, nrCrt);
            maxim = max(maxim, nrCrt);
        }

        fout << "---------------------------------------------------------------------------------------------------\n";
        fout << "Testul " << indiceTest << " are " << size << " numere, iar numarul maxim este " << maxNumber << "\n\n";

        int sol[size];

        if (true){
            /// SORTARE STANDARD LIMBAJ
            copyArray(sol, a, size);
            auto startTime = high_resolution_clock::now(); 
            sort(sol, sol+size);
            auto endTime = high_resolution_clock::now(); 
            auto duration = duration_cast<microseconds>(endTime - startTime); 
            fout << "Timp sortare standard limbaj: " << (long long) duration.count() << " microsecunde\n\n"; 
        }

        int aCopy[size];
        copyArray(aCopy, a, size);

        // if (true){
        //     /// BUBBLE SORT
        //     auto startTime = high_resolution_clock::now(); 
        //     bubbleSort(aCopy, size);
        //     auto endTime = high_resolution_clock::now(); 
        //     auto duration = duration_cast<microseconds>(endTime - startTime); 
        //     fout << "Timp sortare bubble sort: " << duration.count() << " microsecunde\n"; 
        //     if( checkIfCorrectArray(aCopy, sol, size) == true){
        //         fout << "BUBBLE SORT ESTE CORECT\n\n";
        //     }
        // }

        copyArray(aCopy, a, size);

        if (true){
            /// COUNTING SORT
            auto startTime = high_resolution_clock::now(); 
            countingSort(aCopy, size, maxim, minim);
            auto endTime = high_resolution_clock::now(); 
            auto duration = duration_cast<microseconds>(endTime - startTime); 
            fout << "Timp sortare counting sort: " << duration.count() << " microsecunde\n"; 
            if( checkIfCorrectArray(aCopy, sol, size) == true){
                fout << "COUNTING SORT ESTE CORECT\n\n";
            }
        }

        if (true){
            /// MERGE SORT
            copyArray(aCopy, a, size);
            auto startTime = high_resolution_clock::now(); 
            mergeSort(0, size-1, aCopy);
            auto endTime = high_resolution_clock::now(); 
            auto duration = duration_cast<microseconds>(endTime - startTime); 
            fout << "Timp sortare merge sort: " << duration.count() << " microsecunde\n"; 
            if( checkIfCorrectArray(aCopy, sol, size) == true){
                fout << "MERGE SORT ESTE CORECT\n\n";
            }
        }

        if (true){
        /// QUICK SORT
            vector <int> vCopy;
            copyVector(vCopy, a, size);
            auto startTime = high_resolution_clock::now(); 
            quickSort(vCopy);
            auto endTime = high_resolution_clock::now(); 
            auto duration = duration_cast<microseconds>(endTime - startTime); 
            fout << "Timp sortare quick sort: " << duration.count() << " microsecunde\n"; 
            if( checkIfCorrectVector(vCopy, sol, size) == true){
                fout << "QUICK SORT ESTE CORECT\n\n";
            }
        }

        if (true){
            /// RADDIX SORT
            copyArray(aCopy, a, size);
            auto startTime = high_resolution_clock::now(); 
            applyRadixSort(aCopy, size, maxim);
            auto endTime = high_resolution_clock::now(); 
            auto duration = duration_cast<microseconds>(endTime - startTime); 
            fout << "Timp sortare raix sort: " << duration.count() << " microsecunde\n"; 
            if( checkIfCorrectArray(aCopy, sol, size) == true){
                fout << "RADIX SORT ESTE CORECT\n\n";
            }
        }
    }
}