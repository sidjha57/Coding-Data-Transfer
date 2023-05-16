package org.example;

import java.util.List;

public class FP01Functional {
    public static void main(String[] args) {
        List<Integer> integers = List.of(12, 16,237, 78, 105, 90);
//        printAllNumbersInListStructured(integers);
//        printEvenNumbersInListStructured(integers);
          printSquaresOfEvenNumbersInListStructured(integers);
    }


    private static void printAllNumbersInListStructured(List<Integer> integers) {
        // What to do?
        integers.stream()
                .forEach(System.out::println); // Method reference
    }

    private static boolean isEven(int number){
        return number%2 == 0;
    }
    private static void printEvenNumbersInListStructured(List<Integer> integers) {
        integers.stream()
                //.filter(FP01Functional::isEven)
                .filter(number -> number%2 == 0) // Lambda Expression
                .forEach(System.out::println);
    }
    private static void printSquaresOfEvenNumbersInListStructured(List<Integer> integers) {
        integers.stream()
                //.filter(FP01Functional::isEven)
                .filter(number -> number%2 == 0) // Lambda Expression
                .map(number -> number*number)
                .forEach(System.out::println);
    }
}