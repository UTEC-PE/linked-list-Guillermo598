#ifndef LIST_H
#define LIST_H

#include <iostream>
#include "node.h"
#include "iterator.h"

using namespace std;

template <typename T>
class List {
    private:
        Node<T>* head;
        Node<T>* tail;
        int nodes;

        void print_reverse(Node<T>* head);

    public:
        List();

        T front(){
            return head -> data;
        };
        T back(){
            return tail -> data;
        };
        void push_front(T value){
            Node<T>* temp = new Node<T>;
            temp -> data = value;
            if (empty()){
                temp -> next = nullptr;
                tail = temp;
                head = temp;
            }
            else{
                head -> next = head;
                head = temp;
            }
        };
        void push_back(T value){
            Node<T>* temp = new Node<T>;
            temp -> data = value;
            temp -> next = nullptr;
            if (empty()){
                tail = temp;
                head = temp;
            }
            else{
                tail -> next = temp;
                tail = temp;
            }
        };
        void pop_front(){
            Node<T>* temp = head;
            head -> next = head;
            delete temp;
        };
        void pop_back(){
            Node<T>* temp = tail;
            //
            tail -> next = nullptr;
            delete temp;
        };
        T get(int position);
        void concat(List<T> &other);
        bool empty();
        int size();
        void print();
        void print_reverse();
        void clear();
        Iterator<T> begin();
        Iterator<T> end();

        ~List();
};
#endif
