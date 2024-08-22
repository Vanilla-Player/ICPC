vector<int> pi(const string &s) {
	int n = (int)s.size();
	vector<int> pi_s(n);
	for (int i = 1, j = 0; i < n; i++) {
		while (j > 0 && s[j] != s[i]) { j = pi_s[j - 1]; }
		if (s[i] == s[j]) { j++; }
		pi_s[i] = j;
	}
	return pi_s;
}