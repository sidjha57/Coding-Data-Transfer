package FantasyGame.Alpha.score;

import FantasyGame.Alpha.portfolio.Portfolio;
import com.fasterxml.jackson.annotation.JsonIgnore;
import jakarta.persistence.*;

import java.math.BigDecimal;

@Entity
public class Score {
    @Id
    @GeneratedValue
    private Long id;

    private BigDecimal points;


    @OneToOne(fetch = FetchType.LAZY)
    @JsonIgnore
    private Portfolio portfolio;

    public Score() {}
    public Score(Long id, Portfolio portfolio, BigDecimal points) {
        this.id = id;
        this.portfolio = portfolio;
        this.points = points;
    }

    public Long getId() {
        return id;
    }

    public void setId(Long id) {
        this.id = id;
    }

    public Portfolio getPortfolio() {
        return portfolio;
    }

    public void setPortfolio(Portfolio portfolio) {
        this.portfolio = portfolio;
    }

    public BigDecimal getPoints() {
        return points;
    }

    public void setPoints(BigDecimal points) {
        this.points = points;
    }

    @Override
    public String toString() {
        return "Score{" +
                "id=" + id +
                ", points=" + points +
                ", portfolio=" + portfolio +
                '}';
    }

}
