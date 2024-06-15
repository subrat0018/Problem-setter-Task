import java.util.*;

public class Main {
    static final long MOD = 1_000_000_007;
    
    // Function to calculate modular inverse
    static long inv(long a) {
        long n = MOD - 2;
        long ans = 1;
        while (n > 0) {
            if ((n & 1) == 1) {
                ans = (ans * a) % MOD;
            }
            a = (a * a) % MOD;
            n >>= 1;
        }
        return ans;
    }

    static class RollHash {
        long[] hsh, power, modpower;
        long p;
        
        RollHash(String s) {
            p = 31;
            int n = s.length();
            hsh = new long[n + 1];
            power = new long[n + 1];
            modpower = new long[n + 1];
            power[0] = modpower[0] = 1;
            long q = inv(p);
            for (int i = 1; i <= n; i++) {
                power[i] = (power[i - 1] * p) % MOD;
                modpower[i] = (modpower[i - 1] * q) % MOD;
                hsh[i] = (hsh[i - 1] + (power[i - 1] * (s.charAt(i - 1) - 'a' + 1)) % MOD) % MOD;
            }
        }

        long getSubstr(int i, int j) {
            i++; j++;
            long value = ((hsh[j] - hsh[i - 1] + MOD) % MOD * modpower[i - 1]) % MOD;
            return value;
        }
    }

    static void solve() {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        String t = sc.next();
        String r = new StringBuilder(t).reverse().toString();
        RollHash tsh = new RollHash(t);
        RollHash rsh = new RollHash(r);

        for (int i = 0; i < n; i++) {
            long x1 = (tsh.getSubstr(0, i) + (tsh.getSubstr(i + n + 1, 2 * n - 1) * tsh.power[i + 1]) % MOD) % MOD;
            long x2 = rsh.getSubstr(n - i - 1, 2 * n - i - 2);
            if (x1 == x2) {
                System.out.println(t.substring(0, i + 1) + t.substring(i + n + 1));
                System.out.println(i + 1);
                return;
            }
        }
        System.out.println(-1);
    }

    public static void main(String[] args) {
        solve();
    }
}

