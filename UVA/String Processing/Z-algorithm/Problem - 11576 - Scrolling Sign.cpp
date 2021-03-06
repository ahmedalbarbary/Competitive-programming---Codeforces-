/*
idea is that we can make use of the latters that are common between two consecutive words such that I use only copy of them for both 
word and we can do this by deleting the number of letters in the max suffix of the word i that match prefix of the word i+1
i.e (abcc) + (cccb)  we can display them in this way   abcccb and both letter will be obtained in the scren 
*/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
const int sz = 205;
int z[sz];

void z_fun(string s, int z[])
{
	int l = 0, r = 0;
	for (int i = 1; i <= s.size(); i++)
	{
		// smart use of prvious match 
		if (i <= r)
			z[i] = min(z[i - l], r - i + 1); // length 

		// brute force 
		for (int j = z[i]; j < s.size() && j + i < s.size(); j++)
		{
			if (s[j] == s[i + j])
				z[i]++;
			else
				break;
		}

		if (i + z[i] - 1 > r) { // edit explored range 
			l = i;
			r = i + z[i] - 1;
		}
	}
	return;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n , k, ans = 0;
		cin >> n >> k;
		string prv, s;
		cin >> prv;
		ans = prv.size();

		for (int i=1; i < k; i++)
		{
			cin >> s;
			string tmp = s + "*" + prv;
			z_fun(tmp, z);
			// get max prefix of s that match suffix of prv 
			int maxi = 0;
			//cout << tmp << endl;
			for (int i = s.size() + 1; i < tmp.size(); i++) { // all strings are of equal size 
				//cout << z[i] << " ";
				if (z[i] + i == tmp.size()) {
					maxi = z[i];
					break;
				}
			}

			//cout << endl;
			ans += (s.size() - maxi);
			prv = s;


			// reinitialize 
			for (int i = 0; i <= 2 * s.size(); i++)
				z[i] = 0;
		}

		cout << ans << endl;
	}
	return 0;
}
