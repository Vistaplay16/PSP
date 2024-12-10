package ProductoConsumidor1;

import java.util.Random;

public class Productor1 extends Thread {
    private final Queue1 cola;

    public Productor1(Queue1 cola) {
        this.cola = cola;
    }

    @Override
    public void run() {
        Random random = new Random();
        try {
            for (int i = 0; i < 10; i++) {
                int numero = random.nextInt(100);
                cola.put(numero);
                Thread.sleep(500); // Simula el tiempo de producción
            }
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
        }
    }
}

