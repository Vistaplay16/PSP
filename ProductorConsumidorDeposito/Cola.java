package ProductorConsumidorDeposito;


public class Cola {

	private Integer num =0;
	
    
  //METODO PARA INTRODUCIR ELEMENTOS EN LA LISTA 
    public synchronized void put(int numero) throws InterruptedException {
        while (num!=0) {
            System.out.println("Productor espera, cola llena...");
            wait();
        }
        num=numero;
        System.out.println("Productor produce: " + numero +"L");
        notifyAll();
    }
    
    
    public synchronized int get() throws InterruptedException {
    	while (num==0) {
            System.out.println("Consumidor espera, cola vacía...");
            wait();
        }
        int numero = num;
        num=0;
        notifyAll();
        return numero;
        
    	
    	
    }
    
}
