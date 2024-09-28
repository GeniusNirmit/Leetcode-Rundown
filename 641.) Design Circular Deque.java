class ListNode {
    int val;
    ListNode next;
    ListNode prev;

    ListNode() {
    }

    ListNode(int val) {
        this.val = val;
    }

    ListNode(int val, ListNode next, ListNode prev) {
        this.val = val;
        this.next = next;
        this.prev = prev;
    }
};

class MyCircularDeque {
    ListNode head;
    ListNode tail;
    int maxSize;
    int size;

    public MyCircularDeque(int k) {
        maxSize = k;
        size = 0;
    }

    public boolean insertFront(int value) {
        if (size == maxSize)
            return false;

        ListNode newNode = new ListNode(value);
        if (head == null) {
            head = newNode;
            tail = head;
        } else {
            newNode.next = head;
            head.prev = newNode;
            head = newNode;
        }

        size++;
        return true;
    }

    public boolean insertLast(int value) {
        if (size == maxSize)
            return false;

        ListNode newNode = new ListNode(value);
        if (head == null) {
            head = newNode;
            tail = head;
        } else {
            tail.next = newNode;
            newNode.prev = tail;
            tail = newNode;
        }
        size++;
        return true;
    }

    public boolean deleteFront() {
        if (size == 0)
            return false;

        if (size == 1) {
            head = null;
            tail = null;
        } else
            head = head.next;

        size--;
        return true;
    }

    public boolean deleteLast() {
        if (size == 0)
            return false;

        if (size == 1) {
            head = null;
            tail = null;
        } else
            tail = tail.prev;

        size--;
        return true;
    }

    public int getFront() {
        if (size == 0)
            return -1;

        return head.val;
    }

    public int getRear() {
        if (size == 0)
            return -1;

        return tail.val;
    }

    public boolean isEmpty() {
        if (size == 0)
            return true;

        return false;
    }

    public boolean isFull() {
        if (size == maxSize)
            return true;

        return false;
    }
}

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque obj = new MyCircularDeque(k);
 * boolean param_1 = obj.insertFront(value);
 * boolean param_2 = obj.insertLast(value);
 * boolean param_3 = obj.deleteFront();
 * boolean param_4 = obj.deleteLast();
 * int param_5 = obj.getFront();
 * int param_6 = obj.getRear();
 * boolean param_7 = obj.isEmpty();
 * boolean param_8 = obj.isFull();
 */