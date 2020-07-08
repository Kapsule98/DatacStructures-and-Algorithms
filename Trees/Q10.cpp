/*
Print the nodes vertically from left to right.
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

//--------------------- print vertical order left to right------------------------//
void fillMap(node* root, int dis, std::map<int, std::vector<int>> &Map){
    if(root==nullptr)
    return;
    
    fillMap(root->left, dis-1, Map);
    Map[dis].push_back(root->data);
    fillMap(root->right, dis+1, Map);
    
}
void printVerticalOrderLeftToRight(node* root){
    if(root == nullptr)
    return;
    
    std::map<int, std::vector<int>> mappy;
    std::map<int, std::vector<int>>::iterator it;
    
    fillMap(root, 0, mappy);
    
    for (it = mappy.begin(); it != mappy.end(); ++it) 
    {
        for(int i=0; i < it->second.size(); i++) {
            cout << it->second[i];
            if (it->second.size() > 1 && i!=it->second.size()-1){
                cout << " " << endl;
            }
        }
        cout << "" << endl;
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
	printVerticalOrderLeftToRight(root);
	return 0;
}
