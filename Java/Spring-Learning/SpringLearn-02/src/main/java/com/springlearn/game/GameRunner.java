package com.springlearn.game;

import org.springframework.beans.factory.annotation.Qualifier;
import org.springframework.stereotype.Component;

@Component
public class GameRunner {

//    private MarioGame game; // GameRunner is tightly coupled with mariogame
    private GamingConsole game; // this is loosely coupled
    public GameRunner(@Qualifier("SuperContraGameQualifier") GamingConsole game){
        this.game = game;
    }


    public void run() {
        System.out.println("Running game: " + game);
        game.up();
        game.down();
        game.left();
        game.right();
    }
}
