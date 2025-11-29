import java.util.Scanner;


public class Main{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        String s1 =  sc.next();
        String s2 = sc.next();
        String[] arr = {"elephant","tiger","cat","mouse"};

        int a = -1, b = -1;
        for(int i = 0;i<arr.length;i++)
        {
            if(s1.equals(arr[i])){
                a = i;
                break;
            }
        }

        for(int i = 0;i<arr.length;i++)
        {
            if(s2.equals(arr[i]))
            {
                b = i;
                break;
            }
        }
        if((a-b == -1) || (a-b == 3))
        {
            System.out.println("win");
        }else if((a-b == 1) || (a-b == -3))
        {
            System.out.println("lose");;
        }else
        {
            System.out.println("tie");;
        }
        sc.close();
    }
}
