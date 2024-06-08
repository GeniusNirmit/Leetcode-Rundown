class Solution {
    public boolean checkSubarraySum(int[] a, int k) {
        int n = a.length;

        if (n < 2)
            return false;

        int prevMod = 0;
        Map<Integer, Integer> mp = new HashMap<>();
        mp.put(0, -1);

        for (int i = 0; i < n; i++) {
            prevMod = (prevMod + a[i]) % k;

            if (mp.containsKey(prevMod) && i - mp.get(prevMod) >= 2)
                return true;
            else if (!mp.containsKey(prevMod))
                mp.put(prevMod, i);
        }

        return false;
    }
}