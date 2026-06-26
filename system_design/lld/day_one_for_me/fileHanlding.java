package system_design.lld.day_one_for_me;

import java.io.*;

public class fileHanlding {
    public static void main(String[] args) {
        File file = new File("example.txt");
        try {
            // Throws IOException which is needed to be handled
            if (file.createNewFile()) {
                System.out.println("New File created with file Name: " + file.getName());
            }
            // To write in the file
            FileWriter myFile = new FileWriter("example.txt");
            myFile.write("Hello world");
            myFile.close();
            BufferedReader read = new BufferedReader(new FileReader("example.txt"));
            String line;
            while ((line = read.readLine()) != null) {
                System.out.println(line);
            }
            read.close();
        } catch (IOException e) {
            System.out.println(e);
        }
    }
}