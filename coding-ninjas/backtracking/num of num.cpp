//num of numbers without duplicates

#include<bits/stdc++.h>
using namespace std;

int num(int* input, int n, int* fact, int freq){
	if(n==0 || n==1) return 0;
	int ans=0;
	for(int i=input[0]+1;i<10;i++){
		if(freq[i]>0) {
			ans+=fact[n-1];
		}
	}	
	freq[input[0]]--;
	ans+=num(input+1,n-1,fact,freq);
	return ans;
} 

int main(){
	int n;
	cin>>n;
	int* input=new int[n];
	int* fact=new int[n+1];
	int freq[10]={};
	fact[0]=1;
	for(int i=0;i<n;i++){
		cin>>input[i];
		freq[input[i]]++;
		fact[i+1]=(i+1)*fact[i];
	}
	cout<<num(input,n,fact,freq)<<endl;
}
