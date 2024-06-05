class Solution {
    public List<String> commonChars(String[] words) {
        int n = words.length;
        int[] commonCharCounter = new int[26];
        int[] currentCharCounter = new int[26];
        List<String> commonChars = new ArrayList<>();

        for (char ch : words[0].toCharArray())
            commonCharCounter[ch - 'a']++;

        for (int i = 1; i < n; i++) {
            Arrays.fill(currentCharCounter, 0);

            for (char ch : words[i].toCharArray())
                currentCharCounter[ch - 'a']++;

            for (int j = 0; j < 26; ++j)
                commonCharCounter[j] = Math.min(commonCharCounter[j], currentCharCounter[j]);
        }

        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < commonCharCounter[i]; ++j)
                commonChars.add(String.valueOf((char) (i + 'a')));
        }

        return commonChars;
    }
}