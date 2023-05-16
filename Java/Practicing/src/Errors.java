import java.util.Scanner;

class BasicErrorHandling {
    int k;
    Scanner sc = new Scanner(System.in);
    public void basicError() {
        System.out.println("Enter number to divide 1000.");
        k = sc.nextInt();
        try {
            System.out.println("Integer part of 1000 divided by k is "+ 1000/k);
        } catch(Exception e) {
            System.out.println("We could not divide. Reason: ");
            System.out.println(e);
        }
        sc.close();
    }
}

class SpecificErrorHandling extends BasicErrorHandling{
    int [] marks = new int[5];
    int idx, number;

    SpecificErrorHandling () {
        marks[0] = 7;
        marks[1] = 45;
        marks[2] = 4;
        marks[3] = 90;
    }
    public void specificError () {
        System.out.println("Enter the array index");
        idx = sc.nextInt();

        System.out.println("Enter the number you want to divide the value with");
        number = sc.nextInt();


        try{
            System.out.println("The value at array index " + idx + " entered is " + marks[idx] );
            System.out.println("Division of " + marks[idx] + " by " + number + " is " + marks[idx]/number );
        } catch (ArithmeticException e){
            System.out.println("ArithmeticException occured!");
            System.out.println(e);
        } catch (ArrayIndexOutOfBoundsException e){
            System.out.println("ArrayIndexOutOfBoundsException occured!");
            System.out.println(e);
        } catch (Exception e){
            System.out.println("Some other exception happened!");
            System.out.println(e);
        }

        sc.close();
    }
}

class NestedErrorHandling extends SpecificErrorHandling{
    public void nestedHandling() {
        System.out.println("Enter the array index");
        idx = sc.nextInt();
        try {
            System.out.println("Welcome to World of Errors");
            try{
                System.out.println(marks[idx]);
            }catch (ArrayIndexOutOfBoundsException e) {
                System.out.println("Exception in level 2");
                System.out.println(e);
            }
        } catch (Exception e) {
            System.out.println("Exception in level 1");
        }
        System.out.println("Done!");
        sc.close();
    }
}
public class Errors {

    public static void main(String[] args) {
        // Runtime Errors
        BasicErrorHandling b = new BasicErrorHandling();
//        b.basicError();
        // Handling specific Errors Seprately
        SpecificErrorHandling s = new SpecificErrorHandling();
//        s.specificError();
        NestedErrorHandling n = new NestedErrorHandling();
        n.nestedHandling();
    }
}
