package com.AOP.learn_aop.business;

import com.AOP.learn_aop.dataservice.DataService1;
import org.springframework.stereotype.Component;
import org.springframework.stereotype.Service;

import java.util.Arrays;

@Service
public class BusinessService1 {
    private DataService1 dataService1;

    public BusinessService1(DataService1 dataService1) {
        this.dataService1 = dataService1;
    }

    public int calculateMax() {
        int[] data = dataService1.retrieveData();
        return Arrays.stream(data).max().orElse(0);
    }
}
