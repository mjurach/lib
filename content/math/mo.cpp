/**
 *	Opis: $O(1)$. Sort do MO. Sortuje przedzialy $[a.x, a.y]$.
 */

const int k = 500;
sort(events.begin(), events.end(), [&](type a, type b){
		if(a.x/k < b.x/k) return true;
		if(a.x/k > b.x/k) return false;
		if((a.x/k)%2 == 1)
		return a.y < b.y;
		else
		return a.y > b.y;
	});
