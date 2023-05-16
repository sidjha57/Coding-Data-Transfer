package com.springboot.learnjpaandhibernate.course.jdbc;

import com.springboot.learnjpaandhibernate.course.Course;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.CommandLineRunner;
import org.springframework.stereotype.Component;


// This would run each time we run the program
@Component
public class CourseJdbcCommandLineRunner implements CommandLineRunner {
    @Autowired
    private CourseJdbcRepository repository;

    @Override
    public void run(String... args) throws Exception {
        repository.insert(new Course(1, "Learn AWS Now", "in28mins"));
        repository.insert(new Course(2, "Learn Azure Now", "in28mins"));
        repository.insert(new Course(3, "Learn GCP Now", "in28mins"));

        repository.deleteById(2);

        System.out.println(repository.findById(1));
        System.out.println(repository.findById(3));
    }
}
