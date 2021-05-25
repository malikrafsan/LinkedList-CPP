#include <bits/stdc++.h>
#include <iostream>
#include "subprogram.hpp"

int main(){
	Node* head = NULL;
    int choice;
    int data;
    int pos;
    int loop;

    do {
        log("=========================================================");
        log("Main Menu");
        log("1. Mencetak linked list");
        log("2. Menambah node");
        log("3. Menghapus node");
        log("4. Mencetak panjang linked list");
        log("5. Membalik (inverse) linked list");
        log("6. Mencari nilai maksimum");
        log("7. Mencari nilai minimum");
        log("8. Pengecekan terhadap linked list");
        log("9. Copy dan concat linked list (double the size of LL)");
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
                log("Apakah ingin menambahkan satu node saja atau beberapa sekaligus?");
                log("1. Menambahkan 1 node saja");
                log("2. Menambahkan beberapa node sekaligus");
                std::cout << "Masukkan pilihan: ";
                std::cin >> choice;

                if (choice == 1){
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
                } else if (choice == 2) {
                    log("");
                    log("> Menu tambah node <");
                    log("1. Menambah node di depan");
                    log("2. Menambah node di belakang");

                    std::cout << "Masukkan pilihan: ";
                    std::cin >> choice;

                    if (choice >= 1 && choice <= 2){
                        std::cout << "Masukkan berapa kali penambahan: ";
                        std::cin >> loop;
                    }
                    switch(choice) {
                        case 1:
                            for (int i=0;i<loop;i++){
                                std::cout << "Masukkan data baru: ";
                                std::cin >> data;
                                konsDot(&head,data);
                                log("");
                            }
                            break;
                        case 2:
                            for (int i=0;i<loop;i++){
                                std::cout << "Masukkan data baru: ";
                                std::cin >> data;
                                konso(&head,data);
                                log("");
                            }
                            break;
                        default:
                            log("");
                            log("Masukan salah!");
                            break;
                    }
                } else {
                    log("Masukan salah!");
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
                log("2. Mengecek apakah ada nilai tertentu di linked list dan dimana posisinya");
                //log("3. ")
                std::cout << "Masukkan pilihan: ";
                std::cin >> choice;

                switch(choice) {
                    case 1:
                        log("");
                        isEmpty(&head);
                        break;
                    case 2:
                        log("");
                        std::cout<<"Masukkan data: ";
                        std::cin>>data;
                        checkValue(&head,data);
                        break;
                    default:
                        log("");
                        log("Masukan salah");
                        break;
                }
                break;
            case 9:
                if (head==NULL){
                    log("");
                    log("Linked list kosong");
                } else {
                    Node* dup = NULL;
                    log("");
                    dup = copyLL(&head);
                    log("");
                    log("Linked list berhasil di-copy");
                    concatLL(head,dup);
                    log("Linked list berhasil di-concat");
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