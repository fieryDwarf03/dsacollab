#include "linkedlist.h"
using namespace std;

void makeCycle(Node* &head, int pos) {
	Node *t = head, *node;
	int i = 0;
	while(t->next != NULL) {
		if(i == pos) node = t;
		t = t->next;
		i++;
	}
	t->next = node;
}

bool hasCycle(Node* &head) {
	Node *slow = head, *fast = head;
	while(fast != NULL && fast->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;
		if(fast == slow) return true;
	}
	return false;
}

void removeCycle(Node* &head) {
	Node *slow = head, *fast = head;
	while(fast != NULL && fast->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;
		if(fast == slow) break;
	}
	fast = head;
	while(slow->next != fast->next) {
		slow = slow->next;
		fast = fast->next;
	}
	slow->next = NULL;
}

int main() {
	int n;
	cin >> n;
	Node* head = NULL;
	for(int i = 0; i < n; i++) {
		int x;
		cin >> x;
		append(head, x);
	}
	makeCycle(head, n/2);
	cout << hasCycle(head) << endl;
	removeCycle(head);
	cout << hasCycle(head) << endl;
	display(head);
	return 0;
}