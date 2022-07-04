class Solution {
public:
    class DSU {
    private: vector<int> parent, size, rank;
    public:
        DSU(int vertex){
            for(int i=0; i<vertex; i++) {
                parent.push_back(i);
                size.push_back(1);
                rank.push_back(0);
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
            if(pu == pv) return ;
            
            if(size[pu] < size[pv]) {
                parent[pu] = pv;
                size[pv] += size[pu];
            }
            else {
                parent[pv] = pu;
                size[pu] += size[pv];
            }
        }
        
    public:
        void unionRank(int u, int v) {
            int pu = findParent(u);
            int pv = findParent(v);
            if(pu == pv) return ;
            
            if(rank[pu] == rank[pv]) {
                parent[pu] = pv;
                rank[pv]++;
            }
            else if(rank[pu] < rank[pv]) {
                parent[pu] = pv;
            }
            else {
                parent[pv] = pu;
            }
        }
    public:
        bool isParentIsSame(int u, int v) {
            if(findParent(u) == findParent(v)) return true;
            return false;
        }
        
        
            
    };
    vector<bool> friendRequests(int n, vector<vector<int>>& restrictions, vector<vector<int>>& requests) {
        vector<bool> ans;
        DSU friends(n);
        
        for(auto &it : requests) {
            int u = it[0];
            int v = it[1];
            bool temp = true;
            for(auto &j : restrictions ) {
                if(friends.isParentIsSame(u,j[0]) && friends.isParentIsSame(v,j[1])) {
                    temp = false;
                    break;
                }
                else if(friends.isParentIsSame(u,j[1]) && friends.isParentIsSame(v,j[0])) {
                    temp = false;
                    break;
                }
            }
            
            ans.push_back(temp);
            if(temp == true) {
                friends.unionSize(u,v);
            }
            
        }
        return ans;
    }
};