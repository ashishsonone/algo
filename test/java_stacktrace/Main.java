import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

class Main{
    public static void main(String[] args){
        System.out.println("main() : caller : " + getCaller());
        doIt();
    }

    static void doIt(){
        System.out.println("main.doIt() : caller : " + getCaller());
        A a = new A();
        a.doIt();
    }

    static class A extends Base{
        void doIt(){
            System.out.println("A.doIt() : caller : " + getCaller());
            B b = new B();
            b.doIt();
        }
    }

    static class B extends Base{
        void doIt(){
            System.out.println("B.doIt() : caller : " + getCaller());
        }
    }

    static String getCaller(){
        int INDEX = 3;
        StackTraceElement[] stackTraceElements = Thread.currentThread().getStackTrace();
        if(stackTraceElements.length > INDEX){
            return stackTraceElements[INDEX].getClassName() + ":" + stackTraceElements[INDEX].getMethodName();
        }

        return "NONE";
        /*
        System.out.println("stack-trace start");
        StackTraceElement[] stackTraceElements = Thread.currentThread().getStackTrace();
        for(int i=0; i<stackTraceElements.length; i++){
            System.out.println(stackTraceElements[i].getClassName() + ":" + stackTraceElements[i].getMethodName());
        }
        */
    }
}
