#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;
string getHint(string secret, string guess) {
    int a = 0, b = 0;
    unordered_map<char, int> secretMap;
    for (int i = 0; i < secret.size(); i++) {
        if (secret[i] == guess[i]) {
            secret.erase(i, 1);
            guess.erase(i, 1);
            i--;
            a++;
        }
        else {
            secretMap[secret[i]]++;
        }
    }

    for (int i = 0; i < guess.size(); i++) {
        if (secretMap[guess[i]] > 0) {
            b++;
            secretMap[guess[i]]--;
        }
    }

    return to_string(a) + "A" + to_string(b) + "B";
}

int main() {
    cout << getHint("1123", "0111") << endl;
    return 0;
}
