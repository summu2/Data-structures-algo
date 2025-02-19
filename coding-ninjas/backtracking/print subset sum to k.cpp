/*Print Subset Sum to K
Send Feedback
Given an array A and an integer K, print all subsets of A which sum to K.
Subsets are of length varying from 0 to n, that contain elements of the array. But the order of elements should remain same as in the input array.
Note : The order of subsets are not important. Just print them in different lines.
Input format :
Line 1 : Size of input array
Line 2 : Array elements separated by space
Line 3 : K 
Sample Input:
9 
5 12 3 17 1 18 15 3 17 
6
Sample Output:
3 3
5 1*/

#include <bits/stdc++.h>
using namespace std;

int checkSum(vector<int>&temp){
    int size=temp.size();
    int ans=0;
    for (int i=0;i<size;i++){
        ans+=temp[i];
    }
    return ans;
}

void subsetCheck(int input[],int n,int k,vector<int> &temp){
    if(n==0){
        if(checkSum(temp)==k){
            for(int i=0;i<temp.size();i++){
        if(i!=temp.size()-1)
            cout<<temp[i]<<" ";
        else
            cout<<temp[i];
    }
    cout<<endl;
        }
        return;
    }
    temp.push_back(input[0]);
    subsetCheck(input +1,n-1,k,temp);
    
    temp.pop_back();
    subsetCheck(input+1,n-1,k,temp);
}

void printSubsetSumToK(int input[], int size, int k) {
    // Write your code here
    vector<int>temp;
    subsetCheck(input,size,k,temp);
}

