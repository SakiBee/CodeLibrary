#include <bits/stdc++.h>
using namespace std;

struct node { 
    int data; 
    node* next; 
};
node *root = NULL;

void append(int n) {
    if(root == NULL) {
        root = new node();
        root -> data = n;
        root -> next = NULL;
    }
    else {
        node *copy_root = root;
        while(copy_root->next != NULL) copy_root = copy_root->next;
        node *newnode = new node();
        newnode->data = n;
        newnode->next = NULL;
        copy_root->next = newnode;
    }
}
void delet(int n) {
    node *cur = root;
    node *pre = NULL;
    while(cur->data != n){
        pre = cur;
        cur = cur->next;
    }
    if(cur == root){
        node *temp = root;
        root = root->next;
        delete(temp);
    }
    else{
        pre->next = cur->next;
        delete(cur);
    }
}
void add_mid(int pos,int value){
    node *cur = root;
    node *pre = NULL;
    int p = pos;
    while(p--){
        pre = cur;
        cur = cur->next;
    }
    node *newnode = new node();
    newnode->data = value;
    newnode->next = NULL;

    if(pos == 0){
        node *temp = root;
        root = newnode;
        root->next = temp;
    }
    else{
        pre->next = newnode;
        newnode->next = cur;
    }
}

void Min_Max_lenght() {
  if(root == NULL) {
    cout << "Nil Min Max\n";
    cout << 0 << endl;
    return;
  }
  int cnt = 0;
  node *cur = root;
  int mn = root -> data, mx = root -> data;
  for (cur = root; cur != NULL; cur = cur -> next) {
    if(cur -> data > mx) mx = cur -> data;
    if(cur -> data < mn) mn = cur -> data;
    cnt ++;
  }
  cout << "Min = " << mn << " Max = " << mx << endl;
  cout << "Lenght = " << cnt << endl;
}


void print(){
    node *cur = root;
    while(cur != NULL){
        cout << cur->data << " ";
        cur = cur->next;
    }
    cout << endl;
}

int main(){
    append(5);
    append(56);
    append(57);
    append(500);
    print();
    add_mid(2,5900);
    add_mid(0,0);
    add_mid(6,599900);
    print();
    delet(56);
    delet(0);
    delet(5);
    print();
    return 0;
}
