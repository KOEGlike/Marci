#include <iostream>
#include <fstream>
#include <stack>
#include <vector>
#include <queue>
#include <array>

#define N 500

using namespace std;

int beOlvas(string fileName, int graf[][N])
{
    ifstream f(fileName);
    int csSz = 0;
    f >> csSz;

    int x, y;
    while (f >> x >> y) // Check if read operation succeeded
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
        cout << "\n";
    }
}

vector<int> moore(int graf[][N], int n, int start)
{
    queue<int> sor;
    vector<int> p(n, -1);

    sor.push(start);
    p[start] = start;
    sor.push(start);
    while (!sor.empty())
    {
        int u = sor.front();
        sor.pop();

        for (int i = 0; i < n; i++)
        {
            if (p[i] == -1 && graf[u][i] == 1)
            {
                p[i] = u;
                sor.push(i);
            }
        }
    }

    return p;
}

void kiirUtvonal(int start, int finish, int graf[][N], int n)
{
    vector<int> p = moore(graf, n, start);
    int x = p[finish];
    while (x != start &&)
}

int main()
{
    int graf[N][N];
    int n = beOlvas("C:/Users/Elev/Documents/XI.A/Marci/Graph/MooreBFS/be.in", graf);

    kiIr(n, graf);
    cout << endl;

    vector<int> p = moore(graf, n, 0);

    for (int e : p)
    {
        cout << e << " ";
    }
}