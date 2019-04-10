class mythread implements Runnable
{
public void run()
{
for(int i=0;i<=10;i++)
{
System.out.println("child thread");
}}
}
class thread2
{
public static void main(String [] args)
{
mythread t=new mythread();
Thread ob=new Thread(t);
ob.start();
for(int i=1;i<=10;i++)
{
System.out.println("parent thread");
}}
}