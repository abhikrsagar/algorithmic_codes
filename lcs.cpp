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
//Longest Common subsequence
//DP solution
//Recurrence
//dp[i][j]=Longest Common subsequence of string a[1...i] and b[1...j]
//Thus dp[i][j]=dp[i-1][j-1]+1  if a[i]=a[j]
//          =max(dp[i][j-1],dp[i-1][j]) otherwise
//Time Complexity O(n^2)
//Space Complexity O(n^2)
int lcs(string a,string b)
{
    int n1=a.size(),n2=b.size();
    int dp[n1][n2];
    for(int i=0;i<n1;i++)
    {
        for(int j=0;j<n2;j++)
        {
           if(i==0||j==0)
           {
               if(a[i]==b[j])
                dp[i][j]=1;
               else
                dp[i][j]=0;
           }
           else
           {
               if(a[i]==b[j])
                dp[i][j]=dp[i-1][j-1]+1;
               else
                dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
           }
        }
    }
return dp[n1-1][n2-1];
}
int main()
{
string x = "AGGTAB";
string y= "GXTXAYB";
  cout<<lcs(x,y);
}
