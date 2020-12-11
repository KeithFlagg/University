import java.util.Scanner;
import java.util.Random;

/* Project 3 Book Store Sales Analysis
 * Ryan Rosiak, Keith Flagg, Michael Millemann
 * COSC 117-503
 * ==================================================================================================|
 *  This program will simulate the sale of a book store for a year of 12 months and do some analysis |
 *  on that. Each month record will contain 6 category book sales (Math, CS, Physics, Chemistry,     |
 *  Biology, Geography). The number of books sold in each category for each month is simulated       |
 *  through random number generator and will be processed by the program. The grid of sales will be  |
 *  displayed as well as the highest, lowest, and total of each column and each row. The program     |
 *  will perform sorting in descending order of months and classes by their total book sales. Lastly,|
 *  the program will perform searching based on user input of month and class to find the sale total |
 *  in the grid all the while performing input validation.											 |
 *  =================================================================================================|
 * 11/25/18
 */
public class BookStoreSalesAnalysis {

	public static void findTotalCol(int[][] BookData, int[] ClassTotals) {
		for (int i = 0; i < BookData[0].length; i++) {
			int sum = 0;                                   // Algorithm to find the total of each column for
			for (int j = 0; j < BookData.length; j++) {    // each month by summation then returning value
				sum += BookData[j][i];
			}
			System.out.print(sum +"    ");
			ClassTotals[i] = sum;
		}
		System.out.println();
	}

	public static void findHighestCol(int[][] BookData) {
		for (int i = 0; i < BookData[0].length; i++) {
			int highest = BookData[0][i];					// Algorithm for finding the highest value of each
			for (int j = 0; j < BookData.length; j++) {     // column then returning the highest value
				if (highest < BookData[j][i]) {
					highest = BookData[j][i];
				}
			}
			System.out.print(highest +"    ");
		}
		System.out.println();
	}

	public static void findLowestCol(int[][] BookData) {
		for (int i = 0; i < BookData[0].length; i++) {
			int lowest = BookData[0][i];					// Algorithm for finding the lowest value of each
			for (int j = 0; j < BookData.length; j++) {     // column then returning the lowest value
				if (lowest > BookData[j][i]) {
					lowest = BookData[j][i];
				}
			}
			System.out.print(lowest +"     ");
		}
		System.out.println();
	}

	public static void findTotalRow(int[][] BookData, int num, int[] MonthTotals) {
		int sum = 0;
		for (int i = 0; i < BookData[0].length; i++) {
			sum += BookData[num][i];						// Algorithm for finding the total of each row by
		}													// summation then returning the total
		System.out.print("    "+ sum);
		MonthTotals[num] = sum;
	}

	public static void findHighestRow(int[][] BookData, int num) {
		int highest = BookData[num][0];
		for (int i = 0; i < BookData[0].length; i++) {		// Algorithm for finding the highest of each row
			if (highest < BookData[num][i]) {				// then returning the highest
				highest = BookData[num][i];
			}
		}
		System.out.print("    "+ highest);
	}

	public static void findLowestRow(int[][] BookData, int num) {
		int lowest = BookData[num][0];
		for (int i = 0; i < BookData[0].length; i++) {
			if (lowest > BookData[num][i]) {				// Algorithm for finding the lowest of each row
				lowest = BookData[num][i];					// then returning the lowest
			}
		}
		System.out.print("    "+ lowest);
	}


	public static void selectSort(int[] a, String[] b) {
       int start, minIn, minIn2, minVal;
       String minVal2;
       for (start = 0; start < (a.length - 1); start++) {
    	   minIn = start;					// Algorithm of selection sort sorting month total values and
    	   minVal = a[start];				// class total values in descending order and then switching
    	   									// the month arrays and class arrays to stay parallel with the sort
    	   minIn2 = start;
    	   minVal2 = b[start];
    	   for (int i = start + 1; i < a.length; i++) {
    		   if (a[i] > minVal) {
    			   minVal = a[i];
    			   minIn = i;

    			   minVal2 = b[i];
    			   minIn2 = i;
    		   }
    	   	}
    	   a[minIn] = a[start];
    	   a[start] = minVal;

    	   b[minIn] = b[start];
    	   b[start] = minVal2;
       }
    }


	public static int linearSearch(String a, String[] b) {
		for (int i = 0; i < b.length; i++) {
			if (a.equals(b[i])) {
				return i;					// Linear search algorithm to test to make sure month and class
			}								// user input is valid then returns a valid subscript or returns
		}									// -1 for an invalid input
		return -1;
	}

