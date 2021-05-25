#pragma once

void log(const char* message);
// I.S message terdefinisi
// F.S message ditampilkan ke layar

// Deklarasi tipe data Node dalam bentuk class untuk linked list
class Node {
	public:
	int data;
	Node *next;
};

void konsDot(Node** head_ref, int new_data);
// I.S. head_ref dan new_data terdefinisi
// F.S. node baru ditambahkan didepan linked list

void konso(Node** head_ref, int new_data);
// I.S. head_ref dan new_data terdefinisi
// F.S. node baru ditambahkan di belakang linked list

void insert(Node** head_ref, int new_data, int pos);
// I.S. head_ref, new_data, dan pos terdefinisi
// F.S. node baru ditambahkan di posisi tertentu

void nodeDelete(Node** head_ref, int key);
// I.S. head_ref dan key terdefinisi
// F.S. dihapuskan node pertama dengan data = key

void posDelete(Node** head_ref, int pos);
// I.S. head_ref dan pos terdefinisi
// F.S. dihapuskan node dengan posisi sesuai dari linked list

void deleteHead(Node** head_ref);
// I.S. head_ref terdefinisi
// F.S. dihapuskan node pertama dari linked list

void deleteLastNode(Node** head_ref);
// I.S. head_ref terdefinisi
// F.S. dihapuskan node terakhir dari linked list

void deleteLL(Node** head_ref);
// I.S. head_ref terdefinisi
// F.S. semua node pada linked list dihapus

void lengthLL(Node* head);
// I.S. head terdefinisi
// F.S. ditampilkan ke layar panjang linked list

void reverse(Node** head_ref);
// I.S. head_ref terdefinisi
// F.S. linked list dibalik urutannya

void maxLL(Node** head_ref);
// I.S. head_ref terdefinisi
// F.S. ditampilkan ke layar, data tertinggi dari linked list

void minLL(Node** head_ref);
// I.S. head_ref terdefinisi
// F.S. ditampilkan ke layar, data terendah dari linked list

void isEmpty(Node** head_ref);
// I.S. head_ref terdefinisi
// F.S. ditampilkan ke layar apakah linked list kosong atau tidak

void checkValue(Node** head_ref, int key);
// I.S. head_ref dan key terdefinisi
// F.S. ditampilkan posisi node dan alamatnya dimana key tersimpan

Node* copyLL(Node** head_ref);
// Fungsi untuk meng-copy linked list dan mengembalikan pointer dari linked list copy yang dibuat

void concatLL(Node* head, Node* tail);
// I.S. head dan tail terdefinisi
// F.S. linked list dari head dan tail digabungkan menjadi 1

void printList(Node *node);
// I.S. node terdefinisi
// F.S ditampilkan ke layar data-data pada linked list