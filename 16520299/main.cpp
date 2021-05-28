#include <iostream>
#include "subprogram.hpp"

// MAIN PROGRAM
int main(){
    // KAMUS
	Node* head = NULL;
    int choice;
    int data;
    int pos;
    int loop;

    // ALGORITMA
    log("");
    do {
        log("=========================================================");
        log("Main Menu");
        log("1. Mencetak linked list");
        log("2. Menambah node");
        log("3. Menghapus node");
        log("4. Membalik (inverse) linked list");
        log("5. Pengecekan terhadap linked list");
        log("6. Copy dan concat linked list (double the size of LL)");
        log("7. Mensortir linked list");
        log("0. exit program");

        // Meminta pilihan main menu
        std::cout << "Masukkan pilihan: ";
        std::cin >> choice;

        // Kasus exit program
        if (choice == 0) {
            log("");
            log("Terima kasih telah bermain! :D");
            log("");
            break;
        } else {
            log("");
            switch(choice) {
            // Kasus mencetak linked list
            case 1:
                printList(head);
                break;

            // Kasus menambah node
            case 2:
                log("Apakah ingin menambahkan satu node saja atau beberapa sekaligus?");
                log("1. Menambahkan 1 node saja");
                log("2. Menambahkan beberapa node sekaligus");
                
                // Meminta pilihan penambahan 1 node atau banyak
                std::cout << "Masukkan pilihan: ";
                std::cin >> choice;
                log("");

                // Kasus menambahkan 1 node saja
                if (choice == 1){
                    log("> Menu tambah node <");
                    log("1. Menambah node di depan");
                    log("2. Menambah node di belakang");
                    log("3. Menambah node di posisi tertentu");

                    // Meminta pilihan menu tambah node
                    std::cout << "Masukkan pilihan: ";
                    std::cin >> choice;
                    
                    // Kasus masukan valid -> meminta data node baru
                    if (choice >= 1 && choice <= 3){
                        std::cout << "Masukkan data node baru: ";
                        std::cin >> data;
                    }
                    switch(choice) {
                        // Kasus menambah node di depan
                        case 1:
                            log("");
                            konsDot(&head,data);
                            break;
                        
                        // Kasus menambah node di belakang
                        case 2:
                            log("");
                            konso(&head,data);
                            break;
                        
                        // Kasus menambah node di posisi tertentu
                        case 3:
                            // Meminta posisi node baru
                            std::cout<<"Masukkan posisi: ";
                            std::cin>>pos;
                            log("");

                            // Kasus input posisi invalid
                            if (pos < 1){
                                log("Posisi invalid!");
                            } // Kasus input posisi valid 
                            else {
                                insert(&head,data,pos);
                            }
                            break;
                        
                        // Kasus input pilihan posisi penambahan invalid
                        default:
                            log("");
                            log("Masukan salah!");
                            break;
                    }
                } // Kasus menambah beberapa node sekaligus 
                else if (choice == 2) {
                    log("> Menu tambah node <");
                    log("1. Menambah node di depan");
                    log("2. Menambah node di belakang");

                    // Meminta input pilihan posisi penambahan node baru
                    std::cout << "Masukkan pilihan: ";
                    std::cin >> choice;

                    // Kasus valid -> meminta berapa kali penambahan
                    if (choice >= 1 && choice <= 2){
                        std::cout << "Masukkan berapa kali penambahan: ";
                        std::cin >> loop;
                    }
                    switch(choice) {
                        // Kasus menambah node di depan
                        case 1:
                            for (int i=0;i<loop;i++){
                                std::cout << "Masukkan data baru: ";
                                std::cin >> data;
                                konsDot(&head,data);
                                log("");
                            }
                            break;
                        
                        // Kasus menambah node di belakang
                        case 2:
                            for (int i=0;i<loop;i++){
                                std::cout << "Masukkan data baru: ";
                                std::cin >> data;
                                konso(&head,data);
                                log("");
                            }
                            break;
                        
                        // Kasus input pilihan invalid
                        default:
                            log("");
                            log("Masukan salah!");
                            break;
                    }
                } // Kasus input pilihan 1 atau beberapa node invalid 
                else {
                    log("Masukan salah!");
                }
                break;
            
            // Kasus menghapus node
            case 3:
                log("> Menu hapus node <");
                log("1. Menghapus node pertama yang bernilai tertentu");
                log("2. Menghapus node di posisi tertentu");
                log("3. Menghapus node pertama");
                log("4. Menghapus node terakhir");
                log("5. Menghapus semua node linked list");
                log("6. Menghapus semua node duplikat");

                // Meminta input menu hapus node
                std::cout << "Masukkan pilihan: ";
                std::cin >> choice;

                switch(choice) {
                    // Kasus menghapus node pertama yang bernilai tertentu
                    case 1:
                        std::cout << "Masukkan nilai node yang akan dihapus: ";
                        std::cin >> data;
                        log("");
                        nodeDelete(&head,data);
                        break;
                    
                    // Kasus menghapus node di posisi tertentu
                    case 2:
                        std::cout << "Masukkan posisi node yang akan dihapus: ";
                        std::cin >> pos;
                        log("");
                        posDelete(&head,pos);
                        break;
                    
                    // Kasus menghapus node pertama
                    case 3:
                        log("");
                        deleteHead(&head);
                        break;
                    
                    // Kasus menghapus node terakhir
                    case 4:
                        log("");
                        deleteLastNode(&head);
                        break;
                    
                    // Kasus menghapus semua node linked list
                    case 5:
                        log("");
                        deleteLL(&head);
                        break;
                    
                    // Kasus menghapus semua node duplikat
                    case 6:
                        log("");
                        deleteDuplicates(head);
                        break;

                    // Kasus input menu hapus node invalid
                    default:
                        log("");
                        log("Masukan salah!");
                        break;
                }
                break;
            
            // Kasus membalik (inverse) linked list
            case 4:
                reverse(&head);
                printList(head);
                break;
            
            // Kasus pengecekan terhadap linked list    
            case 5:
                log("> Menu Pengecekan <");
                log("1. Mengecek apakah linked list kosong");
                log("2. Mengecek apakah ada nilai tertentu di linked list dan dimana posisi dan alamatnya");
                log("3. Mengecek nilai maksimum pada linked list");
                log("4. Mengecek nilai minimum pada linked list");
                log("5. Mengecek panjang linked list");
                
                // Meminta input pilihan menu pengecekan
                std::cout << "Masukkan pilihan: ";
                std::cin >> choice;
                log("");

                switch(choice) {
                    // Kasus mengecek apakah linked list kosong
                    case 1:
                        isEmpty(&head);
                        break;
                    
                    // Kasus mengecek apakah ada nilai tertentu di linked list dan dimana posisi dan alamatnya
                    case 2:
                        std::cout<<"Masukkan data: ";
                        std::cin>>data;
                        log("");
                        checkValue(&head,data);
                        break;

                    // Kasus mengecek nilai maksimum pada linked list
                    case 3:
                        maxLL(&head);
                        break;
                    
                    // Kasus mengecek nilai minimum pada linked list
                    case 4:
                        minLL(&head);
                        break;
                    
                    // Kasus mengecek panjang linked list
                    case 5:
                        lengthLL(head);
                        break;

                    // Kasus input pilihan menu pengecekan invalid
                    default:
                        log("Masukan salah");
                        break;
                }
                break;
            
            // Kasus copy dan concat linked list (double the size of LL)
            case 6:
                // Kasus linked list kosong
                if (head==NULL){
                    log("Linked list kosong");
                } 
                // Kasus linked list tidak kosong 
                else {
                    // Membuat linked list baru dan meng-copy linked list lama
                    Node* dup = NULL;
                    dup = copyLL(&head);
                    log("");
                    log("Linked list berhasil di-copy");

                    // Menggabungkan linked list copy-an dan linked list asli
                    concatLL(head,dup);
                    log("Linked list berhasil di-concat");
                }
                break;
            
            // Kasus mensortir linked list
            case 7:
                log("> Menu sortir linked list <");
                log("1. Sortir linked list terurut membesar");
                log("2. Sortir linked list terurut mengecil");

                // Meminta input pilihan menu pengecekan
                std::cout << "Masukkan pilihan: ";
                std::cin >> choice;
                
                log("");
                switch (choice) {
                    // Kasus sortir linked list terurut membesar
                    case 1:
                        sortingLL(head);
                        printList(head);
                        break;
                    
                    // Kasus sortir linked list terurut mengecil
                    case 2:
                        sortingLL(head);
                        reverse(&head);
                        printList(head);
                        break;

                    // Kasus masukan salah
                    default:
                        log("Masukan salah!");
                        break;
                }
                break;

            // Kasus input main menu invalid
            default:
                log("Masukkan salah!");
                break;
            }
        }
        log("");
    } while(true);
}

// Author
// Malik Akbar Hashemi Rafsanjani
// 16520299