package ObserverPattern;

import ObserverPattern.Observable.IphoneObservableImpl;
import ObserverPattern.Observable.StocksObservable;
import ObserverPattern.Observer.EmailAlertObserverImpl;
import ObserverPattern.Observer.MobileAlertObserverImpl;
import ObserverPattern.Observer.NotificationAlertObserver;

public class Store {

    public static void main(String[] args) {

        StocksObservable iphoneStocksObservable = new IphoneObservableImpl();
        
        NotificationAlertObserver observer1 = new EmailAlertObserverImpl("sidjha987@email.com", iphoneStocksObservable);
        NotificationAlertObserver observer2 = new EmailAlertObserverImpl("sejaljha@email.com", iphoneStocksObservable);
        NotificationAlertObserver observer3 = new MobileAlertObserverImpl("Abha Jha", iphoneStocksObservable);

        iphoneStocksObservable.add(observer1);
        iphoneStocksObservable.add(observer2);
        iphoneStocksObservable.add(observer3);

        // notify will be called as the stock initially was 0
        iphoneStocksObservable.setStockCount(10);
        System.out.println(iphoneStocksObservable.getStockCount());
        iphoneStocksObservable.setStockCount(100);
        iphoneStocksObservable.setStockCount(-110);
        System.out.println(iphoneStocksObservable.getStockCount());
        iphoneStocksObservable.setStockCount(1);
    }
    
}
