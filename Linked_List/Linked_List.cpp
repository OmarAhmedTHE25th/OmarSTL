//
// Created by DELL on 10/15/2025.
//

#include "Linked_List.h"

#include <iostream>
#include <print>
#include "Node.h"
using  namespace std;
void Linked_List::insert_node(const int value) {
    Node* temp = head;
    if (head == nullptr)  {
        head = new Node(value);
        tail = head;
        n_count++;
        return;
    }


    while (temp->next != nullptr) temp = temp->next;
    temp->next = new Node(value);
    tail = temp;
    n_count++;
}
void Linked_List::display() {
int i =0;
    Node* temp = head;
    while (temp != nullptr) {
        std::println("Node {}'s value: {}",i,temp->data);
        temp = temp->next;
        i++;
    }
    n =i;
}
void Linked_List::delete_node(const int value) {
    if (head != nullptr && head->data == value) {
        const Node* temp = head;
        head = head->next;
        delete temp;
        n_count--;
        return;
    }
    Node *prev = head;
   Node  *temp = head->next;
    while (temp != nullptr) {

        if (temp->data == value)  {
            if (temp->next == nullptr) {prev->next = nullptr; n_count--; delete temp; return;}
            Node *nextNode = temp->next;
            prev->next = nextNode;
            delete temp;
            n_count--;
            return;
        }
        prev = temp;
        temp = temp->next;
    }

}
void Linked_List::update_by_pos(const int pos, const int new_value) const {
    Node* temp = head;
    int idx =0;
    while (temp != nullptr) {

        if (pos < 0 or pos > n_count) {std::cout<< "[[ERROR]] Invalid position\n" << std::endl;; return;}
        if (idx == pos)  {
            temp->data = new_value;
            std::cout << "Update Successful!\n";
            return;
        }
        idx++;
        temp = temp->next;
    }
    if (temp == nullptr){ std::cout << "[[ERROR]] Empty List,Nothing to update\n"<< std::endl; }
}
void Linked_List::update_by_value(const int old_value,const int new_value) const {
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->data == old_value) {
            temp->data = new_value;
            std::cout << "Update Successful\n" << std::endl;
            return;
        }

        temp = temp->next;
        if (temp->next == nullptr and temp->data != old_value){std::cout << "[[ERROR]] Value doesnt exist\n"<<std::endl; return;}
    }

    if (temp == nullptr){ std::cout << "[[ERROR]] Empty List,Nothing to update\n"<< std::endl; }
}
void Linked_List::Reverse(Node *node) {
    static int idx = n-1;
    if (node == nullptr)return;
    Reverse(node->next);
    std::println("Node {}'s value: {}", idx,node->data);
    idx--;
}
void Linked_List::display_reverse() {
  Reverse(head);
}
void Linked_List::insert_at_pos(const int pos,const int value) {
    int idx = 0;

    if (pos < 0 or pos > n_count) {std::cout<< "[[ERROR]] Invalid position\n" << std::endl;; return;}
    if (pos == 0 ) {
        Node* NewNode{};
        NewNode = new  Node(value);
        NewNode->next = head;
        head = NewNode;
        n_count++;
        return;

    }



    Node *prev = head;
    Node *temp = head->next;
    while (temp!= nullptr) {
        if (idx == pos)  {
            Node* NewNode{};
            NewNode = new  Node(value);
            NewNode->next = temp;
            prev->next = NewNode;
            return;
        }
        if (temp->next == nullptr) {
            temp->next = new Node(value);
            n_count++;
            return;
        }

        prev = temp;
        temp = temp->next;
        idx++;
        n_count++;

    }
}
void Linked_List::delete_at_pos(const int pos) {
    if (pos < 0 or pos >= n_count) {std::cout<< "[[ERROR]] Invalid position\n" << std::endl; return;}
    if (pos == 0 and head != nullptr )
        {
        const Node* temp = head;
        head = head->next;
        delete temp;
        n_count--;
        return;
    }

    Node *prev = head;
    Node *temp = head->next;
    int idx = 1;
    while (temp != nullptr) {
        if (pos == idx) {
            if (temp->next == nullptr) {
                prev->next = nullptr;
                delete temp;
                n_count--;
                return;
            }
            Node *nextNode = temp->next;
            prev->next = nextNode;
            delete temp;
            n_count--;
            return;
        }
        prev = temp;
        temp = temp->next;
        idx++;
    }
}
std::ostream& operator<<(std::ostream& stream,const Linked_List& list) {
    Node *temp = list.head;
    while (temp != nullptr) {
        stream << temp->data << " -> ";
        temp = temp -> next;
    }
    stream << "nullptr\n";
    return stream;
}
int Linked_List::get_Value_At(const int pos) const {
    const Node* current = head;
    int index = 0;
    while (current && index < pos) {
        current = current->next;
        index++;
    }
    if (!current) throw std::out_of_range("Position out of bounds");
    return current->data;
}
Linked_List::Linked_List(const Linked_List &olist)
    : head(nullptr), tail(nullptr), n_count(0), n(0)
{
    if (olist.head == nullptr) {
        return;  // Empty list, nothing to copy
    }
    
    // Copy the first node
    head = new Node(olist.head->data);
    tail = head;
    n_count = 1;
    
    const Node* source = olist.head->next;
    Node* current = head;
    
    while (source != nullptr) {
        current->next = new Node(source->data);
        current = current->next;
        tail = current;
        source = source->next;
        n_count++;
    }
}
bool Linked_List::is_empty() const {
    if (n_count == 0 )
        return true;

    return false;
}
int Linked_List::get_size() const {
    return n_count;
}













