#include <algorithm>
#include <iostream>
#include <vector>

using ll = long long;
ll mpow(ll n, ll e) {
	if (e == 0) return 1;
	return mpow(n * n, e / 2) * (e & 1 ? n : 1);
}
// sqrt(-1) exists or not
inline bool sqrtm1Exists(ll p) {
	return !(p % 4 == 3);
}

// sqrt(2) exists or not for odd prime
inline bool sqrt2Exists(ll p) {
	ll k = p / 4;
	if (p % 4 == 1) {
		return k % 2 == 0;
	}
	else if (p % 4 == 3) {
		return k % 2 == 1;
	}
	return true;
}

//# (x,y,z) where x^2+y^2==z^2 (mod p^e) and 0<=x,y,z<p^e
ll calc_all(ll p, ll e) {
	ll ans = e & 1 ? p * p : 1;
	ll tmp = e & 1 ? mpow(p, 6) : mpow(p, 4);
	if (p != 2) tmp -= tmp / ::mpow(p, 2); //for odd prime

	for (ll i = (e & 1); i != e; i += 2) {
		ans *= p * p * p;
		ans += tmp;
		tmp *= p * p * p * p;
	}
	return ans;
}

//# (z) where 0==z^2 (mod p^e) and 0<=z<p^e
ll calc_twozero1(ll p, ll e) {
	return mpow(p, e / 2);
}

//# (x) where 2x^2==0 (mod p^e) and 0<=x<p^e
ll calc_twozero2(ll p, ll e) {
	return p != 2 ? mpow(p, e / 2) : calc_twozero1(p, e - 1) * p;
}

//# (y,z) where y^2==z^2 (mod p^e) and 0<=y,z<p^e
ll calc_onezero1(ll p, ll e) {
	if (p == 2) return mpow(p, e) * e;
	int ee = (e + 1) / 2;
	return mpow(p, 2 * (e - ee)) + 2 * mpow(p, e - 1) * (p - 1) * ee;
}

//# (x,y) where x^2+y^2==0 (mod p^e) and 0<=x,y<p^e
ll calc_onezero2(ll p, ll e) {
	if (p == 2) return mpow(p, e);
	if(!sqrtm1Exists(p)) return mpow(p, 2 * (e / 2));
	int ee = (e + 1) / 2;
	return 2 * mpow(p, e - 1) * (p - 1) * ee + mpow(p, 2 * (e / 2));
}

ll calc_threezero(ll p, ll e) {
	return 1;
}

//# (y,z) where 2*y^2==z^2 (mod p^e) and 0<=y,z<p^e
ll calc_same(ll p, ll e) {
	if (p == 2) return mpow(p, e);
	if (sqrt2Exists(p)) return calc_onezero1(p, e);
	return mpow(p, 2 * (e / 2));
}

void tryAtPrime(int & n, int p, ll& all, ll& one1, ll& one2, ll& two1, ll& two2, ll& same) {
	int e = 0;
	while (!(n % p)) {
		e++; n /= p;
	}
	if (e == 0) return;
	all *= calc_all(p, e);
	one1 *= calc_onezero1(p, e);
	one2 *= calc_onezero2(p, e);
	two1 *= calc_twozero1(p, e);
	two2 *= calc_twozero2(p, e);
	same *= calc_same(p, e);
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0); std::cout.tie(0);

	int n;
	ll all = 1, one1 = 1, one2 = 1, two1 = 1, two2 = 1, same = 1;
	std::cin >> n;

	for (int p : {2, 3}) tryAtPrime(n, p, all, one1, one2, two1, two2, same);
	for (int i = 6;; i += 6) {
		tryAtPrime(n, i-1, all, one1, one2, two1, two2, same);
		tryAtPrime(n, i+1, all, one1, one2, two1, two2, same);
		if ((i+1)*(i+1) > n) break;
	}
	if (n != 1) {
		tryAtPrime(n, n, all, one1, one2, two1, two2, same);
	}
	ll zero = 2*one1 + one2 - 3 * two1 + 1;
	ll nzsame = same - two1 - two2 + 1;
	ll ans = (all - zero + nzsame) / 2;

	std::cout << ans << '\n';
	return 0;
}
