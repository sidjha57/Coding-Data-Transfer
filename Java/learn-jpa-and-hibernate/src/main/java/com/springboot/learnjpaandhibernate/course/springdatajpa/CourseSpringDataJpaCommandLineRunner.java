package com.springboot.learnjpaandhibernate.course.springdatajpa;

import com.springboot.learnjpaandhibernate.course.Course;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.CommandLineRunner;
import org.springframework.stereotype.Component;


// This would run each time we run the program
@Component
public class CourseSpringDataJpaCommandLineRunner implements CommandLineRunner {
    @Autowired
    private CourseSpringDataJpaRepository repository;

    @Override
    public void run(String... args) throws Exception {
        repository.save(new Course(1, "Learn AWS Now", "in28mins"));
        repository.save(new Course(2, "Learn Azure Now", "in28mins"));
        repository.save(new Course(3, "Learn GCP Now", "in28mins"));

        repository.deleteById(2l);

        System.out.println(repository.findById(1l));
        System.out.println(repository.findById(3l));

        System.out.println(repository.findAll());
        System.out.println(repository.count());

        System.out.println(repository.findByAuthor("in28mins"));
        System.out.println(repository.findByAuthor(""));
    }
}
