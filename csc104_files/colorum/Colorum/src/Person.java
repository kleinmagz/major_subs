public class Person {
    int age;
    String name;
    double height;
    double weight;

    public Person( int age, String name, double height, double weight ){
        this.age = age;
        this.name = name;
        this.height = height;
        this.weight = weight;
    }

    public static void math(){
        int random = (int)(Math.random() * 100 ) + 1;
        System.out.println(random);
    }
}
