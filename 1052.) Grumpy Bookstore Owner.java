class Solution {
    public int maxSatisfied(int[] customers, int[] grumpy, int minutes) {
        int n = customers.length;
        int maxCustomer = 0, currentCustomer = 0;

        for (int i = 0; i < n; i++) {
            if (grumpy[i] == 0)
                currentCustomer += customers[i];
            if (i < minutes && grumpy[i] == 1)
                currentCustomer += customers[i];
        }

        maxCustomer = currentCustomer;
        for (int i = 1; i < n - minutes + 1; i++) {
            if (grumpy[i - 1] == 1)
                currentCustomer -= customers[i - 1];
            if (grumpy[i + minutes - 1] == 1)
                currentCustomer += customers[i + minutes - 1];
            maxCustomer = Math.max(maxCustomer, currentCustomer);
        }

        return maxCustomer;
    }
}