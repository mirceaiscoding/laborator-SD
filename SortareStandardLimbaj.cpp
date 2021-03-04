#include <fstream>
#include <algorithm>

using namespace std;


ifstream fin("date.in");
ofstream fout("date.out");

int v[100];

int main(){

    int n;
    fin >> n;
    int maxim = -1;

    for (int i = 0; i < n; i++){
        fin >> v[i];
    }

    sort(v, v+n);

    for (int i = 0; i < n; i++){
        fout << v[i] << " ";
    }

    return 0;
}

