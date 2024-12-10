package ProductoConsumidor1;



public class Consumidor1 extends Thread {
    private final Queue1 cola;

    public Consumidor1(Queue1 cola) {
        this.cola = cola;
    }

    @Override
    public void run() {
        int sumaTotal = 0;
        try {
            for (int i = 0; i < 10; i++) {
                int numero = cola.get();
                sumaTotal += numero;
                System.out.println("Consumidor suma total: " + sumaTotal);
                Thread.sleep(1000); // Simula el tiempo de consumo
            }
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
        }
    }
}

