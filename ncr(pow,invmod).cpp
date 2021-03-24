vector<ll> fact;
void pre(ll n, ll m)
{
	fact.resize(n + 5);
	fact[0] = 1;

	for (ll i = 1; i < n+5; i++)
		fact[i] = (fact[i - 1] % m * i % m) % m;
}

ll pow(ll a, ll n, ll m)
{
	ll ans = 1;
	while (n)
	{
		if (n % 2)
		{
			ans = (ans % m * a % m);
			n--;
		}
		else
		{
			a = (a % m * a % m) % m;
			n = n / 2;
		}
	}
	return ans;
}

ll modinv(ll n)
{
	return pow(n, mod - 2, mod);
}

ll ncr(ll n, ll r, ll m)
{
	if (r > n)
		return 0;

	return (fact[n] % m * modinv(fact[n - r]) % m * modinv(fact[r]) % m) % m;
}

ll npr(ll n, ll r, ll m)
{
	if (r > n)
		return 0;

	return (fact[n] % m * modinv(fact[n - r]) % m) % m;
}

int main() {
	fastio;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	ll t, N;
	t = 1;
	N = 1e5;
	pre(N, mod);
	//cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}
