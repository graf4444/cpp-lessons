#include <iostream>
#include <stdexcept>

using namespace std;

class Node {
private:
    int data;
    Node* next;

public:
    Node(int data) {
        this->next = NULL;
        this->data = data;
    }

    int getData() {
        return data;
    }

    Node* getNext() {
        return this->next;
    }

    void setNext(Node* node) {
        this->next = node;
    }
};

class MyList {
private:
    Node* head;
    Node* tail;

public:
    MyList() {
        head = NULL;
        tail = NULL;
    }

    void insert(int data);
    void deleteNode(int pos);
    void print();
};

void MyList::insert(int data) {
    Node* newNode = new Node(data);

    if (head == NULL) {
        head = newNode;
        tail = head;
        return;
    }

    // (*tail).setNext(newNode);
    tail->setNext(newNode);
    tail = newNode;
}

void MyList::deleteNode(int pos) {
    if (head == NULL) {
        throw runtime_error("MyList is empty");
    }
    Node* cur = this->head;
    Node* prev = NULL;

    if (pos == 1) {
        head = this->head->getNext();
        delete cur;
        return;
    }

    int cnt = 1;
    while (cur != NULL && cnt++ < pos) {
        prev = cur;
        cur = cur->getNext();
    }

    if (cur != NULL) {
        prev->setNext(cur->getNext());
        if (cur->getNext() == NULL) {
            tail = prev;
        }
        delete cur;
    }
    else { 
        throw runtime_error("Index out of range!");
    }
}

void MyList::print() {
    Node* cur = this->head;

    if (cur == NULL) {
        cout << "MyList is empty" << endl;
        return;
    }

    while(cur != NULL) {
        cout << cur->getData();
        if (cur->getNext() != NULL) {
            cout << " -> ";
        }
        else {
            cout << endl;
        }
        cur = cur->getNext();
    }
}


int main() {
    MyList myList;
    myList.insert(1);
    myList.insert(2);
    myList.insert(3);
    myList.insert(4);
    myList.print();

    try {
        myList.deleteNode(10);
    }
    catch (const runtime_error& ex) {
        cout << ex.what() << endl;
    }
    myList.print();
    myList.insert(5);
    myList.print();

    return 0;
}