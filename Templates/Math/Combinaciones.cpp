
const int MAXN = 100010;
const int MOD = 998244353;
long long F[MAXN], rF[MAXN], INV[MAXN];  // rF[x] = (x!)^(-1) o sea 1 / (x!)^(-1) F[x] = x!
long long inv(long long a, long long m) {
	if (a == 1) return 1;
	return inv(m%a, m) * (m - m/a) % m;
}

F[0] = rF[0] = 1;
INV[1] = 1;
for (int i = 2; i < MAXN; i++) {
	INV[i] = MOD - (long long)(MOD/i)*INV[MOD%i]%MOD; // Se usa el MOD - PORQUE -X = (MOD-X) EN ARITMETICA MODULAR
}
for (int i = 1; i < MAXN; i++) { // Factoriales
	F[i] = F[i-1] * i % MOD;
	rF[i] = rF[i-1] * INV[i] % MOD;
}

// Ejemplo de uso Combinaciones (n+k) = n+k!        (n) = n!
//                              (k)     k!(n+k)-k!  (k)   k!n-k!
long long ans = F[cg + c0] * rF[c0] % MOD * rF[cg] % MOD; 
// Acordate del mod tio

