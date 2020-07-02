#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>
using namespace std;
using std::vector;

struct Segment 
{
  int start, end;
};

bool cmp(Segment i, Segment j)
{
	return (i.end<j.end);
}

vector<int> optimal_points(vector<Segment> &segments) 
{
  vector<int> points;
  sort(segments.begin(),segments.end(),cmp);
  int point= segments[0].end;
  points.push_back(point);
  
  //Below function checks if the initial end overlaps with the other segments start or end 
  //and appends the same to the point variable
  
  for (size_t i = 1; i < segments.size(); ++i) 
  {
    if(segments[i].end < point || segments[i].start > point)
    {
    	point=segments[i].end;
    	points.push_back(point);
	}
  }
  return points;
}

int main() 
{
  int n;
  cin>>n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i) 
  {
    cin >> segments[i].start >> segments[i].end;
  }
  vector<int> points = optimal_points(segments);
  cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) 
  {
    cout << points[i] << " ";
  }
  return 0;
}
