package FantasyGame.Alpha.priceManager;

import java.math.BigDecimal;

public class CustomData {
    public BigDecimal price;
    public BigDecimal change;

    public BigDecimal getPrice() {
        return price;
    }

    public BigDecimal getChange() {
        return change;
    }

    public CustomData(BigDecimal price, BigDecimal change) {
        this.price = price;
        this.change = change;
    }

    @Override
    public String toString() {
        return "CustomData{" +
                "price=" + price +
                ", change=" + change +
                '}';
    }
}
