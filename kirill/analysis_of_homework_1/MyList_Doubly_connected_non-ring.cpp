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
        Node* before;

    public:
        Node(int data)
        {
            this->data = data;
            next = NULL;
            before = NULL;
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

        Node* getBefore()
        {
            return this->before;
        }

        void setBefore(Node* before)
        {
            this->before = before;
        }
};

class MyList
{
    private:
        Node* head;
        // Node* last;
        Node* tail;
    
    public:
        MyList()
        {
            head = NULL;
            tail = NULL;
        }

        void insert(int data);
        void delet(int pos);
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
        tail = head;
        return;
    }
    // else
    // {
    tail->setNext(newNode);
    newNode->setBefore(tail);
    tail = newNode;
        // tail->setBefore(last);
        // last = tail;
        // return;
    // }
}

void MyList::delet(int pos)
{
    if (head == NULL)
    {
        throw runtime_error("MyList is empty! I can't delete anything!");
    }

    Node* cur = this->head;
    Node* prev = NULL;

    if (pos == 1)
    {
        head = this->head->getNext();
        head->setBefore(NULL);
        delete cur;
        return;
    }

    int cnt = 1;

    while (cur != NULL && cnt < pos)
    {
        prev = cur;
        cur = cur->getNext();
        cnt++;
    }


    if (cur != NULL)
    {
        // косяк
        //           cur -> NULL == cur->getNext()
        //  1 -> 2 -> 3
        cur->getNext()->setBefore(cur->getNext());
        // косяк prev может быть NULL, если pos == 1
        prev->setNext(cur->getNext());

        if (cur->getNext() == NULL)
        {
            tail = prev;
            delete cur;
        }
    }
    else
    {
        throw runtime_error("Index out of range!");
    }
}

void MyList::print()
{
    if (this->head == NULL)
    {
        cout << "MyList is empty! I can't print it!" << endl;
        return;
    }

    Node* cur = this->head;

    while (cur != NULL)
    {
        cout << cur->getData() << " ";
        cur = cur->getNext();
    }
    cout << endl;
}

int MyList::size()
{
    Node* cur = this->head;

    int cnt = 0;

    while (cur != NULL)
    {
        cnt++;
        cur = cur->getNext();
    }

    return cnt;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    MyList mylist;

    mylist.size();
    mylist.insert(1);
    mylist.insert(2);
    mylist.insert(3);
    mylist.insert(4);
    mylist.print();
    mylist.size();

    try
    {
        mylist.delet(2);
        mylist.delet(10);
    }

    catch(const runtime_error& ex)
    {
        cout << ex.what() << endl;
    }

    mylist.print();
    mylist.size();
    mylist.insert(5);
    mylist.insert(6);
    mylist.insert(7);
    mylist.print();
    mylist.size();
    
    return 0;
}