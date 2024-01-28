#include<iostream>
#include<queue>
using namespace std;
class node{
      public :
      int data;
      node*left;
      node *right;
      node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
      }
      
};
node *create(node *root){
        int data;
        cin>>data;
        root = new node(data);
        if(data == -1) {
            return NULL;
        }
        cout<<"Enter data to be inserted in left of "<<data<<" ";
        root->left = create(root->left);
        cout<<"Enter data to be inserted in right of "<<data<<" ";
        root->right = create(root->right);
      }
void levelorder(node *root) {
        queue<node*> q;
        q.push(root);
        q.push(NULL);
        while(!q.empty()) {
            node *temp = q.front();
            q.pop();
            if(temp == NULL) {
                cout<<endl;
                if(!q.empty()) {
                    q.push(NULL);
                }
            }
            else {
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
            }
        }
}
void bulidtree(node *&root) {
    queue<node*> q;
     cout<<"Enter data for root : ";
     int data;
     cin>>data;
     root = new node(data);
     q.push(root);
     while(!q.empty()) {
        node *temp = q.front();
        q.pop();
        int leftdata;
        cout<<"Enter data for left node  ";
        cin>>leftdata;
        if(leftdata != -1) {
            temp->left = new node(leftdata);
            q.push(temp->left);
        }
        
        int rightdata;
        cout<<"Enter data for right node ";
        cin>>rightdata;
        if(rightdata != -1) {
            temp->right = new node(rightdata);
            q.push(temp->right);
        }
     }
}
int height(node *&root) {
    if(root == NULL) {
    return 0;
    }
    int left = height(root->left);
    int right = height(root->right);
    return (1+max(left,right));
}
int main(){
    node *root =NULL;
    root = create(root);
    levelorder(root);
    // bulidtree(root);
    // levelorder(root);
    cout<<"Height of the tree is "<<height(root);
    return 0;
}
