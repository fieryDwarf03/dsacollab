#include "circularlinkedlist.h"
using namespace std;

void append(Node* &head, int data) {
	Node* node = new Node(data);
	Node* t = head;
	if(t == NULL) {
		head = node;
		node->next = head;
		return;
	}
	while(t->next != head) {
		t = t->next;
	}
	t->next = node;
	node->next = head;
}

void prepend(Node* &head, int data) {
	Node* node = new Node(data);
	Node* t = head;
	if(t == NULL) {
		head = node;
		node->next = head;
		return;
	}
	while(t->next != head)
		t =  t->next;
	node->next = head;
	t->next = node;
	head = node;
}

void remove(Node* &head, int data) {
	Node* t = head, *prev = NULL;
	if(t->data == data) {
		while(t->next != head) t = t->next;
		t->next = head->next;
		t = head;
		head = head->next;
		delete t;
		return;
	}
	while(t->next != head) {
		if(t->data == data) break;
		prev = t;
		t = t->next;
	}
	if(t->data == data) {
		if(t->next == head) {
			prev->next = head;
		} else {
			prev->next = t->next;
		}
		delete t;
	}
}

void display(Node* &head) {
	Node* t = head;
	while(t != NULL && t->next != head) {
		cout << t->data << " ";
		t = t->next;
	}
	cout << t->data;
	cout << "..." << endl;
}