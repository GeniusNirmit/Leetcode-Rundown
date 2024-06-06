class Solution {
    public boolean isNStraightHand(int[] hand, int groupSize) {
        int n = hand.length;

        if (n % groupSize != 0)
            return false;

        Map<Integer, Integer> mp = new TreeMap<>();
        for (int i = 0; i < n; i++)
            mp.put(hand[i], mp.getOrDefault(hand[i], 0) + 1);

        while (mp.size() > 0) {
            int currentCard = mp.entrySet().iterator().next().getKey();

            for (int i = 0; i < groupSize; i++) {
                if (!mp.containsKey(currentCard + i))
                    return false;

                mp.put(currentCard + i, mp.get(currentCard + i) - 1);

                if (mp.get(currentCard + i) == 0)
                    mp.remove(currentCard + i);
            }
        }

        return true;
    }
}