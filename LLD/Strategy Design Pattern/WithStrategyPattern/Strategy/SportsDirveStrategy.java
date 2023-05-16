package WithStrategyPattern.Strategy;

public class SportsDirveStrategy implements DriveStrategy {
    

    @Override
    public void drive() {
        System.out.println("Sports drive capability");
    }
}
