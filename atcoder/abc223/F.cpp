#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

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
#define vec(args...)      vector<args>
#define set(args...)      set<args,Comp<args> >
#define pqueue(args...)   priority_queue<args,vector<args>,Comp<args> > 
#define oset(args...)     tree<args, null_type, less<args>, rb_tree_tag, tree_order_statistics_node_update>

const int N = 100001, M = 998244353, mod = 1000000007, MX = INT64_MAX, MN = INT64_MIN, oo = 1e18;

#ifdef DEBUG
#include "./Debug/debug.hpp"
#else
#define debug(args...) 0;
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#endif

using namespace __gnu_pbds;
using namespace std;

vec(string) tokenizer(string str,char ch) {istringstream var((str)); vec(string) v; string t; while(getline((var), t, (ch))) {v.pb(t);} return v;}

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

template <class Base,
          class Node,
          class Update,
          class MakeNode,
          class CombineNodes,
          class ApplyUpdate,
          class ComposeUpdates = nullptr_t,
          class CheckLazy = nullptr_t>
class segtree 
{
    static constexpr bool is_lazy = !is_same<ComposeUpdates, nullptr_t>::value;
    static constexpr bool is_check_lazy = !is_same<CheckLazy, nullptr_t>::value;

   private:
    int _n, log;
    vector<Node> d;
    vector<Update> lz;
    MakeNode make_node;
    CombineNodes combine;
    Node id_node;
    ApplyUpdate apply_update;
    Update id_update;
    ComposeUpdates compose_updates;
    CheckLazy check_lazy;

    void merge(int k) { d[k] = combine(d[k<<1], d[k<<1 | 1]); }
    void all_apply(int k, Update upd) {
        d[k] = apply_update(upd, d[k]);
        if constexpr (is_lazy)
            if (k < _n) lz[k] = compose_updates(upd, lz[k]);
    }
    void push(int k) {
        if constexpr (is_check_lazy) {
            if (!check_lazy(lz[k])) return;
        }
        all_apply(k<<1, lz[k]);
        all_apply(k<<1 | 1, lz[k]);
        lz[k] = id_update;
    }

   public:
    template <typename... T>
    explicit segtree(int n, const Base& id_base, T... args) : segtree(vector<Base>(n, id_base), args...) {}
    explicit segtree(const vector<Base>& v,
                     const Node& _id_node,
                     const MakeNode& _make_node,
                     const CombineNodes& _combine,
                     const Update& _id_update,
                     const ApplyUpdate& _apply_update,
                     const ComposeUpdates& _compose_updates = nullptr,
                     const CheckLazy& _check_lazy = nullptr)
                    : _n(int32_t(v.size())),
                      make_node(_make_node),
                      combine(_combine),
                      id_node(_id_node),
                      apply_update(_apply_update),
                      id_update(_id_update),
                      compose_updates(_compose_updates),
                      check_lazy(_check_lazy) {
                            build(v);
                      }

    void build(const vector<Base>& v) {
        _n = int32_t(v.size());
        log = 0;
        while ((2 * _n - 1) >> log > 1) ++log;
        d = vector<Node>(2 * _n, id_node);
        if constexpr (is_lazy) lz = vector<Update>(_n, id_update);
        for (int i = 0; i < _n; i++) d[_n + i] = make_node(v[i], i);
        for (int i = _n - 1; i >= 1; i--) merge(i);
    }
    
    void assign(int p, Node x) {
        p += _n;
        if constexpr (is_lazy)
            for (int i = log; i >= 1; i--) push(p >> i);
        d[p] = x;
        for (int i = 1; i <= log; ++i) merge(p >> i);
    }

    Node query(int p) {
        p += _n;
        if constexpr (is_lazy)
            for (int i = log; i >= 1; i--) push(p >> i);
        return d[p];
    }

    Node query(int l, int r) {
        if (l == r) return id_node;
        l += _n, r += _n;
        if constexpr (is_lazy) {
            int l_ctz = __builtin_ctz(l);
            int r_ctz = __builtin_ctz(r);
            for (int i = log; i > l_ctz; --i) push(l >> i);
            for (int i = log; i > r_ctz; --i) push((r - 1) >> i);
        }
        Node sm = id_node;
        --l;
        const int lg = __lg(r ^ l);
        const int lg_mask = (1 << lg) - 1;
        const int l_iter = lg - __builtin_popcount(l & lg_mask);
        for (int i = 0; i < l_iter; ++i) {
            ++(l >>= __builtin_ctz(~l));
            sm = combine(sm, d[l]);
        }
        const int r_iter = __builtin_popcount(r & lg_mask);
        int r_suffix = r & ((1 << lg) - 1);
        for (int i = 0; i < r_iter; ++i) {
            const int lg_suffix = __lg(r_suffix);
            const int R = r >> lg_suffix;
            sm = combine(sm, d[R - 1]);
            r_suffix ^= 1 << lg_suffix;
        }
        return sm;
    }
    
    Node query() const { return query(0, _n); }
    
    void update(int p, Update upd) {
        p += _n;
        if constexpr (is_lazy)
            for (int i = log; i >= 1; i--) push(p >> i);
        d[p] = apply_update(upd, d[p]);
        for (int i = 1; i <= log; ++i) merge(p >> i);
    }
    
