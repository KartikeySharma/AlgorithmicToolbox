#include <iostream>
#include <vector>
using namespace std;
using std::vector;

int lcs3(vector<int> &a, vector<int> &b, vector<int> &c, int an, int bn, int cn) {
  int dp[an+1][bn+1][cn+1];
  for(int i=0;i<=an;i++)
  {
  	for(int j=0;j<=bn;j++)
  	{
  		for(int k=0;k<=cn;k++)
		{
		 	if(i==0||j==0||k==0)
		 		dp[i][j][k]=0;
		 	else if(a[i-1]==b[j-1] && b[j-1]==c[k-1])
		 	{	dp[i][j][k]=dp[i-1][j-1][k-1]+1;
		 		continue;
		 	}
			else
			{
				dp[i][j][k]=max(max(dp[i-1][j][k],dp[i][j-1][k]),dp[i][j][k-1]);	
			}		 
		  	
		}	
	}
  }
  
  return dp[an][bn][cn];
  
}

int main() {
  
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  size_t an;
  std::cin >> an;
  vector<int> a(an);
  for (size_t i = 0; i < an; i++) {
    std::cin >> a[i];
  }
  size_t bn;
  std::cin >> bn;
  vector<int> b(bn);
  for (size_t i = 0; i < bn; i++) {
    std::cin >> b[i];
  }
  size_t cn;
  std::cin >> cn;
  vector<int> c(cn);
  for (size_t i = 0; i < cn; i++) {
    std::cin >> c[i];
  }
  std::cout << lcs3(a, b, c ,an, bn, cn) << std::endl;
}
