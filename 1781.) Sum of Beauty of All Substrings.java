class Solution {
    public int beautySum(String s) {
        int n = s.length();
        int beautyCounter = 0;

        for (int i = 0; i < n; i++) {
            int mp[] = new int[26];
            for (int j = i; j < n; j++) {
                int minVal = Integer.MAX_VALUE;
                int maxVal = 0;

                mp[s.charAt(j) - 'a']++;

                for (int k = 0; k < 26; k++) {
                    if (mp[k] > 0) {
                        minVal = Math.min(minVal, mp[k]);
                        maxVal = Math.max(maxVal, mp[k]);
                    }
                }

                beautyCounter += (maxVal - minVal);
            }
        }

        return beautyCounter;
    }
}