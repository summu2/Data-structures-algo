/*Code: Construct BST from a Sorted Array
Send Feedback
Given a sorted integer array A of size n, which contains all unique elements. You need to construct a balanced BST from this input array. Return the root of constructed BST.
Note: If array size is even, take first mid as root.
Input format:
The first line of input contains an integer, which denotes the value of n. The following line contains n space separated integers, that denote the values of array.
Output Format:
The first and only line of output contains values of BST nodes, printed in pre order traversal.
Constraints:
Time Limit: 1 second
Sample Input 1:
7
1 2 3 4 5 6 7
Sample Output 1:
4 2 1 3 6 5 7 */

BinaryTreeNode<int>* constructhelper(int* input,int start,int end){
    if(start>end) return NULL;
    if(start==end){
        BinaryTreeNode<int>* root=new BinaryTreeNode<int>(input[start]);
        return root;
    }
    int mid=(start+end)/2;
    BinaryTreeNode<int>* root=new BinaryTreeNode<int>(input[mid]);
    BinaryTreeNode<int>* left=constructhelper(input,start,mid-1);
    BinaryTreeNode<int>* right=constructhelper(input,mid+1,end);
    root->left=left;
    root->right=right;
    return root;   
}
BinaryTreeNode<int>* constructTree(int *input, int n) {
    if(n==0) return NULL;
    return constructhelper(input,0,n-1);
}
