/*
Print the diameter of a given tree.
-Epsilon
*/

#include <iostream> 
using namespace std; 
#include <vector>
#include <map>
class node
{
    public:
    int data;
    node* left;
    node* right;
    node(int data)
    {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
    
};

//---------------------------height of a tree ------------------------//
//lets find out height of a tree.
int getHeight (node* root) {
   if(root == nullptr){
       return 0;
   } else {
       int leftHeight = getHeight(root->left);
       int rightHeight = getHeight(root->right);
       
       if(leftHeight > rightHeight){
           return leftHeight+1;
       } else {
           return rightHeight+1;
       }
   } 
}
//--------------------- print diameter of a tree------------------------//
int getDiameterOfTree(node* root){
    if (root == nullptr){
        return 0;
    } else {
        int l = getHeight (root->left);
        int r = getHeight (root->right);
        
        int dl = getDiameterOfTree(root->left);
        int dr = getDiameterOfTree(root->right);
        
        return max(l+r+1, max(dl, dr));
    }
}
//---------------------Tree creation and blah blah -----------------//

node* Create_Tree()
{
    node* root0 = new node(8);
    node* n1 = new node(4);
    node* n2 = new node(15);
    node* n3 = new node(1);
    node* n4 = new node(6);
    node* n5 = new node(10);
    node* n6 = new node(20);
    node* n7 = new node(30);
    node* n8 = new node(40);
    root0->left = n1;
    root0->right = n2;
    n1->left = n3;
    n1->right = n4;
    n2->left = n5;
    n2->right = n6;
    n6->right = n7;
    n7->right = n8;
    return root0;
}

int main() 
{
    node* root = Create_Tree();
	int dia = getDiameterOfTree(root);
	std::cout << dia << std::endl;
	return 0;
}
