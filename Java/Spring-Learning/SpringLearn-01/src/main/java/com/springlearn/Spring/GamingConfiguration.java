package com.springlearn.Spring;

import com.springlearn.Spring.game.GameRunner;
import com.springlearn.Spring.game.GamingConsole;
import com.springlearn.Spring.game.MarioGame;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;

@Configuration
public class GamingConfiguration {

    @Bean
    public GamingConsole game() {
        var game = new MarioGame();
        return game;
    }

    @Bean
    public GameRunner gameRunner(GamingConsole game){
        return new GameRunner(game);
    }


}
