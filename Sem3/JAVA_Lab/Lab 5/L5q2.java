import java.util.Scanner;

class L5q2 {
    Scanner sc = new Scanner(System.in);

    public void getData(){
        try{
            System.out.println("Enter the number you want to check:");
            int i = sc.nextInt();
            check(i);
        }
        catch(NumberFormatException e){
            System.out.println("Number is even exception"+ e.toString());
        }
    }

    public void check(int j) throws NumberFormatException{
        if (j%2 == 0)
            throw new NumberFormatException();
        System.out.println("Number is not even");
    }

    public static void main(String args[]){
        L5q2 obj = new L5q2();
        obj.getData();
    }
}
