#include <iostream>
#include "tree.hpp"
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>


#define INT32_MIN (-2147483647 - 1)
#define INT32_MAX 2147483647

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
    vector<int> traverseInOrder(Node*&);
};

void Tree:: insert(Node*& node, int value){
    
    if(node == NULL){
        node = new Node(value);
        return;
    }

    if(value == node->data){
        return;
    }

    if(node->data == value) return;

    else if(value < node->data){
        insert(node->leftChild, value);
    }
    else{
        insert(node->rightChild,value);
    }
}


vector<int> Tree:: traverseInOrder(Node*& node){
    stack<Node*> S;
    vector<int> vect;

    Node* current = node;

    while(current != NULL || S.empty() == false){

        while(current != NULL){
            S.push(current);
            current = current->leftChild;
        }

        current = S.top();
        S.pop();

        //cout << current->data << " ";
        vect.push_back(current->data);

        current = current->rightChild;
    }

    return vect;

}

int main(){

    Tree tree1;
    Tree tree2;
    AVLTree tree;
    // cout << "Enter the elements of tree 1/-1 to terminate " << endl;

    // int value;
    // while(true){
    //     cin >> value;

    //     if(value == -1){
    //         break;
    //     }

    //     tree1.insert(tree1.root,value);
    // }

    // cout << "Enter the elements of tree 2/-1 to terminate " << endl;
    // while(true){
    //     cin >> value;

    //     if(value == -1){
    //         break;
    //     }

    //     tree2.insert(tree2.root,value);
    // }

    tree1.insert(tree1.root,30);
    tree1.insert(tree1.root,32);
    tree1.insert(tree1.root,34);
    tree1.insert(tree1.root,21);
    tree1.insert(tree1.root,3);
    tree1.insert(tree1.root,39);
    tree1.insert(tree1.root,12);
    tree1.insert(tree1.root,54);
    tree1.insert(tree1.root,1);

    tree2.insert(tree2.root,29);
    tree2.insert(tree2.root,2);
    tree2.insert(tree2.root,43);
    tree2.insert(tree2.root,54);
    tree2.insert(tree2.root,52);
    tree2.insert(tree2.root,1);
    tree2.insert(tree2.root,5);
    tree2.insert(tree2.root,43);
    tree2.insert(tree2.root,5);



    vector<int> v1 = tree1.traverseInOrder(tree1.root);
    //cout << endl;
    vector<int> v2 = tree2.traverseInOrder(tree2.root);
    // cout << endl;

    //Displaying first tree
    for(int i = 0; i < v1.size(); i++){
        cout << v1[i] << " ";
    }
    cout << endl;


    //Displaying second tree
    for(int i = 0; i < v2.size(); i++){
        cout << v2[i] << " ";
    }
    cout << endl;

    //merging the two sorted arrays
    vector<int> v3(v1.size() + v2.size());
    merge(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());

    //Displaying the merged array
    for(int i = 0; i < v3.size(); i++){
        cout << v3[i] << " ";
    }
    cout << endl;

    //inserting the sorted array into AVL tree
    int i = 0;
    Tree tree3;
    while(i < v3.size()){
        tree.insert(tree.root,v3[i++]);
    }

    //Display the binary tree after merging the two trees
    tree.traverseInOrder(tree.root);
    cout << endl;

    return 0;
}