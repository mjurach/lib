/**
 * 	Opis: W $O(nm)$ oblicza tablice $\mathbf{D}$ z odległościami od $s$ w grafie skierowanym ważonym (dopuszczane ujemne wagi).
 *		  Po obliczeniu odległości \texttt{isNegCyc()} zwraca czy w grafie jest ujemny cykl.
 */

const int INF = numeric_limits<int>::max();
struct edge 
{
	int a, b, cost;
	edge(int _a, int _b, int _cost){a = _a; b = _b; cost = _cost;}
};
struct Bellman_Ford
{
	int n;
	vector<edge> edges;
	vector<int> D;
	bool makeStep()
	{
		bool e = 0;
		for(auto v : edges)
			if(D[v.a] != INF)
				if(D[v.b] > D[v.a] + v.cost)
					D[v.b] = D[v.a] + v.cost, e = true;
		return e;
	}
	Bellman_Ford(int _n, vector<edge>& _edges, int s)
	{	
		n = _n; edges = _edges;
		D.resize(n+1, INF);
		D[s] = 0;
		while(_n-->1) makeStep();
	}
	bool isNegCyc()
	{
		return makeStep();
	}
};
