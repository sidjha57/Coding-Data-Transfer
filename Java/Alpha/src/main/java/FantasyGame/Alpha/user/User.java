package FantasyGame.Alpha.user;

import FantasyGame.Alpha.portfolio.Portfolio;
import com.fasterxml.jackson.annotation.JsonIgnore;
import jakarta.persistence.Entity;
import jakarta.persistence.GeneratedValue;
import jakarta.persistence.Id;
import jakarta.persistence.OneToMany;

import java.util.List;

@Entity
public class User {
    @Id
    @GeneratedValue
   private Long id;
   private String name;
   private String phonenum;

   @OneToMany(mappedBy = "user")
   @JsonIgnore
   private List<Portfolio> portfolios;


   public User() {}
    public User(Long id, String name, String phonenum) {
        this.id = id;
        this.name = name;
        this.phonenum = phonenum;
    }

    public Long getId() {
        return id;
    }

    public void setId(Long id) {
        this.id = id;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getphonenum() {
        return phonenum;
    }

    public void setphonenum(String phonenum) {
        this.phonenum = phonenum;
    }

    public List<Portfolio> getPortfolios() {
        return portfolios;
    }

    public void setPortfolios(List<Portfolio> portfolios) {
        this.portfolios = portfolios;
    }

    @Override
    public String toString() {
        return "User{" +
                "id=" + id +
                ", name='" + name + '\'' +
                ", phonenum=" + phonenum +
                '}';
    }
}
