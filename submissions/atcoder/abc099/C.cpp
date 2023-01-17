#include <bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>

#define int               long long
#define ld                long double
#define get(type,args...) type args; read(args);
#define putn(args...)     { put(args); cout<<"\n"; }
#define rep(i,a,b)        for(int i=a; i<b; i++)
#define repr(i,a,b)       for(int i=a; i>b; i--)
#define vi                vector<long long>
#define vs                vector<string>
#define pq_max            priority_queue<long long>
#define pq_min            priority_queue< long long , vi , greater<long long> >
#define init(a,n)         vector<long long> a(n); for(int i=0; i<n; i++) { cin>>a[i]; }
#define logarr(arr,f,l)   { auto start=arr.begin(), end=arr.begin(); advance(start,f); advance(end,l); for(auto it=start; it!=end; it++) cout<<*it<<" "; cout<<"\n"; }
#define all(x)            x.begin(), x.end()
#define uniq(x)           x.erase(unique(all(x)),x.end());
#define sz(x)             (int)x.size()
#define mid(l,r)          (l+(r-l)/2)
#define pii               pair<int,int>
#define sumv(v,b,e)       accumulate(v.begin()+b,v.begin()+e,0LL)
#define minv(v,b,e)       min_element(v.begin()+b,v.begin()+e)
#define maxv(v,b,e)       max_element(v.begin()+b,v.begin()+e)
#define pb                emplace_back
#define pf                push_front
#define fr                first
#define sc                second
#define bpc               __builtin_popcountll
#define ctz               __builtin_ctzll
#define clz               __builtin_clzll
#define precise(n)        cout<<fixed<<setprecision(n)

const int N = 100001, M = 998244353, mod = 1000000007, MX = INT64_MAX, MN = INT64_MIN, oo = 1e18;

#ifndef ONLINE_JUDGE
#define log(args...)      { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#define debug(arr,f,l)    { int t=f; auto start=arr.begin(), end=arr.begin(); advance(start,f); advance(end,l); for(auto it=start; it!=end; it++) cerr<<t++<<"--> "<<*it<<"\n"; }
#else
#define log(args...) 1;
#define debug(arr,f,l) 2;
#endif

//#define ordered_set tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>
//using namespace __gnu_pbds;
using namespace std;

vs tokenizer(string str,char ch) {std::istringstream var((str)); vs v; string t; while(getline((var), t, (ch))) {v.pb(t);} return v;}

template<typename T1, typename T2> istream& operator >> (istream& in, pair<T1,T2>& a) { in>>a.first>>a.second; return in; }
template<typename T1, typename T2> ostream& operator << (ostream& out, pair<T1,T2> a) { out<<a.first<<" "<<a.second; return out; }
template<typename T,typename T1>T amax(T &a,T1 b){ if(b>a) a=b; return a;}
template<typename T,typename T1>T amin(T &a,T1 b){ if(b<a) a=b; return a;}

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) { cerr << *it << " = " << a << "\n"; err(++it, args...); }

template<typename... T>
void read(T&... args) { ((cin>>args), ...); }

template<typename... T>
void put(T&&... args) { ((cout<<args<<" "), ...);}

void file_i_o()
{
    freopen("./tests/test01.txt", "r", stdin);
    freopen("./tests/output01.txt", "w", stdout);
}

long long exp(long long a, long long b)
{
    long long res=1;
    while(b)
    {
        if(b & 1) { res*=a; }
        b/=2;
        a*=a;
    }
    return res;
}

void solve(int T)
{
    get(int,n)
    vector<int> dp(n+1,0);
    vector<int> aux;
    aux.push_back(1);
    rep(i,1,7) aux.push_back(exp(6,i));
    rep(i,1,6) aux.push_back(exp(9,i));
    dp[1] = 1;
    rep(i,2,n+1)
    {
        int cur = MX;
        for(auto opt:aux) if(i >= opt) amin(cur,dp[i-opt]);
        dp[i] = cur+1;
    }
    putn(dp[n])

}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //file_i_o();

    int t=1;
    rep(i,1,t+1)
    {
        //cout<<"Case #"<<i<<": ";
        solve(t);
    }

    #ifndef ONLINE_JUDGE
    cerr<<"\ntime taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<"\n";
    #endif
    return 0;
}