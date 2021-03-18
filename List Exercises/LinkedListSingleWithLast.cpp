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

    ~ListLinkedSingle() { delete_list(head); }

    void push_front(const std::string &value) {
        Node* newHead = new Node { value, nullptr};
        head = newHead;
        num_elems++;
    }

    void push_back(const std::string &);

    void pop_front() {
        assert(head != nullptr);
        Node* oldHead = head;
        head = oldHead->next;
        delete oldHead;
    }

    void pop_back();

    int getSize() const {
        Node* current = head;
        int cont = 0;

        while (current != nullptr) {
            current = current->next;
            cont++;
        }

        return cont;
    }

    bool isEmpty() const { return getSize() == 0; }

    const std::string &getFront() const {
        assert(num_elems > 0);
        return head->value;
    }

    std::string &getFront() {
        assert(num_elems > 0);
        return head->value;
    }

    const std::string &getBack() const {
        assert(num_elems > 0);
        return last->value;
    }

    std::string &getBack() {
        assert(num_elems > 0);
        return last->value;
    }

    const std::string &operator[](int index) const {
        assert (0 <= index && index < num_elems);
        Node* resultNode = nth_node(index);
        return resultNode->value;
    }

    std::string &operator[](int index) {
        assert(0 <= index && index < num_elems);
        Node* resultNode = nth_node(index);
        return resultNode->value;
    }
    
    void display() const { display(std::cout); }
    void display(std::ostream&) const;

private:

    Node* head;
    Node* last;
    int num_elems;

    Node* lastNode() const { return last; }
    Node* nth_node(const int &) const;
    void delete_list(Node*);
};

ListLinkedSingle::Node* ListLinkedSingle::lastNode() const {
    assert (head != nullptr);
    Node* current = head;

    while (current != nullptr) current = current->next;

    return current;
}

ListLinkedSingle::Node* ListLinkedSingle::nth_node(const int& index) const {
    assert(head != nullptr && 0 <= index && index < getSize());
    Node* current = head;
    int current_index = 0;

    while (current_index != index) {
        current = current->next;
        current_index++;
    }

    return current;
}

void ListLinkedSingle::delete_list(Node* startNode) {
    if (startNode != nullptr) {
        delete_list(startNode->next);
        delete startNode;
    }
}

void ListLinkedSingle::push_back(const std::string &index) {
    Node* newNode = new Node { index, nullptr };

    if (head != nullptr) head = newNode;
    else {
        Node* current = head;

        while (current != nullptr) current = current->next;
        current->next = newNode;
    }
    num_elems++;
}

void ListLinkedSingle::pop_back() {
    assert (head != nullptr);

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
        current->next = previous;
    }
}

void ListLinkedSingle::display() const {
    Node* current = head;
    
    std::cout << "[";
    while (current != head) {
        std::cout << current->value << ",";
        current = current->next;
    }
    std::cout << "]";
}