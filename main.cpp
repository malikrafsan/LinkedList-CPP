#include <bits/stdc++.h>
#include <iostream>

void log(const char* message) {
    std::cout << message << std::endl;
}

class Node {
	public:
	int data;
	Node *next;
};

void konsDot(Node** head_ref, int new_data) {
	Node* new_node = new Node();
	new_node->data = new_data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}

void konso(Node** head_ref, int new_data) {
	Node* new_node = new Node();
	Node *last = *head_ref;

	new_node->data = new_data;
	new_node->next = NULL;

	if (*head_ref == NULL) {
		*head_ref = new_node;
		return;
	}

	while (last->next != NULL)
		last = last->next;

	last->next = new_node;
	return;
}

void nodeDelete(Node** head_ref, int key) {
    Node* walk = *head_ref;
    Node* prev = NULL;

    if (walk != NULL && walk->data == key) {
        *head_ref = walk->next;
        delete walk;
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
    }
}

void printList(Node *node) {
    if (node == NULL) {
        log("Linked list kosong");
    } else {
        while (node != NULL) {
            std::cout<<" "<<node->data;
            node = node->next;
        }
    }
    log("");
}

int main(){
	Node* head = NULL;
    int choice;
    int data;
    
    do {
        log("Menu");
        log("1. Mencetak linked list");
        log("2. Menambah node");
        log("3. Menghapus node");
        log("0. exit program");

        std::cout << "Masukkan pilihan: ";
        std::cin >> choice;
        if (choice == 0) {
            log("Exit the program");
            log("");
            break;
        } else {
            switch(choice) {
            case 1:
                printList(head);
                break;
            case 2:
                log("");
                log("Menu tambah node");
                log("1. Menambah node di depan");
                log("2. Menambah node di belakang");
                //log("3. Menambah node di posisi tertentu");

                std::cout << "Masukkan pilihan: ";
                std::cin >> choice;
                
                if (choice >= 1 && choice <= 2){
                    std::cout << "Masukkan data baru: ";
                    std::cin >> data;
                }
                switch(choice) {
                    case 1:
                        konsDot(&head,data);
                        break;
                    case 2:
                        konso(&head,data);
                        break;
                    default:
                        log("Masukkan salah!");
                        break;
                }
                break;
            case 3:
                std::cout << "Masukkan nilai node yang akan dihapus: ";
                std::cin >> data;
                
                nodeDelete(&head,data);
                break;
            default:
                log("Masukkan salah!");
                break;
            }
        }
        log("");
    } while(true);
}