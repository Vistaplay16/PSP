package ProductoConsumidor1;

import java.util.concurrent.ArrayBlockingQueue;

public class Queue1 {
    private static final int CAPACIDAD = 5;
    private final ArrayBlockingQueue<Integer> cola = new ArrayBlockingQueue<>(CAPACIDAD);

    public synchronized void put(int numero) throws InterruptedException {
        while (cola.size() == CAPACIDAD) {
            System.out.println("Productor espera, cola llena...");
            wait();
        }
        cola.add(numero);
        System.out.println("Productor produce: " + numero);
        notifyAll();
    }

    public synchronized int get() throws InterruptedException {
        while (cola.isEmpty()) {
            System.out.println("Consumidor espera, cola vacía...");
            wait();
        }
        int numero = cola.poll();
        System.out.println("Consumidor consume: " + numero);
        notifyAll();
        return numero;
    }
}

