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
        System.out.println(
            System.getProperty("java.library.path"));
    }
}