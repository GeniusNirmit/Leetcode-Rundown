class Solution {
    public int[] sortJumbled(int[] mapping, int[] a) {
        int n = a.length;
        List<int[]> mp = new ArrayList<>();
        int[] sortedArr = new int[n];

        for (int i = 0; i < n; i++) {
            String numStr = Integer.toString(a[i]);
            String mapStr = "";

            for (int j = 0; j < numStr.length(); j++)
                mapStr += mapping[numStr.charAt(j) - '0'];

            int[] entry = new int[2];
            entry[0] = Integer.parseInt(mapStr);
            entry[1] = i;
            mp.add(entry);
        }

        Collections.sort(mp, (x, y) -> {
            if (x[0] == y[0])
                return Integer.compare(x[1], y[1]);
            return Integer.compare(x[0], y[0]);
        });

        for (int i = 0; i < n; i++)
            sortedArr[i] = a[mp.get(i)[1]];

        return sortedArr;
    }
}