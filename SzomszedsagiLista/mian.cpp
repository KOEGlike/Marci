#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> graf;
int visited[100] = {0};

bool v[N]; // feldolgozott csomopontok
int d[N];  // tavolsag vektor, minden csomopont tavolsaga a start csomopont
int p[N];  // szulo(parent) vektor, minden csomopont tavolsaga a start csomopont

int beOlvas(string fileName, vector<vector<int>> &graf)
{
    ifstream f(fileName);
    int n = 0; // csomopontok szama
    f >> n;
    int i, j;
    graf.resize(n);
    while (f >> i >> j)
    {
        graf[i].push_back(j);
    }
    return n;
}

void kiIr(vector<vector<int>> &graf, int n)
{
    cout << "Szomszedsagi lista:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << i << ": ";
        for (int j = 0; j < graf[i].size(); j++)
        {
            cout << graf[i][j] << ", ";
        }
        cout << endl;
    }
}

void bfs(vector<vector<int>> &graf, int n, int start)
{
    cout << "BFS sorrend: ";
    queue<int> sor;
    sor.push(start);
    while (!sor.empty())
    {
        int u = sor.front();
        sor.pop();
        if (!visited[u]) // meg nem latogattuk meg
        {
            visited[u] = true;
            cout << u << " ";
            for (int i = 0; i < graf[u].size(); i++)
            {
                int csomopont = graf[u][i];
                if (!visited[csomopont])
                {
                    sor.push(csomopont);
                }
            }
        }
    }
    cout << endl;
}

void dijkstra(int graf[][N], int n, int start)
{
    for (int i = 0; i < n; i++)
    {
        v[i] = 0;       // nem dolgoztunk fel egyet sem
        p[i] = -1;      // nincs szulo
        d[i] = INT_MAX; // minden tavolsag vegtelen
    }
    d[start] = 0;

    for (int i = 0; i < n; i++)
    {
        int u = legkozelebbi(graf, n);
        // ha a legkozelebbi vegtelen tavolsagra van akkor azt jelenti, hogy kulon komponensben van
        if (u == -1)
            break;
        v[u] = true;
        // szomszedok tavolsaganak frissitese
        for (int j = 0; j < graf[u].size(); j++)
        {
            if (!v[j] && d[u] + graf[u][j] < d[j])
            {
                d[j] = d[u] + graf[u][j];
                p[j] = u;
            }
        }
    }
}

int main()
{
    int n = beOlvas("graf.txt", graf);
    kiIr(graf, n);
    bfs(graf, n, 0);
    return 0;
}