	public static void main(String[] args) {
		Scanner keyboard = new Scanner(System.in);
		Random rand = new Random();

		// Initialize the Arrays
		String[] Subject = new String[6]; // Array for the subject names
		String[] Month = new String[12]; // Array for the month names
		String[] SubjectOriginal = new String[6]; // Copy of subject array
		String[] MonthOriginal = new String[12]; // Copy of month array
		int[][] BookData = new int[12][6]; // Book Data array
		int[] MonthTotals = new int[12]; // Array for totals for each month
		int[] ClassTotals = new int[6]; // Array for Totals for each class

		// Hard code the month names into month array
		Month[0] = "Jan";
		Month[1] = "Feb";
		Month[2] = "Mar";
		Month[3] = "Apr";
		Month[4] = "May";
		Month[5] = "Jun";
		Month[6] = "Jul";
		Month[7] = "Aug";
		Month[8] = "Sep";
		Month[9] = "Oct";
		Month[10] = "Nov";
		Month[11] = "Dec";

		// Hard code the class names into class array
		Subject[0] = "Math";
		Subject[1] = "CS";
		Subject[2] = "Phys";
		Subject[3] = "Chem";
		Subject[4] = "Bio";
		Subject[5] = "Geo";

		// Copy subject array
		for (int i = 0; i < SubjectOriginal.length; i++) {
			SubjectOriginal[i] = Subject[i];
		}

		// Copy month array
		for (int i = 0; i < MonthOriginal.length; i++) {
			MonthOriginal[i] = Month[i];
		}

		// Assign random integers from 30 to 120 to each subscript in BookData array
		for (int i = 0; i < BookData.length; i++) {
			for (int j = 0; j < BookData[0].length; j++) {
				BookData[i][j] = rand.nextInt(91) + 30;
			}
		}
		// Title screen
		System.out.println("\t\t\t Book Store Sales Analysis");
		System.out.println("Data");
		System.out.print("\t   ");
		for (int i = 0; i < Subject.length; i++) {
			System.out.print(Subject[i] +"    "); // Print subjects in grid across top
		}
		System.out.print("Total    High    Low");

		System.out.println();

		for (int i = 0; i < BookData.length; i++) {
			System.out.print(Month[i]); // Print month in grid in a row going down
			System.out.print("\t    ");
			for (int j = 0; j < BookData[0].length; j++) {
				System.out.printf("%-3d", BookData[i][j]); // Print the array of numbers in grid format
				System.out.print("    ");
			}
			findTotalRow(BookData, i, MonthTotals); // Print out total for each month in row with month
			findHighestRow(BookData, i); // Print out highest for each month in row with month
			findLowestRow(BookData, i); // Print out lowest for each month in row with month
			System.out.println();
		}
		System.out.println();
		System.out.print("Total"+ "\t    ");
		findTotalCol(BookData, ClassTotals); // Print total for each class in column with class
		System.out.print("High"+ "\t    ");
		findHighestCol(BookData); // Print highest for each class in column with class
		System.out.print("Low"+ "\t    ");
		findLowestCol(BookData); // Print lowest for each class in column with class
		System.out.println();

		System.out.println("Sorting in descending order... "); // UI for sorting
		System.out.println();

		selectSort(MonthTotals, Month); // Sort months array and totals for months
		selectSort(ClassTotals, Subject); // Sort class array and totals for classes

		System.out.println("Monthly Sales: \n");
		for (int i = 0; i < MonthTotals.length; i++) {
			System.out.println(Month[i] +"     "+ MonthTotals[i]); // Print out month total array in descending
		}														   // order with corresponding month
		System.out.println();
		System.out.println("Class Sales: \n");
		for (int i = 0; i < ClassTotals.length; i++) {
			System.out.println(Subject[i] +"\t"+ ClassTotals[i]); // Print out class total array in descending
		}														  // order with corresponding class

		String input1, input2;
		int menuChoice, check1, check2;

		System.out.println("\nSearching:\n");
		System.out.println("Would you like to search for a month and class data? (enter a number, -1 to exit)");
		menuChoice = keyboard.nextInt(); // Ask user if they want to search for data and reads input

		while (menuChoice != -1) { // While the user input is not equal to -1, program will keep searching data
			System.out.println("Enter a month and Class:");
			System.out.print("Month: ");
			input1 = keyboard.next(); // Read input from keyboard of month
			System.out.print("Class: ");
			input2 = keyboard.next(); // Read input from keyboard of class

			check1 = linearSearch(input1, MonthOriginal); // Checks for valid month input by searching month
														  // array
			check2 = linearSearch(input2, SubjectOriginal); // Checks for valid class input by searching class
															// array
			if (check1 == -1 || check2 == -1) { // If either search returns -1 than user must re-input valid
												// month and/or class
				System.out.println("Invalid, Month/Class could not be found! Please re-enter and try again!");
			}

			else if (check1 != -1 && check2 != -1) { // When both inputs are valid the program will print out
													 // the corresponding sale value based off searched input
													 // and returned subscripts
				System.out.print("The total sale is: ");
				System.out.print(BookData[check1][check2] +"\n");
				System.out.println("Would you like to search for more data? (enter a number, -1 to exit)");
				menuChoice = keyboard.nextInt(); // User is asked if they want to search again and
												 // program will read user input
			}
		}
		System.out.println("Bye! :)"); // When user finally enters -1 the program terminates and says bye
		keyboard.close();
	}

}
