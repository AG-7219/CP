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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	cin>>s;
	string ans("   ");
	for(int i=1; i<3; i++)
	{
		ans[i-1]=s[i];
	}
	ans[2]=s[0];
	putn(ans)

	return 0;
}
