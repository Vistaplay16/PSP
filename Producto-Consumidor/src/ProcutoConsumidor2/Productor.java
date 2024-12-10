package ProcutoConsumidor2;

import java.util.Random;

import ProductoConsumidor1.Queue1;

public class Productor extends Thread {
    private final Cola cola;

    public Productor(Cola cola) {
        this.cola = cola;
    }

    @Override
    public void run() {
        Random random = new Random();
        try {
            for (int i = 0; i < 10; i++) {
                int numero = random.nextInt(100);
                cola.put(numero);
                Thread.sleep(1000*2); // Simula el tiempo de producción
            }
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
        }
    }
}
