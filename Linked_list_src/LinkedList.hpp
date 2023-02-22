#include <bits/stdc++.h>
#pragma once

/* Linked List template class*/


template <class T>
class Node {
    public:
        T val;
        Node* next;
        Node(T v) : val{v}, next{nullptr}{}
};


template <class T>
class LinkedList {
    Node<T>* h;  // head
    Node<T>* t;  // tail
    int length;  

    public:
        LinkedList() : h{nullptr}, t{nullptr}, length{0} {} 

        LinkedList(T val) {
            Node<T>* newNode = new Node<T>{val};
            h = newNode;
            t = newNode;
            ++length;
        }

        ~LinkedList() { 
            Node<T>* p = h;
            while (h) {
                h = h->next;
                delete p;
                p = h;
                --length;
            }
            t = h;
        }

        bool isEmpty() { return (h == nullptr) ? true : false; }
        int getLength() { return length; }

        // Iterates through the list and prints the index and node value.
        // Time O(N)
        void printList() {
            Node<T>* tmp = h;
            int idx {0};
            while(tmp) {
                std::cout << "Index: " << idx++ << " Node value: " << tmp->val << std::endl;
                tmp = tmp->next;
            }
        }

        // Add new node to the head of the list.
        // Time O(1).
        void prepend(T v) {
            Node<T>* node = new Node<T>{v};
            if (length == 0) {
                h = node;
                t = node;

            } else {
                node->next = h;
                h = node;
            }
            ++length;
        }

        // Add new node at the tail of the list.
        // Time O(1).
        void append(T v) {
            Node<T>* node = new Node<T>{v};
            if (length == 0) {
                h = node;
                t = node;

            } else {
                t->next = node;
                t = node;
            }
            ++length;
        }
   
       Node<T>* head() { return h; }  // Get a pointer to the head of the list.
       
       Node<T>* tail() { return t; }  // Get a pointer to the end of the list.

       // Return a pointer tothe node at a valid index.
       // Time O(N)
       Node<T>* get(int idx) {
            if (idx < 0 || idx >= length ) return nullptr;

            Node<T>* p = h;
            for(int i = 0; i < idx; ++i) p = p->next;
            return p;
        }


        // Insert a new node at a given valid index in the list.
        // Time O(N)
        void insert(int idx, T v) {
            if ( idx < 0  || idx > length) return;
            if (length == 0) prepend(v);
            else if (idx == length) append(v);
            else {
                Node<T>* node = new Node<T>{v};
                Node<T>* p = h;
                for(int i = 0; i < idx-1; ++i) p = p->next;

                node->next = p->next;
                p->next = node;
                ++length;
            }
        }

        // Delete first node.
        // Time O(1)
        void deleteFront() {
            if (h) {
                Node<T>* p = h;
                h = h->next;
                delete p;          
                --length;
                if (length == 0) t = nullptr;       
            }
        }

        // Delete last node
        // Time O(1)
        void deleteTail() {
            if (t) {
                Node<T>* p = h;
                if ( p == t ) {
                    h = nullptr;
                    t = nullptr;

                } else {
                    while ( p->next != t ) p = p->next;
                    t = p;
                    p = p->next;
                    t->next = nullptr;
                }
                delete p;
                --length;
            }
        }

        // Delete the specified node at a given valid index.
        // Time O(N)
        void deleteNode(int idx) {
            if (idx < 0 || idx >= length) return;
            else if ( idx == 0 ) return deleteFront();
            else if ( idx == (length-1)) return deleteTail();

            Node<T>* prev = get(idx-1); 
            Node<T>* delNode = prev->next;
            prev->next = delNode->next;
            delete delNode;
            --length;
        }


};
