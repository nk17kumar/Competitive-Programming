import java.io.*;

class Test{

	public static void main(String[] args) throws Exception{
		
		BufferedReader out1 = new BufferedReader(new FileReader("output.txt"));
		BufferedReader out2 = new BufferedReader(new FileReader("output1.txt"));
        int flag = 1;
        try{
		while(true)
		{
			String a = out1.readLine();
			if(a.equals(null)) break;
			String b = out2.readLine();
			if(a.equals(b)){}
				else
				{   flag=0;
					System.out.println(" :( Mismatch at :    " + a + "  <-> " +b);
				}

		}
	}
	catch(Exception e)
	{
		if(flag==1)
			System.out.println(" :) All good AC ");
	}

	}
}
