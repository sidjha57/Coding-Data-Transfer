package WithStrategyPattern;

import WithStrategyPattern.Strategy.SportsDirveStrategy;

public class OffRoadVehicle extends Vehicle{
    
    OffRoadVehicle() {
        super(new SportsDirveStrategy());
    }
}
