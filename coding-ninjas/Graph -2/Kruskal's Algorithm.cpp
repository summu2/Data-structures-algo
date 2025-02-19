/*Code : Kruskal's Algorithm
Send Feedback
Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.
Find and print the Minimum Spanning Tree (MST) using Kruskal's algorithm.
For printing MST follow the steps -
1. In one line, print an edge which is part of MST in the format - 
v1 v2 w
where, v1 and v2 are the vertices of the edge which is included in MST and whose weight is w. And v1  <= v2 i.e. print the smaller vertex first while printing an edge.
2. Print V-1 edges in above format in different lines.
Note : Order of different edges doesn't matter.
Input Format :
Line 1: Two Integers V and E (separated by space)
Next E lines : Three integers ei, ej and wi, denoting that there exists an edge between vertex ei and vertex ej with weight wi (separated by space)
Output Format :
Print the MST, as described in the task.
Constraints :
2 <= V, E <= 10^5
Time Limit: 1 sec
Sample Input 1 :
4 4
0 1 3
0 3 5
1 2 1
2 3 8
Sample Output 1 :
1 2 1
0 1 3
0 3 5*/

#include <bits/stdc++.h>
using namespace std;

class Edge{
    public:
    int src=0;
    int dest=0;
    int wt=0;
};
bool compare(Edge& a,Edge& b){
    return a.wt<b.wt;
}
int findparent(int a,vector<int>& paren){
    if(paren[a]==a){
        return a;
    }
    return findparent(paren[a],paren);
}
int main()
{
    int V, E;
    cin >> V >> E;
	vector<Edge> input(E);
    for(int i=0;i<E;i++){
        cin>>input[i].src>>input[i].dest>>input[i].wt;
    }
    sort(input.begin(),input.end(),compare);
    vector<int>paren(V);
    for(int i=0;i<V;i++){
        paren[i]=i;
    }
    int count=0;
    int j=0;
    vector<Edge> output(V-1);
    while(count<V-1){
        int sp=findparent(input[j].src,paren);
        int dp=findparent(input[j].dest,paren);
        if(sp!=dp){
            
            output[count]=input[j];
            count++;
            paren[sp]=dp;
        }
        j++;
    }
    for(auto &i:output){
        if(i.src>i.dest){
            cout<<i.dest<<" "<<i.src<<" "<<i.wt<<endl;
        }else{
            cout<<i.src<<" "<<i.dest<<" "<<i.wt<<endl;
        }
    }
  return 0;
}
