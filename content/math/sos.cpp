/**
 * 	Opis: $O(l \cdot 2^l)$. Zwraca $\mathbf{sos}[mask]$ równe sumie $\mathbf{s}[m]$ po podzbiorach $mask$.
 */

vector<int> SOS(int l, vector<int>& s)
{
	vector<int> sos(1<<l);
	for(int mask = 0;mask<(1<<l);mask++)
		sos[mask] = s[mask];
	for(int i=0;i<l;i++)
		for(int mask=0;mask<(1<<l);mask++)
			if((mask & (1<<i)) != 0)
					sos[mask] += sos[mask^(1<<i)];

	return sos;
}
