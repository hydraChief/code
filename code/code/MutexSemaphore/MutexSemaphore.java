// package MutexSemaphore;
import java.util.Scanner;
import java.util.concurrent.Semaphore;


public class MutexSemaphore {
    static Semaphore readlock=new Semaphore(1);
    static Semaphore writelock=new Semaphore(1);
    static int readcnt=0;
    static class Read implements Runnable{
        @Override
        public void run(){
            try{
            readlock.acquire();
            readcnt++;
            if(readcnt==1){
                writelock.acquire();
            }
            readlock.release();

            System.out.println("Thread" + Thread.currentThread().getName()+"is reading ....");
            Thread.sleep(1000);
            System.out.println("Thread"+Thread.currentThread().getName()+"has finished");

            readlock.acquire();readcnt--;
            if(readcnt==0){
                writelock.release();
            }
            readlock.release();
        }
        catch (InterruptedException e) {
            System.out.println(e.getMessage());
        }
    }
}
    
    static class Write implements Runnable{

        @Override
        public void run(){
            try{
            writelock.acquire();
            System.out.println("Thread "+ Thread.currentThread().getName()+"is writing");
            Thread.sleep(1000);
            System.out.println("Thread "+Thread.currentThread().getName()+"has finished");
            writelock.release();
            }
            catch(InterruptedException e){
                System.out.println(e.getMessage());
            }
    }
}

    public static void main(String[]args){
        Read read=new Read();
        Write write=new Write();
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter Input Size");
        int n=sc.nextInt();
        Thread p[]=new Thread[n];
        int seq[]=new int[n];
        for(int i=0;i<n;i++){
            seq[i]=sc.nextInt();
        }

        for(int i=0;i<n;i++){
            if(seq[i]==1){
                p[i]=new Thread(read);
                p[i].setName("Thread"+(i+1));
            }else{
                p[i]=new Thread(write);
                p[i].setName("Thread"+(i+1));
            }
        }

        for(int i=0;i<n;i++){
            p[i].start();
        }

        sc.close();
    }
}