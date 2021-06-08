map<ll,ll>prime;
void fac(ll n)
{
    for(int i=2;i<=n/i;i++)
    { 
          while(n%i==0)
        {
            prime[i]++;
            n=n/i;
        }
    }
    if(n>1) prime[n]++;
}
