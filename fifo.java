package os;

import java.util.Scanner;

public class FIFO {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        System.out.print("Enter the numbr of processes:");
        int n;
        n=sc.nextInt();
        
        double AT[]=new double[n];
        double ET[]=new double[n];
        
        for (int i = 0; i<n ; i++) {
            System.out.print("enter the arrival time for process "+(i+1)+" : ");
            AT[i]=sc.nextDouble();
            System.out.print("enter the brust time of process "+(i+1)+" : ");
            ET[i]=sc.nextDouble();
        }
        
        double CT[]=new double[n];
        CT[0]=AT[0]+ET[0];
        System.out.println("completion time of process 1 is "+CT[0]);
        for (int i = 1; i < n; i++) {
            
            if(AT[i]<=CT[i-1])
            {
                CT[i]=CT[i-1]+ET[i];
            }
            else
            {
                CT[i]=CT[i-1]+AT[i]+ET[i];
            }
            System.out.println("completion time of process "+(i+1)+" is "+CT[i]);
        }
        double TCT=0;
        for (int i = 0; i < n; i++) {
            TCT=TCT+CT[i];
            
        }
        System.out.println("total completion time is : "+TCT);
        
        
        //TURNAROUND TIME
        
        double TAT[]=new double[n];
        
        for (int i = 0; i < n; i++) {
            
            TAT[i]=CT[i]-AT[i];
            System.out.println("turnaround time of process "+(i+1)+" is "+TAT[i]);
        }
        double TTAT=0;
        for (int i = 0; i < n; i++) {
            TTAT=TTAT+TAT[i];
        }
        System.out.println("average turnaround time is "+(TTAT/n));
        
        
        
        
        
        double WT[]=new double[n];
        for (int i = 0; i < n; i++) {
            WT[i]=TAT[i]-ET[i];
            System.out.println("waiting time of process "+(i+1)+" is "+WT[i]);
        }
        double TET=0;
        for (int i = 0; i < n; i++) {
            TET=TET+ET[i];
        }
        System.out.println("average execution time is "+(TET/n));
        
        
        
    }
}