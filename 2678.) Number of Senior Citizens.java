class Solution {
    public int countSeniors(String[] details) {
        int n = details.length;
        int counter = 0;

        for (int i = 0; i < n; i++) {
            StringBuilder age = new StringBuilder();
            age.append(details[i].charAt(11));
            age.append(details[i].charAt(12));

            if (Integer.parseInt(age.toString()) > 60)
                counter++;
        }

        return counter;
    }
}