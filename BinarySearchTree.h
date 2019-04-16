//
// Created by ruben on 4/5/19.
//

#ifndef LINKEDLISTVSBINARYTREE_BINARYTREE_H
#define LINKEDLISTVSBINARYTREE_BINARYTREE_H
#include "Location.h"

namespace UTEC {

    struct Node_bt {
        Location data;
        Node_bt* right;
        Node_bt* left;

        Node_bt(Location data): data{data}, right{nullptr}, left{nullptr} {}
    };

    class BinarySearchTree {
        Node_bt* root;
    public:
        BinarySearchTree(): root{nullptr} {}
        ~BinarySearchTree();
        Node_bt* insert(Node_bt* node_tmp, const Location& data);
        void clear();
        bool is_empty();
        Node_bt* get_root();
        Node_bt* search(std::string position_id);
        void print();
    };

    void load_locations(BinarySearchTree* linked_list, std::string file_name);
    void print_node(Node_bt* node);
}

#endif //LINKEDLISTVSBINARYTREE_BINARYTREE_H
