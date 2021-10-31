import java.util.*;

public class SortingAlgorithms {	
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter the vector size: ");
		int size = sc.nextInt();
		System.out.println();
		//Creating vectors
		int[] ordered = createVector("ord", size);
		int[] disordered = createVector("disord", size);
		int[] aleatory = createVector("aleatory", size);
		Random gen = new Random(); // Used in quicksort
		String[] algorithms = {"mergesort", "heapsort", "quicksort", "insertionsort", "bubblesort"};		
		//Results:	
		for(String algorithm: algorithms) {		
			int[] disorderedClone = disordered.clone();
			int[] aleatoryClone = aleatory.clone();
			System.out.println(algorithm + ":");			
			testTime(ordered, "Ordered", algorithm, gen);
			testTime(disorderedClone, "Disordered", algorithm, gen);
			testTime(aleatoryClone, "Aleatory", algorithm, gen);
			System.out.println();
		}
		sc.close();
	}
	
	public static void testTime(int[] vect, String vectorType, String sort, Random gen){
		long start = System.nanoTime();
		boolean stackOverflow = false;
		if(sort.matches("mergesort")) {
			vect = Mergesort.sort(vect, 0, vect.length-1);			
		}else if(sort.matches("bubblesort")) {
			Bubblesort.sort(vect);								
		}else if(sort.matches("heapsort")) {			
			Heap.sort(vect);			
		}else if(sort.matches("insertionsort")) {
			Insertionsort.sort(vect);
		}else if(sort.matches("quicksort")) {		
			try {
				Quicksort.sort(vect, 0, vect.length-1, gen);	
			}catch(StackOverflowError error) {
				stackOverflow = true;
			}
		}
		long end = System.nanoTime();
		double totalTime =(end-start)/1000000;
		if(stackOverflow){
			System.out.print("(StackOverflow)");
		}
		if(checkOrder(vect)) {
			System.out.printf("%s: %.2fms\n", vectorType, totalTime);	
		}else {
			System.out.println("Failed to order");
		}
	}
	
	public static int[] createVector(String type, int size) {
		Random generator = new Random();		
		int[] vect = new int[size];
		for(int i=1; i<=size; i++) {
			if(type=="ord") {
				vect[i-1] = i;
			}else if(type=="disord") {
				vect[size-i] = i;
			}else {
				vect[i-1] = generator.nextInt(1000);
			}		
		}
		return vect;		
	}
	
	public static boolean checkOrder(int[] vect) {
		for(int i=0; i<vect.length-1; i++) {
			if(vect[i] > vect[i+1]) {
				return false;
			}
		}
		return true;
	}
	
	
	//mergesort
	public static class Mergesort{
		public static int[] merge(int[] vect1, int[] vect2) {
			int finalLength = vect1.length + vect2.length;
			int[] result = new int[finalLength];
			int i=0, j=0, indexRes=0; // i -> vect1, j -> vect2, indexRes -> result
			while(indexRes < finalLength) {
				if(j >= vect2.length || (i < vect1.length && vect1[i] < vect2[j])) {
					result[indexRes] = vect1[i];
					i += 1;			
				}else {
					result[indexRes] = vect2[j];
					j += 1;
				}
				indexRes += 1;
			}
			return result;		
		}
		public static int[] sort(int[] vect, int start, int end) {
			if(end>start) {
				int mid = (end+start)/2;
				int[] leftSide = sort(vect, start, mid);
				int[] rightSide = sort(vect, mid+1, end);
				return merge(leftSide, rightSide);
			}else {			
				return new int[]{vect[start]};
			}
		}
	}
	
	
	//heapsort
	public static class Heap{ 	
		private static void buildHeap(int[] vect) {			
			for(int i = vect.length/2 -1; i >= 0; i--) {			
				maxHeapify(vect, i, vect.length-1);
			}
		}		
		private static void maxHeapify(int[] vect, int index, int limit) { 			
			int max = index;		
			int left = index*2;
			int right = index*2+1;			
			if(left <= limit && vect[left] > vect[max]) {
				max = left;
			}
			if(right <= limit && vect[right] > vect[max]) {
				max = right;
			}
			if(max != index) {
				int num = vect[index];
				vect[index] = vect[max];
				vect[max] = num;
				maxHeapify(vect, max, limit);
			}
		}
		public static void sort(int[] vect) {
			buildHeap(vect);			
			for(int limit = vect.length-1; limit > 0; limit--) {			
				maxHeapify(vect, 0, limit);
				int num = vect[0];
				vect[0] = vect[limit];
				vect[limit] = num;				
			}			
		}
	}
	
	//quicksort
	public static class Quicksort{
		public static int split(int[] vect, int start, int end, Random gen) {		
			int randomPos = gen.nextInt(end+1-start) + start;
			int comparator = vect[randomPos];
			vect[randomPos] = vect[end];
			vect[end] = comparator;		
			int left = start, right = end; 
			boolean turnLeft = true;
			boolean stopAll = false;
			
			while(!stopAll && left < right) {
				if(turnLeft){
					while(vect[left] < comparator) {
						left += 1;
						if(left == right) {
							stopAll = true;
							break;
						}
					}
					if(!stopAll) {
						vect[right] = vect[left];
						right -= 1;					
						turnLeft = false;
					}				
				}else {
					while(vect[right] > comparator){
						right -= 1;
						if(right == left) {
							stopAll = true;
							break;
						}
					}
					if(!stopAll) {
						vect[left] = vect[right];					
						left += 1;
						turnLeft = true;
					}			
				}	
			}		
			vect[right] = comparator;
			return right;
		}
		public static void sort(int[] vect, int start, int end, Random gen) {		
			if(end>start) {
				int mid = split(vect, start, end, gen);			
				sort(vect, start, mid-1, gen);
				sort(vect, mid+1, end, gen);				
			}
		}
	}
	
	
	//insertionsort
	public static class Insertionsort{
		public static void sort(int[] vect) {			
			for(int i=1; i<vect.length; i++) {
				putInOrder(vect, i, 0, i-1);
			}			
		}
		public static void putInOrder(int[] vect, int index, int start, int end) {
			if(end-start > 0) {				
				int mid = (end+start)/2;
				if(vect[index] < vect[mid]) {
					putInOrder(vect, index, start, mid-1);
				}else {
					putInOrder(vect, index, mid+1, end);
				}
			}else if(start+1 < index){
				int pos = start;
				if(vect[index] > vect[start]) {
					pos++;
				}
				int saved = vect[pos];
				vect[pos] = vect[index];
				while(pos < index) {
					pos++;
					int nextSaved = vect[pos];
					vect[pos] = saved;
					saved = nextSaved;
				}
			}else if(start+1 == index && vect[index] < vect[start]) {
				int num = vect[start];
				vect[start] = vect[index];
				vect[index] = num;
			}
				
					
				
			}			
		
	}
	
		
	//bubblesort
	public static class Bubblesort{
		public static void sort(int[] vect) {
			boolean ordained;
			do{
				ordained = true;
				for(int i=0; i<vect.length-1; i++) {
					if(vect[i] > vect[i+1]){
						int num = vect[i+1];
						vect[i+1] = vect[i];
						vect[i] = num;
						ordained = false;
					}
				}
			}while(!ordained);
		}
	}
}
