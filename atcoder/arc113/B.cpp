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

long long expm(long long a, long long b, long long m=mod)
{
	long long res=1;
	while(b)
	{
		if(b & 1) { res=((res % m) * (a % m)) % m; }
		b/=2;
		a=((a % m) * (a % m)) % m;
	}
	return res;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	getl(a) getl(b) getl(c)
	int dig=a%10;
	ll val;
	switch(dig)
	{
		case 0:
			putn(0)
			break;
		case 1:
			putn(1)
			break;
		case 2:
			val=expm(b,c,4);
			if(val == 0)
			{
				putn(6)
			}
			else if(val == 1)
			{
				putn(2)
			}
			else if(val == 2)
			{
				putn(4)
			}
			else{
				putn(8)
			}
			break;
		case 3:
			val=expm(b,c,4);
			if(val == 0)
			{
				putn(1)
			}
			else if(val == 1)
			{
				putn(3)
			}
			else if(val == 2)
			{
				putn(9)
			}
			else{
				putn(7)
			}
			break;
		case 4:
			val=expm(b,c,2);
			if(val & 1)
			{
				putn(4)
			}
			else
			{
				putn(6)
			}
			break;
		case 5:
			putn(5)
			break;
		case 6:
			putn(6)
			break;
		case 7:
			val=expm(b,c,4);
			if(val == 0)
			{
				putn(1)
			}
			else if(val == 1)
			{
				putn(7)
			}
			else if(val == 2)
			{
				putn(9)
			}
			else{
				putn(3)
			}
			break;
		case 8:
			val=expm(b,c,4);
			if(val == 0)
			{
				putn(6)
			}
			else if(val == 1)
			{
				putn(8)
			}
			else if(val == 2)
			{
				putn(4)
			}
			else{
				putn(2)
			}
			break;
		case 9:
			val=expm(b,c,2);
			if(val & 1)
			{
				putn(9)
			}
			else
			{
				putn(1)
			}
			break;
	}
	return 0;
}