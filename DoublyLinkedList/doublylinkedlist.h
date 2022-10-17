#pragma once
#include <bits/stdc++.h>

class Node {
	public:
	int data;
	Node* prev;
	Node* next;

	Node(int data) {
		this->data = data;
		prev = NULL;
		next = NULL;
	}
};

void append(Node* &head, int data);
void prepend(Node* &head, int data);
int length(Node* &head);
void display(Node* &head);
void prependK(Node* &head, int k);