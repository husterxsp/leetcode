class Solution {
public:
    string numberToWords(int num) {
        vector<string> lessThan20{"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten",
                    "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        vector<string> tens{"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        vector<string> thousand{"", "Thousand", "Million", "Billion"};

        string ret = "";
        int i = 0;
        while (num > 0) {
            if (num % 1000 != 0) ret = helper() + ret;

            num /= 1000;
            i++;
        }
    }
private:
    string helper(int num) {
        if (num == 0) return "";
        else if (num < 20) return lessThan20[num];
        else if (num < 100) return tens[num / 10] + " " +lessThan20[num % 10];
        else return lessThan20[num / 100] + " " + helper(num % 100); 
    }
};
