package com.springlearn.examples.a1.exercise1;

import org.springframework.context.annotation.AnnotationConfigApplicationContext;
import org.springframework.context.annotation.ComponentScan;
import org.springframework.context.annotation.Configuration;

import java.util.Arrays;

@Configuration
@ComponentScan
public class RealWorldSpringContextLauncherApplication {
    public static void main(String[] args) {
        try (var dataService =
                new AnnotationConfigApplicationContext
                        (RealWorldSpringContextLauncherApplication.class)){
            Arrays.stream(dataService.getBeanDefinitionNames())
                    .forEach(System.out::println);

            System.out.println(
                    dataService.getBean(BusinessCalculationService.class).findMax());
        }

    }
}
