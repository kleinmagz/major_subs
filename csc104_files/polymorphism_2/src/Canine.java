public class Canine {
    protected int n_legs;
    protected String name;

    public Canine(String name, int n_legs) {
        this.n_legs = n_legs;
        this.name = name;
    }

    public int getLegs() {
        return n_legs;
    }

    public void setLegs(int n) {
        this.n_legs = n;
    }
    // original method
    protected void howl() {
        System.out.println(name + " is howling.");
    }
    // overload of howl
    protected void howl(int x) {
        System.out.println(name + " howled " + x + " times.");
    }

}

class Dog extends Canine {
    protected String breed;

    public Dog(String n, int x, String b) {
        super(n, x);
        this.breed = b;
    }

    public void setBreed(String b) {
        this.breed = b;
    }

    public String getBreed() {
        return this.breed;
    }

    protected void howl() {
        System.out.println(name + " is howling, but mildly");
    }
}