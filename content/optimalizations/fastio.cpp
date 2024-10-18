/**
 * Opis: fastio.
*/

inline void SuckInt(int *n){
	register char c=0;
	register int r=1;
	(*n)=0;
	while (c<33) c=getc_unlocked(stdin);
	if (c==45)
		r=-1, c=getc_unlocked(stdin);
	while (c>32)
		(*n)=(*n)*10+c-48, c=getc_unlocked(stdin);
	(*n)*=r;
}
inline void SuckLong(long long *n){
	register char c=0;
	register int r=1;
	(*n)=0;
	while (c<33) c=getc_unlocked(stdin);
	if (c==45)
		r=-1, c=getc_unlocked(stdin);
	while (c>32)
		(*n)=(*n)*10+c-48, c=getc_unlocked(stdin);
	(*n)*=r;
}
inline void ThrowSlow(string s){
	for (auto i: s)
		putc_unlocked(i, stdout);
}
inline void Throw(int n, bool f=true){
	if (n<0 && f) putc_unlocked('-', stdout), n*=-1;
	if (n==0 && f) putc_unlocked('0', stdout);
	if (n==0) return;
	Throw(n/10, 0);
	putc_unlocked(n%10+'0', stdout);
}
