public class PlainList<T> extends AbstractList implements List<T> {
    private int lastIndex;
    private Object[] elements;

    public PlainList() {
        super();
        elements = new Object[10];
        lastIndex = -1;
    }

    public int append(T item) {
        if (lastIndex == elements.length -1) {
            growStorage();
        }

        lastIndex++;
        elements[lastIndex] = item;
        return lastIndex + 1;
    }

    private void growStorage() {
        Object[] newElements = new Object[elements.length + 5];
        
        for (int i = 0; i < elements.length; i++) {
            newElements[i] = elements[i];
        }
        
        elements = newElements;
    }

    public String toString() {
        String temp = "[";
        for (int i = 0; i <= lastIndex; i++) {
            temp += elements[i];
            if (i < lastIndex) {
                temp += ",";
            }
        }
        temp += "]";

        return temp;
    }

    public void insert(T item, int pos) throws ListException {
        if (pos < 0 || pos > lastIndex + 1) {
            throw new ListException("Cannot insert, invalid position");
        }
        else if (pos == lastIndex + 1) {
            append(item);
        }
        else {
            if (lastIndex == elements.length - 1) {
                growStorage();
            }
            lastIndex++;
            for (int i = lastIndex; i > pos; i--) {
                elements[i] = elements[i-1];
            }
            elements[pos] = item;
        }
    }

    @SuppressWarnings("unchecked")
    public T remove(int pos) throws ListException {
        if (pos < 0 || pos > lastIndex) {
            throw new ListException("Cannot remove, invalid position");
        } 
        else {
            T removedItem = (T)elements[pos];
            for (int i = pos; i < lastIndex; i++) {
            elements[i] = elements[i+1];
            }
            elements[lastIndex] = null;
            lastIndex--;
            return removedItem;
        }
    }

    public int remove(T item) {
        int numRemoved = 0;
        for (int i = 0; i < lastIndex; i++) {
            if (elements[i].equals(item)) {
                try {
                    remove(i);
                    i--;
                    numRemoved++;
                }
                catch (ListException e) {
                    System.out.println("Can't occur, position is invalid");
                }
            }
        }
        return numRemoved;
    }
    
    public int find(T item) {return 0;}
    public T retrieve(int pos) throws ListException {return null;}
    public int length() {return 0;}
    public PlainList<T> copy() {return null;}
    public boolean isEmpty() {
    return lastIndex < 0;
    }
    public boolean equals(Object list) {return false;}
    public void replace(T item, int pos) throws ListException {}
    public PlainList<T> combine(List<T> list2) {return null;}
    public PlainList<T> reverse() {return null;}
}
