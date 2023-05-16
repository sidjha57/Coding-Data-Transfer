package com.springlearn.examples.a0;

import org.springframework.context.annotation.AnnotationConfigApplicationContext;
import org.springframework.context.annotation.ComponentScan;
import org.springframework.context.annotation.Configuration;
import org.springframework.context.annotation.Lazy;
import org.springframework.stereotype.Component;

import java.util.Arrays;

@Component
class ClassA{

}

@Component
@Lazy // It creates bean only when the below class is made to use. Not recommended
class ClassB {
    private ClassA classA;

    public ClassB(ClassA classA) {
        //Logic
        System.out.println("Some Initialization logic goes here");
        this.classA = classA;
    }

    public void doSomething() {
        System.out.println("Did Something");
    }
}

@Configuration
@ComponentScan
public class LazyInitializationLauncherApplication {

    public static void main(String[] args) {

        try (
                var context =
                        new AnnotationConfigApplicationContext
                            (LazyInitializationLauncherApplication.class)) {

                context.getBean(ClassB.class).doSomething();
        }

    }
}
