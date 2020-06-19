//Problem Link - https://codeforces.com/problemset/problem/61/E


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
#include <ext/pb_ds/assoc_container.hpp> 
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>  indexed_set;
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
int n;
const int N = 1e6+9;
int bit[N][2] = {0};
int b[N];
void update(int in,int val,int ind){
    while(in<=n){
        bit[in][ind] += val;
        in += in & -in;
    }
}

int sum(int in,int ind){
    int ans=0;
    while(in>0){
        ans += bit[in][ind];
        in -= in & -in;
    }
    return ans;
}

int32_t main() {
    IOS;
    cin>>n;
    pair<int,int> v[n+2];
    for(int i=1;i<=n;i++){
        cin>>v[i].F;
        v[i].S = i;
    }    
    sort(v+1,v+n+1);
    for(int i=1;i<=n;i++){
        b[v[i].S] = i;
    }
    for(int i=2;i<=n;i++){
        update(b[i],1,1);
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        int leftsum = sum(b[i],0);
        int rightsum = sum(b[i]-1,1);
        int efectiveleft = (i-1) - leftsum;
        ans += efectiveleft*rightsum;
        update(b[i],1,0);
        if(i<n) update(b[i+1],-1,1);
    }
    cout<<ans;
    return 0;
}
