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
void solve(node *&root,int sum,int &maxsum,int len,int &maxlen) {
    if(root == NULL) {
        if(len>maxlen) {
            maxsum=sum;
            maxlen=len;
        }
        else if(maxlen == len) {
            maxsum = max(sum,maxsum);
        }
        return;
    }
    sum = sum+root->data;
    solve(root->left,sum,maxsum,len+1,maxlen);
    solve(root->right,sum,maxsum,len+1,maxlen);
}
node *lca(node *&root,int n1,int n2) {
    if(root == NULL) {
        return NULL;
    }
    if(root->data == n1 || root->data == n2) {
        return root;
    }
    node *leftans = lca(root->left,n1,n2);
    node  *rightans = lca(root->right,n1,n2);
    if(leftans != NULL && rightans != NULL) {
        return root;
    }
    else if(leftans != NULL && rightans == NULL) {
        return leftans;
    }
    else if(leftans == NULL && rightans == NULL) {
        return rightans;
    }
    else {
        return NULL;
    }
}
int largesum(node *&root) {
    int len = 0;
    int maxlen = 0;
    int sum =0;
    int maxsum = -11111;
    solve(root,sum,maxsum,len,maxlen);
    return maxsum;
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
    // levelorder(root);
    // // bulidtree(root);
    // // levelorder(root);
    // cout<<"Height of the tree is "<<height(root);
    node *ans = lca(root,7,14);
    cout<<ans->data;
    return 0;
}
