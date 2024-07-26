class Solution {
    public String countOfAtoms(String formula) {
        int n = formula.length();
        Stack<Map<String, Integer>> st = new Stack<>();
        st.push(new HashMap<>());

        int i = 0;
        while (i < n) {
            if (formula.charAt(i) == '(') {
                st.push(new HashMap<>());
                i++;
            } else if (formula.charAt(i) == ')') {
                Map<String, Integer> mp = st.pop();
                i++;
                StringBuilder multiply = new StringBuilder();

                while (i < n && Character.isDigit(formula.charAt(i))) {
                    multiply.append(formula.charAt(i));
                    i++;
                }

                if (multiply.length() > 0) {
                    int multiplier = Integer.parseInt(multiply.toString());
                    for (String atom : mp.keySet())
                        mp.put(atom, mp.get(atom) * multiplier);
                }

                for (String atom : mp.keySet()) {
                    Map<String, Integer> prevMp = st.peek();
                    prevMp.put(atom, prevMp.getOrDefault(atom, 0) + mp.get(atom));
                }
            } else {
                StringBuilder atom = new StringBuilder();
                atom.append(formula.charAt(i));
                i++;

                while (i < n && Character.isLowerCase(formula.charAt(i))) {
                    atom.append(formula.charAt(i));
                    i++;
                }

                StringBuilder counterStr = new StringBuilder();
                while (i < n && Character.isDigit(formula.charAt(i))) {
                    counterStr.append(formula.charAt(i));
                    i++;
                }

                int counter = 1;
                if (counterStr.length() > 0)
                    counter = Integer.parseInt(counterStr.toString());

                Map<String, Integer> mp = st.peek();
                mp.put(atom.toString(), mp.getOrDefault(atom.toString(), 0) + counter);
            }
        }

        Map<String, Integer> mp = new TreeMap<>(st.peek());
        StringBuilder atomCounter = new StringBuilder();

        for (String atom : mp.keySet()) {
            atomCounter.append(atom);

            if (mp.get(atom) > 1)
                atomCounter.append(mp.get(atom));
        }

        return atomCounter.toString();
    }
}