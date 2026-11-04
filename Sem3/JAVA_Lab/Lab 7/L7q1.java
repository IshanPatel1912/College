public class L7q1 {
    private static int counter = 1;
    private static final int MAX_LIMIT = 20;

    public static void main(String[] args) {

        Thread oddThread = new Thread() {
            @Override
            public void run() {
                while (counter <= MAX_LIMIT) {
                    if (counter % 2 != 0) {
                        System.out.println(getName() + ": " + counter);
                        counter++;
                    }
                    try {
                        Thread.sleep(200);
                    } catch (InterruptedException e) {
                        Thread.currentThread().interrupt();
                    }
                }
            }
        };

        Thread evenThread = new Thread() {
            @Override
            public void run() {
                while (counter <= MAX_LIMIT) {
                    if (counter % 2 == 0) {
                        System.out.println(getName() + ": " + counter);
                        counter++;
                    }
                    try {
                        Thread.sleep(200);
                    } catch (InterruptedException e) {
                        Thread.currentThread().interrupt();
                    }
                }
            }
        };

        oddThread.setName("Odd-Thread");
        evenThread.setName("Even-Thread");

        oddThread.start();
        evenThread.start();
    }
}
