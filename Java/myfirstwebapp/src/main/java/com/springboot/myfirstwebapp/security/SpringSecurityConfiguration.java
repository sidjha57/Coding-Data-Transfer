package com.springboot.myfirstwebapp.security;

import org.springframework.context.annotation.Bean;
import org.springframework.security.config.annotation.web.builders.HttpSecurity;
import org.springframework.security.core.userdetails.User;
import org.springframework.security.core.userdetails.UserDetails;
import org.springframework.security.crypto.bcrypt.BCryptPasswordEncoder;
import org.springframework.security.crypto.password.PasswordEncoder;
import org.springframework.security.provisioning.InMemoryUserDetailsManager;
import org.springframework.security.web.SecurityFilterChain;
import org.springframework.stereotype.Controller;
import static org.springframework.security.config.Customizer.withDefaults;

import java.util.function.Function;

@Controller
public class SpringSecurityConfiguration {
    //LDAP or Database
    //In Memory

//    InMemoryUserDetailsManager
//    InMemoryUserDetailsManager(UserDetails... users)
    @Bean
    public InMemoryUserDetailsManager createUserDetailsManager(){

            UserDetails userDetails1 = createUserDetails("in28mins", "dummy");
            UserDetails userDetails2 = createUserDetails("sid", "smart");
            return new InMemoryUserDetailsManager(userDetails1, userDetails2);
        }

    private UserDetails createUserDetails(String username, String password) {
        Function<String, String> passwordEncoder
                = input -> passwordEncoder().encode(input);
        UserDetails userDetails = User.builder()
                                        .passwordEncoder(passwordEncoder)
                                        .username(username)
                                        .password(password)
                                        .roles("USER", "ADMIN")
                                        .build();
        return userDetails;
    }

    @Bean
    public PasswordEncoder passwordEncoder() {
        return new BCryptPasswordEncoder();
    }

    //ALl URLs are protected
    //A login form is shown for unauthorized requests
    //CSRF diable
    // Frames
    @Bean
    public SecurityFilterChain filterChain(HttpSecurity http) throws Exception {
        http.authorizeHttpRequests(
                auth -> auth.anyRequest().authenticated());
        http.formLogin(withDefaults());

        http.csrf().disable();
        http.headers().frameOptions().disable();

        return http.build();
    }
}
