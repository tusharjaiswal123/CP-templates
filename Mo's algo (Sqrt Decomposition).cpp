PROBLEM:

CODECHEF:https://www.codechef.com/problems/DDCC



SOLUTION:


#include<bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define fr(i,k) for(i=0;i<k;i++)
#define deb(x) cerr<<#x<<"  = "<<x<<endl;
#define deb2(x,y) cerr<<#x<<" = "<<x<<"  "<<#y<<" = "<<y<<endl;
#define print(x) for (auto k:x) cout<<k<<" ";cout<<endl;
#define SZ(x) (x).size();
#define ll long long
#define mod 1000000007
#define ff first
#define ss second
#define pb push_back
#define em emplace_back
#define ulli unsigned long long int
#define inf 1e18
#define endl "\n"
typedef vector<vector<ll>> vvll;
typedef vector<ll> vll;
typedef vector<pair<ll, ll>> vpll;
typedef pair<ll, ll> pll;
typedef vector<bool> vb;
void solve();
void pre();


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

ll a[300005];
ll cur_l, cur_r;
query queries[300005];
ll cost2freq[1000005];
ll cost;

struct query {

	ll L;
	ll R;
	ll q_no;
	ll block_no;

	bool operator < (query &q2)
	{
		if (block_no != q2.block_no)
			return block_no < q2.block_no;

		return R < q2.R;
	}
};

void Add(ll x)
{
	ll f = cost2freq[x];
	cost2freq[x]++;

	cost = cost - x * f * f + (f + 1) * (f + 1) * x;
}

void Remove(ll x)
{
	ll f = cost2freq[x];
	cost2freq[x]--;

	cost = cost - x * f * f + (f - 1) * (f - 1) * x;
}

void adjust(ll i)
{

	while (cur_l > queries[i].L)
	{
		cur_l--;
		Add(a[cur_l]);
	}

	while (cur_r < queries[i].R)
	{
		cur_r++;
		Add(a[cur_r]);
	}

	while (cur_l < queries[i].L)
	{
		Remove(a[cur_l]);
		cur_l++;
	}

	while (cur_r > queries[i].R)
	{
		Remove(a[cur_r]);
		cur_r--;
	}
}

inline void solve()
{
	ll n, sn, q, i, l, r;
	cin >> n >> q;

	sn = (ll)sqrt(n);
	vector<ll> ans(q);

	for (i = 0; i < n; i++)
		cin >> a[i];

	for (i = 0; i < q; i++)
	{
		cin >> l >> r;
		l--;
		r--;

		queries[i].L = l;
		queries[i].R = r;
		queries[i].q_no = i;
		queries[i].block_no = (l + 1) / sn;
	}

	sort(queries, queries + q);

	ll cur_l = queries[0].L;
	ll cur_r = queries[0].R;

	cost = 0;
	for (i = cur_l; i <= cur_r; i++)
	{
		Add(a[i]);
	}

	ans[queries[0].q_no] = cost;

	for (i = 1; i < q; i++)
	{
		adjust(i);
		ans[queries[i].q_no] = cost;
	}


	for (auto k : ans)
		cout << k << endl;

}


