#include <iostream>
#include <fstream>

#define N 50
using namespace std;

int graf[N][N] = {0};
int verem[N] = {0};
int n; // csomopontok szama

int beOlvas(string fileName, int graf[][N])
{
    ifstream f(fileName);
    int n = 0; // csomopontok szama
    f >> n;
    int i, j;
    while (f >> i >> j)
    {
        graf[i][j] = 1;
        graf[j][i] = 1;
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

bool megoldas(int szint)
{
    if (szint == n)
        return true;
    return false;
}

bool jo(int szint)
{
    if (szint > 0 && graf[verem[szint]][verem[szint - 1]] == 0)
        return false;
    for (int i = 0; i < szint; i++)
        if (verem[i] == verem[szint])
            return false;
    return true;
}

void kiirMegoldas()
{
    cout << "Hamilton: ";
    for (int i = 0; i < n; i++)
        cout << verem[i] << " ";
    cout << endl;
}

void back(int szint)
{
    if (megoldas(szint))
    {
        kiirMegoldas();
        return;
    }
    for (int i = 0; i < n; i++)
    {
        verem[szint] = i;
        if (jo(szint))
        {
            back(szint + 1);
        }
    }
}

int main()
{
    n = beOlvas("graf.txt", graf);
    kiIr(graf, n);

    back(0);
    return 0;
}