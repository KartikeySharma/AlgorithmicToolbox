#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	ll t,n,a,prod;
	//cin>>t;
	vector<ll>v;
	//while( t-->0)
	//{
		cin>>n;
		for(ll i=0;i<n;i++)
		{
			cin>>a;
			v.push_back(a);
		}
		sort(v.begin(),v.end());
		prod= v[n-1]*v[n-2];
		cout<<prod<<"\n";
//	}

 return 0;
}

