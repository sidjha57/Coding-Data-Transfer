class MyEmployees {
    private int id;
    private String name;

    public MyEmployees(int id, String name) {
        this.id = id;
        this.name = name;
    }

    public MyEmployees () {
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }
}
public class Constructors {
    public static void main(String[] args) {
        MyEmployees emp1 = new MyEmployees(100, "Siddharth"), emp2 = new MyEmployees();
        emp2.setId(500);
        emp2.setName("Sejal Rajwade");
        System.out.println(emp1.getName());
        System.out.println(emp2.getName());

    }
}
