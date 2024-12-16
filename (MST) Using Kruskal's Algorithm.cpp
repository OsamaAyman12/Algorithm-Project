#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge
{
    int u, v, weight;
    bool operator<(const Edge &e) const
    {
        return weight < e.weight;
    }
};

class DisjointSet
{
public:
    vector<int> parent, rank;

    DisjointSet(int n)
    {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; ++i)
        {
            parent[i] = i; // Each vertex is initially its own parent
        }
    }

    int find(int u)
    {
        if (u != parent[u])
        {
            parent[u] = find(parent[u]); // Path compression
        }
        return parent[u];
    }

    void unionSet(int u, int v)
    {
        int root_u = find(u);
        int root_v = find(v);

        if (root_u != root_v)
        {
            // Union by rank
            if (rank[root_u] > rank[root_v])
            {
                parent[root_v] = root_u;
            }
            else if (rank[root_u] < rank[root_v])
            {
                parent[root_u] = root_v;
            }
            else
            {
                parent[root_v] = root_u;
                rank[root_u]++; // Increment rank if both have the same rank
            }
        }
    }
};

vector<Edge> kruskal(int V, vector<Edge> &edges)
{
    DisjointSet ds(V);
    vector<Edge> mst;

    // Sort edges by weight
    sort(edges.begin(), edges.end());

    for (const auto &edge : edges)
    {
        int u = edge.u, v = edge.v;

        if (ds.find(u) != ds.find(v))
        {
            mst.push_back(edge);
            ds.unionSet(u, v);
        }

        if (mst.size() == V - 1)
            break;
    }

    return mst;
}

// Helper function to print the MST
void printMST(const vector<Edge> &mst)
{
    int totalWeight = 0;
    for (const auto &edge : mst)
    {
        cout << "Edge: " << edge.u << " - " << edge.v << " | Weight: " << edge.weight << endl;
        totalWeight += edge.weight;
    }
    cout << "Total weight of MST: " << totalWeight << endl;
}

int main()
{
    int V = 4; // Number of vertices
    vector<Edge> edges = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}};

    vector<Edge> mst = kruskal(V, edges);

    cout << "Minimum Spanning Tree:" << endl;
    printMST(mst);

    return 0;
}
