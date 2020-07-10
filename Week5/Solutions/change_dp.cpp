#include <bits/stdc++.h>
#define INF 1000000
using namespace std;

int coins[]={0,1,3,4};
int get_change(int m, int coins[]) {
  int dp[m+1];
  memset(dp,sizeof(dp),0);
  dp[0]=0;
  dp[1]=1;
  dp[2]=2;
  
  for(int i=3;i<=m;i++)
  {
  	dp[i]=INF;
  	for(int j=1;j<=3;j++)
  	{
  		if(i>=coins[j])
		{
		  	int num=1+dp[i-coins[j]];
		  	if(num< dp[i])
		  		dp[i]=num;
		}	
	}
  }
  return dp[m];
  
}

int main() {
  int m;
  cin >> m;
  cout << get_change(m,coins) << '\n';
}
