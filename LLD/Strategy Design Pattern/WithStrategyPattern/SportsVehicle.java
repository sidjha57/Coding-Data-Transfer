package WithStrategyPattern;

import WithStrategyPattern.Strategy.SportsDirveStrategy;

public class SportsVehicle extends Vehicle{
    
    SportsVehicle() {
        super(new SportsDirveStrategy());
    }
}
