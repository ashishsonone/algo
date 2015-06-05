import java.util.Scanner;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

class S{
    static int sleepTime = 2000;
    public static void main(String[] args){
        System.out.println("here");
        Scanner in = new Scanner(System.in);
        while(true){
            //check name is not an email address
            String name = in.nextLine();
            Pattern p = Pattern.compile(".+@.+\\.[a-z]+");
            Matcher m = p.matcher(name);
            boolean matchFound = m.matches();
            System.out.println("" + matchFound);
        }
    }
}
