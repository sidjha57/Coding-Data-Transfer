package com.springlearn.examples.a3;

import jakarta.annotation.PostConstruct;
import jakarta.annotation.PreDestroy;
import org.springframework.context.annotation.AnnotationConfigApplicationContext;
import org.springframework.context.annotation.ComponentScan;
import org.springframework.context.annotation.Configuration;
import org.springframework.context.annotation.Lazy;
import org.springframework.stereotype.Component;

import java.util.Arrays;


@Component
class SomeClass{
    private SomeDependency someDependency;

    public SomeClass(SomeDependency someDependency) {
        System.out.println("All dependencies are ready!");
        this.someDependency = someDependency;
    }

    @PostConstruct
    public void initialize(){
        someDependency.getReady();
    }

    @PreDestroy
    public void cleanup(){
        System.out.println("All variables are cleaned");
    }
}

@Component
class SomeDependency {
    public void getReady(){
        System.out.println("Some logic using SomeDependency");
    }
}


@Configuration
@ComponentScan
public class PrePostAnnotationsContextLauncherApplication {

    public static void main(String[] args) {

        try (
                var context =
                        new AnnotationConfigApplicationContext
                            (PrePostAnnotationsContextLauncherApplication.class)) {
                Arrays.stream(context.getBeanDefinitionNames())
                        .forEach(System.out::println);
        }

    }
}
