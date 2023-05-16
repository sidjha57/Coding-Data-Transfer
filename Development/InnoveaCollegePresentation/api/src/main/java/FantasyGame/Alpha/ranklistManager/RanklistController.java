package FantasyGame.Alpha.ranklistManager;


import FantasyGame.Alpha.ResponseHandler;
import FantasyGame.Alpha.portfolio.Portfolio;
import FantasyGame.Alpha.portfolio.PortfolioRepository;

import FantasyGame.Alpha.score.ScoreController;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RestController;


import java.util.List;
import java.util.Optional;


@RestController
public class RanklistController {

    private final PortfolioRepository portfolioRepository;
    private ScoreController scoreController;
    public RanklistController(PortfolioRepository portfolioRepository, ScoreController scoreController) {
        this.portfolioRepository = portfolioRepository;
        this.scoreController = scoreController;
    }

    @GetMapping("/ranks")
    public ResponseEntity<Object> getRankInfo() {
        try {
//            To be uncomented tomorrow
//            scoreController.UpdateScores();

            List<Portfolio>  portfolioList = portfolioRepository.findByStatusOrderByScorePointsDesc("live");
            return ResponseHandler.generateResponse("Succesfully retrieved data!", HttpStatus.OK, portfolioList);
        } catch (Exception e) {
            return ResponseHandler.generateResponse(e.getMessage(),HttpStatus.MULTI_STATUS, null);
        }
    }
}
