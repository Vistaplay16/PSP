package ProductoConsumidor3;

import ProductoConsumidor1.Queue1;

public class Consumidor1 extends Thread{
    private final Cola cola;

    public Consumidor1(Cola cola) {
        this.cola = cola;
    }

    @Override
    public void run() {
        int sumaTotal = 0;
        try {
            for (int i = 0; i < 10; i++) {
                int numero = cola.get(true);
            	sumaTotal += numero;
            	System.out.println("Consumidor 1 suma total: " + sumaTotal);
                Thread.sleep(1000*10); 
            }
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
        }
    }
}
