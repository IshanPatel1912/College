import java.util.*; 
import java.io.*; 

class L1q1 { 
    float arr[]=new float[7]; 
    float avg; 
    
    public void getData() { 
        Scanner sc =new Scanner(System.in); 
        for(int i=0;i<arr.length;i++) { 
            System.out.println("Enter the temp of that day"); 
            arr[i]=sc.nextFloat(); 
        } 
    } 
    
    public void average() { 
        float sum=0; 
        for(int i=0;i<arr.length;i++) { 
            sum+=arr[i]; 
        } 
        avg=sum/7; 
        System.out.println("the average temperature is: "+ avg); 
    } 

    public void temp_count() { 
        int count=0; 
        for(int i=0;i<arr.length;i++) { 
            if(arr[i]>avg) { 
                count++; 
            } 
        } 
        System.out.println("The number of days having greater temperature : "+count); 
    } 
    public void minmax() { 
        float min=arr[0]; 
        float max=arr[0]; 
        for(int i=0;i<arr.length;i++) { 
            if(arr[i]<min) 
                min=arr[i]; 
            if(arr[i]>max) 
                max=arr[i]; 
        } 
        System.out.println("the max temp is: "+max); 
        System.out.println("the min temp is: "+min); 
    } 
    public static void main(String args[]) { 
        L1q1 o=new L1q1(); 
        o.getData(); 
        o.average(); 
        o.temp_count(); 
        o.minmax(); 
        System.out.println("Ishan Patel "+"\n25BCP113");
    }
}
