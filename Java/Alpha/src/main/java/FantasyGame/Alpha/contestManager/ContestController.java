package FantasyGame.Alpha.contestManager;

import FantasyGame.Alpha.instrument.Instrument;
import FantasyGame.Alpha.portfolio.Portfolio;
import FantasyGame.Alpha.portfolio.PortfolioRepository;
import FantasyGame.Alpha.score.Score;
import FantasyGame.Alpha.score.ScoreRepository;
import FantasyGame.Alpha.user.UserRepository;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RestController;

import java.math.BigDecimal;
import java.util.ArrayList;
import java.util.List;

@RestController
public class ContestController {

    private PortfolioRepository portfolioRepository;
    private ScoreRepository scoreRepository;
    private UserRepository userRepository;

    private String[] symbols = new String[] {"^NSEI", "^NSEBANK", "^NSEMDCP50", "NIFTYSMLCAP50.NS", "^CNXAUTO", "^CNXFMCG", "^CNXIT", "^CNXMETAL", "^CNXPHARMA", "^CNXREALTY", "^CRSLDX"};
    public List<Instrument> prices = new ArrayList<Instrument>();

    public ContestController(PortfolioRepository portfolioRepository, ScoreRepository scoreRepository, UserRepository userRepository) {
        this.portfolioRepository = portfolioRepository;
        this.scoreRepository = scoreRepository;
        this.userRepository = userRepository;
    }



    // move joined portfolios to ranklist and change status to live at start
    @GetMapping("/startContest")
    public void StartContest() {
        List<Portfolio> portfolioList = portfolioRepository.findByStatus("joined");

        portfolioList.stream().forEach(
                portfolio -> {
                    Score newScore = new Score();
                    newScore.setPortfolio(portfolio);
                    newScore.setPoints(BigDecimal.ZERO);
                    scoreRepository.save(newScore);

                    portfolio.setStatus("live");
                    portfolioRepository.save(portfolio);

                }
        );
    }

    @GetMapping("/endContest")
    public void EndContest() {
        List<Portfolio> portfolioList = portfolioRepository.findByStatus("live");
        portfolioList.stream().forEach(
                portfolio -> {
                    portfolio.setStatus("completed");
                    portfolioRepository.save(portfolio);
                }
        );
    }
}
