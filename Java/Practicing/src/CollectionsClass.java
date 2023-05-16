import java.util.*;

public class CollectionsClass {
    public static void main(String[] args) {
        ArrayList<Integer> l1 = new ArrayList<>();
        ArrayList<Integer> l2 = new ArrayList<>(5);
        l2.add(10);
        l2.add(19);
        l1.add(6);
        l1.add(7);
        l1.add(8);
        l1.add(9);
        l1.add(0, 2);
        l1.addAll(l2);
        for (int x : l1) {
            System.out.println(x);
        }

        System.out.println("Working Directory = " + System.getProperty("user.dir"));

    }
}
