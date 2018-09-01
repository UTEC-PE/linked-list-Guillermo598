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
        List(){
            head = tail = nullptr;
        };

        T front(){
            if (head == nullptr)
                throw "ListError";
            return head -> data;
        };
        T back(){
            if (head == nullptr)
                throw "ListError";
            return tail -> data;
        };
        void push_front(T value){
            Node<T>* temp = new Node<T>;
            temp -> data = value;
            temp -> next = head;
            if (empty())
                head = tail = temp;
            else
                head = temp;
        };
        void push_back(T value){
            Node<T>* temp = new Node<T>;
            temp -> data = value;
            temp -> next = nullptr;
            if (empty())
                head = tail = temp;
            else {
                tail->next = temp;
                tail = temp;
            }
        };
        void pop_front(){
            if (empty())
                throw "ListError";
            else {
                Node<T> *temp = head;
                head = head->next;
                delete temp;
            }
        };
        void pop_back(){
            if (empty())
                throw "ListError";
            else {
                Node<T> *temp = head;
                for (int i = 1; i < size()-1; i++)
                    temp = temp -> next;
                tail = temp;
                temp = temp -> next;
                delete temp;
            }
        };
        T get(int position){
            if (position > size()-1 || position < 0)
                throw "ListError";
            else{
                Node<T>* temp = head;
                for (int i = 0; i < position; i++)
                    temp = temp -> next;
                return temp -> data;
            }
        };
        void concat(List<T> &other){
            this -> tail -> next = other -> head;
            this -> tail = other -> tail;
        };
        bool empty(){
            return head == nullptr;
        };
        int size(){
            Node<T>* temp = head;
            int size = 0;
            while (temp != nullptr){
                temp = temp -> next;
                size++;
            }
            return size;
        };
        void print(){
            Node<T>* temp = head;
            while (temp != nullptr){
                cout << temp -> data << endl;
                temp = temp -> next;
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

        ~List(){
            head -> killSelf();
        };
};
#endif
