// #include <bits/stdc++.h>
// #define endl "\n"

// using namespace std;

// int main()
// {
//     int n, t, p;
//     vector<float> cnt(6);
//     cin >> n;
//     for (int i = 0; i < 6; i++)
//     {
//         cin >> cnt[i];
//     }
//     cin >> t >> p;

//     int T = 0;
//     for (int i = 0; i < 6; i++)
//     {
//         if (!cnt[i])
//             continue;
//         T += ceil(cnt[i] / t);
//     }

//     int P1 = n / p;
//     int P2 = n % p;

//     cout << T << "\n"
//          << P1 << " " << P2 << endl;

//     return 0;
// }

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    // Reading the input
    long long N;
    cin >> N;
    
    long long S, M, L, XL, XXL, XXXL;
    cin >> S >> M >> L >> XL >> XXL >> XXXL;
    
    long long T, P;
    cin >> T >> P;
    
    // Calculate the minimum number of T-shirt bundles
    long long totalTShirtBundles = 0;
    totalTShirtBundles += (S + T - 1) / T;  // ceil(S / T)
    totalTShirtBundles += (M + T - 1) / T;
    totalTShirtBundles += (L + T - 1) / T;
    totalTShirtBundles += (XL + T - 1) / T;
    totalTShirtBundles += (XXL + T - 1) / T;
    totalTShirtBundles += (XXXL + T - 1) / T;
    
    // Calculate the maximum number of pen bundles
    long long maxPenBundles = N / P;
    long long remainingPens = N % P;
    
    // Print the results
    cout << totalTShirtBundles << endl;
    cout << maxPenBundles << " " << remainingPens << endl;

    return 0;
}
