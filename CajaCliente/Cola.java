package CajaCliente;

import java.util.LinkedList;
import java.util.Queue;
import java.util.concurrent.ArrayBlockingQueue;

public class Cola {
	private static final int CAPACIDAD = 15;
	private final ArrayBlockingQueue<Integer> cola = new ArrayBlockingQueue<>(CAPACIDAD);

	 public synchronized void agregarCliente(int clienteId) {
	        cola.add(clienteId);
	        notifyAll(); // Notificar a los hilos que hay un cliente disponible
	 }
	 
	 public synchronized int atenderCliente() throws InterruptedException {
	        while (cola.isEmpty()) {
	            wait(); // Si la cola está vacía, esperar
	        }
	        return cola.poll();
	  }
	
}
