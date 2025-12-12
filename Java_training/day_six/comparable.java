import java.util.*;

class Sample implements Comparable<Sample> {
    int age;
    String name;

    public Sample(int age, String name) {
        this.age = age;
        this.name = name;
    }

    // overriding the compareTo method
    @Override
    public int compareTo(Sample obj) {
        // In built comparision method of int type -> Integer.compare()
        // return this.age - obj.age; // Ascending order
        return obj.age - this.age;// Descending order
    }

    // overriding the toString method
    // this is only used to display the value instead of the address
    @Override
    public String toString() {
        return age + " " + name;
    }
}

public class comparable {
    public static void main(String[] args) {
        ArrayList<Sample> arr = new ArrayList<>();
        arr.add(new Sample(14, "adhi"));
        arr.add(new Sample(18, "varun"));
        arr.add(new Sample(16, "kr"));
        System.out.println(arr);
        Collections.sort(arr); // needed to call the comparable to sort the values other wise it act as just
                               // display and insertion
        System.out.println(arr);
    }
}
