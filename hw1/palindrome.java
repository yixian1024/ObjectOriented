import java.io.*;

public class palindrome{
  public static void main(String args[]) {
          String sentence=String.valueOf(args[0]);
    String reverse = "";
    sentence.replaceAll("[^A-Za-z0-9]","");
     for ( int i = sentence.length() - 1; i >= 0; i-- )
       reverse = reverse + sentence.charAt(i);
        if (sentence.equalsIgnoreCase(reverse))
           System.out.println("Yes");
        else
           System.out.println("No");
  }
}
