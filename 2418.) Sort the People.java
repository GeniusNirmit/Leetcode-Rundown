class Solution {
    public String[] sortPeople(String[] names, int[] heights) {
        int n = names.length;

        Integer[] sortedInd = new Integer[n];
        String[] sortedNames = new String[n];
        for (int i = 0; i < n; i++)
            sortedInd[i] = i;

        Arrays.sort(sortedInd, (a, b) -> heights[b] - heights[a]);

        for (int i = 0; i < n; i++)
            sortedNames[i] = names[sortedInd[i]];

        return sortedNames;
    }
}