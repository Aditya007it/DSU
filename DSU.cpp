class Solution {
public:
    class DSU{
    private:
        vector<int> parent, size, rank;
    
    public:
        DSU(int n)
        {
            for(int i=0; i<n; i++)
            {
                parent.push_back(i);
                size.push_back(1);                
                rank.push_back(1);                
            }
        }
    public:
        int findParent(int node)
        {
            if(node == parent[node]) return node;
            return findParent(parent[node]);
        }
    public:
        void Union_by_size(int u, int v)
        {
            int parent_of_u = findParent(u);
            int parent_of_v = findParent(v);

            if(parent_of_u == parent_of_v)
            {
                return;
            }

            if(size[parent_of_u] < size[parent_of_v])
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

            if(parent_of_u == parent_of_v)
            {
                return;
            }
            if(rank[parent_of_u]==rank[parent_of_v])
            {
                parent[parent_of_u] = parent_of_v;
                rank[parent_of_v]++;
            }
            else if(rank[parent_of_u] < rank[parent_of_v])
            {
                parent[parent_of_u] = parent_of_v;
            }
            else{
                parent[parent_of_v] = parent_of_u;
            }
        }
    
};