vector<ll> primes;
vector<bool> prime;
void Sieve(ll n)
{
	prime.assign(n + 5, 1);
	prime[1] = false;
	for (ll i = 2; i<= n; i++)
	{
		if (prime[i])
		{
			primes.pb(i);
			for (ll j = i * i; j <= n; j += i)
			{
				prime[j] = false;
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

	ll t,N;
	t = 1;
  N=1e5;
  sieve(N);
	cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}
