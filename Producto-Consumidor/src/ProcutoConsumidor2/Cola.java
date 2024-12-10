package ProcutoConsumidor2;

import java.util.concurrent.ArrayBlockingQueue;

public class Cola {
    private static final int CAPACIDAD = 5;
    private final ArrayBlockingQueue<IntBoolCola> cola = new ArrayBlockingQueue<>(CAPACIDAD);

    
    
    //METODO PARA INTRODUCIR ELEMENTOS EN LA LISTA 
    public synchronized void put(int numero) throws InterruptedException {
        while (cola.size() == CAPACIDAD) {
            System.out.println("Productor espera, cola llena...");
            wait();
        }
        cola.add(new IntBoolCola(numero));
        System.out.println("Productor produce: " + numero);
        notifyAll();
    }
    
    
    

    public synchronized int get() throws InterruptedException {
        while (cola.isEmpty()) {
        	System.out.println("Consumidor espera, cola vacía...");
        	wait();
        }

        IntBoolCola elemento = cola.peek(); // Obtén el elemento sin eliminarlo
        elemento.marcarConsumido(); // Marcar el elemento como consumido por un consumidor, da igual quien sea de los dos 

        if (elemento.puedeEliminar()) {
            cola.poll(); // Elimina el elemento si ya fue consumido por ambos
            System.out.println("Elemento eliminado: " + elemento);
        }
        
        notifyAll();
        return elemento.getNumero();
    }

    
}


class IntBoolCola {
    private int numero;
    private int contadorConsumido; // Lleva el conteo de cuántos consumidores lo han procesado

    public IntBoolCola(int numero) {
        this.numero = numero;
        this.contadorConsumido = 0;
    }

    public int getNumero() {
        return numero;
    }

    public boolean puedeEliminar() {
    	if (contadorConsumido == 2) {
    		return true;
    	}else {
    		return false;
    	}
    }

    public void marcarConsumido() {
        contadorConsumido++;
    }

    @Override
    public String toString() {
        return "[numero=" + numero + ", contadorConsumido=" + contadorConsumido + "]";
    }
}


