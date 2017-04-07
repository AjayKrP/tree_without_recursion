package Test;
import java.util.*;

public class Application {
	private static ArrayList<String>bookList;
	private static HashMap<Integer, String>studentList;
	private static LinkedList<StudentList>studentDatabase;
	private static PriorityQueue<String>waitingBooks;
	private static Vector<Integer>countLoginedStudent;
	private static Integer ID;
	private static String name;
	private static String bookName;
	private static Scanner sc;
	private Integer count;
	private Application(){
		sc = new Scanner(System.in);
		bookList = new ArrayList<>();
		studentList = new HashMap<>();
		studentDatabase = new LinkedList<>();
		waitingBooks = new PriorityQueue<>();
		countLoginedStudent = new Vector<Integer>();
		count = 0;
	}
	
	
	private void InsertAllBooks(){
		bookList.add("ADS");
		bookList.add("EG");
		bookList.add("MP");
		bookList.add("MIII");
		bookList.add("PPL");
	}
	
	private void FillNameAndID(){
		System.out.print("Enter your name: ");
		name = sc.next();
		System.out.print("Enter your ID: ");
		ID = sc.nextInt();
	}
	
	private boolean searchBook(String book){
		for(int i = 0; i < bookList.size(); ++i){
			if(bookList.get(i).equals(book)){
				return true;
			}
		}
		return false;
	}
	
	private boolean searchStudent(String name, Integer id){
		Iterator itr = studentDatabase.iterator();
		while(itr.hasNext()){
			StudentList st = (StudentList)itr.next();
			if(st.name.equals(name) && st.ID.equals(id)){
				return true;
			}
		}
		return false;
	}
	
	
	private void issueBook(){
		FillNameAndID();
		if(searchStudent(name, ID)){
		System.out.print("Enter book name: ");
		bookName = sc.next();
		if(searchBook(bookName)){
			studentList.put(ID, bookName);
		}
		else{
			System.out.println("Your book name is added in the queue!!!");
			waitingBooks.add(bookName);
		 }
		}
		else{
			System.out.println("Your details not found!!!");
		}
	}
	
	private void returnBooks(){
		FillNameAndID();
		int p = 0; 
			if(studentList.containsKey(ID)){
				studentList.remove(ID);
				p = 1;
				System.out.println("You hava successfully return book.");
			}
		if(p == 0){
			System.out.println("You didn't issued any books");
		}
	}
	
	private void EnterStudentDetails(){
		FillNameAndID();
		studentDatabase.add(new StudentList(name, ID));
		countLoginedStudent.add(ID);
	}
	
	private void PrintWaitingBookList(){
		Iterator itr = waitingBooks.iterator();
		while(itr.hasNext()){
			System.out.println(itr.next());
		}
	}
	
	private void printAllStudent(){
		Iterator itr = studentDatabase.iterator();
		while(itr.hasNext()){
			StudentList st = (StudentList) itr.next();
			System.out.println("Student name: "+st.name +" and student id: "+st.ID);
		}
	}
	
	private void mainMenu(){
		System.out.println("1.student login");
		System.out.println("2.issue book");
		System.out.println("3.return book");
		System.out.println("4.print all student");
		System.out.println("5.print all waiting books");
		System.out.println("6.Total size of list");
	}
	
	public static void main(String[] args){
		Application app = new Application();
		String ch = "y";
		Integer choice;
		app.InsertAllBooks();
		do{
			app.mainMenu();
			System.out.print("Enter your choice: ");
			choice = sc.nextInt();
			switch(choice){
			case 1:
				app.EnterStudentDetails();
				break;
			case 2:
				app.issueBook();
				break;
			case 3:
				app.returnBooks();
				break;
			case 4:
				app.printAllStudent();
				break;
			case 5:
				app.PrintWaitingBookList();
				break;
			case 6:
				System.out.println("Yotal member of library is: "+countLoginedStudent.size());
				break;
			}
			
			System.out.print("Do you want to continue(y/n)? ");
			ch = sc.next();
		}while(!ch.equals("n"));
	}
	
}
