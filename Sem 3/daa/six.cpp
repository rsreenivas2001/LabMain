#include <iostream>
using namespace std;

class Node{

    int data;
    Node* leftChild;
    Node* rightChild;
public:
    Node(int);
    friend class Tree;
};

Node:: Node(int value){
    data = value;
    leftChild = NULL;
    rightChild = NULL;
}

class Tree{

public:
    Node* root;
    Tree() { root = NULL; };
    void insert(Node*&,int);
    int getNodeCount(Node*&);
    int getHeight(Node*&);
};

void Tree:: insert(Node*& node, int value){
    
    if(node == NULL){
        node = new Node(value);
        return;
    }

    else if(value < node->data){
        insert(node->leftChild, value);
    }
    else{
        insert(node->rightChild,value);
    }
}

int Tree::getNodeCount(Node*& node){
    //int count = 1;

    if(node != NULL){
        int count = 1;
        count += getNodeCount(node->leftChild) + getNodeCount(node->rightChild);
        return count;
    }

    return 0;
}
int Tree::getHeight(Node*& node){

    if(node == NULL) 
        return 0;
    else{
        int left = getHeight(node->leftChild);
        int right = getHeight(node->rightChild);

        return left > right ? left + 1 : right + 1;
    }
}

int main(){

    Tree tree;
    int MONK[] = {2,1,3};
    int len = (sizeof(MONK)/sizeof(MONK[0]));
    
    for(int i = 0; i < len; i++){
        tree.insert(tree.root,MONK[i]);
    }

    cout << tree.getHeight(tree.root) << endl; 

    return 0;
}