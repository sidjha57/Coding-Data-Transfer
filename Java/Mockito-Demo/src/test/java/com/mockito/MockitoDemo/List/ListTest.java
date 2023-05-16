package com.mockito.MockitoDemo.List;

import org.junit.jupiter.api.Test;
import org.mockito.Mockito;

import java.util.List;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.mockito.Mockito.mock;
import static org.mockito.Mockito.when;

public class ListTest {

    @Test
    void test() {
        List listMock = mock(List.class);

        when(listMock.size()).thenReturn(3);
        assertEquals(3, listMock.size());
    }

    @Test
    void multipleReturns() {
        List listMock = mock(List.class);

        when(listMock.size()).thenReturn(1).thenReturn(2);
        assertEquals(1, listMock.size());
        assertEquals(2, listMock.size());
        assertEquals(3, listMock.size());
        assertEquals(2, listMock.size());
    }

    @Test
    void specificParamters() {
        List listMock = mock(List.class);
        when(listMock.get(0)).thenReturn("SomeString Back").thenReturn(2);
        assertEquals("SomeString Back", listMock.get(0));
        assertEquals(null, listMock.get(1));
    }

    @Test
    void genericParamters() {
        List listMock = mock(List.class);
        when(listMock.get(Mockito.anyInt())).thenReturn("SomeOtherString").thenReturn(2);
        assertEquals("SomeOtherString", listMock.get(0));
        assertEquals("SomeOtherString", listMock.get(1));
    }


}
