import java.util.Map;
import java.util.HashMap;

class ListNode {
    int key;
    int val;
    int freq;
    ListNode next;
    ListNode prev;

    ListNode() {
        this.key = -1;
        this.val = -1;
        this.freq = 1;
    }

    ListNode(int key, int val) {
        this.key = key;
        this.val = val;
        this.freq = 1;
    }
}

class Lists {
    int size;
    ListNode head;
    ListNode tail;

    Lists() {
        this.size = 0;
        this.head = new ListNode(-1, -1);
        this.tail = new ListNode(-1, -1);
        this.head.next = tail;
        this.tail.prev = head;
    }

    void insertNode(ListNode newNode) {
        newNode.next = this.tail;
        this.tail.prev.next = newNode;
        newNode.prev = this.tail.prev;
        this.tail.prev = newNode;
        this.size++;
    }

    void deleteNode(ListNode deleteNode) {
        deleteNode.prev.next = deleteNode.next;
        deleteNode.next.prev = deleteNode.prev;
        this.size--;
    }
}

class LFUCache {
    ListNode head = new ListNode();
    ListNode tail = new ListNode();
    Map<Integer, ListNode> mp = new HashMap<>();
    Map<Integer, Lists> freq = new HashMap<>();
    int capacity, minFreq, currentSize;

    public LFUCache(int capacity) {
        this.capacity = capacity;
        this.minFreq = 0;
        this.currentSize = 0;
    }

    void updateNode(ListNode node) {
        Lists currentList = freq.get(node.freq);
        currentList.deleteNode(node);

        if (node.freq == minFreq && currentList.size == 0) {
            freq.remove(node.freq);
            minFreq++;
        }

        node.freq++;
        Lists newList = freq.getOrDefault(node.freq, new Lists());
        newList.insertNode(node);
        newList.size++;
        freq.put(node.freq, newList);
    }

    public int get(int key) {
        if (mp.containsKey(key)) {
            updateNode(mp.get(key));
            return mp.get(key).val;
        }
        return -1;
    }

    public void put(int key, int value) {
        if (capacity == 0)
            return;

        if (mp.containsKey(key)) {
            mp.get(key).val = value;
            updateNode(mp.get(key));
        } else {
            currentSize++;

            if (currentSize > capacity) {
                Lists currentList = freq.get(minFreq);
                if (currentList.head.next.key != -1) {
                    mp.remove(currentList.head.next.key);
                    currentList.deleteNode(currentList.head.next);
                    currentSize--;
                }
            }

            minFreq = 1;
            ListNode newNode = new ListNode(key, value);
            Lists currentList = freq.getOrDefault(minFreq, new Lists());
            currentList.insertNode(newNode);

            mp.put(key, newNode);
            freq.put(minFreq, currentList);
        }
    }
}
