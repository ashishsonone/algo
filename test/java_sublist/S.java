import java.util.ArrayList;
import java.util.List;

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
    public static void main(String[] args){
        List<Integer> l = new ArrayList<>();
        int limit = 2;
        l.add(0);
        l.add(1);
        l.add(2);
        l.add(3);
        l.add(4);
        l.add(5);
        System.out.println("original :" + l);
        l.subList(0, l.size()-limit).clear(); //subList(from, to) : where : from[inclusive], to[exclusive]
        System.out.println("keeping only last " + limit + " elements : " + l);
    }
}
