package com.AOP.learn_aop.dataservice;

import org.springframework.stereotype.Repository;

@Repository
public class DataService1 {

    public int[] retrieveData() {
        return new int[] {11,25, 67, 89};
    }
}
