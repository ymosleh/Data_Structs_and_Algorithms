#include <bits/stdc++.h>
#pragma once


template <class T>
class Node {
    public:
        T val;
        Node* next;

        Node(T v) : val{v}, next{nullptr}{}
};


template <class T>
class LinkedList {
    Node<T>* h;
    Node<T>* t;
    int length;

    public:
        LinkedList() : h{nullptr}, t{nullptr}, length{0} {}

        void addAtHead(T v) {
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

        void addAtTail(T v) {
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

        T get(int idx) {
            if (idx < 0 || idx >= length ) return -1;

            Node<T>* p = h;
            for(int i = 0; i < idx; ++i) p = p->next;
            return p->val;
        }

        void AddAtIndex(int idx, T v) {
            if ( idx < 0  || idx > length) return;

            if (length == 0) addAtHead(v);
            else if (idx == length) addAtTail(v);
            else {
                Node<T>* node = new Node<T>{v};
                Node<T>* p = h;
                for(int i = 0; i < idx-1; ++i) p = p->next;

                node->next = p->next;
                p->next = node;
                ++length;
            }
        }

        void deleteAtIndex(int idx) {
            if (idx < 0 || idx >= length) return;

            if (idx == 0) {
                Node<T>* tmp = h;
                h = h->next;
                delete tmp;

            } else {
                Node<T>* p = h;
                for(int i = 0; i < idx-1; ++i) p = p->next;

                if (idx == length) t = p;

                Node<T>* delNode = p->next;
                p->next = delNode->next;
                delete delNode;
            }
            --length;
        }

};
