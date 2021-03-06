import java.io.*;


class Calibrator{

	public static String getOutput(String str){
		String tmp = "Case #";
		StringBuffer ret = new StringBuffer("");
		int i;
	    for(i=5;i<str.length();i++)
			if(str.charAt(i)==':') break;
		for(++i;i<str.length();i++)
			ret.append(str.charAt(i));
		return ret.toString();
	}

	public static int getCaseNumber(String str){
       int ret = 0;
       for(int i=6; str.charAt(i)!=':';i++)
       	 ret = ret*10 + str.charAt(i) - '0';
       return ret;
	} 
}

class Test{


	public static void main(String[] args) throws Exception{
		
		BufferedReader out1 = new BufferedReader(new FileReader("output.txt"));
		BufferedReader out2 = new BufferedReader(new FileReader("output1.txt"));
        int flag = 1;
        int first = 0;
        try{
		while(true)
		{
			String a = out1.readLine();
			if(a.equals(null)) break;
			String b = out2.readLine();
			if(a.equals(b)){}
				else
				{   flag=0;
					if(first == 0){

						first = 1;
						
						int mismatch[] = {32,95,95,32,32,95,95,32,95,95,95,32,95,95,95,95,32,32,95,95,32,32,95,95,32,
							32,32,32,95,32,32,95,95,95,95,95,32,95,95,95,95,32,95,32,32,32,95,32,10,124,32,32,92,47,
							32,32,124,95,32,95,47,32,95,95,95,124,124,32,32,92,47,32,32,124,32,32,47,32,92,124,95,32,
							32,32,95,47,32,95,95,95,124,32,124,32,124,32,124,10,124,32,124,92,47,124,32,124,124,32,
							124,92,95,95,95,32,92,124,32,124,92,47,124,32,124,32,47,32,95,32,92,32,124,32,124,124,32,
							124,32,32,32,124,32,124,95,124,32,124,10,124,32,124,32,32,124,32,124,124,32,124,32,95,95,95,
							41,32,124,32,124,32,32,124,32,124,47,32,95,95,95,32,92,124,32,124,124,32,124,95,95,95,124,32,
							32,95,32,32,124,10,124,95,124,32,32,124,95,124,95,95,95,124,95,95,95,95,47,124,95,124,32,32,
							124,95,47,95,47,32,32,32,92,95,92,95,124,32,92,95,95,95,95,124,95,124,32,124,95,124,10};
					   
					    for(int i=0;i<mismatch.length;i++)
					    	System.out.print((char)mismatch[i]);
					    System.out.println("");

					}
					int testcase = Calibrator.getCaseNumber(a);
					System.out.println("Mismatch :(   " + " @ " + "Case #" + testcase + "   |  " 
						               + Calibrator.getOutput(a) + "   |  " + Calibrator.getOutput(b) );

				}

		}
	}
	catch(Exception e)
	{
		if(flag==1){
			int accepted[] = {
				32,32,32,32,95,32,32,32,32,95,95,95,95,32,95,95,95,95,32,95,95,95,95,95,32,95,95,95,95,32,95,95,95,
				95,95,32,95,95,95,95,95,32,95,95,95,95,32,32,10,32,32,32,47,32,92,32,32,47,32,95,95,95,47,32,95,95,
				95,124,32,95,95,95,95,124,32,32,95,32,92,95,32,32,32,95,124,32,95,95,95,95,124,32,32,95,32,92,32,10,
				32,32,47,32,95,32,92,124,32,124,32,32,124,32,124,32,32,32,124,32,32,95,124,32,124,32,124,95,41,32,124,
				124,32,124,32,124,32,32,95,124,32,124,32,124,32,124,32,124,10,32,47,32,95,95,95,32,92,32,124,95,95,124,
				32,124,95,95,95,124,32,124,95,95,95,124,32,32,95,95,47,32,124,32,124,32,124,32,124,95,95,95,124,32,124,
				95,124,32,124,10,47,95,47,32,32,32,92,95,92,95,95,95,95,92,95,95,95,95,124,95,95,95,95,95,124,95,124,32,
				32,32,32,124,95,124,32,124,95,95,95,95,95,124,95,95,95,95,47,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,
				32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10
			};
			for(int i=0;i<accepted.length;i++){
				System.out.print((char)accepted[i]);
			}

			System.out.println(" :) 100% Match ");
		}
	}

	}
}

