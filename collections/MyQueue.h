#pragma once
#include <conio.h>
#include <cstdlib>

using namespace std;

// Implementation of the queue based on linked list type (FIFO).
template<class T>
class MyQueue{
    class Node{
    public:
        T value;
        Node *next;
    };
    Node* begin, *end;
    int count;
public:
    // Default constructor
    MyQueue(){
        begin = nullptr;
        end = nullptr;
        count = 0;
    }

    // The copy constructor
    MyQueue(const MyQueue& sourceList): begin(nullptr),end(nullptr)
    {
        Node *tmp = sourceList.begin;
        while(tmp != nullptr){

            this->push(tmp->value);
            tmp = tmp->next;
        }
    }

    //Adding an element to the end of the list
    void push(T i){
        Node *tmp = new Node;
        tmp->value = i;
        tmp->next = nullptr;
        if(begin==nullptr){
            begin = end = tmp;
        }
        else{
            end->next=tmp;
            end = tmp;
        }
        count++;
    }

    // Display queue
    void show(){
        Node *temp = begin;
        while(temp != nullptr){
            cout<<temp -> value<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }

    // Removing an item from the queue
    void pop(){
        if(empty()){
            cout<<"Empty List!!!"<<endl;
            exit(EXIT_FAILURE);
        }
        else{
            Node *temp = begin->next;
            if((begin != nullptr)&&(temp != nullptr)){
                delete begin;
                begin = temp;
                count--;
            }
            else if((begin != nullptr)&&(temp == nullptr)){
                delete begin;
                count = 0;
            }
        }
    }

    // Первый елемент очереди
    T front(){
        return begin->value;
    }

    // Последний елемент очереди
    T back(){
        return end->value;
    }

    // Количество ел. очереди.
    int size(){
        return count;
    }

    // Является ли очередь пустой.
    bool empty() {
        return (size() == 0);
    }

    //Очистка очереди.
    void clear() {
        while(!empty())
            pop();
    }
    // Деструктор
    ~MyQueue(){
        while(begin != nullptr){
            Node *temp = begin->next;
            delete begin;
            begin = temp;
        }
    }



};

