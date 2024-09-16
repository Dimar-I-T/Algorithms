#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>

// DIMAR ILHAM TAMARA
using namespace std;

int Min(vector<int> uang){
	int hasil = uang[0];
	for (int x = 1; x < uang.size(); x++){
		if (hasil > uang[x]){
			hasil = uang[x];
		}
	}
	
	return hasil;
}
int MinIndeks(vector<int> uang){
	int hasil = uang[0];
	int idks = 0;
	for (int x = 1; x < uang.size(); x++){
		if (hasil > uang[x]){
			hasil = uang[x];
			idks = x;
		}
	}
	
	return idks;
}

int main(){
	int n;
	cin >> n;
	vector<int> a(n);
	for (int x = 0; x < n; x++){cin >> a[x];}
	int banyakMin = 0;
	for (int x = 0; x < n; x++){
		if (a[x] < 0){
			banyakMin++;
		}
	}
	int uangMin = 0;
	if (banyakMin % 2 == 0){
		for (int x = 0; x < n; x++){
			if (a[x] < 0){
				uangMin += -1 + abs(a[x]);
			}else{
				uangMin += abs(1 - a[x]);
			}
		}
	}else{
		for (int x = 0; x < n; x++){
			if (a[x] < 0){
				uangMin += -1 + abs(a[x]);
			}else{
				uangMin += abs(1 - a[x]);
			}
		}
		vector<int> uang;
		for (int x = 0; x < n; x++){
			if (a[x] < 0){
				uang.push_back(1 + abs(a[x]));
			}else{
				uang.push_back(abs(-1 - a[x])); 
			}
		}
		int indks = MinIndeks(uang);
		int t = 0;
		if (a[indks] < 0){
			t = -1 + abs(a[indks]);
		}else{
			t = abs(1 - a[indks]);
		}
		int tambahan = Min(uang);
		uangMin += tambahan - t;
	}
	cout << uangMin;
}
