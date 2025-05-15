// Queue.java
import java.util.*;

public class Queue<T> {
    private static final int MAX_CAPACITY = 20;
    private final T[] data;
    private int head, tail;

    // Ctor queue (kosong) dengan alokasi kapasitas maksimum
    public Queue() { 
        this.data = (T[]) new Object[MAX_CAPACITY];
        this.head = 0;
        this.tail = 0;
    }

    // Ctor queue terisi dari array dengan alokasi kapasitas maksimum.
    // Copy array dari indeks ke-0 hingga terakhir (data.length)
    // Boleh dilakukan secara copy reference object (bukan reference array)
    public Queue(T[] data) { 
        this.data = (T[]) new Object[MAX_CAPACITY];
        for (int i = 0; i < data.length; i++){
            this.data[i] = data[i];
        }
        this.head = 0;
        this.tail = data.length;
    }

    // Mengintip element paling depan pada queue.
    // Jika queue kosong, return null
    public T peek() { 
        if (head == tail) return null;
        else return data[head];
    }

    // Mengeluarkan elemen paling depan dari queue.
    // Jika queue kosong, return null
    public T pop() {
        if (head == tail) return null;
        else{ 
            T elemenPop = data[head];
            head++;
            return elemenPop;
        }
    }

    // Menambahkan elemen ke dalam queue.
    // Prekondisi: tail < MAX_CAPACITY - 2 (tidak perlu divalidasi)
    public void push(T o) { 
        data[tail] = o;
        tail++;
    }

    // Menghitung panjang queue.
    public int size() {
        return (tail - head);
    }

    // Getter attribute
    public T[] getData() { 
        return data;
    }
    public int getHead() { 
        return head;
    }
    public int getTail() { 
        return tail;
    }
}