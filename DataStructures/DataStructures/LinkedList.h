#pragma once
using namespace std;
#include <iostream>
class LinkedList
{
    private: 
        struct node {
            int value;
            struct node* next;
            struct node* before;
        };
        node* head;

    public:
        LinkedList() {
            head = nullptr;
        }
        void addAfter(int id, int valorAInserir) {
            node* tmp = head;
            node* valueToInsert = new node;
            valueToInsert->value = valorAInserir;
            while (tmp != nullptr) {
                if (tmp->value == id) {
                    if (tmp->next == nullptr) {
                        tmp->next = valueToInsert;
                        valueToInsert->before = tmp;
                        valueToInsert->next = nullptr;
                    }
                    else {
                        tmp->next->before = valueToInsert;
                        valueToInsert->next = tmp->next;
                        tmp->next = valueToInsert;
                        valueToInsert->before = tmp;
                    }
                    break;
                }
                tmp = tmp->next;
            }
        }
        void remove(int value) {
            node* tmp = head;
            while (tmp != nullptr) {
                if (tmp->value == value) {
                    if (tmp->before != nullptr) {
                        tmp->before->next = tmp->next;
                    }
                    else {
                        head = tmp->next;
                    }
                    if (tmp->next != nullptr) {
                        tmp->next->before = tmp->before;
                    }
                    delete(tmp);
                    break;
                }
                tmp = tmp->next;    
            }
        }
        void addOrdened(int value) {
            node* tmp = head;
            node* valueToInsert = new node;
            valueToInsert->next = nullptr;
            valueToInsert->before = nullptr;
            valueToInsert->value = value;
            if (head == nullptr) {
                head = valueToInsert;
                return;
            }
            if (head->value > valueToInsert->value) {
                valueToInsert->next = head;
                head->before = valueToInsert;
                head = valueToInsert;
                return;
            }
            while (tmp != nullptr) {
                if (tmp->value > value) {
                    if (tmp->before != nullptr) {
                        tmp->before->next = valueToInsert;
                        valueToInsert->before = tmp->before;
                    }
                    tmp->before = valueToInsert;
                    valueToInsert->next = tmp;
                    break;
                }
                if (tmp->next == nullptr) {
                    tmp->next = valueToInsert;
                    valueToInsert->before = tmp;
                    break;
                }
                tmp = tmp->next;
            }
        }
        void addAtStart(int value) {
            node* tmp = new node;
            tmp->value = value;
            tmp->next = head;
            if(head != nullptr)
            head->before = tmp;
            head = tmp;
            head->before = nullptr;
        }
        bool find(int value) {
            node* tmp = head;
            while (tmp != nullptr) {
                if (tmp->value == value) {
                    return true;
                }
                tmp = tmp->next;
            }
            return false;
        }
        void print() {
            node* temp = head;
            while (temp != nullptr) {
                cout << "Value: " << temp->value << "\n";
                temp = temp->next;
            }
        }

};

