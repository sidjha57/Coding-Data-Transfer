import javax.management.monitor.MonitorSettingException;

abstract class Pen {
    abstract void write();
    abstract void refill();
}

class FountainPen extends Pen {

    void write() {
        System.out.println("Write");
    }

    void refill() {
        System.out.println("Refill");
    }
    void changeNib() {
        System.out.println("Change the nib");
    }
}

// Problem 3
class Monkey{
    void jump(){
        System.out.println("Jumping...");
    }
    void bite() {
        System.out.println("Biting...");
    }
}

interface BasicAnimal{
    void eat();
    void sleep();
}
class Human extends Monkey implements BasicAnimal{
    void speak(){
        System.out.println("Hello Hello");
    }

    @Override
    public void eat() {
        System.out.println("Eating");
    }

    @Override
    public void sleep() {
        System.out.println("Sleeping");
    }
}
public class AbstractPractice {
    public static void main(String[] args) {
        FountainPen pen = new FountainPen();
        pen.changeNib();
        Human h = new Human();
        h.eat();

        //Q5
        Monkey m = new Human();
        m.bite();
    }
}
