//program to print the longest palindromic subsequence of string a
//revise again
#include<iostream>
#include<vector>
using namespace std;
int lps_recursive(string s1,int start,int end,vector<vector<int> > dp){
  if(start==end)
  {
    dp[start][end] = 1;
    return dp[start][end];
  }
  if(start+1==end && s1[start]==s1[end])
    {
      dp[start][end] = 2;
      return dp[start][end];
    }
  if(s1[start]==s1[end])
    {
      dp[start][end] = 2+lps_recursive(s1,start+1,end-1,dp);
    }
  else
    {
      dp[start][end] = max(lps_recursive(s1,start+1,end,dp),lps_recursive(s1,start,end-1,dp));
    }
    return dp[start][end];

}
int lps_wrong(string s1){
  int start = 0;
  int end = s1.size()-1;int m = s1.size();
  vector<vector<int> > dp(m+1,vector<int>(m+1,-1));
  for(int i=0;i<=m;i++){
    for(int j=0;j<=m;j++){
      if((i==0||j==0)||i>j){
        dp[i][j] = 0;
      }
      else if(i+1==j && s1[i]==s1[j]){
        dp[i][j] = 2;
      }
      else if(i==j){
        dp[i][j] = 1;
      }
      else{
        if(s1[i]==s1[j]){
          // cout<<s1[i]<<" ";
          dp[i][j] = 2+dp[i+1][j-1];
        }
        else{
          dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
      }
    }
  }
  for(int i=0;i<=m;i++){
    for(int j=0;j<=m;j++){
      cout<<dp[i][j]<<" ";
    }
    cout<<"\n";
  }
  return dp[m][m];
}

int lps(string s1){
  int m = s1.size();
  vector<vector<int> > dp(m,vector<int>(m,-1));
  for(int i=0;i<m;i++){
    dp[i][i] = 1;
  }
  for(int c=2;c<=m;c++){
    for(int i=0;i<m-c+1;i++){
      int j = i+c-1;
      if(i+1==j){
        dp[i][j] = 2;}
      else if(s1[i]==s1[j]){
        dp[i][j] = 2+dp[i+1][j-1];
      }
      else{
        dp[i][j] = max(dp[i+1][j],dp[i][j-1]);
      }
    }
  }
  return dp[0][m-1];
}
int main(int argc, char const *argv[]) {
  int test;
  cin>>test;
  for(int i=0;i<test;i++){
    string s1;
    // string s2;
    cin.ignore();
    getline(cin,s1);
    // getline(cin,s2);
    int start = 0;
    int end = s1.size()-1;
    int m = s1.size();
    vector<vector<int> > dp(m,vector<int>(m,-1));

    // cout<<print_longest_palindromic_subsequence(s1,start,end,dp)<<"\n";
    cout<<lps(s1)<<"\n";
  }
  return 0;
}
