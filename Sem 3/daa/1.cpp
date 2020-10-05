#include<iostream>
using namespace std;

class Node{
    int value;
    Node* leftchild;
    Node* rightchild;
    public:
    Node(int);
    friend class Tree;
};

Node::Node(int x){
    value = x;
}

class Tree{
    public:
    Node* Root;
    Tree(){
        Root = NULL;
    }
    void inserter(Node*&,int);
    void deleter(Node*&,int);
    void traverseInorder(Node*&);
    void traversePreorder(Node*&);
    void traversePostorder(Node*&);
    int deletemin(Node*&);
    int getMaxValue(Node*&);
    int getMinValue(Node*&);
    Node* getLeftChild(Node*&,int);
    Node* getRightChild(Node*&,int);
    bool findElement(Node*&,int);

};

void Tree::inserter(Node*& node ,int value){
    if(node==NULL){
        node = new Node(value);
        cout<<"inserted";
        return;
    }
    else if(value >= node->value){
            inserter(node->rightchild,value);
        }            
        else{
            inserter(node->leftchild,value);
        }          
}

void Tree::deleter(Node*& node,int value){
    if(node==NULL)
        return;
    else{
        if(value<node->value){
            deleter(node->leftchild,value);
        }
        else if(value > node->value){
                deleter(node->rightchild,value);
        }
        else{
            if(node->leftchild == NULL && node->rightchild == NULL){
                Node* t = node;
                node = NULL;
                delete t;
            }
            else if(node->leftchild == NULL && node->rightchild != NULL){
                Node*t = node;
                node = node->rightchild;
                delete t;
            }
            else if(node->leftchild != NULL && node->rightchild == NULL){
                Node*t = node;
                node = node->leftchild;
                delete t;
            }
            else{
                int minimum = deletemin(node->rightchild);
                node->value = minimum; 
            }
        }

    }
}


int Tree::deletemin(Node*& node){
    if(node->leftchild == NULL){
        deletemin(node->leftchild);
    }
    else{
        int minimum = node->value;
        Node* t = node;
        node = node->rightchild;
        delete t;
        return minimum;
    }
}

void Tree::traverseInorder(Node*& node){
    if(node != NULL){
        traverseInorder(node->leftchild);
        cout << node->value<< " ";
        traverseInorder(node->rightchild);
    }
}

void Tree::traversePreorder(Node*& node){
    if(node != NULL){
        cout << node->value<< " ";
        traversePreorder(node->leftchild);
        traversePreorder(node->rightchild);
    }
}

void Tree::traversePostorder(Node*& node){
    if(node != NULL){
        traversePostorder(node->leftchild);
        traversePostorder(node->rightchild);
        cout << node->value<< " ";
    }
}

int Tree::getMinValue(Node*& node){
    if(node->leftchild == NULL){
        return node->value;
    }
    else{
        getMinValue(node->leftchild);
    }
    return 0;
}

int Tree:: getMaxValue(Node*& node){
    if(node->rightchild == NULL){
        return node->value;
    }
    else{
         getMaxValue(node->rightchild);
    }
    return 0;
}

bool Tree::findElement(Node*& node,int value){
    
    if(node->value == value)
        return true;
    else if(value < node->value){
        findElement(node->leftchild,value);
    }
    else{
        findElement(node->rightchild,value);
    }

    return false;
}

Node* Tree::getLeftChild(Node*& node,int value){
    if(findElement(node,value)){
        if(value == node->value){
            return node->leftchild;
        }
        else if(value < node->value){
            getLeftChild(node->leftchild,value);
        }
        else{
             getLeftChild(node->rightchild,value);
        }
    }
    return NULL;
}

Node* Tree::getRightChild(Node*& node,int value){
    if(findElement(node,value)){
        if(value == node->value){
            return node->rightchild;
        }
        else if(value < node->value){
             getRightChild(node->leftchild,value);
        }
        else{
            getRightChild(node->rightchild,value);
        }
    }
    return NULL;
}

int main(){
    Tree bst;
    bst.inserter(bst.Root,10);
    bst.inserter(bst.Root,20);
    bst.inserter(bst.Root,30);
    bst.inserter(bst.Root,5);
    bst.inserter(bst.Root,30);
    bst.inserter(bst.Root,50);
    bst.inserter(bst.Root,2);
    cout<<"hinsert";
    bst.deleter(bst.Root,30);
    bst.deleter(bst.Root,2);
    cout<<"hi";
    bst.traverseInorder(bst.Root);
    cout<<"hi";
    return 0;
}