
ll ex_gcd(ll a, ll b, ll &x, ll &y) {
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

ll inverse(ll a, ll m)
{
    ll x,y;
    ll d=ex_gcd(a,m,x,y);
    if(x<0) x += m;
    /// if answer does not exist
    if(d!=1) return -1;
    return x;
}
