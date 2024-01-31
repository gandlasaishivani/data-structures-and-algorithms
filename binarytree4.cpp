#include<iostream>
#include<queue>
#include<algorithm>
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
void solve(node *&root,int &k,int &count,vector<int> &path) {
     if(root == NULL)
     return;
     path.push_back(root->data);
     solve(root->left,k,count,path);
     solve(root->right,k,count,path);
     int size = path.size();
     int sum = 0;
     for(int i = size-1;i>=0;i--) {
        sum += path[i];
        if(sum == k) {
            count++;
        }
     }
     path.pop_back();
}
int traversals(node *&root,int k) {
    vector<int> path;
    int count = 0;
    solve(root,k,count,path);
    return count;
}
int height(node *&root) {
    if(root == NULL) {
    return 0;
    }
    int left = height(root->left);
    int right = height(root->right);
    return (1+max(left,right));
}
pair<int,int> maxsum(node *&root) {
    if(root == 0) {
        pair<int,int> p = make_pair(0,0);
        return p;
    }
    pair<int,int> left = maxsum(root->left);
    pair<int,int> right = maxsum(root->right);
    pair<int,int> res;
    res.first = root->data+left.second+right.second;
    res.second = max(left.first,left.second)+max(right.first,right.second);
    return res;
}
int getsum(node *&root) {
    pair<int,int> ans = maxsum(root);
    return max(ans.first,ans.second);
}
int main(){
    node *root =NULL;
    root = create(root);
    cout<<getsum(root);
    return 0;
}
