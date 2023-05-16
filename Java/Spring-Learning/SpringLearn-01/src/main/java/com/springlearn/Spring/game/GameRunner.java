package com.springlearn.Spring.game;

public class GameRunner {

//    private MarioGame game; // GameRunner is tightly coupled with mariogame
    private GamingConsole game; // this is loosely coupled
    public GameRunner(GamingConsole game){
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
