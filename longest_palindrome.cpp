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
//Longest Palindromic subsequence
//DP solution
//Recurrence
//dp[i][j]=Longest Palindromic subsequence starting at index i and ending at index j
//Thus dp[i][j]=2+dp[i+1][j-1]   if a[i]=a[j]
//             =max(dp[i][j-1],dp[i+1][j]) otherwise
//Time Complexity O(n^2)
//Space Complexity O(n^2)
int lp(string s )
{
    int n=s.size();
    int dp[n][n];
    rep(i,0,n)
    {
        rep(j,0,n)
        dp[i][j]=0;
    }
    for(int i=n-1;i>=0;i--)
    {
        for(int j=i;j<n;j++)
        {
            if(i==j)
                dp[i][j]=1;
            else if(s[i]==s[j])
                dp[i][j]=dp[i+1][j-1]+2;
            else
                dp[i][j]=max(dp[i][j-1],dp[i+1][j]);
        }
    }
    return dp[0][n-1];
}
//Alternate approach would be taks LCS of string and reverse of string
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
int long_pal(string a)
{
    string b=a;reverse(b.begin(),b.end());
    return lcs(a,b);
}
int main()
{
 string a="GEEKS FOR GEEKS";
 cout<<"DP approach:"<<lp(a)<<endl;
 cout<<"LCS approach:"<<long_pal(a)<<endl;
}
