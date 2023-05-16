package FantasyGame.Alpha.portfolio;

import FantasyGame.Alpha.ResponseHandler;
import FantasyGame.Alpha.score.Score;
import FantasyGame.Alpha.user.User;
import FantasyGame.Alpha.user.UserRepository;
import org.springframework.http.HttpStatus;
import org.springframework.http.MediaType;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;

import java.util.List;
import java.util.Optional;


@RestController
public class PortfolioController {

    PortfolioRepository portfolioRepository;
    UserRepository userRepository;

    public PortfolioController(PortfolioRepository portfolioRepository, UserRepository userRepository) {
        this.portfolioRepository = portfolioRepository;
        this.userRepository = userRepository;
    }

    @GetMapping("/users/{id}/portfolios")
    public ResponseEntity<Object> retrievePortfoliosByUserId(@PathVariable Long id) {
        try {
            Optional<User> user = userRepository.findById(id);
            if (user.isEmpty())
                 return ResponseHandler.generateResponse("User not found", HttpStatus.MULTI_STATUS, null);

            List<Portfolio> portfolioList = portfolioRepository.findByUser(user.get());
            if (portfolioList.isEmpty())
                return ResponseHandler.generateResponse("User has no portfolios", HttpStatus.MULTI_STATUS, null);

            return ResponseHandler.generateResponse("Succesfully retrieved data!", HttpStatus.OK, portfolioList);

        } catch (Exception e) {
            return ResponseHandler.generateResponse(e.getMessage(),HttpStatus.MULTI_STATUS, null);
        }
    }

    @GetMapping("/users/{id}/portfolios/{status}")
    public ResponseEntity<Object> retrievePortfoliosByStatus(@PathVariable Long id, @PathVariable String status) {
        try {
            System.out.println(status);
            if (status.equals("saved") || status.equals("joined") || status.equals("live") || status.equals("completed")) {

                Optional<User> user = userRepository.findById(id);

                if (user.isEmpty())
                    return ResponseHandler.generateResponse("User not found, check user id", HttpStatus.MULTI_STATUS, null);

                List<Portfolio> portfolioList = portfolioRepository.findByUserAndStatus(user.get(), status);
                if (portfolioList.isEmpty())
                    return ResponseHandler.generateResponse("No portfolios available with the required status", HttpStatus.MULTI_STATUS, null);

                return ResponseHandler.generateResponse("Succesfully retrieved data!", HttpStatus.OK, portfolioList);
            } else {
                return ResponseHandler.generateResponse("Status's can only be saved, joined, live and completed", HttpStatus.MULTI_STATUS, null);
            }



        } catch(Exception e) {
            return ResponseHandler.generateResponse(e.getMessage(),HttpStatus.MULTI_STATUS, null);

        }

    }

    // Get Portfolio by Id
    @GetMapping("/portfolio/{pid}")
//    public Portfolio retrievePortfoliosById(@PathVariable Long pid) {
//        return portfolioRepository.findById(pid).get();
//    }
    public ResponseEntity<Object> retrievePortfoliosById(@PathVariable Long pid) {
        try {
            Optional<Portfolio> portfolio =  portfolioRepository.findById(pid);
            if (portfolio.isEmpty())
                return ResponseHandler.generateResponse("Portfolio not found, check portfolio id", HttpStatus.MULTI_STATUS, null);

            return ResponseHandler.generateResponse("Succesfully retrieved data!", HttpStatus.OK, portfolio);
        } catch (Exception e) {
            return ResponseHandler.generateResponse(e.getMessage(),HttpStatus.MULTI_STATUS, null);
        }
    }

    @GetMapping("/portfolios/{status}")
    public List<Portfolio> retrievePortfoliosByStatus(@PathVariable String status) {
        List<Portfolio> portfolioList = portfolioRepository.findByStatus(status);
        return portfolioList;
    }

    // Create a portfolio (/users/{id}/portfolios/)
    @PostMapping("/users/{id}/portfolios")
    public ResponseEntity<Object> createPortfolioByUserId(@PathVariable Long id, @RequestBody Portfolio portfolio) {

        try {
            Optional<User> user = userRepository.findById(id);

            if (user.isEmpty())
                return ResponseHandler.generateResponse("User not found, check user id", HttpStatus.MULTI_STATUS, null);

            portfolio.setUser(user.get());
            System.out.println("hello");
            System.out.println(portfolio.toString());

            Portfolio newPortfolio = portfolioRepository.save(portfolio);

            return ResponseHandler.generateResponse("Succesfully retrieved data!", HttpStatus.OK, newPortfolio);
        } catch (Exception e) {
            return ResponseHandler.generateResponse(e.getMessage(),HttpStatus.MULTI_STATUS, null);
        }
    }

    @GetMapping("/users/{id}/portfolios/{status}/count")
    public ResponseEntity<Object> retrieveCountOfPortfoliosWithStatusOfUser(@PathVariable Long id, @PathVariable String status) {
        try {
            Long count = portfolioRepository.countByUserIdAndStatus(id, status);
            return ResponseHandler.generateResponse("Succesfully retrieved data!", HttpStatus.OK, count);
        } catch (Exception e) {
            return ResponseHandler.generateResponse(e.getMessage(),HttpStatus.MULTI_STATUS, null);
        }

    }
    // Update a portfolio (/users/{id}/portfolios/{pid})
    @PutMapping(value = "/portfolio/{pid}")
    public ResponseEntity<Object> updatePortfolioByPortfolioId(@PathVariable Long pid,
                                               @RequestBody Portfolio newPortfolio) {
        try {
            Portfolio portfolio = portfolioRepository.findById(pid).get();
            newPortfolio.setUser(portfolio.getUser());
            newPortfolio.setId(pid);
            System.out.println(newPortfolio.toString());
//            System.out.println(newPortfolio.getUser().getId()); // 1
//            System.out.println(portfolioRepository.countByUserIdAndStatus(newPortfolio.getUser().getId(), newPortfolio.getStatus()));

            if (newPortfolio.getStatus().equals("joined") && portfolioRepository.countByUserIdAndStatus(newPortfolio.getUser().getId(), newPortfolio.getStatus()).equals(5L)) {
                return ResponseHandler.generateResponse("You cannot have more than 5 portfolios in joined state",HttpStatus.MULTI_STATUS, null);
            }

            if (newPortfolio.getScore() == null ) {
                newPortfolio.setScore(null);
            } else {
                Score score = newPortfolio.getScore();
                score.setPortfolio(newPortfolio);
                newPortfolio.setScore(score);
            }

            portfolio = portfolioRepository.save(newPortfolio);
            return ResponseHandler.generateResponse("Succesfully retrieved data!", HttpStatus.OK, portfolio);
        } catch (Exception e) {
            return ResponseHandler.generateResponse(e.getMessage(),HttpStatus.MULTI_STATUS, null);
        }

    }


    // Delete a portfolio (/users/{id}/portfolios/{pid})
    @DeleteMapping("/portfolio/{pid}")
    public ResponseEntity<Object> updatePortfolioByPortfolioId(@PathVariable Long pid) {
        try {
            portfolioRepository.deleteById(pid);
            return ResponseHandler.generateResponse("Succesfully retrieved data!", HttpStatus.OK, null);
        } catch (Exception e) {
            return ResponseHandler.generateResponse(e.getMessage(),HttpStatus.MULTI_STATUS, null);
        }
    }






}
