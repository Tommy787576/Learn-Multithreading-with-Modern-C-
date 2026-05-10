#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    vector<int> vec{4, 2, 3, 5, 1};
    for (auto i : vec)
        cout << i << ' ';
    cout << endl;
    for (auto& i : vec)
        i += 2;
    for (auto i : vec)
        cout << i << ' ';
    cout << endl;
    return 0;
}