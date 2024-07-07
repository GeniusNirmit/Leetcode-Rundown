class Solution {
    public int numWaterBottles(int numBottles, int numExchange) {
        int emptyBottles = numBottles, counter = numBottles;

        while (numExchange <= emptyBottles) {
            int newBottles = emptyBottles / numExchange;
            counter += newBottles;
            emptyBottles %= numExchange;
            emptyBottles += newBottles;
        }

        return counter;
    }
}