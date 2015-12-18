#include <iostream>
#include <conio.h>
#include "Mylist.h"
#include "MyVector.h"
#include "MySteck.h"
#include "MyQueue.h"
#include "mydual-linklist.h"
#include "algorithm"
using namespace std;


int main()
{
    cout<<"----------------------------------------------------------"<<endl;
    cout<<"*************************MyVector*************************"<<endl;
    MyVector<int> vector_one;
    for(int i=1;i<100;i++)
        vector_one.push_back(i);

    vector_one.pop_back();
    vector_one.pop_back();
    vector_one.pop_back();
    vector_one.pop_back();

    cout << "Capacity vector_one: " << vector_one.capacity()<< endl;
    cout << "Size vector_one: " << vector_one.size()<< endl;

    cout<<endl;
    for(int i=0;i<vector_one.size();i++)
        cout << " " << vector_one[i];

    cout << endl << endl;

    cout << "vector_two:" << endl;

    cout << "vector_two = vecrtor_one"<<endl;

    MyVector<int> vector_two=vector_one;

    cout << "Capacity vector_two: " << vector_one.capacity()<< endl;
    cout << "Size vector_two: " << vector_one.size()<< endl;

    cout<<endl;

    for(int i=0;i<vector_two.size();i++)
        cout << " " << vector_two[i];

    cout<<endl;
    cout<<endl;

    MyVector<int> vector_three(20,20);
    cout<<"vector_three(20,20)"<<endl;
    for(int i=0;i<vector_three.size();i++)
        cout << " " << vector_three[i];

    cout<<endl;
    cout<<endl;

    cout<<"vector_five = vector_three.subVector(0,4)"<<endl;
    MyVector<int> vector_five = vector_three.subVector(0,4);
    for(MyVector<int>::my_iterator i = vector_five.begin(); i != vector_five.end(); ++i){
        cout << *i << " ";
    }

    cout<<endl;
    cout<<endl;

    cout<<"vector_five.insert(3,55)"<<endl;
    vector_five.insert(3,55);
    for(MyVector<int>::my_iterator i = vector_five.begin(); i != vector_five.end(); ++i){
        cout << *i << " ";
    }

    cout<<endl;
    cout<<endl;
    cout<<"vector_five.remove(3)"<<endl;
    vector_five.remove(3);
    for(MyVector<int>::my_iterator i = vector_five.begin(); i != vector_five.end(); ++i){
        cout << *i << " ";
    }
    cout<<endl;
    cout<<endl;
    //copy(vector_two.begin(),vector_two.end(),std::ostream_iterator<int>(cout," "));
    cout<<"----------------------------------------------------------"<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"----------------------------------------------------------"<<endl;
    cout<<"****************************MyList**************************"<<endl;
    MyList<int> firstTry ;
    cout<<"MyList<int> firstTry"<<endl;

    firstTry.add_front(12);
    firstTry.add_front(10);
    firstTry.add_front(0);

    cout<<"List size : ";
    cout << firstTry.size() << std::endl;

    firstTry.show();

    cout<<endl;
    cout<<endl;

    firstTry.pop_front();
    firstTry.pop_front();
    firstTry.add_back(3);

    cout<<"MyList<int> firstTry"<<endl;
    cout<<"List size : ";
    cout << firstTry.size() << std::endl;
    firstTry.show();

    cout<<endl;
    cout<<endl;

    firstTry.insert(4,55);
    firstTry.insert(1,95);
    firstTry.insert(2,95);

    firstTry.show();

    firstTry.remove(2);
    firstTry.remove(3);

    cout<<endl;
    cout<<"MyList<int> firstTry"<<endl;
    cout<<"List size : ";
    cout<<firstTry.size()<<endl;
    firstTry.show();
    cout<<endl;

    firstTry.set(0,45);

    firstTry.show();

    cout<<"MyList<int> secondTry = firstTry"<<endl;
    cout<<"MyList<int> secondTry"<<endl;
    MyList<int> secondTry ;
    secondTry = firstTry;
    cout<<"List size : ";
    cout<<secondTry.size()<<endl;
    secondTry.show();

    if(firstTry == secondTry){
        cout<<"Good!!!"<<endl;
    }
    cout<<endl;
    int v = secondTry[2];
    cout<<v<<endl;
    cout<<endl;
    cout<<secondTry<<endl;


    cout<<"----------------------------------------------------------"<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"----------------------------------------------------------"<<endl;
    cout<<"*************************MyStack*****************************"<<endl;
    MyStack<int> stack;

    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);

    cout<<"Stack size: "<<stack.size()<<endl;
    stack.print();
    cout<<endl;
    cout<<"Stack pop()"<<endl;
    cout<<"Stack pop()"<<endl;
    stack.pop();
    stack.pop();
    cout<<"Stack size: "<<stack.size()<<endl;
    stack.print();
    cout<<"----------------------------------------------------------"<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"----------------------------------------------------------"<<endl;
    cout<<"*************************MyQueue*****************************"<<endl;
    MyQueue<int> firstQueue;
    firstQueue.push(1);
    firstQueue.push(2);
    firstQueue.push(3);
    firstQueue.push(4);
    firstQueue.push(5);
    cout<<"Queue size: "<<firstQueue.size()<<endl;
    firstQueue.show();
    cout<<"Queue.pop()"<<endl;
    cout<<"Queue.pop()"<<endl;
    firstQueue.pop();
    firstQueue.pop();
    cout<<"Queue size: "<<firstQueue.size()<<endl;
    firstQueue.show();
    cout<<"Queue front element: "<<firstQueue.front()<<endl;
    cout<<"Queue back element: "<<firstQueue.back()<<endl;
    cout<<endl;
    cout<<"Queue copy first queue: "<<endl;
    MyQueue<int> secondQueue(firstQueue);
    secondQueue.show();
    cout<<"----------------------------------------------------------"<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"----------------------------------------------------------"<<endl;   
    cout<<"*************************MyDualLinkList*****************************"<<endl;
    MyDualLinkList<int> DualLinkList;
    cout<<"push_front()-1,2,3"<<endl;
    DualLinkList.push_front(1);
    DualLinkList.push_front(2);
    DualLinkList.push_front(3);
    cout<<"List size :"<<DualLinkList.size()<<endl;
    DualLinkList.show();
    cout<<endl;
    cout<<"pop-front()"<<endl;
    DualLinkList.pop_front();
    DualLinkList.show();
    cout<<endl;
    cout<<"push.back(4)"<<endl;
    DualLinkList.push_back(4);
    DualLinkList.show();
    cout<<endl;
    cout<<"pop_back()"<<endl;
    cout<<"pop_back()"<<endl;
    DualLinkList.pop_back();
    DualLinkList.pop_back();
    DualLinkList.show();
    cout<<endl;
    cout<<"push_front(1)"<<endl;
    cout<<"push_front(2)"<<endl;
    DualLinkList.push_front(1);
    DualLinkList.push_front(2);
    DualLinkList.show();   
    cout<<"Inserting an element [2]=88 in a list "<<endl;
    DualLinkList.insert(2,88);
    DualLinkList.show();
    cout<<endl;
    cout<<"Removing an item [2] from the list "<<endl;
    DualLinkList.erase(2);
    DualLinkList.show();
    MyDualLinkList<int> DualLinkList_two = DualLinkList;
    DualLinkList_two.show();
    DualLinkList_two.push_front(56);
    DualLinkList_two.push_front(6);
    DualLinkList_two.push_front(5);
    DualLinkList_two.sort();
    DualLinkList_two.show();



    return 0;
}
