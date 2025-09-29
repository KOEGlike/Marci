#include <iostream>
#include <fstream>
#include <stack>
#include <vector>
#include <queue>
#include <array>

#define N 50

using namespace std;

int beOlvas(string fileName, int graf[][N])
{
    ifstream f(fileName);
    int csSz = 0;
    f >> csSz;

    int x, y;
    while (f >> x >> y) // Check if read operation succeeded
    {
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

vector<bool> dfs(int n, int graf[][N], int start)
{
    stack<int> verem;
    vector<bool> visited(n);
    verem.push(start);
    visited[start] = true; // Mark as visited when pushing

    while (!verem.empty())
    {
        int u = verem.top();
        verem.pop();
        // cout << u + 1 << " ";

        for (int i = n - 1; i >= 0; i--)
        {
            if (!visited[i] && graf[u][i])
            {
                visited[i] = true;
                verem.push(i);
            }
        }
    }
    return visited;
}

vector<bool> bfs(int n, int graf[][N], int start)
{
    queue<int> sor;
    vector<bool> visited(n);
    sor.push(start);
    while (!sor.empty())
    {
        int u = sor.front();
        sor.pop();
        if (!visited[u])
        {
            visited[u] = true;
            for (int i = 0; i < n; i++)
            {
                if (!visited[i] && graf[u][i])
                {
                    sor.push(i);
                }
            }
        }
    }
    return visited;
}

bool all_true(vector<bool> vec)
{
    for (bool i : vec)
    {
        if (!i)
        {
            return false;
        }
    }
    return true;
}

void merge_bools(vector<bool> &into, vector<bool> &from)
{
    for (int i = 0; i < into.size() && i < from.size(); i++)
    {
        if (from[i])
        {
            into[i] = true;
        }
    }
}

vector<vector<int>> szamol(int n, int graf[][N])
{
    vector<bool> visited(n);
    vector<vector<int>> szegmensek;
    while (!all_true(visited))
    {
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                vector<bool> vec = dfs(n, graf, i);

                merge_bools(visited, vec);

                vector<int> elemek;
                for (int i = 0; i < vec.size(); i++)
                {
                    if (vec[i])
                    {
                        elemek.push_back(i);
                    }
                }
                szegmensek.push_back(elemek);
            }
        }
    }
    return szegmensek;
}

int main()
{
    int graf[N][N] = {0};
    int csSz = beOlvas("./graf.txt", graf);
    kiIr(csSz, graf);
    cout << endl;

    vector<vector<int>> szegmensek = szamol(csSz, graf);

    cout << "graph szegmensei: \n";
    for (vector<int> sz : szegmensek)
    {
        for (int e : sz)
        {
            cout << e << " ";
        }
        cout << endl;
    }
}