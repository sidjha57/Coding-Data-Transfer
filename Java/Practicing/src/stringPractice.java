import java.util.Scanner;
public class stringPractice {
    public static void main(String[] args) {
        // Problem 3
        String Letter = "Dear <name>, Thanks!";
        System.out.println(Letter.replace("<name>", "Siddharth"));

        // Problem 4
        String myString = "This string containes double  and   triple space";
        System.out.println(myString.indexOf("  "));
        System.out.println(myString.indexOf("   "));
    }
}
