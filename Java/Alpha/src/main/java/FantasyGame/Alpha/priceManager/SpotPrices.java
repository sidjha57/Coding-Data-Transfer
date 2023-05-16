package FantasyGame.Alpha.priceManager;

import FantasyGame.Alpha.instrument.InstrumentRepository;
import com.mysql.cj.conf.ConnectionUrlParser;
import org.springframework.context.annotation.Primary;
import org.springframework.data.util.Pair;
import org.springframework.stereotype.Component;
import yahoofinance.Stock;
import yahoofinance.YahooFinance;
import yahoofinance.quotes.stock.StockQuote;

import java.io.IOException;
import java.math.BigDecimal;
import java.util.*;

@Component
@Primary
public class SpotPrices {
    public CustomData getSpot(String id) {
        Map<String, CustomData> spotChanges = getSpots();

        BigDecimal price = null;
        BigDecimal change = null;
        try {
            price = YahooFinance.get(id).getQuote(false).getPrice();
            change = YahooFinance.get(id).getQuote(false).getChangeInPercent();
            CustomData data = new CustomData(price,change);
            return data;
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    public Map<String,CustomData> getSpots() {
        String[] symbols = new String[] {"^NSEI", "^NSEBANK", "^NSEMDCP50", "NIFTYSMLCAP50.NS", "^CNXAUTO", "^CNXFMCG", "^CNXIT", "^CNXMETAL", "^CNXPHARMA", "^CNXREALTY", "^CRSLDX"};
        try {
            Map<String, Stock> stocks = YahooFinance.get(symbols);
            Map<String, CustomData> spotChange = new HashMap<String, CustomData>() {};
            for (int i=0; i<=10; i++) {
                String id = symbols[i];
                var quote = stocks.get(id).getQuote(false);
                BigDecimal price = quote.getPrice();
                BigDecimal change = quote.getChangeInPercent();
                CustomData data = new CustomData(price, change);
                System.out.println("Loop");
                System.out.println(id);
                System.out.println(data.toString());
                spotChange.put(id, data);
            }

            return spotChange;
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
}
