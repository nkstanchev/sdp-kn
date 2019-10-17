#include <iostream>

struct Node
{
	int value;
	Node* next;
};

class LinkedList
{
	Node* head;
	Node* tail;
	size_t size;
	void copy(LinkedList& other) {
		Node * prev = nullptr;
		Node* first;
		if (other.head == nullptr) return; // if empty copy nothing
		// Copy first elem
		first = new Node();
		first->value = other.head->value;
		this->head = first;
		prev = first;
		Node * tempOther = other.head->next;
		Node * curr = nullptr;
		// will not enter in while if only 1 elem
		// tempOther will accept the value of each node from other list
		// curr is a temp node that is created with the value of tempOther
		// prev is reference to the previous node, before curr so we can link them
		while (tempOther != nullptr) {
			curr = new Node();
			curr->value = tempOther->value;
			prev->next = curr;
			prev  = curr;
			tempOther = tempOther->next;
		}
		this->tail = prev; // handle tail
		size = other.size; // handle size
	}

	void erase() {
		Node* temp = head;
		Node* temp2 = nullptr;
		while (temp != nullptr) {
			temp2 = temp->next;
			delete temp;
			temp = temp2;
		}
		head = tail = nullptr;
		size = 0;
	}


public:
	LinkedList() {
		head = tail = nullptr;
		size = 0;
	}
	LinkedList(LinkedList& other) {
		copy(other);
	}
	LinkedList& operator =(LinkedList other) {
		if(this != &other) {
			erase();
			copy(other);
		}
		return *this;
	}
	~LinkedList() {
		erase();
	}
	bool is_empty() {
		return size == 0;
	}
	void push_back(int value)
	{
		Node* new_node = new Node();
		new_node->value = value;
		if (tail != nullptr)
		{
			tail->next = new_node;
			tail = new_node;
			
		}
		else
		{
			head = tail = new_node;
		}
		size++;
	}

	void pop_back()
	{
		if (tail == nullptr) return;
		size--;
		Node* temp = head;
		if (head == tail)
		{
			delete head;
			head = tail = nullptr;
			return;
		}
		while (temp->next->next != nullptr)
		{
			temp = temp->next;
		}
		temp->next = nullptr;
		delete tail;
		tail = temp;
	}
	void pop_front() {
		if (head == nullptr && tail == nullptr) return;
		Node* temp = head->next;
		delete head;
		head = temp;
		if (size == 1) {
			tail = temp;
		}
		size--;

	}
};

class Stack
{
	LinkedList List;
public:
	void pop()
	{
		List.pop_back();
	}
	void push(int value)
	{
		List.push_back(value);
	}
	bool is_empty() {
		return List.is_empty();
	}
};

int main()
{
	LinkedList L;
	L.push_back(1);
	L.push_back(2);
	L.push_back(3);
	L.pop_back();
	L.pop_back();
	LinkedList L2(L);
	L.push_back(4);
	L2 = L;

	Stack s;
	s.push(1);
	s.push(2);
	s.push(3);

	s.pop();
	s.pop();
	return 0;
}
