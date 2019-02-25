/*
 * Author: Jason Wong
 * Project: Stack and Queue
 * Purpose: To implement a stack and queue based on a linked list
 * Notes: 
 */
#include "List.h"
#include "Stack.h"
#include "Queue.h"
#include "linked_list_functions.h"
#include <iostream>
#include <vector>

using namespace std;

// linked list functions
void test_copy_nodes();
// linked list class
void test_list_push_pop();
void test_copy_list();
void test_list_copy_ctor();
void test_list_insert();
// stack
void test_stack();
// queue
void test_queue();


int main(int argc, char const* argv[]) {
    // loop these a bunch of times to check for crashes or memory leaks
    // vector<int*> stress_test;
    // for (int i = 0; i < 500; i++) {
    //     stress_test.push_back(new int[rand()]);
    //     test_copy_nodes();
    //     stress_test.push_back(new int[rand()]);
    //     test_list_push_pop();
    //     stress_test.push_back(new int[rand()]);
    //     test_copy_list();
    //     stress_test.push_back(new int[rand()]);
    //     test_list_copy_ctor();
    //     stress_test.push_back(new int[rand()]);
    //     test_stack();
    //     stress_test.push_back(new int[rand()]);
    //     test_list_insert();
    //     stress_test.push_back(new int[rand()]);
    //     test_queue();
    //     stress_test.push_back(new int[rand()]);
    // }
    // for (int i = 0; i < stress_test.size(); i++) {
    //     delete stress_test.at(i);


    // linked list functions
    test_copy_nodes();
    cout << endl;
    cout << endl;
    // linked list class
    test_list_push_pop();
    cout << endl;
    cout << endl;
    test_copy_list();
    cout << endl;
    cout << endl;
    test_list_copy_ctor();
    cout << endl;
    cout << endl;
    test_list_insert();
    cout << endl;
    cout << endl;
    // stack
    test_stack();
    cout << endl;
    cout << endl;
    // queue
    test_queue();
    cout << endl;
    system("pause");
    return 0;
}

void test_copy_nodes() {
    Node<int>* list;
    LinkedList::init_head(list);
    for (int i = 0; i < 20; i++) {
        LinkedList::insert_head(list, i);
    }
    LinkedList::print_list(list) << endl << endl;
    cout << "COPY THE LIST A BUNCH OF TIMES" << endl;
    for (int i = 0; i < 100; i++) {
        Node<int>* list_copy;
        LinkedList::init_head(list_copy);
        cout << LinkedList::copy_list(list, list_copy) << ": ";
        LinkedList::print_list(list_copy) << endl;
        LinkedList::delete_all(list_copy);
    }
}
void test_list_push_pop() {
    cout << "PUSH BACK" << endl;
    List<int> list;
    for (int i = 0; i < 10; i++) {
        list.push_back(i);
        cout << list << endl;
    }
    cout << "PUSH FRONT" << endl;
    for (int i = 0; i < 10; i++) {
        list.push_front(i);
        cout << list << endl;
    }

    cout << "POP FRONT" << endl;
    for (int i = 0; i < 10; i++) {
        list.pop_front();
        cout << list << endl;
    }

    cout << list << endl;
}

void test_copy_list() {
    const int lists_size = 10;
    List<int> lists[lists_size];

    for (int i = 0; i < lists_size; i++) {
        lists[0].push_back(i);
    }
    for (int i = 0; i < lists_size - 1; i++) {
        int* a = new int[rand()];
        lists[i + 1] = lists[0];
        delete a;
    }
    for (int i = 0; i < lists_size; i++) {
        cout << lists[i] << endl;
    }
    for (int i = 0; i < lists_size; i += 2) {
        lists[i].push_back(i);
    }

    cout << "verify things were actually copied" << endl;
    for (int i = 0; i < lists_size; i++) {
        cout << lists[i] << endl;
    }
}

void test_list_copy_ctor() {
    List<int> list0;
    for (int i = 0; i < 20; i++) {
        list0.push_back(i);
    }
    cout << list0 << endl;
    List<int> list2(list0);
    cout << list2 << endl;
}

void test_stack() {
    Stack<int> stack;
    cout << "TEST PUSH STACK" << endl;
    for (int i = 0; i < 10; i++) {
        stack.push(i);
        cout << stack << endl;
    }
    cout << "TEST POP STACK" << endl;
    for (int i = 0; i < 10; i++) {
        stack.pop();
        cout << stack << endl;
    }
}

void test_list_insert() {
    cout << "INSERT AT POSITION" << endl;
    List<int> list;
    list.push_front(5);
    list.push_front(5);
    list.push_front(5);
    list.push_front(5);
    cout << list << endl;
    list.insert(0, 6);
    list.insert(3, 7);
    list.insert(5, 6);
    cout << list << endl;
    cout << "INSERT AT ITERATOR" << endl;
    auto pos = list.find(7);
    list.insert_after(pos, 9);
    cout << list << endl;
}

void test_queue() {
    Queue<int> queue;
    cout << "QUEUE PUSH" << endl;
    for (int i = 0; i < 10; i++) {
        queue.push(i);
        cout << queue << endl;
    }
    cout << "QUEUE POP" << endl;
    for (int i = 0; i < 10; i++) {
        queue.pop();
        cout << queue << endl;
    }
}
