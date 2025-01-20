package CajaCliente;

public class Cliente extends Thread{
	private int idCliente;
    private Cola colaClientes;

    public Cliente(int idCliente, Cola colaClientes) {
        this.idCliente = idCliente;
        this.colaClientes = colaClientes;
    }

    @Override
    public void run() {
        // El cliente se agrega a la cola
        colaClientes.agregarCliente(idCliente);
        System.out.println("Cliente " + idCliente + " en espera.");
    }
	
}
