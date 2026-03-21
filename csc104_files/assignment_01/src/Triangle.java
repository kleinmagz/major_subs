public class Triangle {
    // Fields
    private double height;
    private double length;

    // Methods
    public double getHeight() {
        return height;
    }

    public double getLength() {
        return length;
    }

    public void setHeight(double height) {
        this.height = height;
        System.out.println("Triangle Height set");
    }

    public void setLength(double length) {
        this.length = length;
    }

    public double getArea() {
        return (height * length) / 2;
    }
}
