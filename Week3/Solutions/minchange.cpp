#include <iostream>
using namespace std;

int get_change(int m) {
  int n=0;
  if(m<5)
  	return m;
  else if(m<10)
  	return 1+m%5;
  else
  	{
  		n+=m/10;
  		m=m%10;
  		n+=m/5;
  		m=m%5;
  		n+=m;
  		
    }
	return n;
}

int main() {
  int m;
  cin >> m;
  cout << get_change(m) << '\n';
}
