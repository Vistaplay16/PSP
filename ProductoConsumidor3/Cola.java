package ProductoConsumidor3;

import java.util.concurrent.ArrayBlockingQueue;

public class Cola {
    private static final int CAPACIDAD = 5;
    private final ArrayBlockingQueue<Integer> cola = new ArrayBlockingQueue<>(CAPACIDAD);
    public boolean cons1Bool=false;
    public boolean cons2Bool=false;

    
    
    //METODO PARA INTRODUCIR ELEMENTOS EN LA LISTA 
    public synchronized void put(int numero) throws InterruptedException {
        while (cola.size() == CAPACIDAD) {
            System.out.println("Productor espera, cola llena...");
            wait();
        }
        cola.add(numero);
        System.out.println("Productor produce: " + numero);
        notifyAll();
    }
    
    
    

    public synchronized int get(boolean esConsumidor) throws InterruptedException {
        while (cola.isEmpty()){
        	System.out.println("Consumidor " + (esConsumidor ? "1" : "2") + " espera...");
        	wait();
        }

        Integer numero = cola.peek(); // Obtén el elemento sin eliminarlo
        
        
        if (esConsumidor) {
        	System.out.println("Consumidor 1");
        	//Consumidor 1 (Pares)
            System.out.println("Consumidor 1 consume: " + numero);
            notifyAll();
            if(numero%2==0) {
            	cola.poll();
            	return numero;
            }else {
            	return 0;
            }
        } else {
        	System.out.println("Consumidor 2");
        	//Consumidor 2 (Impares)
            System.out.println("Consumidor 2 consume: " + numero);
            notifyAll();
            if(numero%2!=0) {
            	cola.poll();
            	return numero;
            }else {
            	return 0;
            }
        }

        
        

        
        
    }

    
}




