//
// Created by ruben on 4/5/19.
//

#ifndef LINKEDLISTVSBINARYTREE_LINKEDLIST_H
#define LINKEDLISTVSBINARYTREE_LINKEDLIST_H
#include "Location.h"

namespace UTEC {

    struct Node {
        Location data;
        Node* next;

        Node(Location data): data{data}, next{nullptr} {}
    };

    class LinkedList {
        Node* head;
        Node* tail;
    public:
        LinkedList(): head{nullptr}, tail{nullptr} {}
        ~LinkedList();
        int size();
        bool is_empty();
        Node* get_head();
        Node* get_tail();
        void add_head(const Location& data);
        void add_tail(const Location& data);
        void print();
        void insert(Node* position, const Location& data);
        Node* search(std::string position_id);
    };
    void load_locations(LinkedList* linked_list, std::string file_name);
}

#endif //LINKEDLISTVSBINARYTREE_LINKEDLIST_H
