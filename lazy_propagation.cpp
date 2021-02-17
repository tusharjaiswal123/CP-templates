typedef ll item;

// struct item{
// 	ll a,b;
// };

struct segtree
{
	vector<ll> operations;
	vector<item> node;
	ll size;
	ll NEUTRAL_ELEMENT = 0;
	ll NO_OPERATION = LLONG_MAX - 1;


	item mul_op(item a, item b, ll len)
	{
		if (b == NO_OPERATION)
			return a;

		return b * len;
	}

	item add_op(item a, item b)
	{
		return a + b;
	}

	void apply_mod_op(item &a, item b, ll len)
	{
		a = mul_op(a, b, len);
	}

	void propagate(ll i, ll lx, ll rx)
	{
		if (rx - lx == 1)
			return;

		ll m = lx + (rx - lx) / 2;

		apply_mod_op(operations[2 * i + 1], operations[i], 1);
		apply_mod_op(operations[2 * i + 2], operations[i], 1);
		apply_mod_op(node[2 * i + 1], operations[i], m - lx);
		apply_mod_op(node[2 * i + 2], operations[i], rx - m);

		operations[i] = NO_OPERATION;
	}

	void build(ll i, ll lx, ll rx)
	{
		if (rx - lx == 1)
		{
			node[i] = 1;
			return;
		}

		ll m = lx + (rx - lx) / 2;

		build(2 * i + 1, lx, m);
		build(2 * i + 2, m, rx);

		node[i] = add_op(node[2 * i + 1] , node[2 * i + 2]);
	}

	void init(ll n)
	{
		size = 1;
		while (size < n)
			size *= 2;

		operations.assign(2 * size, 0);
		node.assign(2 * size, 0);

		//build(0, 0, size);
	}

	item get(ll l, ll r, ll i, ll lx, ll rx)
	{
		propagate(i, lx, rx);
		if (lx >= r || l >= rx)
			return NEUTRAL_ELEMENT;

		if (lx >= l && rx <= r)
		{
			return node[i];
		}

		ll m = lx + (rx - lx) / 2;

		item m1 = get(l, r, 2 * i + 1, lx, m);
		item m2 = get(l, r, 2 * i + 2, m, rx);

		return add_op(m1 , m2);
	}

	item get(ll l, ll r)
	{
		return get(l, r, 0, 0, size);
	}

	void add(ll l, ll r, ll v, ll i, ll lx, ll rx)
	{
		propagate(i, lx, rx);
		if (lx >= r || l >= rx)
			return;

		if (lx >= l && rx <= r)
		{
			apply_mod_op(operations[i], v, 1);
			apply_mod_op(node[i], v, rx - lx);
			return;
		}

		ll m = lx + (rx - lx) / 2;

		add(l, r, v, 2 * i + 1, lx, m);
		add(l, r, v, 2 * i + 2, m, rx);

		node[i] = add_op(node[2 * i + 1] , node[2 * i + 2]);
	}

	void add(ll l, ll r, ll v)
	{
		return add(l, r, v, 0, 0, size);
	}


};
