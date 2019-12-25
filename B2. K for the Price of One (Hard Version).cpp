/* problem link: https://codeforces.com/contest/1282/problem/B2
 * problem tag : brute force, dp, greedy, sorting.
 * 
 * my solution is sorting+greedy
 * 
 * here i constructed a tree structure for finding a greedy solution, the tree look like this:
 * 
 *					         (0)
 * 	                                        /   \
 *                                            (1)  (0+k)
 *                                           /   \    \
 * 					   (2)  (1+k) (0+2k)
 * 					   / \      \      \
 * 					 (3) (2+k) (1+2k) (0+3k)
 *					 / \    \      \      \
 * 
 * 	                            (i<k-1) <> (i+k-1 < n) and so on 
*/


#include<bits/stdc++.h>
     
using namespace std;
     
#define fasterInOut ios::sync_with_stdio(false); cin.tie(0);
#define pb push_back
#define inf INT_MAX
#define neginf LLONG_MIN
#define wk cout << "working" << endl
#define s second
#define f first

         
typedef long long int ll;     
typedef pair<int , int>  pii;
typedef pair<int , pii > piii; 
typedef priority_queue<pii, vector<pii> , greater<pii> > pq; 

int n,p,k,arr[200005];

int solve(int i, int state, int price){
	
	if(i >= n)
		return n;
	
	int res1, res2;
		
	if(state == 0 && arr[i] <= price && i<k-1){
		res1 = solve(i+1, 0, price-arr[i]);
	}   
	else{
		res1 = i;
	}
	
	if(i+k-1 < n && arr[i+k-1] <= price)
		res2 = solve(i+k, 1, price-arr[i+k-1]);
	else
		res2 = i;
		
	return max(res1,res2);
}

int main(){
	fasterInOut;	
	int t;
	
	cin >> t;
	
	while(t--){
		cin >> n >> p >> k;
		
		for(int i=0; i<n; i++)
			cin >> arr[i];
		
		sort(arr, arr+n);
		
		cout << solve(0,0,p) << "\n";
	}
	
	return 0;
}

