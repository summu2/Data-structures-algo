/*Lapindrome is defined as a string which when split in the middle, gives two halves having the same characters and same frequency of each character. If there are odd number of characters in the string, we ignore the middle character and check for lapindrome. For example gaga is a lapindrome, since the two halves ga and ga have the same characters with same frequency. Also, abccab, rotor and xyzxy are a few examples of lapindromes. Note that abbaab is NOT a lapindrome. The two halves contain the same characters but their frequencies do not match.
Your task is simple. Given a string, you need to tell if it is a lapindrome.

Input:
First line of input contains a single integer T, the number of test cases.
Each test is a single line containing a string S composed of only lowercase English alphabet.
Output:
For each test case, output on a separate line: "YES" if the string is a lapindrome and "NO" if it is not.
Constraints:
1 = T = 100
2 = |S| = 1000, where |S| denotes the length of S
Example:
Input:
6
gaga
abcde
rotor
xyzxy
abbaab
ababc


Output:
YES
NO
YES
YES
NO
NO
*/

#include<bits/stdc++.h>
#include<iostream>
using namespace std;
#include<string>
#include<algorithm>

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        string ss1, ss2;
        int l = s.length();

        for(int i=0;i<l/2;i++){
            ss1.push_back(s[i]);
            ss2.push_back(s[l-1-i]);
        }
        sort(ss1.begin(),ss1.end());
        sort(ss2.begin(),ss2.end());

        if(ss1 == ss2) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}

