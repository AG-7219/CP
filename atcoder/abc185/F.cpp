#include <bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>

#define ll              long long
#define ld              long double
#define get(a)          int a; cin>>a;
#define getl(a)         long long a; cin>>a;
#define put(a)          cout<<a<<" ";
#define putn(a)         cout<<a<<"\n";
#define rep(i,a,b)      for(int i=a; i<=b; i++)
#define repr(i,a,b)     for(int i=a; i>=b; i--)
#define vi              vector<long long>
#define vs              vector<string>
#define ump             unordered_map
#define mp              map
#define pq_max          priority_queue<long long>
#define pq_min          priority_queue< long long , vi , greater<long long> >
#define init(a,n)       vector<long long> a(n+1); for(int i=1; i<=n; i++) { cin>>a[i]; }
#define logarr(a)       for(auto i:a) { cout<<i<<" "; } cout<<"\n"; 
#define log(args...)    { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#define token(str,ch)   (std::istringstream var((str)); vs v; string t; while(getline((var), t, (ch))) {v.pb(t);} return v;)
#define all(x)          x.begin(), x.end()
#define mid(l,r)        (l+(r-l)/2)
#define pii             pair<ll,ll>
#define mod             1000000007
#define N               100001
#define pb              emplace_back
#define pf              first
#define ps              second
#define bpc             __builtin_popcountll
#define ctz             __builtin_ctzll
#define clz             __builtin_clzll
#define precise(n)      cout<<fixed<<setprecision(n)

// #define ordered_set tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>;
//using namespace __gnu_pbds;
using namespace std;

vs tokenizer(string str,char ch) {std::istringstream var((str)); vs v; string t; while(getline((var), t, (ch))) {v.pb(t);} return v;}

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{
    cout << *it << " = " << a << "\n";
    err(++it, args...);
}

void file_i_o()
{
    freopen("./tests/test01.txt", "r", stdin);
    freopen("./tests/output01.txt", "w", stdout);
}

vi tree(12*N);

void build(int i, int ss, int se, vi& v)
{
    if(ss == se)
    {
       tree[i] = v[ss];
       return ;  
    } 
    build(2*i, ss, mid(ss,se), v);
    build(2*i+1, mid(ss,se)+1,se,v);
    tree[i] = tree[2*i] ^ tree[2*i+1];
}

void update(int i, int ss, int se, int x, int y)
{
    if(x>se or x<ss) return ;
    if(ss == se)
    {
        tree[i] ^= y;
        return ;
    }
    update(2*i,ss,mid(ss,se),x,y);
    update(2*i+1,mid(ss,se)+1,se,x,y);
    tree[i] = tree[2*i] ^ tree[2*i+1];
}

int query(int i, int ss, int se, int l, int r)
{
    if(ss>r or l>se) return 0;
    if(ss>=l and se<=r) return tree[i];
    return query(2*i,ss,mid(ss,se),l,r) ^ query(2*i+1,mid(ss,se)+1,se,l,r);
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //file_i_o();
    int t=1;
    while(t--)
    {
        get(n) get(q)
        init(v,n)
        build(1,1,n,v);
        while(q--)
        {
            get(type) get(x) get(y)
            if(type==1)
                update(1,1,n,x,y);
            else putn(query(1,1,n,x,y))
        }        
    }

    #ifndef ONLINE_JUDGE
    cerr<<"\ntime taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<"\n";
    #endif
    return 0;
}
