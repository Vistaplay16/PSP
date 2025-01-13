package ProductorConsumidorDeposito;

public class Camion2 extends Thread {

	private final Cola cola;

	public Camion2(Cola cola) {
		this.cola = cola;
	}
	
    @Override
	public void run() {
        int sumaTotal = 0;
        try {
            for (int i = 0; i < 5; i++) {
                int numero = cola.get();
            	sumaTotal += numero;
            	System.out.println("Camion 2 carga: " + numero +"L");
                Thread.sleep(1000*5); 
            }
            System.out.println("Camion2 => Volumen total= "+ sumaTotal+ ". Operacion finalizada");
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
        }
    }
}
