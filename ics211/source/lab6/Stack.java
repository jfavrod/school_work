public class Stack {
    private LinkedList myList;
    
    public Stack() {
        myList = new LinkedList();
    }

    public Object pop() {
        Object popValue = null;
        
        if (!isEmpty()) {
            try {
                popValue = myList.remove(myList.length()-1);
            }
            catch (ListException e) {
                e.printStackTrace();
            }
        }
        
        return popValue;
    }

    public void push(Object o) {
        myList.append(o);
    }

    public Object peek() {
        Object peekValue = null;
        
        if (!isEmpty()) {
            try {
                peekValue = myList.retrieve(myList.length()-1);
            }
            catch (ListException e) {
            e.printStackTrace();
            }
        }
    
        return peekValue;
    }

    public boolean isEmpty() {
        return myList.isEmpty();
    }

    public int size() {
        return myList.length();
    }

    public String toString() {
        String temp = null;
        temp = myList.toString();
        return temp;
    }
}
