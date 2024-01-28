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
        cout<<"Enter data to be inserted in left of : "<<data<<" ";
        root->left = create(root->left);
        cout<<"Enter data to be inserted in right of : "<<data<<" ";
        root->right = create(root->right);
      }
int height(node *&root) {
    if(root == NULL) {
    return 0;
    }
    int left = height(root->left);
    int right = height(root->right);
    return (1+max(left,right));
}
int diameter(node *&root) {
    if(root == NULL) {
        return 0;
    }
    int op1= diameter(root->left);
    int op2 = diameter(root->right);
    int op3 = 1+height(root->left)+height(root->right);
    int ans = max(op1,max(op2,op3));
    return ans;
}
bool isbalanced(node *&root) {
    if(root == NULL) {
        return true;
    }
    bool left = isbalanced(root->left);
    bool right = isbalanced(root->right);
    bool diff = abs(height(root->left)-height(root->right)) <= 1;
    if(left && right && diff) {
        return 1;
    }
    else {
        return 0;
    }
}
bool checkequal(node *&root1,node *&root2) {
     if(root1==NULL && root2==NULL) {
        return true;
     }
     if(root1==NULL && root2!=NULL) {
        return false;s
     }
     if(root1!=NULL && root2==NULL) {
        return false;
     }
     bool left = checkequal(root1->left,root2->left);
     bool right = checkequal(root1->right,root2->right);
     bool val = root1->data == root2->data;
     if(left && right && val) {
        return true;
     }
     else {
        return false;
     }
}
int main(){
    node *root1 =NULL;
    root1 = create(root1);
    // cout<<"Diameter of tree is "<<diameter(root)<<endl;
    // cout<<isbalanced(root);
    node *root2 = NULL;
    root2 = create(root2);
    cout<<checkequal(root1,root2);
    return 0;
}
