/*Print Specific Tree Pattern
Send Feedback
Given a "complete" binary tree , print the following pattern using its all nodes.
root element
first element of second level
last element of  of second level
first element of the of the third level
last element of the third level
second element of the third level
second from last element of the third level
..... So on.
Example :
For tree :
Alt text

The pattern should be: 
1 2 3 4 7 5 6 8 15 9 14 10 13 11 12
Input Format
Line 1: Nodes in level order form (separated by space). If any node does not have left or right child, take -1 in its place
Output Format
Required pattern
Constraint
Given binary tree is complete
1 <= Number of Nodes <= 10^6
1 <= value of each node <= 10^8
Sample Input 1
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
Sample Output 1
1 2 3 4 7 5 6 8 15 9 14 10 13 11 12*/


void dfs(BinaryTreeNode<int>* root, vector<vector<int>>& vec,int level){
    if(root==NULL) return;
    if(level>vec.size()){
        vector<int> temp;
        temp.push_back(root->data);
        vec.push_back(temp);
    }else{
        vec[level-1].push_back(root->data);
    }
    dfs(root->left,vec,level+1);
    dfs(root->right,vec,level+1);
    return;
}

void printSpecificPattern(BinaryTreeNode<int> * root)
{
    if(root==NULL) return;
    vector<vector<int>> vec;
    //update the vector of vectors    
    dfs(root,vec,1);
    cout<<root->data<<" ";
    //cout<<vec.size();
    for (int i=1;i<vec.size();i++){
        int j=0,k=vec[i].size()-1;
        while(j<k){
            cout<<vec[i].at(j)<<" ";
            j++;
            cout<<vec[i].at(k)<<" ";
            k--;
        }
    }  
}

