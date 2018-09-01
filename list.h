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
        nodes = 0;
    };

    T front(){
        if (head == nullptr)
            cout << "ListError" << endl;
        else
            return head -> data;
    };
    T back(){
        if (head == nullptr)
            cout << "ListError" << endl;
        else
            return tail -> data;
    };
    void push_front(T value){
        Node<T>* temp = new Node<T>;
        temp -> data = value;
        temp -> next = head;
        if (head == nullptr)
            head = tail = temp;
        else
            head = temp;
        nodes++;
    };
    void push_back(T value){
        Node<T>* temp = new Node<T>;
        temp -> data = value;
        temp -> next = nullptr;
        if (head == nullptr)
            head = tail = temp;
        else {
            tail->next = temp;
            tail = temp;
        }
        nodes++;
    };
    void pop_front(){
        if (head == nullptr)
            cout << "ListError" << endl;
        else {
            Node<T> *temp = head;
            head = head -> next;
            delete temp;
            nodes--;
        }
    };
    void pop_back(){
        if (head == nullptr)
            cout << "ListError" << endl;
        else {
            Node<T> *temp = head;
            while (temp -> next != tail)
                temp = temp -> next;
            temp -> next = nullptr;
            delete tail;
            tail = temp;
            nodes--;
        }
    };
    T get(int position){
        if (position > size()-1 || position < 0)
            cout << "ListError" << endl;
        else{
            Node<T>* temp = head;
            for (int i = 0; i < position; i++)
                temp = temp -> next;
            return temp -> data;
        }
    };
    void concat(List<T> &other){
        tail -> next = other.head;
        tail = other.tail;
        nodes += other.nodes;
    };
    bool empty(){
        return head == nullptr;
    };
    int size(){
        return nodes;
    };
    void print(){
        Node<T>* temp = head;
        while (temp != nullptr){
            cout << temp -> data << endl;
            temp = temp -> next;
        }
    };
    void print_reverse(){
        for (int i = size() - 1; i >= 0; i--){
            cout << get(i) << endl;
        }
    };
    void clear(){
        head -> killSelf();
        head = tail = nullptr;
        nodes = 0;
    };
    Iterator<T> begin();
    Iterator<T> end();

    ~List(){
        head -> killSelf();
    };

};
#endif

