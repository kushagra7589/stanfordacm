#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double


struct Point {
	ld x, y;

	bool operator < (const Point &p) const {
		return x < p.x || (x == p.x && y < p.y);
	}
};

ld cross(const Point &O, const Point &A, const Point &B)
{
	return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}

vector<Point> convex_hull(vector<Point> P)
{
	int n = P.size();
	int k = 0;
	vector<Point> H(2*n);

	sort(P.begin(), P.end());

	for(int i=0; i<n; i++)
	{
		while(k >= 2 && cross(H[k-2], H[k-1], P[i]) <= 0) k--;
		H[k++] = P[i];
	}

	for(int i=n-2, t = k+1; i>=0; i--)
	{
		while(k >= t && cross(H[k-2], H[k-1], P[i]) <= 0) k--;
		H[k++] = P[i];
	}

	H.resize(k-1);
	return H;
}

int main()
{
	ios_base::sync_with_stdio(false);
	return 0;
}