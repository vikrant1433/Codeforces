using namespace std;
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstring>
#include <limits.h>

#define s(n)                         scanf("%d",&n)
#define sc(n)                        scanf("%c",&n)
#define sl(n)                        scanf("%lld",&n)
#define sf(n)                        scanf("%lf",&n)
#define ss(n)                        scanf("%s",n)
#define scana(a,t)                   for(int i = 0; i < t; i++){cin >> a[i];}

#define FOR(i,a,b)                	 for(int i=a;i<b;i++)
#define FOREACH(v, c)                for( typeof( (c).begin()) v = (c).begin();  v != (c).end(); ++v)
#define REP(i,a)                     for (int i=0; i<a; i++)

#define all(a)                        a.begin(), a.end()
#define in(a,b)                       ( (b).find(a) != (b).end())
#define pb                            push_back
#define fill(a,v)                     memset(a, v, sizeof a)
#define sz(a)                         ((int)(a.size()))

#define maX(a,b)                      ( (a) > (b) ? (a) : (b))
#define miN(a,b)                      ( (a) < (b) ? (a) : (b))
#define PI                     		  acos(-1)
#define sqr(x)                 		  ((x) * (x))

#define p(n)                          printf("%d\n",n)
#define pl(n)                         printf("%lld\n",n)
#define pul(n)                        printf("%llu\n", n);
#define pf(n)                         printf("%f\n",n)
#define pc(n)                         printf("%c\n",n)
#define ps(n)                         printf("%s\n",n)

#define sort(x)                       sort(all(x))

#define DEBUG(x)               		  { cerr << #x << " = " << x << endl; }
#define PR(a,n)                		  {cerr<<#a<<" = "; FOR(_,1,n) cerr << a[_] << ' '; cerr <<endl;}
#define PR0(a,n)               		  {cerr<<#a<<" = ";REP(_,n) cerr << a[_] << ' '; cerr << endl;}

#define numTest(t)                    int t; s(t); while(t--)

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;

typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<PII> VII;
typedef vector<PLL> VLL;

typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef vector<VII> VVII;
typedef vector<VLL> VVLL;

typedef vector<string> VS;
typedef vector<VS> VVS;

int maxContSubArray(int arr[], int k, int n, int s, int e)
{
	int a = s;
	LL curMax = 0;
	for (int i = s; i<s+k; ++i)
	{
        curMax += arr[i];
	}
	LL maxSoFar = curMax;
	for (int i = s+k; i < e; ++i)
	{
        curMax = curMax+ arr[i]-arr[i-k];
		if(curMax > maxSoFar)
		{
			a = i-k+1;
			maxSoFar = curMax;
		}
	}
	for (int i = a; i < a+k; ++i)
	{
		arr[i] = 0;
	}

	DEBUG(a);
	DEBUG(curMax); DEBUG(maxSoFar);
	PR0(arr,n);
	return a;

}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen ("in.txt", "r", stdin);
		// freopen ("out.txt", "w", stdout);
	#endif
	int n,k;
	s(n); s(k);
	int arr[200000];
	for (int i = 0; i < n; ++i)
	{
		s(arr[i]);
	}
	// PR0(arr,n);
	// int sum1, sum2;
	// sum1 = sum2 =0;
	// for (int i = 29; i <29+24 ; ++i)
	// {
	// 	sum1 += arr[i];
	// }
	// DEBUG(sum1)
	// for (int i = 66; i < 66+24; ++i)
	// {
	// 	sum2 += arr[i];
	// }
	// DEBUG(sum2)
	// int sum3 = 0;
	// for (int i = 74; i < 74+24; ++i)
	// {
	// 	sum3 += arr[i];
	// }
	// DEBUG(sum3)
	int a = maxContSubArray(arr,k,n,0,n-k);
	// int b = maxContSubArray(arr,k,n,k,n);
	// printf("%d %d\n",++a,++b);

	return 0;
}
