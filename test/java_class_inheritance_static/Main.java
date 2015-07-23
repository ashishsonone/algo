import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

class Main{
    public static void main(String[] args){
        A a = new A();
        B b = new B();
        a.onResume();
        b.onPause();
        System.out.println("a=" + a.isVisible + ", b=" + b.isVisible);
    }

    static class A extends Base{
    }

    static class B extends Base{
    }
}
