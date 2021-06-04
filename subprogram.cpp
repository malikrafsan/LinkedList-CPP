#include <iostream>
#include "subprogram.hpp"

void log(const char* message) {
    // I.S message terdefinisi
    // F.S message ditampilkan ke layar

    // ALGORITMA
    std::cout << message << std::endl;
}

void konsDot(Node** head_ref, int new_data) {
    // I.S. head_ref dan new_data terdefinisi
    // F.S. node baru ditambahkan didepan linked list

    // KAMUS
	Node* new_node = new Node(); // membuat node baru
	
    // ALGORITMA
    // Mendefinisikan properti node baru
    new_node->data = new_data;
	new_node->next = (*head_ref);

    // Memindahkan pointer head
	(*head_ref) = new_node;
    
    log("Node berhasil ditambahkan");
    return;
}

void konso(Node** head_ref, int new_data) {
    // I.S. head_ref dan new_data terdefinisi
    // F.S. node baru ditambahkan di belakang linked list

    // KAMUS
	Node* new_node = new Node();
	Node *last = *head_ref;

    // ALGORITMA
    // Mendefinisikan properti node baru
	new_node->data = new_data;
	new_node->next = nullptr;

    // Kasus linked list kosong
	if (*head_ref == nullptr) {
		*head_ref = new_node;
        log("Node berhasil ditambahkan");
		return;
	} // Mencari ekor dari linked list
	while (last->next != nullptr)
		last = last->next;

    // Menambahkan node baru di belakang
	last->next = new_node;
    log("Node berhasil ditambahkan");
	return;
}

void insert(Node** head_ref, int new_data, int pos) {
    // I.S. head_ref, new_data, dan pos terdefinisi
    // F.S. node baru ditambahkan di posisi tertentu
    
    // KAMUS
    Node* walk = *head_ref;
    Node* prev = nullptr;
	Node* new_node = new Node();
    
    // ALGORITMA
    // Mendefinisikan properti data dari node baru
    new_node->data = new_data;

    // Penanganan kasus penambahan di depan
    if (pos == 1){
        new_node->next = (*head_ref);
        (*head_ref) = new_node;
        log("Node berhasil ditambahkan");
        return;
    } else {
        // Mencari posisi yang diinginkan sambil mengecek apakah merupakan ekor dari linked list
        while (walk != nullptr && pos != 1){
            prev = walk;
            walk = walk->next;
            pos--;
        } // Kasus ditemukan posisi sesuai
        if (pos == 1){
            prev->next = new_node;
            new_node->next = walk;  
            log("Node berhasil ditambahkan");
            return;  
        } // Kasus ketika sudah mencapai ekor linked list tetapi belum ditemukan posisi sesuai
        else {
            log("Posisi invalid");
            return;
        }
    }
}

void nodeDelete(Node** head_ref, int key) {
    // I.S. head_ref dan key terdefinisi
    // F.S. dihapuskan node pertama dengan data = key

    // KAMUS
    Node* walk = *head_ref;
    Node* prev = nullptr;

    // ALGORITMA
    // Kasus linked list kosong
    if (walk == nullptr){
        log("Linked list kosong");
        return;
    }
    // Kasus data node pertama = key
    if (walk != nullptr && walk->data == key) {
        *head_ref = walk->next;
        delete walk;
        log("Node berhasil dihapus");
        return;
    }
    else {
        // Mencari node dengan data = key
        while (walk != nullptr && walk->data != key) {
            prev = walk;
            walk = walk->next;
        } // Kasus tidak ditemukan node dengan data = key
        if (walk == nullptr){
            log("Nilai tidak ditemukan");
            return;
        }
        // Kasus ditemukan node dengan data = key
        prev->next = walk->next;
        delete walk;

        log("Node berhasil dihapus");
    }
}

