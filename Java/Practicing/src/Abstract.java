abstract class Parent2 {
    public Parent2() {
        System.out.println("Mai base2 ka constructor hoon");
    }
    public void sayHello() {
        System.out.println("Hello");
    }
    abstract public void greet();
}

class Child2 extends Parent2{
    @Override
    public void greet() {
        System.out.println("Good Morning");
    }
}

abstract class Child3 extends Parent2{
    public void th() {
        System.out.println("I am good");
    }
}
public class Abstract {
    public static void main(String[] args) {
//        Parent2 p = new Parent2(); // This cannot be performed because Parent2 is a abstract class
        Child2 c = new Child2();
    }
}
