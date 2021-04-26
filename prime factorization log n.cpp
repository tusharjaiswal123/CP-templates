vector<ll> spf;

vector<pair<ll, ll>> factorize(ll x)
{
	vector<pair<ll, ll>> ans;
	ll p, e;

	while (x > 1)
	{
		p = spf[x];
		e = 0;

		while (x % p == 0)
		{
			x = x / p;
			e++;
		}
		ans.pb({p, e});
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

int main() {
	fastio;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	ll t;
	t = 1;


	ll N = 1e7;
	sieve(N);
	//cin >> t;
	for (ll test = 1; test <= t; test++)
	{
		//cout << "Case #" << test << ": ";
		solve();
	}
	return 0;
}
