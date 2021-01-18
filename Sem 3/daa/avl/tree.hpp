#include <iostream>
using namespace std;

#define INT32_MIN (-2147483647 - 1)
#define INT32_MAX 2147483647

class AVLNode{

    int data;
    int height;
    AVLNode* leftChild;
    AVLNode* rightChild;
public:
    AVLNode(int);
    friend class AVLTree;
};

AVLNode:: AVLNode(int value){
    data = value;
    height = 0;
    leftChild = NULL;
    rightChild = NULL;
}

class AVLTree{

public:
    AVLNode* root;
    AVLTree() { root = NULL; }
    void insert(AVLNode*&,int);
    void deleteAVLNode(AVLNode*&,int);
    void deleteMin(AVLNode*&);
    void deleteRoot(AVLNode*&);
    AVLNode* LLRotation(AVLNode*&);
    AVLNode* RRRotation(AVLNode*&);
    AVLNode* LRRotation(AVLNode*&);
    AVLNode* RLRotation(AVLNode*&);
    int getMinValue(AVLNode*&);
    int getBalanceFactor(AVLNode*& node);
    int getAVLNodeHeight(AVLNode*&);
    int getHeight(AVLNode*&);
    int countLeaf(AVLNode*&);
    void traverseInOrder(AVLNode*&);
    bool findElement(AVLNode*&,int);
};

void AVLTree:: insert(AVLNode*& node, int value){
    
    if(node == NULL){
        node = new AVLNode(value);
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

    node->height = getAVLNodeHeight(node);

    int balanceFactor = getBalanceFactor(node);

    if(balanceFactor > 1 && value < node->leftChild->data){
        node = LLRotation(node);

    }
    if(balanceFactor < -1 && value > node->rightChild->data){
        node = RRRotation(node);

    }
    if(balanceFactor > 1 && value > node->leftChild->data){
        node = LRRotation(node);
    }
    if(balanceFactor < -1 && value < node->rightChild->data){
        node = RLRotation(node);

    }
    
}

void AVLTree::deleteMin(AVLNode*& node){
    if(node == NULL){
        return;
    }

    int min = getMinValue(node);
    deleteAVLNode(node,min);
}

void AVLTree::deleteRoot(AVLNode*& node){
    if(node == root){
        int value = node->data;
        deleteAVLNode(node,value);
    }
}

void AVLTree::deleteAVLNode(AVLNode*& node,int value){
    
    if(node == NULL)
        return;
    else{
        if(value < node->data)
            deleteAVLNode(node->leftChild,value);
        else if(value > node->data)
            deleteAVLNode(node->rightChild,value);
        else{
            if(node->leftChild == NULL && node->rightChild == NULL){
                AVLNode* temp = node;
                node = NULL;
                delete temp;
            }
            else if(node->leftChild == NULL && node->rightChild != NULL ){
                AVLNode* temp = node;
                node = node->rightChild;
                delete temp;
            }
            else if(node->leftChild != NULL && node->rightChild == NULL){
                AVLNode* temp = node;
                node = node->leftChild;
                delete temp;
            }
            else{
                //implement delete
                int min = getMinValue(node->rightChild);
                node->data = min;
                deleteAVLNode(node->rightChild,min);
            }
        }
    }

    if(node == NULL) return;

    node->height = getAVLNodeHeight(node);
    int balance = getBalanceFactor(node);

    //perform AVL Rotations
    if(node != NULL && (balance != 1 && balance != -1 && balance != 0)){
        if(node->data < value && (getBalanceFactor(node->leftChild) == 0 || getBalanceFactor(node->leftChild) == -1)){
            //LL rotation
            node = LLRotation(node);
        }
        if(node->data < value && (getBalanceFactor(node->leftChild) == 1)){
            //R-1
            node = LRRotation(node);
        }
        if(node->data > value && node->rightChild == NULL){
            //LL
            node = LLRotation(node);
        }
        if(node->data > value && (getBalanceFactor(node->rightChild) == 0 || getBalanceFactor(node->rightChild) == -1)){
            //RR
            node = RRRotation(node);
        }
        if(node->data < value && getBalanceFactor(node->leftChild) == -1){
            //L1
            node = RLRotation(node);
        }
    }
    
}

AVLNode* AVLTree::LLRotation(AVLNode*& node){
    AVLNode* temp = node->leftChild;
    node->leftChild = temp->rightChild;
    temp->rightChild = node;

    node->height = getAVLNodeHeight(node);
    temp->height = getAVLNodeHeight(temp);

    return temp;

}

AVLNode* AVLTree::RRRotation(AVLNode*& node){

    AVLNode* temp = node->rightChild;
    node->rightChild = temp->leftChild;
    temp->leftChild = node;

    node->height = getAVLNodeHeight(node);
    temp->height = getAVLNodeHeight(temp);
    
    return temp;
}

AVLNode* AVLTree::LRRotation(AVLNode*& node){
    AVLNode* temp = node->leftChild;
    node->leftChild = RRRotation(temp);
    return LLRotation(node);
}

AVLNode* AVLTree::RLRotation(AVLNode*& node){
    AVLNode* temp = node->rightChild;
    node->rightChild = LLRotation(temp);
    return RRRotation(node);
}

void AVLTree:: traverseInOrder(AVLNode*& node){
    if(node != NULL){
        traverseInOrder(node->leftChild);
        cout << node->data << " ";
        traverseInOrder(node->rightChild);
    }

}

int AVLTree::getAVLNodeHeight(AVLNode*& node){
    int left,right;

    left = node && node->leftChild ? node->leftChild->height : 0;
    right = node && node->rightChild ? node->rightChild->height : 0;

    return left > right ? left + 1 : right + 1;
}

int AVLTree::getBalanceFactor(AVLNode*& node){
    int left,right;

    left = node && node->leftChild ? node->leftChild->height : 0;
    right = node && node->rightChild ? node->rightChild->height : 0;

    return left - right;

}

int AVLTree::getMinValue(AVLNode*& node){
    if(node != NULL){
        if(node->leftChild == NULL){
            return node->data;
        }
        else
        {
            return getMinValue(node->leftChild);
        }
        
    }

    return INT32_MIN;
}

bool AVLTree::findElement(AVLNode*& node,int value){
    
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

int AVLTree::getHeight(AVLNode*& node){

    if(node == NULL) return 0;

    else{
        int left = getHeight(node->leftChild);
        int right = getHeight(node->rightChild);

        return left > right ? left + 1 : right + 1;
    }
}

int AVLTree::countLeaf(AVLNode*& node){
    if(node != NULL){
        if(node->leftChild == NULL && node->rightChild == NULL){
            return 1;
        }
        int leftCount = countLeaf(node->leftChild);
        int rightCount = countLeaf(node->rightChild);
        return leftCount + rightCount;
    }
    else{
        return 0;
    }
}