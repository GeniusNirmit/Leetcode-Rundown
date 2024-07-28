class Solution {
    public List<Integer> survivedRobotsHealths(int[] positions, int[] healths, String directions) {
        int n = positions.length;
        List<int[]> robots = new ArrayList<>();
        Stack<int[]> st = new Stack<>();

        for (int i = 0; i < n; i++)
            robots.add(new int[] { positions[i], healths[i], directions.charAt(i), i });

        Collections.sort(robots, (a, b) -> Integer.compare(a[0], b[0]));

        for (int[] robot : robots) {
            if (robot[2] == 'R' || st.isEmpty() || st.peek()[2] == 'L') {
                st.push(robot);
                continue;
            }
            if (robot[2] == 'L') {
                boolean add = true;
                while (!st.isEmpty() && st.peek()[2] == 'R' && add) {
                    int last_health = st.peek()[1];
                    if (robot[1] > last_health) {
                        st.pop();
                        robot[1] -= 1;
                    } else if (robot[1] < last_health) {
                        st.peek()[1] -= 1;
                        add = false;
                    } else {
                        st.pop();
                        add = false;
                    }
                }

                if (add)
                    st.push(robot);
            }
        }

        List<int[]> resultList = new ArrayList<>(st);
        resultList.sort(Comparator.comparingInt(a -> a[3]));

        List<Integer> result = new ArrayList<>();
        for (int[] robot : resultList)
            result.add(robot[1]);

        return result;
    }
}