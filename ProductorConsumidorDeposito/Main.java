package ProductorConsumidorDeposito;



public class Main {

    public static void main(String[] args) {
        Cola cola = new Cola();

        Productor prod = new Productor(cola);
        Camion1 camion1 = new Camion1(cola);
        Camion2 camion2 = new Camion2(cola);
        Camion3 camion3 = new Camion3(cola);

        // Iniciar los hilos
        prod.start();
        camion1.start();
        camion2.start();
        camion3.start();
        }
}
