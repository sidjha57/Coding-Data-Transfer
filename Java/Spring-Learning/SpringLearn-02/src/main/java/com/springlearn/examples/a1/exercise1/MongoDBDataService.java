package com.springlearn.examples.a1.exercise1;

import org.springframework.context.annotation.Primary;
import org.springframework.stereotype.Component;

@Primary
@Component
public class MongoDBDataService implements DataService{
    @Override
    public int[] retrieveData() {
        return new int[] {11, 45, 80, 49};
    }
}
