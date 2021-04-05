struct FenwickTree {
	vector<ll> bit;  // binary indexed tree
	ll n;

	FenwickTree(ll n)
	{
		this->n = n;
		bit.assign(n, 0);

		//build(a);
	}

	void build(vll &a)
	{
		ll i;
		for (i = 0; i < a.size(); i++)
			add(i, a[i]);
	}


	ll query(ll r)
	{
		ll ans = 0;

		for (; r >= 0; r = (r & (r + 1)) - 1)
		{
			ans += bit[r];
		}

		return ans;
	}

	ll query(ll l, ll r) {
		return query(r) - query(l - 1);
	}

	void add(ll idx, ll delta) {
		for (; idx < n; idx = idx | (idx + 1))
			bit[idx] += delta;
	}
};
