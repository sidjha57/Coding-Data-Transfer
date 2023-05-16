interface Bicycle{
    int a = 45;
    void applyBrake(int decrement);
    void speedUp(int increment);
}

interface HornBicycle{
    int b = 45;
    void blowHornk3g();
    void blowHornmhn();
}
class AvonCycle implements Bicycle, HornBicycle {
    void blowHorn() {
        System.out.println("Pee Poo Poo Poo");
    }

    @Override
    public void applyBrake(int decrement){
        System.out.println("Applying Brake");
    }

    @Override
    public void speedUp(int increment) {
        System.out.println("Applying SpeedUP");
    }

    @Override
    public void blowHornk3g() {
        System.out.println("Mai hoon Na");
    }

    @Override
    public void blowHornmhn() {
        System.out.println("Kabhi khushi Kabhi Gam");
    }
}
public class Interfaces {
    public static void main(String[] args) {
        AvonCycle cycleHarry = new AvonCycle();
        cycleHarry.applyBrake(1);
        // You can create properties in Interfaces
        System.out.println(cycleHarry.a);
        // You cannot modify the properties in Interfaces as they are final
    }
}
