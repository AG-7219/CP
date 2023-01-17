#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>

#define int               long long
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
//#define oset(args...)   tree<args, null_type, less<args>, rb_tree_tag, tree_order_statistics_node_update>

const int N = 100001, M = 998244353, mod = 1000000007, MX = INT64_MAX, MN = INT64_MIN, oo = 1e18;

#ifdef DEBUG
#include "./Debug/debug.hpp"
#else
#define debug(args...) 0;
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#endif

//using namespace __gnu_pbds;
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
void TATAKAE(int T)
{
    get(int,h,w)
    vector grid(h, vector (w,'.'));
    rep(i,0,h) rep(j,0,w) cin>>grid[i][j];
    
    int src = -1, target = -1;
    vector<pii> adj[h*w + 26];
    rep(i,0,h)
    {
        rep(j,0,w)
        {
            if(grid[i][j] == '#') continue;
            if(grid[i][j] == 'S') src = i*w + j;
            if(grid[i][j] == 'G') target = i*w + j;

            if(i and grid[i-1][j]=='#') 
            {
                adj[i*w + j].pb((i-1)*w + j,1);
                adj[(i-1)*w + j].pb((i)*w + j,1);
            }
            if(i+1<h and grid[i+1][j]!='#')
            {
                adj[i*w + j].pb((i+1)*w + j,1);
                adj[(i+1)*w + j].pb((i)*w + j,1);
            }
            if(j and grid[i][j-1]!='#')
            {
                adj[i*w + j].pb(i*w + j-1,1);                
                adj[i*w + j-1].pb(i*w + j,1);                
            }
            if(j+1<w and grid[i][j+1]!='#')
            {
                adj[i*w + j].pb(i*w + j+1,1);                
                adj[i*w + j+1].pb(i*w + j,1);                
            }
            if(grid[i][j] >='a' and grid[i][j]<='z')
            {
                adj[i*w + j].pb(h*w + (grid[i][j] - 'a'),0);
                adj[h*w + (grid[i][j] - 'a')].pb(i*w + j,1);
            }
        }
    }
    assert(src!=-1 and target!=-1);
    vector<int> dist(h*w+26,oo);
    deque<int> dq;
    dq.push_back(src);
    dist[src] = 0;
    while(!dq.empty())
    {
        auto node = dq.front();
        dq.pop_front();

        for(auto& [child,wt]:adj[node])
        {
            if(amin(dist[child],dist[node] + wt))
            {
                if(wt) dq.push_back(child);
                else dq.push_front(child);
            }
        }
    }
    if(dist[target]==oo) putr(-1)
    putn(dist[target])
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
