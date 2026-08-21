import java.util.*; 
import java.io.*; 

class L1q2 { 
    public static void main(String args[]) { 
        Scanner sc=new Scanner(System.in); 
        int r1,r2,c1,c2; 
        int i,j,k; 

        System.out.println("Enter the r1 and c1 of matrix 1:"); 
        r1=sc.nextInt(); 
        c1=sc.nextInt(); 

        System.out.println("Enter the r2 and c2 of matrix 2:"); 
        r2=sc.nextInt(); 
        c2=sc.nextInt(); 

        int mat1[][]=new int[r1][c1]; 
        int mat2[][]=new int[r2][c2]; 
        int mat3[][]=new int[c1][r2]; 
        if(c1==r2) { 
            System.out.println("Matrix 1 element input:"); 
            for(i=0;i<r1;i++) { 
                for(j=0;j<c1;j++) { 
                    mat1[i][j]=sc.nextInt(); 
                } 
            } 

            System.out.println("Matrix 2 element input:"); 
            for(i=0;i<r2;i++) { 
                for(j=0;j<c2;j++) { 
                    mat2[i][j]=sc.nextInt(); 
                } 
            } 
            for(i=0;i<r1;i++) { 
                for(j=0;j<c2;j++) { 
                    mat3[i][j]=0; 
                    for(k=0;k<c1;k++) 
                        mat3[i][j]=mat3[i][j]+mat1[i][k]*mat2[k][j]; 
                } 
            } 

            System.out.println("Matrix 1"); 
            for(i=0;i<r1;i++) { 
                for(j=0;j<c1;j++) { 
                    System.out.print(mat1[i][j]+" "); 
                } 
                System.out.println(); 
            } 

            System.out.println("\nMatrix 2"); 
            for(i=0;i<r2;i++) { 
                for(j=0;j<c2;j++) { 
                System.out.print(mat2[i][j]+" "); 
                } 
            System.out.println(); 
            } 

            System.out.println("\nMatrix 3"); 
            for(i=0;i<c1;i++) { 
                for(j=0;j<r1;j++) { 
                    System.out.print(mat3[i][j]+"  "); 
                } 
                System.out.println(); 
            } 
        }

        else { 
            System.out.println("Matrix Multiplication not possible"); 
        } 
    System.out.println("Netraa Patel"); 
    System.out.println("25BCP125"); 
    } 
} 