#include <iostream>
#include <numeric>
using namespace std;
bool subsetSum(int S[], int n, int a, int b, int c)
{
	
	if (a == 0 && b == 0 && c == 0)
		return true;

	if (n < 0)
		return false;

	bool A = false;
	if (a - S[n] >= 0)
		A = subsetSum(S, n - 1, a - S[n], b, c);

	bool B = false;
	if (!A && (b - S[n] >= 0))
		B = subsetSum(S, n - 1, a, b - S[n], c);

	bool C = false;
	if ((!A && !B) && (c - S[n] >= 0))
		C = subsetSum(S, n - 1, a, b, c - S[n]);

	return A || B || C;
}


bool partition(int S[], int n)
{
	if (n < 3)
		return false;

	int sum = std::accumulate(S, S + n, 0);

	return !(sum % 3) && subsetSum(S, n - 1, sum/3, sum/3, sum/3);
}

int main()
{
	
	int n;
	cin>>n;
	int S[n];
	for(int i=0;i<n;i++)	cin>>S[i];
	if (partition(S, n))
		cout << "1";
	else
		cout << "0";

	return 0;
}
