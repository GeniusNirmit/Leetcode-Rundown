class Solution {
    public int[] frequencySort(int[] a) {
        int n = a.length;
        Map<Integer, Integer> mp = new HashMap<>();
        Integer[] sortedArr = new Integer[n];

        for (int i = 0; i < n; i++)
            mp.put(a[i], mp.getOrDefault(a[i], 0) + 1);

        for (int i = 0; i < n; i++)
            sortedArr[i] = a[i];

        Arrays.sort(sortedArr, (x, y) -> {
            if (mp.get(x) == mp.get(y))
                return Integer.compare(y, x);
            return Integer.compare(mp.get(x), mp.get(y));
        });

        for (int i = 0; i < n; i++)
            a[i] = sortedArr[i];
        return a;
    }
}