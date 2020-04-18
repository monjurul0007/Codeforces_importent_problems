#include <bits/stdc++.h>

using namespace std;

#define fasterInOut ios::sync_with_stdio(false); cin.tie(0);
#define pb push_back
#define inf INT_MAX
#define neginf LLONG_MIN
#define wk cout << "working" << endl
#define all(x) x.begin(),x.end()
#define mem(arr,value) memset(arr, value, sizeof(arr))
#define mod 100000007
#define F first  
#define S second   

typedef long long int ll;     
typedef pair<int , int>  pii;
typedef pair<int , pii > piii; 
typedef priority_queue <pii, vector<pii> , greater<pii> > pq;

vector < pair<ll,ll> > v;
int dp[5005];
int dir[5005];
int n;

int lis(int u){
	if(dp[u] != -1)
		return dp[u];
	int mx = 0;
	
	for(int i = u+1; i<=n; i++){
		if(v[i].F > v[u].F && v[i].S > v[u].S){
			if(lis(i) > mx){
				mx = lis(i);
				dir[u] = i;
			}
		}
	}
	
	dp[u] = 1 + mx;
	return dp[u];
}

int main(){
	fasterInOut;
	
	ll w,h,a,b;

	map < pair<ll,ll> , int > mp; 
	cin >> n >> w >> h;
	
	v.pb({w,h});
	for(int i=1; i<=n; i++){
		cin >> a >> b;
		mp[{a,b}] = i;
		v.pb({a,b});
	}
	
	sort(v.begin()+1, v.end());
	
	mem(dp, -1);
	int mx = lis(0),u = 0;
	cout << mx-1 << "\n";
	for(int i=0; i<mx-1; i++){
		u = dir[u];
		cout << mp[v[u]] << " ";
	}
	cout << endl;
	
    return 0;
}
