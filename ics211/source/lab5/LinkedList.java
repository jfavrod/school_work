public class LinkedList<T> extends AbstractList implements List<T> {
    private Node head;
    private Node tail;
    private int count;

    /*
    Inner class with package level access
    Visible to classes in the same directory
    */
    class Node {
        T data;
        Node next;

        Node(T data) {
            this.data = data;
            next = null;
        }
    }

    public LinkedList() {
        super();
        head = null;
        tail = null;
        count = 0;
    }

    public int append(T item) {
        Node newNode = new Node(item);
        
        if (count == 0) {
            head = newNode;
            tail = newNode;
        }

        else if (count > 0) {
                tail.next = newNode;
                tail = newNode;
            }

        count++;
        return count;
    }

    public void insert(T item, int pos) throws ListException {
        if (pos < 0 || pos > count) {
            throw new ListException("");
        }
        else {
            Node newNode = new Node(item);
            if (count == 0 || pos == count) {
                append(item);
            }
            else if (pos == 0) {
                newNode.next = head;
                head = newNode;
                count++;
            }
            else {
                Node prev = jump(pos-1);
                newNode.next = prev.next;
                prev.next = newNode;
                count++;
            }
        }
    }

    public T remove(int pos) throws ListException {
        T item = null;

        if (pos < 0 || pos > count-1) {
            throw new ListException("Cannot remove, invalid position");
        }
        else {

            if (pos == 0) {
                item = head.data;
                head = head.next;
                count--;
            }
            else if (pos == count-1) {
                item = tail.data;
                Node prev = jump(pos-1);
                tail = prev;
                prev.next = null;
                count--;
            }
            else {
                Node prev = jump(pos-1);
                item = prev.next.data;
                prev.next = prev.next.next;
            }
        }
        return item;
    }

    public int remove(T item) {
        Node ptr = head;

        for (int i = 0; i < count; i++) {
            if (ptr.data.equals(item)) {
                try {
                    remove(i);
                } 
                catch (ListException e) {
                    e.printStackTrace();
                }
                return i;
            }
            ptr = ptr.next;
        }
        return -1;
    }

    public int find(T item) {
        Node ptr = head;

        for (int pos = 0; pos < count; pos++) {
            if (ptr.data.equals(item)) {
                return pos;
            }
            ptr = ptr.next;
        }

        return -1;
    }

    public T retrieve(int pos) throws ListException {return null;}

    public int length() {
        return count;
    }

    public LinkedList<T> copy() {return null;}
    
    public boolean isEmpty() {
        return count == 0;
    }
    
    public boolean equals(Object list) {return false;}
    
    public void replace(T item, int pos) throws ListException {}
    
    public LinkedList<T> combine(List<T> list2) {return null;}
    
    public LinkedList<T> reverse() {return null;}

    private Node jump(int numJumps) {
        Node prev = head;
        for (int i = 0; i < numJumps; i++) {
            prev = prev.next;
        }
        return prev;
    }

    public String toString() {
        String temp = "[-";
        Node node = head;

        if (count > 0) {
            temp += head.data.toString() + "-";
        }

        for (int i = 0; i < count; i++) {
            if (node.next != null) {
                node = node.next;
                temp += node.data.toString() + "-";
            }
        }

        temp +="]";
        return temp;
    }


}
