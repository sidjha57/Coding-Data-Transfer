package com.springlearn.Spring;

import com.springlearn.Spring.game.GameRunner;
import com.springlearn.Spring.game.GamingConsole;
import com.springlearn.Spring.game.MarioGame;
import org.springframework.context.annotation.AnnotationConfigApplicationContext;

public class App03GamingBasicJava {
    public static void main(String[] args) {

        try (
                var context =
                        new AnnotationConfigApplicationContext
                            (GamingConfiguration.class)) {
            context.getBean(GamingConsole.class).up();
            context.getBean(GameRunner.class).run();
        }

    }
}
