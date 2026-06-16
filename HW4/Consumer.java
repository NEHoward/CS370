class Consumer implements Runnable {
    private final BoundedBuffer buffer;
    private final int total;

    public Consumer(BoundedBuffer buffer, int total) {
        this.buffer = buffer;
        this.total = total;
    }

    public void run() {
        for (int i = 0; i < total; i++) {
            try {
                Double item = buffer.take();
                System.out.println("Consumer took: " + item);
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
                break;
            }
        }
    }
}