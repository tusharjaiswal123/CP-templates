#include<bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define deb(x) cerr<<#x<<"  = "<<x<<endl;
#define deb2(x,y) cerr<<#x<<" = "<<x<<"  "<<#y<<" = "<<y<<endl;
#define print(x) for (auto k:x) cout<<k<<" ";cout<<endl;
#define debmp(x) for(auto k:x) cout<<k.first<<" "<<k.second<<endl;
#define ll long long
#define lld long double
#define mod1 1000000007
#define mod2 998244353
#define ff first
#define ss second
#define pb push_back
#define inf 1e18
#define endl "\n"
typedef vector<vector<ll>> vvll;
typedef vector<ll> vll;
typedef vector<pair<ll, ll>> vpll;
typedef pair<ll, ll> pll;
typedef vector<bool> vb;

ll mod = mod1;

string to_str(ll n) {string ans = ""; while (n) {ans += (n % 10 + '0'); n = n / 10;} reverse(ans.begin(), ans.end()); return ans;}
ll add(ll a, ll b) {a = a % mod; b = b % mod; return ((a + b) % mod + mod) % mod;}
ll sub(ll a, ll b) {a = a % mod; b = b % mod; return ((a - b) % mod + mod) % mod;}
ll mul(ll a, ll b) {a = a % mod; b = b % mod; return ((1ll * a * b) % mod + mod) % mod;}
ll expo(ll a, ll n) {ll ans = 1; a = a % mod; while (n) {if (n % 2) {ans = ((ans % mod) * (a % mod)) % mod; n--;} else {a = ((a % mod) * (a % mod)) % mod; n = n / 2;}} return ans;}
ll dv(ll a, ll b) {a = a % mod; b = b % mod; return (a * expo(b, mod - 2)) % mod;}
ll pw(ll a, ll n) {ll ans = 1; while (n) {if (n % 2) {ans = ans * a; n--;} else {a = a * a; n = n / 2;}} return ans;}
ll modinv(ll a) {return expo(a, mod - 2);}

void solve();


int main() {
	fastio;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	ll t;
	t = 1;

	//cin >> t;
	for (ll test = 1; test <= t; test++)
	{
		//cout << "Case #" << test << ": ";
		solve();
	}
	return 0;
}

typedef ll item;

/*struct item {
	ll a,b
};*/

struct segtree {

	vector<item> node;
	ll size;
	item NEUTRAL_ELEMENT = {0};
	void init(ll n)
	{
		size = 1;
		while (size < n)
			size *= 2;

		node.assign(2 * size, NEUTRAL_ELEMENT);
	}

	item merge(item a, item b)
	{
		return a + b;
	}

	item single(ll v)
	{
		return v;
	}

	void build(vll &a, ll i, ll l, ll h)
	{
		if (h - l == 1)
		{
			if (l < a.size())
			{
				node[i] = single(a[l]);
			}
			return;
		}

		ll m = l + (h - l) / 2;

		build(a, 2 * i + 1, l, m);
		build(a, 2 * i + 2, m, h);

		node[i] = merge(node[2 * i + 1], node[2 * i + 2]);
	}

	void build(vll &a)
	{
		build(a, 0, 0, size);
	}

	void set(ll x, ll val, ll i, ll l, ll h)
	{
		if (h - l == 1)
		{
			node[i] = single(val);
			return;
		}

		ll m = l + (h - l) / 2;

		if (x < m)
			set(x, val, 2 * i + 1, l, m);
		else
			set(x, val, 2 * i + 2, m, h);

		node[i] = merge(node[2 * i + 1], node[2 * i + 2]);
	}

	void set(ll x, ll val)
	{
		set(x, val, 0, 0, size);
	}

	item query(ll l, ll h, ll i, ll sl, ll sh)
	{
		if (sl >= h || l >= sh)
			return NEUTRAL_ELEMENT;

		if (sl >= l && sh <= h)
			return node[i];

		ll m = sl + (sh - sl) / 2;

		item s1 = query(l, h, 2 * i + 1, sl, m);
		item s2 = query(l, h, 2 * i + 2, m, sh);


		return merge(s1, s2);
	}

	item query(ll l, ll r)
	{
		return query(l, r, 0, 0, size);
	}

};

const ll N = 200005;

ll a[N];
vll adj[N];
ll timer;
ll in[N];
ll out[N];
vll v;

void dfs(ll s, ll p)
{
	v.pb(a[s]);
	in[s] = timer++;
	for (auto k : adj[s])
	{
		if (k != p)
		{
			dfs(k, s);
		}
	}

	v.pb(a[s]);
	out[s] = timer++;
}

inline void solve()
{
	ll n, i, q, k, s, x;
	cin >> n >> q;

	for (i = 0; i < n; i++)
		cin >> a[i];

	for (i = 0; i < n - 1; i++)
	{
		ll x, y;
		cin >> x >> y;
		x--;
		y--;

		adj[x].pb(y);
		adj[y].pb(x);
	}

	timer = 0;
	dfs(0, -1);

	segtree seg;
	seg.init(2 * n + 1);
	seg.build(v);

	for (i = 0; i < q; i++)
	{
		cin >> k;

		if (k == 1)
		{
			cin >> s >> x;
			s--;

			seg.set(in[s], x);
			seg.set(out[s], x);
		}
		else
		{
			cin >> s;
			s--;

			ll ans = seg.query(in[s], out[s] + 1);
			ans = ans / 2;
			cout << ans << endl;
		}
	}

}
