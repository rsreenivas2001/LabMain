#include <iostream>
using namespace std;


class Node{

    int data;
    int height;
    Node* leftChild;
    Node* rightChild;
public:
    Node(int);
    friend class Tree;
};

Node:: Node(int value){
    data = value;
    height = 0;
    leftChild = NULL;
    rightChild = NULL;
}

class Tree{

public:
    Node* root;
    Tree() { root = NULL; }
    void insert(Node*&,int);
    Node* LLRotation(Node*&);
    Node* RRRotation(Node*&);
    Node* LRRotation(Node*&);
    Node* RLRotation(Node*&);
    int getBalanceFactor(Node*& node);
    int getNodeHeight(Node*&);
    void traverseInOrder(Node*&);
    void traverseLevelOrder(Node*&)
};

void Tree:: insert(Node*& node, int value){
    
    if(node == NULL){
        node = new Node(value);
        node->height = 1;
        return;
    }

    if(node->data == value){
        return;
    }

    else if(value < node->data){
        insert(node->leftChild, value);
    }
    else{
        insert(node->rightChild,value);
    }

    node->height = getNodeHeight(node);

    int balanceFactor = getBalanceFactor(node);

    if(balanceFactor > 1 && value < node->leftChild->data){
        node = LLRotation(node);


        cout << "LL ROTATION -->  ";
        traverseInOrder(root);
        cout << endl;
    }
    if(balanceFactor < -1 && value > node->rightChild->data){
        node = RRRotation(node);


        cout << "RR ROTATION -->  ";
        traverseInOrder(root);
        cout << endl;
    }
    if(balanceFactor > 1 && value > node->leftChild->data){
        node = LRRotation(node);

        cout << "LR ROTATION -->  ";
        traverseInOrder(node);
        cout << endl;
    }
    if(balanceFactor < -1 && value < node->rightChild->data){
        node = RLRotation(node);

        
        cout << "RL ROTATION -->  ";
        traverseInOrder(node);
        cout << endl;
    }
    
}

Node* Tree::LLRotation(Node*& node){
    Node* temp = node->leftChild;
    node->leftChild = temp->rightChild;
    temp->rightChild = node;

    node->height = getNodeHeight(node);
    temp->height = getNodeHeight(temp);

    return temp;

}

Node* Tree::RRRotation(Node*& node){

    Node* temp = node->rightChild;
    node->rightChild = temp->leftChild;
    temp->leftChild = node;

    node->height = getNodeHeight(node);
    temp->height = getNodeHeight(temp);
    
    return temp;
}

Node* Tree::LRRotation(Node*& node){
    Node* temp = node->leftChild;
    node->leftChild = RRRotation(temp);
    return LLRotation(node);
}

Node* Tree::RLRotation(Node*& node){
    Node* temp = node->rightChild;
    node->rightChild = LLRotation(temp);
    return RRRotation(node);
}

void Tree:: traverseInOrder(Node*& node){
    if(node != NULL){
        traverseInOrder(node->leftChild);
        cout << node->data << " ";
        traverseInOrder(node->rightChild);
    }

}

int Tree::getNodeHeight(Node*& node){
    int left,right;

    left = node && node->leftChild ? node->leftChild->height : 0;
    right = node && node->rightChild ? node->rightChild->height : 0;

    return left > right ? left + 1 : right + 1;
}

int Tree::getBalanceFactor(Node*& node){
    int left,right;

    left = node && node->leftChild ? node->leftChild->height : 0;
    right = node && node->rightChild ? node->rightChild->height : 0;

    return left - right;

}

void Tree::traverseLevelOrder(Node*& node){
    if(node == NULL) return;
    queue<Node*> Q;
    Q.push(node);
    while(!Q.empty()){
        Node* current = Q.front();
        cout << current->data << " ";
        if(current->leftChild != NULL)
            Q.push(current->leftChild);
        if(current->rightChild != NULL)
            Q.push(current->rightChild);
        Q.pop();
    }

}


int main(){

    Tree tree;

    int value;
    cout << "Enter the values to be inserted/-1 to terminate " << endl;

    while(true){
        cin >> value;

        if(value == -1) break;

        tree.insert(tree.root,value);
    }

    // tree.insert(tree.root,10);
    // tree.insert(tree.root,20);
    // tree.insert(tree.root,30);
    // tree.insert(tree.root,40);
    // tree.insert(tree.root,50);
    // tree.insert(tree.root,60);
    // tree.insert(tree.root,70);
    // tree.insert(tree.root,80);
    // tree.insert(tree.root,90);
    // tree.insert(tree.root,100);
    // tree.insert(tree.root,110);
    tree.traverseInOrder(tree.root);

    return 0;
}