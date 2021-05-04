struct dsu
{
	vll par;
	vll r;

	void init(ll n)
	{
		r.assign(n + 10, 1);
		par.resize(n + 10);

		for (ll i = 1; i <= n + 5; i++)
		{
			par[i] = i;
		}
	}

	ll get(ll x)
	{
		return par[x] = (par[x] == x ? x : get(par[x]));
	}

	bool merge(ll a, ll b)
	{
		ll p1 = get(a);
		ll p2 = get(b);

		if (p1 != p2)
		{
			if (r[p1] > r[p2])
				swap(p1, p2);

			par[p1] = p2;
			r[p2] += r[p1];

			return true;
		}

		return false;
	}

};
