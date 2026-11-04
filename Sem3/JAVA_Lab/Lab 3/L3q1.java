import java.util.*;
import java.io.*;
class Emp{
    String n;
    String id;
    double s;
    public Emp(String n,String id,double s){
        this.n=n;
        this.id=id;
        this.s=s;
    }

    public void disp(){
        System.out.println("Name:"+n+"\nID: "+id+"\nSallary: "+s);
    }

    public double bonus(){
        return s*0.10;
    }
}
class Faculty extends Emp{
    
    String d;
    public Faculty(String n,String id,double s,String d){
        super(n,id,s);
        this.d=d;
    }

    public void disp(){
        super.disp();
        System.out.println("Department: "+ d);
    }
    
    public double bonus(){
        return s*0.20;
    }
}
class Adminstaff extends Emp{

    String des;
    public Adminstaff(String n,String id,double s,String des){
        super(n,id,s);
        this.des=des;
    }

    public void disp(){
        super.disp();
        System.out.println("Designation: "+des);
    }

    public double bonus(){
        return s*0.15;
    }
}

public class L3q1{
  public static void main(String args[]){
    Faculty a =new Faculty("Ishan","a1",24,"cse");
    Adminstaff b=new Adminstaff("Dhanya","s2",23,"admin");
    a.disp();
    System.out.println("The bonus is :"+a.bonus());
    b.disp();
    System.out.println("The bonus is :"+b.bonus());
    Emp c=new Emp("Jeet","3h",290);
    c.disp();
    System.out.println("The bonus is :"+c.bonus());
    }
}