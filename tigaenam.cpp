#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> nilai(n);
	for (int x = 0; x < n; x++){cin >> nilai[x];}
	int maks = nilai[0];
	for (int x = 1; x < n; x++){
		if (maks < nilai[x]){
			maks = nilai[x];
		}
	}
	int hasil = 0;
	for (int x = 0; x < n; x++){
		if (nilai[x] == maks){
			hasil++;
		}
	}
	
	cout << hasil;
	return 0;
}
