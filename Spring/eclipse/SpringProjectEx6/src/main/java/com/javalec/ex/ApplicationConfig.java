package com.javalec.ex;

import java.util.ArrayList;

import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;

@Configuration
// @ImportResource("classpath:applicationCTX.xml") 다음과 같이 XML로 작성한 DI를 자바 파일로 들여올 수 있다.
// 자바 안으로 XML 하든가, XML 안으로 자바 하든가... 둘 중에 하나만 해야함. 그런데 그냥 XML로 작성하는 게 제일 좋은듯.
public class ApplicationConfig {
	
	@Bean
	public Student student1() {
		
		ArrayList<String> hobbys = new ArrayList<String>();
		hobbys.add("수영");
		hobbys.add("요리");
		
		Student student = new Student("홍길동");
		student.setAge(10);
		student.setHobbys(hobbys);
		
		return student;
	}
	
	@Bean
	public Student student2() {
		
		ArrayList<String> hobbys = new ArrayList<String>();
		hobbys.add("독서");
		hobbys.add("음악감상");
		
		Student student = new Student("홍길자");
		student.setAge(5);
		student.setHobbys(hobbys);
		
		return student;
	}
}
