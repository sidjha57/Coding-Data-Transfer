package com.springlearn.examples.a1.exercise1;

import org.springframework.beans.factory.annotation.Qualifier;
import org.springframework.stereotype.Component;

@Component
@Qualifier("MySQLDataService")
public class MySQLDataService implements DataService{
    @Override
    public int[] retrieveData() {
        return new int[] {98, 123, 56, 89, 199, 250};
    }
}
