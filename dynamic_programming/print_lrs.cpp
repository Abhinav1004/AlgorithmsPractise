//program to print the longest repeating subsequence

#include<iostream>
#include<vector>
using namespace std;
void print_lrs(string s1,string s2){
  int m = s1.size();int n = s2.size();
  vector<vector<int> > dp(m+1,vector<int>(n+1,-1));
  for(int i=0;i<=m;i++){
    for(int j=0;j<=n;j++){
        if(i==0 || j==0)
        dp[i][j]=0;
        else if(s1[i-1]==s2[j-1] && i!=j)
        dp[i][j] = 1+dp[i-1][j-1];
        else
        dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
    }
  }
  int len_lrs = dp[m][n];
  string lrs = "";
  int i=m;int j=n;
  while(i>0 && j>0){
    if(s1[i-1]==s2[j-1] && i!=j){
      lrs = s1[i-1]+lrs;
      i--;j--;
    }
    else if(dp[i-1][j]>dp[i][j-1]){
      i--;
    }
    else
    j--;
  }
  cout<<lrs<<"\n";
  // cout<<dp[m][n]<<"\n";
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
    print_lrs(s1,s1);
  }
  return 0;
}
