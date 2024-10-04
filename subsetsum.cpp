#include<bits/stdc++.h>
using namespace std;
int dp[100][100];
bool subsetsum(int tar,int nums[],int n){
for(int i=0;i<=n;i++){
    for(int j=0;j<=tar;j++){
        if(j==0)dp[i][j]=1;
        else if(i==0) dp[i][j]=0;
        else if(nums[i-1]>j) dp[i][j]=dp[i-1][j];
        else dp[i][j]=(dp[i-1][j-nums[i-1]]||dp[i-1][j]);
    }
    
}
return dp[n][tar]; 
}
int main(){
    int arr[] = {2, 3, 7, 1};    // Input array
    int sum = 6;                 // Desired sum
    
    cout << (subsetsum(sum,arr,4) ? "True" : "False");   // Output result as True or False
    return 0;
}
