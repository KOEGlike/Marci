#include <iostream>
#include <fstream>
using namespace std;

struct edge
{
    int from;
    int to;
    int weight;
    edge() {}
    edge(int from, int to, int weight)
    {
        this->from = from;
        this->to = to;
        this->weight = weight;
    }
};

edge edges[100];
int edge_count;

int beOlvas(string fileName, edge edges[])
{
    ifstream f(fileName);
    int n = 0; // csomopontok szama
    int i = 0;
    f >> n;

    int to, from, weight;
    while (f && f >> from >> to >> weight)
    {
        edges[i].from = from;
        edges[i].to = to;
        edges[i].weight = weight;
        i++;
    }
    edge_count = i;
    return n;
}
// Kiirja a graf adjacencia(szomszedsagi) matrixat
void kiIr(edge edges[], int edge_count)
{
    cout << "Ellista:" << endl;
    for (int i = 0; i < edge_count; i++)
    {
        cout << edges[i].from << " " << edges[i].to << " " << edges[i].weight << endl;
    }
}

int main()
{
    beOlvas("graf.txt", edges);
    kiIr(edges, edge_count);

    return 0;
}