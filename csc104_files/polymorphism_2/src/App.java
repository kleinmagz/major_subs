import java.util.Scanner;

public class App {
    public static void main(String[] args) throws Exception {
        System.out.println("Hello, World!");
        Canine c = new Canine("Caesar", 4);
        Scanner sc = new Scanner(System.in);
        Dog d = new Dog("Brian", 4, "Mixed");
        c.howl();
        System.out.print("Enter n: ");
        int n = sc.nextInt();
        c.howl(n);
        d.howl();

        sc.close();
    }
}
