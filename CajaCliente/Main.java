package CajaCliente;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		// Crear cola de clientes
		Cola colaClientes = new Cola();
		
		
		// Crear 3 cajas
        Caja caja1 = new Caja(1,colaClientes);
        Caja caja2 = new Caja(2, colaClientes);
        Caja caja3 = new Caja(3, colaClientes);
        caja1.start();
        caja2.start();
        caja3.start();


        // Crear 15 clientes
        for (int i = 0; i <= 15; i++) {
            Cliente cliente = new Cliente(i, colaClientes);
            Thread t = new Thread(cliente);
            t.start();
        }

	}

}
