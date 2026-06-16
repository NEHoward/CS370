import java.util.Random;

//1) Implement the FIFO Circular Buffer and ensure that the buffer can hold a maximum of 1000 items at a time. 
//2) Consumer should wait if there are no items in the buffer 
//3) Producer should wait if the buffer is full 
//4) Ensure that the producer can produce 1,000,000 items and the consumer can consume 
//1,000,000, items with a bounder buffer that can hold at most 1000 items at a time. 
//a. You should not run out of memory. Remember, your producer should not produce if the 
//buffer is full. You should not set the size of the Java VM in your makefile or expect that 
//the JVM will be set to a certain value. 
//b. Your solution must satisfy the correctness constraint i.e. you consume each item exactly 
//once, in the order that it was produced, and demonstrate this by printing out the value 
//of your counter (at both the producer and consumer) every time you have produced or 
//consumed 100,000 elements. See the example output below; note how the counter 
//values match at the producer and consumer for the same N.  
//c. There should be no deadlock. Your program will be executed 5 times, and it should run 
//to completion every time without a deadlock. 
class BoundedBuffer {
    private final Double[] buffer;
    private final int capacity;
    private int head = 0;
    private int tail = 0;
    private int count = 0;

    public BoundedBuffer(int capacity) {
        this.capacity = capacity;
        this.buffer = new Double[capacity];
    }

    public synchronized void put(Double item) throws InterruptedException {
        //producer should wait if the buffer is full
        while (count == capacity) {
            wait();
        }
        buffer[tail] = item;
        tail = (tail + 1) % capacity;
        count++;
        notifyAll();
    }

    public synchronized Double take() throws InterruptedException {
        //consumer should wait if there are no items in the buffer
        while (count == 0){
            wait();
        }
        Double item = buffer[head];
        head = (head + 1) % capacity;
        count--;
        notify();
        return item;
    }
}

public class ProduceConsumer {
    public static void main(String[] args) {
        // Initialize the number of items to be produced and consumed,
        // items set to 1000000 and the buffer capacity set to 1000
        final int ITEMS = 1000000;
        final int BUFFER_CAPACITY = 1000;

        BoundedBuffer buffer = new BoundedBuffer(BUFFER_CAPACITY);
        Thread producerThread = new Thread(new Producer(buffer, ITEMS));
        Thread consumerThread = new Thread(new Consumer(buffer, ITEMS));

        producerThread.start();
        consumerThread.start();

        try {
            producerThread.join();
            consumerThread.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        System.out.println("Exiting!");
    }
}