#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Node
{
    public:
    string judul;
    Node* l;
    Node* r;
};

// fungsi tambahan
void print(string s){
    cout << s << "\n";
}

string inputJudul() {
    cout << "Masukkan judul kegiatan: ";
    string judul;
    cin.ignore();
    getline(cin, judul);

    return judul;
}

int inputAngka() {
    cout << "Masukkan nomor: ";
    string inp;
    cin >> inp;
    for (int x = 0; x < inp.length(); x++){
        int asc = inp[x];
        if (asc < 48 || asc > 57) {
            print("Input tidak valid!");
            return inputAngka();
        }
    }

    int hasil = 0;
    int s = 1;
    for (int x = inp.length() - 1; x >= 0; x--){
        hasil += (inp[x] - '0') * s;
        s *= 10;
    }

    if (hasil == 0){
        print("Input tidak valid!");
        return inputAngka();
    }

    return hasil;
}

void insertAtBeginning(Node* head)
{
    string judul = inputJudul();
    Node* sesudah = head->r;
    Node* baru = new Node();
    baru->judul = judul;
    baru->l = head;
    head->r = baru;
    baru->r = sesudah;
    sesudah->l = baru;
    print("Kegiatan berhasil ditambahkan\n");
}

void insertAtEnd(Node* ujung)
{
    string judul = inputJudul();
    Node* sebelum = ujung->l;
    Node* baru = new Node();
    baru->judul = judul;
    baru->r = ujung;
    baru->l = sebelum;
    ujung->l = baru;
    sebelum->r = baru;
    print("Kegiatan berhasil ditambahkan\n");
}

void insertAtPosition(Node* head)
{
    if (head->r->r == NULL) {
        print("Anda tidak memilki task!");
        return;
    }

    int k = 0;
    int t = inputAngka();
    bool ada = 0;

    while (head->r != NULL){
        if (k == t){
            string judul = inputJudul();
            Node* temp = head;
            Node* sebelumnya = head->l;
            Node* baru = new Node();
            baru->judul = judul;
            baru->r = temp;
            baru->l = sebelumnya;
            temp->l = baru;
            sebelumnya->r = baru;
            while (head->l != NULL) {
                head = head->l;
            }

            print("Kegiatan berhasil ditambahkan\n");
            ada = 1;
            return;
        }

        head = head->r;
        k++;
    }

    while (head->l != NULL) {
        head = head->l;
    }

    if (!ada){
        print("Nomor tersebut belum ada di list!");
        insertAtPosition(head);
    }
}

void deleteAtBeginning(Node* head)
{
    if (head->r->r == NULL) {
        print("Anda tidak memilki task!");
        return;
    }

    Node* awal = head->r;
    head->r = awal->r;
    awal->r->l = head;
    awal->l = NULL;
    awal->r = NULL;
    print("Kegiatan berhasil dihapus");
}

void deleteAtEnd(Node* ujung)
{
    if (ujung->l->l == NULL) {
        print("Anda tidak memilki task!");
        return;
    }

    Node* akhir = ujung->l;
    ujung->l = akhir->l;
    akhir->l->r = ujung;
    akhir->l = NULL;
    akhir->r = NULL;
    print("Kegiatan berhasil dihapus");
}

void deleteAtPosition(Node* head)
{
    if (head->r->r == NULL) {
        print("Anda tidak memilki task!");
        return;
    }

    int k = 0;
    int t = inputAngka();
    bool ada = 0;

    while (head->r != NULL){
        if (k == t){
            Node* sek = head;
            sek->l->r = sek->r;
            sek->r->l = sek->l;
            sek->l = NULL;
            sek->r = NULL;
            print("Kegiatan berhasil dihapus");
            while (head->l != NULL) {
                head = head->l;
            }

            ada = 1;
            return;
        }

        head = head->r;
        k++;
    }

    while (head->l != NULL) {
        head = head->l;
    }

    if (!ada){
        print("Nomor tersebut belum ada di list!");
        deleteAtPosition(head);
    }
}

