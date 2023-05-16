package com.springboot.myfirstwebapp.welcome;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.boot.autoconfigure.neo4j.Neo4jProperties;
import org.springframework.security.core.Authentication;
import org.springframework.security.core.context.SecurityContextHolder;
import org.springframework.stereotype.Controller;
import org.springframework.ui.ModelMap;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.SessionAttributes;

@Controller
@SessionAttributes("name")
public class WelcomeController {
    //    private Logger logger = LoggerFactory.getLogger(getClass());
    @RequestMapping(value="/", method = RequestMethod.GET)
//    public String gotoLoginPage(@RequestParam String name, ModelMap model) {
        public String gotoWelcomePage(ModelMap model) {
          model.put("name", getLoggedInUsername());
//        System.out.println("Request param is " + name); // Not reccommended in production
//        model.put("name", name);
//        logger.debug("Request param is {}", name); // we can use info,warn etc
        return "welcome";
    }

    private String getLoggedInUsername() {
        Authentication authentication =
                SecurityContextHolder.getContext().getAuthentication();
        return authentication.getName();
    }




}
