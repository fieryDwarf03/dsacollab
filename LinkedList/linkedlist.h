#pragma once
#include <bits/stdc++.h>

class Node {
	public:
	int data;
	Node* next;

	Node(int data) {
		this->data = data;
		next = NULL;
	}
};

void prepend(Node* &head, int val);
void append(Node* &head, int val);
void remove(Node* &head, int val);
Node* reverse(Node* &head);
Node* reverseK(Node* &head, int k);
int length(Node* &head);
void display(Node* &head);
int intersectValue(Node* &head1, Node* &head2);
Node* merge(Node* &h1, Node* &h2);