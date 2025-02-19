/*The Fibonacci sequence F0,F1,� is a special infinite sequence of non-negative integers, where F0=0, F1=1 and for each integer n=2, Fn=Fn-1+Fn-2.

Consider the sequence D of the last decimal digits of the first N Fibonacci numbers, i.e. D=(F0%10,F1%10,�,FN-1%10). Now, you should perform the following process:

Let D=(D1,D2,�,Dl).
If l=1, the process ends.
Create a new sequence E=(D2,D4,�,D2?l/2?). In other words, E is the sequence created by removing all odd-indexed elements from D.
Change D to E.
When this process terminates, the sequence D contains only one number. You have to find this number.

Input
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first and only line of each test case contains a single integer N.
Output
For each test case, print a single line containing one integer ? the last remaining number.

Constraints
1=T=105
1=N=1018
Subtasks
Subtask #1 (20 points):

1=T=105
1=N=107
Subtask #2 (80 points): original constraints

Example Input
1
9
Example Output
3
Explanation
Example case 1: The first N Fibonacci numbers are (0,1,1,2,3,5,8,13,21). The sequence D is (0,1,1,2,3,5,8,3,1)?(1,2,5,3)?(2,3)?(3).*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
     ll n;
     cin>>n;
     ll z=log2((long double)n);
     if(z==0)
        cout<<0<<'\n';
     else if(z==1)
        cout<<1<<'\n';
     else
     {
         int x=z%4;
         if(x==3)
            cout<<3<<'\n';
         else if(x==2)
            cout<<2<<'\n';
         else if(x==0)
            cout<<0<<'\n';
         else if(x==1)
            cout<<9<<'\n';
     }
    }
    return 0;
}

