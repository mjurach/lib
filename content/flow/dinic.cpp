/**
 * 	Opis: $O(V^2E)$, chyba że mamy sieć jednostkową (max flow na krawędzi to 1) to $O(E \sqrt{V})$.
 */

const int INF = numeric_limits<int>::max();
struct flowEdge
{
	int u, v, cap, flow;
	flowEdge(int _u, int _v, int _cap, int _flow){u = _u; v = _v; cap = _cap; flow = _flow;}
	flowEdge(){}
};
struct dinic
{
	vector<flowEdge> edges;
	vector<vector<int> > idx;
	queue<int> q;
	vector<int> lvl;
	vector<int> ptr;
	int n, m;
	dinic(int _n, int _m, vector<pair<pair<int, int>, int> >& _edges) //krawedzie musza byc znormalizowane do DG
	{
		n = _n; m = _m;
		idx.resize(n+1);
		lvl.resize(n+1);
		ptr.resize(n+1);
		for(auto v : _edges)
		{
			edges.push_back(flowEdge(v.first.first, v.first.second, v.second, 0));
			edges.push_back(flowEdge(v.first.second, v.first.first, 0, 0));
			idx[v.first.first].push_back(edges.size()-2);
			idx[v.first.second].push_back(edges.size()-1);
		}
	}
	bool bfs()
	{
		fill(lvl.begin(), lvl.end(), -1);
		q.push(0);
		lvl[0] = 0;
		while(!q.empty())
		{
			int a = q.front();
			q.pop();
			for(auto v : idx[a])
			{
				if(lvl[edges[v].v] != -1) continue;
				if(edges[v].cap - edges[v].flow < 1) continue;
				lvl[edges[v].v] = lvl[a]+1;
				q.push(edges[v].v);
			}
		}
		return lvl[n] != -1;
	}
	int dfs(int v, int aktmin)
	{
		if(v == n) return aktmin;
		if(aktmin == 0) return aktmin;
		for(int& i = ptr[v];i<idx[v].size();i++)
		{
			int id = idx[v][i];
			int nv = edges[id].v;
			if(lvl[v] + 1 != lvl[nv] || edges[id].cap - edges[id].flow < 1) continue;
			long long bFlow = dfs(nv, min(aktmin, edges[id].cap - edges[id].flow));
			if(bFlow == 0) continue;
			edges[id].flow += bFlow;
			edges[id^1].flow -= bFlow;
			return bFlow;
		}
		return 0;
	}
	int maxFlow()
	{
		int res = 0;
		while(true)
		{
			if(!bfs()) break;
			fill(ptr.begin(), ptr.end(), 0);
			while(int flow = dfs(0, INF)) res += flow;
		}
		return res;
	}
};
