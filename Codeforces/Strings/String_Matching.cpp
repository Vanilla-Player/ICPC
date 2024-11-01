#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
#define fori(i,n) for(int i = 0; i < (n); i++)
#define fora(i,a,n) for(int i = (a); i <= (n); i++)
#define ford(i,a,n) for(int i = a; i >= 0; i--)
#define dprint(v) cout << #v"=" << v << endl //;)
// First We will aplicate Z alg, look easier
// g++ -std=c++11 -O2 -Wall test.cpp -o test

// Computes the Z-array of s
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

// vector<int> z(string s) {
// int n = s.size();
// vector<int> z(n);
// int x = 0, y = 0;
// for (int i = 1; i < n; i++) {
//     cout << "VARIABLES"  << endl;
//     dprint(i);
//     dprint(x);
//     dprint(y);
//     dprint(z[i]);
//     dprint(y);
//     z[i] = max(0,min(z[i-x],y-i+1));
//     while (i+z[i] < n && s[z[i]] == s[i+z[i]]) {
//     cout << "Encontro Parecido" << endl;
//     dprint(i);
//     dprint(z[i]);
//     x = i; y = i+z[i]; z[i]++;
//     }   
// }
// return z;
// }

// int main(){
//     string s, p;
//     cin >> s >> p;

//     s = s + '#' + p;
//     // cout << s << " " << p << endl;
//     vector<int>z_array = z(s);
//     // int z_size = z_array.size();
//     // How can i check??
//     // s[i] == p[0] z[i] =? p.size()
//     int ans = 0;
//     int p_size = p.size();
//     for (int l : z_array) {
// 		if (l == p_size) { ans++; }
//         cout << l << " ";
// 	}
//     cout << endl;
// 	cout << ans << '\n';

// }


// ### SOLUTION WITH KMP
#include <bits/stdc++.h>
using namespace std;

// namespace str {
// /** Computes the Pi array of s. */
// vector<int> pi(const string &s) {
// 	int n = (int)s.size();
// 	vector<int> pi_s(n);
// 	for (int i = 1, j = 0; i < n; i++) {
// 		while (j > 0 && s[j] != s[i]) { j = pi_s[j - 1]; }
// 		if (s[i] == s[j]) { j++; }
// 		pi_s[i] = j;
// 	}
// 	return pi_s;
// }
// }  // namespace str
// int main() {
// 	string P, T;
// 	cin >> T >> P;
// 	vector<int> Thash = rhash(T,hashPow, hashMod);
// 	vector<int> Phash = rhash(P,hashPow, hashMod);
// 	string S = P + '#' + T;
// 	vector<int> pi = str::pi(S);
// 	int ans = 0;
//     int P_size = P.size();
// 	for (int l : pi) {
// 		if (l == P_size) { ans++; }
//         cout << l << " " << endl;
// 	}
// 	cout << ans << '\n';
// }   

const long long hashPow = 911382323, hashMod = 972663749;
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

int main() {
	string P, T;
	cin >> T >> P; 
	vector<ll> Thash = rhash(T,hashPow, hashMod);
	vector<ll> Phash = rhash(P,hashPow, hashMod);
	ll p_size = P.size();
	ll t_size = T.size();
	// cout << T << endl;
	ll ppow = 1;
	for(int i = 0 ; i < p_size;i++){ppow = (ppow * hashPow)%hashMod;}
	ll ans = 0;
	for( ll i = 0; i + p_size - 1 < t_size; i++ ){
		ll r = Thash[i + p_size - 1];
		ll l = i == 0? 0 :(Thash[i - 1] * ppow % hashMod);
		ll curHash = (r - l + hashMod ) % hashMod;
		if(curHash == Phash.back()){
			ans++;

		}

	}
	cout << ans << '\n';
}   

