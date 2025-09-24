#include <iostream>
#include <fstream>
#include <stack>
#include <vector>
#include <queue>

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
        x--;
        y--;
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

void dfs(int n, int graf[][N], int start)
{
    stack<int> verem;
    bool visited[n] = {0};
    verem.push(start);
    while (!verem.empty())
    {
        int u = verem.top();
        verem.pop();
        if (!visited[u])
        {
            visited[u] = true;
            cout << u << " ";
            for (int i = 0; i < n; i++)
            {
                if (!visited[i] && graf[u][i])
                {
                    verem.push(i);
                }
            }
        }
    }
}

void bfs(int n, int graf[][N], int start)
{
    queue<int> verem;
    bool visited[n] = {0};
    verem.push(start);
    while (!verem.empty())
    {
        int u = verem.front();
        verem.pop();
        if (!visited[u])
        {
            visited[u] = true;
            cout << u << " ";
            for (int i = 0; i < n; i++)
            {
                if (!visited[i] && graf[u][i])
                {
                    verem.push(i);
                }
            }
        }
    }
}

int main()
{
    int graf[N][N] = {0};
    int csSz = beOlvas("C:\\Users\\Elev\\Documents\\XI.A\\Marci\\Graph\\DFS\\graf.txt", graf);
    kiIr(csSz, graf);
    dfs(csSz, graf, 0);
    cout << endl;
    bfs(csSz, graf, 0);
    // cout << csSz;
}