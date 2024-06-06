class Solution {
    public boolean isPossibleDivide(int[] a, int k) {
        int n = a.length;

        if (n % k != 0)
            return false;

        Map<Integer, Integer> mp = new TreeMap<>();
        for (int i = 0; i < n; i++)
            mp.put(a[i], mp.getOrDefault(a[i], 0) + 1);

        while (mp.size() > 0) {
            int currentNum = mp.entrySet().iterator().next().getKey();

            for (int i = 0; i < k; i++) {
                if (!mp.containsKey(currentNum + i))
                    return false;

                mp.put(currentNum + i, mp.get(currentNum + i) - 1);

                if (mp.get(currentNum + i) == 0)
                    mp.remove(currentNum + i);
            }
        }

        return true;
    }
}