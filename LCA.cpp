const ll LOG = 20;
vll adj[N];
ll up[N][LOG];
ll depth[N];


void dfs(ll s, ll p = -1)
{
	for (auto k : adj[s])
	{
		if (k != p)
		{
			depth[k] = depth[s] + 1;

			up[k][0] = s;
			for (ll i = 1; i < LOG; i++)
				up[k][i] = up[ up[k][i - 1] ][i - 1];

			dfs(k, s);
		}
	}
}

ll lca(ll a, ll b)
{
	if (depth[a] < depth[b])
		swap(a, b);

	ll k = depth[a] - depth[b];

	for (ll i = 0; i < LOG; i++)
	{
		if (k & (1 << i))
			a = up[a][i];
	}

	if (a == b)
		return a;

	for (ll i = LOG - 1; i >= 0 ; i--)
	{
		if (up[a][i] != up[b][i])
		{
			a = up[a][i];
			b = up[b][i];
		}
	}

	return up[a][0];
}
