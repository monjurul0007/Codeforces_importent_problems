    #include <bits/stdc++.h>
     
    #define fasterInOut ios::sync_with_stdio(false); cin.tie(0);
    #define fin(i) freopen(i, "r", stdin)
    #define fout(o) freopen(o, "w", stdout)
    #define pb push_back
    #define ll long long int
    #define inf LLONG_MAX
    #define neginf LLONG_MIN
    #define wk cout << "working" << endl
     
    #define gcd(a,b) __gcd(a,b)
    #define lcm(a, b) (a*b)/gcd(a, b)
    #define pi acos(-1.0)
     
    using namespace std;
     
    int main(){
    	fasterInOut;
    	//fin("input.txt");
    	
    	ll arr[200005],n,cnt=1;
    	cin >> n;
    	for(int i=0; i<n; i++){
    		if(i%2 == 0){
    			arr[i] = cnt++;
    			arr[n+i] = cnt++;
    		}
    		else{
    			arr[n+i] = cnt++;
    			arr[i] = cnt++;
    		} 
    	}
    	
    	if(arr[2*n-1] == 2*n){
    		cout << "YES" << endl;
    		for(int i=0; i<2*n; i++)
    			cout << arr[i] << " ";
    		cout << endl;
    	}
    	else
    		cout << "NO" << endl;
    	return 0;
    }
