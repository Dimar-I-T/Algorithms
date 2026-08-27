class Solution {
public:
    string getPermutation(int n, int k) {
        vector<long long> fakt;
        fakt.push_back(1);
        int lastFakt = *fakt.rbegin();
        int i = 1;
        while (lastFakt <= k) {
            int faktBaru = lastFakt * i;
            fakt.push_back(faktBaru);
            lastFakt = faktBaru;
            i++;
        }

        fakt.pop_back();
        int idx = fakt.size() - 1;
        vector<int> nums(n);
        for (int x = 0; x < n; x++) {
            nums[x] = x + 1;
        }

        vector<int> hasil;
        while (k > 1) {
            int faktTerdekat = *fakt.rbegin();
            for (int x = 0; x < n; x++) {
                if (fakt[x + 1] >= k) {
                    faktTerdekat = fakt[x];
                    idx = x;
                    break;
                }
            }

            int nSem = nums.size();
            for (int x = 0; x < nSem - idx - 1; x++) {
                hasil.push_back(nums[0]);
                nums.erase(nums.begin());
            }

            int idxSel = (k + faktTerdekat - 1) / faktTerdekat;
            int angkaSel = nums[idxSel - 1];
            nums.erase(nums.begin() + idxSel - 1);
            hasil.push_back(angkaSel);
            if (k % faktTerdekat == 0) {
                cout << faktTerdekat;
                k = faktTerdekat;
            } else {
                k %= faktTerdekat;
            }
        }

        if (!nums.empty()) {
            for (int x : nums) {
                hasil.push_back(x);
            }
        }

        string hasilString = "";
        for (int x : hasil) {
            hasilString += to_string(x);
        }

        return hasilString;
    }
};