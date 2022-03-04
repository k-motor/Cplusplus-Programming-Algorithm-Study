#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare( pair<string, pair<int, int> > a,
			  pair<string, pair<int, int> > b)
{
	if(a.second.first == b.second.first)
	{
		return a.second.second > b.second.second;
	}
	else
	{
		return a.second.first > b.second.first;
	}
}
int main(void)
{
	vector<pair <string, pair<int, int> > > v;
	v.push_back(pair <string, pair<int, int> >("a", pair<int, int>(90, 1996122)));
	v.push_back(pair <string, pair<int, int> >("b", pair<int, int>(80, 1993122)));
	v.push_back(pair <string, pair<int, int> >("c", pair<int, int>(70, 1992122)));
	v.push_back(pair <string, pair<int, int> >("e", pair<int, int>(90, 1991122)));

	sort(v.begin(), v.end(), compare);
	
	for(int i = 0; i < v.size(); i++)
	{
		cout << v[i].first << ' ';
	}
}
