#include<bits/stdc++.h>

using namespace std;
typedef long long ll;



int b,l,d[MAXN];
int main()
{
    cin << b << l;
    for(int i=1;i<=l;i++) scanf("%d",&d[i]);
    int mod=0,p=b;

    for(int i=l;i>=1;i--)
    {
        mod=(mod+1LL*d[i]*p)%(b+1); // d[i]*b^(par) % (b+1) = d[i]
        p=b+1-p;// d[i]*b^(impar) % (b+1) = d[i]*b % (b+1) = b + 1 - d
        // hace variar el valor entre b y 1
    }

    if(mod==0) {cout << "0 0" << endl; return 0;}

    
    for(int i=1;i<=l;i++)
    {
        if((l-i)&1)
        {
            if(d[i]-mod>=0)
            {
                cout << i << " " << d[i]-mod << endl;
                return 0;
            }
        }
        else 
        {
            if(d[i]-(b+1-mod)>=0)
            {
                cout << i << " " << d[i] - (b+1-mod) << endl;
                return 0;
            }
        }
    }
    puts("-1 -1");
    return 0;
}