void posDelete(Node** head_ref, int pos) {
    // I.S. head_ref dan pos terdefinisi
    // F.S. dihapuskan node dengan posisi sesuai dari linked list

    // KAMUS
    Node* walk = *head_ref;
    Node* prev = nullptr;

    // ALGORITMA
    // Kasus linked list kosong
    if (walk == nullptr){
        log("Linked list kosong");
        return;
    }
    // Kasus posisi yang dihapus = posisi pertama
    if (walk != nullptr && pos == 1){
        (*head_ref) = walk->next;
        delete walk;
        log("Node berhasil dihapus");
        return;
    } else {
        // Mencari posisi yangs sesuai
        while (walk != nullptr && pos != 1){
            prev = walk;
            walk = walk->next;
            pos--;
        } // Kasus posisi lebih dari panjang linked list
        if (walk == nullptr){
            log("Posisi invalid");
            return;
        } else {
            // Kasus ditemukan posisi sesuai
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
    // I.S. head_ref terdefinisi
    // F.S. dihapuskan node pertama dari linked list

    // KAMUS
    Node* walk = *head_ref;
    
    // ALGORITMA
    // Kasus linked list kosong
    if (walk == nullptr){
        log("Linked list kosong");
        return;
    } // Menghapus node pertama
    (*head_ref) = walk->next;
    delete walk;

    log("Node berhasil dihapus");
    return;
}

void deleteLastNode(Node** head_ref) {
    // I.S. head_ref terdefinisi
    // F.S. dihapuskan node terakhir dari linked list

    // Kasus linked list kosong
    if (*head_ref == nullptr){
        log("Linked list kosong");
        return;
    } // Mencari ekor dari linked list
    while (*head_ref && (*head_ref)->next)
        head_ref = &(*head_ref)->next;
    
    // Menghapus node terakhir
    free(*head_ref);
    *head_ref = nullptr;

    log("Node berhasil dihapus");
}

void deleteLL(Node** head_ref) {
    // I.S. head_ref terdefinisi
    // F.S. semua node pada linked list dihapus

    // KAMUS
    Node* walk = *head_ref;
    Node* next = nullptr;
 
    // ALGORITMA
    // Kasus linked list kosong
    if (walk == nullptr){
        log("Linked list kosong");
        return;
    } 
    // Menghapus node sampai ditemukan ekor linked list
    while (walk != nullptr) {
        next = walk->next;
        delete walk;
        walk = next;
    }
    *head_ref = nullptr;

    log("Semua node berhasil dihapus");
}

void deleteDuplicates(Node *head_ref) {
    // I.S. head_ref terdefinisi
    // F.S. nilai pada linked list yang jumlahnya lebih dari 1 dihapus

    // KAMUS
    Node *traverse, *walk, *dump;
    traverse = head_ref;

    // ALGORITMA
    // Kasus linked list kosong
    if (traverse == nullptr) {
        log("Linked list kosong");
        return;
    }
    // Looping dari node pertama sampai node terakhir 
    while (traverse != nullptr && traverse->next != nullptr) {
        // Lakukan loop ke sisa linked list untuk mengecek tiap node apakah memiliki duplikat
        walk = traverse;
        while (walk->next != nullptr) {
            // Jika node selanjutnya merupakan duplikat maka hapus
            if (traverse->data == walk->next->data) {
                dump = walk->next;
                walk->next = walk->next->next;
                delete dump;
            } // Jika bukan duplikat maka lanjut
            else {
                walk = walk->next;
            }
        }
        traverse = traverse->next;
    }
    log("Node duplikat telah dihapus dari linked list");
}

void lengthLL(Node* head){
    // I.S. head terdefinisi
    // F.S. ditampilkan ke layar panjang linked list

    // KAMUS
    int count = 0;
    Node* walk = head;

    // ALGORITMA
    // Menghitung jumlah node 1 per 1 sampai ditemukan ekor
    while (walk != nullptr) {
        count++;
        walk = walk->next;
    }
    // Menampilkan hasil perhitungan ke layar
    std::cout<<"Panjang linked list: "<<count<<std::endl;
}

void reverse(Node** head_ref) {
    // I.S. head_ref terdefinisi
    // F.S. linked list dibalik urutannya

    // KAMUS
    Node* current = *head_ref;
    Node *prev = nullptr, *next = nullptr;

    // ALGORITMA
    // Kasus linked list kosong
    if (current == nullptr){
        log("Linked list kosong");
        return;
    }
    // Membalik arah pointer next sampai node terakhir
    while (current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head_ref = prev;
    return;
}

void maxLL(Node** head_ref) {
    // I.S. head_ref terdefinisi
    // F.S. ditampilkan ke layar, data tertinggi dari linked list

    // KAMUS
    Node* walk = *head_ref;
    
    // ALGORITMA
    // Kasus linked list kosong
    if (walk == nullptr){
        log("Linked list kosong");
        return;
    }
    // Mencari data tertinggi
    int max = walk->data;
    while (walk != nullptr){
        if (max < walk->data){
            max = walk->data;
        }
        walk = walk->next;
    }
    // Menampilkan hasil ke layar
    std::cout<<"Nilai maksimum dari linked list: "<< max << std::endl;
}

void minLL(Node** head_ref) {
    // I.S. head_ref terdefinisi
    // F.S. ditampilkan ke layar, data terendah dari linked list

    // KAMUS
    Node* walk = *head_ref;

    // ALGORITMA
    // Kasus linked list kosong
    if (walk == nullptr){
        log("Linked list kosong");
        return;
    }
    // Mencari data terendah
    int min = walk->data;
    while (walk != nullptr){
        if (min > walk->data){
            min = walk->data;
        }
        walk = walk->next;
    }
    // Menampilkan hasil ke layar
    std::cout<<"Nilai minimum dari linked list: "<< min << std::endl;
}

void isEmpty(Node** head_ref){
    // I.S. head_ref terdefinisi
    // F.S. ditampilkan ke layar apakah linked list kosong atau tidak

    // ALGORITMA
    // Cek head_ref
    if (*head_ref == nullptr){
        log("Linked list kosong");
    } else{
        log("Linked list tidak kosong");
    }
}

void checkValue(Node** head_ref, int key){
    // I.S. head_ref dan key terdefinisi
    // F.S. ditampilkan posisi node dan alamatnya dimana key tersimpan

    // KAMUS
    Node* walk = *head_ref;
    int pos = 1;
    bool found = false;

    // ALGORITMA
    // Kasus linked list kosong
    if (walk == nullptr){
        log("Linked list kosong");
        return;
    }
    std::cout<<"Nilai "<< key << " ditemukan pada posisi(alamat): "<<std::endl;

    // Mencari posisi dan alamat node yang sesuai
    while (walk != nullptr){
        if (walk->data == key){
            std::cout<<pos<< "(" <<  &walk <<") ";
            found = true;
        }
        walk = walk->next;
        pos++;
    }
    // Kasus tidak ditemukan node yang sesuai
    if (found==false){
        log("Tidak ditemukan");
    } else {
        log("");
    }
}

Node* copyLL(Node** head_ref){
    // Fungsi untuk meng-copy linked list dan mengembalikan pointer dari linked list copy yang dibuat

    // KAMUS
    Node* walk = *head_ref;
    Node* copy = nullptr;

    // ALGORITMA
    // Menambahkan node di belakang linked list copy-an berdasarkan data dari linked list asli
    while (walk != nullptr){
        konso(&copy,walk->data);
        walk = walk->next;
    }
    return copy;
}

void concatLL(Node* head, Node* tail){
    // I.S. head dan tail terdefinisi
    // F.S. linked list dari head dan tail digabungkan menjadi 1

    // ALGORITMA
    // Menggunakan metode rekursif sampai ditemukan ekor dari linked list head
    if (head->next == nullptr){
        head->next = tail;
    } else {
        concatLL(head->next,tail);
    }
}

void my_swap (Node *node_1, Node *node_2){
    // I.S. node_1 dan node_2 terdefinisi
    // F.S. nilai data dari node_1 dan node_2 dibalik
    
    // ALGORITMA
	int temp = node_1->data;
	node_1->data = node_2 -> data;
	node_2 -> data = temp;
}

void sortingLL(Node *head_ref){
    // I.S. head_ref terdefinisi
    // F.S. linked list tersortir membesar
    
    // KAMUS
	bool swapped;
	Node *walk;
	
    // ALGORITMA
    // Kasus linked list kosong
	if (head_ref == nullptr){
	    log("Linked list kosong");
	    return;
	}
    // Mensortir linked list
	do {
		swapped = false;
		walk = head_ref;
		while (walk->next != nullptr){
			if (walk->data > walk->next->data) {
				my_swap(walk, walk->next); 
                swapped = true; 
			}
			walk = walk->next;
		}
	} while(swapped);
}

void printList(Node *node) {
    // I.S. node terdefinisi
    // F.S ditampilkan ke layar data-data pada linked list

    // ALGORITMA
    // Penanganan kasus linked list kosong
    if (node == nullptr) {
        log("Linked list kosong");
    } else {
        log("Linked list: ");
        // Menampilkan data dari setiap node pada linked list
        while (node != nullptr) {
            std::cout<< "("<< node->data << ") -> ";
            node = node->next;
        }
        log("nullptr");
    }
}