package ObserverPattern.Observable;

import ObserverPattern.Observer.NotificationAlertObserver;

public interface StocksObservable {

    // add or register
    public void add(NotificationAlertObserver observer);
    
    public void remove(NotificationAlertObserver observer);
    
    public void notifySubsribers();
    
    public void setStockCount(int newStockAdded);

    public int getStockCount();

}
