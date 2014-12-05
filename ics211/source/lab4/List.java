public interface List<T> {
   public int append(T item);
   public void insert(T item, int pos) throws ListException;
   public T remove(int pos) throws ListException;
   public int remove(T item);
   public int find(T item);
   public T retrieve(int pos) throws ListException;
   public int length();
   public List<T> copy();
   public boolean isEmpty();
   public boolean equals(Object list);
   public void replace(T item, int pos) throws ListException;
   public List<T> combine(List<T> list2);
   public List<T> reverse();
}
