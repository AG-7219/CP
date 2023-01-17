#include <bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>

#define ll              long long
#define ld              long double
#define get(a)          int a; cin>>a;
#define getl(a)         long long a; cin>>a;
#define sin(s)          string s; cin>>s;
#define put(a)          cout<<a<<" ";
#define putn(a)         cout<<a<<"\n";
#define rep(i,a,b)      for(int i=a; i<b; i++)
#define repr(i,a,b)     for(int i=a; i>b; i--)
#define vi              vector<long long>
#define vs              vector<string>
#define pq_max          priority_queue<long long>
#define pq_min          priority_queue< long long , vi , greater<long long> >
#define init(a,n)       vector<long long> a(n); for(int i=0; i<n; i++) { cin>>a[i]; }
#define log(args...)    { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#define all(x)          x.begin(), x.end()
#define uniq(x)         x.erase(unique(all(x)),x.end());
#define rev             reverse
#define mid(l,r)        (l+(r-l)/2)
#define pii             pair<ll,ll>
#define mod             1000000007
#define N               100001
#define pb              emplace_back
#define pf              push_front
#define fr              first
#define sc              second
#define bpc             __builtin_popcountll
#define ctz             __builtin_ctzll
#define clz             __builtin_clzll
#define precise(n)      cout<<fixed<<setprecision(n)

//#define ordered_set tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>;
//using namespace __gnu_pbds;
using namespace std;

vs tokenizer(string str,char ch) {std::istringstream var((str)); vs v; string t; while(getline((var), t, (ch))) {v.pb(t);} return v;}

template<typename T1, typename T2> istream& operator >> (istream& in, pair<T1,T2>& a) { in>>a.first>>a.second; return in; }
template<typename T1, typename T2> ostream& operator << (ostream& out, pair<T1,T2> a) { out<<a.first<<" "<<a.second; return out; }

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{
    cerr << *it << " = " << a << "\n";
    err(++it, args...);
}

template<typename T>
void logarr(T arr, int f, int l)
{
    auto start = (arr).begin(), end = (arr).begin(); 
    advance(start,f); advance(end,l); 
    for(auto it=start; it!=end; it++) cout<<*it<<" "; 
    cout<<"\n";
}

template<typename T>
void debug(T arr, int f, int l)  
{
    int tmp = f; 
    auto start = (arr).begin(), end = (arr).begin(); 
    advance(start,f); advance(end,l); 
    for(auto it=start; it!=end; it++) cerr<<tmp++<<"--> "<<*it<<"\n";
}

void file_i_o()
{
    freopen("./tests/test01.txt", "r", stdin);
    freopen("./tests/output01.txt", "w", stdout);
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
        sin(s)
        int n = s.length();
        int ans = INT_MIN;
        for(int len = 1; len<=n/2-1; len++)
        {
            if(s.substr(0,len) == s.substr(len,len)) ans = 2*len;
        }
        putn(ans)
    }

    #ifndef ONLINE_JUDGE
    cerr<<"\ntime taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<"\n";
    #endif
    return 0;
}
