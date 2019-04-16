#include "BinarySearchTree.h"
UTEC::BinarySearchTree::~BinarySearchTree(){

}

bool UTEC::BinarySearchTree::is_empty() {
    return root == nullptr;
}

UTEC::Node_bt *UTEC::BinarySearchTree::get_root() {
    return root;
}

UTEC::Node_bt *UTEC::BinarySearchTree::insert(Node_bt* node_tmp, const Location& data){   //Inicialmente recibe como argumento la raiz del arbol
    if(node_tmp == nullptr){
        return new Node_bt(data);
    }
    else{
        Node_bt* node_new = new Node_bt(data);
        if(node_tmp->data.getPosition_id() > node_new->data.getPosition_id()){
            node_tmp->right = insert(node_tmp->right, data);
        }
        else if(node_tmp->data.getPosition_id() < node_new->data.getPosition_id()){
            node_tmp->left = insert(node_tmp->left, data);
        }
    }
    return node_tmp;
}