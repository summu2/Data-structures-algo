/*Given an array of integers, sort the array into a wave like array and return it,
In other words, arrange the elements into a sequence such that a1 >= a2 <= a3 >= a4 <= a5.....

Example

Given [1, 2, 3, 4]

One possible answer : [2, 1, 4, 3]
Another possible answer : [4, 1, 3, 2]*/

vector<int> Solution::wave(vector<int> &A) {
        int N = A.size(), i = 0;
    sort(A.begin(), A.end());
    
    for(i = 0; i<N-1; i+=2){
        swap(A[i], A[i+1]);
    }
    return A;
}

