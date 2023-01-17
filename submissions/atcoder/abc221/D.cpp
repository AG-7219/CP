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
#define init(a,n)         vector<long long> a(n+1); for(int i=1; i<=n; i++) { cin>>a[i]; }
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
#define precise(n)        cout<<fixed<<setprecision(n)
#define bpc               __builtin_popcountll
#define ctz               __builtin_ctzll
#define clz               __builtin_clzll
#define MSB(n)            ((n) ? (1LL<<__lg(n)) : 0)
#define LSB(n)            (n&(-n))

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

void solve(int T)
{
    get(int,n)
    vector<pii> v(n);
    vector<int> aux;
    rep(i,0,n) 
    {
        cin>>v[i];
        aux.push_back(v[i].fr);
        aux.push_back(v[i].fr+1);
        aux.push_back(v[i].fr+v[i].sc-1);
        aux.push_back(v[i].fr+v[i].sc);
    }
    sort(all(aux));
    uniq(aux)
    map<int,int> inv;
    rep(i,0,aux.size()) inv[aux[i]] = i;
    vector<int> pre(aux.size(),0);
    rep(i,0,n)
    {
        int a = v[i].fr;
        int b = v[i].sc;
        pre[inv[a]] += 1;
        pre[inv[b+a]] -= 1;
    }
    rep(i,1,pre.size()) pre[i] += pre[i-1];
    // logarr(aux,0,aux.size())
    // logarr(pre,0,pre.size())
    vector<int> ans(n+1);
    rep(i,1,aux.size())
    {
        ans[pre[i-1]] += aux[i] - aux[i-1];
    }
    ans[pre.back()] += 1;
    logarr(ans,1,ans.size())
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
// 5797762 54601291 136809000 453599267 468677897 583563238 653199778 785892285 820642330 916692569 
// 65697 116251 207213 207213 228925 273502 273502 182540 131986 87409 0 
// cur = 3206245444713
// cur = 9556728378959
// cur = 65643061595871
// cur = 3124488158190
// cur = 26300126688425
// cur = 19045732963080
// cur = 36291666049514
// cur = 6343273214300
// cur = 12677286844654