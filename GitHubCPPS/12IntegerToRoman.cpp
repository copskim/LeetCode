
class Solution {
public:
    string intToRoman(int num) {
        string result;
        int q, r;
        q = num / 1000; r = num % 1000;
        if (q) while (q-- > 0) result += 'M';
        q = r / 100; r = r % 100;
        if (q == 4) result += "CD";
        else if (q == 9) result += "CM";
        else if (q < 4) while (q-- > 0) result += 'C';
        else {
            result += 'D';
            q -= 5;
            while (q-- > 0) result += 'C';
        }
        q = r / 10; r = r % 10;
        if (q == 4) result += "XL";
        else if (q == 9) result += "XC";
        else if (q < 4) while (q-- > 0) result += 'X';
        else {
            result += 'L';
            q -= 5;
            while (q-- > 0) result += 'X';
        }
        q = r;
        if (q == 4) result += "IV";
        else if (q == 9) result += "IX";
        else if (q < 4) while (q-- > 0) result += 'I';
        else {
            result += 'V';
            q -= 5;
            while (q-- > 0) result += 'I';
        }
        return(result);
    }
};