/*Alice and Bob need to send secret messages to each other and are discussing ways to encode their messages:
Alice: �Let�s just use a very simple code: We�ll assign �A� the code word 1, �B� will be 2, and so on down to �Z� being assigned 26.�

Bob: �That�s a stupid code, Alice. Suppose I send you the word �BEAN� encoded as 25114. You could decode that in many different ways!�

Alice: �Sure you could, but what words would you get? Other than �BEAN�, you�d get �BEAAD�, �YAAD�, �YAN�, �YKD� and �BEKD�. I think you would be able to figure out the correct decoding. And why would you send me the word �BEAN� anyway?�

Bob: �OK, maybe that�s a bad example, but I bet you that if you got a string of length 5000 there would be tons of different decodings and with that many you would find at least two different ones that would make sense.�

Alice: �How many different decodings?�

Bob: �Jillions!�
For some reason, Alice is still unconvinced by Bob�s argument, so she requires a program that will determine how many decodings there can be for a given string using her code.
Input
Input will consist of multiple input sets. Each set will consist of a single line of at most 5000 digits representing a valid encryption (for example, no line will begin with a 0). There will be no spaces between the digits. An input line of �0� will terminate the input and should not be processed.
Output
For each input set, output the number of possible decodings for the input string. Print your answer taking modulo "10^9+7"
Sample Input:
25114
1111111111
3333333333
0
Sample Output:
6
89
1*/

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long int ll;
 
ll count_codes(string num,int length){
    ll* output=new ll[5001];
    output[0]=1;
    for (int i=1;i<length;i++){
        int t=(num[i-1]-'0')*10 + (num[i]-'0');
        if(num[i]!='0') output[i]=output[i-1];
        if(t>=10 && t<=26 && i>1) output[i]+=output[i-2];
        else if(t>=10 && t<=26)output[i]++;           
        output[i]=output[i]% mod;
    }
    return output[length-1];   
}
int main(){
    string num;
    while (true){
        cin>>num;
        if(num=="0") break;
        int n=num.length();
        cout<<count_codes(num,n)<<endl;       
    }
    return 0;
}


//CN-editorial

int num_codes(int* n, int size) {
	 if (size == 1) {
		 return 1;
	 }
	 if (size == 0) {
		 return 1;
	 }
	 int output = num_codes(n, size - 1);
	 if (output[size - 2] * 10 + output[size - 1] <= 26) {
		 output += num_codes(n, size -2);
	 }
	 return output;
}

int num_codes_i(int * input, int size) {
	int* output = new int[size + 1];
	output[0] = 1;
	output[1] = 1;

	for (int i = 2; i <= size; i++) {
		output[i] = output[i - 1];
		if (input[i-2] *10 + input[i - 1] <= 26) {
			output[i] += output[i - 2];
		}
	}
	int ans = output[size];
	delete [] output;
	return ans;
}

int num_codes2(int* n, int size, int* arr) {
	 if (size == 1) {
		 return 1;
	 }
	 if (size == 0) {
		 return 1;
	 }
	 if (arr[size] > 0) {
		 return arr[size];
	 }

	 int output = num_codes(n, size - 1);
	 if (output[size - 2] * 10 + output[size - 1] <= 26) {
		 output += num_codes(n, size -2);
	 }
	 arr[size] = output;
	 return output;
}

