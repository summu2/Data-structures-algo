/*Code : No. of BSTs
Send Feedback
Given an integer N, find and return the count of unique Binary search trees (BSTs) are possible with nodes valued from 1 to N.
Output count can be very large, so return the count modulo 10^9+7.
Input Format :
Integer n 
Output Format :
Count of BSTs
Contraints :
1<= N <=1000
Sample Input 1:
8
Sample Output 1:
1430
Sample Input 2:
3
Sample Output 2:
5*/

#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
typedef long long int ll;


int countBST( int n)
{
    ll* dp=new ll[n+1];
    dp[0]=1;
    dp[1]=1;
    for (int i=2;i<=n;i++){
        for (int j=1;j<=i;j++){
            dp[i]+=((dp[j-1]%mod)*(dp[i-j]%mod))%mod;
        }
       dp[i]=dp[i]%mod; 
    }
    return (dp[n]);
    
    
}

