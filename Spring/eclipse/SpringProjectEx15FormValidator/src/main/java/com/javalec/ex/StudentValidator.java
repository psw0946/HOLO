package com.javalec.ex;

import org.springframework.validation.Errors;
import org.springframework.validation.ValidationUtils;
import org.springframework.validation.Validator;

public class StudentValidator implements Validator {

	@Override
	public boolean supports(Class<?> arg0) {
		// TODO Auto-generated method stub
		return Student.class.isAssignableFrom(arg0); // ������ ��ü�� Ŭ���� Ÿ�� ����
	}

	@Override
	public void validate(Object arg0, Errors arg1) {
		// TODO Auto-generated method stub
		System.out.println("validate()");
		Student student = (Student)arg0;
		
		/*
		String studentName = student.getName();
		if (studentName == null || studentName.trim().isEmpty()) {
			System.out.println("studentName is null or empty");
			arg1.rejectValue("name", "trouble");
		}
		*/
		ValidationUtils.rejectIfEmptyOrWhitespace(arg1, "name", "trouble");
		
		int studentId = student.getId();
		if (studentId == 0) {
			System.out.println("studentId is 0");
			arg1.rejectValue("id", "trouble");
		}
	}

}
