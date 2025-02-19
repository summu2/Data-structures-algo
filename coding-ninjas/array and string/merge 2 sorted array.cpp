/*Code : Merge two sorted arrays
Send Feedback
You have been given two sorted arrays/lists(ARR1 and ARR2) of size N and M respectively, merge them into a third array/list such that the third array is also sorted.
Input Format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

First line of each test case or query contains an integer 'N' representing the size of the first array/list.

Second line contains 'N' single space separated integers representing the elements of the first array/list.

Third line contains an integer 'M' representing the size of the second array/list.

Fourth line contains 'M' single space separated integers representing the elements of the second array/list.
Output Format :
For each test case, print the sorted array/list(of size N + M) in a single row, separated by a single space.

Output for every test case will be printed in a separate line.
Constraints :
1 <= t <= 10^2
0 <= N <= 10^5
0 <= M <= 10^5
Time Limit: 1 sec 
Sample Input 1 :
1
5
1 3 4 7 11
4
2 4 6 13
Sample Output 1 :
1 2 3 4 4 6 7 11 13 
Sample Input 2 :
2
3
10 100 500
7
4 7 9 25 30 300 450
4
7 45 89 90
0
Sample Output 2 :
4 7 9 10 25 30 100 300 450 500
7 45 89 90*/

#include<bits/stdc++.h>
using namespace std;

void merge(int *arr1, int size1, int *arr2, int size2, int *ans)
{
    //Write your code here  
    int i=0,j=0;
    int l=size1+size2;
    int k=0;
	for( i=0;i<size1;i++){
	while(i<size1 && j<size2){
			if(arr1[i]<arr2[j]){
				ans[k]=arr1[i];
				i++;
				k++;
			}
			else{
				ans[k]=arr2[i];
				j++;
				k++;
			}
		}
	}
	
	while(i<size1){
            ans[k]=arr1[i];
            i++;
            k++;
        }
         while(j<size2){
            ans[k]=arr2[j];
            j++;
            k++;
        }
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int size1,size2;
		cin>>size1;
		int arr1[size1];
		for(int i=0;i<size1;i++) cin>>arr1[i];
		cin>>size2;
		int arr2[size2],l=size2+size1;
		int ans[l],a[l];
		for(int i=0;i<size2;i++) cin>>arr2[i];
			merge(arr1, size1, arr2, size2, ans);
		}
	}

