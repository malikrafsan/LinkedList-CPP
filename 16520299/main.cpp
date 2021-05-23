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

void insert(Node** head_ref, int new_data, int pos) {
    Node* walk = *head_ref;
    Node* prev = NULL;

	Node* new_node = new Node();
    new_node->data = new_data;

    if (pos == 1){
        new_node->next = (*head_ref);
        (*head_ref) = new_node;
    } else {
        while (walk != NULL && pos != 1){
            prev = walk;
            walk = walk->next;
            pos--;
        }
        if (pos == 1){
            prev->next = new_node;
            new_node->next = walk;    
        }
        else {
            log("Posisi invalid");
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
                delete walk; 
            }
            else {
                log("Posisi invalid");
            }
        }
    }
}

void lengthLL(Node* head){
    int count = 0;
    Node* walk = head;
    while (walk != NULL) {
        count++;
        walk = walk->next;
    }
    std::cout<<count<<std::endl;
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
    int pos;

    do {
        log("Menu");
        log("1. Mencetak linked list");
        log("2. Menambah node");
        log("3. Menghapus node");
        log("4. Mencetak panjang linked list");
        log("5. Membalik (inverse) linked list");
        log("0. exit program");

        std::cout << "Masukkan pilihan: ";
        std::cin >> choice;
        if (choice == 0) {
            log("");
            log("Exit the program");
            log("");
            break;
        } else {
            switch(choice) {
            case 1:
                log("");
                printList(head);
                break;
            case 2:
                log("");
                log("Menu tambah node");
                log("1. Menambah node di depan");
                log("2. Menambah node di belakang");
                log("3. Menambah node di posisi tertentu");

                std::cout << "Masukkan pilihan: ";
                std::cin >> choice;
                
                if (choice >= 1 && choice <= 3){
                    std::cout << "Masukkan data baru: ";
                    std::cin >> data;
                }
                switch(choice) {
                    case 1:
                        log("");
                        konsDot(&head,data);
                        break;
                    case 2:
                        log("");
                        konso(&head,data);
                        break;
                    case 3:
                        std::cout<<"Masukkan posisi: ";
                        std::cin>>pos;
                        log("");
                        if (pos < 1){
                            log("Posisi invalid!");
                        } else {
                            insert(&head,data,pos);
                        }
                        break;
                    default:
                        log("");
                        log("Masukan salah!");
                        break;
                }
                break;
            case 3:
                log("");
                log("Menu hapus node");
                log("1. Menghapus node pertama yang bernilai tertentu");
                log("2. Menghapus node di posisi tertentu");

                std::cout << "Masukkan pilihan: ";
                std::cin >> choice;

                switch(choice) {
                    case 1:
                        std::cout << "Masukkan nilai node yang akan dihapus: ";
                        std::cin >> data;
                        log("");
                        nodeDelete(&head,data);
                        break;
                    case 2:
                        std::cout << "Masukkan posisi node yang akan dihapus: ";
                        std::cin >> pos;
                        log("");
                        posDelete(&head,pos);
                        break;
                    default:
                        log("");
                        log("Masukan salah!");
                }
                break;
            case 4:
                log("");
                lengthLL(head);
                break;
            case 5:
                log("");
                reverse(&head);
                printList(head);
                break;
            default:
                log("");
                log("Masukkan salah!");
                break;
            }
        }
        log("");
    } while(true);
}