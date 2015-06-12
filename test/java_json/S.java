import java.util.Scanner;
import org.json.JSONException;
import org.json.JSONObject;

/*
 * Download org.json jar from  https://org-json-java.googlecode.com/files/org.json-20120521.jar
 * Compile
 *      javac -cp org.json-20120521.jar S.java
 * Run
 *      java -cp .:org.json-20120521.jar S
/*
 
   { "a" : "A", "b" : "B", "c" : "C"}
   { "b" : "B", "c" : "C"}
*/

class S{
    static int sleepTime = 2000;
    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        while(true){
            String jsonString = in.nextLine();
            try{
                JSONObject json = new JSONObject(jsonString);
                //String a = json.optString("a", null);
                String a = json.getString("a");
                if(a != null){
                    System.out.println(a);
                }
                else{
                    System.out.println("NULL");
                }
            }
            catch(Exception e){
                e.printStackTrace();
            }
        }
    }
}
