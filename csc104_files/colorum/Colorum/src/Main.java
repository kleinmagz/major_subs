public class Main {

    // Static is used so that you can all the methods of a
    // class without instantiating it.

    // private ArrayList<Integer> numbers = new ArrayList<>();
    // private static Scanner scan = new Scanner(System.in);

    public static void populate() {
        int i;
        for (i = 0; i < 10; i++) {
            // numbers.add(i + 1);
        }
    }

    public static void printall() {
        int i;
        for (i = 0; i < 10; i++) {
            // System.out.println(numbers.get(i));

        }
    }

    public static void printT() {
        int i;
        for (i = 0; i < 10; i++) {
            if (i == 0) {
                System.out.println("=================");
                continue;
            }
            System.out.println("\t|");
        }
    }

    public static void main(String[] args) throws Exception {
        Main.printT();
        Person.math();
    }
}
