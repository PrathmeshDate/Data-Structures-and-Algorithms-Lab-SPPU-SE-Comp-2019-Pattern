import java.util.Scanner;

public class ShellSort
{
	public static void main(String args[])
	{
		int n,j,temp,gap;
		Scanner scan = new Scanner(System.in);
		System.out.println("Enter number of elements:");
		n = scan.nextInt();
		int [] arr = new int[n];
		System.out.println("Enter elements to be sorted.");
		for(int i=0;i<n;i++)
		{
			System.out.println("Enter element "+(i+1)+":");
			arr[i] = scan.nextInt();
		}
		scan.close();
		System.out.println("Elements accepted successfully."+"\n");
		
		System.out.println("Array before sorting:");
		for(int i=0;i<n;i++)
		{
			System.out.println(arr[i]);
		}
		for(gap=n/2;gap>0;gap/=2)
		{
			for(int i = gap;i<n;i++)
			{
				temp = arr[i];
				for(j=i; j>=gap && arr[j-gap]>temp;j=j-gap)
				{
					arr[j]=arr[j-gap];
				}
				arr[j] = temp;
			}
		}
		System.out.println("Array after sorting:");
		for(int i=0;i<n;i++)
		{
			System.out.println(arr[i]);
		}
	}
}