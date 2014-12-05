public class Queue {
    private LinkedList myList;

    public Queue() {
        myList = new LinkedList();
    }

    @SuppressWarnings("unchecked")
    public <T> T dequeue() {
        T item = null;
        try {
            if (!myList.isEmpty()) {
            item = (T)myList.remove(myList.length()-1);
            }   
        }
        catch (ListException e) {
            e.printStackTrace();
        }   
        return item;
    }

    @SuppressWarnings("unchecked")
    public <T> void enqueue(T item) {
        try {
            myList.insert(item, 0);
        }
        catch (ListException e) {
            e.printStackTrace();
        }
    }   

    @SuppressWarnings("unchecked")
    public <T> T peek() {
        T item = null;
        try {
            item = (T)myList.retrieve(myList.length() - 1);
        }
        catch (ListException e) {
            e.printStackTrace();
        }
        return item;
    }

    public void print() {
        for (int i = (myList.length() - 1); i >= 0; i--) {
            try {
                System.out.print(myList.retrieve(i) + " ");
            }
            catch (ListException e) {
                e.printStackTrace();
            }
        }
        System.out.println("");
    }

    public String toString() {
        String str = "";
        for (int i = (myList.length() - 1); i >= 0; i--) {
            try {
                str += myList.retrieve(i) + " ";
            }
            catch (ListException e) {
                e.printStackTrace();
            }
        }
        return str;
    }   
    
    public int size() {
        return myList.length();
    }

    public boolean isEmpty() {
        return myList.length() == 0;
    }   
}
