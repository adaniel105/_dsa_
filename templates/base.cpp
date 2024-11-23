#include <bits/stdc++.h>
using namespace std;

typedef long long				ll;
typedef long double         	ld;
typedef pair <int, int>     	pii;
typedef pair <ll, ll>       	pll;
typedef vector<int>				vi;
typedef vector<ll>				vll;
typedef vector<vector<int>>		vvi;
typedef vector<pair<int,int>>	vpi;

# define a          first
# define b          second
# define endl       '\n'
# define sep        ' '
# define all(x)     x.begin(), x.end()
# define kill(x)    return cout << x << endl, 0
# define sz(x)      int(x.size())
# define pb			push_back
# define rsz		resize
# define lc         id << 1
# define rc         id << 1 | 1
# define FOR(i,a,b)		for(int i=(a); i<(b); ++i)
# define F0R(i,b)		FOR(i,0,b)
# define ROF(i,a,b)		for(int i=(b)-1; i>=(a); --i)
# define R0F(i,b)		ROF(i,0,b)
# define foreach(x, a)	for(auto &x : a)
ll power(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));}
ll gcd(ll a, ll b){ if (a == 0) return b; if (a == 1) return 1; return gcd(b % a, a); }
ll lcm(ll a, ll b){ return (a * b) / gcd(a, b); }

const ll mod = 1e9 + 7;
const ll inf = 3e9;
const double pi = 3.141592;

void setIO(string name = "") {
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	if (!name.empty()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

const int N = 2e5 + 3;


int main() {
	// setIO("test");
}