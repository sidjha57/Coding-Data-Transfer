public class Varags_Destructing {

    /*

     */
    static int sum (int ...arr) {
        int total = 0;
        for (int a: arr) {
            total += a;
        }
        return total;
    }

    static int sum1 (int x, int ...arr) {
        int total = 0;
        for (int a: arr) {
            total += a;
        }
        return total;
    }
    public static void main(String[] args) {
        System.out.println(sum(1,5,7));
        System.out.println(sum());
//        System.out.println(sum1()); //This won't work as we have made one element to be necessary
        System.out.println(sum(1,4));
    }
}
