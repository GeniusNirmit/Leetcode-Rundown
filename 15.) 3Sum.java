class Solution {
    public List<List<Integer>> threeSum(int[] a) {
        int n = a.length;
        List<List<Integer>> triplets = new ArrayList<>();
        Arrays.sort(a);

        for (int i = 0; i < n; i++) {
            if (i > 0 && a[i] == a[i - 1])
                continue;

            int j = i + 1, k = n - 1;
            while (j < k) {
                long sum = a[i] + a[j] + a[k];
                if (sum == 0) {
                    List<Integer> triplet = new ArrayList<>();
                    triplet.add(a[i]);
                    triplet.add(a[j]);
                    triplet.add(a[k]);
                    triplets.add(triplet);
                    j++;
                    k--;

                    while (j < k && a[j] == a[j - 1])
                        j++;
                    while (j < k && a[k] == a[k + 1])
                        k--;
                } else if (sum < 0)
                    j++;
                else
                    k--;
            }
        }

        return triplets;
    }
}