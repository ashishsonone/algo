class S{
    static int sleepTime = 2000;
    public static void main(String[] args){
        System.out.println("here");

        Runnable r1 = new Runnable() {
          @Override
          public void run(){
              A a = new A();
              a.add(sleepTime);
          }
        };

        Runnable r2 = new Runnable() {
          @Override
          public void run(){
              A a = new A();
              a.remove(sleepTime);
          }
        };

        Thread t1 = new Thread(r1);
        Thread t2 = new Thread(r2);
        t1.start();
        t2.start();
    }
}

class A{
    void add(int t){
        synchronized(this){
            System.out.println("entering add()");
            try{
                Thread.sleep(t);
            }
            catch(Exception e){
            }
            System.out.println("leaving add()");
        }
    }

    void remove(int t){
        synchronized(A.class){
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
