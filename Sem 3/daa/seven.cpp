#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int count = 1;

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
    void insert(Node*&,int);
    vector<int> traverseLevelOrder(Node*&);
    int minSwaps(vector<int>);
};

void Tree::insert(Node*& node,int value){

    if(node == NULL){
        node = new Node(value);
        cout<<"in insert";
        return;
    }
    
    queue<Node*> Q;
    Q.push(node);

    //cout << count++;

    while (!Q.empty())
    {
        Node* temp = Q.front();
        Q.pop();

        if(!temp->leftChild){
            temp->leftChild = new Node(value);
            break;
        }
        else{
            Q.push(temp->leftChild);
        }

        if(!temp->rightChild){
            temp->rightChild = new Node(value);
            break;
        }
        else
        {
            Q.push(temp->rightChild);
        }
        
    }
    
}

vector<int> Tree::traverseLevelOrder(Node*& node){
    queue<Node*> Q;
    Q.push(node);

    vector<int> seqs;

    while (!Q.empty())
    {
        Node* current = Q.front();
        cout << current->data << " ";
        seqs.push_back(current->data);
        if(current->leftChild != NULL)
            Q.push(current->leftChild);
        if(current->rightChild != NULL)
            Q.push(current->rightChild);
        Q.pop();
    }
    
    cout << endl;

    return seqs;
}

int Tree::minSwaps(vector<int> seqs){
    vector<pair <int,int> > vect(seqs.size());
    int count = 0;

    for(int i = 0; i < vect.size(); i++){
        vect[i].first = seqs[i], vect[i].second = i;
    }

    sort(vect.begin(), vect.end());
    for(int i = 0; i < vect.size(); i++){
        if(i == vect[i].second)
            continue;
        else
        {
            swap(vect[i].first, vect[vect[i].second].first);
            swap(vect[i].second, vect[vect[i].second].second);
        }
        
        if( i != vect[i].second)
            --i;
        count++;

    }

    return count;
}

int main(){

    Tree tree;
    tree.insert(tree.root,10);
    tree.insert(tree.root,5);
    tree.insert(tree.root,7);
    tree.insert(tree.root,9);
    tree.insert(tree.root,14);
    tree.insert(tree.root,16);
    tree.insert(tree.root,54);
    vector<int> seqs = tree.traverseLevelOrder(tree.root);
    cout<<"hi";
    cout << tree.minSwaps(seqs);


    return 0;
}