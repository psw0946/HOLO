package com.javalec.ex;

import org.springframework.context.support.AbstractApplicationContext;
import org.springframework.context.support.GenericXmlApplicationContext;

public class MainClass {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		String configLocation = "classpath:applicationCTX.xml";
		AbstractApplicationContext ctx = new GenericXmlApplicationContext(configLocation);
		StudentInfo studentInfo = ctx.getBean("studentInfo", StudentInfo.class);
		studentInfo.getStudentInfo();
		
		// constructor가 있는 것은 <constructor-arg>, setter로 하는 것은 <property>
		
		Student student2 = ctx.getBean("student2", Student.class);
		studentInfo.setStudent(student2); // Point... 직접 set해줄 수 있다.
		studentInfo.getStudentInfo();
		
		ctx.close();
	}

}
