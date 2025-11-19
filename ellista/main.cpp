#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

struct Edge
{
    int from = -1;
    int to = -1;
    int weight = -1;
    Edge() {}
    Edge(int from, int to, int weight)
    {
        this->from = from;
        this->to = to;
        this->weight = weight;
    }
};

Edge edges[100];
int edge_count, node_count;

int beOlvas(string fileName, Edge edges[])
{
    ifstream f(fileName);
    int n = 0; // csomopontok szama
    int i = 0;
    f >> n;

    int to, from, weight;
    while (f && f >> from >> to >> weight)
    {
        edges[i] = Edge(from, to, weight);
        i++;
    }
    edge_count = i;
    node_count = n;
    return n;
}
// Kiirja a graf adjacencia(szomszedsagi) matrixat
void kiIr(Edge edges[], int edge_count)
{
    cout << "Ellista:" << endl;
    for (int i = 0; i < edge_count; i++)
    {
        cout << edges[i].from << " " << edges[i].to << " " << edges[i].weight << endl;
    }
}

void custom_sort(Edge edges[], int edge_count)
{
    for (int i = 0; i < edge_count; i++)
    {
        int min_index = i;
        for (int j = i + 1; j < edge_count; j++)
        {
            if (edges[min_index].weight > edges[j].weight)
            {
                min_index = j;
            }
        }
        Edge tmp = edges[i];
        edges[i] = edges[min_index];
        edges[min_index] = tmp;
    }
}

void KruskalAlg(Edge edges[], int edge_count, int node_count)
{
    int komp[node_count];
    int osszeg = 0, edge_db = 0;
    for (int i = 0; i < node_count; i++)
    {
        komp[i] = i;
    }
    custom_sort(edges, edge_count);
    for (int i = 0; i < edge_count && edge_db < node_count - 1; i++)
    {
        int komp_from = edges[i].from, komp_to = edges[i].to, komp_weight = edges[i].weight;
        if (komp[komp_from] != komp[komp_to])
        {
            osszeg += edges[i].weight;
            edge_db++;
            for (int j = 0; j < node_count; j++)
            {
                if (komp[j] == komp[komp_to])
                {
                    komp[j] = komp[komp_from];
                }
            }
        }
    }
    cout << "osszeg:" << osszeg << " db:" << edge_db;
}

int main()
{
    beOlvas("graf.txt", edges);
    kiIr(edges, edge_count);
    // sort(edges, edges + edge_count, [](Edge &e1, Edge &e2)
    //      { return e1.weight < e2.weight; });

    KruskalAlg(edges, edge_count, node_count);
    return 0;
}