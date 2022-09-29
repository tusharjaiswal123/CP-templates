https://cp-algorithms.com/algebra/module-inverse.html#finding-the-modular-inverse-using-extended-euclidean-algorithm


1. For numbers in range [1,m-1] mod inverse m and m should be prime 

vector<ll> inv(m);
inv[1] = 1;

for(int i = 2; i < m; i++)
    inv[i] = sub(m, mul((m/i),inv[m%i]));



2. For all numbers in array mod inverse m

ll extended_euclidean(ll a, ll b, ll &x, ll &y) 
{
    if (a == 0) {
        x = 0; y = 1;
        return b;
    }
    ll x1, y1;
    ll d = ex_gcd(b%a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

vector<int> invs(vector<int> &a, int m) 
{
    int n = a.size();
    if (n == 0) 
      return {};
  
    vector<ll> b(n);
  
    ll v = 1;
    for (int i = 0; i < n; i++) 
    {
        b[i] = v;
        v = muil(v,a[i]);
    }
  
    int x, y;
    extended_euclidean(v, m, x, y);
  
    x = add(x, m);
  
    for (int i = n - 1; i >= 0; i--) 
    {
        b[i] = mul(x,b[i]);
        x = mul(x,a[i]);
    }
  
    return b;
}
