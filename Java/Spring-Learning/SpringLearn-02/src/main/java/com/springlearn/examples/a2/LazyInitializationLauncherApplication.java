package com.springlearn.examples.a2;

import org.springframework.beans.factory.config.ConfigurableBeanFactory;
import org.springframework.context.annotation.*;
import org.springframework.stereotype.Component;

@Component
class NormalClass {

}

@Component
@Scope(value= ConfigurableBeanFactory.SCOPE_PROTOTYPE)
class PrototypeClass{

}

@Configuration
@ComponentScan
public class LazyInitializationLauncherApplication {

    public static void main(String[] args) {

        try (
                var context =
                        new AnnotationConfigApplicationContext
                            (LazyInitializationLauncherApplication.class)) {
            // The spring returns the same instance of the bean whenever called
            System.out.println(context.getBean(NormalClass.class));
            System.out.println(context.getBean(NormalClass.class));

            // The spring returns different instance of the bean when scope is used
            System.out.println(context.getBean(PrototypeClass.class));
            System.out.println(context.getBean(PrototypeClass.class));
            System.out.println(context.getBean(PrototypeClass.class));
        }

    }
}
