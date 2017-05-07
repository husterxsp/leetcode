#include <iostream>
#include <vector>

using namespace std;

bool canWinNim(int n) {
    return n % 4;
}

int main () {
    cout << canWinNim(1348820612) << endl;
    return 0;
}
