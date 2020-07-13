#include <iostream>
#include <vector>
#include<bits/stdc++.h>
using namespace std;
using std::vector;
#define ll long long
ll optimal_weight(ll W, vector<ll> wt,vector<ll> val, ll n) 
{
  vector<vector<ll> > dp(n+1,vector<ll>(W+1,0));
  for(ll i=1;i<n+1;i++)
  {
  	for(ll w=1;w < W+1;w++)
  	{
  		dp[i][w]=dp[i-1][w];	
  		if(wt[i-1]<=w)
  		{
  			ll val1 = val[i-1]+dp[i-1][w-wt[i-1]];
			if(val1>dp[i][w])
				dp[i][w]=val1;
		}
	}
  }
  return dp[n][W];
}

int main() {
  
  ll W,n,a;
  cin>>W>>n;
  vector<ll>wt,val;
  for(int i=0;i<n;i++)
  {
  	cin>>a;
  	wt.push_back(a);
  	val.push_back(a);
  }
  cout << optimal_weight(W, wt, val,n) << '\n';
}
