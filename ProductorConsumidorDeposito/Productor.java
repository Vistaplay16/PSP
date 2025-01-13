package ProductorConsumidorDeposito;

import java.util.Random;


public class Productor extends Thread {

	private final Cola cola;
	
	public Productor(Cola cola) {
        this.cola = cola;
    }
	
	
	public void run() {
        Random random = new Random();
        try {
            for (int i = 0; i < 15; i++) {
                int numero = random.nextInt(1000);
                cola.put(numero);
                Thread.sleep(1000*2); // Simula el tiempo de producción
            }
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
        }
    }
}
