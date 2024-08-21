#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll N;
ll fib[MAXN];
map<ll,int> mp;
set<ll> failed;
bool dfs(ll cur)
{
    if(cur==1) return true;
    if(failed.count(cur)) return false;
    for(int i=71;i>=1;i--)
    {
        if(cur%fib[i]) continue;
        if(dfs(cur/fib[i])) {mp[cur]=i; return true;}
    }
    failed.insert(cur);
    return false;
}
vector<int> v;
int main()
{
   cin >> N;
    fib[1]=2;
    fib[2]=3;
    for(int i=3;i<=71;i++)
        fib[i]=fib[i-1]+fib[i-2];
    if(!dfs(N)) {puts("IMPOSSIBLE"); return 0;}
    while(N>1)
    {
        v.push_back(mp[N]);
        N/=fib[mp[N]];
    }
    sort(v.begin(),v.end(),greater<int>());
    for(auto x:v) 
    {
        for(int i=1;i<=x;i++) printf("A");
        printf("B");
    }
    puts("");
    return 0;
}