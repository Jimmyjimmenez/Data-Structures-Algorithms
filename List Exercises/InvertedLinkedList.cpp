#include <iostream>
#include <cassert>

class ListLinkedSingle {

private:

    struct Node {
        std::string value;
        Node* next;
    };

public:

    ListLinkedSingle(): head(nullptr) { }

    void push_back(const std::string &);

    void push_front(const std::string &value) {
        Node* newNode = new Node {value, head};
        head = newNode;
    }

    void pop_front() {
        assert(head != nullptr);
        Node* oldHead = head;
        head = head->next;
        delete oldHead;
    }

    void pop_back();

    std::string getFront() {
        assert(head != nullptr);
        return head->next->value;
    }

    std::string getBack() const { return lastNode()->value; }

    std::string at(const int &index);

    int getSize() const {
        int cont = 0;
        Node* current = head;

        while (current->next != nullptr) {
            current = current->next;
            cont++;
        }

        return cont;
    }

    bool isEmpty() const { return getSize() == 0; }

    void reverted();

    void print() const;

private:

    Node* head;

    Node* lastNode() const;
    Node* nth(const int&) const;

};

ListLinkedSingle::Node* ListLinkedSingle::lastNode() const {

    if (head != nullptr) {
        Node* current = head;

        while (current != nullptr) current = current->next;
        return current;
    }

    return nullptr;
}

ListLinkedSingle::Node* ListLinkedSingle::nth(const int &index) const {
    assert(index >= 0);
    int current_index = 0;
    Node* current = head;

    while (current != nullptr && current_index <= index) {
        current = current->next;
        current_index++;
    }

    return current;
}


void ListLinkedSingle::push_back(const std::string &imputValue) {
    Node* newNode = new Node { imputValue, nullptr };
    
    if (head == nullptr) head = newNode;
    else {
        Node* current = head;

        while (current->next != nullptr) current = current->next;
        current->next = newNode;
    }
}

void ListLinkedSingle::pop_back() {
    assert(head != nullptr);

    if (head->next == nullptr){
        delete head;
        head = nullptr;
    } 
    else {
        Node* current = head->next;
        Node* previous = head;

        while (current != nullptr) {
        current = current->next;
        previous = previous->next;
        }

        previous->next = nullptr;
        delete current;
    }    
}

std::string ListLinkedSingle::at(const int &index) { return nth(index)->value; }

void ListLinkedSingle::reverted() {
   Node* current = head;
   Node* previous = nullptr;

   while (current != nullptr) {
       Node* nextNode = current->next;
       current->next = previous;
       previous = current;
       current = nextNode;
   }

   head = previous;
}

void ListLinkedSingle::print() const {
    assert (head != nullptr);
    Node* current = head;
    
    std::cout << "[" ;
    while (current != nullptr) {
        std::cout << current->value << ", ";
        current = current->next;
    }
    std::cout << "]\n";
}

int main() {
    ListLinkedSingle l1;

    l1.push_back("1");
    l1.push_back("2");
    l1.push_back("3");
    l1.push_back("4");
    l1.print();
    l1.reverted();
    l1.print();
}