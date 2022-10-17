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

void append(Node* &head, int data);
void prepend(Node* &head, int data);
void remove(Node* &head, int data);
void display(Node* &head);