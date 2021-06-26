struct fenwick {
	vector<ll> bit;  // binary indexed tree
	ll n;

	void init(ll size)
	{
		n = size;
		bit.assign(n+1, 0);
	}

	void build(ll a[])
	{
		for (ll i = 0; i < n; i++)
			update(i, a[i]);
	}


	ll query(ll x)
	{
		ll ans = 0;
		for (ll i=x; i > 0; i -= i&-i)
			ans += bit[i];

		return ans;
	}
	
	// zero based indexing 
	ll query(ll l, ll r)
	{
		return query(r+1) - query(l);
	}
	
	// zeno based indexing
	void update(ll x, ll v)
	{	
		x++;
		for (ll i=x; i<=n; i += i&-i)
			bit[i] += v;
	}
};



Sum in 2D:

struct fenwick{
	
    vector<vector<int>> bit;
    int n, m;

    void init(ll nn,ll mm)
    {
	 n = nn;
	 m = mm;
	 bit = vector<vector<int>> (nn+1,vector<int(mm+1,0));
    }
    
    //zero based indexing
    int sum(int x, int y)
    {	
	x++;
	y++;
        int ans = 0;
        for (int i = x; i >= 0; i -= i & -i)
            for (int j = y; j >= 0; j -= j & -j)
                ret += bit[i][j];
	    
        return ans;
    }
    
    //zero based indexing
    void add(int x, int y, int v)
    {	
	x++;
	y++;
        for (int i = x; i <= n; i += i & -i )
            for (int j = y; j <= m; j += j & -j)
                bit[i][j] += v;
    }
};
