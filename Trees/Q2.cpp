Amit - Needs more improvement..

// C++ program to demonstrate insertion 
// in a BST recursively. 
#include <iostream> 
using namespace std; 
#include <vector>
  
class BST 
{ 
    int data; 
    BST *left, *right; 
  
    public: 
      
    // Default constructor. 
    BST(); 
      
    // Parameterized constructor. 
    BST(int); 
      
    // Insert function. 
    BST* Insert(BST *, int); 
      
    // post order traversal output. 
    //void Inorder(BST *); 
    std::vector<int>postOrderTraversalOutput(BST *root);
}; 
  
// Default Constructor definition. 
BST :: BST() : data(0), left(NULL), right(NULL){} 
  
// Parameterized Constructor definition. 
BST :: BST(int value) 
{ 
    data = value; 
    left = right = NULL; 
}

// Insert function definition. 
BST* BST :: Insert(BST *root, int value) 
{ 
    if(!root) 
    { 
        // Insert the first node, if root is NULL. 
        return new BST(value); 
    } 
  
    // Insert data. 
    if(value > root->data) 
    { 
        // Insert right node data, if the 'value' 
        // to be inserted is greater than 'root' node data. 
          
        // Process right nodes. 
        root->right = Insert(root->right, value); 
    } 
    else
    { 
        // Insert left node data, if the 'value'  
        // to be inserted is greater than 'root' node data. 
          
        // Process left nodes. 
        root->left = Insert(root->left, value); 
    } 
      
    // Return 'root' node, after insertion. 
    return root; 
}

std::vector<int>BST :: postOrderTraversalOutput(BST *root) 
{
    std::vector<int> post;
    
    if(!root)
    post.push_back(0);
    
    postOrderTraversalOutput(root->left);
    postOrderTraversalOutput(root->right);
    post.push_back(root->data);
    
    return post;
}

std::vector<int> post(std::vector<int> pre) {
    std::vector<int> postOrder;
    BST b, *root = NULL;
    root = b.Insert(root, pre[0]);
    for (int i = 0; i < pre.size(); i++) {
        b.Insert(root, pre[i+1]);
    }
    postOrder = b.postOrderTraversalOutput(root);
	return postOrder;
}

int main() {
	//code
	std::vector<int> output;
	std::vector<int> inputPreOrder = {8, 4, 1, 6, 15, 10, 20};
	output = post(inputPreOrder);
	for (int i = 0; i<inputPreOrder.size(); i++){
	    std::cout << output[i] << std::endl;
	}
	return 0;
}
