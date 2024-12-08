#include <iostream>
#include <string>
using namespace std;

class ChainLink {
private:
    string color;
public:
    ChainLink(string color) {
        this->color = color;
    }
    string get_color() {
        return this->color;
    }
};

class Node {
public:
    ChainLink* data;
    Node* next;
    Node(ChainLink* data) {
        this->data = data;
        this->next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;
public:
    LinkedList() {
        this->head = nullptr;
    }
    void append(ChainLink* chainLink) {
        Node* newNode = new Node(chainLink);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    ChainLink* get(int index) {
        if (index < 0) {
            cout << "Index out of bounds." << endl;
            return nullptr;
        }
        Node* temp = head;
        int currentIndex = 0;
        while (temp != nullptr) {
            if (currentIndex == index) {
                return temp->data;
            }
            temp = temp->next;
            currentIndex++;
        }

        cout << "Index out of bounds." << endl;
        return nullptr;
    }
    ~LinkedList() {
        Node* temp;
        while (head != nullptr) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    LinkedList list;
    ChainLink* link_one = new ChainLink("red");
    ChainLink* link_two = new ChainLink("blue");
    ChainLink* link_three = new ChainLink("green");
    list.append(link_one);
    list.append(link_two);
    list.append(link_three);
    ChainLink* retrieved_link = list.get(1);
    if (retrieved_link) {
        cout << "Link at index 1: " << retrieved_link->get_color() << endl;
    }
    ChainLink* another_retrieved_link = list.get(2);
    if (another_retrieved_link) {
        cout << "Link at index 2: " << another_retrieved_link->get_color() << endl;
    }
    delete link_one;
    delete link_two;
    delete link_three;
    return 0;
}
