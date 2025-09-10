#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

void eratoszteneszSzitaja(int n, vector<int> &primek)
{
    primek.push_back(2);
    primek.push_back(3);

    for (int k = 1; primek.size() < n; k++)
    {
        for (int i = 0; i <= 1; i++)
        {
            int candidate = 6 * k + (i * 2 - 1);

            int j=0;
            for(; j<primek.size(); j++) {
                if(candidate%primek[j] == 0) {
                    break;
                }
            }
            if(j==primek.size()) {
                primek.push_back(candidate);
            }

            if(n==primek.size()) {
                return;
            }
        }
    }
}

void kiir(vector<int> &tomb) {
    for(int e:tomb) {
        cout<<e<<" ";
    }
}

void fajlbaIr(vector<int> &tomb) {
    ofstream fajl("primek.txt");
    if (!fajl.is_open()) {
        cout << "Nem sikerült megnyitni a fájlt!" << endl;
        return;
    }
    for(int e:tomb) {
        fajl<<e<<" ";
    }
    fajl.close();
}

int main()
{
    int n;
    vector<int> primek;
    cout<<"n=";
    cin>>n;
    eratoszteneszSzitaja(n, primek);
    kiir(primek);
    fajlbaIr(primek);

    return 0;
}