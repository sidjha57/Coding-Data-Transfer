package com.springboot.learnjpaandhibernate.course.springdatajpa;

import com.springboot.learnjpaandhibernate.course.Course;
import org.springframework.data.jpa.repository.JpaRepository;

import java.util.List;

public interface CourseSpringDataJpaRepository extends JpaRepository<Course, Long> {
    // Custom queries
    List<Course> findByAuthor(String author);
}
