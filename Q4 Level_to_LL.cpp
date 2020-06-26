/*
Author : Kapil
--------------------------------------------------------------
     Convert each level of a binary tree into a linked list
--------------------------------------------------------------
*/


#include<bits/stdc++.h>

using namespace std;

//Linked list node
class LL_node
{
    public:
    int data;
    LL_node* link;

    LL_node(int x)
    {
        this->data = x;
        this->link = nullptr;
    }
};

//Tree node
class T_node
{
    public:
    int data;
    T_node *left,*right;

    T_node(int x)
    {
        this->data = x;
        this->left = nullptr;
        this->right = nullptr;
    }
};

//Function to add a node at the end of linked list
void Add_to_LL(LL_node* Adjlist[],int data,int count)
{
    
    if(Adjlist[count] == nullptr)
    {
        Adjlist[count] = new LL_node(data);
        return;
    }
    LL_node* p = Adjlist[count];
    while(p->link!=nullptr)
    {
        p = p->link;
    }
    p->link = new LL_node(data);
    return;
}


// Function to traverse a level
void Explore_current_level(T_node* root,int level,int count,LL_node* Adjlist[])
{
    if(root == nullptr)
    {
        return;
    }
    if(level == 0)
    {
        Add_to_LL(Adjlist,root->data,count);
    }
    else
    {
        Explore_current_level(root->left,level-1,count,Adjlist);
        Explore_current_level(root->right,level-1,count,Adjlist);
    }
    

}

//Function to convert Tree to linked lists
void Convert(T_node* root,int height,LL_node* AdjencyList[])
{
    int count = 0;
    for(int i=0;i<height;i++)
    {
        Explore_current_level(root,i,count,AdjencyList);
        count++;
    }
    return;
}

//find height of tree
int Find_height(T_node* root)
{
    if(root == nullptr)
    {
        return 0;
    }
    return max(1+Find_height(root->left),1+Find_height(root->right));
}
//Prints a linked list
void print_list(LL_node* root)
{
    if(root == nullptr)
    {
        return;
    }
    while(root!=nullptr)
    {
        cout<<root->data;
        root = root->link;
    }
}

T_node* Create_tree()
{
    T_node* root = new T_node( 1);
    root->right = new T_node(2);
    root->left = new T_node(3);
    return root;
}

int main()
{
    T_node* root = Create_tree();
    int h = Find_height(root);
    LL_node* adjencylist[h];
    for(int i=0;i<h;i++)
    {
        adjencylist[i] = nullptr;
    }
    Convert(root,h,adjencylist);
    for(int i=0;i<h;i++)
    {
        print_list(adjencylist[i]);
        cout<<endl;
    }
    
    return 0;
}
