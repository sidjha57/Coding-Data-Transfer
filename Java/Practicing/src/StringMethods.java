public class StringMethods {
    public static void main (String [] args) {
        String name = "Siddharth";
        int len = name.length();
        System.out.println(len);

        String lstring = name.toLowerCase();
        System.out.println(lstring);

        String ustring = name.toUpperCase();
        System.out.println(ustring);

        String nonTrimString = "      Siddharth ";
        System.out.println(nonTrimString);
        System.out.println(nonTrimString.trim());

        System.out.println(name.substring(1));
        System.out.println(name.substring(1,4));
        System.out.println(name.replace('d', 'j'));
        System.out.println(name.replace('j', 'd'));
    }
}
