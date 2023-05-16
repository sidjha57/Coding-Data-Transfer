package com.springlearn.Spring;

import com.springlearn.Spring.game.GameRunner;
import com.springlearn.Spring.game.MarioGame;
import com.springlearn.Spring.game.SuperContraGame;

public class App01GamingBasicJava {
    public static void main(String[] args) {
        var game = new MarioGame();
//        var game = new SuperContraGame(); // 1: Object Creation

        /* In this example we can see that we won't be able to
           run superContraGame due to tight Coupling of GameRunner
           with mario game */

        var gameRunner = new GameRunner(game); // 2: Object Creation + Wiring of Dependencies
        // Game is a Dependency of GameRunner
        gameRunner.run();
    }
}
