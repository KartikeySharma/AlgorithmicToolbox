#include <iostream>
#include <vector>
using std::vector;

int getindex(vector<int> weights,vector<int> values)
{
		int index=0;
		double max=0;
		for(int j=0;j<weights.size();j++)
		{
			if(weights[j]!=0 && (double)values[j]/weights[j] > max)
			{
				max= (double) values[j]/weights[j];
				index=j;
			}
		}
		
	return index;
}

double getoptimal(vector<int>weights,vector<int>values,int capacity)
{
	double value=0.0;
	for(int i=0;i<weights.size();i++)
	{
		if(capacity==0)
			return value;
		int index1= getindex(weights,values);
		int a= std::min(capacity,weights[index1]);
		value += a * (double)values[index1]/weights[index1];
		weights[index1]-=a;
		capacity-=a;
	}
	return value;
}

int main()
{
	int n,capacity;
	std::cin>>n>>capacity;
	vector<int>weights(n);
	vector<int>values(n);
	for(int i=0;i<n;i++)
	{
		std::cin>>values[i]>>weights[i];
	}
	double optimal= getoptimal(weights,values,capacity);
	std::cout.precision(10);
	std::cout<<optimal<<std::endl;
	return 0;
}


