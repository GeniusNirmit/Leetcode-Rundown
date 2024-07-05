class Solution {
    int rabinKarp(String source, String target) {
        int m = source.length(), n = target.length();
        int MOD = 10000007;
        int power = 1;
        for (int i = 0; i < n; i++)
            power = (power * 7) % MOD;

        int targetCode = 0;
        for (int i = 0; i < n; i++)
            targetCode = (targetCode * 7 + target.charAt(i)) % MOD;

        int hashCode = 0;
        for (int i = 0; i < m; i++) {
            hashCode = (hashCode * 7 + source.charAt(i)) % MOD;
            if (i < n - 1)
                continue;
            if (i >= n)
                hashCode = (hashCode - source.charAt(i - n) * power) % MOD;
            if (hashCode < 0)
                hashCode += MOD;
            if (hashCode == targetCode) {
                if (source.substring(i - n + 1, i + 1).equals(target))
                    return i - n + 1;
            }
        }

        return -1;
    }

    public int repeatedStringMatch(String a, String b) {
        if (a == b)
            return 1;

        int counter = 1;
        String patternRepeat = a;

        while (patternRepeat.length() < b.length()) {
            counter++;
            patternRepeat += a;
        }

        if (patternRepeat.equals(b))
            return counter;
        if (rabinKarp(patternRepeat, b) != -1)
            return counter;
        if (rabinKarp(patternRepeat + a, b) != -1)
            return counter + 1;
        return -1;
    }
}