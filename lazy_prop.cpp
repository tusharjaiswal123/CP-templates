typedef ll item;
 
// struct item
// {
// 	ll a,b;
// };
 
struct segTree {
 
	ll size;
	item NO_OPERATION = LLONG_MAX;
	vector<item> node;
 
	void init(ll n)
	{
		size = 1;
		while (size < n)
			size = size * 2;
 
		node.assign(2 * size, 0);
	}
 
	item operation(ll a, ll b)
	{
		if (b == NO_OPERATION)
			return a;
 
		return b;
	}
 
	void apply_operation(ll &a, ll b)
	{
		a = operation(a, b);
	}
 
	void propagate(ll i, ll lx, ll rx)
	{
		if (rx - lx == 1)
			return;
 
		apply_operation(node[2 * i + 1], node[i]);
		apply_operation(node[2 * i + 2], node[i]);
		node[i] = NO_OPERATION;
	}
 
	void add(ll l, ll h, ll v, ll i, ll lx, ll rx)
	{
		propagate(i, lx, rx);
		if (lx >= h || l >= rx)
			return;
 
		if (lx >= l && rx <= h)
		{
			apply_operation(node[i], v);
			return;
		}
 
		ll m = lx + (rx - lx) / 2;
 
		add(l, h, v, 2 * i + 1, lx, m);
		add(l, h, v, 2 * i + 2, m, rx);
 
	}
 
	void add(ll l, ll r, ll v)
	{
		add(l, r, v, 0, 0, size);
	}
 
	item get(ll x, ll i, ll lx, ll rx)
	{
		propagate(i, lx, rx);
		if (rx - lx == 1)
			return node[i];
 
		ll m = lx + (rx - lx) / 2;
 
		ll res;
		if (x < m)
		{
			res = get(x, 2 * i + 1, lx, m);
		}
		else
		{
			res = get(x, 2 * i + 2, m, rx);
		}
 
		return res;
	}
 
	item get(ll x)
	{
		return get(x, 0, 0, size);
	}
 
};
 
inline void solve()
{
	ll n, m, i, l, r, v, idx, op;
	cin >> n >> m;
 
	segTree seg;
	seg.init(n);
 
	for (i = 0; i < m; i++)
	{
		cin >> op;
 
		if (op == 1)
		{
			cin >> l >> r >> v;
			seg.add(l, r, v);
		}
		else
		{
			cin >> idx;
			cout << seg.get(idx) << endl;
		}
	}
}
