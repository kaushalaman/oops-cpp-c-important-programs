public class MaxWindowPattern {
	private static String pattenStr1 = "ABCDFGH";
	private static String pattenStr2 = "GHFDCBA";
	private static String reversePatternString = "";
	static {
		reversePatternString = reverseSubStr(pattenStr1);
		System.out.println(reversePatternString);
	}

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		//System.out.println(reverseSubStr(pattenStr1));
		
		System.out.println(binarySearchWindowStr(reversePatternString));
	}

	private static String reverseSubStr(String str) {
		String resString = "";
		StringBuilder sBuilder = new StringBuilder(str);
		sBuilder.reverse();
		resString = sBuilder.toString();
		return resString;
	}

	private static String binarySearchWindowStr(String str) {
    if ("".equals(str)||str==null) {
	 System.out.println("empty string cannot find any window substring!");
	}else if (pattenStr2.contains(str)){
		System.out.println("max windows is "+str.length()+"window String from B is "+str);
	}
    int [][] strArray=new int[str.length()][pattenStr2.length()];
    int lenth=0;
    int end=0;
    char[] strArray1=str.toCharArray();
    char[] strArray2=pattenStr2.toCharArray();
    for (int i = 0; i < str.length(); i++) {
		for (int j = 0; j < pattenStr2.length(); j++) {
			int n =(i-1>;0&&j-1>;0)?strArray[i-1][j-1]:0;
			strArray[i][j]=(strArray1[i]==strArray2[j]?1+n:0);
			if(strArray[i][j]>lenth){
				lenth=strArray[i][j];
				end =i;
			}
		}
	}
    return str.substring(end-lenth+1,end+1);
	}
}