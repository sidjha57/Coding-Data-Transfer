package FantasyGame.Alpha.instrument;

import FantasyGame.Alpha.priceManager.CustomData;
import FantasyGame.Alpha.priceManager.SpotPrices;
import org.springframework.web.bind.annotation.*;

import java.io.IOException;
import java.math.BigDecimal;
import java.util.List;
import java.util.Map;

import static org.springframework.data.jpa.domain.AbstractPersistable_.id;

@RestController
public class InstrumentController {
    private InstrumentRepository instrumentRepository;
    private SpotPrices spotPrices;

    public InstrumentController(InstrumentRepository instrumentRepository, SpotPrices spotPrices) {
        this.instrumentRepository = instrumentRepository;
        this.spotPrices = spotPrices;
    }


    @GetMapping("/instruments")
    public List<Instrument> retrieveInstruments() {
        return instrumentRepository.findAll();
    }
//
    @GetMapping("/instruments/{symbol}")
    public Instrument retrieveInstrument(@PathVariable String symbol) {
        return (Instrument) instrumentRepository.findById(symbol).get();
    }

    @PostMapping("/instruments")
    public Instrument createInstrument(@RequestBody Instrument instrument) {
        return (Instrument) instrumentRepository.save(instrument);
    }

//    @DeleteMapping("/instruments/{id}")
//    public void DeleteInstrumentById(@PathVariable Long id) {
//        instrumentRepository.deleteById(id);
//    }

    public Instrument updateInstrument(CustomData data, String symbol) {
        System.out.println(symbol);
        System.out.println(data);

        BigDecimal price = data.getPrice();
        BigDecimal change = data.getChange();
        Instrument instrument = instrumentRepository.findById(symbol).get();
//        instrument.setPrice(price);
        instrument.setPerchange(change);

        instrumentRepository.save(instrument);
        return instrument;

    }
    @GetMapping("/instruments/updatePrice/{symbol}")
    public Instrument UpdateInstrumentById (@PathVariable String symbol) throws IOException {
        CustomData data = spotPrices.getSpot(symbol);
        return updateInstrument(data,symbol);
    }

    @GetMapping("/instruments/updateAllPrices")
    public List<Instrument> UpdateAllInstrumentPrices() {
        Map<String, CustomData> spots = spotPrices.getSpots();
        List<Instrument> instruments = instrumentRepository.findAll();
        instruments.stream()
                .forEach(instrument ->
                        updateInstrument(spots.get(instrument.getId()),instrument.getId())
                );
        return instruments;
    }

}
