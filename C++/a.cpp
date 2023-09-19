#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("avx2")
const char nl = '\n';
using namespace std;
using ll = long long;
using ld = long double;
const int N = 1 << 21;
const int M1 = (483 << 21)+1, R1 = 62;
const int M2 = (479 << 21)+1, R2 = 62;
const ll M = 1LL * M1 * M2;

ll egcd(ll a, ll b, ll& x, ll &y) { if (!b) {x=1; y=0; return a;}
  ll d = egcd(b, a%b, y, x); y -= x * (a/b); return d; }
ll X1, X2, d = egcd(M1, M2, X1, X2);
ll chin_rem(ll a1, ll a2) {
  ll A = (X1*a2%M2*M1 + X2*a1%M1*M2);
  A %= M;
  if (A < 0) A += M;
  return A;
}

ll modpow(ll x, ll e, ll mod) {
  ll ans = 1;
  for (; e; e /= 2, x = x*x%mod) {
    if (e%2) ans = ans*x%mod;
  }
  return ans;
}

using uint = unsigned int;
alignas(32) uint a[N];
alignas(32) uint b[N];

alignas(32) uint wdit[2][N];
alignas(32) uint wpdit[2][N];
template <ll M, ll R, bool dit = 0> void ntt(uint a[N]) {
  a = (uint*) __builtin_assume_aligned(a, 32);
  auto w = (uint*) __builtin_assume_aligned(wdit[dit], 32);
  auto wp = (uint*) __builtin_assume_aligned(wpdit[dit], 32);
  w[0] = w[1] = 1;
  wp[0] = wp[1] = (1LL << 32) / M;
  int n = N;
  //static vector<uint> w(2, 1), wp(2, (1LL << 32) / M); int n = a.size();
  for (static int k = 2; k < n; k *= 2) {
    w[k] = 1;
    ll c = modpow(R, M/2/k * (dit ? M-2 : 1), M);
    for (int i = k+1; i < 2*k; i++) w[i] = w[i-1]*c % M;
    for (int i = k; i < 2*k; i++) wp[i] = ((ll) w[i] << 32) / M; }
  for (int t = 1; t < n; t *= 2) {
    int k = (dit ? t : n/2/t);
    for (int i = 0; i < n; i += k*2) {
      for (int j = 0; j < k; j++) {
        uint X = a[i+j], Y = a[i+j+k], W = w[j+k], Wp = wp[j+k], T, Q;
        if (!dit) {
          if ((a[i+j] += Y) >= 2*M) a[i+j] -= 2*M;
          T = X - Y + 2*M;
          Q = ((unsigned long long) Wp * T) >> 32;
          a[i+j+k] = W*T - Q*M;
        } else {
          if (X >= 2*M) X -= 2*M;
          Q = ((unsigned long long) Wp * Y) >> 32;
          T = W*Y - Q*M;
          a[i+j] = X + T;
          a[i+j+k] = X - T + 2*M;
        }
      }
    }
  }
  for (int i = 0; i < N; i++) a[i] %= M;
}
template <ll M = (119<<23)+1, ll R = 62>
void conv(uint a[N], uint b[N]) {
  //if(a.empty() || b.empty()) return {};
  int len = N - 1, n = 1 << (32 - __builtin_clz(len));
  ll inv = modpow(n, M-2, M);
  ntt<M,R>(a); ntt<M,R>(b);
  for(int i=0; i<n; i++) a[i] = 1LL*a[i]*b[i] % M * inv % M;
  ntt<M,R,1>(a);
}

char get() {
  static char buf[1000000], *S = buf, *T = buf;
  if (S == T) {
    T = (S = buf) + fread(buf, 1, 1000000, stdin);
    if (S == T) return EOF;
  }
  return *S++;
}
void read(int& x) {
  static char c; x = 0;
  for (c = get(); c < '0'; c = get());
  for (; c >= '0'; c = get()) x = x * 10 + c - '0';
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, m; read(n); read(m);
  vector<int> p(n+1), q(m+1);
  for (int& i : p) read(i);
  for (int& i : q) read(i);
  copy(begin(p), end(p), a);
  copy(begin(q), end(q), b);
  conv<M1, R1>(a, b);
  vector<uint> ans1(n+m+1);
  copy(a, a+n+m+1, begin(ans1));
  memset(a, 0, sizeof a);
  memset(b, 0, sizeof b);
  copy(begin(p), end(p), a);
  copy(begin(q), end(q), b);
  conv<M2, R2>(a, b);
  vector<uint> ans2(n+m+1);
  copy(a, a+n+m+1, begin(ans2));
  ll out = 0;
  for (int i = 0; i <= n+m; i++) {
    out ^= chin_rem(ans1[i], ans2[i]);
  }
  cout << out << nl;
}
