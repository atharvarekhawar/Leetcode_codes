class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int i = n - 1;
        
        digits[i] += 1;  // Adding 1 at the end of array
        
        while(i >= 0) {
     if (digits[i] != 10) return digits;  // If that digit is not 10 then we've done our work
            digits[i] = 0;    // Since v[i] was 10, we'll make it 0
            if (i > 0) digits[i - 1] += 1;  // We can still add 1 to the previous element
            else digits.insert(digits.begin(), 1);  // Here we can't so insert 1 at beginning
            i--;
        }
        
        return digits;
    }
};