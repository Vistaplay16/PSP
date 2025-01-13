package ProductorConsumidorDeposito;
public class Camion3 extends Thread{

	private final Cola cola;

	public Camion3(Cola cola) {
		this.cola = cola;
	}
	
    @Override
	public void run() {
        int sumaTotal = 0;
        try {
            for (int i = 0; i < 5; i++) {
                int numero = cola.get();
            	sumaTotal += numero;
            	System.out.println("Camion 3 carga: " + numero +"L");
                Thread.sleep(1000*10); 
            }
            System.out.println("Camion3 => Volumen total= "+ sumaTotal+ ". Operacion finalizada");
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
        }
    }
}
