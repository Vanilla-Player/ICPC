vector<int> z(const string &s) {
	int n = (int)s.size();
	vector<int> z_S(n);
	for (int i = 1, l = 0, r = 0; i < n; i++) {
		if (i <= r) { z_S[i] = min(z_S[i - l], r - i + 1); }
		while (i + z_S[i] < n && s[z_S[i]] == s[i + z_S[i]]) { z_S[i]++; }
		if (i + z_S[i] - 1 > r) {
			l = i;
			r = i + z_S[i] - 1;
		}
	}
	return z_S;
}