#include <iostream>
#include <queue>
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
    Tree() { root = NULL; }
    void insert(Node*&,int);
    Node* LLRotation(Node*&);
    Node* RRRotation(Node*&);
    Node* LRRotation(Node*&);
    Node* RLRotation(Node*&);
    void convert(Node*&,Node*&);
    void traverseInOrder(Node*&);
    void traverseLevelOrder(Node*&);
};

void Tree:: insert(Node*& node, int value){
    
    if(node == NULL){
        node = new Node(value);
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
    
}

void Tree:: convert(Node*& tree1, Node*& tree2){

    if(tree1 != NULL && tree2 != NULL){
        while(tree1->data != tree2->data){
            if(tree1->data < tree2->data){
                //perform right rotations
                if(tree1->rightChild != NULL && tree1->rightChild->leftChild != NULL && 
                    tree1->rightChild->leftChild->data == tree2->data){
                    //RL Rotation
                    tree1 = RLRotation(tree1);
                }
                if(tree1->rightChild != NULL || tree2->leftChild != NULL){
                    //RR Rotation
                    tree1 = RRRotation(tree1);
                }
            }
            if(tree1->data > tree2->data){
                //perform left rotations
                if(tree1->leftChild != NULL && tree1->leftChild->rightChild != NULL && 
                    tree1->leftChild->rightChild->data == tree2->data){
                    //LR Rotation
                    tree1 = LRRotation(tree1);
                }
                if(tree1->rightChild != NULL || tree1->leftChild != NULL){
                    //LL rotation
                    tree1 = LLRotation(tree1);
                }
            }
        }
        convert(tree1->leftChild,tree2->leftChild);
        convert(tree1->rightChild,tree2->rightChild);
    }

}

Node* Tree::LLRotation(Node*& node){
    Node* temp = node->leftChild;
    node->leftChild = temp->rightChild;
    temp->rightChild = node;

    return temp;

}

Node* Tree::RRRotation(Node*& node){

    Node* temp = node->rightChild;
    node->rightChild = temp->leftChild;
    temp->leftChild = node;
    
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

    Tree tree1,tree2;

    

    tree1.insert(tree1.root,10);
    tree1.insert(tree1.root,11);
    tree1.insert(tree1.root,12);
    tree1.insert(tree1.root,13);
    tree1.insert(tree1.root,14);
    tree1.insert(tree1.root,15);
    tree1.insert(tree1.root,16);
    tree1.insert(tree1.root,17);
    tree1.traverseLevelOrder(tree1.root);
    cout<<endl;
    tree2.insert(tree2.root,17);
    tree2.insert(tree2.root,16);
    tree2.insert(tree2.root,15);
    tree2.insert(tree2.root,14);
    tree2.insert(tree2.root,13);
    tree2.insert(tree2.root,12);
    tree2.insert(tree2.root,11);
    tree2.insert(tree2.root,10);
    tree2.traverseLevelOrder(tree2.root);
    cout<<endl;
    tree1.convert(tree1.root,tree2.root);
    tree1.traverseLevelOrder(tree1.root);
    //tree1.traverseInOrder(tree1.root);


    return 0;
}