//
// Created by DELL on 10/15/2025.
//

#ifndef LINKED_LIST_LINKED_LIST_H
#define LINKED_LIST_LINKED_LIST_H
#include <iosfwd>
#include "Node.h"


class Node;

class Linked_List {
    Node *head{};
    Node* tail{};
    int n_count = 0;
    int n =0;
    void Reverse(Node* node);
public:
    Linked_List()= default;
    ~Linked_List() {
        const Node* prev = head;


        while (prev != nullptr)  {
            const Node *temp = prev->next;
            delete prev;
            prev = temp;

        }

    }
    Linked_List(const Linked_List& olist);
    void insert_node(int value);
    void delete_node(int value);
    void display();
    void update_by_pos(int pos,int new_value) const;
    void update_by_value(int old_value, int new_value) const;
    void display_reverse();
    void insert_at_pos(int pos,int value);
    void delete_at_pos(int pos);
    friend std::ostream& operator<<(std::ostream& stream,const Linked_List& list);
    Linked_List operator+(const Linked_List& list) const {
    const Node* temp = list.head;
    Linked_List F_list = *this;
    while (temp != nullptr) {
        F_list.insert_node(temp->data);
        temp = temp->next;
    }
    return F_list;
}
    Linked_List operator-(const Linked_List& list)const {
        Linked_List F_list = *this;
        const Node *temp = list.head;
        while (temp != nullptr) {
            F_list.delete_node(temp->data);
            temp = temp->next;
        }
        return F_list;
    }
    [[nodiscard]] int get_Value_At(int pos) const;
    [[nodiscard]] bool is_empty() const;
    [[nodiscard]] int get_size() const;
    friend class STACK;
    friend std::ostream& operator<< (std::ostream& stream, const STACK& stack);
};


#endif //LINKED_LIST_LINKED_LIST_H