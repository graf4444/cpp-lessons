// #include <bits/stdc++.h>
#include <iostream>
#include <stdexcept>

using namespace std;

#define endl '\n'

class Node
{
    private:
        int data;
        Node* next;

    public:
        Node(int data)
        {
            this->data = data;
            next = NULL;
        }

        int getData()
        {
            return data;
        }

        Node* getNext()
        {
            return this->next;
        }

        void setNext(Node* next)
        {
            this->next = next;
        }
};

class MyList
{
    private:
        Node* head;
        Node* tail;
        // Node* last;
    
    public:
        MyList()
        {
            head = NULL;
            tail = NULL;
            // last = NULL;
        }

        void insert(int data);
        void deleteNode(int pos);
        void print();
        int size();
        // void circle();
};

void MyList::insert(int data)
{
    Node* newNode = new Node(data);

    if (head == NULL)
    {  
        head = newNode;
        // last = head;
        // tail = last;
        tail = head;
        tail->setNext(head);
        return;
    }

    // else
    // {
    tail->setNext(newNode);
    // tail->setNext(head);
    // last = newNode;
    // tail = last;
    tail = newNode;
    tail->setNext(head);
    // return;
    // }
}

void MyList::deleteNode(int pos)
{
    if (head == NULL)
    {
        throw runtime_error("MyList is empty! I can't delete anything!");
    }

    Node* cur = this->head;
    Node* prev = NULL;

//    // if (pos == 1)
//    // {
//    //     head = this->head->getNext();
//    //     tail->setNext(head);
//    //     delete cur;
//    //     return;
//    // }

    int cnt = 1;
// 1->2->3->4      // 100500 // 100500 % size()
    while (cnt < pos)
    {
        prev = cur;
        cur = cur->getNext();
        cnt++;
    }

    if (prev != NULL) { 
        prev->setNext(cur->getNext());
    }

    if (cur == head)
    {
        head = cur->getNext();
        tail = head;
        // delete cur;
        // + tail 
    }
    delete cur;
}

void MyList::print()
{
    if (this->head == NULL)
    {
        cout << "MyList is empty! I can't print it!" << endl;
        return;
    }

    Node* cur = this->head;

    // while (cur != last)
    while (cur != tail)
    {
        cout << cur->getData() << " ";
        cur = cur->getNext();
    }
    
    cout << cur->getData() << endl;
}

// void MyList::size()
int MyList::size()
{
    if (this->head == NULL) {
        return 0;
    }

    Node* cur = this->head;

    int cnt = 0;

    // while (cur != last)
    while (cur != tail)
    {
        cnt++;
        cur = cur->getNext();
    }
    cnt++;

    // if (last != NULL)
    // {
    //     cnt++;
    // }

    // cout << cnt << endl;
    return cnt;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    MyList mylist;

    cout << "mylist.size()1: " << mylist.size() << endl;
    cout << "list1: ";
    mylist.print();

    try
    {
        mylist.deleteNode(1);
    }
    catch(const runtime_error& ex)
    {
        cout << ex.what() << endl;
    }
    cout << "mylist.size()2: " << mylist.size() << endl;
    cout << "list2: ";
    mylist.print();

    mylist.insert(1);
    cout << "mylist.size()3: " << mylist.size() << endl;
    cout << "list3: ";
    mylist.print();

    try
    {
        mylist.deleteNode(1);
    }
    catch(const runtime_error& ex)
    {
        cout << ex.what() << endl;
    }
    cout << "mylist.size()4: " << mylist.size() << endl;
    cout << "list4: ";
    mylist.print();


    mylist.insert(1);
    cout << "mylist.size()5: " << mylist.size() << endl;
    cout << "list5: ";
    mylist.print();


    mylist.insert(1);
    cout << "mylist.size()6: " << mylist.size() << endl;
    cout << "list6: ";
    mylist.print();

    try
    {
        mylist.deleteNode(5);
    }
    catch(const runtime_error& ex)
    {
        cout << ex.what() << endl;
    }
    cout << "mylist.size()7: " << mylist.size() << endl;
    cout << "list7: ";
    mylist.print();

    mylist.insert(1);
    mylist.insert(2);
    mylist.insert(3);
    mylist.insert(4);
    mylist.insert(5);
    cout << "mylist.size()8: " << mylist.size() << endl;
    cout << "list8: ";
    mylist.print();

    try
    {
        mylist.deleteNode(3);
    }
    catch(const runtime_error& ex)
    {
        cout << ex.what() << endl;
    }
    cout << "mylist.size()9: " << mylist.size() << endl;
    cout << "list9: ";
    mylist.print();

    // cout << mylist.size() << endl;
    // mylist.insert(1);
    // mylist.insert(2);
    // mylist.insert(3);
    // mylist.insert(4);
    // mylist.print();
    // cout << mylist.size() << endl;

    // try
    // {
    //     mylist.deleteNode(5);
    //     mylist.deleteNode(11);
    // }
    // catch(const runtime_error& ex)
    // {
    //     cout << ex.what() << endl;
    // }

    // mylist.print();
    // cout << mylist.size() << endl;
    // mylist.insert(5);
    // mylist.insert(6);
    // mylist.insert(7);

    // // try
    // // {
    // //     mylist.delet(8);
    // //     mylist.delet(10);
    // // }

    // // catch(const runtime_error& ex)
    // // {
    // //     cout << ex.what() << endl;
    // // }
    
    // mylist.print();
    // cout << mylist.size() << endl;
    
    return 0;
}