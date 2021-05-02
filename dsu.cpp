ll par[300005];
ll r[300005];
ll ep[300005];
ll ext[300005];

ll get(ll x)
{
	return par[x] = (par[x] == x ? x : get(par[x]));
}

ll find(ll x)
{
	if (par[x] == x)
		return ep[x] - ext[x];

	return (ep[x] - ext[x] + find(par[x]));
}

void unin(ll a, ll b)
{
	ll p1 = get(a);
	ll p2 = get(b);

	if (r[p1] > r[p2])
		swap(p1, p2);

	if (p1 != p2)
	{
		par[p1] = p2;
		ext[p1] = ep[p2];
		r[p2] += r[p1];
	}
}
