PROBLEM:

Given two numbers L and R (inclusive) find the product of primes within this range. Print the product modulo 10^9+7. If there are no
primes in that range you must print 1.
 

Input
The first line of the input contains T the number of test cases.  Then T lines follow. Each test case contains one line , having two
values L and R which denotes the range of the numbers.

Output
For each test case print the product modulo 10^9+7 in a new line.
 

Constraints :             
1<=T<=50

1<=L,R<=10^9

0<=R-L<=10^6
 

Example

Input
 2
 1 10
 1 20


 Output : 
 210
 9699690
 
 
 SOLUTION:


#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

void sieve(vector<int>& p,int n)
{   
    
    vector<bool> isprime(n+1,false);
    isprime[0]=isprime[1]=true;
    int i,j;
    
    for(int i=2;i*i<=n;i++)
    {
        if(isprime[n]==false)
        {
            for(int j=i*i;j<=n;j+=i)
            isprime[j]=true;
        }
    }
    
    for(i=2;i<=n;i++)
    {
        if(isprime[i]==false)
        p.push_back(i);
    }
}

int main() {
    
    vector<int> p;
    int limit=10000;
    sieve(p,limit);
    
	int t;
	cin>>t;
	
	while(t--)
	{
	    long long l,r,i,curr,base,ans=1,j;
	    cin>>l>>r;
	    vector<bool> prime(r-l+1,false);
	    
	    for(i=0;p[i]*p[i]<=r;i++)
	    {
	        curr=p[i];
	        base=(l/curr)*curr;
	        
	        if(base<l)
	        base=base+curr;
		    
		if(base==curr)
		base+=curr;
	        
	        for(j=base;j<=r;j+=curr)
	        {
	            prime[j-l]=true;
	        }
	    }
		
	     if(l==1)
		     prime[0]=true;
	    
	    for(i=0;i<=r-l;i++)
	    {
	        if(prime[i]==false)
	        {
	            ans=(ans*(l+i))%MOD;
	        }
	    }
	    
	    cout<<ans<<endl;
	}
	return 0;
}
