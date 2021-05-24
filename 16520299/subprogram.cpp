#include <bits/stdc++.h>
#include <iostream>
#include "subprogram.hpp"

void log(const char* message) {
    std::cout << message << std::endl;
}

void konsDot(Node** head_ref, int new_data) {
	Node* new_node = new Node();
	new_node->data = new_data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
    log("Node berhasil ditambahkan");
    return;
}

void konso(Node** head_ref, int new_data) {
	Node* new_node = new Node();
	Node *last = *head_ref;

	new_node->data = new_data;
	new_node->next = NULL;

	if (*head_ref == NULL) {
		*head_ref = new_node;
        log("Node berhasil ditambahkan");
		return;
	}
	while (last->next != NULL)
		last = last->next;

	last->next = new_node;
    log("Node berhasil ditambahkan");
	return;
}

void insert(Node** head_ref, int new_data, int pos) {
    Node* walk = *head_ref;
    Node* prev = NULL;

	Node* new_node = new Node();
    new_node->data = new_data;

    if (pos == 1){
        new_node->next = (*head_ref);
        (*head_ref) = new_node;
        log("Node berhasil ditambahkan");
        return;
    } else {
        while (walk != NULL && pos != 1){
            prev = walk;
            walk = walk->next;
            pos--;
        }
        if (pos == 1){
            prev->next = new_node;
            new_node->next = walk;  
            log("Node berhasil ditambahkan");
            return;  
        }
        else {
            log("Posisi invalid");
            return;
        }
    }
}

void nodeDelete(Node** head_ref, int key) {
    Node* walk = *head_ref;
    Node* prev = NULL;

    if (walk == NULL){
        log("Linked list kosong");
        return;
    }

    if (walk != NULL && walk->data == key) {
        *head_ref = walk->next;
        delete walk;
        log("Node berhasil dihapus");
        return;
    }
    else {
        while (walk != NULL && walk->data != key) {
            prev = walk;
            walk = walk->next;
        }
        if (walk == NULL){
            log("Nilai tidak ditemukan");
            return;
        }
        prev->next = walk->next;
    
        delete walk;
        log("Node berhasil dihapus");
    }
}

void posDelete(Node** head_ref, int pos) {
    Node* walk = *head_ref;
    Node* prev = NULL;

    if (walk == NULL){
        log("Linked list kosong");
        return;
    }

    if (walk != NULL && pos == 1){
        (*head_ref) = walk->next;
        delete walk;
        log("Node berhasil dihapus");
        return;
    } else {
        while (walk != NULL && pos != 1){
            prev = walk;
            walk = walk->next;
            pos--;
        }
        if (walk == NULL){
            log("Posisi invalid");
            return;
        } else {
            if (pos == 1){
                prev->next = walk->next;
                log("Node berhasil dihapus");
                delete walk; 
            }
            else {
                log("Posisi invalid");
            }
        }
    }
}

void deleteHead(Node** head_ref){
    Node* walk = *head_ref;
    if (walk == NULL){
        log("Linked list kosong");
        return;
    }
    (*head_ref) = walk->next;
    delete walk;
    log("Node berhasil dihapus");
    return;
}

void deleteLastNode(Node** head_ref) {
    if (*head_ref == NULL){
        log("Linked list kosong");
        return;
    }
    while (*head_ref && (*head_ref)->next)
        head_ref = &(*head_ref)->next;
    free(*head_ref);
    *head_ref = NULL;
    log("Node berhasil dihapus");
}

void deleteLL(Node** head_ref) {
    Node* walk = *head_ref;
    Node* next = NULL;
 
    while (walk != NULL) {
        next = walk->next;
        delete walk;
        walk = next;
    }
    *head_ref = NULL;
    log("Semua node berhasil dihapus");
}

void lengthLL(Node* head){
    int count = 0;
    Node* walk = head;
    while (walk != NULL) {
        count++;
        walk = walk->next;
    }
    std::cout<<"Panjang linked list: "<<count<<std::endl;
}

void reverse(Node** head_ref) {
    Node* current = *head_ref;
    Node *prev = NULL, *next = NULL;

    if (current == NULL){
        log("Linked list kosong");
        return;
    }

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head_ref = prev;
    return;
}

void maxLL(Node** head_ref) {
    Node* walk = *head_ref;
    if (walk == NULL){
        log("Linked list kosong");
        return;
    }
    int max = walk->data;
    while (walk != NULL){
        if (max < walk->data){
            max = walk->data;
        }
        walk = walk->next;
    }
    std::cout<<"Nilai maksimum dari linked list: "<< max << std::endl;
}

void minLL(Node** head_ref) {
    Node* walk = *head_ref;

    if (walk == NULL){
        log("Linked list kosong");
        return;
    }
    int min = walk->data;
    while (walk != NULL){
        if (min > walk->data){
            min = walk->data;
        }
        walk = walk->next;
    }
    std::cout<<"Nilai minimum dari linked list: "<< min << std::endl;
}

void isEmpty(Node** head_ref){
    if (*head_ref == NULL){
        log("Linked list kosong");
    }else{
        log("Linked list tidak kosong");
    }
}

void checkValue(Node** head_ref, int key){
    Node* walk = *head_ref;

    if (walk == NULL){
        log("Linked list kosong");
        return;
    }
    std::cout<<"Nilai "<< key << " ditemukan pada posisi: "<<std::endl;
    int pos = 1;
    bool found = false;
    while (walk != NULL){
        if (walk->data == key){
            std::cout<<pos<<" ";
            found = true;
        }
        walk = walk->next;
        pos++;
    }
    if (found==false){
        log("Tidak ditemukan");
    } else {
        log("");
    }
}

Node* copyLL(Node** head_ref){
    Node* walk = *head_ref;
    Node* copy = NULL;

    while (walk != NULL){
        konso(&copy,walk->data);
        walk = walk->next;
    }
    return copy;
}

void concatLL(Node* head, Node* tail){
    if (head->next == NULL){
        head->next = tail;
    } else {
        concatLL(head->next,tail);
    }
}

void printList(Node *node) {
    if (node == NULL) {
        log("Linked list kosong");
    } else {
        log("Linked list: ");
        while (node != NULL) {
            std::cout<<node->data<<"->";
            node = node->next;
        }
        log("NULL");
    }
}