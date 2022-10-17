#include "doublylinkedlist.h"
using namespace std;

void append(Node* &head, int data) {
	Node *node = new Node(data), *t = head;
	if(t == NULL) {
		head = node;
		return;
	}
	while(t->next != NULL)
		t = t->next;
	t->next = node;
	node->prev = t;
}

void prepend(Node* &head, int data) {
	Node *node = new Node(data), *t = head;
	if(t == NULL) {
		head = node;
		return;
	}
	node->next = head;
	head->prev = node;
	head = node;
}

void prependK(Node* &head, int k) {
	if(head == NULL || head->next == NULL) return;
	Node *nhead = NULL, *nTail = NULL, *tail = head;
	int len = length(head), count = 1;
	while(tail->next != NULL) {
		if(count == len-k)
			nTail = tail;
		if(count == len-k+1)
			nhead = tail;
		tail = tail->next;
		count++;
	}
	nhead->prev = NULL;
	nTail->next = NULL;
	tail->next = head;
	head->prev = tail;
	head = nhead;
}

void remove(Node* &head, int k) {
	if(head == NULL) return;
	Node* t = head;
	if(head->data == k) {
		head = head->next;
		t = head->prev;
		head->prev = NULL;
		delete t;
		return;
	}
	while(t != NULL && t->data != k)
		t = t->next;
	t->prev->next = t->next;
	if(t->next)
		t->next->prev = t->prev;
	delete t;
}

int length(Node* &head) {
	Node* t = head;
	int count = 0;
	while(t != NULL) {
		t = t->next;
		count++;
	}
	return count;
}

void display(Node* &head) {
	Node *t = head;
	while(t != NULL) {
		cout << t->data << " ";
		t = t->next;
	}
	cout << endl;
}