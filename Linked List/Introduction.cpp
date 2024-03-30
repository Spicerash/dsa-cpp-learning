/*
Linked List Data Structure
A linked list is a fundamental data structure in computer science. It consists of nodes where each node contains data and a reference 
(link) to the next node in the sequence. This allows for dynamic memory allocation and efficient insertion and deletion operations 
compared to arrays.
*/
#include <iostream>
using namespace std;

class node {
    public:
    int data;
    node *next;

    node(int data) {
        this -> data = data;
        this -> next = nullptr;
    }
};

class LinkedList{
    private:
    node* head;

    public:
    LinkedList() {
        head = nullptr;
    }

    void printList() {
        node* link = head;
        while(link != nullptr) {
            cout << link -> data << " ";
            link = link -> next;
        }
        cout << endl;
    }

    void prepend(int data) {
        node *temp = new node(data);
        temp -> next = head;
        head = temp;
    }

    void append(int data) {
        if(head == nullptr) {
            head = new node(data);
            return;
        }
        node* temp = head;
        while(temp -> next != nullptr) {
            temp = temp -> next;
        }
        temp -> next = new node(data);
    }

    void insertAfterRef(node* prev, int data) {
        node* temp = new node(data);
        temp -> next = prev -> next;
        prev -> next = temp;
    }

    void insertAfter(int key, int data) {
        if(head == nullptr) {
            cout << "Empty link";
            return;
        }
        node *link = head;
        while(link -> data != key) {
            link = link -> next;
            if(link == nullptr) {
                cout << "Not found";
                return;
            }
        }
        insertAfterRef(link, data);
    }

    int size(){
        int count = 0;
        node* temp = head;
        while(temp != nullptr) {
            count++;
            temp = temp -> next;
        }
        return count;
    }

    void remove(int data) {
        // if no nodes
        if(head == nullptr) {
            cout << "Empty List" << endl;
            return;
        }
        // if first node is to be deleted
        if(head -> data = data) {
            node* release = head;
            head = head -> next;
            delete release;
            return;
        }

        // if node to be deleted is after first node
        node* temp = head;
        while(temp -> next -> data != data) {
            temp = temp -> next;
            if(temp -> next == NULL){ // if not found
                cout << "Not found" << endl;
                return;
            }  
        }
        node* release = temp -> next;
        temp -> next = release -> next;
        delete release; // releasing resources
    }

    node* reverseFrom(node* head) {
        if(head == nullptr || head -> next == nullptr) return head;
        node* rest = reverseFrom(head -> next);
        head -> next -> next = head;
        head = head -> next;
        head -> next -> next = nullptr;
        return rest;
    }
    
    void reverse() {
        head = reverseFrom(head);
    }
};

int main() {
    LinkedList ll;
    ll.prepend(10);
    ll.append(20);
    ll.insertAfter(10, 15);
    ll.reverse();
    ll.remove(20);
    ll.remove(15);
    ll.printList();
    cout << ll.size();
    
    return 0;
}