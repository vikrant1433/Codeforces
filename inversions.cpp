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

#define s(n)                         scanf("%d",&n)
#define sc(n)                        scanf("%c",&n)
#define sl(n)                        scanf("%lld",&n)
#define sf(n)                        scanf("%lf",&n)
#define ss(n)                        scanf("%s",n)
#define scana(a,t)                   for(int i = 0; i < t; i++){cin >> a[i];}

#define forall(i,a,b)                for(int i=a;i<b;i++)
#define foreach(v, c)                for( typeof( (c).begin()) v = (c).begin();  v != (c).end(); ++v)
#define rep(i,a)                     for (int i=0; i<a; i++)

#define all(a)                        a.begin(), a.end()
#define in(a,b)                       ( (b).find(a) != (b).end())
#define pb                            push_back
#define fill(a,v)                     memset(a, v, sizeof a)
#define sz(a)                         ((int)(a.size()))

#define maX(a,b)                      ( (a) > (b) ? (a) : (b))
#define miN(a,b)                      ( (a) < (b) ? (a) : (b))

#define p(n)                          printf("%d\n",n)
#define pl(n)                         printf("%lld\n",n)
#define pul(n)                        printf("%llu\n", n);
#define pf(n)                         printf("%f\n",n)
#define pc(n)                         printf("%c\n",n)
#define ps(n)                         printf("%s\n",n)

#define sort(x)                       sort(all(x))

#define freopen_in                    freopen("in.txt","r",stdin);
#define freopen_out                   freopen("out.txt","w",stdout);
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


void copyBack(int temp[], int a[], int i, int j)
{
	int s=0;
	while(i <= j)
	{
		a[i++] = temp[s++];
	}
}
void mergeSplitCount(int a[], int i, int mid, int j, ULL& sum)
{
	int* temp = new int[j-i+1];
	int k=0, m = mid+1, f=i;
	while(1)
	{
		if (i<=mid && m<=j && a[i]<=a[m])
		{
			temp[k++] = a[i++];
		}
		else if (i<=mid && m<=j && a[m]<a[i])
		{
			temp[k++] = a[m++];
			sum += (ULL)(mid+1-i);
		}
		else
			break;
	}
	while(i<=mid)
	{
		temp[k++] = a[i++];
	}
	while(m<=j)
	{
		temp[k++] = a[m++];
	}
	copyBack(temp,a,f,j);
	delete[] temp;
}

void mergeCount(int a[], int i, int j, ULL& sum)
{
	if(i>=j)
	{
		return;
	}
	else
	{
		int mid = i+ (j-i)/2;
		mergeCount(a,i,mid,sum);
		mergeCount(a,mid+1,j,sum);
		//printf("%d %d %d\n",i,mid,j);
		mergeSplitCount(a,i,mid,j,sum);
	}
}

void printArr(int a[], int n)
{
	for (int i = 0; i < n; ++i)
	{
		printf("%d\n", a[i]);
	}
}
#define N 100000
int main()
{
	freopen_in;
	freopen_out;
	ULL sum=0;
	int a[100000];
	rep(i,N)
		s(a[i]);
	mergeCount(a,0,N-1,sum);
	printf("inversions = %llu\n", sum);
	printArr(a,N);
	return 0;
}
