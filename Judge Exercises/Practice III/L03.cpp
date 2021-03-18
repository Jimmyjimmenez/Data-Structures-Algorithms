/*
 * ---------------------------------------------------
 *                ESTRUCTURAS DE DATOS
 * ---------------------------------------------------
 */

 /*
  * MUY IMPORTANTE: Para realizar este ejercicio solo podéis
  * modificar el código contenido entre las etiquetas <answer>
  * y </answer>. Toda modificación fuera de esas etiquetas está
  * prohibida, pues no será corregida.
  *
  * Tampoco esta permitido modificar las líneas que contienen
  * las etiquetas <answer> y </answer>, obviamente :-)
  */

  //@ <answer>
  /*
   * Introduce el nombre y apellidos de los/as componentes del grupo:
   *
   * Estudiante 1: Roxanne Caiafa
   * Estudiante 2: Jaime Jiménez
   *
   */
   //@ </answer>

#include <iostream>
#include <cassert>
#include <fstream>


	class ListLinkedDouble {
	private:
		struct Node {
			int value;
			Node *next;
			Node *prev;
		};

	public:
		ListLinkedDouble() : num_elems(0) {
			head = new Node;
			head->next = head;
			head->prev = head;
		}

		ListLinkedDouble(const ListLinkedDouble &other) : ListLinkedDouble() {
			copy_nodes_from(other);
			num_elems = other.num_elems;
		}

		~ListLinkedDouble() { delete_nodes(); }

		void push_front(const int &elem) {
			Node *new_node = new Node{ elem, head->next, head };
			head->next->prev = new_node;
			head->next = new_node;
			num_elems++;
		}

		void push_back(const int &elem) {
			Node *new_node = new Node{ elem, head, head->prev };
			head->prev->next = new_node;
			head->prev = new_node;
			num_elems++;
		}

		void pop_front() {
			assert(num_elems > 0);
			Node *target = head->next;
			head->next = target->next;
			target->next->prev = head;
			delete target;
			num_elems--;
		}

		void pop_back() {
			assert(num_elems > 0);
			Node *target = head->prev;
			target->prev->next = head;
			head->prev = target->prev;
			delete target;
			num_elems--;
		}

		int size() const { return num_elems; }

		bool empty() const { return num_elems == 0; };

		const int &front() const {
			assert(num_elems > 0);
			return head->next->value;
		}

		int &front() {
			assert(num_elems > 0);
			return head->next->value;
		}

		const int &back() const {
			assert(num_elems > 0);
			return head->prev->value;
		}

		int &back() {
			assert(num_elems > 0);
			return head->prev->value;
		}

		const int &operator[](int index) const {
			assert(0 <= index && index < num_elems);
			Node *result_node = nth_node(index);
			return result_node->value;
		}

		int &operator[](int index) {
			assert(0 <= index && index < num_elems);
			Node *result_node = nth_node(index);
			return result_node->value;
		}

		ListLinkedDouble &operator=(const ListLinkedDouble &other) {
			if (this != &other) {
				delete_nodes();
				head = new Node;
				head->next = head->prev = head;
				copy_nodes_from(other);
				num_elems = other.num_elems;
			}
			return *this;
		}

		void partition(int pivot);

		void display(std::ostream &out) const;
		void display_reverse(std::ostream &out) const;

		void display() const { display(std::cout); }
		void display_reverse() const { display_reverse(std::cout); }

	private:
		Node *head;
		int num_elems;

		Node *nth_node(int n) const;
		void delete_nodes();
		void copy_nodes_from(const ListLinkedDouble &other);
		void detach(Node *node);
		void attach(Node *node, Node *position);
};

ListLinkedDouble::Node *ListLinkedDouble::nth_node(int n) const {
	int current_index = 0;
	Node *current = head->next;

	while (current_index < n && current != head) {
		current_index++;
		current = current->next;
	}

	return current;
}

void ListLinkedDouble::delete_nodes() {
	Node *current = head->next;
	while (current != head) {
		Node *target = current;
		current = current->next;
		delete target;
	}

	delete head;
}

void ListLinkedDouble::copy_nodes_from(const ListLinkedDouble &other) {
	Node *current_other = other.head->next;
	Node *last = head;

	while (current_other != other.head) {
		Node *new_node = new Node{ current_other->value, head, last };
		last->next = new_node;
		last = new_node;
		current_other = current_other->next;
	}
	head->prev = last;
}

void ListLinkedDouble::display(std::ostream &out) const {
	out << "[";
	if (head->next != head) {
		out << head->next->value;
		Node *current = head->next->next;
		while (current != head) {
			out << ", " << current->value;
			current = current->next;
		}
	}
	out << "]";
}

void ListLinkedDouble::display_reverse(std::ostream &out) const {
	out << "[";
	if (head->prev != head) {
		out << head->prev->value;
		Node *current = head->prev->prev;
		while (current != head) {
			out << ", " << current->value;
			current = current->prev;
		}
	}
	out << "]";
}

std::ostream &operator<<(std::ostream &out, const ListLinkedDouble &l) {
	l.display(out);
	return out;
}

// ----------------------------------------------------------------
//@ <answer>
/*
Coste de la función O(1)
*/
void ListLinkedDouble::detach(Node *node) {
	Node *auxprev = node->prev;
	auxprev->next = node->next;
	auxprev->next->prev = auxprev;
}
/*
Coste de la función O(1)
*/
void ListLinkedDouble::attach(Node *node, Node *position) {
	Node* previous = position->prev;
	previous->next = node;
	node->prev = previous;
	node->next = position;
	position->prev = node;
}
/*
Coste de la función O(n) siendo n el numero de elementos de la lista
*/
void ListLinkedDouble::partition(int pivot) {
	Node *current = head->next;
	Node *first = head;
	bool firstBigger = true;
	while (current != first && current!= head) { //Itera sobre la lista
		if (current->value > pivot) {
			if (firstBigger) {
				firstBigger = false;
				first = current;
			}
			Node* aux = current;
			current = current->next;
			detach(aux);
			attach(aux, head);
		}
		else {
			current = current->next;
		}
	}
}

using namespace std;

void tratar_caso() {
	// Implementar. Aquí se procesa cada caso de prueba
	int n = -1, pivot;
	ListLinkedDouble list;
	while (n != 0) {
		std::cin >> n;
		if (n != 0)list.push_back(n);
	}
	std::cin >> pivot;
	if (!list.empty()) {
		list.partition(pivot);
	}
	list.display();
	std::cout << '\n';
	list.display_reverse();
	std::cout << '\n';

}


//@ </answer>

// ¡No modificar nada debajo de esta línea!
// ----------------------------------------------------------------

int main() {
#ifndef DOMJUDGE
	std::ifstream in("sample.in");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	// Leemos el número de casos de prueba que vendrán a continuación
	int num_casos;
	cin >> num_casos;

	for (int i = 0; i < num_casos; i++) {
		tratar_caso();
	}

#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}