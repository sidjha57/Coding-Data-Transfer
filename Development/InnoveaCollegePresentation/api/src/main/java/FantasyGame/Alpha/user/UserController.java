package FantasyGame.Alpha.user;

import FantasyGame.Alpha.ResponseHandler;
import FantasyGame.Alpha.portfolio.Portfolio;
import FantasyGame.Alpha.portfolio.PortfolioRepository;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;

import java.util.List;
import java.util.Optional;

@RestController
public class UserController {

    private UserRepository userRepository;
    public UserController(UserRepository userRepository) {
        this.userRepository = userRepository;
    }

    @GetMapping("/verify/user/{phonenum}")
    public ResponseEntity<Object> verifyUser(@PathVariable String phonenum){
        try {
            User user = userRepository.findByPhonenum(phonenum);
            if(user == null)
                return ResponseHandler.generateResponse("You are not authorized",HttpStatus.MULTI_STATUS, null);
            return ResponseHandler.generateResponse("Succesfully retrieved data!", HttpStatus.OK, user);
        } catch (Exception e) {
            return ResponseHandler.generateResponse(e.getMessage(),HttpStatus.MULTI_STATUS, null);
        }
    }
    @GetMapping("/users")
    public List<User> retrieveAllUsers() {
        return userRepository.findAll();
    }

    @GetMapping("/users/{id}")
    public User retrieveUserById(@PathVariable Long id) {
        return userRepository.findById(id).get();
    }

    @PostMapping("/users")
    public ResponseEntity<Object> createUser(@RequestBody User user) {
        try {
            User newUser = userRepository.save(user);
            return ResponseHandler.generateResponse("Succesfully retrieved data!", HttpStatus.OK, newUser);
        } catch (Exception e) {
            return ResponseHandler.generateResponse(e.getMessage(),HttpStatus.MULTI_STATUS, null);
        }
    }

    @DeleteMapping("/users/{id}")
    public void DeleteUserById(@PathVariable Long id) {
        userRepository.deleteById(id);
    }


}
