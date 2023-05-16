package FantasyGame.Alpha.score;

import FantasyGame.Alpha.portfolio.Portfolio;
import FantasyGame.Alpha.portfolio.PortfolioRepository;
import FantasyGame.Alpha.priceManager.CustomData;
import FantasyGame.Alpha.priceManager.SpotPrices;
import FantasyGame.Alpha.score.Score;
import FantasyGame.Alpha.score.ScoreRepository;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RestController;
import yahoofinance.Stock;
import yahoofinance.YahooFinance;

import java.io.IOException;
import java.math.BigDecimal;
import java.util.List;
import java.util.Map;

@RestController
public class ScoreController {
    private ScoreRepository scoreRepository;
    private final PortfolioRepository portfolioRepository;
    private SpotPrices spotPrices;

    public ScoreController(ScoreRepository scoreRepository, PortfolioRepository portfolioRepository, SpotPrices spotPrices) {
        this.scoreRepository = scoreRepository;
        this.portfolioRepository = portfolioRepository;
        this.spotPrices = spotPrices;
    }


    // get scoreList
    @GetMapping("/scores")
    public List<Score> retrieveScores () {
        return scoreRepository.findAll();
    }

    @GetMapping("/scores/count")
    public Long retrieveTotalEntries() {
        return scoreRepository.count();
    }
    @GetMapping("/scores/orderByPoints")
    public List<Score> retieveScoresByPointsDesc() {
        return scoreRepository.findByOrderByPointsDesc();
    }

    // get scoreById
    @GetMapping("/scores/{id}")
    public Score retrieveScoreById(@PathVariable Long id) {
        return scoreRepository.findById(id).get();
    }

    // get scorelist paginated

//    // get scorelist of first 10
    @GetMapping("/scores/top10")
    public List<Score> retrieveTop10Scores() {
        return scoreRepository.findTop10ByOrderByPointsDesc();
    }

    // get user portfolios rank
    @GetMapping("/scoresByUser/{sid}")
    public String retrieveScoreWithUsers (@PathVariable Long sid) {
        return scoreRepository.findById(sid).toString();
    }

    private Map<String, Stock> latestInstrumentPrices () throws IOException {
        String[] symbols = new String[] {"^NSEI", "^NSEBANK", "^NSEMDCP50", "NIFTYSMLCAP50.NS", "^CNXAUTO", "^CNXFMCG", "^CNXIT", "^CNXMETAL", "^CNXPHARMA", "^CNXREALTY", "^CRSLDX"};
        Map<String, Stock> stocks = YahooFinance.get(symbols);
        return stocks;
    }
    // update scores
    private BigDecimal percentChange (Map<String, Stock> stocks, String id) throws IOException {
        return stocks
                .get(id)
                .getQuote(false)
                .getChangeInPercent()
                .multiply(BigDecimal.valueOf(100));
    }

    @GetMapping("/updatePoints")
    public void UpdateScores() throws IOException {
        Map<String, Stock> stocks = latestInstrumentPrices();

        List<Score> scores = scoreRepository.findAll();
        scores.stream().forEach(score -> {
            Portfolio portfolio = portfolioRepository.findById(score.getPortfolio().getId()).get();
            BigDecimal totalPoints = new BigDecimal(0);

                totalPoints.add(BigDecimal.valueOf(15));
                    try {
                        totalPoints = totalPoints.add(percentChange(stocks,portfolio.getInstrument1())
                                .multiply(BigDecimal.valueOf(portfolio.getBooster1())));

                        totalPoints = totalPoints.add(percentChange(stocks,portfolio.getInstrument2())
                                .multiply(BigDecimal.valueOf(portfolio.getBooster2())));

                        totalPoints = totalPoints.add(percentChange(stocks,portfolio.getInstrument3())
                                .multiply(BigDecimal.valueOf(portfolio.getBooster3())));

                        totalPoints = totalPoints.add(percentChange(stocks,portfolio.getInstrument4())
                                .multiply(BigDecimal.valueOf(portfolio.getBooster4())));
                    } catch (IOException e) {
                        throw new RuntimeException(e);
                    }
                    score.setPoints(totalPoints);
                    scoreRepository.save(score);
                }
        );
    }


}
