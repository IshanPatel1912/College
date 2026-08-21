import java.io.*;
import java.util.*;

class Hotel{
    private int registerID;
    private String guestName;
    private int roomNo;
    private double billAmount;

    public static int availableRooms=50;
    public static int nextRoomNumber=101;

    public Hotel(int registerID, String guestName){
        this.registerID=registerID;
        this.guestName=guestName;
        if (availableRooms>0){
            this.roomNo=nextRoomNumber;
            nextRoomNumber++;
            availableRooms--;
            System.out.println("Room " + this.roomNo + " successfully allocated to " + this.guestName);
        }
        else{
            this.roomNo = -1;
            System.out.println("No rooms  available");
        }
    }

    public void calculateBill(int days) {
        int standardRate = 1500;
        this.billAmount = days * standardRate; 
    }

    public void calculateBill(int days, int dailyRate) {
        this.billAmount = days * dailyRate; 
    }

    public void displayGuest() {
        if (this.roomNo != -1) {
            System.out.println("Reg ID: " + registerID + " | Name: " + guestName + 
                               " | Room: " + roomNo + " | Total Bill: Rs. " + billAmount);
        }
    }
}
public class Bookingsystem {
    public static void main(String[] args) {
        System.out.println("Initial Available Rooms: " + Hotel.availableRooms + "\n");

        Hotel guest1 = new Hotel(5001, "Jeet");
        guest1.calculateBill(3); 

        Hotel guest2 = new Hotel(5002, "Aakarshan");
        guest2.calculateBill(2, 2500); 

        System.out.println("\n--- Guest Details ---");
        guest1.displayGuest();
        guest2.displayGuest();

        System.out.println("\nRemaining Available Rooms: " + Hotel.availableRooms);
    }
}
