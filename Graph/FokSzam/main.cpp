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

void kiirFokszamok(int csSz, int graf[][N])
{
    for (int i = 0; i < csSz; i++)
    {
        int db = 0;
        for (int j = 0; j < csSz; j++)
        {
            if (graf[i][j] == 1)
            {
                db++;
            }
        }
        cout << i << ":" << db << endl;
    }
}

int main()
{
    int graf[N][N] = {0};
    int csSz = beOlvas("C:/Users/Elev/Documents/XI.A/Marci/Graph/FokSzam/graf.txt", graf);
    kiIr(csSz, graf);
    kiirFokszamok(csSz, graf);
}