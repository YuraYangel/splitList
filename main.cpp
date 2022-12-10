#include <iostream>
#include <vector>
using namespace std;

struct Node{
    int data;
    Node *nextAddress;
};


class List{
private:
    Node *head;
    Node *tail;
public:
    List(){
        head = nullptr;
        tail = nullptr;
    }

    bool isEmpty(){
        return head == nullptr;
    }

    void addNode(int value){
        Node *newNode = new Node;
        newNode->data = value;
        newNode->nextAddress = nullptr;
        if (isEmpty()){
            head = newNode;
            tail = newNode;
            return;
        }
        tail->nextAddress = newNode;
        tail = newNode;
    }

    List split(int position){
        Node* currentNode = head;

        int count = 0;
        List secondList;
        while (count != position - 1){
            currentNode = currentNode->nextAddress;
            count ++;
        }
        Node* currentNodeCopy = currentNode->nextAddress;
        while(currentNodeCopy){
            secondList.addNode(currentNodeCopy->data);
            currentNodeCopy = currentNodeCopy->nextAddress;
        }
        currentNode->nextAddress = nullptr;
        return secondList;
    }

    void print(){
        Node *currentData = head;
        while(currentData){
            cout << currentData->data << ' ';
            currentData = currentData->nextAddress;
        }
    }
};

int main(){
    List list;
    for (int i = 0; i < 5; i ++){
        int x;
        cin >> x;
        list.addNode(x);
    }

    List secondPart = list.split(3);
    list.print();
    cout << endl;
    secondPart.print();
}
