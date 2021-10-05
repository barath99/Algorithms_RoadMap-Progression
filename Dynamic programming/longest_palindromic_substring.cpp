#include<bits/stdc++.h>
using namespace std;

int dp[1001][1001];

int solve(string& s,string& a,int n,int m){
    if(n==0||m==0)
        return 0;
    if(dp[n][m]!=-1)
        return dp[n][m];
    if(s[n-1]==a[m-1])
        return dp[n][m]=1+solve(s,a,n-1,m-1);
    else
        return dp[n][m]=max(solve(s,a,n-1,m),solve(s,a,n,m-1));
}

int longestPalindromeSubseq(string s) {
    string a = s;
    reverse(a.begin(),a.end());
    memset(dp,-1,sizeof(dp));
    return solve(s,a,s.size(),a.size());
}


int main(){

    string subseq;
    cin>>subseq;
   
    // length of longest palindromic subsequence
    cout<<longestPalindromeSubseq(subseq);
}