#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::max;

int compute_min_refills(int dist, int tank, vector<int> & stops) {
    int count=0;
    int rpos=-2;
    int i=0,currlocation=0;
    stops.push_back(dist);
    while(true)
    {
    	if(tank+ currlocation>=dist)
    	return count;
    	
    	if(tank < stops[i]-currlocation)
    	{
    		rpos=i-1;
    		if(currlocation==stops[rpos])
				return -1;
			count++;
			currlocation=stops[i-1];
			i--;
			continue; //WHY?
		}
		i++;
	}
    
    
    return -1;
}


int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
