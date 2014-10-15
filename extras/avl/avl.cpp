#include <iostream>
using namespace std;
#define MAX2(a, b) (a > b ? a : b)

template <class T> 
struct Node{
    Node * left;
    Node * right;
    Node * parent;
    T val;
    int size; //size of subtree rooting self
    int height;
    Node(){
        left = NULL;
        right = NULL;
        parent = NULL;
        height = 0;
        size = 0;
    }
    Node(Node *p, T v){
        left = NULL;
        right = NULL;
        parent = p;
        val = v;
        height = 0;
        size = 0;
    }
};


template <class T>
int get_height(Node<T> *node){
    if(node == NULL) return -1;
    return node->height;
}

template <class T>
void update_ancestors(Node<T> *node){
    Node<T> * parent = node->parent;
    if(node == NULL) return;
    while(parent != NULL){
        parent->height = MAX2(get_height(parent->left), get_height(parent->right)) + 1;
        parent = parent->parent;
    }
}

template <class T>
Node<T>* insert(Node<T> *&root, T val){
    if(root == NULL){
        root = new Node<T>(NULL, val);
        //cout << "root " << val <<endl;
        return root;
    }

    Node<T> *curr = root;

    while(curr != NULL){
        if(val > curr->val){
            //cout << "val" << val << " > " << curr->val << endl;
            if(curr->right == NULL){
                Node<T> * n = new Node<T>(curr, val);
                curr->right = n;
                update_ancestors(n);
                return n;
            }
            curr = curr->right;
        }
        else{
            //cout << "val" << val << " < " << curr->val << endl;
            if(curr->left == NULL){
                Node<T> * n = new Node<T>(curr, val);
                curr->left = n;
                update_ancestors(n);
                return n;
            }
            curr = curr->left;
        }
    }
}

template <class T> 
void print(Node<T> *root){
    if(root == NULL) return;
    cout << root->val << "," << root->height << " : ";
    print(root->left);
    print(root->right);
}

int main(){
    Node<int> * root = NULL;
    insert<int>(root, 4);
    insert<int>(root, 6);
    insert<int>(root, 2);
    insert<int>(root, 1);
    insert<int>(root, -1);
    print<int>(root);
    cout << endl;
}
