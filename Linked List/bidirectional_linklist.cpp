#include <bits/stdc++.h>
using namespace std;
struct node { 
    int role; 
    node *l, *r;
    node(){
        l = NULL;
        r = NULL;
    }
};

node *root;

void append(int n) {
    if(root == NULL){
        root = new node();
        root -> role = n;
    }
    else {
        node *cur = root, *parent;
        while(cur != NULL) {
            parent = cur;
            if(n < cur -> role) cur = cur -> l;
            else cur = cur -> r;
        }
        node *newnode = new node();
        newnode -> role = n;
        if(newnode -> role < parent -> role) parent -> l = newnode;
        else parent -> r = newnode;
    }
}

void print(node *cur) {
    if(cur == NULL) return;
    cout << cur->role << endl;
    print(cur->l);
    print(cur->r);
}

int main() {
    append(5);
    append(56);
    append(57);
    print(root);
    return 0;
}
