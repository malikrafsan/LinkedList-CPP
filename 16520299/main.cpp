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

void printList(Node *node) {
    if (node == NULL) {
        log("Linked list kosong");
    } else {
        log("Linked list: ");
        while (node != NULL) {
            std::cout<<" "<<node->data;
            node = node->next;
        }
    }
}

int main(){
	Node* head = NULL;
    int choice;
    int data;
    int pos;

    do {
        log("===================================");
        log("Main Menu");
        log("1. Mencetak linked list");
        log("2. Menambah node");
        log("3. Menghapus node");
        log("4. Mencetak panjang linked list");
        log("5. Membalik (inverse) linked list");
        log("6. Mencari nilai maksimum");
        log("7. Mencari nilai minimum");
        log("8. Pengecekan terhadap linked list");
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
                log("> Menu tambah node <");
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
                log("> Menu hapus node <");
                log("1. Menghapus node pertama yang bernilai tertentu");
                log("2. Menghapus node di posisi tertentu");
                log("3. Menghapus node pertama");
                log("4. Menghapus node terakhir");
                log("5. Menghapus semua node linked list");

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
                    case 3:
                        log("");
                        deleteHead(&head);
                        break;
                    case 4:
                        log("");
                        deleteLastNode(&head);
                        break;
                    case 5:
                        log("");
                        deleteLL(&head);
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
            case 6:
                log("");
                maxLL(&head);
                break;
            case 7:
                log("");
                minLL(&head);
                break;
            case 8:
                log("");
                log("> Menu Pengecekan <");
                log("1. Mengecek apakah linked list kosong");
                //log("2. ")
                //log("3. ")
                std::cout << "Masukkan pilihan: ";
                std::cin >> choice;

                switch(choice) {
                    case 1:
                        log("");
                        isEmpty(&head);
                        break;
                    default:
                        log("");
                        log("Masukan salah");
                        break;
                }
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