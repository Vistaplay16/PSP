package ProductorConsumidorDeposito;


public class Camion1 extends Thread{

	private final Cola cola;

	public Camion1(Cola cola) {
		this.cola = cola;
	}
	
    @Override
	public void run() {
        int sumaTotal = 0;
        try {
            for (int i = 0; i < 5; i++) {
                int numero = cola.get();
            	sumaTotal += numero;
            	System.out.println("Camion 1 carga: " + numero +"L");
                Thread.sleep(1000*7); 
            }
            System.out.println("Camion1 => Volumen total= "+ sumaTotal+ ". Operacion finalizada");
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
        }
    }
}
