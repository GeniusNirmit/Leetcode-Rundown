class Node {
    int counter;
    Node prev;
    Node next;
    Set<String> keys = new HashSet<>();

    Node(int counter) {
        this.counter = counter;
    }
}

class AllOne {
    Map<String, Node> mp = new HashMap<>();
    Node head;
    Node tail;

    public AllOne() {
        head = new Node(0);
        tail = new Node(0);
        head.next = tail;
        tail.prev = head;
    }

    public void inc(String key) {
        if (mp.containsKey(key)) {
            Node currentNode = mp.get(key);
            Node nextNode = currentNode.next;
            int counter = currentNode.counter;
            currentNode.keys.remove(key);

            if (nextNode == tail || nextNode.counter != counter + 1) {
                Node newNode = new Node(counter + 1);
                newNode.keys.add(key);

                currentNode.next = newNode;
                newNode.prev = currentNode;
                newNode.next = nextNode;
                nextNode.prev = newNode;

                mp.put(key, newNode);
            } else {
                nextNode.keys.add(key);
                mp.put(key, nextNode);
            }

            if (currentNode.keys.isEmpty()) {
                currentNode.prev.next = currentNode.next;
                currentNode.next.prev = currentNode.prev;
            }
        } else {
            Node startNode = head.next;

            if (startNode == tail || startNode.counter > 1) {
                Node newNode = new Node(1);
                newNode.keys.add(key);

                head.next = newNode;
                newNode.next = startNode;
                newNode.prev = head;
                startNode.prev = newNode;

                mp.put(key, newNode);
            } else {
                startNode.keys.add(key);
                mp.put(key, startNode);
            }
        }
    }

    public void dec(String key) {
        if (!mp.containsKey(key))
            return;

        Node currentNode = mp.get(key);
        Node prevNode = currentNode.prev;
        currentNode.keys.remove(key);
        int counter = currentNode.counter;

        if (counter == 1)
            mp.remove(key);
        else {
            if (prevNode == head || prevNode.counter != counter - 1) {
                Node newNode = new Node(counter - 1);
                newNode.keys.add(key);

                prevNode.next = newNode;
                newNode.prev = prevNode;
                newNode.next = currentNode;
                currentNode.prev = newNode;

                mp.put(key, newNode);
            } else {
                prevNode.keys.add(key);
                mp.put(key, prevNode);
            }
        }

        if (currentNode.keys.isEmpty()) {
            currentNode.prev.next = currentNode.next;
            currentNode.next.prev = currentNode.prev;
        }
    }

    public String getMaxKey() {
        if (tail.prev == head)
            return "";

        return tail.prev.keys.iterator().next();
    }

    public String getMinKey() {
        if (head.next == tail)
            return "";

        return head.next.keys.iterator().next();
    }
}

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne obj = new AllOne();
 * obj.inc(key);
 * obj.dec(key);
 * String param_3 = obj.getMaxKey();
 * String param_4 = obj.getMinKey();
 */