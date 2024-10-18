/**
 *	Opis: $O(n \log n)$. Zwraca długość najdłuższego podciągu rosnącego.
 */

int LIS(vector<int> A) 
{
	vector<int> vec;
	for(auto& v : A)
		if(vec.size() == 0 || v > vec.back()) 
			vec.push_back(v);
		else
			*lower_bound(vec.begin(), vec.end(), v) = v;
	return vec.size();
}
