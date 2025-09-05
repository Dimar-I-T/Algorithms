#include <bits/stdc++.h>
using namespace std;

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

void insertAtBeginning(list<string>& kegiatan)
{
    string judul = inputJudul();
    kegiatan.push_front(judul);
    print("Kegiatan berhasil ditambahkan\n");
}

void insertAtEnd(list<string>& kegiatan)
{
    string judul = inputJudul();
    kegiatan.push_back(judul);
    print("Kegiatan berhasil ditambahkan\n");
}

void insertAtPosition(list<string>& kegiatan)
{
    int t = inputAngka();
    list<string>::iterator itr = kegiatan.begin();
    int k = 1;
    bool ada = 0;
    for (itr; itr != kegiatan.end(); ++itr) {
        if (k == t) {
            string judul = inputJudul();
            ada = 1;
            kegiatan.insert(itr, judul);
            print("Kegiatan berhasil ditambahkan\n");
            break;
        }

        k++;
    }

    if (!ada) {
        print("Nomor tersebut tidak ada di kegiatan!\n");
        insertAtPosition(kegiatan);
    }
}

void deleteAtBeginning(list<string>& kegiatan)
{
    if (kegiatan.empty()) {
        print("Anda tidak memiliki kegiatan");
        return;
    }

    kegiatan.pop_front();
    print("Kegiatan berhasil dihapus");
}

void deleteAtEnd(list<string>& kegiatan)
{
    if (kegiatan.empty()) {
        print("Anda tidak memiliki kegiatan");
        return;
    }

    kegiatan.pop_back();
    print("Kegiatan berhasil dihapus");
}

void deleteAtPosition(list<string>& kegiatan)
{
    int t = inputAngka();
    list<string>::iterator itr = kegiatan.begin();
    int k = 1;
    bool ada = 0;

    for (itr; itr != kegiatan.end(); ++itr) {
        if (k == t) {
            ada = 1;
            kegiatan.erase(itr);
            print("Kegiatan berhasil dihapus");
            break;
        }

        k++;
    }

    if (!ada) {
        print("Nomor tersebut tidak ada di kegiatan");
        deleteAtPosition(kegiatan);
    }
}

void printListForward(list<string>& kegiatan)
{
    if (kegiatan.empty()) {
        print("Anda belum memiliki kegiatan");
        return;
    }

    print("Kegiatanmu: ");
    int i = 1;
    for (auto itr : kegiatan) {
        string s = to_string(i) + ". " + itr;
        print(s);
        i++;
    }
}

void printListReverse(list<string>& kegiatan)
{
    if (kegiatan.empty()) {
        print("Anda belum memiliki kegiatan");
        return;
    }

    list<string>::reverse_iterator itrR = kegiatan.rbegin();
    int i = 1;
    for (itrR; itrR != kegiatan.rend(); ++itrR){
        string s = to_string(i) + ". " + *itrR;
        print(s);
        i++;
    }
}


bool inputValid(vector<string> s, string sInput){
    unordered_map<string, bool> valid;
    for (auto str : s) {
        valid[str] = 1;
    }

    return valid[sInput];
}

void inputInsert(list<string>& kegiatan) {
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
        inputInsert(kegiatan);
    }

    switch (inp[0]){
        case '1':
            insertAtBeginning(kegiatan);
            break;
        case '2':
            insertAtEnd(kegiatan);
            break;
        case '3':
            insertAtPosition(kegiatan);
            break;
        case '4':
            return;
    }
}

void inputDelete(list<string>& kegiatan) {
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
        inputDelete(kegiatan);
    }

    switch (inp[0]){
        case '1':
            deleteAtBeginning(kegiatan);
            break;
        case '2':
            deleteAtEnd(kegiatan);
            break;
        case '3':
            deleteAtPosition(kegiatan);
            break;
        case '4':
            return;
    }
}

void inputTampilkan(list<string>& kegiatan) {
    vector<string> inpValid = {"1", "2", "3"};
    print("1. Tampilkan maju");
    print("2. Tampilkan mundur");
    print("3. Kembali");
    cout << "Pilih menu (1-3): ";
    string inp;
    cin >> inp;
    if (!inputValid(inpValid, inp)){
        print("Input tidak valid!");
        inputTampilkan(kegiatan);
    }

    switch (inp[0]) {
        case '1':
            printListForward(kegiatan);
            break;
        case '2':
            printListReverse(kegiatan);
            break;
        case '3':
            return;
    }
}

int main(){
    vector<string> inpValid = {"1", "2", "3", "4"};
    list<string> kegiatan;
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
                inputInsert(kegiatan);
                break;
            case '2':
                inputTampilkan(kegiatan);
                break;
            case '3':
                inputDelete(kegiatan);
                break;
            case '4':
                lanjut = 0;
                break;
        }
    }
}