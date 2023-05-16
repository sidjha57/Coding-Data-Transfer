package FantasyGame.Alpha.portfolio;

import FantasyGame.Alpha.score.Score;
import FantasyGame.Alpha.user.User;
import com.fasterxml.jackson.annotation.JsonIgnore;
import com.fasterxml.jackson.annotation.JsonIgnoreProperties;
import jakarta.persistence.*;

import java.time.LocalDateTime;

@Entity
public class Portfolio {
    @Id
    @GeneratedValue
    private Long id;
    private String instrument1;
    private Double booster1;
    private String instrument2;
    private Double booster2;
    private String instrument3;
    private Double booster3;
    private String instrument4;
    private Double booster4;

    private String status;





    @ManyToOne(fetch = FetchType.LAZY)
    private User user;

    @OneToOne(mappedBy = "portfolio")
    private Score score;

    public Score getScore() {
        return score;
    }

    public void setScore(Score score) {
        this.score = score;
    }

    public Portfolio() {
    }

    public Long getId() {
        return id;
    }

    public void setId(Long id) {
        this.id = id;
    }

    public String getInstrument1() {
        return instrument1;
    }

    public void setInstrument1(String instrument1) {
        this.instrument1 = instrument1;
    }

    public Double getBooster1() {
        return booster1;
    }

    public void setBooster1(Double booster1) {
        this.booster1 = booster1;
    }

    public String getInstrument2() {
        return instrument2;
    }

    public void setInstrument2(String instrument2) {
        this.instrument2 = instrument2;
    }

    public Double getBooster2() {
        return booster2;
    }

    public void setBooster2(Double booster2) {
        this.booster2 = booster2;
    }

    public String getInstrument3() {
        return instrument3;
    }

    public void setInstrument3(String instrument3) {
        this.instrument3 = instrument3;
    }

    public Double getBooster3() {
        return booster3;
    }

    public void setBooster3(Double booster3) {
        this.booster3 = booster3;
    }

    public String getInstrument4() {
        return instrument4;
    }

    public void setInstrument4(String instrument4) {
        this.instrument4 = instrument4;
    }

    public Double getBooster4() {
        return booster4;
    }

    public void setBooster4(Double booster4) {
        this.booster4 = booster4;
    }

    public String getStatus() {
        return status;
    }

    public void setStatus(String status) {
        this.status = status;
    }

    public User getUser() {
        return user;
    }

    public void setUser(User user) {
        this.user = user;
    }

    @Override
    public String toString() {
        return "Portfolio{" +
                "id=" + id +
                ", instrument1='" + instrument1 + '\'' +
                ", booster1=" + booster1 +
                ", instrument2='" + instrument2 + '\'' +
                ", booster2=" + booster2 +
                ", instrument3='" + instrument3 + '\'' +
                ", booster3=" + booster3 +
                ", instrument4='" + instrument4 + '\'' +
                ", booster4=" + booster4 +
                ", status='" + status + '\'' +
                ", user=" + user +
                ", score=" + score +
                '}';
    }
}
