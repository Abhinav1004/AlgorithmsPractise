//program to print the shortest common supersequence

#include<iostream>
#include<vector>
using namespace std;
void print_scs(string s1,string s2){
  int m = s1.size();int n = s2.size();
  vector<vector<int> > dp(m+1,vector<int>(n+1,-1));
  for(int i=0;i<=m;i++){
    for(int j=0;j<=n;j++){
        if(i==0)
        {
          dp[i][j] = n;
        }
        else if(dp[i][j]==0){
          dp[i][j] = m;
        }
        else if(s1[i-1]==s2[j-1])
        dp[i][j] = 1+dp[i-1][j-1];
        else
        dp[i][j] = 1+min(dp[i-1][j],dp[i][j-1]);
    }
  }
  int len_scs = dp[m][n];
  string scs = "";
  int i=m;int j=n;
  while(i>0 && j>0){
    if(s1[i-1]==s2[j-1]){
      scs = s1[i-1]+scs;
      i--;j--;
    }
    else if(dp[i-1][j]>dp[i][j-1]){
      scs = s1[i-1]+scs;
      i--;
    }
    else{
    scs = s2[j-1]+scs;
    j--;
    }
  }
  while(i>0){
    scs = s1[i-1]+scs;
    i--;
  }
  while(j>0){
    scs = s2[j-1]+scs;
    j--;
  }
  cout<<scs<<"\n";
  // cout<<dp[m][n]<<"\n";
}
int main(int argc, char const *argv[]) {
  int test;
  cin>>test;
  for(int i=0;i<test;i++){
    string s1;
    string s2;
    cin.ignore();
    // cout<<i<<"\n";
    getline(cin,s1);
    // cout<<s1;
    getline(cin,s2);
    print_scs(s1,s2);
  }
  return 0;
}
