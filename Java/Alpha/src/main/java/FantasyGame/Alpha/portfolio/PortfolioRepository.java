package FantasyGame.Alpha.portfolio;

import FantasyGame.Alpha.user.User;
import org.springframework.data.jpa.repository.JpaRepository;

import java.util.List;

public interface PortfolioRepository extends JpaRepository<Portfolio, Long> {
    List<Portfolio> findByOrderByScorePointsDesc();
    List<Portfolio> findByStatusOrderByScorePointsDesc(String status);
    List<Portfolio> findByUser(User user);

    Long countByUserIdAndStatus(Long id, String status);

    List<Portfolio> findByUserAndStatus(User user, String status);

    List<Portfolio> findByStatus(String status);

}
