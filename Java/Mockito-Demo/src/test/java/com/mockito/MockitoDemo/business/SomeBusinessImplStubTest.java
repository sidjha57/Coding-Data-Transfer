package com.mockito.MockitoDemo.business;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.assertEquals;

public class SomeBusinessImplStubTest {
    @Test
    void findGreatestFromAllData_basicScenario() {
        DataService dataServiceStub = new DataServiceStub();
        SomeBusinessImpl businessImpl = new SomeBusinessImpl(dataServiceStub);
        int result = businessImpl.findTheGreatestFromAllData();
        assertEquals(25, result);
    }
    @Test
    void findGreatestFromAllData_withOneValue() {
        DataService dataServiceStub = new DataServiceStub2();
        SomeBusinessImpl businessImpl = new SomeBusinessImpl(dataServiceStub);
        int result = businessImpl.findTheGreatestFromAllData();
        assertEquals(35, result);
    }
}

// In case of stubs we need to create multiple stubs for different functionalities
// and even in case if we change DataService interface we will need to implement different class
class DataServiceStub implements DataService {
    @Override
    public int[] retrieveAllData() {
        return new int[] {25, 15, 5};
    }
}

class DataServiceStub2 implements DataService {

    @Override
    public int[] retrieveAllData() {
        return new int[] {35};
    }
}
