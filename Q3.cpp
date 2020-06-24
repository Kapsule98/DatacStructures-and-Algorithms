/*
Author : Kapil
------------------------------------------------------
     Check if 2 given trees are mirrors of each other
------------------------------------------------------
Time complexity :O(N)
Extra Space     :none
*/

#include<bits/stdc++.h>

using namespace std;

class node
{
    public:
    int data;
    node *left,*right;
    node(int x)
    {
        this->data = x;
        this->left = nullptr;
        this->right = nullptr;
    }
};

bool IsMirror(node* root1,node* root2)
{
    if(root1 == nullptr && root2 == nullptr)
    {
        return true;
    }
    if(root1 == nullptr || root2 == nullptr)
    {
        return false;
    }
    if(root1->data != root2->data)
    {
        return false;
    }
    return IsMirror(root1->left,root2->right) && IsMirror(root1->right,root2->left);
    
}

//modify this function to make test cases
pair<node*,node*> Tree()
{
    //Tree 1
    node* root1 = new node(1);
    root1->left = new node(2);
    root1->right = new node(3);
    
    //Tree 2
    node* root2 = new node(1);
    root2->left = new node(3);
    root2->right = new node(2);
    
    pair<node*,node*> p ;
    p.first = root1;
    p.second = root2;
    return p;
}

int main()
{
    node *root1 = Tree().first;
    node *root2 = Tree().second;

    if(IsMirror(root1,root2))
    {
        cout<<"Mirror\n";
    }
    else
    {
        cout<<"Not mirror\n";
    }
    return 0;   
}
