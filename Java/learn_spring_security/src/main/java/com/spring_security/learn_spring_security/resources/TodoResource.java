package com.spring_security.learn_spring_security.resources;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.web.bind.annotation.*;

import java.util.List;

@RestController
public class TodoResource {

    private Logger logger = LoggerFactory.getLogger(getClass());
    private static final List<Todo> TODOS_LIST =  List.of(new Todo("sid", "Learn AWS"),
            new Todo("sid", "Learn GCP"));
    @GetMapping("/todos")
    public List<Todo> retrieveAllTodos() {
        return TODOS_LIST;
    }

    @GetMapping("/users/{username}/todos")
    public Todo retrieveTodosForSpecificUser (@PathVariable String username) {
        return TODOS_LIST.get(0);
    }

    @PostMapping("/users/{username}/todos")
    public void createTodoForSpecificUser(@PathVariable String username, @RequestBody Todo todo) {
       logger.info("Create {} for {}", todo, username);
//        TODOS_LIST.add(todo);
    }

}

record Todo (String username, String description) {}