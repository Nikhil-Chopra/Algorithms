//Problem Link - https://www.spoj.com/problems/INVCNT/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define pb push_back
#define IOS ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define Test int T;cin>>T;while(T--)
#define ls lower_bound
#define up upper_bound
#define bs binary_search
#define S second
#define F first
#define vi vector<int>  
#define pii pair<int,int>
#define vpi vector<pii>
#define gcd(a,b) __gcd((a),(b))
#define lcm(a,b) ((a)*(b))/gcd((a),(b))
#define m_n(v) *min_element(all(v))
#define m_x(v) *max_element(all(v))
/* 
#include <ext/pb_ds/assoc_container.hpp> using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>indexed_set;
*/
int power(int x, int y,int mod){
    int res = 1;
    while (y)
    {
        if (y & 1)
        res = (res*x)%mod;
        y = y>>1;
        x = (x*x)%mod;
    }
    return res;
}
int modInverse(int a, int m){
    int m0 = m;
    int y = 0, x = 1;

    if (m == 1)
      return 0;

    while (a > 1)
    {
        int q = a / m;
        int t = m;
        m = a % m, a = t;
        t = y;
        y = x - q * y;
        x = t;
    }
    if (x < 0)
       x += m0;

    return x;
}
int binomial(int n,int k){
    int res = 1;
    if ( k > n - k )
        k = n - k;

    for (int i = 0; i < k; ++i)
    {
        res *= (n - i);
        res /= (i + 1);
    }

    return res;
}
/*vector<int> prime;
void sieve(){
    bool arr[300000]={0};
    prime.pb(2);
    for(int i=3;i<300000;i+=2){
        if(arr[i])continue;
        for(int j=i*i;j<300000;j+=i) arr[j]=1;
        prime.pb(i);
    }
}*/
const int mod=1e7+1;;
int mx;
int bt[mod];
void update(int index)
{
    while(index<=mx)
    {
        bt[index]+=1;
        index += index&-index;
    }
}
int get(int index)
{
    int result=0;
    while(index>0)
    {
        result+=bt[index];
        index -= index&-index;
    }
    return result;
}

int32_t main() {
    IOS;
    int t;
    cin>>t;
    while(t--)
    {
        memset(bt,0,sizeof(bt));
        int n;
        cin>>n;
        vector<int> v(n);
        for(auto &i:v) cin>>i;
        mx = m_x(v);
        int ans=0;
        for(auto i:v){
            update(i);
            ans += get(mx)-get(i);
        }
        cout<<ans<<"\n";
    }
    return 0;
}
