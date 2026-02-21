import java.util.*;

public class vending_machine {
    static float current_amount = 0.0f;
    static int current_selected_product;
    static Set<products> refill_Products = new HashSet<>();
    static float change = 0.0f;
    products head;

    vending_machine() {
        head = null;
    }

    // can only be done by admins
    void add_products(int product_id, String product_name, float price, long quantity) {
        products new_prodcut = new products(product_id, product_name, price, quantity);
        if (head == null) {
            head = new_prodcut;
            return;
        }
        products temp = head;
        while (temp.next != null) {
            temp = temp.next;
        }
        temp.next = new_prodcut;
    }

    // on every retrival update the quantity of that product

    void update_product_details(products temp) {
        temp.quantity -= 1;
        if (temp.quantity == 0) {
            refill_Products.add(temp);
        }
    }

    boolean check_money(products product, float entered_amount) {
        current_amount += entered_amount;
        change = (product.price - current_amount);
        if (change == 0) {
            System.out.println("The change: " + change);
            return true;
        }
        return false;
    }
    // if the product that the user is trying to retrieve is 0 then don't display
    // that product

    public void display_products() {
        products temp = head;
        while (temp != null) {
            if (temp.quantity != 0) {
                System.out.println(temp.product_id);
                System.out.println(temp.product_name);
                System.out.println(temp.quantity);
                System.out.println(temp.price);
            }
            temp = temp.next;
        }
    }

    float get_change() {
        return change;
    }

    // displays the product
    // allows the user to select a product through the id
    // once the product is selected asks the user for money
    // if the price of the product and amonunt of money entered doesn't match then
    // ask the user to enter the remaining amount of money
    // once that money is reached tell the user to enjoy the product
    // update the product details
    public void get_products() {
        display_products();
        Scanner sc = new Scanner(System.in);
        int product_id = sc.nextInt();
        float entered_amount = 0;
        products product = head;
        while (product != null && product.price != product_id) {
            product = product.next;
        }
        if (product == null) {
            System.err.println("Invalid product id");
            return;
        }
        System.out.println("You have selected " + product.product_name + " and it costs \n" + product.price);
        System.out.println("Enter the money");
        entered_amount = sc.nextFloat();
        while (!check_money(product, entered_amount)) {
            System.out.println("The enterd amount is insufficient. Enter the remaining amount: " + get_change());
            entered_amount = sc.nextFloat();
        }
        System.out.println("Here you go! Enjoy your bevrage");
        update_details(product);
        display_products();
        sc.close();
    }

    public void update_details(products product) {
        update_product_details(product);

    }

    public void add(boolean is_admin) {
        if (is_admin) {
            Scanner sc = new Scanner(System.in);
            System.out.println("Enter the number of products that you want to add");
            int n = sc.nextInt();
            for (int i = 0; i < n; i++) {
                System.out.println("Enter the values in the following order: id , name , price , quantity");
                add_products(sc.nextInt(), sc.nextLine(), sc.nextFloat(), sc.nextLong());
            }
            sc.close();
        }
    }

    public void refill() {
        System.out.println("The products that are to be refilled are: ");
        for (products product : refill_Products)
            System.out.println(product.product_name + "\n" + product.product_id);

        Scanner sc = new Scanner(System.in);
        while (!refill_Products.isEmpty()) {
            Iterator<products> iterator = refill_Products.iterator();
            products product = iterator.next();
            product.quantity = sc.nextLong();
        }
        sc.close();
    }
}
