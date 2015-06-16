//static objects as lock
//at any point of time, atmost 1 working(having the WORK_LOCK) and 1 pending(waiting) thread
//INC_LOCK is used to check and increment the count atomically
import java.util.Scanner;

class R{
    static int count = 0;
    final static String inc_lock = "INC_LOCK";
    final static String work_lock = "WORK_LOCK";

    static int sleepTime = 4000;
    public static void main(String[] args){
        System.out.println("Welcome to thread tutorial...");

        Scanner in = new Scanner(System.in);
        while(true){
            final String msg = in.nextLine();
            Runnable r1 = new Runnable() {
              @Override
              public void run(){
                  A.add(sleepTime, msg);
              }
            };
            Thread t1 = new Thread(r1);
            t1.start();
        }
    }
}

class A{
    static void add(int t, String msg){
        synchronized(R.inc_lock){
            System.out.println(msg + ": count=" + R.count);
            if(R.count == 2) {
                System.out.println(msg + ": not needed");
                return;
            }
            R.count++;
            System.out.println(msg + ": attempting to aquire work lock");
        }
        synchronized(R.work_lock){
            System.out.println(msg + ": work started");
            try{
                Thread.sleep(t);
            }
            catch(Exception e){
            }
            System.out.println(msg + ": work ended");
        }
    }

    void remove(int t){
        synchronized(R.inc_lock){
            System.out.println("entering remove()");
            try{
                Thread.sleep(t);
            }
            catch(Exception e){
            }
            System.out.println("leaving remove()");
        }
    }
}
