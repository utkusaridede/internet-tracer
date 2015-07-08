

public static void main(String[] args){ 
	Process process = null;
  BufferedReader input = null; 
  PrintWriter out = null;
  String line = null;

  try { 

   process= Runtime.getRuntime().exec("tcpdump -I -s 256 -i en1"); 
   input = new BufferedReader(new InputStreamReader(process.getInputStream())); 
   out = new PrintWriter(new FileWriter("output2.txt"));

 } catch (IOException e1) { 
  e1.printStackTrace();   
  System.exit(1); 
}

try { 
 while( (line=input.readLine())!=null) {

  int index = line.indexOf("10.11.12.26 >");

  if(index != -1){

                      		   // System.out.println(index);
   System.out.println(line);
                      		   //System.out.println(line.substring(77, 81)); print just the signal
   out.println(line);

 }
}
out.close();

} catch (IOException e1) { 
  e1.printStackTrace();   
  System.exit(0); 
} 
} 
} 