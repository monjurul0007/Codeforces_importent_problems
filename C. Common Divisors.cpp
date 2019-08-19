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
    	int n;
    	cin >> n;
    	ll num,gcd,cnt = 0;
    	cin >> num;
    	gcd = num;
    	for(int i=1; i<n; i++){
			cin >> num;
			gcd = gcd(num,gcd);
		}
		
		ll l = sqrt(gcd);
		for(int i=1; i<=l; i++){
			if(gcd%i == 0){
				if(gcd/i == i)
					cnt++;
				else
					cnt += 2;
			}
		}
				
		cout << cnt << endl;
		
    	return 0;
    }
 
 
