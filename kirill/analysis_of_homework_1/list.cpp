// #include <bits/stdc++.h>
#include <iostream>
#include <stdexcept>

using namespace std;

// template <class T> class node
template <class T> class Node
{
    private:

        T val;
        Node<T>* next;
        Node<T>* prev;

    public:

        // constructor
        Node(T v)
        {
            this -> val = v;
            this -> prev = this -> next = NULL;
        }

        // get value
        T getVal()
        {
            return val;
        }
        // set value
        void setVal(T v)
        {
            this -> val = v;
        }


        // set prev/next
        void setPrev(Node<T>* it){
            this -> prev = it;
        }
        void setNext(Node<T>* it){
            this -> next = it;
        }


        // get prev/next
        Node <T>* getNext()
        {
            return this -> next;
        }
        Node <T>* getPrev()
        {
            return this -> prev;
        }
};

template <typename T> class MyList
{
    private:

        Node<T>* head;
        Node<T>* tail;
        unsigned size;

    public:


        // constuctor()
        MyList(){
            this -> head = this -> tail = NULL;
            this -> size = 0;
        }


        // // resize()
        // void changeSize(int t)
        // {
        //     this -> size += t;
        // }


        // push_back()
        void listPB(T value)
        {
            Node<T>* newNode = new Node<T>(value);
            if(this -> head == NULL)
            {
                this -> head = newNode;
                this -> tail = newNode;
            }
            else{
                tail->setNext(newNode);
                (*newNode).setPrev(this -> tail);
                this -> tail = newNode;
            }
            // changeSize(1);
            size++;
        }


        // size()
        unsigned getSize()
        {
            return this -> size;
        }


        // erase(num_of_element{1, ..., size()})
        void listErase(unsigned i)
        {
            if(i > size){
                cout << "out of range" << endl;
                return;
            }
            // если нужно удалить первый элемент
            if(i == 1)
            {
                // падает при 1 элементе
                Node<T>* curNode = this->head->getNext();
                this -> head = curNode->getNext();
                (*(this -> head)).setPrev(NULL);
                delete curNode;
                // changeSize(-1);
                size--;
                return;
            }
            // если нужно удалить последний элемент
            if(i == size)
            {
                Node<T>* curNode = this->head->getPrev();
                this->tail = curNode->getPrev();
                this->tail->setNext(NULL);
                delete curNode;
                // changeSize(-1);
                size--;
                return;
            }


            // общий случай
            Node <T>* it;
            // оптимизация и поиск
            if(i - 1 <= getSize() - i)
            {
                it = this -> head;
                while(--i)
                {
                    it = it->getNext();
                }
            } else {
                it = this -> tail;
                i = getSize() - i;
                while(i--)
                {
                    it = it->getPrev();
                }
            }
                // удаление
            Node<T>* prv = (*it).getPrev();
            Node<T>* nxt = (*it).getNext();
            (*prv).setNext(nxt);
            (*nxt).setPrev(prv);
            delete it;

            // changeSize(-1);
            size--;
        }

        // insert(value; place, where I want my element to be) # for e.g., I wanna add "1" at the 3rd place, so I should use "insert(1, 3)"; like (what? where?)
        void listInsert(T value, int place)
        {
            if(place >  getSize() + 1){
                cout << "out of range" << endl;
                return;
            }

            Node<T>* N = new Node<T> (value);

            if (size == 0) {
                listPB(value);
                return;
            }

            // если нужно добавить на первое место
            if(place == 1)
            {
                (*(this -> head)).setPrev(N);
                (*N).setNext(this -> head);
                this -> head = N;
                // changeSize(1);
                size++;
                return;
            }

            // если нужно добавить на последнее место, отсылаемся к PB

            if(place == getSize()+1)
            {
                listPB(value);
                return;
            }

            // общий случай
            Node <T>* it;
            // вынести в отельный метод
                // оптимизация и поиск
            if(place - 1 <= getSize() - place)
            {
                it = this -> head;
                while(--place)
                {
                    it = (*it).getNext();
                }
            }else{
                it = this -> tail;
                place = getSize() - place;
                while(place--)
                {
                    it = (*it).getPrev();
                }
            }
            
                // добавление
            (*N).setNext(it);
            (*N).setPrev((*it).getPrev());
            (*it).setPrev(N);
            it = (*N).getPrev();
            (*it).setNext(N);

            // changeSize(1);
            size++;
        }

        //print_list

        void printList()
        {
            int l = getSize();
            auto it = this -> head;
            while(l--)
            {
                cout << (*it).getVal() << ' ';
                it = (*it).getNext();
            }
            cout << endl;
        }

};
//1 2 3 5 + 7
int main()
{
    MyList<int> myList;
    cout << "list: ";
    myList.printList();
    cout << "myList.getSize(): " << myList.getSize() << endl;

    myList.listInsert(1, 1);
    cout << "list: ";
    myList.printList();
    cout << "myList.getSize(): " << myList.getSize() << endl;

    // myList.listErase(1);
    // cout << "list: ";
    // myList.printList();
    // cout << "myList.getSize(): " << myList.getSize() << endl;
    
    myList.listPB(1);
    cout << "list: ";
    myList.printList();
    cout << "myList.getSize(): " << myList.getSize() << endl;

    // myList.listErase(1);
    // cout << "list: ";
    // myList.printList();
    // cout << "myList.getSize(): " << myList.getSize() << endl;


    myList.listPB(1);
    myList.listPB(3);
    myList.listPB(4);
    myList.listPB(5);
    myList.listInsert(2, 4);
    
    cout << "list: ";
    myList.printList();
    cout << "myList.getSize(): " << myList.getSize() << endl;

    myList.listErase(1);
    cout << "list: ";
    myList.printList();
    cout << "myList.getSize(): " << myList.getSize() << endl;

}