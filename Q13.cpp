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

int maxi(node *root)
{
    if(root == nullptr)
    {
        return INT_MIN;
    }
    int max = root->data;
    if(maxi(root->left) > root->data)
    {
        max = maxi(root->left);
    }
    if(maxi(root->right) > max)
    {
        max = maxi(root->right);
    }
    return max;
}

int mini(node *root)
{
    if(root == nullptr)
    {
        return INT_MAX;
    }
    int min = root->data;

    if(mini(root->left) < min)
    {
        min = mini(root->left);
    }
    if(mini(root->right) < min)
    {
        min = mini(root->right);
    }
    return min;
    
}

node *Create_Tree()
{
    node *root = new node(1);
    root->right = new node(3);
    root->left = new node (2);
}

int main()
{
    node *root = Create_Tree();
    cout<<maxi(root->left) + mini(root->right)<<endl;
    return 0;
}
