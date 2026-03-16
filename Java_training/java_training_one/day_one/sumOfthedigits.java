public class sumOfthedigits {
    public static void main(String[] args) {
        String input = "ab34c16d4hello3@2";
        int sum = 0;
        String checkSum = "";
        for (char ch : input.toCharArray()) {
            if (ch >= 48 || ch <= 57) {
                checkSum += ch;
            } else {
                sum += Integer.parseInt(checkSum);
                checkSum = "";
            }
        }
        if (checkSum != "")
            sum += Integer.parseInt(checkSum);
    }
}
