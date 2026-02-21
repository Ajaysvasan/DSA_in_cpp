
public class products {
    int product_id;
    String product_name;
    float price;
    long quantity;
    products next;

    public products(int product_id, String product_name, float price, long quantity) {
        this.next = null;
        this.product_id = product_id;
        this.product_name = product_name;
        this.price = price;
        this.quantity = quantity;
    }
}
