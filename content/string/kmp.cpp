/**
 *	Opis: $O(n + m)$. Constructor przyjmuje wzorzec i tekst, oblicza vector indeksów 
 *		 wystąpień wzorca w tekście.
 */

struct KMP{
	string s;
	vector<int>pi;
	vector<int>ans;
	KMP(string &a,string &b):s(a+'#'+b){
		prefsuf();
		for(int i=ssize(a);i<ssize(s);i++){
			if(pi[i]==ssize(a))ans.push_back(i-2*ssize(a));
		}
	}
	void prefsuf(){
		int n=ssize(s);
		pi.resize(n,0);
		for(int i=1;i<n;i++){
			int j=pi[i-1];
			while(j>0&&s[i]!=s[j])j=pi[j-1];
			pi[i]=j+(s[i]==s[j]);
		}
	}
};
