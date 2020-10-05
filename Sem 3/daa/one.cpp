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
    int deleteMin(Node*&);
    void deleteNode(Node*&,int);
    void traverseInOrder(Node*&);
    void traversePreOrder(Node*&);
    void traversePostOrder(Node*&);
    int getMinValue(Node*&);
    int getMaxValue(Node*&);
    Node* getLeftChild(Node*&,int);
    Node* getRightChild(Node*&,int);
    bool findElement(Node*&,int);
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

int Tree::deleteMin(Node*& node){
    if(node->leftChild != NULL){
        return deleteMin(node->leftChild);
    }
    else{
        int min = node->data;
        Node* tempNode = node;
        node = node->rightChild;
        delete tempNode;
        return min;
    }
}

void Tree::deleteNode(Node*& node,int value){
    
    if(node == NULL)
        return;
    else{
        if(value < node->data)
            deleteNode(node->leftChild,value);
        else if(value > node->data)
            deleteNode(node->rightChild,value);
        else{
            if(node->leftChild == NULL && node->rightChild == NULL){
                Node* temp = node;
                node = NULL;
                delete temp;
            }
            else if(node->leftChild == NULL && node->rightChild != NULL ){
                Node* temp = node;
                node = node->rightChild;
                delete temp;
            }
            else if(node->leftChild != NULL && node->rightChild == NULL){
                Node* temp = node;
                node = node->leftChild;
                delete temp;
            }
            else{
                int minValue = deleteMin(node->rightChild);
                node->data = minValue;
            }
        }
    }
}


int Tree::getMinValue(Node*& node){
    if(node->leftChild == NULL){
        return node->data;
    }
    else{
        getMinValue(node->leftChild);
    }

    return 0;
}

int Tree:: getMaxValue(Node*& node){
    if(node->rightChild == NULL){
        return node->data;
    }
    else{
         getMaxValue(node->rightChild);
    }

    return 0;
}

void Tree:: traverseInOrder(Node*& node){
    if(node != NULL){
        traverseInOrder(node->leftChild);
        cout << node->data << " ";
        traverseInOrder(node->rightChild);
    }
}

void Tree:: traversePreOrder(Node*& node){
    if(node != NULL){
        cout << node->data << " ";
        traversePreOrder(node->leftChild);
        traversePreOrder(node->rightChild);
    }
}

void Tree::traversePostOrder(Node*& node){
    if(node != NULL){
        traversePostOrder(node->leftChild);
        traversePostOrder(node->rightChild);
        cout << node->data << " ";
    }
}

bool Tree::findElement(Node*& node,int value){
    
    if(node->data == value)
        return true;
    else if(value < node->data){
        findElement(node->leftChild,value);
    }
    else{
        findElement(node->rightChild,value);
    }

    return false;
}

Node* Tree::getLeftChild(Node*& node,int value){
    if(findElement(node,value)){
        if(value == node->data){
            return node->leftChild;
        }
        else if(value < node->data){
            getLeftChild(node->leftChild,value);
        }
        else{
             getLeftChild(node->rightChild,value);
        }
    }

    return NULL;
}

Node* Tree::getRightChild(Node*& node,int value){
    if(findElement(node,value)){
        if(value == node->data){
            return node->rightChild;
        }
        else if(value < node->data){
             getRightChild(node->leftChild,value);
        }
        else{
            getRightChild(node->rightChild,value);
        }
    }

    return NULL;
}

int main(){

    Tree tree;
    tree.insert(tree.root,10);
    tree.insert(tree.root,20);
    tree.insert(tree.root,-1);
    tree.insert(tree.root,5);
    tree.insert(tree.root,30);
    tree.insert(tree.root,50);
    tree.insert(tree.root,2);
    tree.deleteNode(tree.root,30);
    tree.deleteNode(tree.root,2);
    tree.traverseInOrder(tree.root);
    return 0;
}