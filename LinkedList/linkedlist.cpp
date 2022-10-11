#include "linkedlist.h"
using namespace std;

void prepend(Node* &head, int val) {
	Node* node = new Node(val);
	if(head == NULL) {
		head = node;
		return;
	}
	node->next = head;
	head = node;
	return;
}

void append(Node* &head, int val) {
	Node* node = new Node(val);
	if(head == NULL) {
		head = node;
		return;
	}
	Node* t = head;
	while(t->next != NULL) {
		t = t->next;
	}
	t->next = node;
	return;
}

void remove(Node* &head, int val) {
	Node* t = head;
	if(head == NULL) return;
	if(t->data == val) {
		head = head->next;
		delete t;
		return;
	}
	while(t->next->data != val)
		t = t->next;
	Node* node = t->next;
	t->next = t->next->next;
	delete node;
}

Node* reverse(Node* &head) {
	// if(head == NULL || head->next == NULL)
	// 	return head;
	// Node* node = reverse(head->next), *t = node;
	// while(t->next != NULL) t = t->next;
	// head->next = NULL;
	// t->next = head;
	// return node;

	if(head == NULL || head->next == NULL)
		return head;
	Node *c = head, *p = NULL, *n = head->next;
	while(c != NULL) {
		c->next = p;
		p = c;
		c = n;
		if(n)
			n = n->next;
	}
	return p;
}

Node* reverseK(Node* &head, int k) {
	if(head == NULL || head->next == NULL)
		return head;
	Node* t = head; int i = 1;
	while(t != NULL && i <= k) {
		t = t->next;
		i++;
	}
	Node *p = reverseK(t, k), *n = head->next;
	t = head;
	for(i = 1; i <= k; i++) {
		t->next = p;
		if(i != k) {
			p = t;
			t = n;
			n = n? n->next: NULL;
		}
	}
	return t;
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
	Node* t = head;
	while(t != NULL) {
		cout << t->data << " ";
		t = t->next;
	}
	cout << endl;
	return;
}

int intersectValue(Node* &head1, Node* &head2) {
	int l1 = length(head1), l2 = length(head2), d = 0;
	Node *ptr1, *ptr2;
	if(l1 > l2) {
		d = l1-l2;
		ptr1 = head1;
		ptr2 = head2;
	} else {
		d = l2-l1;
		ptr1 = head2;
		ptr2 = head1;
	}
	while(d > 0) {
		ptr1 = ptr1->next;
		if(ptr1 == NULL) return -1;
		d--;
	}
	while(ptr1 != NULL && ptr2 != NULL) {
		if(ptr1 == ptr2)
			return ptr1->data;
		ptr1 = ptr1->next;
		ptr2 = ptr2->next;
	}
	return -1;
}

Node* merge(Node* &h1, Node* &h2) {
	// Node *head = NULL, *t1 = h1, *t2 = h2;
	// while(t1 != NULL && t2 != NULL) {
	// 	if(t1->data < t2->data) {
	// 		append(head, t1->data);
	// 		t1 = t1->next;
	// 	} else {
	// 		append(head, t2->data);
	// 		t2 = t2->next;
	// 	}
	// }
	// while(t1) {
	// 	append(head, t1->data);
	// 	t1 = t1->next;
	// }
	// while(t2) {
	// 	append(head, t2->data);
	// 	t2 = t2->next;
	// }
	// return head;

	Node* node = new Node(-1);
	Node *t1 = h1, *t2 = h2, *t3 = node;
	while(t1 != NULL && t2 != NULL) {
		if(t1->data < t2->data) {
			t3->next = t1;
			t1 = t1->next;
			t3 = t3->next;
		} else {
			t3->next = t2;
			t2 = t2->next;
			t3 = t3->next;
		}
	}
	while(t1) {
		t3->next = t1;
		t1 = t1->next;
		t3 = t3->next;
	}
	while(t2) {
		t3->next = t2;
		t2 = t2->next;
		t3 = t3->next;
	}
	return node->next;
}