#include <iostream>
#include <fstream>

#define N 50

using namespace std;

int beOlvas(string fileName, int graf[][N])
{
    ifstream f(fileName);
    int csSz = 0;
    f >> csSz;

    while (f)
    {
        int x, y;
        f >> x >> y;
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
        cout << "\n";
    }
}

int dfs()
{
}

int main()
{
    int graf[N][N] = {0};
    int csSz = beOlvas("C:\\Users\\Elev\\Documents\\XI.A\\Marci\\Graph\\DFS\\graf.txt", graf);
    kiIr(csSz, graf);
    cout << csSz;
}