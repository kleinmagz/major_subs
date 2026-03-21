import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws Exception {

        // Calculate the area of a rectangle

        double width = 0;
        double height = 0;
        double area = 0;
        Scanner scanner = new Scanner(System.in);
        
        System.out.print("Enter rectangle width: ");
        width = scanner.nextDouble();

        System.out.print("Enter rectangle height: ");
        height = scanner.nextDouble();

        area = width * height;

        System.out.println("The rectangle's area is: " + area + " m^2");
        

        scanner.close();
    }
}
