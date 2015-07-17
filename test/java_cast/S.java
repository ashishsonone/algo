import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

class S{
    public static void main(String[] args){
        List<Object> l = new ArrayList<Object>();

        l.add(3);
        l.add("5");

        Scanner in = new Scanner(System.in);
        while(true){
            String index = in.nextLine();
            int i = Integer.parseInt(index);
            if(i >= l.size()){
                System.out.println("index out of bounds");
                continue;
            }
            try{
                String x = (String) l.get(i);
                System.out.println("success extracted string=" + x);
            }
            catch(ClassCastException e){
                e.printStackTrace();
                System.out.println("caught the exception successfully");
            }
        }
    }
}
