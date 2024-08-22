
const long long hashPow = 9973, hashMod = 1000000007;
// Se pueden usar otros valores hashmod puede ser hasta 10^18
vector<long long> rhash(const string &s, const long long P, const long long M) {
	int n = (int)s.size();
	vector<long long> rhash_S(n);
	for (int i = 0; i < n; i++) {
		if (i != 0) { rhash_S[i] = rhash_S[i - 1] * P % M; }
		rhash_S[i] = (rhash_S[i] + (long long)s[i]) % M;
	}
	return rhash_S;
}
