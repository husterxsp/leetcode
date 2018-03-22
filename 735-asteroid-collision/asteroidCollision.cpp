// easy..
#include <iostream>
#include <vector>

using namespace std;

vector<int> asteroidCollision(vector<int>& asteroids) {
    for (int i = 0; i < asteroids.size(); i++) {
        if (asteroids[i] > 0) continue;

        while (i >= 1) {
            if (asteroids[i - 1] < 0) break;

            if (abs(asteroids[i - 1]) > abs(asteroids[i])) {
                asteroids.erase(asteroids.begin() + i);
                i--;
                break;
            }
            else if (abs(asteroids[i - 1]) == abs(asteroids[i])) {
                asteroids.erase(asteroids.begin() + i - 1, asteroids.begin() + i + 1);
                i -= 2;
                break;
            }
            else {
                asteroids.erase(asteroids.begin() + i  -1);
                i--;
            }
        }
    }
    return asteroids;
}

int main() {
    vector<int> asteroids{-2, -1, 1, 2};
    asteroidCollision(asteroids);
}
