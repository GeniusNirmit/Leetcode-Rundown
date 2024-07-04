class Solution {
    public int myAtoi(String s) {
        s = s.trim();
        int n = s.length();

        if (n == 0)
            return 0;

        boolean isNegative = false;
        int num = 0;
        int i = 0;

        if (s.charAt(i) == '-') {
            isNegative = true;
            i++;
        } else if (s.charAt(i) == '+')
            i++;

        for (; i < n; i++) {
            if (Character.isDigit(s.charAt(i))) {
                if (num > (Integer.MAX_VALUE - Character.getNumericValue(s.charAt(i))) / 10) {
                    if (isNegative)
                        return Integer.MIN_VALUE;
                    return Integer.MAX_VALUE;
                }
                num *= 10;
                num += Character.getNumericValue(s.charAt(i));
            } else
                break;
        }

        if (isNegative)
            num *= -1;
        return num;
    }
}