    void update(int l, int r, Update upd) {
        if (l == r) return;
        l += _n, r += _n;
        const int l_ctz = __builtin_ctz(l);
        const int r_ctz = __builtin_ctz(r);
        if constexpr (is_lazy) {
            for (int i = log; i > l_ctz; --i) push(l >> i);
            for (int i = log; i > r_ctz; --i) push((r - 1) >> i);
        }
        {
            const int l2 = l, r2 = r;
            --l;
            const int lg = __lg(r ^ l);
            const int lg_mask = (1 << lg) - 1;
            const int l_iter = lg - __builtin_popcount(l & lg_mask);
            for (int i = 0; i < l_iter; ++i) {
                ++(l >>= __builtin_ctz(~l));
                all_apply(l, upd);
            }
            const int r_iter = __builtin_popcount(r & lg_mask);
            int r_suffix = r & ((1 << lg) - 1);
            for (int i = 0; i < r_iter; ++i) {
                const int lg_suffix = __lg(r_suffix);
                const int R = r >> lg_suffix;
                all_apply(R - 1, upd);
                r_suffix ^= 1 << lg_suffix;
            }
            l = l2, r = r2;
        }
        for (int i = l_ctz + 1; i <= log; ++i) update(l >> i);
        for (int i = r_ctz + 1; i <= log; ++i) update((r - 1) >> i);
    }

    template <class G>
    int max_right(int l, G bs) {
        // assert(0 <= l && l <= _n);
        // assert(bs(id_node));

        if (l == _n) return _n;

        l += _n;
        int r = 2 * _n;
        
        const int l_ctz = __builtin_ctz(l);
        const int r_ctz = __builtin_ctz(r);
        
        if constexpr (is_lazy) {
            for (int i = log; i > l_ctz; --i) push(l >> i);
            for (int i = log; i > r_ctz; --i) push((r - 1) >> i);
        }
        
        Node sm = id_node;

        --l;
        int i = -1;
        const int lg = __lg(r ^ l);
        const int lg_mask = (1 << lg) - 1;
        const int l_iter = lg - __builtin_popcount(l & lg_mask);
        for (int it = 0; it < l_iter; ++it) {
            ++(l >>= __builtin_ctz(~l));
            int root = l;
            auto c = combine(sm, d[root]);
            if (!bs(c)) {
                i = root;
                break;
            }
            sm = c;
        }

        if (i == -1) {
            const int r_iter = __builtin_popcount(r & lg_mask);
            int r_suffix = r & ((1 << lg) - 1);
            for (int it = 0; it < r_iter; ++it) {
                const int lg_suffix = __lg(r_suffix);
                const int R = r >> lg_suffix;
                r_suffix ^= 1 << lg_suffix;
                const int root = R - 1;
                auto c = combine(sm, d[root]);
                if (!bs(c)) {
                    i = root;
                    break;
                }
                sm = c;
            }
        }

        if (i == -1) return _n;
        while (i < _n) {
            push(i);
            i = 2 * i;
            auto c = combine(sm, d[i]);
            if (bs(c)) {
                sm = c;
                ++i;
            }
        }
        return i - _n;
    }

    template <class G>
    int min_left(int r, G bs) {
        // assert(0 <= r && r <= _n);
        // assert(bs(id_node));
        if (r == 0) return 0;
        r += _n;
        int l = _n;
       
        const int l_ctz = __builtin_ctz(l);
        const int r_ctz = __builtin_ctz(r);
        
        if constexpr (is_lazy) {
            for (int i = log; i > l_ctz; --i) push(l >> i);
            for (int i = log; i > r_ctz; --i) push((r - 1) >> i);
        }
        
        --l;
        Node sm = id_node;
        int i = -1;
        const int lg = __lg(r ^ l);
        const int lg_mask = (1 << lg) - 1;
        const int r_iter = __builtin_popcount(r & lg_mask);
        for (int it = 0; it < r_iter; ++it) {
            r >>= __builtin_ctz(r);
            const int root = --r;
            auto c = combine(d[root], sm);
            if (!bs(c)) {
                i = root;
                break;
            }
            sm = c;
        }

        if (i == -1) {
            const int l_iter = lg - __builtin_popcount(l & lg_mask);
            int l_suffix = (l & lg_mask) ^ lg_mask;
            for (int it = 0; it < l_iter; ++it) {
                const int lg_suffix = __lg(l_suffix);
                const int L = l >> lg_suffix;
                l_suffix ^= 1 << lg_suffix;
                const int root = L + 1;
                auto c = combine(d[root], sm);
                if (!bs(c)) {
                    i = root;
                    break;
                }
                sm = c;
            }
        }

        if (i == -1) return 0;
        while (i < _n) {
            push(i);
            i = 2 * i + 1;
            auto c = combine(d[i], sm);
            if (bs(c)) {
                sm = c;
                --i;
            }
        }
        return i + 1 - _n;
    }
};

// If you win, you live. You cannot win unless you fight.
void TATAKAE(int T)
{
    get(int,n,q)
    get(string,s)
    vector<int> aux(n);
    rep(i,0,n)
    {
        if(s[i] == '(') aux[i] = 1;
        else aux[i] = -1;
    }

    segtree root(aux,make_pair(0LL,0LL),[](const int& x, const int& ind){ return make_pair(x,x); }, [](const pii& l, const pii& r){ return make_pair(l.fr + r.fr, min(l.sc,l.fr + r.sc)); }, 0LL, [](int upd, pii x){ return make_pair(upd,upd); });
    // static_assert(!decltype(root)::is_lazy);

    while(q--)
    {
        get(int,type,l,r)
        l--;
        if(type==1)
        {
            r--;
            swap(aux[l],aux[r]);
            root.update(l,aux[l]);
            root.update(r,aux[r]);
        }
        else 
        {
            auto ans = root.query(l,r);
            if(ans.first or (ans.second < 0)) putn("No")
            else putn("Yes")
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
