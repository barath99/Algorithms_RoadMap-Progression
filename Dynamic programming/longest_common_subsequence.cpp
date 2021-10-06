#include<bits/stdc++.h>
using namespace std;


int dp[1001][1001];

int solve(string& a,string& b,int n,int m){
    if(n==0||m==0)
        return 0;
    if(dp[n][m]!=-1)
        return dp[n][m];
    if(a[n-1]==b[m-1])
        return dp[n][m]=1+solve(a,b,n-1,m-1);
    else
        return dp[n][m]=max(solve(a,b,n-1,m),solve(a,b,n,m-1));
}

int longestCommonSubsequence(string text1, string text2) {
    memset(dp,-1,sizeof(dp));
    return solve(text1,text2,text1.size(),text2.size());
}



int main(){

    string subseq1, subseq2;
    cin>>subseq1>>subseq2;
   
    // length of longest common subsequence
    cout<<longestCommonSubsequence(subseq1, subseq2);
}