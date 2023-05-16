
class NegativeRadiusException extends Exception{
    @Override
    public String toString() {
        return "Radius cannot be negative!";
    }

    @Override
    public String getMessage() {
        return "Radius cannot be negative";
    }
}
public class ThrowVsThrows {

    public static double area(int r) throws NegativeRadiusException{
        if (r < 0) {
            throw new NegativeRadiusException();
        }
        double result = Math.PI * r * r;
        return result;
    }
    public static int divide(int a, int b) throws ArithmeticException {
        return a/b;
    }

    public static void main(String[] args) {
        try{
            System.out.println(divide(6,0));
        } catch (Exception e) {
            System.out.println(e);
        }

        try {
            double ar = area(-6);
        } catch (Exception e){
            System.out.println(e);
        }
    }
}
