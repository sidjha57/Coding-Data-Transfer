package com.alpha.play2earn.SetupInstrumentsUnderCatalog;

import jakarta.persistence.*;

@Entity
@Table(name = "InstrumentsConfig")
public class InstrumentConfig {
    @Id
    @GeneratedValue
    Long id; // Should I take it BigDecimal or long works?

    @Column(name = "_catalogID", nullable = false)
    private String catalogID;


    @Column(name = "_InstrumentName", nullable = false)
    private String instrumentName;


    @Column(name = "_InstrumentSymbol", nullable = false)
    private String instrumentSymbol;



    @Column(name = "_InstrumentUniqueID", nullable = false)
    private String instrumentUniqueID;


    @Column(name = "_catalogID", nullable = false)
    private boolean _isActive = true;

    public InstrumentConfig() {
    }

    public InstrumentConfig(Long id, String catalogID, String instrumentName, String instrumentSymbol, String instrumentUniqueID, boolean _isActive) {
        this.id = id;
        this.catalogID = catalogID;
        this.instrumentName = instrumentName;
        this.instrumentSymbol = instrumentSymbol;
        this.instrumentUniqueID = instrumentUniqueID;
        this._isActive = _isActive;
    }

    public Long getId() {
        return id;
    }

    public void setId(Long id) {
        this.id = id;
    }

    public String getCatalogID() {
        return catalogID;
    }

    public void setCatalogID(String catalogID) {
        this.catalogID = catalogID;
    }

    public String getInstrumentName() {
        return instrumentName;
    }

    public void setInstrumentName(String instrumentName) {
        this.instrumentName = instrumentName;
    }

    public String getInstrumentSymbol() {
        return instrumentSymbol;
    }

    public void setInstrumentSymbol(String instrumentSymbol) {
        this.instrumentSymbol = instrumentSymbol;
    }

    public String getInstrumentUniqueID() {
        return instrumentUniqueID;
    }

    public void setInstrumentUniqueID(String instrumentUniqueID) {
        this.instrumentUniqueID = instrumentUniqueID;
    }

    public boolean is_isActive() {
        return _isActive;
    }

    public void set_isActive(boolean _isActive) {
        this._isActive = _isActive;
    }

    @Override
    public String toString() {
        return "InstrumentConfig{" +
                "id=" + id +
                ", catalogID='" + catalogID + '\'' +
                ", instrumentName='" + instrumentName + '\'' +
                ", instrumentSymbol='" + instrumentSymbol + '\'' +
                ", instrumentUniqueID='" + instrumentUniqueID + '\'' +
                ", _isActive=" + _isActive +
                '}';
    }
}
