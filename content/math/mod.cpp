/**
 * Opis: operacje $\mod 998244353$. 
*/

const int mod = 998244353;

int add(int a, int b) {
	a += b;
	return a >= mod ? a-mod : a;
}

int sub(int a, int b) {
	return add(a, mod-b);
}

int mul(int a, int b) {
	return int(((ll)a*b)%mod);
}

int fpow(int a, int b) {
	int res = 1;
	while (b) {
		if (b&1) {
			res = mul(a, res); 
			b--;
		}
		a = mul(a, a);
		b /= 2;
	}
	return res;
}

int inv(int x) {
	return fpow(x, mod-2);
}
