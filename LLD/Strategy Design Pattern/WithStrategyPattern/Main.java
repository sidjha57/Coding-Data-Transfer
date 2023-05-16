package WithStrategyPattern;

public class Main {

    public static void main(String[] args) {
        // Polymorphism
        Vehicle sportsVehicle = new SportsVehicle();
        sportsVehicle.drive();

        Vehicle passVehicle = new PassengerVehicle();
        passVehicle.drive();
    }
    
}
