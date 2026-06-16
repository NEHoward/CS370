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
            for (int i = 0; i < total; i++) {
                Double bufferItem = random.nextDouble() * 100.0;
            
                    buffer.put(bufferItem);
                    cumulative += bufferItem;
                    if (i % 100000 == 0) {
                        System.out.println("Producer produced: " + cumulative);
                    }
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
            break;
        }
        
        }
    }
}

    