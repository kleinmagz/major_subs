// Name: Klein Timothy A. Magallano
// Section: CSC 104 - AE1
// Topic: Classes, Objects, Setters & Getters, Access Modifiers
// Figures Implemented: Cylinder, Triangle

public class Main {
    public static void main(String[] args) {
        Triangle triangle = new Triangle();
        Cylinder cylinder = new Cylinder();

        triangle.setHeight(12);
        triangle.setLength(27);
        cylinder.setHeight(39);
        cylinder.setRadius(15);

        System.out.println("Figure: Triangle");
        System.out.println("Height: " + triangle.getHeight());
        System.out.println("Length: " + triangle.getLength());
        System.out.println("Area: " + triangle.getArea());
        System.out.println("");

        System.out.println("Figure: Cylinder");
        System.out.println("Height: " + cylinder.getHeight());
        System.out.println("Radius: " + cylinder.getRadius());
        System.out.println("Volume: " + cylinder.getVolume());
    }
}
