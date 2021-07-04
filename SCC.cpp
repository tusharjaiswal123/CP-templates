struct SCC {

	ll N;
	vvll adj, radj;
	vll todo, comps, comp;
	vb vis;

	void init(ll n)
	{
		N = n;
		adj.resize(N);
		radj.resize(N);
		comp = vll(N, -1);
		vis.resize(N);
	}

	void ae(ll x, ll y)
	{
		adj[x].pb(y);
		radj[y].pb(x);
	}

	void dfs(ll x)
	{
		vis[x] = 1;
		for (auto k : adj[x])
		{
			if (!vis[k])
				dfs(k);
		}

		todo.pb(x);
	}

	void dfs2(ll x, ll v)
	{
		comp[x] = v;

		for (auto k : radj[x])
		{
			if (comp[k] == -1)
				dfs2(k, v);
		}
	}

	void gen(ll n)
	{
		// fills allComp
		for (ll i = 1; i <= n; i++)
		{
			if (!vis[i])
				dfs(i);
		}

		reverse(todo.begin(), todo.end());

		for (auto k : todo)
		{
			if (comp[k] == -1)
			{
				dfs2(k, k);
				comps.pb(k);
			}
		}
	}
};
