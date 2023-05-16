public class FinallyKeyword {
    public static int greet() {
        try{

            int a = 8;
            int b = 0;
            int c = a/b;
            return c;
        }catch(Exception e){
            System.out.println(e);
        } finally{
            // this block always runs
            System.out.println("Cleaning up resources.....This is the end of this function");
        }
        return -1;
    }

    public static void main(String[] args) {
        System.out.println(greet());
        int b = 4,a = 100;
        while(true){
            try{
                System.out.println(a/b);
            } catch (Exception e) {
                System.out.println(e);
                break;
            } finally {
                System.out.println("I am finally value of b = "+b);
            }
            b--;
        }
    }
}
