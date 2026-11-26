#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 20

struct Edge
{
    int u, v, w;
};

Edge edge[MAX];
int parent[MAX];

// Find Parent
int find(int x)
{
    while (parent[x] != x)
        x = parent[x];

    return x;
}

// Union of Sets
void Union(int a, int b)
{
    parent[a] = b;
}

// Compare edges by weight
bool compare(Edge a, Edge b)
{
    return a.w < b.w;
}

int main()
{
    int v, e;
    int totalCost = 0;

    cout << "Enter number of vertices: ";
    cin >> v;

    cout << "Enter number of edges: ";
    cin >> e;

    cout << "Enter Source Destination Weight:\n";

    for (int i = 0; i < e; i++)
    {
        cin >> edge[i].u
            >> edge[i].v
            >> edge[i].w;
    }

    // Initialize Parent
    for (int i = 0; i < v; i++)
        parent[i] = i;

    // Sort edges by weight
    sort(edge, edge + e, compare);

    cout << "\nEdges in Minimum Spanning Tree:\n";

    for (int i = 0; i < e; i++)
    {
        int p1 = find(edge[i].u);
        int p2 = find(edge[i].v);

        if (p1 != p2)
        {
            Union(p1, p2);

            cout << edge[i].u
                 << " --> "
                 << edge[i].v
                 << " Cost = "
                 << edge[i].w
                 << endl;

            totalCost += edge[i].w;
        }
    }

    cout << "\nMinimum Cost = " << totalCost << endl;

    return 0;
}
