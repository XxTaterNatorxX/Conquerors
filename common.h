#pragma once

#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

enum class faction {
    INFAMY,
    KINGDOM,
    EMPIRE,
    ADVENTURER,
    MONSTER,
    NEUTRAL
};
template<typename T>
class node
{
private:
    node* next;
    node* prev;
    T* data;

public:
    node() {
        next = nullptr;
        prev = nullptr;
        data = nullptr;
    }
    
    friend class list<T>;
    ~node();
    node* getNext(){
        return next;
    }
    node* getPrev(){
        return prev;
    }
    T* getData(){
        return data;
    }
};

template<typename T>
class list
{
private:
    node<T>* head;
    node<T>* tail;
    int length;
public:
    list() {
        head = nullptr;
        tail = nullptr;
        length = 0;
    }
    
    ~list() {
        clear();
    }

    void add(T item) {
        node<T>* newNode = new node<T>();
        newNode->data = new T(item);
        
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        length++;
    }

    void remove(T item) {
        node<T>* current = head;
        while (current != nullptr) {
            if (*(current->data) == item) {
                if (current->prev) {
                    current->prev->next = current->next;
                } else {
                    head = current->next;
                }
                
                if (current->next) {
                    current->next->prev = current->prev;
                } else {
                    tail = current->prev;
                }
                
                delete current->data;
                delete current;
                length--;
                return;
            }
            current = current->next;
        }
    }

    bool contains(T item) {
        node<T>* current = head;
        while (current != nullptr) {
            if (*(current->data) == item) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    int size() {
        return length;
    }

    T get(int index) {
        if (index >= length || index < 0) {
            throw std::out_of_range("Index out of bounds");
        }
        
        node<T>* current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        return *(current->data);
    }

    void set(int index, T item) {
        if (index >= length || index < 0) {
            throw std::out_of_range("Index out of bounds");
        }
        
        node<T>* current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        *(current->data) = item;
    }

    void clear() {
        node<T>* current = head;
        while (current != nullptr) {
            node<T>* next = current->next;
            delete current->data;
            delete current;
            current = next;
        }
        head = nullptr;
        tail = nullptr;
        length = 0;
    }

    void print() {
        node<T>* current = head;
        while (current != nullptr) {
            std::cout << *(current->data) << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};
