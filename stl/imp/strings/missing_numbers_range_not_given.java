import java.util.HashMap;
import java.util.Map;

public class NumberofDigits {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		String str = "1213141517";
		Map<Integer, Boolean> resultsMap = new HashMap<Integer, Boolean>();
		int startDigit = 0;
		boolean result;
		for (int i = 1; i<;5; i++) {		
			result = identifyFUnction(str,0,i);
			if (result) {
					//System.out.println("The starting number of the string is a "+i+ " digit number");
					startDigit = i;
					resultsMap.put(i, result);
			}	
			resultsMap.put(i, result);
		}
		//System.out.println(resultsMap);	
		findMissingNumber(str,startDigit);
		
	}
	
	public static void findMissingNumber(String str, int startDigit){
		
		int start = Integer.parseInt(str.substring(0, startDigit));
		int nextnumber1 = start + 1;
		int nextnumber2 = start + 2;		
		/*System.out.println(start);
		System.out.println(nextnumber1);
		System.out.println(nextnumber2);
		System.out.println(next);
		System.out.println("---------");*/
		
		if (str.substring(startDigit, str.length()).startsWith(String.valueOf(nextnumber1)) ) {
			findMissingNumber(str.substring(startDigit, str.length()), String.valueOf(nextnumber1).length());
		}
		
		
		else if (str.substring(startDigit, str.length()).startsWith(String.valueOf(nextnumber2)) ) {
			System.out.println("Missing number in the above sequence is " +nextnumber1);
		}
		
		
	}
	
	public static boolean identifyFUnction(String str, int beginIndex, int offSet) {
		
		int start = Integer.parseInt(str.substring(beginIndex, offSet));
		int nextnumber1 = start + 1;
		int nextnumber2 = start + 2;
		
		String str2 = str.substring(offSet, str.length());
		
		if (str2.startsWith(nextnumber1+"") || str2.startsWith(nextnumber2+"")) {
			return true;
		
		}
		else {
			
			return false;
		}
		
	}

}