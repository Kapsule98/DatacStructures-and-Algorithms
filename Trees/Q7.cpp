#include<bits/stdc++.h>

using namespace std;

class node
{
    public:
    int data;
    node* left,*right;

    node(int x)
    {
        data = x;
        this->left = nullptr;
        this->right = nullptr;
    }
};

void Print_Left_View(node* root)
{
    queue<node*> q;
    q.push(root);
    while(!q.empty())
    {
        int n = q.size();

        for(int i=0;i<n;i++)
        {
            node *k = q.front();
            q.pop();
           if(i==0)
            {
                cout<<k->data<<endl;
            }
            if(k->left)
            {
                q.push(k->left);
            }
            if(k->right)
            {
                q.push(k->right);
            }
        }
    }
}

node* Create_Tree()
{
    node* root = new node(1);
    root->left = new node(2);
    root->left->left = new node(3);
    root->left->right = new node(4);
    root->right = new node(6);
    root->right->left = new node(7);
    root->right->left->right = new node(5);
    return root;
}

int main()
{
    node* root = Create_Tree();
    Print_Left_View(root);

    return 0;
}

