class Solution {
    public String[] uncommonFromSentences(String s1, String s2) {
        List<String> uncommonWords = new ArrayList<>();
        Map<String, Integer> mp = new HashMap<>();

        for (String word : s1.split(" "))
            mp.put(word, mp.getOrDefault(word, 0) + 1);

        for (String word : s2.split(" "))
            mp.put(word, mp.getOrDefault(word, 0) + 1);

        for (String word : mp.keySet()) {
            if (mp.get(word) == 1)
                uncommonWords.add(word);
        }

        return uncommonWords.toArray(new String[uncommonWords.size()]);
    }
}