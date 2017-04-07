package Test;

public class StudentList {
	
	String name;
	Integer ID;
	public StudentList(String name, Integer ID){
		this.ID = ID;
		this.name = name;
	}
	
	public String getName(){
		return name;
	}
	
	public Integer getID(){
		return ID;
	}
}
