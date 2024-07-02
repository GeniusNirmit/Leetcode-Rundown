class Solution {
    public int romanToInt(String s) {
        int n = s.length();
        int num = 0;
        Map<String, Integer> mp = new HashMap<>();

        mp.put("I", 1);
        mp.put("V", 5);
        mp.put("X", 10);
        mp.put("L", 50);
        mp.put("C", 100);
        mp.put("D", 500);
        mp.put("M", 1000);
        mp.put("IV", 4);
        mp.put("IX", 9);
        mp.put("XL", 40);
        mp.put("XC", 90);
        mp.put("CD", 400);
        mp.put("CM", 900);

        for (int i = n - 1; i >= 0; i--) {
            String number1 = s.charAt(i) + "";
            String number2 = "";
            if (i - 1 >= 0)
                number2 = s.charAt(i - 1) + number1;

            if (mp.containsKey(number2) == true) {
                num += mp.get(number2);
                i--;
            } else if (mp.containsKey(number1) == true)
                num += mp.get(number1);
        }

        return num;
    }
}