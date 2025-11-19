#include <iostream>
#include <fstream>
#include <fstream>
#include <stack>
#include <queue>
#include <climits>
#define N 50
using namespace std;

bool v[N]; // feldolgozott csomopontok
int d[N];  // tavolsag vektor, minden csomopont tavolsaga a start csomopont

// Beolvassa a csomopontok szamat es az elek listajat
// felepit egy adjacencia(szomszedsagi) matrixot)
// visszateriti a csomopontok szamat
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

int legkozelebbi(int graf[][N], int n)
{
    int min_dist = INT_MAX;
    int mini = -1;
    for (int i = 0; i < n; i++)
    {
        if (!v[i] && d[i] < min_dist)
        {
            min_dist = d[i];
            mini = i;
        }
    }
    return mini;
}

int prim(int graf[][N], int n)
{
    int start = 0;
    int total_weight = 0;
    for (int i = 0; i < n; i++)
    {
        v[i] = 0;       // nem dolgoztunk fel egyet sem
        d[i] = INT_MAX; // minden tavolsag vegtelen
    }
    d[start] = 0;

    for (int i = 0; i < n; i++)
    {
        int u = legkozelebbi(graf, n);
        if (u == -1)
            break;
        v[u] = true;
        // szomszedok tavolsaganak frissitese
        for (int j = 0; j < n; j++)
        {
            if (!v[j] && graf[u][j] != 0 && graf[u][j] < d[j])
            {

                d[j] = graf[u][j];
                total_weight += graf[u][j];
            }
        }
    }
    return total_weight;
}

int main()
{
    int graf[N][N] = {0};
    int n = beOlvas("/workspaces/Marci/Prim/graf.txt", graf);
    kiIr(graf, n);
    cout << "total weight: " << prim(graf, n) << endl;

    return 0;
}
