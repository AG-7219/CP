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
	get(h) get(w) get(x) get(y)
	vector<char> a(w+1,'#');
	vector<vector<char>> arr(h+1,a);
	for(int i=1; i<=h; i++)
	{
		for(int j=1; j<=w; j++)
		{
			cin>>arr[i][j];
		}
	}
	int ans=0;
	if(arr[x][y]!='#')
	{
		for(int j=y+1; j<=w && arr[x][j]!='#'; j++)
		{
			ans++;
		}
		for(int j=x+1; j<=h && arr[j][y]!='#'; j++)
		{
			ans++;
		}
		for(int i=x-1; arr[i][y]!='#'; i--)
		{
			ans++;
		}
		for(int j=y-1; arr[x][j]!='#'; j--)
		{
			ans++;
		}
		ans++;
	}
	putn(ans)

	return 0;
}