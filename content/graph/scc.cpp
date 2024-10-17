/**
 *  Opis: silnie spójne składowe. Argument do constructora to graf skierowany w postaci \texttt{vector<vector<int>> v}. 
 *		  Oblicza vector indeksów spójnie składowej do której należy $v$ o nazwie \texttt{scc}.
 * 		  Czas, pamiec $O(n+m)$.
 */

struct SCC{
	vector<vector<int>>v,x;
	int n;
	queue<int>q;
	vector<bool>vis;
	int kt=0;
	vector<int>scc;
	SCC(const vector<vector<int>>&vv):v(vv),n(ssize(vv)){
		vis.resize(n,0);
		scc.resize(n);
		for(int i=0;i<n;i++){
			if(!vis[i])dfs0(i);
		}
		make_x();
		fill(all(vis),0);
		while(!q.empty()){
			if(!vis[q.front()]){
				dfs1(q.front());
				kt++;
			}
			q.pop();
		}
	}
	void dfs0(int a){
		vis[a]=1;
		for(auto b:v[a]){
			if(!vis[b])dfs0(b);
		}
		q.push(a);
	}
	void make_x(){
		x.resize(n);
		for(int i=0;i<ssize(v);i++){
			for(auto b:v[i]){
				x[b].push_back(i);
			}
		}
	}
	void dfs1(int a){
		vis[a]=1;
		scc[a]=kt;
		for(auto b:v[a]){
			if(!vis[b])dfs1(b);
		}
	}
};
