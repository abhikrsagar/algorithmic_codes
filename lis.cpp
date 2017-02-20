//Author Abhishek Kumar
#include<bits/stdc++.h>
#define vi vector<int>
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define vpi vector<pii>
#define MAX (int)1e5
#define big (int)1e9+7
#define ll long long
#define si set<int>
#define fast_io ios::sync_with_stdio(false);cin.tie(NULL);
#define f first
#define s second
#define rep(i,a,b) for(int i=a;i<b;i++)
#define reps(i,a,b) for(int i=a;i<=b;i++)
#define ull unsigned long long
using namespace std;
//Longest Increasing subsequence
//Linear DP solution
//Recurrence
//dp[i]=Longest Increasing subsequence ending at index i
//Thus dp[i]=1+max(dp[j]) for all j from 1 to i such that a[i]<=a[j]
//          =1 is no such j exists
//Time Complexity O(n^2)
//Space Complexity O(n)
int lis(int *a,int n)
{
    int dp[n];
    for(int i=0;i<n;i++)
    {
        int w=0;
        for(int j=0;j<i;j++)
        {
            if(a[j]<=a[i])
                w=max(w,dp[j]);
        }
        dp[i]=1+w;
    }
return dp[n-1];
}
int main()
{
   int n;
   cin>>n;
   int *a=new int[n];
   rep(i,0,n)
   cin>>a[i];
   cout<<lis(a,n);
}
