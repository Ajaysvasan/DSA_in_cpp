package system_design.lld.day_one_for_me;
import java.util.*;
    //       Throwable
    //           /         \
    //      Exception       Error
    //        /    \
    //  (Checked)  RuntimeException
                //   (Unchecked)
// Custom exception 
class InvalidAge extends Exception{
    public InvalidAge(String message){
        super(message);
    }
}
public class exceptionHandling {
    private static int accessElement(int nums[] , int idx) throws IndexOutOfBoundsException {
        if(idx >= nums.length){
            throw new IndexOutOfBoundsException("The index value is not valid. Please enter a valid index");
        }
        return nums[idx];
    }
public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int a = sc.nextInt();
    int b = sc.nextInt();
    int[] nums = {10 , 20 , 30 ,40};
    try{
        int div = a/b;
        System.out.println(div);
        System.out.println(accessElement(nums , 10));
        int age =sc.nextInt();
        if(age < 18){
            throw new InvalidAge("Enter a valid age");
        }
    }catch (ArithmeticException | IndexOutOfBoundsException | InvalidAge e){
        System.err.println(e);
    }
    sc.close();
    return;
}
}