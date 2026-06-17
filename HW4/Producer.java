import java.util.Random;

public class Producer implements Runnable {
    private final BoundedBuffer buffer;
    private final int total;

    public Producer(BoundedBuffer buffer, int total) {
        this.buffer = buffer;
        this.total = total;
    }

    public void run(){
        Random random = new Random();
        double cumulative = 0.0;  
        try {
            for (int i = 1; i <= total; i++) {
                Double bufferItem = random.nextDouble() * 100.0;            
                    buffer.put(bufferItem);
                    cumulative += bufferItem;
                    if (i % 100000 == 0) {
                         System.out.printf("Producer: Generated %,d items, Cumulative value of generated items=%.3f%n",
                            i, cumulative);
                    }
            }
            System.out.printf("Producer: Finished generating %,d items%n", total);
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
        }
    }
}

    