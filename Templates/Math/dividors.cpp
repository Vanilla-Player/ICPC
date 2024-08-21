vector<int> Div;
void getDiv(int n) {
 Div.clear();
 for (int d = 1; d * d <= n; d++) {
 if (n%d == 0) {
 Div.push_back(d);
 Div.push_back(n/d);
 }
 if (d*d == n) Div.pop_back();
 }
 sort(D.begin(), D.end());
}