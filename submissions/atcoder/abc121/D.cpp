#include <bits/stdc++.h>
#define ll long long
#define get(a) int a; cin>>a;
#define getl(a) long long a; cin>>a;
#define put(a) cout<<a<<" ";
#define putn(a) cout<<a<<"\n";
#define rep(i,k,n) for(int i=k; i<n; i++)
#define repl(i,k,n) for(long long i=k; i<n; i++)
#define vec vector<int>
#define vecl vector<long long>
#define init(a,n) vector<int> a(n); for(int i=0; i<n; i++) { cin>>a[i]; }
#define initl(a,n) vector<long long> a(n); for(int i=0; i<n; i++) { cin>>a[i]; }
#define logarr(a) for(auto i:a) { cout<<i<<" "; } cout<<"\n"; 
#define all(x) x.begin(), x.end()
#define pairii pair<int,int>
#define mod 1000000007
#define pb emplace_back
#define pf first
#define ps second
using namespace std;

ll x(ll n)
{
	if(n%4 == 1)
	{
		return 1;
	}
	else if(n%4 == 2)
	{
		return n+1;
	}
	else if(n%4 == 3)
	{
		return 0;
	}
	else
	{
		return n; 
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	getl(a) getl(b)
    ll res=0;
    if(a==0)
    {
      res=x(b);
    }
    else
    {
      res=x(b) ^ x(a-1);
    }
	putn(res)
	return 0;
}