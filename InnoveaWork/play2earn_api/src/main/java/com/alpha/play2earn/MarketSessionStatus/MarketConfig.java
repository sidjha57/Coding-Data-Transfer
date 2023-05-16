package com.alpha.play2earn.MarketSessionStatus;

import jakarta.persistence.*;

import java.time.LocalDateTime;

@Entity
@Table(name = "MarketConfig")
public class MarketConfig {
    @Id
    @GeneratedValue
    private Long id;

    @Column (name = "_marketType")
    private String marketType;

    @Column (name = "_sessionDateTime", nullable=false)
    private LocalDateTime sessionDateTime = LocalDateTime.now();

    @Column (name = "_marketSessionStatus", nullable = false)
    private String marketSessionStatus;
    @Column (name = "_isMarketExtended", nullable = false)
    private boolean isMarketExtended=false;
    @Column (name = "_isMarketPaused", nullable = false)
    private boolean isMarketPaused=false;

    @Column (name = "_isMarketCancelled", nullable = false)
    private boolean isMarketCancelled=false;

    @Column (name = "_marketSessionStartTime", nullable=false)
    private LocalDateTime marketSessionStartTime = LocalDateTime.now();

    @Column (name = "_marketSessionExtendedTime", nullable=false)
    private LocalDateTime marketSessionExtendedTime = LocalDateTime.now();

    @Column (name = "_marketSessionEndTime", nullable=false)
    private LocalDateTime marketSessionEndTime = LocalDateTime.now();

    public MarketConfig() {
    }

    public Long getId() {
        return id;
    }

    public void setId(Long id) {
        this.id = id;
    }

    public String getMarketType() {
        return marketType;
    }

    public void setMarketType(String marketType) {
        this.marketType = marketType;
    }

    public LocalDateTime getSessionDateTime() {
        return sessionDateTime;
    }

    public void setSessionDateTime(LocalDateTime sessionDateTime) {
        this.sessionDateTime = sessionDateTime;
    }

    public String getMarketSessionStatus() {
        return marketSessionStatus;
    }

    public void setMarketSessionStatus(String marketSessionStatus) {
        this.marketSessionStatus = marketSessionStatus;
    }

    public boolean isMarketExtended() {
        return isMarketExtended;
    }

    public void setMarketExtended(boolean marketExtended) {
        isMarketExtended = marketExtended;
    }

    public boolean isMarketPaused() {
        return isMarketPaused;
    }

    public void setMarketPaused(boolean marketPaused) {
        isMarketPaused = marketPaused;
    }

    public boolean isMarketCancelled() {
        return isMarketCancelled;
    }

    public void setMarketCancelled(boolean marketCancelled) {
        isMarketCancelled = marketCancelled;
    }

    public LocalDateTime getMarketSessionStartTime() {
        return marketSessionStartTime;
    }

    public void setMarketSessionStartTime(LocalDateTime marketSessionStartTime) {
        this.marketSessionStartTime = marketSessionStartTime;
    }

    public LocalDateTime getMarketSessionExtendedTime() {
        return marketSessionExtendedTime;
    }

    public void setMarketSessionExtendedTime(LocalDateTime marketSessionExtendedTime) {
        this.marketSessionExtendedTime = marketSessionExtendedTime;
    }

    public LocalDateTime getMarketSessionEndTime() {
        return marketSessionEndTime;
    }

    public void setMarketSessionEndTime(LocalDateTime marketSessionEndTime) {
        this.marketSessionEndTime = marketSessionEndTime;
    }

    @Override
    public String toString() {
        return "MarketConfig{" +
                "id=" + id +
                ", marketType='" + marketType + '\'' +
                ", sessionDateTime=" + sessionDateTime +
                ", marketSessionStatus='" + marketSessionStatus + '\'' +
                ", isMarketExtended=" + isMarketExtended +
                ", isMarketPaused=" + isMarketPaused +
                ", isMarketCancelled=" + isMarketCancelled +
                ", marketSessionStartTime=" + marketSessionStartTime +
                ", marketSessionExtendedTime=" + marketSessionExtendedTime +
                ", marketSessionEndTime=" + marketSessionEndTime +
                '}';
    }
}
