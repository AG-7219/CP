#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ld                long double
#define get(T,args...)    T args; read(args);
#define init(a,T,n,s)     vector<T> a((n)+1,s); cin>>a;
#define putn(args...)     { put(args); cout<<"\n"; }
#define pute(args...)     { put(args); cout<<endl; }
#define putr(args...)     { putn(args) return ;}
#define rep(i,a,b)        for(int i=(a); i<(b); i++)
#define repr(i,a,b)       for(int i=(a); i>(b); i--)
#define logarr(arr,f,l)   { auto start=arr.begin(), end=arr.begin(); advance(start,(f)); advance(end,(l)); for(auto it=start; it!=end; it++) cout<<*it<<" "; cout<<"\n"; }
#define all(x)            x.begin(), x.end()
#define rall(x)           x.rbegin(), x.rend()
#define sort_by(span,p)   sort(span, [&](const auto &l, const auto &r) { return p; })
#define f(u, args...)     [&](auto &&u) { return args; }
#define g(u, v, args...)  [&](auto &&u, auto &&v) { return args; }
#define uniq(x)           x.erase(unique(all(x)),x.end());
#define sz(x)             (int)(x).size()
#define mid(l,r)          ((l)+((r)-(l))/2)
#define zov(v,z,c)        ((c) ? (v) : (z))
#define pii               pair<int,int>
#define pb                emplace_back
#define pf                push_front
#define fr                first
#define sc                second
#define sumv(v,b,e)       accumulate((v).begin()+b,(v).begin()+e,0LL)
#define minv(v,b,e)       min_element((v).begin()+b,(v).begin()+e)
#define maxv(v,b,e)       max_element((v).begin()+b,(v).begin()+e)
#define precise(n)        cout<<fixed<<setprecision((n))
#define bpc(n)            ((n) ? __builtin_popcountll((unsigned long long)(n)) : 0)
#define ctz(n)            ((n) ? __builtin_ctzll((unsigned long long)(n)) : 0)
#define clz(n)            ((n) ? __builtin_clzll((unsigned long long)(n)) : 64)
#define MSB(n)            ((n) ? (1LL<<__lg(n)) : 0)
#define LSB(n)            ((n)&(-(n)))
#define vec(args...)      std::vector<args>
#define set(args...)      std::set<args,Comp<args> >
#define pqueue(args...)   std::priority_queue<args,vector<args>,Comp<args> > 
#define oset(args...)     tree<args, null_type, less<args>, rb_tree_tag, tree_order_statistics_node_update>


#ifdef DEBUG
#include "./Debug/debug.hpp"
#else
#define debug(args...) 0;
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#endif

using namespace __gnu_pbds;
using namespace std;

vec(string) tokenizer(string str,char ch) {std::istringstream var((str)); vec(string) v; string t; while(getline((var), t, (ch))) {v.pb(t);} return v;}

template<typename T> struct Comp { bool operator()(const T& l, const T& r) const { return l < r; } };
template<typename T1, typename T2> inline istream& operator >> (istream& in, pair<T1,T2>& a) { in>>a.first>>a.second; return in; }
template<typename T1, typename T2> inline ostream& operator << (ostream& out, pair<T1,T2> a) { out<<a.first<<" "<<a.second; return out; }
template<typename T> istream& operator >> (istream& in, vector<T>& v) { rep(i,1,sz(v)) cin>>v[i]; return in; }
template<typename T,typename T1> inline bool amax(T &a,T1 b){ if(b>a) { a=b; return true; } return false; }
template<typename T,typename T1> inline bool amin(T &a,T1 b){ if(b<a) { a=b; return true; } return false; }

template<typename... T>
void read(T&... args) { ((cin>>args), ...); }

template<typename... T>
void put(T&&... args) { ((cout<<args<<" "), ...);}

void file_i_o()
{
    freopen("./tests/test01.txt", "r", stdin);
    freopen("./tests/output01.txt", "w", stdout);
}

// If you win, you live. You cannot win unless you fight.
vector<int> adj[3001];
int dp[3001][3001], back[3001][3001];
void TATAKAE(int T)
{
    const int oo = INT_MAX;
    get(int,n,m,k)
    rep(i,1,n+1) rep(j,1,n+1) dp[i][j] = oo;
    while(m--)
    {
        get(int,a,b)
        adj[a].pb(b);
        adj[b].pb(a);
    }
    vector<tuple<int,int,int>> restrictions(k);
    for(auto& [x,y,z]:restrictions) cin>>x>>y>>z;
    sort(all(restrictions));
    auto restricted = [&](int x ,int y, int z)
    {
        return binary_search(all(restrictions), make_tuple(x,y,z));
    };
    set<tuple<int,int,int>> st;
    st.emplace(0,1,1);
    rep(i,1,n+1) dp[1][i] = 0;
    while(!st.empty())
    {
        auto [dist,node,prev] = *st.begin();
        st.erase(st.begin());

        for(int child:adj[node])
        {
            if(restricted(prev,node,child)) continue;
            if(dp[child][node] > dp[node][prev] + 1){
                st.erase({dp[child][node], child, node});
                dp[child][node] = dp[node][prev] +1;
                st.emplace(dp[child][node], child,node);
                back[child][node] = prev;
            }
        }
    }
    int ans = oo;
    rep(i,1,n+1) ans = min(ans,dp[n][i]);
    if(ans == oo) putr(-1);

    vector<int> path;
    rep(i,1,n+1)
    {
        if(dp[n][i] == ans)
        {
            int cur = n, prev = i;
            while(cur!=1)
            {
                path.push_back(cur);
                int temp = back[cur][prev];
                cur = prev;
                prev = temp;
            }
            path.push_back(1);
            reverse(all(path));
            cout<<ans<<"\n";
            for(int node:path) cout<<node<<" ";
            cout<<"\n";
            return;
        }
    }
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
        TATAKAE(t);
    }

    #ifndef ONLINE_JUDGE
    cerr<<"\ntime taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<"\n";
    #endif
    return 0;
}