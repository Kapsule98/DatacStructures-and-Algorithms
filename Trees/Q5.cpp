// C++ program to find number of paths in a tree to a given sum
//- Epsilon
//=======================================
// Time Complexity = ??
//=======================================
#include <iostream> 
using namespace std; 
#include <vector>

//With stone in my heart I am using this global variable.
int finalCount = 0;
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

int countNumberOfPathsToAGivenSum(node* root, vector<int>& path, int givenSum) 
{
    int numberOfPaths = 0;
    if(root == nullptr) 
    {
        return 0;
    }
    {
        path.push_back(root->data);
    
        countNumberOfPathsToAGivenSum(root->left, path, givenSum);
        countNumberOfPathsToAGivenSum(root->right, path, givenSum);
    
        int totalsum = 0;
        for(int i = path.size()-1; i >= 0; i--) 
        {
            totalsum = totalsum + path[i];
        
            if(totalsum == givenSum) 
            {
                finalCount++;
            }
        }
    
        path.pop_back();
    }
    
}

node* Create_Tree()
{
    node* root0 = new node(8);
    node* n1 = new node(4);
    node* n2 = new node(15);
    node* n3 = new node(1);
    node* n4 = new node(6);
    node* n5 = new node(10);
    node* n6 = new node(20);
    root0->left = n1;
    root0->right = n2;
    n1->left = n3;
    n1->right = n4;
    n2->left = n5;
    n2->right = n6;
    return root0;
}

int main() 
{
    node* root = Create_Tree();
    std::vector<int> path;
	int count = countNumberOfPathsToAGivenSum(root, path, 10);
	std::cout << finalCount << std::endl;
	return 0;
}
