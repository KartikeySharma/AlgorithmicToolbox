#include <algorithm>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using std::vector;

void get_majority_element(vector<int> &a, int left, int right) 
{
  	if (left == right) 
		std::cout<<-1;
  	sort(a.begin(),a.end());
  	if (left + 1 == right) 
	  	std::cout<<a[left];
  	int mid=(left+right)/2;
  	int n= a.size();
  	int c= std::count(a.begin(),a.end(),a[mid]);
  	if(c>n/2)
  		{std::cout<<1;}
  	else
  		std::cout<<0;
}

int main() 
{
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) 
  {
    std::cin >> a[i];
  }
  
  get_majority_element(a, 0, a.size()) ;
}
