#include <bits/stdc++.h>
using namespace std;

class DSU
{
private:
    vector<int> parent, size, rank;

public:
    DSU(int n)
    {
        for (int i = 0; i < n; i++)
        {
            parent.push_back(i);
            size.push_back(1);
            rank.push_back(1);
        }
    }

public:
    int findParent(int node)
    {
        if (node == parent[node])
            return node;
        return findParent(parent[node]);
    }

public:
    void Union_by_size(int u, int v)
    {
        int parent_of_u = findParent(u);
        int parent_of_v = findParent(v);

        if (parent_of_u == parent_of_v)
        {
            return;
        }

        if (size[parent_of_u] < size[parent_of_v])
        {
            parent[parent_of_u] = parent_of_v;
            size[parent_of_v] += size[parent_of_u];
        }
        else
        {
            parent[parent_of_v] = parent_of_u;
            size[parent_of_u] += size[parent_of_v];
        }
    }

public:
    void Union_by_rank(int u, int v)
    {
        int parent_of_u = findParent(u);
        int parent_of_v = findParent(v);

        if (parent_of_u == parent_of_v)
        {
            return;
        }
        if (rank[parent_of_u] == rank[parent_of_v])
        {
            parent[parent_of_u] = parent_of_v;
            rank[parent_of_v]++;
        }
        else if (rank[parent_of_u] < rank[parent_of_v])
        {
            parent[parent_of_u] = parent_of_v;
        }
        else
        {
            parent[parent_of_v] = parent_of_u;
        }
    }
};

void roads_in_berlin()
{
    int n;
    cin >> n;
    vector<pair<int, int>> oldRoads;
    DSU dsu(n+2);

    for (int i = 1; i <= n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        // if their parents are equal , then dont connect them, this was our old road
        if (dsu.findParent(u) != dsu.findParent(v))
        {
            dsu.Union_by_rank(u, v);
        }
        else
        {

            oldRoads.push_back({u, v});
        }
    }

    // mumber of road required to connect cities = number of components of graph - 1 = jitne parent utne componet
    set<int> st;
    for (int i = 1; i <= n; i++)
    {
        st.insert(dsu.findParent(i));
    }

    int newRoads = st.size() - 1;
    int j = 0;
    vector<int> connectRoads(st.begin(), st.end());
    cout << newRoads << endl;
    for (int i = 1; i <= newRoads; i++)
    {
        cout << oldRoads[j].first << " " << oldRoads[j].second << " " << connectRoads[i] << " " << connectRoads[i - 1] << endl;
        j++;
    }
}

int main()
{
    roads_in_berlin();
    return 0;
}