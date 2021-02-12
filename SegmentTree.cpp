typedef ll item;

/*struct item {
	ll a,b
};*/

struct segtree {

	vector<item> node;
	ll size;
	item NEUTRAL_ELEMENT={0,0};
	void init(ll n)
	{
		size = 1;
		while (size < n)
			size *= 2;

		node.assign(2 * size,NEUTRAL_ELEMENT);
	}

	item merge(item a, item b)
	{	
	  return a+b;
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
