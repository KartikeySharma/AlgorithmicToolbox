#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;
using std::string;

int DistDP(string str1, string str2, int m, int n) {
	vector<vector<int> > dp(m + 1, vector<int>(n + 1));

	for (int i = 0; i <= m; i++) {
		for (int j = 0; j <= n; j++) {
			if (i == 0)
				dp[i][j] = j;

			else if (j == 0)
				dp[i][j] = i;

			else if (str1[i - 1] == str2[j - 1])
				dp[i][j] = dp[i - 1][j - 1];

			else
				dp[i][j] = 1 + min(min(dp[i][j - 1], dp[i - 1][j]), dp[i - 1][j - 1]);
		}
	}

	return dp[m][n];
}
int main() {
	string First_String, Second_String;
	cin >> First_String >> Second_String;
	
	cout << DistDP(First_String, Second_String, First_String.size(),Second_String.size())<< endl;
}
