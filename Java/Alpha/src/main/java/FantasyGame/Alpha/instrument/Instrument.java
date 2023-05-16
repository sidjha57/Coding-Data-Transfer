package FantasyGame.Alpha.instrument;

import jakarta.persistence.Entity;
import jakarta.persistence.Id;

import java.math.BigDecimal;

@Entity
public class Instrument {
    @Id
    String id;

    String name;

    BigDecimal price;
    BigDecimal perchange;

    public Instrument() {}

    public Instrument(String id, String name, BigDecimal price, BigDecimal perchange) {
        this.id = id;
        this.name = name;
        this.price = price;
        this.perchange = perchange;
    }

    public BigDecimal getPerchange() {
        return perchange;
    }

    public void setPerchange(BigDecimal perchange) {
        this.perchange = perchange;
    }

    public String getId() {
        return id;
    }

    public void setId(String id) {
        this.id = id;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public BigDecimal getPrice() {
        return price;
    }

    public void setPrice(BigDecimal price) {
        this.price = price;
    }

    @Override
    public String toString() {
        return "Instrument{" +
                "id='" + id + '\'' +
                ", name='" + name + '\'' +
                ", price=" + price +
                ", perchange=" + perchange +
                '}';
    }
}
