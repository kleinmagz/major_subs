public class Cylinder {
    // Fields
    private double height;
    private double radius;

    // Methods
    public double getHeight() {
        return this.height;
    }

    public double getRadius() {
        return this.radius;
    }

    public void setHeight(double height) {
        this.height = height;
        System.out.println("Cylinder Height set");
    }

    public void setRadius(double radius) {
        this.radius = radius;
    }

    public double getVolume() {
        return Math.PI * Math.pow(radius, 2) * height;
    }
}
