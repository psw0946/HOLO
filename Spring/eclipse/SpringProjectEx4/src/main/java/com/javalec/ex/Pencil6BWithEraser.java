package com.javalec.ex;

public class Pencil6BWithEraser extends Pencil6B implements Pencil {

	@Override
	public void use() {
		// TODO Auto-generated method stub
		super.use();
		System.out.println("지우개도 있습니다.");
	}

}
