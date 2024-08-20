#include <bits/stdc++.h>
using namespace std;


const int MAXN = 100010;
const int MOD = 998244353;
char str[MAXN];
long long F[MAXN], rF[MAXN], INV[MAXN];
long long inv(long long a, long long m) {
	if (a == 1) return 1;
	return inv(m%a, m) * (m - m/a) % m;
}
int main() {
	int T;
	int n;
	F[0] = rF[0] = 1;
    INV[1] = 1;
    for (int i = 2; i < MAXN; i++) {
		INV[i] = MOD - (long long)(MOD/i)*INV[MOD%i]%MOD; // Se usa el MOD - PORQUE -X = (MOD-X) EN ARITMETICA MODULAR
	}
	for (int i = 1; i < MAXN; i++) {
		F[i] = F[i-1] * i % MOD;
		rF[i] = rF[i-1] * INV[i] % MOD;
	}
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		scanf("%s", str);
		int cg = 0;
		int c0 = 0;
		for (int i = 0; i < n; i++) {
			if (str[i] == '0') {
				c0++;
			} else if (i+1 < n && str[i+1] == '1') {
				cg++;
				i++;
			}
		}
		long long ans = F[cg + c0] * rF[c0] % MOD * rF[cg] % MOD;
		printf("%d\n", (int) ans);
	}
	return 0;
}