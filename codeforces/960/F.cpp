#include <bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
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
#define mid(l,r)          std::midpoint((l),(r))
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
#define bpc(n)            std::popcount((unsigned long long)(n))
#define hsb(n)            std::has_single_bit((unsigned long long)(n))
#define MSB(n)            std::bit_floor((unsigned long long)(n))
#define ctz(n)            ((n) ? __builtin_ctzll((unsigned long long)(n)) : 0)
#define clz(n)            ((n) ? __builtin_clzll((unsigned long long)(n)) : 64)
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

void read(auto&... args) { ((cin>>args), ...); }
void put(auto&&... args) { ((cout<<args<<" "), ...);}

void file_i_o()
{
    freopen("./tests/test01.txt", "r", stdin);
    freopen("./tests/output01.txt", "w", stdout);
}

class segtree
{
    vector<int> tree;
    public:

    segtree() {}

    segtree(int n)
    {
        tree.resize(2*n,0);
    }

    void update(int ind, int val)
    {
        ind += tree.size()/2;
        amax(tree[ind],val);
        while(ind>1)
        {
            ind >>= 1;
            amax(tree[ind],max(tree[2*ind],tree[2*ind+1]));
        }
    }

    int query(int l, int r)
    {
        l += tree.size()/2;
        r += tree.size()/2;
        int ans = 0;
        while(r > l)
        {
            if(l&1) amax(ans,tree[l++]);
            if(r&1) amax(ans,tree[--r]);
            l >>= 1, r >>= 1;
        }
        return ans;
    }
    
};

// If you win, you live. You cannot win unless you fight.
void TATAKAE(int T)
{   
    get(int,n,m)
    vector<array<int,3>> edges(m);
    vector<int> in[n];
    rep(i,0,m)
    {
        cin>>edges[i][0]>>edges[i][1]>>edges[i][2];
        edges[i][0]--, edges[i][1]--;
        in[edges[i][1]].pb(edges[i][2]);
    }

    vector<segtree> helper(n);
    for(int i=0; i<n; i++)
    {
        sort(all(in[i]), greater<>());
        uniq(in[i]);
        helper[i] = segtree(in[i].size());
    }

    vector<int> dp(m);
    for(int i=0; i<m; i++)
    {
        auto [a,b,w] = edges[i];
        int ind = upper_bound(all(in[a]),w,greater<>()) - in[a].begin();
        dp[i] = 1 + helper[a].query(ind,in[a].size());
        debug(helper[a].query(ind,in[a].size()))

        ind = lower_bound(all(in[b]),w,greater<>()) - in[b].begin();
        debug(i,a,b,w,ind,in[b][ind])
        assert(in[b][ind] == w);
        helper[b].update(ind,dp[i]);
    }
    debug(dp)
    putn(*maxv(dp,0,m))
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
