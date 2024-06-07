class Solution {
    public String replaceWords(List<String> dictionary, String sentence) {
        String[] words = sentence.split(" ");
        int n = words.length;

        for (int i = 0; i < n; i++) {
            for (String j : dictionary) {
                if (words[i].startsWith(j))
                    words[i] = j;
            }
        }

        return String.join(" ", words);
    }
}