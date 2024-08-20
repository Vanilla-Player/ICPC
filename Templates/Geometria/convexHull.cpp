vector<pt> upper_hull(vector<pt> &v){
    vector<pt> uh;
    for (int i = 0; i < v.size(); i++)
    {
        while(uh.size() >= 2 && ((uh.back() - uh[uh.size()-2]) & (uh.back() - v[i])) < 0){
            int val = (uh.back() - uh[uh.size()-2]) & (uh.back() - v[i]);
            uh.pop_back();
        }  
        uh.push_back(v[i]);
    }
    return uh;
}

sort(v.begin(), v.end(), 
     [] (const pt &a, const pt &b) {
            return (a.x == b.x) ? (a.y < b.y) : (a.x < b.x); // Ordeno por menor Y
    });
vector<pt> v1 = upper_hull(v);
sort(v.begin(), v.end(), 
     [] (const pt &a, const pt &b) {
            return (a.x == b.x) ? (a.y > b.y) : (a.x > b.x); // Ordeno por mayor Y
    });
vector<pt> v2 = upper_hull(v);

// Para mergear ambos 
for (int i = 1; i < v2.size() - 1; i++) { // Salteo el primero y el ultimo
    v1.push_back(v2[i]);
}   