void printListForward(Node* head)
{
    int i = 1;
    head = head->r;
    if (head->r == NULL) {
        print("Anda tidak memiliki kegiatan");
        return;
    }

    print("Kegiatanmu: ");
    while (head->r != NULL) {
        string s = to_string(i) + ". " + head->judul;
        print(s);
        i++;
        head = head->r; 
    }

    print("");
    while (head->l != NULL) {
        head = head->l;
    }
}

void printListReverse(Node* ujung)
{
    int i = 1;
    ujung = ujung->l;
    if (ujung->l == NULL) {
        print("Anda tidak memilki kegiatan");
        return;
    }

    print("Kegiatanmu: ");
    while (ujung->l != NULL) {
        string s = to_string(i) + ". " + ujung->judul;
        print(s);
        i++;
        ujung = ujung->l; 
    }

    print("");
    while (ujung->r != NULL) {
        ujung = ujung->r;
    }
}

// fungsi tambahan

bool inputValid(vector<string> s, string sInput){
    unordered_map<string, bool> valid;
    for (auto str : s) {
        valid[str] = 1;
    }

    return valid[sInput];
}

void inputInsert(Node* head, Node* ujung) {
    vector<string> sValid = {"1", "2", "3", "4"};
    print("1. Tambah di awal");
    print("2. Tambah di akhir");
    print("3. Tambah di posisi tertentu");
    print("4. Kembali");
    cout << "Pilih menu (1-4): ";
    string inp;
    cin >> inp;
    if (!inputValid(sValid, inp)) {
        print("Input tidak valid!");
        inputInsert(head, ujung);
    }

    switch (inp[0]){
        case '1':
            insertAtBeginning(head);
            break;
        case '2':
            insertAtEnd(ujung);
            break;
        case '3':
            insertAtPosition(head);
            break;
        case '4':
            return;
    }
}

void inputDelete(Node* head, Node* ujung) {
    vector<string> sValid = {"1", "2", "3", "4"};
    print("1. Hapus di awal");
    print("2. Hapus di akhir");
    print("3. Hapus di posisi tertentu");
    print("4. Kembali");
    cout << "Pilih menu (1-4): ";
    string inp;
    cin >> inp;
    if (!inputValid(sValid, inp)) {
        print("Input tidak valid!");
        inputDelete(head, ujung);
    }

    switch (inp[0]){
        case '1':
            deleteAtBeginning(head);
            break;
        case '2':
            deleteAtEnd(ujung);
            break;
        case '3':
            deleteAtPosition(head);
            break;
        case '4':
            return;
    }
}

void inputTampilkan(Node* head, Node* ujung) {
    vector<string> inpValid = {"1", "2", "3"};
    print("1. Tampilkan maju");
    print("2. Tampilkan mundur");
    print("3. Kembali");
    cout << "Pilih menu (1-3): ";
    string inp;
    cin >> inp;
    if (!inputValid(inpValid, inp)){
        print("Input tidak valid!");
        inputTampilkan(head, ujung);
    }

    switch (inp[0]) {
        case '1':
            printListForward(head);
            break;
        case '2':
            printListReverse(ujung);
            break;
        case '3':
            return;
    }
}

int main()
{
    vector<string> inpValid = {"1", "2", "3", "4"};
    Node* ujung = new Node();
    Node* head = new Node();
    head->r = ujung;
    head->l = NULL;
    ujung->r = NULL;
    ujung->l = head;
    bool lanjut = 1;
    while (lanjut) { 
        print("MENU");
        print("1. Tambah kegiatan baru");
        print("2. Tampilkan semua list kegiatan");
        print("3. Hapus kegiatan tertentu");
        print("4. Keluar dari program");
        cout << "Pilih menu (1-4): ";
        string inp;
        cin >> inp;
        if (!inputValid(inpValid, inp)) {
            print("Input tidak valid!");
            continue;
        }

        switch (inp[0]) {
            case '1':
                inputInsert(head, ujung);
                break;
            case '2':
                inputTampilkan(head, ujung);
                break;
            case '3':
                inputDelete(head, ujung);
                break;
            case '4':
                lanjut = 0;
                break;
        }
    }
}