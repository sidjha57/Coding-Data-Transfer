class Employee {
    int id;
    String name;

    void print() {
        System.out.println(name + " id is " + id);
    }
}
public class Custom_Classes {
    public static void main(String[] args) {
        Employee sid = new Employee();
        sid.id = 1;
        sid.name = "Siddharth Jha";
        sid.print();
    }
}
