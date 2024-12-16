package ProductoConsumidor3;

import ProductoConsumidor1.Queue1;

public class Consumidor2 extends Thread {
    private final Cola cola;

    public Consumidor2(Cola cola) {
        this.cola = cola;
    }

    @Override
    public void run() {
        int sumaTotal = 0; 
        try {
            for (int i = 0; i < 10; i++) {
                int numero = cola.get(false); 
            	sumaTotal += numero;
            	System.out.println("Consumidor 2 suma total: " + sumaTotal);
                Thread.sleep(1000*5); 
            }
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
        }
    }
}
