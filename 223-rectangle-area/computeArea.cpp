#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <stack>
#include <Map>
#include <Set>
#include <unordered_map>
#include <unordered_set>

using namespace std;
int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
    int sum = (C - A) * (D - B) + (G - E) * (H - F);
    if (E > C || G < A || F > D || H < B) return sum;
    return sum - (min(C, G) - max(A, E)) * (min(D, H) - max(B, F));
}

int main () {
    cout << computeArea(-3, 0, 3, 4, 0, -1, 9, 2) << endl;
    return 0;
}
