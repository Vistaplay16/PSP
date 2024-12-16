package ProductoConsumidor3;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		Cola cola = new Cola();
		
		Productor prod=new Productor(cola);
		Consumidor1 cons1=new Consumidor1(cola);
		Consumidor2 cons2=new Consumidor2(cola);
		
		prod.start();
		cons1.start();
		cons2.start();
	}

}
