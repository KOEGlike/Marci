#include <iostream>
#include <fstream>
#include <fstream>
#include <stack>
#include <queue>
#include <climits>

#define N 50

using namespace std;

int beOlvas(string fileName, int graf[][N])
{
    ifstream f(fileName);
    int n = 0; // csomopontok szama
    f >> n;

    int i, j, w;
    while (f >> i >> j >> w)
    {
        graf[i][j] = w;
        graf[j][i] = w;
    }

    return n;
}

// Kiirja a graf adjacencia(szomszedsagi) matrixat
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
fokszam iranyitottFokszamok[N];

int iranyitattlanFokszamok[N];

void feltoltFokszam(int graf[][N], int n)
{
    for (int i = 0; i < n; i++)
    {
        iranyitottFokszamok[i].ki = 0;
        iranyitottFokszamok[i].be = 0;
        for (int j = 0; j < n; j++)
        {
            if (graf[i][j])
            {
                iranyitottFokszamok[i].ki += graf[i][j];
            }
            if (graf[j][i])
            {
                iranyitottFokszamok[j].be += graf[j][i];
            }
        }
    }
}

void csomopontokFokszama(int graf[][N], int n)
{
    for (int i = 0; i < n; i++)
    {
        iranyitattlanFokszamok[i] = 0;
        for (int j = 0; j < n; j++)
        {
            if (graf[i][j])
            {
                iranyitattlanFokszamok[i] += graf[i][j];
            }
        }
    }
}

bool euler_iranyitattlan(int graf[][N], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (iranyitattlanFokszamok[i] % 2 == 1)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int graf[N][N] = {0};
    int n = beOlvas("graf.txt", graf);
    kiIr(graf, n);
    feltoltFokszam(graf, n);
    cout << "euler: " << euler_iranyitattlan(graf, n);
}