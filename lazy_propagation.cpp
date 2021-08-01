typedef ll item;

/*struct item {
	ll a,b
};*/

struct segtree
{
	vector<ll> operations;
	vector<item> node;
	vector<bool> lazy;
	ll size;
	ll NEUTRAL_ELEMENT = 0;

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

	void init(ll n)
	{
		size = 1;
		while (size < n)
			size *= 2;

		operations.assign(2 * size, 0);
		node.assign(2 * size, 0);
		lazy.assign(2 * size, false);
	}

	void apply(ll i, ll lx, ll rx, ll v)
	{
		node[i] += v * (rx - lx);

		if (rx - lx == 1)
			return;

		lazy[i] = true;
		operations[i] += v;
	}


	void propagate(ll i, ll lx, ll rx)
	{
		if (lazy[i])
		{
			lazy[i] = false;

			ll m = lx + (rx - lx) / 2;
			apply(2 * i + 1, lx, m, operations[i]);
			apply(2 * i + 2, m, rx, operations[i]);

			operations[i] = 0;
		}
	}


	ll query(ll l, ll r, ll i, ll lx, ll rx)
	{
		if (lx >= r || l >= rx)
			return NEUTRAL_ELEMENT;

		if (lx >= l && rx <= r)
			return node[i];

		propagate(i, lx, rx);
		ll m = lx + (rx - lx) / 2;

		ll m1 = query(l, r, 2 * i + 1, lx, m);
		ll m2 = query(l, r, 2 * i + 2, m, rx);

		return merge(m1 , m2);
	}

	ll query(ll l, ll r)
	{
		return query(l, r, 0, 0, size);
	}

	void rupd(ll l, ll r, ll v, ll i, ll lx, ll rx)
	{
		if (lx >= r || l >= rx)
			return;

		if (lx >= l && rx <= r)
		{
			apply(i, lx, rx, v);
			return;
		}

		propagate(i, lx, rx);
		ll m = lx + (rx - lx) / 2;

		rupd(l, r, v, 2 * i + 1, lx, m);
		rupd(l, r, v, 2 * i + 2, m, rx);

		node[i] = merge(node[2 * i + 1] , node[2 * i + 2]);
	}

	void rupd(ll l, ll r, ll v)
	{
		return rupd(l, r, v, 0, 0, size);
	}

};
