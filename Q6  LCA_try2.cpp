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

// Returns true if "x" is present in tree rooted at "root" else returns false
bool Is_present(node *root,node *x)
{
    if(root == nullptr || x == nullptr)
    {
        return false;
    }
    if(root->data == x->data)
    {
        return true;
    }
    if(Is_present(root->right,x))
    {
        return true;
    } 
    if(Is_present(root->left,x))
    {
        return true;
    }
}

node* LCA(node *root,node *a,node *b)
{   
    // if either of two nodes is root then root is LCA
    if(root->data == a->data || root->data == b->data)
    {
        return root;
    }
    // both nodes present in left subtree
    bool left = Is_present(root->left,a) && Is_present(root->left,b);
    
    //both nodes present in right subtree
    bool right = Is_present(root->right,a) && Is_present(root->right,b);
    
    // both left and right are false means one node is in left subtree and other node is in right subtree so root is LCA
    if(left == false && right == false)
    {
        return root;
    }
    //both nodes in left/right subtree so LCA is in left/right subtree
    if(left)
    {
        LCA(root->left,a,b);
    }
    else
    {
        LCA(root->right,a,b);
    }
}

// Make tree by editing this function
node* Create_Tree()
{
    node *root = new node(1);
    root->left = new node(2);
    root->left->left = new node(3);
    root->right = new node(4);
    return root;
}

int main()
{
    node *root = Create_Tree();
    node *a = root->left;
    node *b = root->left->left;
    if(root == nullptr || !Is_present(root,a) ||!Is_present(root,b))
    {
        cout<<"Error : Tree is empty or one or both node(s) not present is Tree\n";
    }
    else
    {
        node *p = LCA(root,a,b);
        cout<<p->data<<endl;
    }
    return 0;

}
