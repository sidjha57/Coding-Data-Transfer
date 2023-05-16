package com.OAuth.learn_oauth;

import org.springframework.security.core.Authentication;
import org.springframework.web.bind.annotation.GetMapping;

public class HelloWorldResource {
    @GetMapping("/")
    public String helloWorld(Authentication authentication) {
        System.out.println(authentication);
        System.out.println(authentication.getPrincipal());
        return "Hello World";
    }
}

