package ProcutoConsumidor2;

import ProductoConsumidor1.Queue1;

public class Consumidor2 extends Thread {
    private final Cola cola;

    public Consumidor2(Cola cola) {
        this.cola = cola;
    }

    @Override
    public void run() {
        int productoTotal = 1; 
        try {
            for (int i = 0; i < 10; i++) {
                int numero = cola.get(); // false indica que es Consumidor 2
                productoTotal *= numero;
                System.out.println("Consumidor 2 multiplicación total: " + productoTotal);
                Thread.sleep(1000*5); 
            }
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
        }
    }
}
