/**
 *	Opis: Zamortyzowane $O(n)$. Dodawanie do końca, usuwanie z przodu i podaj $\min$.
 */

struct minQue
{
	deque<pair<int, int> > q;
	int _size = 0;
	void push(int val) 
	{
		_size++;
		pair<int, int> nq = {val, 1};
		while(!q.empty() && q.back().first >= val) //zmienic na <= jezeli ma byc maxQue
		{
			nq.second += q.back().second;
			q.pop_back();
		}
		q.push_back(nq);
	}
	void pop()
	{
		_size--;
		assert(!q.empty());
		if(q.front().second > 1) q.front().second--;
		else q.pop_front();
	}
	int top()
	{
		return q.front().first;
	}
	int size()
	{
		return _size;
	}
};
