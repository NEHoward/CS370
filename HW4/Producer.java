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
        for (int i = 0; i < total; i++) {
            System.out.println(name + " is working on task " + i);
    }
}

    