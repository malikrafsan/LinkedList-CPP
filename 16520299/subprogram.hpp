#pragma once

void log(const char* message);

class Node {
	public:
	int data;
	Node *next;
};

void konsDot(Node** head_ref, int new_data);

void konso(Node** head_ref, int new_data);

void insert(Node** head_ref, int new_data, int pos);

void nodeDelete(Node** head_ref, int key);

void posDelete(Node** head_ref, int pos);

void deleteHead(Node** head_ref);

void deleteLastNode(Node** head_ref);

void deleteLL(Node** head_ref);

void lengthLL(Node* head);

void reverse(Node** head_ref);

void maxLL(Node** head_ref);

void minLL(Node** head_ref);

void isEmpty(Node** head_ref);

void checkValue(Node** head_ref, int key);

Node* copyLL(Node** head_ref);

void concatLL(Node* head, Node* tail);

void printList(Node *node);