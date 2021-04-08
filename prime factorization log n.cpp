vector<ll> spf;

vector<ll> factorize(ll x)
{
	vector<ll> ans;

	while (x > 1)
	{
		ans.pb(spf[x]);
		x = x / spf[x];
	}

	return ans;
}

void sieve(ll n)
{
	spf.resize(n + 5);

	for (ll i = 2; i <= n; i++)
	{
		if (i % 2 == 0)
			spf[i] = 2;
		else
			spf[i] = i;
	}

	for (ll i = 3; i <= n; i++)
	{
		if (spf[i] == i)
		{
			for (ll j = i * i; j <= n; j += i)
			{
				if (spf[j] == j)
					spf[j] = i;
			}
		}
	}
}
