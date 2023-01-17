#include<bits/stdc++.h>
using namespace std;

int main()
{
  int n,k,s;
  cin>>n>>k>>s;
  vector<int> ans(n);
  for(int i=0; i<k; i++) ans[i] = s;
  if(s == 1000000000) for(int i=k; i<n; i++) ans[i] = 1;
  else for(int i=k; i<n; i++) ans[i] = 1000000000;
  for(int i:ans) cout<<i<<" ";
  cout<<"\n";
}