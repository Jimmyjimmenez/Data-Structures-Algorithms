#include <iostream>
#include <cassert>

class ListLinkedSingle {

public:

    ListLinkedSingle(): head(nullptr) { }

    void push_front(const std::string &);

    void push_back(const std::string &);

    void pop_front() {
         assert (head != nullptr);
         Node* oldHead = head;
         head = head->next;
         delete oldHead;
    }

    void pop_back();

    void duplicate();

    int getSize() const {
        Node* current = head;
        int cont = 0;

        while (current->next != nullptr) {
            current = current->next;
            cont++;
        }

        return cont;
    }

    bool isEmpty() const { return getSize() == 0; }

    std::string getFront() const {
        assert(head != nullptr);
        return head->next->value;
    }

    std::string getBack() const { return lastNode()->value; }

    std::string at(int index) const { return nth_node(index)->value; }

    void print() const;

private:

    struct Node {
        std::string value;
        Node* next;
    };

    Node* head;

    Node* lastNode() const;
    Node* nth_node(const int &) const;
};

ListLinkedSingle::Node* ListLinkedSingle::lastNode() const {
    assert(head != nullptr);
    Node* current = head;

    while (current->next != nullptr) current = current->next;
    return current;
}

ListLinkedSingle::Node* ListLinkedSingle::nth_node(const int &index) const {
    assert(0 <= index);
    int current_index = 0;
    Node* current = head;

    while (current_index <= index && current != nullptr) {
        current_index++;
        current = current->next;
    }

    return current;
}

void ListLinkedSingle::push_front(const std::string &value) {
    Node *newNode = new Node{value, head};
    head = newNode;
}

void ListLinkedSingle::push_back(const std::string &value) {
    Node* newNode = new Node{value, nullptr};

    if (head == nullptr) head = newNode;
    else {
        Node* current = head;

        while (current->next != nullptr) current = current->next;
        current->next = newNode;
    }
}

void ListLinkedSingle::pop_back() {
    assert(head != nullptr);

    if (head->next == nullptr) {
        delete head;
        head = nullptr;
    }
    else {
        Node* previous = head;
        Node* current = head->next;

        while (current->next != nullptr) {
            previous = current;
            current = current->next;
        }

        delete current;
        previous->next = nullptr;
    }
}

void ListLinkedSingle::duplicate() {
    Node* current = head;

    while(current != nullptr) {
        Node* newNode = new Node;
        newNode->value = current->value;
        newNode->next = current->next;
        current->next = newNode;

        current = newNode->next;
    }
}

void ListLinkedSingle::print() const {
    assert (head != nullptr);
    Node* current = head;

    std::cout << "[";
    while (current != nullptr) {
        std::cout << current->value << ",";
        current = current->next;
    }
    std::cout << "]\n";
}

int main() {

    ListLinkedSingle firstLinkedList;

    firstLinkedList.push_back("1");
    firstLinkedList.push_back("2");
    firstLinkedList.push_back("3");
    firstLinkedList.print();
    firstLinkedList.duplicate();
    firstLinkedList.print();
}