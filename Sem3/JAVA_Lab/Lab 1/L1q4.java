import java.util.*; 
import java.io.*; 

public class L1q4 { 
      
    public void circle(double radius){ 
        double area=3.14*radius; 
        System.out.println("The are of rectangle is:"+area); 
    } 
 
    public void rectangle(double length,double breadth){ 
        double area=length*breadth;  
        System.out.println("The are of rectangle is:"+area); 
    } 

    public void square(int s) { 
        int area=s*s; 
        System.out.println("The are of square is:"+area); 
    } 
    public static void main(String args[]) { 
        L1q4 o= new L1q4(); 
        o.square(8); 
        o.rectangle(2.0,4.4); 
        o.circle(3.5); 
        System.out.println("Netraa Patel "+"\n25BCP125"); 
    } 
} 