class Solution {
    public String kthDistinct(String[] a, int k) {
        int n = a.length;
        Map<String, Integer> mp = new HashMap<>();

        if (n < k)
            return "";

        int counter = 0;
        for (int i = 0; i < n; i++)
            mp.put(a[i], mp.getOrDefault(a[i], 0) + 1);

        for (int i = 0; i < n; i++) {
            if (mp.get(a[i]) == 1)
                counter++;
            if (counter == k)
                return a[i];
        }

        return "";
    }
}