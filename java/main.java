import java.util.Date;

public class main {
    public static void main(String[] args) {
        Boolean i;
        boolean j;
        i = true;
        j = false;
        System.out.println("hello Jay");
        System.out.println(new Date());
        System.getProperties().list(System.out);
        System.out.println(System.getProperty("user.name"));
        String s = "bc";

        System.out.println(s*2);
        System.out.println(s.length());
        String b = "sdf";
        if (s.length() > 3 || b.length() > 5) {
            System.out.println("ddddddd");
        }
    }
}
