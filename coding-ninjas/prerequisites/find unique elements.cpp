Find the Unique Element
Send Feedback
Given an integer array of size 2N + 1. In this given array, N numbers are present twice and one number is present only once in the array.
You need to find and return that number which is unique in the array.
Note : Given array will always contain odd number of elements.
Input format :
Line 1 : Array size i.e. 2N+1
Line 2 : Array elements (separated by space)
Output Format :
Unique element present in the array
Constraints :
1 <= N <= 10^6
Sample Input :
7
2 3 1 6 3 6 2
Sample Output :
1

// arr - input array
// size - size of array
#include<bits/stdc++.h>
using namespace std;

int FindUnique(int arr[], int size){
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    sort(arr,arr+size);
    for(int i=0;i<size;i++)
    {
        if(arr[i]!=arr[i+1]&&i==0)
        {
            return arr[i];
        }
        else if(i==size-1&&arr[i]!=arr[i-1])
            return arr[i];
        else if(arr[i]!=arr[i+1]&&arr[i]!=arr[i-1])return arr[i];
    }
}
