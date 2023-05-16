package com.spring.todo;

import org.springframework.data.jpa.repository.JpaRepository;

import java.util.List;

public interface TodoJpaRepository extends JpaRepository<Todo, Integer> {

    List<Todo> findByUsername(String username);
}
