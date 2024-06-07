class Solution {
    public List<List<Integer>> fourSum(int[] a, int target) {
        int n = a.length;
        List<List<Integer>> quadruplets = new ArrayList<>();
        Arrays.sort(a);

        for (int i = 0; i < n; i++) {
            if (i > 0 && a[i] == a[i - 1])
                continue;
            for (int j = i + 1; j < n; j++) {
                if (j > i + 1 && a[j] == a[j - 1])
                    continue;

                int k = j + 1, l = n - 1;
                while (k < l) {
                    long sum = a[i];
                    sum += a[j];
                    sum += a[k];
                    sum += a[l];
                    if (sum == target) {
                        List<Integer> quadruple = new ArrayList<>();
                        quadruple.add(a[i]);
                        quadruple.add(a[j]);
                        quadruple.add(a[k]);
                        quadruple.add(a[l]);
                        quadruplets.add(quadruple);
                        l--;
                        k++;

                        while (k < l && a[k] == a[k - 1])
                            k++;
                        while (k < l && a[l] == a[l + 1])
                            l--;
                    } else if (sum > target)
                        l--;
                    else
                        k++;
                }
            }
        }

        return quadruplets;
    }
}