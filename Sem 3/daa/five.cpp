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


int main(){

    Tree tree;

    int X;
    int value;
    cout << "Enter the value of X" << endl;
    cin >> X;
    
    while (true)
    {
        cout << "Enter the array values -1 to terminate ";
        cin >> value;
        if(value == -1) 
            break;
        
        tree.insert(tree.root,value);
        //cout << "testing";
    }
    

    int number = tree.getNodeCount(tree.root);

    if(number == X)
        cout << "The array is GOOD " << endl;
    else if(number < X)
        cout << "The array is BAD!! " << endl;
    else
        cout << "The array is AVERAGE!!" << endl;

    return 0;
}