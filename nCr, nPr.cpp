// nCr using pascal's triangle for n upto 1005 and r upto 1005

ll dp[1005][1005];

void preCalc()
{
	memset(dp, -1, sizeof dp);

	for (int i = 1; i < 1005; i++)
	{	
		dp[i][0] = 1;
		dp[i][1] = i;
		dp[i][i] = 1;

		for (int j = 2; j < i; j++)
			dp[i][j] = add(dp[i - 1][j - 1], dp[i - 1][j]);
	}
}


vector<ll> FACT;

void preFactModulo(ll n) 
{
	FACT.resize(n + 5); 
	FACT[0] = 1; 
	
	for (ll i = 1; i < n + 5; i++)
		FACT[i] = mul(FACT[i - 1], i);
}

ll ncr(ll n, ll r)
{
	if (r > n)
		return 0;

	return mul(fact[n],mul(modinv(fact[n - r]),modinv(fact[r])));
}

ll npr(ll n, ll r)
{
	if (r > n)
		return 0;
	
	return mul(fact[n],modinv(fact[n - r]));
}

int main() {
	fastio;

	ll t;
	t = 1;
	preFactModulo(60);

	cin >> t;
	for (ll test = 1; test <= t; test++)
	{
		// cout << "Case #" << test << ": ";
		solve();
	}
	return 0;
}