class LineTest{


	public static void main(String[] args) throws Exception{
		
		BufferedReader out1 = new BufferedReader(new FileReader("output.txt"));
		BufferedReader out2 = new BufferedReader(new FileReader("output1.txt"));
        int flag = 1;
        int first = 0;
        int testcase = 0;
        try{
		while(true)
		{   testcase++;
			String a = out1.readLine();
			if(a.equals(null)) break;
			String b = out2.readLine();
			if(a.equals(b)){}
				else
				{   flag=0;
					if(first == 0){

						first = 1;
						
						int mismatch[] = {32,95,95,32,32,95,95,32,95,95,95,32,95,95,95,95,32,32,95,95,32,32,95,95,32,
							32,32,32,95,32,32,95,95,95,95,95,32,95,95,95,95,32,95,32,32,32,95,32,10,124,32,32,92,47,
							32,32,124,95,32,95,47,32,95,95,95,124,124,32,32,92,47,32,32,124,32,32,47,32,92,124,95,32,
							32,32,95,47,32,95,95,95,124,32,124,32,124,32,124,10,124,32,124,92,47,124,32,124,124,32,
							124,92,95,95,95,32,92,124,32,124,92,47,124,32,124,32,47,32,95,32,92,32,124,32,124,124,32,
							124,32,32,32,124,32,124,95,124,32,124,10,124,32,124,32,32,124,32,124,124,32,124,32,95,95,95,
							41,32,124,32,124,32,32,124,32,124,47,32,95,95,95,32,92,124,32,124,124,32,124,95,95,95,124,32,
							32,95,32,32,124,10,124,95,124,32,32,124,95,124,95,95,95,124,95,95,95,95,47,124,95,124,32,32,
							124,95,47,95,47,32,32,32,92,95,92,95,124,32,92,95,95,95,95,124,95,124,32,124,95,124,10};
					   
					    for(int i=0;i<mismatch.length;i++)
					    	System.out.print((char)mismatch[i]);
					    System.out.println("");

					}
					System.out.println("Mismatch :(   " + " @ " + "Line #" + testcase + "   |  " 
						               + Calibrator.getOutput(a) + "   |  " + Calibrator.getOutput(b) );

				}

		}
	}
	catch(Exception e)
	{
		if(flag==1){
			int accepted[] = {
				32,32,32,32,95,32,32,32,32,95,95,95,95,32,95,95,95,95,32,95,95,95,95,95,32,95,95,95,95,32,95,95,95,
				95,95,32,95,95,95,95,95,32,95,95,95,95,32,32,10,32,32,32,47,32,92,32,32,47,32,95,95,95,47,32,95,95,
				95,124,32,95,95,95,95,124,32,32,95,32,92,95,32,32,32,95,124,32,95,95,95,95,124,32,32,95,32,92,32,10,
				32,32,47,32,95,32,92,124,32,124,32,32,124,32,124,32,32,32,124,32,32,95,124,32,124,32,124,95,41,32,124,
				124,32,124,32,124,32,32,95,124,32,124,32,124,32,124,32,124,10,32,47,32,95,95,95,32,92,32,124,95,95,124,
				32,124,95,95,95,124,32,124,95,95,95,124,32,32,95,95,47,32,124,32,124,32,124,32,124,95,95,95,124,32,124,
				95,124,32,124,10,47,95,47,32,32,32,92,95,92,95,95,95,95,92,95,95,95,95,124,95,95,95,95,95,124,95,124,32,
				32,32,32,124,95,124,32,124,95,95,95,95,95,124,95,95,95,95,47,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,
				32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10
			};
			for(int i=0;i<accepted.length;i++){
				System.out.print((char)accepted[i]);
			}

			System.out.println(" :) 100% Match ");
		}
	}

	}
}