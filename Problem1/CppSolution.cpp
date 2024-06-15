#include <bits/stdc++.h>
using namespace std;
#define nline "\n"
using ull = unsigned long long;
using ll = long long;
const ll mod = 1e9 + 7;

// Function to calculate modular inverse using exponentiation
ll inv(ll a) {
    ll n = mod - 2;
    ll ans = 1;
    while (n) {
        if (n & 1) ans = (ans *1LL* a) % mod; // If n is odd, multiply ans with a
        a = (a * a) % mod; // Square the base
        n >>= 1; // Divide n by 2
    }
    return ans;
}

// Rolling hash class to handle hashing of substrings
class RollHash {
public:
    vector<ll> hsh, power, modpower;
    ll p;
    
    // Constructor to initialize the rolling hash
    RollHash(string &s) {
        p = 31; // Base for hashing
        ll n = s.size();
        hsh.resize(n + 1);
        power.resize(n + 1);
        modpower.resize(n + 1);
        power[0] = modpower[0] = 1;
        ll q = inv(p); // Calculate modular inverse of p
        for (ll i = 1; i <= n; i++) {
            power[i] = (power[i - 1] * p) % mod; // Precompute powers of p
            modpower[i] = (modpower[i - 1] * q) % mod; // Precompute inverse powers of p
            hsh[i] = (hsh[i - 1] + (power[i - 1] * (s[i - 1] - 'a' + 1)) % mod) % mod; // Calculate prefix hash
        }
    }

    // Function to get hash of a substring [i, j]
    ll getSubstr(ll i, ll j) {
        i++; j++;
        ll value = ((hsh[j] - hsh[i - 1] + mod) % mod * modpower[i - 1]) % mod; // Extract and normalize hash
        return value;
    }
};

// Function to solve the problem
void solve() {
    int n;
    cin >> n; // Read the length of the string S
    string t;
    cin >> t; // Read the string T of length 2N
    string r = t;
    reverse(r.begin(), r.end()); // Create a reverse of string T
    RollHash tsh(t); // Initialize rolling hash for T
    RollHash rsh(r); // Initialize rolling hash for reversed T

    // Iterate over possible values of i (0 to N-1)
    for (int i = 0; i < n; i++) {
        // Calculate the hash for the first i characters and the last (N-i) characters of T
        ll x1 = (tsh.getSubstr(0, i) + (tsh.getSubstr(i + n + 1, 2 * n - 1) * tsh.power[i + 1]) % mod) % mod;
        // Calculate the hash for the corresponding part in the reversed string
        ll x2 = rsh.getSubstr(n - i - 1, 2 * n - i - 2);

        // If the hashes match, we have found a valid pair (S, i)
        if (x1 == x2) {
            cout << t.substr(0, i + 1) + t.substr(i + n + 1) << nline; // Output the string S
            cout << i + 1 << nline; // Output the value of i
            return;
        }
    }
    // If no valid pair (S, i) is found, output -1
    cout << -1 << nline;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("debug.txt", "w", stderr); 
    #endif
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

    ll t;
    t = 1; 
    for (ll i = 1; i <= t; i++) {
        solve();
    }

    return 0;
}
