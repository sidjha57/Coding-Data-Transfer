package com.springlearn.Spring.helloworld;

import org.springframework.beans.factory.annotation.Qualifier;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import org.springframework.context.annotation.Primary;


// This automatically creates constructor, getters and setters for us of class Person
record Person (String name, int age, Address address) {};
record Address (String firstLine, String city) {};
@Configuration
public class HelloWorldConfiguration {

    @Bean
    public String name() {
        return  "Ramu";
    }
    @Bean
    public int age() {
        return  56;
    }
    @Bean
    public Person person() {
        return new Person("Sid", 21, new Address("Maharashtra", "Mumbai"));
    }
    @Bean
    public Person person2MethodCall() {
        return new Person(name(), age(), address());
    }

    @Bean
    public Person person3Parameters(String name, int age, Address address2) { // name,age,address2
        return new Person(name, age, address2);
    }
    @Bean
    public Person person4Qualifier(String name, int age,  @Qualifier("address3qualifier") Address address) { // name,age,address3
        return new Person(name, age, address);
    }
    @Bean(name = "address2")
    @Primary
    public Address address() {
        return  new Address("Main Street", "London");
    }
    @Bean(name = "address3")
    @Qualifier("address3qualifier")
    public Address address3() {
        return  new Address("Jane Street", "US");
    }
}
