#include <bits/stdc++.h>
using namespace std;
class DSU{	
	private: vector<int> parent, size;
	public:
		DSU(int v) {
			for(int i=0; i<v; i++) {
				parent.push_back(i);
				size.push_back(1);
			}
		}
		
		int findparent(int node) {
			if(node == parent[node]) return node;
		
			return findparent(parent[node]);
		}

		void unionSize(int u, int v) {
			int pu = findparent(u);
			int pv = findparent(v);
			if(pu == pv) return;
			if(size[pu] < size[pv]) {
				parent[pu] = pv;
				size[pv] += size[pu];
				size[pu] = 0;
			}
			else {
				parent[pv] = pu;
				size[pu] += size[pv];
				size[pv] = 0;
			}
		}

		void addsize(int n, vector<int> &ans) {
			for(int i=1; i<=n; i++) {
				if(size[i] > 0) {
					ans.push_back(size[i]);
				}
			}
		}
};


void countComponenets() {
	int n,m;
	cin>>n>>m;
	DSU log(n+1);
	for(int i=0; i<m; i++) {
		int u,v;
		cin>>u>>v;

		if(log.findparent(u) != log.findparent(v)) {
			log.unionSize(u,v);
		}
		vector<int> ans;
		log.addsize(n,ans);
		sort(ans.begin(), ans.end());
		for(auto it : ans) {
			cout<<it<<" ";
		}
		cout<<endl;	
	}
}
int main() {
	countComponenets();
	return 0;
}