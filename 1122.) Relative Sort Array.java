class Solution {
    public int[] relativeSortArray(int[] a1, int[] a2) {
        Map<Integer, Integer> mp = new HashMap<>();
        List<Integer> remaining = new ArrayList<>();
        List<Integer> result = new ArrayList<>();

        for (int i : a2)
            mp.put(i, 0);

        for (int i : a1) {
            if (mp.containsKey(i))
                mp.put(i, mp.get(i) + 1);
            else
                remaining.add(i);
        }

        Collections.sort(remaining);

        for (int i : a2) {
            for (int j = 0; j < mp.get(i); j++)
                result.add(i);
        }

        result.addAll(remaining);
        return result.stream().mapToInt(Integer::intValue).toArray();
    }
}