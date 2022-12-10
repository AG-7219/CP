#include <bits/stdc++.h>
using namespace std;
template<typename T = int> vector<T> create(size_t n){ return vector<T>(n); }
template<typename T, typename... Args> auto create(size_t n, Args... args){ return vector<decltype(create<T>(args...))>(n, create<T>(args...)); }
const int maxn = 100100, lg = 30;
int to[maxn * lg][2], nds = 1;
void insert(int x){
	int cur = 0;
	for(int i = lg - 1; i >= 0; i--){
		int & v = to[cur][(x>>i)&1];
		if(v == 0) v = nds++;
		cur = v;
	}
}
int get(int r, int b){
	if(to[r][0] == 0 && to[r][1] == 0) return 0;
	if(to[r][0] == 0) return get(to[r][1], b - 1);
	if(to[r][1] == 0) return get(to[r][0], b - 1);
	return min(get(to[r][0], b - 1), get(to[r][1], b - 1)) + (1<<b);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n; cin >> n;
	for(int i = 0; i < n; i++){
		int x; cin >> x;
		insert(x);
	}
	cout << get(0, 29) << endl;
	return 0;
}
