#include<bits/stdc++.h>
using namespace std;

int main()
{
	int N, i, val;
	cin >> N;
	stack<int>s;
	vector<int>arr, v;
	for (int i = 0; i < N; i++)
	{
		cin >> val;
		arr.push_back(val);
	}
	for (i = N - 1; i >= 0; i--)
	{
		while ((s.size() > 0) && (s.top() >= arr[i]))
			s.pop();
		if (s.size() == 0)
			v.push_back(-1);
		else
			v.push_back(s.top());
		s.push(arr[i]);
	}
	reverse(v.begin(), v.end());
	for (auto x : v)
		cout << x << " ";
}