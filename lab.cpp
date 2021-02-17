#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

/// 0

/*
int main(){
    long long a, b;
    cin>>a>>b;
    cout<<a+b;
}
*/

/// 1

/*
bool perfect(long long nr){
    if(nr == 1){
        return true;
    }
    long long s = 0;
    for (int i=1; i<nr; i++){
        if (nr % i == 0){
            s += i;
        }
    }
    if (s == nr){
        return true;
    }
    return false;
}

int main(){
    long long a, b;
    long long suma = 0;
    cin>>a>>b;
    for (int i=a; i<=b; i++){
        if (perfect(i)){
            suma += 1LL * i;
        }
    }
    cout<<suma;

}
*/

/// 2

class Baza{

    public:

        double getPerimetru()

        double getArie()

};

class Cerc : public Baza{

    int raza;

    double getPerimetru() override{
        return 2 * 3.14 * raza;
    }

    double getArie() override{
        return 3.14 * raza * raza;
    }

};

class Dreptunghi : public Baza{

    int laturaMica;
    int laturaMare;

    double getPerimetru() override{
        return laturaMica * 2 + laturaMare * 2;
    }

    double getArie() override{
        return laturaMica * laturaMare;
    }


};

class Patrat : public Baza{

    int latura;

    double getPerimetru() override{
        return latura * 4;
    }

    double getArie() override{
        return latura * latura;
    }

};

class TriunghiDreptunghic : public Baza{

    int catetaMare;
    int catetaMica;

    double getPerimetru() override{
        double ipotenuza = sqrt(catetaMica * catetaMica + catetaMare * catetaMare);
        return catetaMica + catetaMare + ipotenuza;
    }

    double getArie() override{
        return double(catetaMica * catetaMare) / 2;
    }

};


class Prajitura{

    Baza baza;
    int h;

    public:

        void afisare(){
            cout<<baza<<" "<<h<<"\n";
        }

        double getFrisca(){
            return baza.getPerimetru()*h + baza.getArie();
        }

        double getGem(){
            return baza.getArie() * h;
        }

};


class Prajituri{

    vector <Prajitura> v;

    public:

        void add(Prajitura p){
            v.push_back(p);
        }

        void remove(int indice){
            v.erase(v.begin()+indice-1);
        }

        void total(){
            totalFrisca = 0;
            totalGem = 0;
            for (int i=0; i<v.size(); i++){
                totalFrisca += v[i].;
            }
        }

};


int main(){

    Prajituri* p = new Prajituri();

}



