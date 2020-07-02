#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>
using namespace std;
using std::vector;
using std::string;

int isgreaterequal(string a,string b)
{
	string ab= a.append(b);
	string ba= b.append(a);
	
	return ab.compare(ba)>0 ?1:0;
}

void largest_number(vector<string> a)
{
  sort(a.begin(),a.end(),isgreaterequal);
  
  for(int i=0;i<a.size();i++)
  {
  	cout<<a[i];
  }
}

int main() 
{
  int n;
  cin >> n;
  vector<string> a(n);
  for (size_t i = 0; i < a.size(); i++) 
  {
    cin >> a[i];
  }
  largest_number(a);
}
