#include<bits/stdc++.h>
class DSU {
private: vector<int> parent, size;
public:
    DSU(int vertex) {
        for(int i=0; i<vertex; i++) {
            parent.push_back(i);
            size.push_back(1);
//             rank.push_back(0);
        }
    }
    
public:
    int findParent(int node) {
        if(node == parent[node]) {
            return node;
        }
        return findParent(parent[node]);
    }
public:
    void unionSize(int u, int v) {
        int pu = findParent(u);
        int pv = findParent(v);
        if(pu == pv) return;
        
        if(size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }    
};

static bool comp(vector<int> &a, vector<int> &b) {
    return a[2] < b[2];
}
int kruskalMST(int n, int m, vector<vector<int>> &graph) {
	// Write your code here.
    int weight = 0;
    DSU krus(n+1);
    
    sort(graph.begin(), graph.end(), comp);
    for(auto &it : graph) {
        int u = it[0];
        int v = it[1];
        if(krus.findParent(u) != krus.findParent(v)) {
            krus.unionSize(u,v);
            weight += it[2];
        }
        
    }
    return weight;
}