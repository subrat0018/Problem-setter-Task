import java.util.*;

public class Main {
    public static void solve() {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        
        long[] arr = new long[n];
        for (int i = 0; i < n; ++i) {
            arr[i] = sc.nextLong();
        }
        
        Map<Long, Long> countMap = new HashMap<>();
        
        for (int i = 0; i < n; ++i) {
            long diff = arr[i] - i;
            countMap.put(diff, countMap.getOrDefault(diff, 0L) + 1);
        }
        
        long beautifulTriplets = 0;
        
        for (Map.Entry<Long, Long> entry : countMap.entrySet()) {
            long count = entry.getValue();
            
            if (count >= 3) {
                beautifulTriplets += (count * (count - 1) * (count - 2)) / 6;
            }
        }
        
        System.out.println(beautifulTriplets);
    }
    
    public static void main(String[] args) {
        solve();
    }
}

