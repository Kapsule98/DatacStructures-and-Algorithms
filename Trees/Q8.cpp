// C++ program to print nodes in level order &  in spiral level order.
//- Epsilon
//=======================================
// Time Complexity = O(n^2) :( 
// Space Complexity = O(n) [Since recursive function use stacks]
//=======================================

//------ON A SERIOUS NOTE--------//
/* 
Time complexity of level order & spiral level order printing can be improved obviously 
from O(n^2) to O(n) by using QUEUE & STACKS

LEVEL ORDER - ( USE QUEUE ) - https://www.geeksforgeeks.org/level-order-tree-traversal/
SPIRAL LEVEL ORDER - ( USE 2 STACKS ) - https://www.geeksforgeeks.org/level-order-traversal-in-spiral-form/
*/
//------------------------------ //
#include <iostream> 
using namespace std; 
#include <vector>

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

//------------Snippet for level order output -----------------//
//lets print nodes in level order.
void printItNow(node* root, int level) {
    if(root==nullptr){
        return;
    } else if(level==1) {
        std::cout << root->data << std::endl;
    } else {
        printItNow(root->left, level-1);
        printItNow(root->right, level-1);
    }
}
void printLevelOrder(node* root) {
    int height = getHeight(root);
    for(int i = 1; i<=height; i++){
        printItNow(root, i);
    }
}

//---------- Snippet for spiral level order ------------------//

void nowPrintItSpiral(node* root, int level) {
    if(root==nullptr){
        return;
    } else if(level==1) {
        std::cout << root->data << std::endl;
    } else if(level%2==0) {
        printItNow(root->right, level-1);
        printItNow(root->left, level-1);
    } else {
        printItNow(root->left, level-1);
        printItNow(root->right, level-1);
    }
}
void printSpiralLevelOrder(node* root) {
    int height = getHeight(root);
    for(int i = 1; i<=height; i++){
        nowPrintItSpiral(root, i);
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
	printSpiralLevelOrder(root);
	return 0;
}
