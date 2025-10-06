#include <iostream>
#include <fstream>

#define N 500

using namespace std;

int beOlvas(string fileName, int graf[][N])
{
    ifstream f(fileName);
    int csSz = 0;
    f >> csSz;

    int x, y;
    while (f >> x >> y)
    {
        graf[x][y] = 1;
        graf[y][x] = 1;
    }

    return csSz;
}

/// @brief Kiírja a gráf szomszédsági mátrixát
/// @param n A csúcsok száma
/// @param graf A szomszédsági mátrix
void kiIr(int n, int graf[][N])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << graf[i][j] << " ";
        }
        cout << endl;
    }
}

void komplementer(int n, int graf[][N], int komplementerGraf[][N])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i != j)
            {
                komplementerGraf[i][j] = (graf[i][j] == 0) ? 1 : 0;
            }
            else
            {
                komplementerGraf[i][j] = 0; // Nincs hurok
            }
        }
    }
}

int main()
{
    int graf[N][N] = {0};
    int komplementerGraf[N][N] = {0};
    int csSz = beOlvas("./graf.txt", graf);
    kiIr(csSz, graf);
    cout << "\n\n\n";
    komplementer(csSz, graf, komplementerGraf);
    kiIr(csSz, komplementerGraf);
}