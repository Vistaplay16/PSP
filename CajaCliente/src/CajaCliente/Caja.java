package CajaCliente;

public class Caja extends Thread{
	private int idCaja;
	private Cola colaClientes;


	public Caja(int idCaja, Cola colaClientes) {
		this.idCaja = idCaja;
		this.colaClientes = colaClientes;
	}


	@Override
    public void run() {
        while (true) {
            try {
                // Espera a que haya un cliente en la cola
                int clienteId = colaClientes.atenderCliente();

                // Simula la atención de un cliente durante 5 segundos
                System.out.println("Caja " + idCaja + " atendiendo al cliente " + clienteId);
                Thread.sleep(5000); // Simula 5 segundos de atención
                System.out.println("Caja " + idCaja + " ha terminado de atender al cliente " + clienteId);

            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}
