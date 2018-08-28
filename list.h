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
            Iterator = head;
            while (Iterator -> next -> next != nullptr)
                Iterator = Iterator -> next;
            tail = Iterator;
            tail -> next = nullptr;
        };
        T get(int position){
            int i = 0;
            Iterator = head;
            while (Iterator != nullptr && i < position){
                Iterator = Iterator -> next;
                i++;
            }
            T value = Iterator -> data;
            return value;
        };
        void concat(List<T> &other){
            this -> tail -> next = other -> head;
            this -> tail = other -> tail;
        };
        bool empty(){
            if (size() == 0)
                return true;
            else
                return false;
        };
        int size(){
            Iterator = head;
            int size = 0;
            while (Iterator != nullptr){
                Iterator = Iterator -> next;
                size++;
            }
            return size;
        };
        void print(){
            Iterator = head;
            while (Iterator != nullptr){
                cout << Iterator -> data << endl;
                Iterator = Iterator -> next;
            }
        };
        void print_reverse(){

        };
        void clear(){
            Iterator = head;
            while (Iterator != nullptr){
                Node<T>* temp = Iterator;
                Iterator = Iterator -> next;
                delete temp;
            }
        };
        Iterator<T> begin();
        Iterator<T> end();

        ~List();
};
#endif
