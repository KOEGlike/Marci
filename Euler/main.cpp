#include <iostream>
#include <fstream>
#define N 50

using namespace std;

int iranyitatlan_fokszam[N];

int beOlvas(string fileName, int graf[][N])
{
    ifstream f(fileName);
    int n = 0; // csomopontok szama
    f >> n;

    int i, j, elSzam;
    while (f >> i >> j >> elSzam)
    {
        graf[i][j] = elSzam;
        graf[j][i] = elSzam;
    }

    return n;
}

void kiIr(int graf[][N], int n)
{
    cout << "Szomszedsagi matrix:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << graf[i][j] << ' ';
        }
        cout << endl;
    }
}

struct fokszam
{
    int be;
    int ki;
};

fokszam fokszamok[N];
void feltoltFokszamok(int graf[][N], int n)
{
    for (int i = 0; i < n; i++)
    {
        fokszamok[i].ki = 0;
        fokszamok[i].be = 0;
        for (int j = 0; j < n; j++)
        {
            if (graf[i][j])
                fokszamok[i].ki += graf[i][j];
            if (graf[j][i])
                fokszamok[i].be += graf[j][i];
        }
    }
}

void csomopontokFokszama(int graf[][N], int n)
{
    for (int i = 0; i < n; i++)
    {
        iranyitatlan_fokszam[i] = 0;
        for (int j = 0; j < n; j++)
        {
            if (graf[i][j])
                iranyitatlan_fokszam[i] += graf[i][j];
        }
    }
}

bool euler_iranyitatlan(int n)
{
    for (int i = 0; i < n; i++)
    {
        if (iranyitatlan_fokszam[i] % 2 != 0)
        {
            return 0;
        }
    }
    return 1;
}

bool euler_iranyitott(int n)
{
    for (int i = 0; i < n; i++)
    {
        if (fokszamok[i].be != fokszamok[i].ki)
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    int graf[N][N] = {0};
    int n = beOlvas("graf.txt", graf);
    kiIr(graf, n);
    /*feltoltFokszamok(graf, n);//iranyitott
    for(int i=0; i<n; i++){
        cout<<i<<": "<<fokszamok[i].be<<" , "<<fokszamok[i].ki<<"\n";
    }

    if(euler_iranyitott(n)){
        cout<<"Van euler vonal \n";
    }
    else{
        cout<<"Nincs euler vonal \n";
    }



    */
    csomopontokFokszama(graf, n); // iranyitott
    for (int i = 0; i < n; i++)
    {
        cout << i << ": " << iranyitatlan_fokszam[i] << "\n";
    }
    if (euler_iranyitatlan(n))
    {
        cout << "Van euler vonal \n";
    }
    else
    {
        cout << "Nincs euler vonal \n";
    }
    return 0;
}