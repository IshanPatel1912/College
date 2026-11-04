import java.io.*; 
import java.util.*; 

class Vehicle { 
    private int num_of_tyre; 
    private int engineno; 
    private String bodycolor; 
    private String RTO_name; 
    private static int vechicle_count = 0; 

    {
        this.RTO_name = "Ahmedabad";
        vechicle_count++;
    }

    public Vehicle(int num_of_tyre, int engineno, String bodycolor) { 
        this.num_of_tyre = num_of_tyre; 
        this.engineno = engineno; 
        this.bodycolor = bodycolor; 
    } 

    public void setRTO(String RTO_name) { 
        this.RTO_name = RTO_name; 
    } 

    public String getRTO() { 
        return this.RTO_name; 
    } 

    public String toString() { 
        return "\nNo. of tyres: " + num_of_tyre + 
               "\nEngine No.: " + engineno + 
               "\nBody color: " + bodycolor + 
               "\nRTO name: " + RTO_name + 
               "\nTill now the objects created are " + vechicle_count; 
    } 
} 

public class L2q2 { 
    public static void main(String args[]) { 
        Vehicle v1 = new Vehicle(4, 4562, "Blue"); 
        System.out.println(v1);
        
        Vehicle v2 = new Vehicle(2, 7891, "Black"); 
        v2.setRTO("Gandhinagar");
        System.out.println(v2);

        Vehicle v3 = new Vehicle(6, 1234, "Red"); 
        System.out.println(v3); 
    } 
}
