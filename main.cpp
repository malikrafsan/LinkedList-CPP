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

void printList(Node *node) {
	while (node != NULL) {
		std::cout<<" "<<node->data;
		node = node->next;
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
                //log("2. Menambah node di belakang");
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
                        //fungsi append
                        log("konso");
                        break;
                    default:
                        log("Masukkan salah!");
                        break;
                }
                break;
            case 3:
                std::cout << "Masukkan nilai node yang akan dihapus: ";
                std::cin >> data;
                //fungsi delete
                log("delete");
                break;
            default:
                log("Masukkan salah");
                break;
            }
        }
        log("");
    } while(true);
}