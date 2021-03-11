#include <iostream>
#include <cassert>

class ListLinkedSingle {

private:
    struct Node {
        std::string value;
        Node* next;
    };

public:
    ListLinkedSingle() : head(nullptr) { }

    int getSize() const;

    bool isEmpty() const { return getSize() == 0; }

    void push_front(const std::string &value) {
        Node* newNode = new Node { value, nullptr };
        head = newNode;
    }

    void push_back(const std::string &);

    void pop_front() {
        assert (head != nullptr);
        Node* oldHead = head;
        head = head->next;
        delete oldHead;
    }

    void pop_back();

    std::string getFront() const { return head->next->value; }

    std::string at(const int &index) { return nth_node(index)->value; };

    std::string getBack() const { return lastNode()->value; }

    void merge(ListLinkedSingle &);

    void print() const;

private:
    Node* head;

    Node* lastNode() const;
    Node* nth_node(const int &);
};

ListLinkedSingle::Node* ListLinkedSingle::lastNode() const {
    assert (head != nullptr);
    Node* current = head;

    while (current->next != nullptr) current = current->next;
    return current;
}

ListLinkedSingle::Node* ListLinkedSingle::nth_node(const int &index) {
    assert (head != nullptr && 0 <= index && index < getSize());
    Node* current = head;
    int current_index = 0;

    while (current_index != index) {
        current = current->next;
        current_index++;
    }
    
    return current;
}

int ListLinkedSingle::getSize() const {
    Node* current = head;
    int cont = 0;

    while (current != nullptr) {
        current = current->next;
        cont++;
    }

    return cont;
}

void ListLinkedSingle::push_back(const std::string &value) {
    Node* newNode = new Node { value, nullptr };

    if (head == nullptr) head = newNode;
    else {
        Node* current = head;

        while (current->next != nullptr) current = current->next;
        current->next = newNode;
    }
}

void ListLinkedSingle::pop_back() {
    assert (head != nullptr);

    if (head->next == nullptr) pop_front();
    else {
        Node* previous = head;
        Node* current = previous->next;

        while (current != nullptr) {
            previous = previous->next;
            current = current->next;
        }
        delete current;
        previous->next = nullptr;
    }
}

void ListLinkedSingle::merge(ListLinkedSingle &other) {
    Node* current;
    Node* aux;

    if (other.head == nullptr) return;

    if (head == nullptr) {
        head = other.head;
        return;
    }
    
    if (head->value <= other.head->value) {
        current = this->head;
        aux = other.head;
    }
    else {
        current = other.head;
        aux = this->head;
        head = other.head;
    }

    while (current->next != nullptr) {
        if (current->next->value < aux->value) current = current->next;
        else {
            Node* old_next = current->next;

            current->next = aux;
            current = aux;
            aux = old_next;
        }
    }

    current->next = aux;
    other.head = nullptr;
}

void ListLinkedSingle::print() const {
    Node* current = head;

    std::cout << "[";
    while (current != nullptr) {
        std::cout << current->value << ", ";
        current = current->next;
    }

    std::cout << "]";
}

int main() {
    
}