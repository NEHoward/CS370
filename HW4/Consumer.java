class Consumer implements Runnable {
    private final BoundedBuffer buffer;
    private final int total;

    public Consumer(BoundedBuffer buffer, int total) {
        this.buffer = buffer;
        this.total = total;
    }

    public void run() {
        double cumulative = 0.0;
        try{
            for (int i = 0; i < total; i++) {
                Double item = buffer.take();
                cumulative += item;
                if (i % 100000 == 0) {
                    System.out.println("Consumer took: " + cumulative);
                }
            }
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
        }
    }
}