#include <bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

// #define int               long long
#define ld                long double
#define get(T,args...)    T args; read(args);
#define init(a,T,n,s)     vector<T> a((n)+1,s); cin>>a;
#define putn(args...)     { put(args); cout<<"\n"; }
#define rep(i,a,b)        for(int i=(a); i<(b); i++)
#define repr(i,a,b)       for(int i=(a); i>(b); i--)
#define logarr(arr,f,l)   { auto start=arr.begin(), end=arr.begin(); advance(start,(f)); advance(end,(l)); for(auto it=start; it!=end; it++) cout<<*it<<" "; cout<<"\n"; }
#define all(x)            x.begin(), x.end()
#define rall(x)           x.rbegin(), x.rend()
#define sort_by(span,p)   sort(span, [&](const auto &l, const auto &r) { return p; })
#define uniq(x)           x.erase(unique(all(x)),x.end());
#define sz(x)             (int)(x).size()
#define mid(l,r)          std::midpoint((l),(r))
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

#ifndef ONLINE_JUDGE
#define log(args...)      { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#define debug(arr,f,l)    { int t=f; auto start=arr.begin(), end=arr.begin(); advance(start,f); advance(end,l); for(auto it=start; it!=end; it++) cerr<<t++<<"--> "<<*it<<"\n"; }
#else
#define log(args...) 1;
#define debug(arr,f,l) 2;
#endif

//using namespace __gnu_pbds;
using namespace std;

vec(string) tokenizer(string str,char ch) {std::istringstream var((str)); vec(string) v; string t; while(getline((var), t, (ch))) {v.pb(t);} return v;}

template<typename T>
struct Comp { bool operator()(const T& l, const T& r) const { return l < r; } };
template<typename T1, typename T2> inline istream& operator >> (istream& in, pair<T1,T2>& a) { in>>a.first>>a.second; return in; }
template<typename T1, typename T2> inline ostream& operator << (ostream& out, pair<T1,T2> a) { out<<a.first<<" "<<a.second; return out; }
template<typename T> istream& operator >> (istream& in, vector<T>& v) { rep(i,1,sz(v)) cin>>v[i]; return in; }
template<typename T,typename T1> inline T amax(T &a,T1 b){ if(b>a) a=b; return a;}
template<typename T,typename T1> inline T amin(T &a,T1 b){ if(b<a) a=b; return a;}

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) { cerr << *it << " = " << a << "\n"; err(++it, args...); }

void read(auto&... args) { ((cin>>args), ...); }
void put(auto&&... args) { ((cout<<args<<" "), ...);}

void file_i_o()
{
    freopen("./tests/test01.txt", "r", stdin);
    freopen("./tests/output01.txt", "w", stdout);
}

struct SegTree
{
    vector<int> tree, lazy;
    
    SegTree() { }
    SegTree(int n) 
    {   
        tree.resize(8*n+4);
        tree.assign(tree.size(),-1);
        lazy.resize(8*n+4);
        lazy.assign(lazy.size(),lazy.size());
    }

    void push(int i, int ss, int se)
    {
        if(ss!=se)
        {
            lazy[2*i] = lazy[2*i+1] = lazy[i];
        }
    }

    int query(int i, int ss, int se, int x)
    {
        if(lazy[i] != lazy.size())
        {
            tree[i] = lazy[i];
            push(i,ss,se);
            lazy[i] = lazy.size();
        }
        if(ss == se) return tree[i];
        int mid = (ss + se)/2;
        if(x<=mid) return query(2*i,ss,mid,x);
        else return query(2*i+1,mid+1,se,x);
    }

    void update(int i, int ss, int se, int l, int r, int val)
    {
        if(lazy[i] != lazy.size())
        {
            tree[i] = lazy[i];
            push(i,ss,se);
            lazy[i] = lazy.size();
        }

        if(ss>r or se<l) return ;
        if(ss>=l and se<=r)
        {
            tree[i] = val;
            if(ss!=se) lazy[2*i] = lazy[2*i+1] = val;
            return ; 
        }
        int mid = (ss + se)/2;
        update(2*i,ss,mid,l,r,val);
        update(2*i+1,mid+1,se,l,r,val);
    }
};

void solve(int T)
{
    get(string,s)
    int n = s.length();
    s.insert(s.begin(),' ');
    auto root = *new SegTree(n);
    root.update(1,0,2*n+1,n,n,0);

    int cnt = 0;
    int ans = 0, res = 1;
    for(int i=1; i<s.length(); i++)
    {
        if(s[i] == '(') cnt++;
        else cnt--;

        int ind = root.query(1,0,2*n+1,cnt+n);
        if(ind != -1)
        {
            if(i - ind > ans)
            {
                ans = i - ind;
                res = 1;
            }
            else if(i-ind == ans) res++;
        }
        else root.update(1,0,2*n+1,cnt+n,cnt+n,i); 
        
        root.update(1,0,2*n+1,cnt+n+1,2*n+1,-1);
    }

    putn(ans,res)

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
