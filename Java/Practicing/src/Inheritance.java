class base {
    int x;

    public base(int x) {
        this.x = x;
    }

    public base() {}
    public int getX() {
        System.out.println("I am calling base constructor x");
        return x;
    }

    public void setX(int x) {
        System.out.println("I am setting base constructor X to "+ x);
        this.x = x;
    }

}

class derive extends base {
    int y;

    public derive(int x, int y) {
        super(x);
        System.out.println("I am setting derive x and y!");
        this.y = y;
    }

    public int getY() {
        return y;
    }

    public void setY(int y) {
        this.y = y;
    }

    public void display() {
        System.out.println("X = "+ x + " Y = " + y);
    }
}
public class Inheritance {
    public static void main(String[] args) {
        derive d = new derive(45, 67);
        d.display();
    }
}
