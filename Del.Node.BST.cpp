#include<iostream> 


using namespace std; 

struct TreeNode{
public: 
      int val; 
      TreeNode* left; 
      TreeNode* right; 
      TreeNode(): val(0), left(nullptr), right(nullptr){}
      TreeNode(int _val): val(_val), left(nullptr), right(nullptr){}
      TreeNode(int _val, TreeNode* _left, TreeNode* _right): val(_val), left(_left), right(_right){}
      
};
class Solution{
public: 
      TreeNode* getMin(TreeNode* node){
        while(node->left){
          node = node->left; 
        }
        return node; 
      }
      TreeNode* deleteNode(TreeNode* root, int key){
        if(!root) return nullptr; 
        if(key < root->val) root->left = deleteNode(root->left, key); 
        else if(key > root->val) root->right = deleteNode(root->right, key); 
        else {
          if(!root->left) {
            TreeNode* temp = root->right; 
            delete root; 
            return temp; 
          }else if(!root->right){
            TreeNode* temp = root->left; 
            delete root; 
            return temp; 
          }else {
            TreeNode* minNode = getMin(root->right); 
            root->val = minNode->val; 
            root->right = deleteNode(root->right, minNode->val); 
          }
        }
        return root; 
      }
void printInOrder(TreeNode* root){
        if(!root) return;
        printInOrder(root->left);
        cout << root->val << " ";
        printInOrder(root->right);
    }
};
int main(){
  TreeNode* root = new TreeNode(5); 
  root->left = new TreeNode(3); 
  root->right = new TreeNode(6); 
  root->left->left = new TreeNode(2); 
  root->left->right = new TreeNode(4); 
  root->right->right = new TreeNode(7); 
  Solution sol; 
  TreeNode* ans= sol.deleteNode(root, 3); 
  sol.printInOrder(ans); 
  cout <<endl; 
  
  return 0; 
}
