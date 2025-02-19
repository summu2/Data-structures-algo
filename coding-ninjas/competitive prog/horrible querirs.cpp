#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unordered_map<int, int> umapii;
typedef unordered_map<int, bool> umapib;
typedef unordered_map<string, int> umapsi;
typedef unordered_map<string, string> umapss;
typedef map<string, int> mapsi;
typedef map<pair<int, int>, int> mappiii;
typedef map<int, int> mapii;
typedef pair<int, int> pii;

#define it iterator
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()

#define MAX 100001
ll tree[4*MAX], lazy[4*MAX];

void update(ll si, ll ei, ll start, ll end, ll id, ll key){
    if(si > ei) return;

    if(lazy[id] != 0){
        tree[id] += lazy[id]*(ei-si+1);

        if(si != ei){
            lazy[2*id] += lazy[id];
            lazy[2*id+1] += lazy[id];
        }

        lazy[id] = 0;
    }

    if(start > ei || end < si) return;
    else if(start <= si && ei <= end){
        tree[id] += key*(ei-si+1);
        if(si != ei){
            lazy[2*id] += key;
            lazy[2*id+1] += key;
        }
        return;
    }

    ll mid = (si+ei)/2;
    update(si, mid, start, end, 2*id, key);
    update(mid+1, ei, start, end, 2*id+1, key);
    tree[id] = tree[2*id] + tree[2*id+1];
}

ll query(ll si, ll ei, ll start, ll end, ll id){
    if(si > ei) return 0;

    if(lazy[id] != 0){
        tree[id] += lazy[id]*(ei-si+1);

        if(si != ei){
            lazy[2*id] += lazy[id];
            lazy[2*id+1] += lazy[id];
        }

        lazy[id] = 0;
    }

    if(start > ei || end < si) return 0;
    else if(start <= si && ei <= end) return tree[id];

    ll mid = (si+ei)/2;
    ll x = query(si, mid, start, end, 2*id);
    ll y = query(mid+1, ei, start, end, 2*id+1);
    return x+y;
}

void printTree(ll n){
    for(ll i = 1; i < 4*n; i++) cout << tree[i] << " ";
    cout << endl;
}

void printLazy(ll n){
    for(ll i = 1; i < 4*n; i++) cout << lazy[i] << " ";
    cout << endl;
}

int main(){
    ll t;
    cin >> t;
    while(t--){
        ll n, c;
        cin >> n >> c;

        for(ll i = 0; i < 4*MAX; i++){
            tree[i] = 0;
            lazy[i] = 0;
        }

        ll type, start, end, key;
        while(c--){
            cin >> type;
            if(type == 0){
                cin >> start >> end >> key;
                update(0, n-1, start-1, end-1, 1, key);
                // printTree(n);
                // printLazy(n);
            }
            else{
                cin >> start >> end;
                cout << query(0, n-1, start-1, end-1, 1) << endl;
                // printTree(n);
                // printLazy(n);
            }
        }
    }
}
