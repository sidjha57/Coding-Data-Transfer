public class Methods_Function {
    static void change (int [] arr) {
        arr[0] = 45;
    }

    void change (int a) {
        a = 60;
    }
    public static void main(String[] args) {

        int x = 95;
        Methods_Function obj = new Methods_Function();

        obj.change(x); // without static we can't access the method we need to create a object
        System.out.println("Integer won't change as it is passed by value "  + x);

        int [] marks = {89, 90, 56};
        change(marks);
        System.out.println("Object is always is passed by reference " + marks[0] );
    }
}
