package com.javalec.ex;

import org.springframework.context.support.GenericXmlApplicationContext;

public class MainClass {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		GenericXmlApplicationContext ctx = new GenericXmlApplicationContext();
		
		ctx.load("classpath:applicationCTX.xml");
		
		ctx.refresh(); // 여기서 초기화가 발생
		
		ctx.close(); // 컨테이너 소멸과 함께 bean도 같이 소멸
	}

}
