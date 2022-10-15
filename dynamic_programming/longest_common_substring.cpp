//program to print the longest common substring of string a and string b

#include<iostream>
#include<vector>
using namespace std;
int lcs_tabulation(string s1,string s2){
    int m = s1.size();int n = s2.size();
    vector<vector<int> > dp(m+1,vector<int>(n+1,-1));
    int ans = 0;int row = 0;int col = 0;
    for(int i=0;i<=m;i++){
      for(int j=0;j<=n;j++){
        if(i==0||j==0)
        dp[i][j] = 0;
        else if(s1[i-1]==s2[j-1]){
          dp[i][j] = 1+dp[i-1][j-1];
          if(ans<dp[i][j])
            {
              ans = dp[i][j];
              row = i;col = j;
            }
        }
        else
        dp[i][j] = 0;
      }
    }
    int i = m;
    int j = n;
    string lcs = "";
    while(dp[row][col]!=0){
        lcs=s1[row-1]+lcs;
      row--;
      col--;
    }
    cout<<lcs<<"\n";
    return ans;
}
int lcs_recursive(string s1,string s2,int m,int n,int count){
  if(m==0||n==0)
  return count;
  else if(s1[m-1]==s2[n-1])
  {
    count = lcs_recursive(s1,s2,m-1,n-1,count+1);
    // return count;
  }
  count = max(count,max(lcs_recursive(s1,s2,m-1,n,0),lcs_recursive(s1,s2,m,n-1,0)));
  return count;
}
int main(int argc, char const *argv[]) {
  int test;
  cin>>test;
  for(int i=0;i<test;i++){
    string s1;
    string s2;
    cin.ignore();
    getline(cin,s1);
    getline(cin,s2);
    // int count = print_longest_common_substring(s1,s2,s1.size()-1,s2.size()-1,0);
    int count = lcs_tabulation(s1,s2);
    cout<<count<<"\n";

  }
  return 0;
}
