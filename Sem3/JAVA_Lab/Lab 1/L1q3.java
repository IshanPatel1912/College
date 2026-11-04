import java.util.*; 
import java.io.*; 

public class L1q3  { 
    private int f, i;  
    private void setDist(int f, int i) { 
        this.f = f; 
        this.i = i; 
    } 
    private void getDist() { 
        System.out.println("Feet:"+f); 
        System.out.println("Inch: "+ i); 
        System.out.println(); 
    } 
    private L1q3 addDist(L1q3 temp) { 
        L1q3 d3 = new L1q3(); 
        d3.f=f+temp.f; 
        d3.i=i+temp.i; 
        if(d3.i>= 12) 
        { 
            d3.i=d3.i- 12; 
            d3.f++; 
        } 
        return d3; 
    } 

    public String toString() { 
        return "feet:" + f + "Inch:" + i; 
    } 
    public static void main(String[] args) { 
        L1q3 d1 = new L1q3(); 
        d1.setDist(5, 7); 
        d1.getDist(); 
        L1q3 d2 = new L1q3(); 
        d2.setDist(7, 5); 
        d2.getDist(); 
        L1q3 d3 = d1.addDist(d2); 
        d3.getDist(); 
        System.out.println("Netraa Patel"); 
        System.out.println("25BCP125"); 
    } 
} 
