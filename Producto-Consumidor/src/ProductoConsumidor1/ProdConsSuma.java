package ProductoConsumidor1;


public class ProdConsSuma {
    public static void main(String[] args) {
        Queue1 cola = new Queue1();

        Productor1 productor = new Productor1(cola);
        Consumidor1 consumidor = new Consumidor1(cola);

        productor.start();
        consumidor.start();
    }
}

