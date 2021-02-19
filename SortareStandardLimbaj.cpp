#include <iostream>
#include <algorithm>

using namespace std;

int v[100];

int main(){

    int n;
    cin >> n;
    int maxim = -1;

    for (int i = 0; i < n; i++){
        cin >> v[i];
    }

    sort(v, v+n);

    for (int i = 0; i < n; i++){
        cout << v[i] << " ";
    }

    return 0;
}

