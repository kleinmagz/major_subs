import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        Scanner scan = new Scanner(System.in);
        String fullname;
        int age;
        System.out.println("Hello, World!");
        System.out.print("Enter your name: ");
        fullname = scan.nextLine();
        System.out.print("Enter you age: ");
        age = scan.nextInt();

        System.out.println("Hello " + fullname);
        System.out.println("You are " + age + " years old.");
        scan.close();
    }
}
