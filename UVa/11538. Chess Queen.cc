#include <iostream>
#include <algorithm>
#include <cstdint>

using namespace std;

int main(int argc, char **argv)
{
    uint64_t n = 0, m = 0;
    while (cin >> n >> m)
    {
        if (n == 0 && m == 0)
            break;

        if (n > m)
            swap(n, m);

        uint64_t ans = 0;
        ans += n * m * (m + n - 2);                   //Same colum and row
        ans += 2 * n * (n - 1) * (3 * m - n - 1) / 3; //diag
        cout << ans << endl;
    }

    return 0;
}