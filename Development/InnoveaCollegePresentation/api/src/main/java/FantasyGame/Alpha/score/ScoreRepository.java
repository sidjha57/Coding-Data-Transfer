package FantasyGame.Alpha.score;

import org.springframework.data.jpa.repository.JpaRepository;

import java.util.List;

public interface ScoreRepository extends JpaRepository<Score, Long> {
    List<Score> findByOrderByPointsDesc();

//    List<Score> findByPortfolioId();
    List<Score> findTop10ByOrderByPointsDesc();
}
