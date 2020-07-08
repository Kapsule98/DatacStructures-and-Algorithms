#include<bits/stdc++.h>
using namespace std;

class node
{
    public:
    int data;
    node* left,*right;

    node(int x)
    {
        this->data = x;
        this->left = nullptr;
        this->right = nullptr;
    }
};

// sum of tree rooted at root
int sum(node *root)
{
    if(root == nullptr)
    {
        return 0;
    }
    return root->data + sum(root->left)+sum(root->right);
}

// changing all nodes to sum of left subtree
void left_sum(node* root)
{
    if(root == nullptr)
    {
        return;
    }
    if(root->left == nullptr)
    {
        root->data = 0;
    }
    root->data = sum(root->left);
    left_sum(root->left);
    left_sum(root->right);
}
// make Test cases here
node* Create_Tree()
{
    node *root = new node(1);
    root->left = new node(2);
    root->left->left = new node(1);
    root->right = new node(1);
    root->right->left = new node(3);
    root->right->right = new node(4);
    root->right->right->left = new node(1);
    return root;
}

// in order traversal
void in_order(node* root)
{
    if(root == nullptr)
    {
        return;
    }
    in_order(root->left);
    cout<<root->data<<" ";
    in_order(root->right);
}

int main()
{
    node *root = Create_Tree();
    node *p = root;
    left_sum(root);
    in_order(p);
    return 0;
}
