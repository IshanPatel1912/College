import java.util.Scanner;

class L5q1{
    public static void main(String args[]){
        int arr[] = new int[5];
        int i,j,r;
        Scanner sc = new Scanner(System.in);
        try{
            System.out.println("Enter elements into the array:");
            for(i=0;i<5;i++){
                arr[i] = sc.nextInt();
            }
            System.out.println("Enter 2 index number of which two number you want to devide:");
            i = sc.nextInt();
            j = sc.nextInt();
            r = arr[i]/arr[j];
            System.out.println("Divison result:"+r);
        }
        catch(ArrayIndexOutOfBoundsException e){
            System.out.println("Array Index out of bound exception"+ e.toString());
        }
        catch(ArithmeticException e){
            System.out.println("Arithmetic exception"+ e.toString());
        }
    }
}